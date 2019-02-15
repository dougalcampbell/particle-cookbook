/**
 * Check Power Status
 * 
 * For Argon and Xenon, this script will render the current voltage level
 * of the battery, and whether the board is powered by USB or Battery.
 *
 * Boron requires a different technique, using its PMIC functions.
 *
 * @author @rickkas7
 * @see https://community.particle.io/t/argon-check-power-source/47694/3
 */
#include "Particle.h"

SerialLogHandler logHandler;

char lastMsg[128];
unsigned long lastPublish = 0;

void setup() {
	Serial.begin();
	pinMode(PWR, INPUT);
	pinMode(CHG, INPUT);
}

void loop() {
	float voltage = analogRead(BATT) * 0.0011224;

	// PWR: 0=no USB power, 1=USB powered
	// CHG: 0=charging, 1=not charging
	char buf[128];
	snprintf(buf, sizeof(buf), "voltage=%.1f PWR=%d CHG=%d", voltage, digitalRead(PWR), digitalRead(CHG));

	if (strcmp(buf, lastMsg) != 0 && millis() - lastPublish > 2000) {
		Particle.publish("battery", buf, PRIVATE);
		Log.info(buf);
		strcpy(lastMsg, buf);
		lastPublish = millis();
	}
}
