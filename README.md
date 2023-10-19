# D2R Runeword Calculator
GUI tool for Windows/Linux/macOS that has been my personal Diablo 2 Resurrected assistant for the last years!
Updated for the currently newest patch 2.7!

It uses wxWidgets for the GUI and supports the following features:

* Calculates possible runewords (You select which runes you have, which item type base, how many sockets, and optionally a level requirement and it will list all possible runewords you can make)

* Breakpoints for all classes (IBS, FCR, FHR). Attack speed currently not supported but I can recommend https://d2.lc/IAS/

* List of runewords (In case you know the name of a runeword and want to check what it does)

* Rune conversions (Hover your mouse over a rune and it will tell you how to upgrade this rune, what this rune is upgraded from and also which effect this rune has when socketed)

* Sort Runes A-Z or by rarity (sometimes by rarity is better, but sometimes you just want to know how to upgrade ITH in the cube and you know where it is alphabetically but you might not be able to find it quickly if the runes are sorted by rarity)

* Rune word information (lists exact details of every runeword, if runeword has different effect for different item types these are listed too)
---
Can I trust the .dll files?
* Yes you can, but you don't have to. I provided the source code so you can build it yourself. Visual Studio with wxWidget is a real pain, so I give you the option to use the binary with the .dll files I provided.

How do I build it on Linux?
* sudo apt install libwxbase3.0-dev libwxgtk3.0-gtk3-0v5 libwxgtk3.0-gtk3-dev
* g++ -std=c++17 *.cpp `wx-config --cxxflags --libs` -o d2rrunes

How do I build it on macOS (e.g. Ventura)?
* Download from [here](https://www.wxwidgets.org/downloads/) under "Source Code" you choose "Source for Linux, macOS, etc"
* Then extract it, move into the folder you downloaded and use "mkdir build-cocoa-debug && cd build-cocoa-debug && ../configure --enable-debug && make && make install"
* Then in the d2r "code" folder you downloaded from here use: "g++ -std=c++17 *.cpp `wx-config --cxxflags --libs` -o d2rrunes"
---
More information about this tool and upcoming / planned features are discussed in my [blog post](https://downioads.github.io/posts/d2-runewords/)
