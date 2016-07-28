------------------------------------------------------------------------------------------------------------

 x64dbg plugin SDK for JWasm64 - fearless 2015 - www.LetTheLight.in

 Supports 64bit x64dbg only.

 The x64dbg plugin SDK for JWasm64 can be downloaded from here:
 https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-jwasm64

 The x64dbg plugin SDK for Masm can be downloaded from here:
 https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-masm

------------------------------------------------------------------------------------------------------------

 About

 x64dbg plugin SDK for JWasm64

 This is a consolidation and conversion of the original x64dbg plugin SDK files: _plugins.h, _plugin_types.h, 
 bridgemain.h & _exports.h to a format that will work with JWASM64 and other assemblers.

 The files that comprise this version of the x64dbg plugin SDK for JWasm are:

 - pluginsdk\x64dbgpluginsdk.inc    Main include for ease of use
 - pluginsdk\x64dbg.inc             x64dbg masm style include converted from x64dbg _plugins.h etc
 - pluginsdk\x64dbg.lib             x64dbg library from the x64dbg source for x64dbg.dll
 - pluginsdk\x64bridge.inc          x64bridge masm style include converted from x64dbg bridgemain.h
 - pluginsdk\x64bridge.lib          x64bridge library from the x64dbg source for x64bridge.dll
 - pluginsdk\dbghelp_x64.inc        dbghelp_x64 masm style include
 - pluginsdk\dbghelp_x64.lib        Library for dbghelp.dll from Microsoft Debugging Tools
 - pluginsdk\TitanEngine_x64.inc    TitanEngine masm style include converted from TitanEngine.h
 - pluginsdk\TitanEngine_x64.lib    TitanEngine library from the x64dbg source for TitanEngine.dll


------------------------------------------------------------------------------------------------------------

 testplugin

 This is a RadASM project to show the basic usage of the x64dbg plugin SDK for JWasm64

 The files that comprise this example project are:

 - testplugin.rap                   The main RadASM project file for testplugin
 - testplugin.asm                   Assembler source file
 - testplugin.inc                   Include file
 - testplugin.def                   Definitions file for the dll (dp64) exports
 - testplugin.rc                    Resource file script
 - testplugin.res                   Resource file compiled binary
 - testplugin.xml                   Manifest file
 - testplugin.dlg                   Dialog used in the testplugin example
 - testplugin.dp64                  x64dbg plugin (renamed from .dll to .dp64)
 - testplugin-readme.txt            This readme
 - Res\testpluginDlg.rc             Resource script for dialog used in testplugin
 - Res\testpluginRes.rc             Other resources used in testplugin
 - Res\testpluginVer.rc             Version info to add to .dll (.dp64)


------------------------------------------------------------------------------------------------------------

 Extras

 Extra bits and pieces provided for your convenience:

 - install.bat                      Copies the pluginsdk files to your JWasm folders (lib, include) 
 - JWasmApiCall.api                 RadASM Code Completion file for api calls (for x64dbg plugin SDK)
 - JWasmApiConst.api                RadASM Code Completion file for constants (for x64dbg plugin SDK)
 - JWasmApiStruct.api               RadASM Code Completion file for structures (for x64dbg plugin SDK)
 - x64dbgplugin.tpl                 RadASM x64dbg plugin template for easy project creation
 - plugins\AutoCmdLine              RadASM source and compiled AutoCmdLine.dp64 plugin & readme
 - plugins\APISearch                RadASM source and compiled APISearch.dp64 plugin & readme


------------------------------------------------------------------------------------------------------------

 Notes

 For more information on the x64dbg plugin SDK functions and overall usage please read the x64dbg help 
 manual section on plugins found here: http://x64dbg.com/help/index.htm

 - x64dbg website    : http://x64dbg.com
 - x64dbg source     : https://github.com/x64dbg/x64dbg
 - x64dbg downloads  : http://sourceforge.net/projects/x64dbg
 - x64dbg testplugin : https://github.com/x64dbg/testplugin

 The most upto date x64dbg.lib, x64bridge.lib and corresponding .dll's can be found in the x64dbg source

 - RadASM IDE v2.2.1.6: http://www.oby.ro/rad_asm/
 - RadASM IDE v2.2.2.0: http://www.assembly.com.br/download/radasm.html
 - JWasm64: http://masm32.com/board/index.php?topic=3795.0
 - JWasm for RadASM package: http://masm32.com/board/index.php?topic=4162.0









