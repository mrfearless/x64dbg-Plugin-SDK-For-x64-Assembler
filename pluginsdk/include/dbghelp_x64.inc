;--------------------------------------------------------------------------------------------------------
; x64dbg plugin SDK for JWasm64 - fearless 2015 - www.LetTheLight.in
;
; Supports 64bit x64dbg only.
;
; The x64dbg plugin SDK for JWasm64 can be downloaded from here:
; https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-JWasm64/overview
;
; The x64dbg plugin SDK for Masm32 can be downloaded from here:
; https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-masm/overview
;
; Include file for dbghelp.dll exports, constants and structures.
;
;--------------------------------------------------------------------------------------------------------

DbgHelpCreateUserDump PROTO :QWORD,:QWORD,:QWORD
DbgHelpCreateUserDumpW PROTO :QWORD,:QWORD,:QWORD
EnumDirTree PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EnumDirTreeW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
EnumerateLoadedModules64 PROTO :QWORD,:QWORD,:QWORD
EnumerateLoadedModules PROTO :QWORD,:QWORD,:QWORD
EnumerateLoadedModulesEx PROTO :QWORD,:QWORD,:QWORD
EnumerateLoadedModulesExW PROTO :QWORD,:QWORD,:QWORD
EnumerateLoadedModulesW64 PROTO :QWORD,:QWORD,:QWORD
ExtensionApiVersion PROTO 
FindDebugInfoFile PROTO :QWORD,:QWORD,:QWORD
FindDebugInfoFileEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FindDebugInfoFileExW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FindExecutableImage PROTO :QWORD,:QWORD,:QWORD
FindExecutableImageEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FindExecutableImageExW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FindFileInPath PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FindFileInSearchPath PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
GetSymLoadError PROTO 
GetTimestampForLoadedLibrary PROTO :QWORD
ImageDirectoryEntryToData PROTO :QWORD,:QWORD,:QWORD,:QWORD
ImageDirectoryEntryToDataEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ImageNtHeader PROTO :QWORD
ImageRvaToSection PROTO :QWORD,:QWORD,:QWORD
ImageRvaToVa PROTO :QWORD,:QWORD,:QWORD,:QWORD
ImagehlpApiVersion PROTO 
ImagehlpApiVersionEx PROTO :QWORD
MakeSureDirectoryPathExists PROTO :QWORD
MapDebugInformation PROTO :QWORD,:QWORD,:QWORD,:QWORD
MiniDumpReadDumpStream PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
MiniDumpWriteDump PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RangeMapAddPeImageSections PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RangeMapCreate PROTO 
RangeMapFree PROTO :QWORD
RangeMapRead PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RangeMapRemove PROTO :QWORD,:QWORD,:QWORD
RangeMapWrite PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
RemoveInvalidModuleList PROTO :QWORD
ReportSymbolLoadSummary PROTO :QWORD,:QWORD,:QWORD
SearchTreeForFile PROTO :QWORD,:QWORD,:QWORD
SearchTreeForFileW PROTO :QWORD,:QWORD,:QWORD
SetCheckUserInterruptShared PROTO :QWORD
SetSymLoadError PROTO :QWORD
StackWalk64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
StackWalk PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
StackWalkEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymAddSourceStreamA PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymAddSourceStream equ <SymAddSourceStreamA>

