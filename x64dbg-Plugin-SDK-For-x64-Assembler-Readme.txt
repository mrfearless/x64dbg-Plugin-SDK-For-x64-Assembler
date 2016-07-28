x64dbg Plugin SDK For x64 Assembler

fearless 2016 - www.LetTheLight.in


Overview
--------

This is a consolidation and conversion of the original x64dbg plugin SDK files: _plugins.h, _plugin_types.h, bridgemain.h & _exports.h to a format that will work with JWasm64/HJwasm and other assemblers. Currently this package only supports 64bit x64dbg (x64dbg).

For 64bit support use the x64dbg Plugin SDK for x86 Assembler found here: https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x86-Assembler


Whats included in this package
------------------------------

 - JWasm64 version of the x64dbg plugin SDK found in the pluginsdk folder
 - RadASM testplugin project and files as a working example of how to use the plugin SDK
 - RadASM template for creating your own x64dbg plugins.
 - RadASM Code Completion files for easy use of the Plugin SDK For x64 Assembler (JWasm64)


The files that comprise this version of the x64dbg Plugin SDK For x64 Assembler are

 - pluginsdk\include\x64dbgpluginsdk.inc     Main include file for ease of use - see below on how to use.
 - pluginsdk\include\x64dbg.inc              x64dbg masm/jwasm style include converted from source files
 - pluginsdk\include\x64bridge.inc           x64bridge masm/jwasm style include converted from x64dbg bridgemain.h
 - pluginsdk\include\dbghelp_x64.inc         dbghelp_x64 masm/jwasm style include
 - pluginsdk\include\TitanEngine_x64.inc     TitanEngine masm/jwasm style include converted from TitanEngine.h
 - pluginsdk\lib\x64dbg.lib                  x64dbg library from the x64dbg source for x64dbg.dll
 - pluginsdk\lib\x64bridge.lib               x64bridge library from the x64dbg source for x64bridge.dll
 - pluginsdk\lib\dbghelp_x64.lib             dbghelp_x64 library from x64dbg source for dbghelp.dll
 - pluginsdk\lib\TitanEngine_x64.lib         TitanEngine library from the x64dbg source for TitanEngine.dll


The files that are included in the extra's folder are

 - install.bat                               Copies the pluginsdk files to your jwasm folders (lib, include) 
 - JwasmApiCall.api                          RadASM Code Completion file for api calls (for x64dbg plugin SDK)
 - JwasmApiConst.api                         RadASM Code Completion file for constants (for x64dbg plugin SDK)
 - JwasmApiStruct.api                        RadASM Code Completion file for structures (for x64dbg plugin SDK)
 - x64dbgplugin.tpl                          RadASM 64bit x64dbg plugin template for easy project creation

 
 
How to use
----------

There are a number of ways of using the pluginsdk files in your own projects

 - Copy the x64dbgpluginsdk.inc, x64dbg.inc, x64bridge.inc, debug_x64.inc and TitanEngine_x64.inc files from pluginsdk\include\ folder to your jwasm\include folder
 - Copy the x64dbg.lib, x64bridge.lib, debug_x64.lib and TitanEngine_x64.lib files from pluginsdk\lib folder to your jwasm\lib folder
 - Add a line in your source code:

    include x64dbgpluginsdk.inc

 - or add the following lines to your source code

    include x64dbg.inc
    include x64bridge.inc
    include debug_x64.inc
    include TitanEngine_x64.inc
    includelib x64dbg.lib
    includelib x64bridge.lib
    includelib debug_x64.lib
    includelib TitanEngine_x64.lib


Alternatively you can use the included template to easily create a x64dbg plugin project ready to use

 - Copy the template\x64dbg_plugin.tpl file to your RadASM\JWasm\Templates folder.
 - Open RadASM and choose a new project.
 - Choose assembler type as JWasm
 - Choose the project name and folder.
 - Specify project as a Dll64 (64bit dynamic link library) type.
 - Select 'x64dbg plugin' as the project template to use and allow it to create & setup a ready to run barebones x64dbg plugin.

With any of these options, feel free to add any other includes and libs as you normally would.

You may need to download my JWasm for RadASM package to add in support for JWasm / JWasm64: http://masm32.com/board/index.php?topic=4162.0

Manual compile and link settings
--------------------------------

 - Assemble: \JWASM\BIN\JWASM64.EXE /c -win64 -Zp8 /Zi /win64 /D_WIN64 /Cp /nologo /W2 /I"\JWasm\Include", "MyPlugin.asm"
 - Link:     \JWASM\BIN\LINK.EXE /SUBSYSTEM:WINDOWS /RELEASE /DLL /DEF:"MyPlugin.def" /LIBPATH:"\JWasm\Lib\x64" /MACHINE:X64 /OUT:"MyPlugin.dp64", "MyPlugin.obj", "MyPlugin.res"
 - Resource: \JWASM\BIN\RC.EXE /v "MyPlugin.rc"


Notes
-----

For more information on the x64dbg plugin SDK functions and overall usage please read the x64dbg help manual section on plugins found here: http://x64dbg.com/help/index.htm.

Make sure you get the latest versions of the x64dbg.lib, x64bridge.lib files from the x64dbg source. The files provided here may become outdated as changes occur with the development of the x64dbg debugger. I may add changes to the x64dbg.inc and x64bridge.inc to take into account new features and functions in future - but I wont guarantee that I will, you may need to manually update the .inc files yourself and download the newest .lib files if you want this package to stay up to date.

Including a manifest and version info in your plugin .dll (.dp64) may prevent anti-virus false positives. The testplugin has an example of this usage.

 - RadASM IDE: http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml
 - Masm32: http://www.masm32.com/masmdl.htm
 - JWasm64: http://masm32.com/board/index.php?topic=3795.0
 - JWasm for RadASM package: http://masm32.com/board/index.php?topic=4162.0


x64dbg
------
 - x64dbg website: http://x64dbg.com
 - x64dbg source: https://github.com/x64dbg/x64dbg
 - x64dbg downloads: http://sourceforge.net/projects/x64dbg
 - x64dbg plugin: https://github.com/x64dbg/testplugin
 - Mr. eXoDia: http://mrexodia.cf



