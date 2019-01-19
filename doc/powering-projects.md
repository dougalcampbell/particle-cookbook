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

---
[<- Home](/particle-cookbook)
