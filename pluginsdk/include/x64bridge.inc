;--------------------------------------------------------------------------------------------------------
; x64dbg Plugin SDK For x64 Assembler - https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x64-Assembler
;
; fearless 2016 - www.LetTheLight.in
;
; v1.0.0.9 - Last updated: 18/10/2016 
; 
; Feature synced with x64dbg commit: https://github.com/x64dbg/x64dbg/commit/9138a3410e9593dafdb6177cd5f8612df7543e7a
;
; This SDK Supports 64bit x64dbg only.
;
; x64dbg Plugin SDK For x64 Assembler can be downloaded from here:
; https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x64-Assembler
;
; x64dbg Plugin SDK For x86 Assembler can be downloaded from here:
; https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x86-Assembler
;
; Include file for x64bridge.dll exports, constants and structures.
;
; This is a conversion of the original plugin sdk files: bridgemain.h to a format that will work with 
; MASM and other assemblers (possibly).
;
; Where are name of a structure, structure field or other definitions conflict with a masm reserved word
; I have appended a underscore at the end of the item in most cases to work around that issue.
; There are a few exceptions: addr becomes address, end becomes finish, just for clarity.
;
; The enum macro provided emulates the enum behaviour in the origal pluginsdk files, however if masm 
; complains about line too complex during compilation, i have had to change some of the enums to
; to lines of ITEMNAME EQU VALUE type statements instead, which approximate the same function anyhow.
;
;--------------------------------------------------------------------------------------------------------

; Bridge functions
BridgeAlloc                     PROTO :QWORD ; (size_t size);
BridgeFree                      PROTO :QWORD ; (void* ptr);
BridgeSettingFlush              PROTO 
BridgeGetDbgVersion             PROTO 
BridgeInit                      PROTO 
BridgeSettingGet                PROTO :QWORD, :QWORD, :QWORD ; (const char* section, const char* key, char* value);
BridgeSettingGetUint            PROTO :QWORD, :QWORD, :QWORD ; (const char* section, const char* key, duint* value);
BridgeSettingRead               PROTO :QWORD  ; (int* errorLine)
BridgeSettingSet                PROTO :QWORD, :QWORD, :QWORD ; (const char* section, const char* key, const char* value);
BridgeSettingSetUint            PROTO :QWORD, :QWORD, :QWORD ; (const char* section, const char* key, duint value);
BridgeStart                     PROTO 

; Debugger functions
DbgInit                         PROTO
DbgExit                         PROTO
DbgMemRead                      PROTO :QWORD, :QWORD, :QWORD ;(duint va, unsigned char* dest, duint size);
DbgMemWrite                     PROTO :QWORD, :QWORD, :QWORD ;(duint va, const unsigned char* src, duint size);
DbgMemGetPageSize               PROTO :QWORD ;(duint base);
DbgMemFindBaseAddr              PROTO :QWORD, :QWORD ;(duint addr, duint* size);
DbgCmdExec                      PROTO :QWORD ;(const char* cmd);
DbgCmdExecDirect                PROTO :QWORD ;(const char* cmd);
DbgMemMap                       PROTO :QWORD ;(MEMMAP* memmap);
DbgIsValidExpression            PROTO :QWORD ;(const char* expression);
DbgIsDebugging                  PROTO
DbgIsJumpGoingToExecute         PROTO :QWORD ;(duint addr);
DbgGetLabelAt                   PROTO :QWORD, :QWORD, :QWORD ;(duint addr, SEGMENTREG segment, char* text);
DbgSetLabelAt                   PROTO :QWORD, :QWORD ;(duint addr, const char* text);
DbgClearLabelRange              PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgGetCommentAt                 PROTO :QWORD, :QWORD ;(duint addr, char* text);
DbgSetCommentAt                 PROTO :QWORD, :QWORD ;(duint addr, const char* text);
DbgClearCommentRange            PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgGetBookmarkAt                PROTO :QWORD ;(duint addr);
DbgSetBookmarkAt                PROTO :QWORD, :QWORD ;(duint addr, bool isbookmark);
DbgClearBookmarkRange           PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgGetModuleAt                  PROTO :QWORD, :QWORD ;(duint addr, char* text);
DbgGetBpxTypeAt                 PROTO :QWORD ;(duint addr);
DbgValFromString                PROTO :QWORD ;(const char* string);
DbgGetRegDump                   PROTO :QWORD ;(REGDUMP* regdump);
DbgValToString                  PROTO :QWORD, :QWORD ;(const char* string, duint value);
DbgMemIsValidReadPtr            PROTO :QWORD ;(duint addr);
DbgGetBpList                    PROTO :QWORD, :QWORD ;(BPXTYPE type, BPMAP* list);
DbgGetFunctionTypeAt            PROTO :QWORD ;(duint addr);
DbgGetLoopTypeAt                PROTO :QWORD, :QWORD ;(duint addr, int depth);
DbgGetBranchDestination         PROTO :QWORD ;(duint addr);
DbgScriptLoad                   PROTO :QWORD ;(const char* filename);
DbgScriptUnload                 PROTO
DbgScriptRun                    PROTO :QWORD ;(int destline);
DbgScriptStep                   PROTO
DbgScriptBpToggle               PROTO :QWORD ;(int line);
DbgScriptBpGet                  PROTO :QWORD ;(int line);
DbgScriptCmdExec                PROTO :QWORD ;(const char* command);
DbgScriptAbort                  PROTO
DbgScriptGetLineType            PROTO :QWORD ;(int line);
DbgScriptSetIp                  PROTO :QWORD ;(int line);
DbgScriptGetBranchInfo          PROTO :QWORD, :QWORD ;(int line, SCRIPTBRANCH* info);
DbgSymbolEnum                   PROTO :QWORD, :QWORD, :QWORD ;(duint base, CBSYMBOLENUM cbSymbolEnum, void* user);
DbgSymbolEnumFromCache          PROTO :QWORD, :QWORD, :QWORD ; (duint base, CBSYMBOLENUM cbSymbolEnum, void* user);
DbgAssembleAt                   PROTO :QWORD, :QWORD ;(  duint addr, const char* instruction);
DbgModBaseFromName              PROTO :QWORD ;(const char* name);
DbgDisasmAt                     PROTO :QWORD, :QWORD ;(duint addr, DISASM_INSTR* instr);
DbgStackCommentGet              PROTO :QWORD, :QWORD ;(duint addr, STACK_COMMENT* comment);
DbgGetThreadList                PROTO :QWORD ;(THREADLIST* list);
DbgSettingsUpdated              PROTO
DbgDisasmFastAt                 PROTO :QWORD, :QWORD ;(duint addr, BASIC_INSTRUCTION_INFO* basicinfo);
DbgMenuEntryClicked             PROTO :QWORD ;(int hEntry);
DbgFunctionGet                  PROTO :QWORD, :QWORD, :QWORD ;(duint addr, duint* start, duint* end);
DbgFunctionOverlaps             PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgFunctionAdd                  PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgFunctionDel                  PROTO :QWORD ;(duint addr);
DbgArgumentGet					PROTO :QWORD, :QWORD, :QWORD ;(duint addr, duint* start, duint* end);
DbgArgumentOverlaps				PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgArgumentAdd					PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgArgumentDel					PROTO :QWORD ;(duint addr);
DbgLoopGet                      PROTO :QWORD, :QWORD, :QWORD, :QWORD;(int depth, duint addr, duint* start, duint* end);
DbgLoopOverlaps                 PROTO :QWORD, :QWORD, :QWORD ;(int depth, duint start, duint end);
DbgLoopAdd                      PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgLoopDel                      PROTO :QWORD, :QWORD ;(int depth, duint addr);
DbgXrefAdd                      PROTO :QWORD, :QWORD ;(duint addr, duint from);
DbgXrefDelAll                   PROTO :QWORD ;(duint addr);
DbgXrefGet                      PROTO :QWORD, :QWORD ;(duint addr, XREF_INFO* info);
DbgGetXrefCountAt               PROTO :QWORD ;(duint addr);
DbgGetXrefTypeAt                PROTO :QWORD ;(duint addr);
DbgIsRunLocked                  PROTO
DbgIsBpDisabled                 PROTO :QWORD ;(duint addr);
DbgSetAutoCommentAt             PROTO :QWORD, :QWORD ;(duint addr, const char* text);
DbgClearAutoCommentRange        PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgSetAutoLabelAt               PROTO :QWORD, :QWORD ;(duint addr, const char* text);
DbgClearAutoLabelRange          PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgSetAutoBookmarkAt            PROTO :QWORD ;(duint addr);
DbgClearAutoBookmarkRange       PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgSetAutoFunctionAt            PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgClearAutoFunctionRange       PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgGetStringAt                  PROTO :QWORD, :QWORD ;(duint addr, char* text);
DbgFunctions                    PROTO
DbgWinEvent                     PROTO :QWORD, :QWORD ;(MSG* message, long* result);
DbgWinEventGlobal               PROTO :QWORD ;(MSG* message);
DbgIsRunning                    PROTO 
DbgGetTimeWastedCounter         PROTO 
DbgGetArgTypeAt                 PROTO :QWORD ;(duint addr);
DbgGetEncodeTypeBuffer          PROTO :QWORD ;(duint addr);
DbgReleaseEncodeTypeBuffer      PROTO :QWORD ;(void* buffer);
DbgGetEncodeTypeAt              PROTO :QWORD, :QWORD ;(duint addr, duint size);
DbgGetEncodeSizeAt              PROTO :QWORD, :QWORD ;(duint addr, duint codesize);
DbgSetEncodeType                PROTO :QWORD, :QWORD, :QWORD ;(duint addr, duint size, ENCODETYPE type);
DbgDelEncodeTypeRange           PROTO :QWORD, :QWORD ;(duint start, duint end);
DbgDelEncodeTypeSegment         PROTO :QWORD ;(duint start);
DbgGetWatchList                 PROTO :QWORD ;(ListOf(WATCHINFO) list);
DbgSelChanged					PROTO :QWORD, :QWORD ; (int hWindow, duint VA);

