;=====================================================================================
; x64dbg plugin SDK for Masm - fearless 2015
;
; testplugin.inc
;
;-------------------------------------------------------------------------------------
include windows.inc
include CommCtrl.inc
include shellapi.inc
include commdlg.INC

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib
includelib ComDlg32.Lib

; Your prototypes for initializing, stopping and setting up your plugin.
testPluginDlgProc           PROTO :HWND, :UINT, :WPARAM, :LPARAM
testSetup                   PROTO ; helps setup plugin
testStop                    PROTO ; cleanup routine for plugin
testDisasm                  PROTO ; custom function called from menu item added to debugger
JustFname                   PROTO :QWORD, :QWORD ; custom internal function
JustExt                     PROTO :QWORD, :QWORD ; custom internal function
cbDumpProcessCommand        PROTO :QWORD, :QWORD ; Exported function for a custom registered command 

.CONST
CRLF                        TEXTEQU <13,10,0> ; carriage return and linefeed for strings that require them (GuiAddLogMessage for example) 
; Constants for any plugin menus
MENU_TEST1                  EQU 1
MENU_OPENDIALOG             EQU 2
MENU_TEST3                  EQU 3
MENU_DISASM                 EQU 4
MENU_DUMP                   EQU 5
MENU_STACK                  EQU 6
MENU_DUMPPROCESS            EQU 7

MENU_PLUGIN1                EQU 1
IDD_PluginDlg               EQU 1000
IDC_PLUGINDLG_OK            EQU 1001

.DATA
align 01
; Data and strings for your menus and commands
szMenuTest1                 DB "Plugin Menu Item.",0
szMenuOpenDialog            DB "Open Test Dialog.",0
szMenuTest3                 DB "Another Menu Item.",0
szMenuDisasm                DB "Disasm Test Menu Item.",0
szMenuDump                  DB "Dump Test Menu Item.",0
szMenuStack                 DB "Stack Test Menu Item.",0
szMenuDumpProcess           DB "&DumpProcess...",0

; Error strings
szLogMsg                    DB MAX_PATH DUP (0)
szErrorDbgGetModuleAt       DB "DumpProcess Error: could not get module.",CRLF
szErrorDbgModBaseFromName   DB "DumpProcess Error: could not get module base.",CRLF
szErrorGetModuleBaseNameA   DB "DumpProcess Error: could not get module base name.",CRLF
szErrorGetSaveFileName      DB "DumpProcess Error: could not dump file.",CRLF
szErrorDumpProcess          DB "DumpProcess Error: Failed to dump file.",CRLF
szSuccessDumpProcess        DB "DumpProcess: Success dumping file: ",0

; Info strings
szStatusMsg                 DB "x64dbg masm32 plugin",0
szStackMsg                  DB "The stack is looking sweet!",0
szDisamMsg                  DB "Not much happening at the moment.",0
szDumpMsg                   DB "Fetching label and printing it on status bar.",0
szPluginLoaded              DB "x64dbg masm32 plugin loaded.",13,10,0
szPluginUnloaded            DB "x64dbg masm32 plugin unloaded.",13,10,0
szDebuggingRequired         DB "x64dbg masm32 plugin: you need to be debugging to use this option",13,10,0
szDebuggingIsAvailable      DB "x64dbg masm32 plugin: Debugging in operation, you are good to go!",13,10,0
szCRLF                      DB 13,10,0


; DumpProcess strings
szDumpProcess               DB "DumpProcess",0
szDump                      DB "_dump.",0
szFilterString              DB "Executables (*.exe, *.dll)",0,"*.exe;*.dll",0,"All Files (*.*)",0,"*.*",0,0
szDialogTitle               DB "Select dump file...",0

szError0                    DB "lstrlen",0
szError1                    DB "lstrlen 0",0
szError2                    DB "LenFilePathName=0",0
szError3                    DB ". not found",0

lpszLabel                   DB MAX_LABEL_SIZE DUP (0)

modname                     DB MAX_MODULE_SIZE DUP (0)
szFileName                  DB MAX_PATH DUP (0)
ext                         DB MAX_PATH DUP (0)

File                        DB MAX_PATH DUP (0)
sSaveFileName               OPENFILENAME <>
.DATA?
align 08
hInstance                   HINSTANCE ?

