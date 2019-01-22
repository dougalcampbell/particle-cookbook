# Particle Cookbook
A collection of programming snippets, tips, and tricks for developing with 
Particle IoT devices.


## Background
The Particle ecosystem of devices along with their Particle Cloud platform
make it simple for hobbyists and product developers to create connected 
projects. Their product line currently includes:
* Wifi: Core, Photon, Argon
* Cellular (2G/3G/LTE): Electron, Boron
* Mesh (based on IEEE 802.15.4-2006): Xenon, Argon, Boron
* Bluetooth: RedBear Duo(\*), RedBear Nano(\*), Xenon(\*\*), Argon(\*\*), Boron(\*\*)

(\*) The RedBear product line is still available for sale, but it is unclear
whether Particle will continue to develop or support them.<br/>
(\*\*) Particle Mesh devices are capable of supporting BlueTooth 5, but the
software APIs are still under development as of January 2019.

Particle provides many excellent tools for developing software for their
devices, including a browser-based Cloud IDE and the Particle Workbench IDE,
which is built on top of the popular Microsft Visual Studio Code IDE, and 
which allow you to build and flash firmware locally, for Windows, Mac, and
Linux. You can also install your own open source build toolchain, or use
other available third-party tools, such as [po](https://github.com/nrobinson2000/po).

They also have detailed documentation of the firmware libraries, tutorials,
and sample code, which covers most anything you need to know, and the
[community forums](https://community.particle.io/) are a great resource when you have questions.
If you have a question about how to hook up some odd sensor, or how to use
a certain code library, send data to a third-party service, or just about
anything, really, you'll often find the answer in the forums.

In fact, the forums are chock-full of great information, tips, little-known
facts, pointers to other tools, etc. So full, that it can be overwhelming. 
Sometimes when you have a problem, you aren't even sure what to search for. 
And *sometimes*, you don't even know that a feature exists, because you've
just never run across it before.


## Purpose
This Cookbook is an attempt to address this problem by collecting and
(hopefully) organizing some of these hidden gems so that you don't have to
waste time searching through the forums, trying to filter out tons of
unanswered questions, or long threads that touch on a topic, then spin off
in another direction. Or trying to piece together bits of the technically 
excellent firmware documentation into a code example that works for your
particular, unusual use-case.


## Topics
[Data Handling](data-handling.md)<br/>
[Mesh](mesh.md)<br/>
[Powering Projects](powering-projects.md)<br/>
[Sleep Modes](sleep-modes.md)<br/>
[System Thread](system-thread.md)<br/>


## See Also:
[github.com/rickkas7](https://github.com/rickkas7) Particle Technical Documentation Writer @rickkas7 has several good tutorials
and example code in his Github.

[Awesome Particle](https://github.com/particle-iot/awesome-particle) is a curated list of awesome things related to Particle.

## Contributions Welcome
If you have suggestions, additions, corrections, complaints, or whatever, 
please feel free to let me know. Pull Requests welcome. For now, I'm just making this a collection
of Markdown files, but I'm open to suggestions for other organizational 
schemes.