GuiGetCurrentAddress			TEXTEQU <GuiSelectionGet> ; alias

; GUI functions
GuiTranslateText				PROTO :QWORD ; (const char* Source);
GuiDisasmAt                     PROTO :QWORD, :QWORD ; (duint addr, duint cip);
GuiSetDebugState                PROTO :QWORD ; (DBGSTATE state);
GuiAddLogMessage                PROTO :QWORD ; (const char* msg);
GuiLogClear                     PROTO  
GuiUpdateAllViews               PROTO  
GuiUpdateRegisterView           PROTO  
GuiUpdateDisassemblyView        PROTO  
GuiUpdateBreakpointsView        PROTO  
GuiUpdateWindowTitle            PROTO :QWORD ; (const char* filename);
GuiGetWindowHandle              PROTO  
GuiDumpAt                       PROTO :QWORD ; (duint va);
GuiScriptAdd                    PROTO :QWORD, :QWORD ; (int count, const char** lines);
GuiScriptClear                  PROTO  
GuiScriptSetIp                  PROTO :QWORD ; (int line);
GuiScriptError                  PROTO :QWORD, :QWORD ; (int line, const char* message);
GuiScriptSetTitle               PROTO :QWORD ; (const char* title);
GuiScriptSetInfoLine            PROTO :QWORD, :QWORD ; (int line, const char* info);
GuiScriptMessage                PROTO :QWORD ; (const char* message);
GuiScriptMsgyn                  PROTO :QWORD ; (const char* message);
GuiScriptEnableHighlighting     PROTO :QWORD ; (bool enable);
GuiSymbolLogAdd                 PROTO :QWORD ; (const char* message);
GuiSymbolLogClear               PROTO 
GuiSymbolSetProgress            PROTO :QWORD ; (int percent);
GuiSymbolUpdateModuleList       PROTO :QWORD, :QWORD ; (int count, SYMBOLMODULEINFO* modules);
GuiSymbolRefreshCurrent         PROTO 
GuiReferenceAddColumn           PROTO :QWORD, :QWORD ; (int width, const char* title);
GuiReferenceSetRowCount         PROTO :QWORD ; (int count);
GuiReferenceGetRowCount         PROTO  
GuiReferenceDeleteAllColumns    PROTO  
GuiReferenceInitialize          PROTO :QWORD ; (const char* name);
GuiReferenceSetCellContent      PROTO :QWORD, :QWORD, :QWORD; (int row, int col, const char* str);
GuiReferenceGetCellContent      PROTO :QWORD, :QWORD ; (int row, int col);
GuiReferenceReloadData          PROTO  
GuiReferenceSetSingleSelection  PROTO :QWORD, :QWORD ; (int index, bool scroll);
GuiReferenceSetProgress         PROTO :QWORD ; (int progress);
GuiReferenceSetCurrentTaskProgress PROTO :QWORD, :QWORD ; (int progress, const char* taskTitle);
GuiReferenceSetSearchStartCol   PROTO :QWORD ; (int col);
GuiStackDumpAt                  PROTO :QWORD, :QWORD ; (duint addr, duint csp);
GuiUpdateDumpView               PROTO 
GuiUpdateWatchView				PROTO
GuiUpdateThreadView             PROTO 
GuiUpdateMemoryView             PROTO 
GuiAddRecentFile                PROTO :QWORD ; (const char* file);
GuiSetLastException             PROTO :QWORD ; (unsigned int exception);
GuiGetDisassembly               PROTO :QWORD, :QWORD ; (duint addr, char* text);
GuiMenuAdd                      PROTO :QWORD, :QWORD ; (int hMenu, const char* title);
GuiMenuAddEntry                 PROTO :QWORD, :QWORD ; (int hMenu, const char* title);
GuiMenuAddSeparator             PROTO :QWORD ; (int hMenu);
GuiMenuClear                    PROTO :QWORD ; (int hMenu);
GuiMenuSetEntryChecked			PROTO :QWORD, :QWORD ;(int hEntry, bool checked);
GuiSelectionGet                 PROTO :QWORD, :QWORD ; (int hWindow, SELECTIONDATA* selection);
GuiSelectionSet                 PROTO :QWORD, :QWORD ; (int hWindow, const SELECTIONDATA* selection);
GuiGetLineWindow                PROTO :QWORD, :QWORD ; (const char* title, char* text);
GuiAutoCompleteAddCmd           PROTO :QWORD ; (const char* cmd);
GuiAutoCompleteDelCmd           PROTO :QWORD ; (const char* cmd);
GuiAutoCompleteClearAll         PROTO 
GuiAddStatusBarMessage          PROTO :QWORD ; (const char* msg);
GuiUpdateSideBar                PROTO 
GuiRepaintTableView             PROTO
GuiUpdatePatches                PROTO 
GuiUpdateCallStack              PROTO 
GuiUpdateSEHChain				PROTO
GuiLoadSourceFile               PROTO :QWORD, :QWORD ; (const char* path, int line);
GuiMenuSetIcon                  PROTO :QWORD, :QWORD ; (int hMenu, const ICONDATA* icon);
GuiMenuSetEntryIcon             PROTO :QWORD, :QWORD ; (int hEntry, const ICONDATA* icon);
GuiShowCpu                      PROTO 
GuiAddQWidgetTab                PROTO :QWORD ; (void* qWidget);
GuiShowQWidgetTab               PROTO :QWORD ; (void* qWidget);
GuiCloseQWidgetTab              PROTO :QWORD ; (void* qWidget);
GuiExecuteOnGuiThread           PROTO :QWORD ; (GUICALLBACK cbGuiThread);
GuiUpdateTimeWastedCounter      PROTO 
GuiSetGlobalNotes               PROTO :QWORD ; (const char* text);
GuiGetGlobalNotes               PROTO :QWORD ; (char** text);
GuiSetDebuggeeNotes             PROTO :QWORD ; (const char* text);
GuiGetDebuggeeNotes             PROTO :QWORD ; (char** text);
GuiDumpAtN                      PROTO :QWORD, :QWORD ; (duint va, int index);
GuiDisplayWarning               PROTO :QWORD, :QWORD ; (const char* title, const char* text);
GuiRegisterScriptLanguage       PROTO :QWORD ; (SCRIPTTYPEINFO* info);
GuiUnregisterScriptLanguage     PROTO :QWORD ; (int id);
GuiUpdateArgumentWidget			PROTO 
GuiFocusView     				PROTO :QWORD ; (int hWindow);
GuiIsUpdateDisabled				PROTO 
GuiUpdateEnable     			PROTO :QWORD ; (bool updateNow);
GuiUpdateDisable				PROTO 
GuiLoadGraph     				PROTO :QWORD ; (BridgeCFGraphList* graph);
GuiGraphAt     					PROTO :QWORD ; (duint addr);
GuiUpdateGraphView				PROTO 
GuiDisableLog					PROTO
GuiEnableLog					PROTO
GuiAddFavouriteTool				PROTO :QWORD, :QWORD ; (const char* name, const char* description);
GuiAddFavouriteCommand			PROTO :QWORD, :QWORD ; (const char* name, const char* shortcut);
GuiSetFavouriteToolShortcut		PROTO :QWORD, :QWORD ; (const char* name, const char* shortcut);
GuiFoldDisassembly				PROTO :QWORD, :QWORD ; (duint startAddress, duint length);
GuiSelectInMemoryMap			PROTO :QWORD ; (duint addr);
GuiGetActiveView				PROTO :QWORD ; (ACTIVEVIEW* activeView);
GuiAddInfoLine					PROTO :QWORD ; (const char* infoLine);

