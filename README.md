# Particle Cookbook
---

_A collection of programming snippets, tips, and tricks for developing with
Particle IoT devices._

## Devices

The Particle ecosystem of devices along with their Particle Cloud platform
make it simple for hobbyists and product developers to create connected
projects. Their product line currently includes:

-   **Wifi**: Core, Photon, Argon

-   **Cellular:** (2G/3G/LTE): Electron, Boron

-   **Mesh:** (based on IEEE 802.15.4-2006): Xenon, Argon, Boron

-   **Bluetooth:** RedBear Duo, RedBear Nano, Xenon, Argon, Boron

_The RedBear product line is still available for sale, but it is unclear
whether Particle will continue to develop or support them._

_Particle Mesh devices are capable of supporting Bluetooth 5, but the
software APIs are still under development as of January 2019._

## Development Tools

Particle provides many excellent tools for developing software for their
devices, including a browser-based [Web IDE](https://build.particle.io/), [Particle Workbench](https://www.particle.io/workbench) (an IDE built on Microsoft Visual Studio Code), and [Particle CLI](https://docs.particle.io/tutorials/developer-tools/cli/) (a command-line experience).

Particle Workbench allows you to build and flash firmware locally, for Windows, Mac, and
Linux, and Particle CLI is an excellent tool for building firmware or managing your Particle devices.

You can choose to install and use Particle's Device OS toolchain directly if you wish by [setting up the environment manually](https://docs.particle.io/support/particle-tools-faq/local-build/), or by using a third-party utility like [po-util](https://po-util.com).

Particle has a [detailed documentation](https://docs.particle.io/reference/device-os/firmware) of the firmware libraries, tutorials,
and sample code, which covers most anything you need to know, and the
[community forums](https://community.particle.io/) are a great resource when you have questions.
If you have a question about how to hook up some odd sensor, or how to use
a certain code library, send data to a third-party service, or just about
anything really, you'll often find the answer in the forums.

In fact, the forums are chock-full of great information, tips, little-known
facts, pointers to other tools, etc. So full, that it can be overwhelming.
Sometimes when you have a problem, you aren't even sure what to search for.
And _sometimes_, you don't even know that a feature exists, because you've
just never run across it before.

## Purpose

This Cookbook is an attempt to address this problem by collecting and
(hopefully) organizing some of these hidden gems so that you don't have to
waste time searching through the forums, trying to filter out tons of
unanswered questions, or long threads that touch on a topic, then spin off
in another direction, or trying to piece together bits of the technically
excellent firmware documentation into a code example that works for your
particular, unusual use-case.

## Topics

-   [Powering Projects](doc/powering-projects.md)
-   [Sleep Modes](doc/sleep-modes.md)
-   [System Thread](doc/system-thread.md)

## See Also:

Particle Technical Documentation Writer @rickkas7 has several good tutorials
and example code in his Github:
<https://github.com/rickkas7>

## Contributions Welcome

If you have suggestions, additions, corrections, complaints, or whatever,
please feel free to let me know. Pull Requests welcome. For now, I'm just making this a collection
of Markdown files, but I'm open to suggestions for other organizational
schemes.
