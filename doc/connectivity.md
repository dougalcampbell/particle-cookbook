# Connectivity
Connectivity is at the heart of the Particle family of devices. Whether or 
not you are using the Particle Cloud platform, the main advantage of these
devices is their built-in, easy-to-use ability to communicate, whether by
WiFi/Ethernet, Bluetooth, or Mesh protocols.

Particle provides a lot of control over how devices use that connectivity,
which makes this a very broad subject.


## PLACEHOLDER : TODO ##
\[Editor Note: We might want to consider breaking these into separate 
sub-documents, like `connectivity-particle-cloud.md`, 
`connectivity-wifi.md`, etc.\]


## How do I control my connection to the network/cloud?
A common question when working with Particle devices is "How can I prevent
my device from automatically connecting to the Cloud/Wifi/Cellular when it
first starts up? Not every project requires a network connection, or you
might want to let your device check for certain conditions first, before
it makes a connection. This behavior is controlled via the `SYSTEM_MODE`
macro. There are three possible settings: `AUTOMATIC`, `SEMI_AUTOMATIC`,
and `MANUAL`.

`SYSTEM_MODE(AUTOMATIC)` is the default setting, which is the same as if
you didn't specify a system mode at all. With this mode, your device will
automatically attempt to connect to the local network and the Particle 
Cloud.

`SYSTEM_MODE(SEMI_AUTOMATIC)` will automatically connect to the local network
(WiFi, Cellular, or Mesh), but not to the Particle Cloud. You can manually
connect and disconnect to the Cloud manually, if needed.

`SYSTEM_MODE(MANUAL)` will not connect to anything automatically. If you need
to connect to the local network or to the Cloud, you will have to manage the
connection and disconnection manually.

Note that this statement should be *outside* of your `setup()` and `loop()`
functions. For example:

    /* My awesome project */
    SYSTEM_MODE(SEMI_AUTOMATIC)
    
    setup() {
      // set up some stuff...
    }
    
    loop() {
      // do all the things...
    }


## Can I make my code run faster?
The FreeRTOS system that underlies the Particle deviceOS is capable of using
threading to manage multiple tasks at once. In deviceOS, we can use this to
let the Particle networking management functions run in their own thread, 
instead of invisibly running as part of your user code thread. This can 
result in a speedup of up to about five times (depending on what other 
things are happening in your code). This is done with the `SYSTEM_THREAD`
macro:

`SYSTEM_THREAD(ENABLED)`

Like `SYSTEM_MODE`, this statement should go outside of your `setup()` and
`loop()` functions. 

Note that the use of `SYSTEM_THREAD` will cause certain other functions to
behave in an asyncronous mode, will may require you to make some adjustments
to your code.

## TODO: Explain async ##



## Particle Cloud

### Particle.publish() / Particle.subscribe()

### Particle.variable()

### Particle.function()

### Webhooks

### Local Cloud Server
At one time, Particle maintained a project called [particle-iot/spark-server](https://github.com/particle-iot/spark-server), which let you host your own 
local cloud server. They have not updated the codebase since 2015. However,
community member @Brewskey maintains his own fork, [Brewskey/spark-server](https://github.com/Brewskey/spark-server), 
which you can use. Be sure to read the docs to learn what differences there
might be between the official Cloud and the local server.


## WiFi


## Cellular


## Mesh


## TCPClient


## UDP


## Serial


## ?? MQTT ??
\[Maybe include info about MQTT here? But there might be a better parent 
topic for it later.\]



---
[<- Home](/particle-cookbook)