; enum macro is used to enumerate constants - similar to how enum works in c. 
enum macro _param_:VARARG
    _segname_ textequ @CurSeg
    _val_=0
    % forc _chr_,_segname_
        _val_=_val_+'&_chr_'
    endm
    IFNB <_param_>
        _count_=0
        _temp_ textequ <0>
        _ldata_ textequ <_DATA>
        for _arg_,<_param_>
            _pos_ instr <_arg_>,<=>
            if _pos_ ne 0
                _temp_ SubStr <_arg_>,_pos_+1
                if _val_ ne 179H ;;179H ='_' + 'D' + 'A' + 'T' + 'A'
                    @SubStr(<_arg_>,1,_pos_-1) equ _temp_
                else
                    @SubStr(<_arg_>,1,_pos_-1) dd _temp_
                endif
                _count_=1
            else
                if _val_ ne 179H ;;179H ='_' + 'D' + 'A' + 'T' + 'A'
                    _arg_ equ _temp_+_count_
                else
                    _arg_ dd _temp_+_count_
                endif
                _count_=_count_+1
            endif
        endm
    ENDIF
endm 

; Bridge defines
MAX_SETTING_SIZE                EQU 65536
DBG_VERSION                     EQU 25

; Debugger defines
MAX_LABEL_SIZE                  EQU 256d
MAX_COMMENT_SIZE                EQU 512d
MAX_MODULE_SIZE                 EQU 256d
MAX_BREAKPOINT_SIZE             EQU 256d
MAX_CONDITIONAL_EXPR_SIZE 		EQU 256d
MAX_CONDITIONAL_TEXT_SIZE 		EQU 256d
MAX_SCRIPT_LINE_SIZE            EQU 2048d
MAX_THREAD_NAME_SIZE            EQU 256d
MAX_WATCH_NAME_SIZE 			EQU 256d
MAX_STRING_SIZE                 EQU 512d
MAX_ERROR_SIZE                  EQU 512d
RIGHTS_STRING_SIZE              EQU 6d ;(sizeof("ERWCG") + 1)
MAX_SECTION_SIZE                EQU 10d
MAX_COMMAND_LINE_SIZE 			EQU 256d
MAX_MNEMONIC_SIZE               EQU 64d
PAGE_SIZE                       EQU 1000h
TCP_ADDR_SIZE 					EQU 50


; Debugger enums
enum initialized,paused,running,stopped
enum SEG_DEFAULT,SEG_ES,SEG_DS,SEG_FS,SEG_GS,SEG_CS,SEG_SS ; SEGMENTREG
enum flagmodule=1,flaglabel=2,flagcomment=4,flagbookmark=8,flagfunction=16,flagloop=32
enum bp_none=0,bp_normal=1,bp_hardware=2,bp_memory=4 ; BPXTYPE
enum FUNC_NONE,FUNC_BEGIN,FUNC_MIDDLE,FUNC_END,FUNC_SINGLE
enum LOOP_NONE,LOOP_BEGIN,LOOP_MIDDLE,LOOP_ENTRY,LOOP_END
enum XREF_NONE,XREF_DATA,XREF_JMP,XREF_CALL
enum ARG_NONE,ARG_BEGIN,ARG_MIDDLE,ARG_END,ARG_SINGLE

DBG_SCRIPT_LOAD                 EQU 0 ;param1=const char* filename,      param2=unused
DBG_SCRIPT_UNLOAD               EQU 1 ;param1=unused,                    param2=unused
DBG_SCRIPT_RUN                  EQU 2 ;param1=int destline,              param2=unused
DBG_SCRIPT_STEP                 EQU 3 ;param1=unused,                    param2=unused
DBG_SCRIPT_BPTOGGLE             EQU 4 ;param1=int line,                  param2=unused
DBG_SCRIPT_BPGET                EQU 5 ;param1=int line,                  param2=unused
DBG_SCRIPT_CMDEXEC              EQU 6 ;param1=const char* command,       param2=unused
DBG_SCRIPT_ABORT                EQU 7 ;param1=unused,                    param2=unused
DBG_SCRIPT_GETLINETYPE          EQU 8 ;param1=int line,                  param2=unused
DBG_SCRIPT_SETIP                EQU 9 ;param1=int line,                  param2=unused
DBG_SCRIPT_GETBRANCHINFO        EQU 10 ;param1=int line,                  param2=SCRIPTBRANCH* info
DBG_SYMBOL_ENUM                 EQU 11 ;param1=SYMBOLCBINFO* cbInfo,      param2=unused
DBG_ASSEMBLE_AT                 EQU 12 ;param1=duint addr,                param2=const char* instruction
DBG_MODBASE_FROM_NAME           EQU 13 ;param1=const char* modname,       param2=unused
DBG_DISASM_AT                   EQU 14 ;param1=duint addr,                 param2=DISASM_INSTR* instr
DBG_STACK_COMMENT_GET           EQU 15 ;param1=duint addr,                param2=STACK_COMMENT* comment
DBG_GET_THREAD_LIST             EQU 16 ;param1=THREADALLINFO* list,       param2=unused
DBG_SETTINGS_UPDATED            EQU 17 ;param1=unused,                    param2=unused
DBG_DISASM_FAST_AT              EQU 18 ;param1=duint addr,                param2=BASIC_INSTRUCTION_INFO* basicinfo
DBG_MENU_ENTRY_CLICKED          EQU 19 ;param1=int hEntry,                param2=unused
DBG_FUNCTION_GET                EQU 20 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_OVERLAPS           EQU 21 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_ADD                EQU 22 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_FUNCTION_DEL                EQU 23 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_GET                    EQU 24 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_OVERLAPS               EQU 25 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_ADD                    EQU 26 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_LOOP_DEL                    EQU 27 ;param1=FUNCTION_LOOP_INFO* info,  param2=unused
DBG_IS_RUN_LOCKED               EQU 28 ;param1=unused,                    param2=unused
DBG_IS_BP_DISABLED              EQU 29 ;param1=duint addr,                param2=unused
DBG_SET_AUTO_COMMENT_AT         EQU 30 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_COMMENT_RANGE   EQU 31 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_LABEL_AT           EQU 32 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_LABEL_RANGE     EQU 33 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_BOOKMARK_AT        EQU 34 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_BOOKMARK_RANGE  EQU 35 ;param1=duint start,               param2=duint end
DBG_SET_AUTO_FUNCTION_AT        EQU 36 ;param1=duint addr,                param2=const char* text
DBG_DELETE_AUTO_FUNCTION_RANGE  EQU 37 ;param1=duint start,               param2=duint end
DBG_GET_STRING_AT               EQU 38 ;param1=duint addr,                param2=unused
DBG_GET_FUNCTIONS               EQU 39 ;param1=unused,                    param2=unused
DBG_WIN_EVENT                   EQU 40 ;param1=MSG* message,              param2=long* result
DBG_WIN_EVENT_GLOBAL            EQU 41 ;param1=MSG* message,              param2=unused
DBG_INITIALIZE_LOCKS            EQU 42 ;param1=unused,                    param2=unused
DBG_DEINITIALIZE_LOCKS          EQU 43 ;param1=unused,                    param2=unused
DBG_GET_TIME_WASTED_COUNTER     EQU 44 ;param1=unused,                    param2=unused
DBG_SYMBOL_ENUM_FROMCACHE       EQU 45 ;param1=SYMBOLCBINFO* cbInfo,      param2=unused
DBG_DELETE_COMMENT_RANGE        EQU 46 ;param1=duint start,               param2=duint end
DBG_DELETE_LABEL_RANGE          EQU 47 ;param1=duint start,               param2=duint end
DBG_DELETE_BOOKMARK_RANGE       EQU 48 ;param1=duint start,               param2=duint end
DBG_GET_XREF_COUNT_AT       	EQU 49 ;param1=duint addr,                param2=unused
DBG_GET_XREF_TYPE_AT       		EQU 50 ;param1=duint addr,                param2=unused
DBG_XREF_ADD       				EQU 51 ;param1=duint addr,                param2=duint from
DBG_XREF_DEL_ALL       			EQU 52 ;param1=duint addr,                param2=unused
DBG_XREF_GET       				EQU 53 ;param1=duint addr,                param2=XREF_INFO* info
DBG_GET_ENCODE_TYPE_BUFFER      EQU 54 ;param1=duint addr,                param2=unused
DBG_ENCODE_TYPE_GET       		EQU 55 ;param1=duint addr,                param2=duint size
DBG_DELETE_ENCODE_TYPE_RANGE    EQU 56 ;param1=duint start,               param2=duint end
DBG_ENCODE_SIZE_GET       		EQU 57 ;param1=duint addr,                param2=duint codesize
DBG_DELETE_ENCODE_TYPE_SEG      EQU 58 ;param1=duint addr,                param2=unused
DBG_RELEASE_ENCODE_TYPE_BUFFER  EQU 59 ;param1=void* buffer,              param2=unused
DBG_ARGUMENT_GET       			EQU 60 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_OVERLAPS       	EQU 61 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_ADD       			EQU 62 ;param1=FUNCTION* info,            param2=unused
DBG_ARGUMENT_DEL       			EQU 63 ;param1=FUNCTION* info,            param2=unused
DBG_GET_WATCH_LIST       		EQU 64 ;param1=ListOf(WATCHINFO),         param2=unused

