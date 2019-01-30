# Particle Workbench
Helpful information for using Visual Studio Code and Particle Workbench.

## Getting VSCode to recognize the `retained` keyword
If you are using `retained` variables to save information across power
cycles or deep sleep, Intellisense in VSCode might flag the `retained`
keyword as unknown, and then flag every use of those variables as undefined
identifiers.

This problem exists as of January 2019, in Particle Workbench alpha7.  It
will probably be fixed in a future release of Particle Workbench.  But in
the meantime, you can work around it by adding the following include to your
project:

    #include "deepsleep_hal_impl.h"
    
Even if you don't do this, Workbench will still be able to compile your
code.  The error highlighting in the editor is only because the Intellisense
syntax highlighting doesn't recognize the `retained` keyword, but the
compiler still does.


---
[<- Home](/particle-cookbook)