SymAddSourceStreamW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymAddSymbol PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymAddSymbolW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymAddrIncludeInlineTrace PROTO :QWORD,:QWORD,:QWORD
SymCleanup PROTO :QWORD
SymCompareInlineTrace PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymDeleteSymbol PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymDeleteSymbolW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumLines PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumLinesW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumProcesses PROTO :QWORD,:QWORD
SymEnumSourceFileTokens PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymEnumSourceFiles PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSourceFilesW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSourceLines PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSourceLinesW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSym PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbols PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbolsEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbolsExW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbolsForAddr PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbolsForAddrW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumSymbolsW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumTypes PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumTypesByName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumTypesByNameW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumTypesW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumerateModules64 PROTO :QWORD,:QWORD,:QWORD
SymEnumerateModules PROTO :QWORD,:QWORD,:QWORD
SymEnumerateModulesW64 PROTO :QWORD,:QWORD,:QWORD
SymEnumerateSymbols64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumerateSymbols PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymEnumerateSymbolsW64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymEnumerateSymbolsW PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymFindDebugInfoFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFindDebugInfoFileW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFindExecutableImage PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFindExecutableImageW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFindFileInPath PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFindFileInPathW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromAddr PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromAddrW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromIndex PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromIndexW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromInlineContext PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromInlineContextW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromName PROTO :QWORD,:QWORD,:QWORD
SymFromNameW PROTO :QWORD,:QWORD,:QWORD
SymFromToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFromTokenW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFunctionTableAccess64 PROTO :QWORD,:QWORD,:QWORD
SymFunctionTableAccess64AccessRoutines PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymFunctionTableAccess PROTO :QWORD,:QWORD
SymGetFileLineOffsets64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetHomeDirectory PROTO :QWORD,:QWORD,:QWORD
SymGetHomeDirectoryW PROTO :QWORD,:QWORD,:QWORD
SymGetLineFromAddr64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromAddr PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromAddrW64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromInlineContext PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromInlineContextW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromName64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineFromNameW64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetLineNext64 PROTO :QWORD,:QWORD
SymGetLineNext PROTO :QWORD,:QWORD
SymGetLineNextW64 PROTO :QWORD,:QWORD
SymGetLinePrev64 PROTO :QWORD,:QWORD
SymGetLinePrev PROTO :QWORD,:QWORD
SymGetLinePrevW64 PROTO :QWORD,:QWORD
SymGetModuleBase64 PROTO :QWORD,:QWORD,:QWORD
SymGetModuleBase PROTO :QWORD,:QWORD
SymGetModuleInfo64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymGetModuleInfo PROTO :QWORD,:QWORD,:QWORD
SymGetModuleInfoW64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymGetModuleInfoW PROTO :QWORD,:QWORD,:QWORD
SymGetOmaps PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetOptions PROTO 
SymGetScope PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetScopeW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSearchPath PROTO :QWORD,:QWORD,:QWORD
SymGetSearchPathW PROTO :QWORD,:QWORD,:QWORD
SymGetSourceFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceFileFromToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceFileFromTokenW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceFileToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceFileTokenW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceFileW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceVarFromToken PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSourceVarFromTokenW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSymFromAddr64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSymFromAddr PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymGetSymFromName64 PROTO :QWORD,:QWORD,:QWORD
SymGetSymFromName PROTO :QWORD,:QWORD,:QWORD
SymGetSymNext64 PROTO :QWORD,:QWORD
SymGetSymNext PROTO :QWORD,:QWORD
SymGetSymPrev64 PROTO :QWORD,:QWORD
SymGetSymPrev PROTO :QWORD,:QWORD
SymGetSymbolFile PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetSymbolFileW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetTypeFromName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetTypeFromNameW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetTypeInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymGetTypeInfoEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymGetUnwindInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymInitialize PROTO :QWORD,:QWORD,:QWORD
SymInitializeW PROTO :QWORD,:QWORD,:QWORD
SymLoadModule64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymLoadModule PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymLoadModuleEx PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymLoadModuleExW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymMatchFileName PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymMatchFileNameW PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymMatchStringA PROTO :QWORD,:QWORD,:QWORD
SymMatchString equ <SymMatchStringA>

SymMatchStringW PROTO :QWORD,:QWORD,:QWORD
SymNext PROTO :QWORD,:QWORD
SymNextW PROTO :QWORD,:QWORD
SymPrev PROTO :QWORD,:QWORD
SymPrevW PROTO :QWORD,:QWORD
SymQueryInlineTrace PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymRefreshModuleList PROTO :QWORD
SymRegisterCallback64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymRegisterCallback PROTO :QWORD,:QWORD,:QWORD
SymRegisterCallbackW64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymRegisterFunctionEntryCallback64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymRegisterFunctionEntryCallback PROTO :QWORD,:QWORD,:QWORD
SymSearch PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSearchW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSetContext PROTO :QWORD,:QWORD,:QWORD
SymSetHomeDirectory PROTO :QWORD,:QWORD
SymSetHomeDirectoryW PROTO :QWORD,:QWORD
SymSetOptions PROTO :QWORD
SymSetParentWindow PROTO :QWORD
SymSetScopeFromAddr PROTO :QWORD,:QWORD,:QWORD
SymSetScopeFromIndex PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSetScopeFromInlineContext PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSetSearchPath PROTO :QWORD,:QWORD
SymSetSearchPathW PROTO :QWORD,:QWORD
SymSrvDeltaName PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvDeltaNameW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetFileIndexInfo PROTO :QWORD,:QWORD,:QWORD
SymSrvGetFileIndexInfoW PROTO :QWORD,:QWORD,:QWORD
SymSrvGetFileIndexString PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetFileIndexStringW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetFileIndexes PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetFileIndexesW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetSupplement PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSrvGetSupplementW PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSrvIsStore PROTO :QWORD,:QWORD
SymSrvIsStoreW PROTO :QWORD,:QWORD
SymSrvStoreFile PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSrvStoreFileW PROTO :QWORD,:QWORD,:QWORD,:QWORD
SymSrvStoreSupplement PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymSrvStoreSupplementW PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
SymUnDName64 PROTO :QWORD,:QWORD,:QWORD
SymUnDName PROTO :QWORD,:QWORD,:QWORD
SymUnloadModule64 PROTO :QWORD,:QWORD,:QWORD
SymUnloadModule PROTO :QWORD,:QWORD
UnDecorateSymbolName PROTO :QWORD,:QWORD,:QWORD,:QWORD
UnDecorateSymbolNameW PROTO :QWORD,:QWORD,:QWORD,:QWORD
UnmapDebugInformation PROTO :QWORD
WinDbgExtensionDllInit PROTO :QWORD,:QWORD,:QWORD
block PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
chksym PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
dbghelp PROTO :QWORD,:QWORD
;dh PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
fptr PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
homedir PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
inlinedbg PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
itoldyouso PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
lmi PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
lminfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
omap PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
optdbgdump PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
optdbgdumpaddr PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
srcfiles PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
stack_force_ebp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
stackdbg PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sym PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
symsrv PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
vc7fpo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD


