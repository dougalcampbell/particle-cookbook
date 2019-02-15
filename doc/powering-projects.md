# Powering Projects
---

## Powering Boron using 12v
Though the data sheet for the Boron says that the maximum `Vin` voltage for
the Boron is 6.2V, you can actually directly power it on the `VUSB` pin at
12V, or even as high as 16-17V. At higher voltages, you could run into heat
problems, and you may need to limit charging current to the LiPo battery to
500ma.

It is still recommended that you are not powering your device by battery, to
use a converter to power the device at 5V, either by the `VUSB` pin, or the
USB port.  Also, you probably should not connect anything to the USB port if
you are supplying power on `VUSB` (though, if you supply power via the USB
port, you can use the `VUSB` pin to supply 5V power to other peripherals).

**NOTE:** Boron only. Other devices use a different charging circuit. I
recommend only using Particle's stated maximums for each device, unless
you confirm for yourself that you can safely exceed those limits.

<https://community.particle.io/t/powering-boron-using-12v/46838>

## Power conversion for automotive projects
Many automotive projects can be powered by simply using a USB converter
plugged into a power port (formerly known as the cigarette lighter). But
if one of those ports isn't convenient, you may want to draw power from
the car battery, either directly, or indirectly through a fuse, or other car
wiring. However, the power environment in an automobile can be harsh --
there are power spikes/dropouts and noise to deal with. It is recommended
that you use some sort of power conditioning when powering micro-controller
projects. One such device is this step-down voltage regulator, found on
Amazon.com:

<https://www.amazon.com/gp/product/B07D4D4Z75>

This device can take in up to 24V, protects against over/under voltage,
reverse polarization, etc, and outputs clean 5V up to 3A (there is also a
10A version).

For more information, see this thread on the Arduino forums:

<https://forum.arduino.cc/index.php?topic=213399.msg1649634#msg1649634>


## Vin On Electron and Mesh devices
When powering Electron or Mesh devices via their onboard LiPo connectors,
be aware that the `Vin` pin will not supply any power. `Vin` will only
supply voltage when `VUSB` is powered. 

<https://community.particle.io/t/powering-a-5v-device-via-electrons-lipo/45605/2>


## Detecting Vin, Battery, and Battery Status
The Electron and the Mesh devices (Argon, Boron, Xenon) can all be powered
by a 3.7V LiPo battery.  Often, it is useful for a device to know whether it
is running on battery power or not, and what the charge status of the
battery is.  The Electron and Boron boards both have an advanced Power
Management chip built in which can report details on the battery status,
while the Argon and Xenon do not, and can only report back a simple battery
voltage level. This can still be useful, as you can read that value, and 
have your device send alerts or shut itself down if the battery reaches a
critically low level (general wisdom is don't go lower than about 3.2V).

* [Example Code for Electron and Boron](/particle-cookbook/examples/power/get-power-status-electron-boron-01.ino)
* [Example Code for Argon and Xenon](/particle-cookbook/examples/power/get-power-status-electron-boron-01.ino)


---
[<- Home](/particle-cookbook)