enum linecommand,linebranch,linelabel,linecomment,lineempty
enum scriptnobranch,scriptjmp,scriptjnejnz,scriptjejz,scriptjbjl,scriptjajg,scriptjbejle,scriptjaejge,scriptcall
enum instr_normal,instr_branch,instr_stack
enum arg_normal,arg_memory
enum str_none,str_ascii,str_unicode

; Thread Priority Enums
enum _PriorityIdle=-15,_PriorityAboveNormal=1,_PriorityBelowNormal=-1,_PriorityHighest=2,_PriorityLowest=-2,_PriorityNormal=0,_PriorityTimeCritical=15,_PriorityUnknown=7FFFFFFFh

; Threadwait reason enums
_Executive                      EQU  0
_FreePage                       EQU  1
_PageIn                         EQU  2
_PoolAllocation                 EQU  3
_DelayExecution                 EQU  4
_Suspended                      EQU  5
_UserRequest                    EQU  6
_WrExecutive                    EQU  7
_WrFreePage                     EQU  8
_WrPageIn                       EQU  9
_WrPoolAllocation               EQU  10d
_WrDelayExecution               EQU  11d
_WrSuspended                    EQU  12d
_WrUserRequest                  EQU  13d
_WrEventPair                    EQU  14d
_WrQueue                        EQU  15d
_WrLpcReceive                   EQU  16d
_WrLpcReply                     EQU  17d
_WrVirtualMemory                EQU  18d
_WrPageOut                      EQU  19d
_WrRendezvous                   EQU  20d
_Spare2                         EQU  21d
_Spare3                         EQU  22d
_Spare4                         EQU  23d
_Spare5                         EQU  24d
_WrCalloutStack                 EQU  25d
_WrKernel                       EQU  26d
_WrResource                     EQU  27d
_WrPushLock                     EQU  28d
_WrMutex                        EQU  29d
_WrQuantumEnd                   EQU  30d
_WrDispatchInt                  EQU  31d
_WrPreempted                    EQU  32d
_WrYieldExecution               EQU  33d
_WrFastMutex                    EQU  34d
_WrGuardedMutex                 EQU  35d
_WrRundown                      EQU  36d

; Memory Size Enums
enum size_byte=1,size_word=2,size_dword=4,size_qword=8

; Encode Type Enums
enc_unknown                    	EQU  0; must be 0
enc_byte                      	EQU  1; 1 byte
enc_word                      	EQU  2; 2 bytes
enc_dword                      	EQU  3; 4 bytes
enc_fword                      	EQU  4; 6 bytes
enc_qword                      	EQU  5; 8 bytes
enc_tbyte                      	EQU  6; 10 bytes
enc_oword                      	EQU  7; 16 bytes
enc_mmword                      EQU  8; 8 bytes
enc_xmmword                     EQU  9; 16 bytes
enc_ymmword                     EQU  10; 32 bytes
enc_zmmword                     EQU  11; 64 bytes avx512 not supported
enc_real4                      	EQU  12; 4 byte float
enc_real8                      	EQU  13; 8 byte double
enc_real10                      EQU  14; 10 byte decimal
enc_ascii                      	EQU  15; ascii sequence
enc_unicode                     EQU  16; unicode sequence
enc_code                      	EQU  17; start of code
enc_junk                      	EQU  18; junk code
enc_middle                      EQU  19; middle of data

; Watch Var Type Enums
TYPE_UINT                      	EQU  0 ;unsigned integer
TYPE_INT                      	EQU  1 ;signed integer
TYPE_FLOAT                      EQU  2 ;single precision floating point value
TYPE_ASCII                      EQU  3 ;ascii string
TYPE_UNICODE                    EQU  4 ;unicode string
TYPE_INVALID                    EQU  5 ;invalid watch expression or data type

; Watchdog Mode Enums
MODE_DISABLED                   EQU  0 ;watchdog is disabled
MODE_ISTRUE                    	EQU  1 ;alert if expression is not 0
MODE_ISFALSE                    EQU  2 ;alert if expression is 0
MODE_CHANGED                    EQU  3 ;alert if expression is changed
MODE_UNCHANGED                  EQU  4 ;alert if expression is not changed



; Debugger typedefs
DBGSTATE                        TYPEDEF QWORD
SEGMENTREG                      TYPEDEF QWORD
ADDRINFOFLAGS                   TYPEDEF QWORD
BPXTYPE                         TYPEDEF QWORD
FUNCTYPE                        TYPEDEF QWORD
LOOPTYPE                        TYPEDEF QWORD
DBGMSG                          TYPEDEF QWORD
SCRIPTLINETYPE                  TYPEDEF QWORD
SCRIPTBRANCHTYPE                TYPEDEF QWORD
DISASM_INSTRTYPE                TYPEDEF QWORD
DISASM_ARGTYPE                  TYPEDEF QWORD
STRING_TYPE                     TYPEDEF QWORD
THREADPRIORITY                  TYPEDEF QWORD
THREADWAITREASON                TYPEDEF QWORD
MEMORY_SIZE                     TYPEDEF QWORD
VALUE_SIZE                      TYPEDEF QWORD
GUIMSG                          TYPEDEF QWORD
WATCHVARTYPE					TYPEDEF QWORD
WATCHDOGMODE					TYPEDEF QWORD
XREFTYPE						TYPEDEF QWORD

; Debugger structs
MEMPAGE                         STRUCT 8
    mbi                         MEMORY_BASIC_INFORMATION <>
    info                        DB MAX_MODULE_SIZE DUP (?)
MEMPAGE                         ENDS

MEMMAP                          STRUCT 8
    count                       DWORD ?
    page_                       QWORD ? ; pointer to MEMPAGE
MEMMAP                          ENDS

; BPXTYPE Breakpoint Type
BPNORMAL 				EQU 0
BPHARDWARE 				EQU 1
BPMEMORY 				EQU 2
BPDLL					EQU 3
BPEXCEPTION				EQU 4

BRIDGEBP                        STRUCT 8
    bpxtype                     BPXTYPE ?
    address                     QWORD ?
    enabled                     BYTE ?
    singleshoot                 BYTE ?
    active                      BYTE ?
    name                        DB MAX_BREAKPOINT_SIZE DUP (?)
    modd                        DB MAX_MODULE_SIZE DUP (?)
    slot                        WORD ? ;unsigned short slot;
    ; extended part
    hitCount					DWORD ? ;unsigned int 
    fastResume					BYTE ? ;bool 
    silent						BYTE ? ;bool 
    breakCondition				DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    logText						DB MAX_CONDITIONAL_TEXT_SIZE DUP (?)
    logCondition				DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    commandText					DB MAX_CONDITIONAL_TEXT_SIZE DUP (?)
    commandCondition			DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)	
BRIDGEBP                        ENDS

BPMAP                           STRUCT 8
    count                       DWORD ?
    lpBridgeBp                  QWORD ? ; pointer to BRIDGEBP
BPMAP                           ENDS

WATCHINFO						STRUCT 8
    WatchName					DB MAX_WATCH_NAME_SIZE DUP (?)
    Expression					DB MAX_CONDITIONAL_EXPR_SIZE DUP (?)
    window						QWORD ?; unsigned int 
    id							DWORD ?; unsigned int 
    varType						WATCHVARTYPE ?
    watchdogMode				WATCHDOGMODE ?
    value						QWORD ? ; duint
    watchdogTriggered			BYTE ? ; bool 
WATCHINFO						ENDS

FUNCTION                        STRUCT 8
    start                       QWORD ? ; duint
    finish                      QWORD ? ; duint
	instrcount					QWORD ? ; duint
FUNCTION                        ENDS

LOOP_                           STRUCT 8
    depth                       DWORD ? ; int
    start                       QWORD ? ; duint
    finish                      QWORD ? ; duint
LOOP_                           ENDS

