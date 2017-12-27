;=========================================================================================
;
; x64dbgpluginsdk_x64 Library v1.0.0.0
;
; 2016 by fearless
;
; http://www.LetTheLight.in
;
; x64dbg plugin SDK For Assembler x64 - fearless
; https://github.com/mrfearless/x64dbg-Plugin-SDK-For-x64-Assembler
;
;=========================================================================================

;-----------------------------------------------------------------------------------------
; x64dbgpluginsdk_x64 Prototypes
;-----------------------------------------------------------------------------------------

; Plugin functions
_plugin_loadmenuicon            PROTO :QWORD, :QWORD, :QWORD
_plugin_getmenutoolbarhandles   PROTO :QWORD, :QWORD
_plugin_getmainscreenhandle     PROTO :QWORD
_plugin_starttoolbargui         PROTO :QWORD, :QWORD
_plugin_stoptoolbargui          PROTO

; DbgFunctions Prototypes:
AssembleAtEx                    PROTO :QWORD, :QWORD, :QWORD, :QWORD            ; duint addr, const char* instruction, char* error, bool fillnop
SectionFromAddr                 PROTO :QWORD, :QWORD                            ; duint addr, char* section
ModNameFromAddr                 PROTO :QWORD, :QWORD, :QWORD                    ; duint addr, char* modname, bool extension
ModBaseFromAddr                 PROTO :QWORD                                    ; duint addr;
ModBaseFromName                 PROTO :QWORD                                    ; const char* modname;
ModSizeFromAddr                 PROTO :QWORD                                    ; duint addr;
Assemble                        PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD    ; duint addr, unsigned char* dest, int* size, const char* instruction, char* error
PatchGet                        PROTO :QWORD                                    ; duint addr
PatchInRange                    PROTO :QWORD, :QWORD                            ; duint start, duint end
MemPatch                        PROTO :QWORD, :QWORD, :QWORD                    ; duint va, const unsigned char* src, duint size
PatchRestoreRange               PROTO :QWORD, :QWORD                            ; duint start, duint end
PatchEnum                       PROTO :QWORD, :QWORD                            ; DBGPATCHINFO* patchlist, size_t* cbsize
PatchRestore                    PROTO :QWORD                                    ; duint addr
PatchFile                       PROTO :QWORD, :QWORD, :QWORD, :QWORD            ; DBGPATCHINFO* patchlist, int count, const char* szFileName, char* error
ModPathFromAddr                 PROTO :QWORD, :QWORD, :QWORD
ModPathFromName                 PROTO :QWORD, :QWORD, :QWORD                    ; const char* modname, char* path, int size
DisasmFast                      PROTO :QWORD, :QWORD, :QWORD                    ; unsigned char* data, duint addr, BASIC_INSTRUCTION_INFO* basicinfo
GetPageRights                   PROTO :QWORD, :QWORD                            ; duint addr, char* rights
SetPageRights                   PROTO :QWORD, :QWORD                            ; duint addr, const char* rights


; Other useful functions
DbgMapPE32File                  PROTO :QWORD, :QWORD
DbgUnmapPE32File                PROTO :QWORD

DbgGetEntryExitPoints           PROTO :QWORD, :QWORD
DbgGetSectionsFromAddr          PROTO :QWORD, :QWORD, :QWORD
DbgGetSectionsFromName          PROTO :QWORD, :QWORD, :QWORD


DbgGetSectionsCount             PROTO :QWORD
DbgGetSectionVirtualOffset      PROTO :QWORD, :QWORD
DbgGetSectionVirtualSize        PROTO :QWORD, :QWORD


.CONST
MODSECTIONINFO                  STRUCT
    qwSectionAddress            DQ ? ; Virtual address duint
    qwSectionSize               DQ ? ; Virtual size duint 
    szSectionName               DB [MAX_SECTION_SIZE * 5] DUP (?) ; Escaped section name char 
MODSECTIONINFO                  ENDS









