# Mesh
## Sample Code: MarcoPolo
Forum user @ninjatill created a project called `Marco Polo` to help test the
range and reliability of Particle Mesh devices. A gateway node publishes
"Marco" events to the mesh network. The other nodes acknowledge with a "Polo"
event and their Device IDs. The gateway gathers these responses, and publishes
statistics to the Particle Cloud about the number of devices who responded,
their response times, and other information.

This code also shows good examples of handling Cloud disconnections and 
conditionally selecting to use the external mesh antenna.

https://github.com/ninjatill/Mesh_MarcoPoloHeartbeat
https://community.particle.io/t/mesh-network-testing-marcopolo-heartbeat-code/47044

