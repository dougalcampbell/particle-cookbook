# Sleep Modes
---

## Quick Electron/Boron Sleep Mode Advice
The balance between conserving battery power and conserving cellular data can
make the question of "best" sleep mode a tricky question. However, the most
common use-case probably looks something like:

1. Wake up
2. Take sensor readings
3. `Particle.publish()` data
4. Go to sleep for `N` minutes
5. Repeat

Generally speaking, if you are putting your device to sleep for less than 23
minutes, you should use "stop mode (pin + time) with
`SLEEP_NETWORK_STANDBY`".  This will look something like:

    System.sleep(D1, RISING, sleep_sec, SLEEP_NETWORK_STANDBY);
    
Where `D1` is a pin which can wake the device, and `sleep_sec` is how long
you want to sleep (in seconds). *NOTE:* Only certain pins are valid for the
wakeup interrupt, be sure to check the documentation for details.

If you are putting your device to sleep for more than 23 minutes, you should 
probably use deep sleep:

    System.sleep(SLEEP_MODE_DEEP, sleep_sec);
    
This sleep mode will turn off the cellular modem completely, which saves more power.
But it also means that on wake, that the device must reestablish its connection
to the cellular network, which uses extra power and an additional amount of 
data for the handshaking (about 6K).

You may be wondering "why 23 minutes?" This actually is particular to the use
of Particle SIMs in the United States (or is it all of North America?). The 
agreement that Particle has with its partner carriers allows for a 23 minute
keep-alive period. If you use a third-party SIM, your keep-alive time may be
_*much*_ lower (e.g., 30 seconds -- but check with your provider to be sure).


## Electron SLEEP_MODE_DEEP tips and examples
Some information about managing the cellular modem in conjunction with the use
of `SLEEP_MODE_DEEP`.

<https://community.particle.io/t/electron-sleep-mode-deep-tips-and-examples/27823>

## Choosing an Electron sleep mode
Excellent information and tutorial about Electron sleep modes by @rickkas7.
This article summarizes the various sleep modes, and the pros and cons of each
with regards to power usage and wake-up time. This will help you choose the
best sleep mode to use, depending on how often your project needs to wake up
and publish data. or how quickly it needs to be ready to publish after waking
up from a sleep state.

<https://community.particle.io/t/choosing-an-electron-sleep-mode/41822>

---
[<- Home](/particle-cookbook)
