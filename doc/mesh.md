# Mesh
---

## Sample Code: MarcoPolo

Forum user [@ninjatill](https://community.particle.io/u/ninjatill/summary)
created a project called `Marco Polo` to help test the
range and reliability of Particle Mesh devices. A gateway node publishes
"Marco" events to the mesh network. The other nodes acknowledge with a "Polo"
event and their Device IDs. The gateway gathers these responses, and publishes
statistics to the Particle Cloud about the number of devices who responded,
their response times, and other information.

This code also shows good examples of handling Cloud disconnections and
conditionally selecting to use the external mesh antenna.

<https://github.com/ninjatill/Mesh_MarcoPoloHeartbeat>
<https://community.particle.io/t/mesh-network-testing-marcopolo-heartbeat-code/47044>


## Xenon D5 Stays High? (Ethernet FeatherWing)
If you have a Xenon that automatically pulls pin `D5` high at startup, it's
probably because you used it with an Ethernet FeatherWing in the past. When
a Xenon is configured to use an Ethernet FeatherWing, it will automatically
pull pin `D5` high, because this is the Ethernet chip select signal for the
FeatherWing. This is a setting stored in configuration flash, so it will 
continue doing this, even when the Xenon is removed from the FeatherWing
board.

To turn this behavior off, flash code which includes:

    System.disableFeature(FEATURE_ETHERNET_DETECTION)
    
This will reset the setting in configuration flash. Once this code has run
once, the setting will be reset, so you only need to do it once. You can 
then remove that code and flash other code normally.



---
[<- Home](/particle-cookbook)
