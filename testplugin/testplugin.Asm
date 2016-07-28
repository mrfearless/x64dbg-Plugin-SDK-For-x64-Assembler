;=====================================================================================
; x64dbg plugin SDK for Masm - fearless 2015
;
; testplugin.asm
;
;-------------------------------------------------------------------------------------
.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

Include x64dbgpluginsdk.inc               ; Main x64dbg Plugin SDK for your program, and prototypes for the main exports 

Include testplugin.inc                   ; plugin's include file

pluginit	        PROTO :QWORD            ; Required prototype and export for x64dbg plugin SDK
plugstop            PROTO                   ; Required prototype and export for x64dbg plugin SDK
plugsetup           PROTO :QWORD            ; Required prototype and export for x64dbg plugin SDK
;=====================================================================================


.CONST
PLUGIN_VERSION      EQU 1

.DATA
align 01
PLUGIN_NAME         DB "testplugin",0

.DATA?
;-------------------------------------------------------------------------------------
; GLOBAL Plugin SDK variables
;-------------------------------------------------------------------------------------
align 08

PUBLIC              pluginHandle
PUBLIC              hwndDlg
PUBLIC              hMenu
PUBLIC              hMenuDisasm
PUBLIC              hMenuDump
PUBLIC              hMenuStack

pluginHandle        DD ?
hwndDlg             DQ ?
hMenu               DD ?
hMenuDisasm         DD ?
hMenuDump           DD ?
hMenuStack          DD ?
;-------------------------------------------------------------------------------------


.CODE

;=====================================================================================
; Main entry function for a DLL file  - required.
;-------------------------------------------------------------------------------------
DllMain PROC hInst:HINSTANCE, fdwReason:DWORD, lpvReserved:LPVOID
    .IF fdwReason == DLL_PROCESS_ATTACH
        mov rax, hInst
        mov hInstance, rax
    .ENDIF
    mov rax,TRUE
    ret
DllMain Endp


;=====================================================================================
; pluginit - Called by debugger when plugin.dp64 is loaded - needs to be EXPORTED
; 
; Arguments: initStruct - a pointer to a PLUG_INITSTRUCT structure
;
; Notes:     you must fill in the pluginVersion, sdkVersion and pluginName members. 
;            The pluginHandle is obtained from the same structure - it may be needed in
;            other function calls.
;
;            you can call your own setup routine from within this function to setup 
;            menus and commands, and pass the initStruct parameter to this function.
;
;-------------------------------------------------------------------------------------
pluginit PROC FRAME USES RBX initStruct:QWORD
    mov rbx, initStruct

    ; Fill in required information of initStruct, which is a pointer to a PLUG_INITSTRUCT structure
    mov eax, PLUGIN_VERSION
    mov [rbx].PLUG_INITSTRUCT.pluginVersion, eax
    mov eax, PLUG_SDKVERSION
    mov [rbx].PLUG_INITSTRUCT.sdkVersion, eax
    Invoke lstrcpy, Addr [rbx].PLUG_INITSTRUCT.pluginName, Addr PLUGIN_NAME
    
    mov rbx, initStruct
    mov eax, [rbx].PLUG_INITSTRUCT.pluginHandle
    mov pluginHandle, eax
    
    ; Do any other initialization here

	mov rax, TRUE
	ret
pluginit endp


;=====================================================================================
; plugstop - Called by debugger when the plugin.dp64 is unloaded - needs to be EXPORTED
;
; Arguments: none
; 
; Notes:     perform cleanup operations here, clearing menus and other housekeeping
;
;-------------------------------------------------------------------------------------
plugstop PROC FRAME
    
    ; remove any menus, unregister any callbacks etc
    Invoke testStop
    
    mov rax, TRUE
    ret
plugstop endp


;=====================================================================================
; plugsetup - Called by debugger to initialize your plugins setup - needs to be EXPORTED
;
; Arguments: setupStruct - a pointer to a PLUG_SETUPSTRUCT structure
; 
; Notes:     setupStruct contains useful handles for use within x64dbg, mainly Qt 
;            menu handles (which are not supported with win32 api) and the main window
;            handle with this information you can add your own menus and menu items 
;            to an existing menu, or one of the predefined supported right click 
;            context menus: hMenuDisam, hMenuDump & hMenuStack
;            
;            plugsetup is called after pluginit. 
;-------------------------------------------------------------------------------------
plugsetup PROC FRAME USES RBX setupStruct:QWORD
    mov rbx, setupStruct

    ; Extract handles from setupStruct which is a pointer to a PLUG_SETUPSTRUCT structure  
    mov rax, [rbx].PLUG_SETUPSTRUCT.hwndDlg
    mov hwndDlg, rax
    mov eax, [rbx].PLUG_SETUPSTRUCT.hMenu
    mov hMenu, eax
    mov eax, [rbx].PLUG_SETUPSTRUCT.hMenuDisasm
    mov hMenuDisasm, eax
    mov eax, [rbx].PLUG_SETUPSTRUCT.hMenuDump
    mov hMenuDump, eax
    mov eax, [rbx].PLUG_SETUPSTRUCT.hMenuStack
    mov hMenuStack, eax
    
    ; Do any setup here: add menus, menu items, callback and commands etc
    Invoke testSetup
    
    ret