ADDRINFO                        STRUCT 8
    flags                       DWORD ?; //ADDRINFOFLAGS (IN)
    module                      DB MAX_MODULE_SIZE DUP (?) ; //module the address is in
    label_                      DB MAX_LABEL_SIZE DUP (?)
    comment_                    DB MAX_COMMENT_SIZE DUP (?)
    isbookmark                  DWORD ?;
    function                    FUNCTION <>
    loop_                       LOOP_ <>
ADDRINFO                        ENDS

SYMBOLINFO_                     STRUCT 8
    address                     QWORD ? ; duint
    decoratedSymbol             QWORD ? ; char*
    undecoratedSymbol           QWORD ? ; char*
	isImported					BYTE ? ; bool
SYMBOLINFO_                     ENDS

SYMBOLMODULEINFO                STRUCT 8
    base                        QWORD ?
    name                        DB MAX_MODULE_SIZE DUP (?)
SYMBOLMODULEINFO                ENDS

SYMBOLCBINFO                    STRUCT 8
    base                        QWORD ?
    cbSymbolEnum                DWORD ? ;CBSYMBOLENUM
    user                        DWORD ?
SYMBOLCBINFO                    ENDS

FLAGS                           STRUCT 8
    c_                          DWORD ?
    p                           DWORD ?
    a                           DWORD ?
    z                           DWORD ?
    s                           DWORD ?
    t                           DWORD ?
    i                           DWORD ?
    d                           DWORD ?
    o                           DWORD ?
FLAGS                           ENDS

MXCSRFIELDS                     STRUCT 8
    FZ                          DWORD ?
    PM                          DWORD ?
    UM                          DWORD ?
    OM                          DWORD ?
    ZM                          DWORD ?
    IM                          DWORD ?
    DM                          DWORD ?
    DAZ                         DWORD ?
    PE                          DWORD ?
    UE                          DWORD ?
    OE                          DWORD ?
    ZE                          DWORD ?
    DE                          DWORD ?
    IE                          DWORD ?
    RC                          WORD ?
MXCSRFIELDS                     ENDS

X87STATUSWORDFIELDS             STRUCT 8
    B                           DWORD ?
    C3                          DWORD ?
    C2                          DWORD ?
    C1                          DWORD ?
    C0                          DWORD ?
    IR                          DWORD ?
    SF                          DWORD ?
    P                           DWORD ?
    U                           DWORD ?
    O                           DWORD ?
    Z                           DWORD ?
    D                           DWORD ?
    I                           DWORD ?
    TOP                         WORD ?
X87STATUSWORDFIELDS             ENDS

X87CONTROLWORDFIELDS            STRUCT 8
    IC                          DWORD ?
    IEM                         DWORD ?
    PM                          DWORD ?
    UM                          DWORD ?
    OM                          DWORD ?
    ZM                          DWORD ?
    DM                          DWORD ?
    IM                          DWORD ?
    RC                          WORD ?
    PC                          WORD ?
X87CONTROLWORDFIELDS            ENDS

XMMREGISTER                     STRUCT 8
    XMMLow                      DWORD ?
    XMMHigh                     DWORD ?
XMMREGISTER                     ENDS
   
YMMREGISTER                     STRUCT 8
    YMMLow                      XMMREGISTER <>; //XMM/SSE part
    YMMHigh                     XMMREGISTER <>; //AVX part
YMMREGISTER                     ENDS

X87FPUREGISTER                  STRUCT 8
    data                        DB 10 DUP (?)
    st_value                    DWORD ?
    tag                         DWORD ?
X87FPUREGISTER                  ENDS

X87FPU                          STRUCT 8
    ControlWord                 WORD ?
    StatusWord                  WORD ?
    TagWord                     WORD ?
    ErrorOffset                 DWORD ?
    ErrorSelector               DWORD ?
    DataOffset                  DWORD ?
    DataSelector                DWORD ?
    Cr0NpxState                 DWORD ?
X87FPU                          ENDS

REGISTERCONTEXT                 STRUCT 8
    cax                         ULONG_PTR ?
    ccx                         ULONG_PTR ?
    cdx                         ULONG_PTR ?
    cbx                         ULONG_PTR ?
    csp                         ULONG_PTR ?
    cbp                         ULONG_PTR ?
    csi                         ULONG_PTR ?
    cdi                         ULONG_PTR ?
IFDEF _WIN64
    r8_                         ULONG_PTR ?
    r9_                         ULONG_PTR ?
    r10_                        ULONG_PTR ?
    r11_                        ULONG_PTR ?
    r12_                        ULONG_PTR ?
    r13_                        ULONG_PTR ?
    r14_                        ULONG_PTR ?
    r15_                        ULONG_PTR ?
ENDIF ; _WIN64
    cip                         ULONG_PTR ?
    eflags                      ULONG_PTR ?
    gs_                         WORD ?
    fs_                         WORD ?
    es_                         WORD ?
    ds_                         WORD ?
    cs_                         WORD ?
    ss_                         WORD ?
    dr0_                        ULONG_PTR ?
    dr1_                        ULONG_PTR ?
    dr2_                        ULONG_PTR ?
    dr3_                        ULONG_PTR ?
    dr6_                        ULONG_PTR ?
    dr7_                        ULONG_PTR ?
    RegisterArea                DB 80 DUP (?)
    x87fpu                      X87FPU <>
    MxCsr                       DWORD ?
IFDEF _WIN64
    XmmRegisters                XMMREGISTER 16 DUP ({})
    YmmRegisters                YMMREGISTER 16 DUP ({})
ELSE ; x86
    XmmRegisters                XMMREGISTER 8 DUP ({})
    YmmRegisters                YMMREGISTER 8 DUP ({})
ENDIF
REGISTERCONTEXT                 ENDS

LASTERROR						STRUCT 8
    code						QWORD ?;
    name						DB 128 DUP (?)
LASTERROR						ENDS

REGDUMP                         STRUCT 8
    regcontext                  REGISTERCONTEXT <>
    flags                       FLAGS <>
    x87FPURegisters             X87FPUREGISTER 8 DUP ({})
    mmx                         DQ ?
    MxCsrFields                 MXCSRFIELDS <>
    x87StatusWordFields         X87STATUSWORDFIELDS <>
    x87ControlWordFields        X87CONTROLWORDFIELDS <>
	lastError					LASTERROR <>
REGDUMP                         ENDS

DISASM_ARG                      STRUCT 8
    type_                       DISASM_ARGTYPE ?
    segment_                    SEGMENTREG ?
    mnemonic                    DB 64 DUP (?)
    constant                    QWORD ? ; duint
    value                       QWORD ? ; duint
    memvalue                    QWORD ? ; duint
DISASM_ARG                      ENDS

DISASM_INSTR                    STRUCT 8
    instruction                 DB 64 DUP (?)
    type_                       DISASM_INSTRTYPE ?
    argcount                    DWORD ?
    instr_size                  DWORD ?
    arg                         DISASM_ARG 3 DUP ({})
DISASM_INSTR                    ENDS

STACK_COMMENT                   STRUCT 8
    color                       DB 8 DUP (?); //hex color-code
    comment_                    DB MAX_COMMENT_SIZE DUP (?);
STACK_COMMENT                   ENDS

THREADINFO                      STRUCT 8
    ThreadNumber                DWORD ?
    hThread                     HANDLE ?
    dwThreadId                  DWORD ?
    ThreadStartAddress          QWORD ?
    ThreadLocalBase             QWORD ?
    threadName                  DB MAX_THREAD_NAME_SIZE DUP (?)
THREADINFO                      ENDS

THREADALLINFO                   STRUCT 8
    BasicInfo                   THREADINFO <>
    ThreadCip                   QWORD ?
    SuspendCount                DWORD ?
    Priority                    THREADPRIORITY ?
    WaitReason                  THREADWAITREASON ?     
    LastError                   DWORD ?
THREADALLINFO                   ENDS

THREADLIST                      STRUCT 8
    count                       DWORD ?
    list                        THREADALLINFO <>
    CurrentThread               DWORD ?
THREADLIST                      ENDS

MEMORY_INFO                     STRUCT 8
    value                       ULONG_PTR ?  ; ULONG_PTR //displacement / addrvalue (rip-relative)
    size_                       MEMORY_SIZE ?; //byte/word/dword/qword
    mnemonic                    DB MAX_MNEMONIC_SIZE DUP (?)
MEMORY_INFO                     ENDS

VALUE_INFO                      STRUCT 8
    value                       ULONG_PTR ?; ULONG_PTR;
    size_                       VALUE_SIZE ?
VALUE_INFO                      ENDS

TYPE_VALUE                      EQU 1d
TYPE_MEMORY                     EQU 2d
TYPE_ADDR                       EQU 4d

BASIC_INSTRUCTION_INFO          STRUCT 8
    type_                       DWORD ?; //value|memory|addr
    value                       VALUE_INFO <>; //immediat
    memory                      MEMORY_INFO <>;
    address                     ULONG_PTR ? ;ULONG_PTR; //addrvalue (jumps + calls)
    branch                      BYTE ?; //jumps/calls
    call_                       BYTE ?; //instruction is a call
    size_                       DWORD ?
    instruction                 DB [MAX_MNEMONIC_SIZE * 4] DUP (?);
BASIC_INSTRUCTION_INFO          ENDS

SCRIPTBRANCH                    STRUCT 8
    type_                       SCRIPTBRANCHTYPE ?
    dest                        DWORD ?
    branchlabel                 DB 256 DUP (?)
SCRIPTBRANCH                    ENDS

FUNCTION_LOOP_INFO              STRUCT 8
    address                     QWORD ?
    start                       QWORD ?
    finish                      QWORD ?
    manual                      DWORD ?
    depth                       DWORD ?
FUNCTION_LOOP_INFO              ENDS

XREF_RECORD						STRUCT 8
	address						QWORD ? ; duint 
    type_						XREFTYPE ? ;  
XREF_RECORD						ENDS

XREF_INFO						STRUCT 8
    refcount					QWORD ? ; duint
    references					QWORD ? ; XREF_RECORD* 
XREF_INFO						ENDS

; Gui defines
; Plugin menu handle enums
GUI_PLUGIN_MENU                 EQU 0
GUI_DISASM_MENU                 EQU 1
GUI_DUMP_MENU                   EQU 2
GUI_STACK_MENU                  EQU 3

; GuiSelectionGet window handle enums
GUI_DISASSEMBLY 				EQU 0
GUI_DUMP 						EQU 1
GUI_STACK 						EQU 2
GUI_GRAPH 						EQU 3
GUI_MEMMAP 						EQU 4
GUI_SYMMOD 						EQU 5

GUI_MAX_LINE_SIZE               EQU 65536d
GUI_MAX_DISASSEMBLY_SIZE        EQU 2048d


; Gui enums
GUI_DISASSEMBLE_AT              EQU 0  ; param1=(duint)va,            param2=(duint)cip
GUI_SET_DEBUG_STATE             EQU 1  ; param1=(DBGSTATE)state,      param2=unused
GUI_ADD_MSG_TO_LOG              EQU 2  ; param1=(const char*)msg,     param2=unused
GUI_CLEAR_LOG                   EQU 3  ; param1=unused,               param2=unused
GUI_UPDATE_REGISTER_VIEW        EQU 4  ; param1=unused,               param2=unused
GUI_UPDATE_DISASSEMBLY_VIEW     EQU 5  ; param1=unused,               param2=unused
GUI_UPDATE_BREAKPOINTS_VIEW     EQU 6  ; param1=unused,               param2=unused
GUI_UPDATE_WINDOW_TITLE         EQU 7  ; param1=(const char*)file,    param2=unused
GUI_GET_WINDOW_HANDLE           EQU 8  ; param1=unused,               param2=unused
GUI_DUMP_AT                     EQU 9  ; param1=(duint)va             param2=unused
GUI_SCRIPT_ADD                  EQU 10 ; param1=int count,            param2=const char** lines
GUI_SCRIPT_CLEAR                EQU 11 ; param1=unused,               param2=unused
GUI_SCRIPT_SETIP                EQU 12 ; param1=int line,             param2=unused
GUI_SCRIPT_ERROR                EQU 13 ; param1=int line,             param2=const char* message
GUI_SCRIPT_SETTITLE             EQU 14 ; param1=const char* title,    param2=unused
GUI_SCRIPT_SETINFOLINE          EQU 15 ; param1=int line,             param2=const char* info
GUI_SCRIPT_MESSAGE              EQU 16 ; param1=const char* message,  param2=unused
GUI_SCRIPT_MSGYN                EQU 17 ; param1=const char* message,  param2=unused
GUI_SYMBOL_LOG_ADD              EQU 18 ; param1(const char*)msg,      param2=unused
GUI_SYMBOL_LOG_CLEAR            EQU 19 ; param1=unused,               param2=unused
GUI_SYMBOL_SET_PROGRESS         EQU 20 ; param1=int percent           param2=unused
GUI_SYMBOL_UPDATE_MODULE_LIST   EQU 21 ; param1=int count,            param2=SYMBOLMODULEINFO* modules
GUI_REF_ADDCOLUMN               EQU 22 ; param1=int width,            param2=(const char*)title
GUI_REF_SETROWCOUNT             EQU 23 ; param1=int rows,             param2=unused
GUI_REF_GETROWCOUNT             EQU 24 ; param1=unused,               param2=unused
GUI_REF_DELETEALLCOLUMNS        EQU 25 ; param1=unused,               param2=unused
GUI_REF_SETCELLCONTENT          EQU 26 ; param1=(CELLINFO*)info,      param2=unused
GUI_REF_GETCELLCONTENT          EQU 27 ; param1=int row,              param2=int col
GUI_REF_RELOADDATA              EQU 28 ; param1=unused,               param2=unused
GUI_REF_SETSINGLESELECTION      EQU 29 ; param1=int index,            param2=bool scroll
GUI_REF_SETPROGRESS             EQU 30 ; param1=int progress,         param2=unused
GUI_REF_SETCURRENTTASKPROGRESS  EQu 31 ; param1=int progress,         param2=const char* taskTitle
GUI_REF_SETSEARCHSTARTCOL       EQU 32 ; param1=int col               param2=unused
GUI_STACK_DUMP_AT               EQU 33 ; param1=duint addr,           param2=duint csp
GUI_UPDATE_DUMP_VIEW            EQU 34 ; param1=unused,               param2=unused
GUI_UPDATE_THREAD_VIEW          EQU 35 ; param1=unused,               param2=unused
GUI_ADD_RECENT_FILE             EQU 36 ; param1=(const char*)file,    param2=unused
GUI_SET_LAST_EXCEPTION          EQU 37 ; param1=unsigned int code,    param2=unused
GUI_GET_DISASSEMBLY             EQU 38 ; param1=duint addr,           param2=char* text
GUI_MENU_ADD                    EQU 39 ; param1=int hMenu,            param2=const char* title
GUI_MENU_ADD_ENTRY              EQU 40 ; param1=int hMenu,            param2=const char* title
GUI_MENU_ADD_SEPARATOR          EQU 41 ; param1=int hMenu,            param2=unused
GUI_MENU_CLEAR                  EQU 42 ; param1=int hMenu,            param2=unused
GUI_SELECTION_GET               EQU 43 ; param1=int hWindow,          param2=SELECTIONDATA* selection
GUI_SELECTION_SET               EQU 44 ; param1=int hWindow,          param2=const SELECTIONDATA* selection
GUI_GETLINE_WINDOW              EQU 45 ; param1=const char* title,    param2=char* text
GUI_AUTOCOMPLETE_ADDCMD         EQU 46 ; param1=const char* cmd,      param2=ununsed
GUI_AUTOCOMPLETE_DELCMD         EQU 47 ; param1=const char* cmd,      param2=ununsed
GUI_AUTOCOMPLETE_CLEARALL       EQU 48 ; param1=unused,               param2=unused
GUI_SCRIPT_ENABLEHIGHLIGHTING   EQU 49 ; param1=bool enable,          param2=unused
GUI_ADD_MSG_TO_STATUSBAR        EQU 50 ; param1=const char* msg,      param2=unused
GUI_UPDATE_SIDEBAR              EQU 51 ; param1=unused,               param2=unused
GUI_REPAINT_TABLE_VIEW          EQU 52 ; param1=unused,               param2=unused
GUI_UPDATE_PATCHES              EQU 53 ; param1=unused,               param2=unused
GUI_UPDATE_CALLSTACK            EQU 54 ; param1=unused,               param2=unused
GUI_UPDATE_SEHCHAIN				EQU 55 ; param1=unused,               param2=unused
GUI_SYMBOL_REFRESH_CURRENT      EQU 56 ; param1=unused,               param2=unused
GUI_UPDATE_MEMORY_VIEW          EQU 57 ; param1=unused,               param2=unused
GUI_REF_INITIALIZE              EQU 58 ; param1=const char* name      param2=unused
GUI_LOAD_SOURCE_FILE            EQU 59 ; param1=const char* path,     param2=line
GUI_MENU_SET_ICON               EQU 60 ; param1=int hMenu,            param2=ICONINFO*
GUI_MENU_SET_ENTRY_ICON         EQU 61 ; param1=int hEntry,           param2=ICONINFO*
GUI_SHOW_CPU                    EQU 62 ; param1=unused,               param2=unused
GUI_ADD_QWIDGET_TAB             EQU 63 ; param1=QWidget*,             param2=unused
GUI_SHOW_QWIDGET_TAB            EQU 64 ; param1=QWidget*,             param2=unused
GUI_CLOSE_QWIDGET_TAB           EQU 65 ; param1=QWidget*,             param2=unused
GUI_EXECUTE_ON_GUI_THREAD       EQU 66 ; param1=GUICALLBACK,          param2=unused
GUI_UPDATE_TIME_WASTED_COUNTER  EQU 67 ; param1=unused,               param2=unused
GUI_SET_GLOBAL_NOTES            EQU 68 ; param1=const char* text,     param2=unused
GUI_GET_GLOBAL_NOTES            EQU 69 ; param1=char** text,          param2=unused
GUI_SET_DEBUGGEE_NOTES          EQU 70 ; param1=const char* text,     param2=unused
GUI_GET_DEBUGGEE_NOTES          EQU 71 ; param1=char** text,          param2=unused
GUI_DUMP_AT_N                   EQU 72 ; param1=int index,            param2=duint va
GUI_DISPLAY_WARNING             EQU 73 ; param1=const char *text,     param2=unused
GUI_REGISTER_SCRIPT_LANG        EQU 74 ; param1=SCRIPTTYPEINFO* info, param2=unused
GUI_UNREGISTER_SCRIPT_LANG      EQU 75 ; param1=int id,               param2=unused
GUI_UPDATE_ARGUMENT_VIEW      	EQU 76 ; param1=unused,               param2=unused
GUI_FOCUS_VIEW      			EQU 77 ; param1=int hWindow,          param2=unused
GUI_UPDATE_WATCH_VIEW      		EQU 78 ; param1=unused,               param2=unused
GUI_LOAD_GRAPH      			EQU 79 ; param1=BridgeCFGraphList*    param2=unused
GUI_GRAPH_AT      				EQU 80 ; param1=duint addr            param2=unused
GUI_UPDATE_GRAPH_VIEW      		EQU 81 ; param1=unused,               param2=unused
GUI_SET_LOG_ENABLED				EQU 82 ; param1=bool isEnabled        param2=unused
GUI_ADD_FAVOURITE_TOOL			EQU 83 ; param1=const char* name      param2=const char* description
GUI_ADD_FAVOURITE_COMMAND		EQU 84 ; param1=const char* command   param2=const char* shortcut
GUI_SET_FAVOURITE_TOOL_SHORTCUT	EQU 85 ; param1=const char* name      param2=const char* shortcut
GUI_FOLD_DISASSEMBLY			EQU 86 ; param1=duint startAddress    param2=duint length
GUI_SELECT_IN_MEMORY_MAP		EQU 87 ; param1=duint addr,           param2=unused
GUI_GET_ACTIVE_VIEW				EQU 88 ; param1=ACTIVEVIEW*,          param2=unused

