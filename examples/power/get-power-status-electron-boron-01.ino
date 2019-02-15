#include "Particle.h"

/**
 * Simple class to monitor for has power (USB or VIN), has a battery, and is charging
 *
 * Just instantiate one of these as a global variable and call setup() out of setup()
 * to initialize it. Then use the getHasPower(), getHasBattery() and getIsCharging()
 * methods as desired.
 *
 * @author rickkas7
 * @see https://community.particle.io/t/when-is-electron-powered-by-battery/20702/18
 */
class PowerCheck {
public:

	PowerCheck();
	virtual ~PowerCheck();

	/**
	 * You must call this out of setup() to initialize the interrupt handler!
	 */
	void setup();

	/**
	 * Returns true if the Electron has power, either a USB host (computer), USB charger, or VIN power.
	 *
	 * Not interrupt or timer safe; call only from the main loop as it uses I2C to query the PMIC.
	 */
	bool getHasPower();

	/**
	 * Returns true if the Electron has a battery.
	 */
	bool getHasBattery();

	/**
	 * Returns true if the Electron is currently charging (red light on)
	 *
	 * Not interrupt or timer safe; call only from the main loop as it uses I2C to query the PMIC.
	 */
	bool getIsCharging();

private:
	void interruptHandler();

	PMIC pmic;
	volatile bool hasBattery = true;
	volatile unsigned long lastChange = 0;
};

PowerCheck::PowerCheck() {
}

PowerCheck::~PowerCheck() {
}

void PowerCheck::setup() {
	// This can't be part of the constructor because it's initialized too early.
	// Call this from setup() instead.

	// BATT_INT_PC13
	attachInterrupt(LOW_BAT_UC, &PowerCheck::interruptHandler, this, FALLING);
}

bool PowerCheck::getHasPower() {
	// Bit 2 (mask 0x4) == PG_STAT. If non-zero, power is good
	// This means we're powered off USB or VIN, so we don't know for sure if there's a battery
	byte systemStatus = pmic.getSystemStatus();
	return ((systemStatus & 0x04) != 0);
}

/**
 * Returns true if the Electron has a battery.
 */
bool PowerCheck::getHasBattery() {
	if (millis() - lastChange < 100) {
		// When there is no battery, the charge status goes rapidly between fast charge and
		// charge done, about 30 times per second.

		// Normally this case means we have no battery, but return hasBattery instead to take
		// care of the case that the state changed because the battery just became charged
		// or the charger was plugged in or unplugged, etc.
		return hasBattery;
	}
	else {
		// It's been more than a 100 ms. since the charge status changed, assume that there is
		// a battery
		return true;
	}
}


/**
 * Returns true if the Electron is currently charging (red light on)
 */
bool PowerCheck::getIsCharging() {
	if (getHasBattery()) {
		byte systemStatus = pmic.getSystemStatus();

		// Bit 5 CHRG_STAT[1] R
		// Bit 4 CHRG_STAT[0] R
		// 00 – Not Charging, 01 – Pre-charge (<VBATLOWV), 10 – Fast Charging, 11 – Charge Termination Done
		byte chrgStat = (systemStatus >> 4) & 0x3;

		// Return true if battery is charging if in pre-charge or fast charge mode
		return (chrgStat == 1 || chrgStat == 2);
	}
	else {
		// Does not have a battery, can't be charging.
		// Don't just return the charge status because it's rapidly switching
		// between charging and done when there is no battery.
		return false;
	}
}

void PowerCheck::interruptHandler() {
	if (millis() - lastChange < 100) {
		// We very recently had a change; assume there is no battey and we're rapidly switching
		// between fast charge and charge done
		hasBattery = false;
	}
	else {
		// Note: It's quite possible that hasBattery will be false when there is a battery; the logic
		// in getHasBattery() takes this into account by checking lastChange as well.
		hasBattery = true;
	}
	lastChange = millis();
}



// Global variables
PowerCheck powerCheck;
unsigned long lastCheck = 0;
char lastStatus[256];

void setup() {
	Serial.begin(9600);
	powerCheck.setup();
}

void loop() {

	if (millis() - lastCheck > 2000) {
		lastCheck = millis();

		char buffer[256];
		snprintf(buffer, sizeof(buffer), "hasPower=%d hasBattery=%d isCharging=%d",
				powerCheck.getHasPower(), powerCheck.getHasBattery(), powerCheck.getIsCharging());

		if (strcmp(lastStatus, buffer) != 0) {
			strcpy(lastStatus, buffer);
			Particle.publish("battery", buffer, PRIVATE);
		}
	}
}

		}
	}
}
