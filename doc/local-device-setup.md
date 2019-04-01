# Setup a New Mesh Device Locally
---

The usual method for setting up a new Particle device is to use the Particle
mobile app (iOS or Android). With the Mesh devices (Argon, Boron, and Xenon),
this involves scanning a very small barcode from a label on the device. Some
people have had problems with that step, because the camera on their phone
just can't focus well enough at a close enough distance to decode the bar
code.

Luckily, it is possible to set up a device completely from a computer, using
Particle Workbench (or po-util, or whatever local toolchain you prefer) to
compile a new firmware, and the Particle CLI to claim it.


## Requirements
* A Particle Cloud login account
* Particle CLI version 1.40.0 or higher
* Particle WorkBench, po-util, or other local build toolchain
* DeviceOS 0.9.0 or higher

To claim a Xenon, you will need a functioning Argon or Boron. This guide will
start with instructions for setting up an Argon.


## Setting up an Argon
First of all, make sure you have Particle CLI 1.40.0 or higher installed.
If you already have the cli installed, you can check the version by running
the command `particle --version` in your terminal. If you have an older 
version, the method for upgrading might vary, depending on how you originally
installed it. You may need to download the newest installer from the Particle
web site, or run the command `particle update-cli`, or perhaps run the 
command `npm install -g particle-cli`.

Next, your device must have DeviceOS 0.9.0 or higher installed. At the time
of this writing, chances are that your device has an older version installed.
If so, you will need to compile a new firmware, and flash it to the the
device with DFU.

### How to tell if you need to flash new firmware
Unpack your Argon, place it on the breadboard, and attach the included
antenna to the connector labeled `WIFI`. Connect it to your computer's USB
port (it should begin blinking blue), and run the command `particle serial 
identify`. If this command returns an error, then your device needs to be
upgraded. On my Mac, the error is `Could not identify device: No serial 
port identified`. If the identify command displays your Device ID and
firmware version, then you should be able to skip the following update step,
and proceed to `Connect to WiFi`.


### Update your device firmware and NCP
If your device is not responding to the identify command, you will need to
flash a new firmware with the deviceOS upgrade included. You can [download
a stock hybrid firmware
image](https://github.com/particle-iot/device-os/releases/tag/v0.9.0) from
the Particle github, or build your own with Workbench.

In either case, you will need to put your device into DFU mode. You do this
by simultaneously pressing the RESET and MODE buttons, then release the
RESET button, and continue holding MODE until the light changes from
flashing magenta to flashing yellow, then release MODE. The device should 
continue flashing yellow.

In Particle Workbench, you can start a project, set it to build with
deviceOS 0.9.0, and select Argon as the target device. Then choose `Run
Build Task...` from the `Terminal` menu, and select "Particle: Flash
application & DeviceOS (local)". It shouldn't matter much what program you
use to flash, it can just be the default empty file. Once the firmware has
flashed, your device should return to flashing blue. In your terminal, you
should be able to run the command `particle serial identify`, and it should
return your device ID and new deviceOS version.

It is possible that the first attempt to flash the firmware will fail. If 
so, just repeat the process, and it should succeed on the second try.

The Argon (Argons only, not Borons or Xenons) will also require an update to
the NCP (Network CoProcessor). [Download the Argon NCP OTA
firmware](https://github.com/particle-iot/argon-ncp-firmware/releases/tag/v0.0.5)
.bin file, then flash it do your Argon with the command `particle flash
--serial argon-ncp-firmware-0.0.5-ota.bin`. Without this update, your device
will be unable to properly connect to a WiFi network.

You can read more information about updating the deviceOS and NCP [in the
Particle Community Forums](https://community.particle.io/t/updated-3-21-19-gen-3-known-issues/45722/3).


### Connect to WiFi
If you haven't already, take note of your Device ID. If you need to, run the
`particle serial identify` command again to get it. Copy it into your
computer clipboard, and maybe paste it into a text editor or notepad app for
reference, if needed. We will need this ID in order to claim your device and 
set up devices on a mesh network and the Particle Cloud.

With your deviceOS and NCP up-to-date, you are now ready to connect to the
Internet. Use the command `particle serial wifi`, and follow the prompts to
select your network, and provide login credentials.

    $ particle serial wifi
    ? Should I scan for nearby Wi-Fi networks? Yes
    ? Select the Wi-Fi network with which you wish to connect your device: myNetwork
    ? Should I try to auto-detect the wireless security type? Yes
    > Detected WPA(PSK/AES,TKIP/TKIP) WPA2(PSK/AES,TKIP/TKIP) security
    ? Wi-Fi Password myWifiPassword
    Done! Your device should now restart.

Your device should change from blinking blue to blinking green, to rapid
flashing green, to flashing cyan, then finally to "breathing" cyan. This 
indicates that your device has a connection to the Particle Cloud.

### Claim your device
Now that your device is online, you can claim it into your Particle account.
Run the command `particle device add <YourDeviceID>`, substituting your
device ID. For example (not a real device id):

    $ particle device add d01c3e6h01bdh3h279c226af
    Claiming device d01c3e6h01bdh3h279c226af
    Successfully claimed device d01c3e6h01bdh3h279c226af

### Rename your device (optional)
With your device claimed, you can give it a name which will be easier to
remember, so that you don't have to keep using the long hashed Device ID.
Use the `particle device rename` command:

    $ particle device rename d01c3e6h01bdh3h279c226af MyArgon01
    Renaming device d01c3e6h01bdh3h279c226af
    Successfully renamed device d01c3e6h01bdh3h279c226af to: MyArgon01
    
From this point on, you should be able to use either the name or the ID in
most particle CLI commands.

### Create a Mesh network
At this point, you can create a new Mesh network with your Argon as its
gateway device. You will provide a name for your network and the Argon's
device ID:

    $ particle mesh create MyMeshNetwork MyArgon01
    ? Enter a password for the new network [hidden]
    ? Confirm the password [hidden]
    Done! The device will be registered in the network once it is connected to the cloud.

Congratulations!  Your Argon should now be completely setup, and ready to
use. You can flash it OTA (Over-The-Air), communicate with the Particle Cloud, 
and add more devices to your Mesh network.


---
[<- Home](/particle-cookbook)