plugsetup endp


;=====================================================================================
; CBMENUENTRY - Called by debugger when a menu item is clicked - needs to be EXPORTED
;
; Arguments: cbType
;            cbInfo - a pointer to a PLUG_CB_MENUENTRY structure. The hEntry contains 
;            the resource id of menu item identifiers
;  
; Notes:     hEntry can be used to determine if the user has clicked on your plugins
;            menu item(s) and to do something in response to it.
;            Needs to be PROC C type procedure call to be compatible with debugger
;-------------------------------------------------------------------------------------
CBMENUENTRY PROC FRAME USES RBX cbType:QWORD, cbInfo:QWORD
    mov rbx, cbInfo
    mov eax, [rbx].PLUG_CB_MENUENTRY.hEntry
    
    .IF eax == MENU_TEST1 ; on the main plugin's sub menu
        Invoke MessageBox, 0, Addr szPluginLoaded, Addr szStatusMsg, MB_OK
    
    .ELSEIF eax == MENU_OPENDIALOG ; on the main plugin's sub menu
        Invoke DialogBoxParam, hInstance, IDD_PluginDlg, hwndDlg, OFFSET testPluginDlgProc, NULL
    
    .ELSEIF eax == MENU_TEST3 ; on the main plugin's sub menu
        Invoke DbgIsDebugging
        .IF eax == FALSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
            Invoke GuiAddLogMessage, Addr szDebuggingRequired
            ret
        .ELSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingIsAvailable
            Invoke GuiAddLogMessage, Addr szDebuggingIsAvailable
        .ENDIF
    
    .ELSEIF eax == MENU_DISASM ; on the right click context menu of the cpu window
        Invoke MessageBox, 0, Addr szDisamMsg, Addr szStatusMsg, MB_OK
        
    .ELSEIF eax == MENU_DUMP ; on the right click context menu of the ascii hex view window
        Invoke testDisasm
    
    .ELSEIF eax == MENU_STACK ; on the right click context menu of the stack window
        Invoke MessageBox, 0, Addr szStackMsg, Addr szStatusMsg, MB_OK
    
    .ELSEIF eax == MENU_DUMPPROCESS ; on the main plugin's sub menu
        Invoke DbgIsDebugging
        .IF eax == FALSE
            Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
            Invoke GuiAddLogMessage, Addr szDebuggingRequired
        .ELSE
            Invoke DbgCmdExec, Addr szDumpProcess
        .ENDIF        
    
    .ENDIF
    
    ret

CBMENUENTRY endp


;=====================================================================================
; Registered custom command - DumpProcess 
;-------------------------------------------------------------------------------------
cbDumpProcessCommand PROC FRAME USES RBX argc:QWORD, argv:QWORD
    LOCAL entry:QWORD
    LOCAL base:QWORD
    LOCAL hProcess:QWORD

    Invoke RtlZeroMemory, Addr sSaveFileName, SIZEOF OPENFILENAME 
    Invoke RtlZeroMemory, Addr szFileName, SIZEOF szFileName
    Invoke RtlZeroMemory, Addr ext, SIZEOF ext
    Invoke RtlZeroMemory, Addr File, SIZEOF File
    
    .IF argc < 2
        Invoke GetContextData, UE_CIP
    .ELSE
        mov rbx, argv
        add rbx, 8d ; argv +1
        Invoke DbgValFromString, rbx
    .ENDIF
    mov entry, rax
 
    Invoke DbgGetModuleAt, entry, Addr modname
    .IF rax == FALSE
        Invoke GuiAddLogMessage, Addr szErrorDbgGetModuleAt
        ret
    .ENDIF

    Invoke DbgModBaseFromName, Addr modname
    .IF rax == 0
        Invoke GuiAddLogMessage, Addr szErrorDbgModBaseFromName
        ret
    .endif
    mov base, rax
    
    Invoke TitanGetProcessInformation 
    mov rax, [rax].PROCESS_INFORMATION.hProcess
    mov hProcess, rax
    Invoke GetModuleBaseNameA, hProcess, base, Addr modname, MAX_MODULE_SIZE
    .IF rax == FALSE
        Invoke GuiAddLogMessage, Addr szErrorGetModuleBaseNameA
        ret   
    .ENDIF

    ;Invoke MessageBox, 0, Addr szPluginLoaded, Addr szStatusMsg, MB_OK

    ; create dump file name by adding _dump after filename part and before extension part
    Invoke JustFname, Addr modname, Addr szFileName
    ;Invoke MessageBox, 0, Addr modname, Addr modname, MB_OK
    Invoke JustExt, Addr modname, Addr ext
    ;Invoke MessageBox, 0, Addr modname, Addr modname, MB_OK
    Invoke lstrcat, Addr szFileName, Addr szDump
    Invoke lstrcat, Addr szFileName, Addr ext
    ;Invoke MessageBox, 0, Addr szFileName, Addr ext, MB_OK
    

    ; Prompt user where to save dump file
    Invoke lstrcpy, Addr File, Addr szFileName ; copy over our _dump file part of filename to buffer for saving filename with GetSaveFileName
    mov sSaveFileName.lStructSize, SIZEOF OPENFILENAME
    lea rax, szFilterString
    mov sSaveFileName.lpstrFilter, rax
    lea rax, File
    mov sSaveFileName.lpstrFile, rax
    mov sSaveFileName.nMaxFile, MAX_PATH
    mov sSaveFileName.Flags, OFN_OVERWRITEPROMPT + OFN_HIDEREADONLY
    lea rax, szDialogTitle
    mov sSaveFileName.lpstrTitle, rax
    mov rax, hwndDlg
    mov sSaveFileName.hwndOwner, rax ; = GuiGetWindowHandle();
    
    

    
    Invoke GetSaveFileName, Addr sSaveFileName
    .IF rax == 0 ; no file name was specified - user clicked cancel
        Invoke GuiAddLogMessage, Addr szErrorGetSaveFileName
        ret
    .ENDIF
    
    ; User clicked ok when saving filename so we are good to go    
    Invoke DumpProcess, hProcess, base, Addr File, entry
    .IF rax == FALSE
        Invoke GuiAddLogMessage, Addr szErrorDumpProcess
    .ELSE
        Invoke lstrcpy, Addr szLogMsg, Addr szSuccessDumpProcess
        invoke lstrcat, Addr szLogMsg, Addr File
        invoke lstrcat, Addr szLogMsg, Addr szCRLF
        Invoke GuiAddLogMessage, Addr szLogMsg
        ;Invoke GuiAddStatusBarMessage, Addr szSuccessDumpProcess
    .ENDIF
    ret

cbDumpProcessCommand endp


;-------------------------------------------------------------------------------------
; Custom procedure for continuing with the setup of the plugin 
;-------------------------------------------------------------------------------------
testSetup PROC FRAME
    Invoke _plugin_menuaddentry, hMenu, MENU_TEST1, Addr szMenuTest1
    Invoke _plugin_menuaddentry, hMenu, MENU_OPENDIALOG, Addr szMenuOpenDialog
    Invoke _plugin_menuaddseparator, hMenu
    Invoke _plugin_menuaddentry, hMenu, MENU_TEST3, Addr szMenuTest3
    
    Invoke _plugin_menuaddentry, hMenuDisasm, MENU_DISASM, Addr szMenuDisasm
    Invoke _plugin_menuaddentry, hMenuDump, MENU_DUMP, Addr szMenuDump
    Invoke _plugin_menuaddentry, hMenuStack, MENU_STACK, Addr szMenuStack

    Invoke _plugin_menuaddentry, hMenu, MENU_DUMPPROCESS, Addr szMenuDumpProcess
    Invoke _plugin_registercommand, pluginHandle, Addr szDumpProcess, Addr cbDumpProcessCommand, TRUE
        
    Invoke GuiAddLogMessage, Addr szPluginLoaded
    
    mov rax, TRUE
    ret
testSetup endp


;-------------------------------------------------------------------------------------
; Custom procedure for cleaning up at the end of the plugin
;-------------------------------------------------------------------------------------
testStop PROC FRAME
    Invoke _plugin_menuclear, hMenu
    Invoke _plugin_unregistercommand, pluginHandle, Addr szDumpProcess
    Invoke GuiAddLogMessage, Addr szPluginUnloaded
    ret