; GUI Typedefs
GUICALLBACK                     PROTO 
GUISCRIPTEXECUTE                PROTO  :QWORD ; (const char* text);
GUISCRIPTCOMPLETER              PROTO  :QWORD, :QWORD, :QWORD ;(const char* text, char** entries, int* entryCount);

; GUI structures
CELLINFO                        STRUCT 8
    row                         DWORD ?
    col                         DWORD ?
    string                      QWORD ?
CELLINFO                        ENDS

SELECTIONDATA                   STRUCT 8
    start                       QWORD ?
    finish                      QWORD ?
SELECTIONDATA                   ENDS

ICONDATA                        STRUCT 8
    data                        QWORD ?
    size_                       QWORD ?
ICONDATA                        ENDS

SCRIPTTYPEINFO                  STRUCT 8
    name                        DB 64 DUP (?)
    id                          QWORD ?
    execute                     QWORD ? ; pointer to GUISCRIPTEXECUTE ?
    completeCommand             QWORD ? ; pointer to GUISCRIPTCOMPLETER ?
SCRIPTTYPEINFO                  ENDS

ACTIVEVIEW						STRUCT 8
    titleHwnd					QWORD ? ; void* 
    classHwnd					QWORD ? ; void* 
    szTitle						DB MAX_STRING_SIZE DUP (?)
    className					DB MAX_STRING_SIZE DUP (?)
ACTIVEVIEW						ENDS

; Dbg functions
dbgfunctionsget                 PROTO
dbgfunctionsinit                PROTO

; DbgFunction Structures
DBGPATCHINFO                    STRUCT 8
    module                      DB MAX_MODULE_SIZE DUP (?)
    address                     QWORD ?
    oldbyte                     DB ?
    newbyte                     DB ?
DBGPATCHINFO                    ENDS

DBGCALLSTACKENTRY               STRUCT 8
    address                     QWORD ?
    from                        QWORD ?
    to                          QWORD ?
    comment_                    DB MAX_COMMENT_SIZE DUP (?)
DBGCALLSTACKENTRY               ENDS

DBGCALLSTACK                    STRUCT 8
    total                       QWORD ?
    entries                     DBGCALLSTACKENTRY {<>}
DBGCALLSTACK                    ENDS

DBGPROCESSINFO                  STRUCT 8
    dwProcessId                 QWORD ?
    szExeFile                   DB MAX_PATH DUP (?)
DBGPROCESSINFO                  ENDS

; TraceRecord Byte Type
enum InstructionBody=0,InstructionHeading,InstructionTailing,InstructionOverlapped
enum DataByte=4,DataWord,DataDWord,DataQWord,DataFloat,DataDouble,DataLongDouble,DataXMM,DataYMM,DataMMX,DataMixed,InstructionDataMixed

; TraceRecord Type
enum TraceRecordNone,TraceRecordBitExec,TraceRecordByteWithExecTypeAndCounter,TraceRecordWordWithExecTypeAndCounter

HANDLEINFO						STRUCT 8
    Handle						QWORD ? ; duint
    TypeNumber					BYTE ? ; unsigned char 
    GrantedAccess				DWORD ? ; unsigned int
HANDLEINFO						ENDS

TCPCONNECTIONINFO				STRUCT 8
	RemoteAddress				DB TCP_ADDR_SIZE DUP (?)
    RemotePort					WORD ? ; unsigned short 
    LocalAddress				DB TCP_ADDR_SIZE DUP (?)
    LocalPort					WORD ? ; unsigned short 
    StateText					DB TCP_ADDR_SIZE DUP (?)
    State						DWORD ? ; unsigned int 
TCPCONNECTIONINFO				ENDS

