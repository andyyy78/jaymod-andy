# Jaymod-Andy

Read below for the original Jaymod modification information.  

Jaymod-Andy is essentially a modificaiton of the Jaymod Mod.  The aim is simply to add some additional features and functionality to make it even more awesome than it already is. :)

Jaymod-Andy uses the latest release of Jaymod to build off of.  As of the time of this document, that release is 2.2.0.  Jaymod also is no longer in active development so chances are there won't be future Jaymod releases, only Jaymod-Andy.

We also changed the way the Windows side development takes place.  Rather than using Mingw (like Jaymod does), Jaymod-Andy builds straight from Visual Studio (we used version 2010 Professional, but other similar versions should work as well).  If you wish to use Mingw like Jaymod does, you should still be able to do that.  There are some major issues that exist that we are working through - such as, currently you can only build debug builds from Visual Studio (release builds throw errors we haven't worked through yet).  You also may get errors when trying to build map files when compiling the solution.  Either turn map file building off or simply right click on the individual projects in the solution and you should be able to build them that way.  We will continue to address these issues in future releases.

We will also include some separate documentation that takes you step by step how to setup the build environment on a Windows PC soon.

# Jaymod

This is the source for the last release of Jaymod, which is version 2.0.0.

# Compiling

The mod has a very powerful make system that can cross-compile the mod for Linux, Windows (via mingw) and OSX. There are also specialty binaries for specific CPU
platforms for each of these platforms.

Information about the build system can be found in the [build system notes](https://raw.githubusercontent.com/budjb/jaymod/master/notes/BuildSystem.txt).

Some of the compilation and system libraries required to make a complete build have been lost to time. If anyone would like to minimalize the build system and provide
compilation instructions, it would be much appreciated.

# License

This source is bound to the original terms from **id Software**. On top of that, I am releasing this source under the Apache 2.0 license. Feel free to use this codebase
as you please, as long as both licenses are bundled and proper credit is given.