testStop endp


;-------------------------------------------------------------------------------------
; Custom procedure - called from right click context menu MENU_DUMP (cpu log screen)
;-------------------------------------------------------------------------------------
testDisasm PROC FRAME USES RBX
    LOCAL sel:SELECTIONDATA
    
    Invoke DbgIsDebugging
    .IF rax == FALSE
        Invoke GuiAddStatusBarMessage, Addr szDebuggingRequired
        Invoke GuiAddLogMessage, Addr szDebuggingRequired
        ret
    .ENDIF
    
    Invoke GuiSelectionGet, GUI_DISASSEMBLY, Addr sel
    .IF rax == TRUE
        Invoke DbgGetLabelAt, sel.start, SEG_DEFAULT, Addr lpszLabel
        Invoke GuiAddStatusBarMessage, Addr lpszLabel
    .ENDIF
    ret
testDisasm endp


;=====================================================================================
; Plugin Dialog Procedure
;-------------------------------------------------------------------------------------
testPluginDlgProc PROC FRAME hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        ; Any initialization here
        
	.ELSEIF eax == WM_CLOSE
        Invoke EndDialog, hWin, NULL
        
	.ELSEIF eax == WM_COMMAND
        mov rax, wParam
        and rax, 0FFFFh
        .IF rax == IDC_PLUGINDLG_OK
            Invoke SendMessage, hWin, WM_CLOSE, NULL, NULL
        .ENDIF
    .ELSE
        mov rax, FALSE
        ret
	.ENDIF
    mov rax, TRUE
    ret
testPluginDlgProc endp


;**************************************************************************
; Just Filename - Strip path name to just filename without extention
;**************************************************************************
JustFname PROC FRAME USES RSI RDI FilePathName:QWORD, FileName:QWORD
	LOCAL LenFilePathName:QWORD
	LOCAL nPosition:QWORD
	
	Invoke lstrlen, FilePathName
	mov LenFilePathName, rax
	mov nPosition, rax
	
	.IF LenFilePathName == 0
	    mov rdi, FileName
		mov byte ptr [rdi], 0
		ret
	.ENDIF
	
	mov rsi, FilePathName
	add rsi, rax
	
	mov rax, nPosition
	.WHILE rax != 0
		movzx rax, byte ptr [rsi]
		.IF al == '\' || al == ':' || al == '/'
			inc rsi
			.BREAK
		.ENDIF
		dec rsi
		dec nPosition
		mov rax, nPosition
	.ENDW
	mov rdi, FileName
	mov rax, nPosition
	.WHILE rax != LenFilePathName
		movzx rax, byte ptr [rsi]
		.IF al == '.' ; stop here
		    .BREAK
		.ENDIF
		mov byte ptr [rdi], al
		inc rdi
		inc rsi
		inc nPosition
		mov rax, nPosition
	.ENDW
	mov byte ptr [rdi], 0h
	ret
JustFname	ENDP


;===============================================================================
; Just Extention - Strip path and filename to just extention
;===============================================================================
JustExt PROC FRAME USES RSI RDI FilePathName:QWORD, FileExtention:QWORD
	LOCAL LenFilePathName:QWORD
	LOCAL nPosition:QWORD
	
	Invoke lstrlen, FilePathName
	mov LenFilePathName, rax
	mov nPosition, rax
	
	.IF LenFilePathName == 0
	    mov rdi, FileExtention
		mov byte ptr [rdi], 0h ; null out filename
		ret
	.ENDIF
	
	mov rsi, FilePathName
	add rsi, rax
	
	mov rax, nPosition
	.WHILE rax != 0
		movzx rax, byte ptr [rsi]
		.IF al == '.'
			inc rsi
			.BREAK
		.ENDIF
		dec rsi
		dec nPosition
		mov rax, nPosition
		.IF rax == 0 ; not found .
	        mov rdi, FileExtention
		    mov byte ptr [rdi], 0h ; null out filename
		    mov rax, FALSE
		    ret
		.ENDIF
	.ENDW
	mov rdi, FileExtention
	mov rax, nPosition
	.WHILE rax != LenFilePathName
		movzx rax, byte ptr [rsi]
		mov byte ptr [rdi], al
		inc rdi
		inc rsi
		inc nPosition
		mov rax, nPosition
	.ENDW
	mov byte ptr [rdi], 0h ; null out filename
	
	mov rax, TRUE
	ret
JustExt	ENDP


END DllMain
