;--------------------------------------------------------------------------------------------------------
; DbgFunctions returns a pointer to a DBGFUNCTIONS structure, which contains a list of function calls.
; The _DbgFunctions macro provided helps with calling these indirect functions.
;
; Example to call the ModPathFromAddr function:
;
; LOCAL sel:SELECTIONDATA
; LOCAL modpath[MAX_PATH]:BYTE
;
; Invoke GuiSelectionGet, GUI_DISASSEMBLY, Addr sel
; _DbgFunctions ModPathFromAddr, sel.start, Addr modpath, MAX_PATH
;
;--------------------------------------------------------------------------------------------------------
DBGFUNCTIONS                    STRUCT
    AssembleAtEx                QWORD ? ; (duint addr, const char* instruction, char* error, bool fillnop);
    SectionFromAddr             QWORD ? ; (duint addr, char* section);
    ModNameFromAddr             QWORD ? ; (duint addr, char* modname, bool extension);
    ModBaseFromAddr             QWORD ? ; (duint addr);
    ModBaseFromName             QWORD ? ; (const char* modname);
    ModSizeFromAddr             QWORD ? ; (duint addr);
    Assemble                    QWORD ? ; (duint addr, unsigned char* dest, int* size, const char* instruction, char* error);
    PatchGet                    QWORD ? ; (duint addr);
    PatchInRange                QWORD ? ; (duint start, duint end);
    MemPatch                    QWORD ? ; (duint va, const unsigned char* src, duint size);
    PatchRestoreRange           QWORD ? ; (duint start, duint end);
    PatchEnum                   QWORD ? ; (DBGPATCHINFO* patchlist, size_t* cbsize);
    PatchRestore                QWORD ? ; (duint addr)
    PatchFile                   QWORD ? ; (DBGPATCHINFO* patchlist, int count, const char* szFileName, char* error);
    ModPathFromAddr             QWORD ? ; (duint addr, char* path, int size);
    ModPathFromName             QWORD ? ; (const char* modname, char* path, int size);
    DisasmFast                  QWORD ? ; (unsigned char* data, duint addr, BASIC_INSTRUCTION_INFO* basicinfo);
    MemUpdateMap                QWORD ? ; 
    GetCallStack                QWORD ? ; (DBGCALLSTACK* callstack);
	GetSEHChain					QWORD ? ; (DBGSEHCHAIN* sehchain);	
    SymbolDownloadAllSymbols    QWORD ? ; (const char* szSymbolStore);
    GetJitAuto                  QWORD ? ; (bool* jitauto)
    GetJit                      QWORD ? ; (char* jit, bool x64);
    GetDefJit                   QWORD ? ; (char* defjit);
    GetProcessList              QWORD ? ; (DBGPROCESSINFO** entries, int* count);
    GetPageRights               QWORD ? ; (duint addr, char* rights);
    SetPageRights               QWORD ? ; (duint addr, const char* rights);
    PageRightsToString          QWORD ? ; (QWORD protect, char* rights);
    IsProcessElevated           QWORD ? ;
    GetCmdline                  QWORD ? ; (char* cmdline, size_t* cbsize);
    SetCmdline                  QWORD ? ; (const char* cmdline);
    FileOffsetToVa              QWORD ? ; (const char* modname, duint offset);
    VaToFileOffset              QWORD ? ; (duint va);
    GetAddrFromLine             QWORD ? ; (const char* szSourceFile, int line);
    GetSourceFromAddr           QWORD ? ; (duint addr, char* szSourceFile, int* line);
    ValFromString               QWORD ? ; (const char* string, duint* value);
    PatchGetEx                  QWORD ? ; (duint addr, DBGPATCHINFO* info); 
	GetBridgeBP					QWORD ? ; (BPXTYPE type, duint addr, BRIDGEBP* bp);
	StringFormatInline			QWORD ? ; (const char* format, size_t resultSize, char* result);
	GetMnemonicBrief			QWORD ? ; (const char* mnem, size_t resultSize, char* result);
	GetTraceRecordHitCount		QWORD ? ; (duint address);
	GetTraceRecordByteType		QWORD ? ; (duint address);
	SetTraceRecordType			QWORD ? ; (duint pageAddress, TRACERECORDTYPE type);
	GetTraceRecordType			QWORD ? ; (duint pageAddress);
	EnumHandles					QWORD ? ; (ListOf(HANDLEINFO) handles);
	GetHandleName				QWORD ? ; (duint handle, char* name, size_t nameSize, char* typeName, size_t typeNameSize);
	EnumTCPConnections			QWORD ? ; (ListOf(TCPCONNECTIONINFO) connections);
	GetDbgEvents				QWORD ? ; ();
	ModGetParty					QWORD ? ; (duint base);
	ModSetParty					QWORD ? ; (duint base, int party);
	WatchIsWatchDogTriggered	QWORD ? ; (unsigned int id);
    MemIsCodePage				QWORD ? ; (duint addr, bool refresh);
    AnimateCommand				QWORD ? ; (const char* command);
    DbgSetDebuggeeInitScript	QWORD ? ; (const char* fileName);
    DbgGetDebuggeeInitScript	QWORD ? ; ()	
DBGFUNCTIONS                    ENDS



;--------------------------------------------------------------------------------------------------------
; _DbgFunctions macro for calling indirect functions stored in the DBGFUNCTIONS structure
; The return value from the DbgFunctions() call is a pointer to the DBGFUNCTIONS structure
; which this macro handles for you. 
;
; Simply specify the name of the function (the structure member name in DBGFUNCTIONS)
; and pass any required parameters as specified in the comments at the end of each line.
;
; Adapted from rrr314159's nvk macros: http://masm32.com/board/index.php?topic=3988.0
;
;--------------------------------------------------------------------------------------------------------
_DbgFunctions MACRO funcname:REQ, args:VARARG  ; "invoke"
;; ALIGN stack to 16 bits, call nvk_noalign, then restore rsp
LOCAL __dbgfunction
.DATA
__dbgfunction DQ 0
.CODE
    Invoke DbgFunctions
    mov rax, [rax].DBGFUNCTIONS.funcname
    mov __dbgfunction, rax


    push rbp            
    lea  rbp, [rsp][8]                              ;; save entering rsp first into rbp then onto stack
    sub rsp, 8                                      ;; make room for entering rsp that was saved in rbp
    and rsp, -10h                                   ;; align 16
    mov [rsp], rbp                                  ;; put entering rsp onto stack
    mov rbp, [rbp-8]                                ;; restore rbp

    _DbgFunctions_noalign __dbgfunction, args
    
    pop rsp                                         ;; right back where we started from
ENDM

_DbgFunctions_noalign MACRO funcname:REQ, args:VARARG           ;; "invoke" without aligning
LOCAL txt, cnt, stackadjust, cnttopass
;; Prepare stack for arguments, load stack, call function, restore rsp
;; called from nvk; also can call directly if u know stack is aligned

;; Count the arguments, prepare reversed arg list

    cnt = 0
    IFNB <args>                                     ;; if args blank skip most of the work
        txt equ <> 
%       FOR arg, <args>
            txt CATSTR <arg> , <,>, txt
            cnt = cnt + 1
        ENDM
        txt SUBSTR txt, 1                           ;; force expression evaluation
        txt SUBSTR txt, 1, @SizeStr( %txt ) - 1

;; Adjust stack for args, rounded up to 16 bits (necessary for some funs)

        IF cnt GT 4
            stackadjust = cnt
        ELSE
            stackadjust = 4
        ENDIF
        stackadjust = ((stackadjust+1)/2)*2 ; round up to 16
        sub rsp, stackadjust * 8

;; Load stack, saving rdx in home space to be restored after each arg

        mov [rsp], rdx                              ;; cld also spill rcx,r8,9 if needed, or whatever
        cnttopass = cnt                             ;; pass by ref, so don't send cnt (gets clobbered)
        _DbgFunctions_loadstack txt, cnttopass 
        
;; Load four regs from prepared args loaded on stack

        mov rcx, [rsp]
        mov rdx, [rsp+8]
        mov r8, [rsp+10h]
        mov r9, [rsp+18h]

;; Adjust by 20h, no other work needed, if arglist was blank

    ELSE
        sub rsp, 20h
    ENDIF

;; Call the function (finally), afterwards restore stack

    call funcname             
    IF cnt GT 0
        add rsp, stackadjust * 8
    ELSE
        add rsp, 20h
    ENDIF
ENDM


_DbgFunctions_loadstack MACRO args, posonstack
local leacmd
;; Load args on stack in reverse, restore rdx after each (it may in the arg list)

%   FOR arg, <args>
        posonstack = posonstack - 1
        mov rdx, [rsp]                                  ;; rdx gets orig value each time

;; Check for "aDdR", if present prepare lea instruction and execute it

        leacmd equ <@DbgFunctions_afteraddr(arg)>                    ;; if addr, returns after-addr text
        IFNB leacmd
            leacmd CATSTR <lea rdx, >, leacmd
            &leacmd                                     ;; execute lea instruction
            mov [rsp + posonstack*8], rdx
        ELSE

;; Convert types as necessary; if real/integer not 8 bytes, convert to real8/qword

            IF TYPE(arg) EQ REAL4 OR TYPE(arg) EQ REAL10
                fld arg
                fstp REAL8 PTR [rsp + posonstack*8]
            ELSE
                IF TYPE(arg) EQ 1 OR TYPE(arg) EQ 2
                    movsx edx, arg
                ELSEIF TYPE(arg) EQ 4
                    mov edx, arg
                ELSE
                    mov rdx, arg
                ENDIF
                mov [rsp + posonstack*8], rdx
            ENDIF
        ENDIF
    ENDM
ENDM

@DbgFunctions_afteraddr MACRO thetxt:=<>
LOCAL char, answer, iswhite, numchars

;; If argument starts with addr return rest of string, else blank

    answer equ <>
    numchars = 0
    FORC char, <&thetxt>
        IF numchars EQ 0
            iswhite INSTR 1,< 	>,<&char>       ;; trim leading spaces or tabs
            IFE iswhite
                answer CATSTR answer,<&char>
                numchars = 1
            ENDIF
        ELSEIF numchars LT 4
                answer CATSTR answer,<&char>
                numchars = numchars + 1
        ELSEIF numchars EQ 4
        
;; "answer" now holds first 4 chars after whitespace, is it "aDdR"?

            IFIDNI <addr>, answer
                answer equ <>                       ;; says addr; now get the latter part of arg
                numchars = 5                        ;; anything > 4 will do; no longer counting
            ELSE
                EXITM <>                            ;; not addr, return blank
            ENDIF
        ELSE                                        ;; numchars > 4 means get rest of string
            answer CATSTR answer,<&char>
        ENDIF
    ENDM

;; If, after trimming, arg was too short, it couldn't be addr

    IF numchars LT 5                            
        answer equ <>
    ENDIF        
EXITM answer
ENDM

