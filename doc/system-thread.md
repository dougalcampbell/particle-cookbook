# System Thread
---

## Particle publish and blocking
This is a very detailed article about using `SYSTEM_THREAD(ENABLED);` (or
not), and how it affects publishing and other networking, and how to
properly avoid your code blocking on certain operations.

<https://community.particle.io/t/particle-publish-and-blocking/42022>

## Particle Threads Tutorial
You may not even realize that the Particle Device OS is built atop FreeRTOS,
a real-time operating system for embedded devices, and that FreeRTOS supports
Threads, which allow you to run multiple tasks simultaneously or
asynchronously. However, threads are very complex and there are lots of
pitfalls. This article gives a pretty deep dive into using threads, and why
you probably should avoid it, unless you really know what you're doing.

<https://github.com/rickkas7/particle-threads>

---
[<- Home](/particle-cookbook)
