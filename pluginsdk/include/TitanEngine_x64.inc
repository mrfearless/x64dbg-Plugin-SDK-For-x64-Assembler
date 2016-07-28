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
; Include file for TitanEngine_x86.dll exports, constants and structures.
;
; This is a consolidation and conversion of the original plugin TitanEngine.h file to a format that will
; work with MASM and other assemblers (possibly).
;
; Where are name of a structure, structure field or other definitions conflict with a masm reserved word
; I have appended a underscore at the end of the item in most cases to work around that issue.
; There are a few exceptions: addr becomes address, end becomes finish, just for clarity.
;
;--------------------------------------------------------------------------------------------------------

; Global.Function.Declaration:
; TitanEngine.Dumper.functions:
DumpProcess                     PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID ImageBase, const char* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessW                    PROTO :QWORD, :QWORD, :QWORD, :QWORD; (HANDLE hProcess, LPVOID ImageBase, const wchar_t* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessEx                   PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID ImageBase, const char* szDumpFileName, ULONG_PTR EntryPoint);
DumpProcessExW                  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID ImageBase, const wchar_t* szDumpFileName, ULONG_PTR EntryPoint);
DumpMemory                      PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, ULONG_PTR MemorySize, const char* szDumpFileName);
DumpMemoryW                     PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, ULONG_PTR MemorySize, const wchar_t* szDumpFileName);
DumpMemoryEx                    PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID MemoryStart, ULONG_PTR MemorySize, const char* szDumpFileName);
DumpMemoryExW                   PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID MemoryStart, ULONG_PTR MemorySize, const wchar_t* szDumpFileName);
DumpRegions                     PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const char* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsW                    PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const wchar_t* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsEx                   PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const char* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpRegionsExW                  PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const wchar_t* szDumpFolder, bool DumpAboveImageBaseOnly);
DumpModule                      PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID ModuleBase, const char* szDumpFileName);
DumpModuleW                     PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID ModuleBase, const wchar_t* szDumpFileName);
DumpModuleEx                    PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID ModuleBase, const char* szDumpFileName);
DumpModuleExW                   PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID ModuleBase, const wchar_t* szDumpFileName);
PastePEHeader                   PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID ImageBase, const char* szDebuggedFileName);
PastePEHeaderW                  PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID ImageBase, const wchar_t* szDebuggedFileName);
ExtractSection                  PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szDumpFileName, DWORD SectionNumber);
ExtractSectionW                 PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szDumpFileName, DWORD SectionNumber);
ResortFileSections              PROTO :QWORD ; (const char* szFileName);
ResortFileSectionsW             PROTO :QWORD ; (const wchar_t* szFileName);
FindOverlay                     PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, LPDWORD OverlayStart, LPDWORD OverlaySize);
FindOverlayW                    PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, LPDWORD OverlayStart, LPDWORD OverlaySize);
ExtractOverlay                  PROTO :QWORD, :QWORD ; (const char* szFileName, const char* szExtactedFileName);
ExtractOverlayW                 PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szExtactedFileName);
AddOverlay                      PROTO :QWORD, :QWORD ; (const char* szFileName, const char* szOverlayFileName);
AddOverlayW                     PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szOverlayFileName);
CopyOverlay                     PROTO :QWORD, :QWORD ; (const char* szInFileName, const char* szOutFileName);
CopyOverlayW                    PROTO :QWORD, :QWORD ; (const wchar_t* szInFileName, const wchar_t* szOutFileName);
RemoveOverlay                   PROTO :QWORD ; (const char* szFileName);
RemoveOverlayW                  PROTO :QWORD ; (const wchar_t* szFileName);
MakeAllSectionsRWE              PROTO :QWORD ; (const char* szFileName);
MakeAllSectionsRWEW             PROTO :QWORD ; (const wchar_t* szFileName);
AddNewSectionEx                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szSectionName, DWORD SectionSize, DWORD SectionAttributes, LPVOID SectionContent, DWORD ContentSize);
AddNewSectionExW                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const char* szSectionName, DWORD SectionSize, DWORD SectionAttributes, LPVOID SectionContent, DWORD ContentSize);
AddNewSection                   PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szSectionName, DWORD SectionSize);
AddNewSectionW                  PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const char* szSectionName, DWORD SectionSize);
ResizeLastSection               PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD NumberOfExpandBytes, bool AlignResizeData);
ResizeLastSectionW              PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD NumberOfExpandBytes, bool AlignResizeData);
SetSharedOverlay                PROTO :QWORD ; (const char* szFileName);
SetSharedOverlayW               PROTO :QWORD ; (const wchar_t* szFileName);
GetSharedOverlay                PROTO
GetSharedOverlayW               PROTO
DeleteLastSection               PROTO :QWORD ; (const char* szFileName);
DeleteLastSectionW              PROTO :QWORD ; (const wchar_t* szFileName);
DeleteLastSectionEx             PROTO :QWORD, :QWORD ; (const char* szFileName, DWORD NumberOfSections);
DeleteLastSectionExW            PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD NumberOfSections);
GetPE32DataFromMappedFile       PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD WhichSection, DWORD WhichData);
GetPE32Data                     PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD WhichSection, DWORD WhichData);
GetPE32DataW                    PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD WhichSection, DWORD WhichData);
GetPE32DataFromMappedFileEx     PROTO :QWORD, :QWORD ; (ULONG_PTR FileMapVA, LPVOID DataStorage);
GetPE32DataEx                   PROTO :QWORD, :QWORD ; (const char* szFileName, LPVOID DataStorage);
GetPE32DataExW                  PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID DataStorage);
SetPE32DataForMappedFile        PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32Data                     PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32DataW                    PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD WhichSection, DWORD WhichData, ULONG_PTR NewDataValue);
SetPE32DataForMappedFileEx      PROTO :QWORD, :QWORD ; (ULONG_PTR FileMapVA, LPVOID DataStorage);
SetPE32DataEx                   PROTO :QWORD, :QWORD ; (const char* szFileName, LPVOID DataStorage);
SetPE32DataExW                  PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID DataStorage);
GetPE32SectionNumberFromVA      PROTO :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert);
ConvertVAtoFileOffset           PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert, bool ReturnType);
ConvertVAtoFileOffsetEx         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, ULONG_PTR ImageBase, ULONG_PTR AddressToConvert, bool AddressIsRVA, bool ReturnType);
ConvertFileOffsetToVA           PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR AddressToConvert, bool ReturnType);
ConvertFileOffsetToVAEx         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, ULONG_PTR ImageBase, ULONG_PTR AddressToConvert, bool ReturnType);
MemoryReadSafe                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead);
MemoryWriteSafe                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten);

; TitanEngine.Realigner.functions:
FixHeaderCheckSum               PROTO :QWORD ; (const char* szFileName);
FixHeaderCheckSumW              PROTO :QWORD ; (const wchar_t* szFileName);
RealignPE                       PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, DWORD RealingMode);
RealignPEEx                     PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD RealingFileSize, DWORD ForcedFileAlignment);
RealignPEExW                    PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD RealingFileSize, DWORD ForcedFileAlignment);
WipeSection                     PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, int WipeSectionNumber, bool RemovePhysically);
WipeSectionW                    PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, int WipeSectionNumber, bool RemovePhysically);
IsPE32FileValidEx               PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD CheckDepth, LPVOID FileStatusInfo);
IsPE32FileValidExW              PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD CheckDepth, LPVOID FileStatusInfo);
FixBrokenPE32FileEx             PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, LPVOID FileStatusInfo, LPVOID FileFixInfo);
FixBrokenPE32FileExW            PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID FileStatusInfo, LPVOID FileFixInfo);
IsFileDLL                       PROTO :QWORD, :QWORD ; (const char* szFileName, ULONG_PTR FileMapVA);
IsFileDLLW                      PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, ULONG_PTR FileMapVA);

; TitanEngine.Hider.functions:
GetPEBLocation                  PROTO :QWORD ; (HANDLE hProcess);
GetPEBLocation64                PROTO :QWORD ; (HANDLE hProcess);
GetTEBLocation                  PROTO :QWORD ; (HANDLE hThread);
GetTEBLocation64                PROTO :QWORD ; (HANDLE hThread);
HideDebugger                    PROTO :QWORD, :QWORD ; (HANDLE hProcess, DWORD PatchAPILevel);
UnHideDebugger                  PROTO :QWORD, :QWORD ; (HANDLE hProcess, DWORD PatchAPILevel);

; TitanEngine.Relocater.functions:
RelocaterCleanup                PROTO
RelocaterInit                   PROTO :QWORD, :QWORD, :QWORD ; (DWORD MemorySize, ULONG_PTR OldImageBase, ULONG_PTR NewImageBase);
RelocaterAddNewRelocation       PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR RelocateAddress, DWORD RelocateState);
RelocaterEstimatedSize          PROTO
RelocaterExportRelocation       PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR StorePlace, DWORD StorePlaceRVA, ULONG_PTR FileMapVA);
RelocaterExportRelocationEx     PROTO :QWORD, :QWORD ; (const char* szFileName, const char* szSectionName);
RelocaterExportRelocationExW    PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, const char* szSectionName);
RelocaterGrabRelocationTable    PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR MemoryStart, DWORD MemorySize);
RelocaterGrabRelocationTableEx  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR MemoryStart, ULONG_PTR MemorySize, DWORD NtSizeOfImage);
RelocaterMakeSnapshot           PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const char* szSaveFileName, LPVOID MemoryStart, ULONG_PTR MemorySize);
RelocaterMakeSnapshotW          PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const wchar_t* szSaveFileName, LPVOID MemoryStart, ULONG_PTR MemorySize);
RelocaterCompareTwoSnapshots    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR LoadedImageBase, ULONG_PTR NtSizeOfImage, const char* szDumpFile1, const char* szDumpFile2, ULONG_PTR MemStart);
RelocaterCompareTwoSnapshotsW   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR LoadedImageBase, ULONG_PTR NtSizeOfImage, const wchar_t* szDumpFile1, const wchar_t* szDumpFile2, ULONG_PTR MemStart);
RelocaterChangeFileBase         PROTO :QWORD, :QWORD ; (const char* szFileName, ULONG_PTR NewImageBase);
RelocaterChangeFileBaseW        PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, ULONG_PTR NewImageBase);
RelocaterRelocateMemoryBlock    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR MemoryLocation, void* RelocateMemory, DWORD RelocateMemorySize, ULONG_PTR CurrentLoadedBase, ULONG_PTR RelocateBase);
RelocaterWipeRelocationTable    PROTO :QWORD ; (const char* szFileName);
RelocaterWipeRelocationTableW   PROTO :QWORD ; (const wchar_t* szFileName);

; TitanEngine.Resourcer.functions:
ResourcerLoadFileForResourceUse PROTO :QWORD ; (const char* szFileName);
ResourcerLoadFileForResourceUseW PROTO :QWORD ; (const wchar_t* szFileName);
ResourcerFreeLoadedFile         PROTO :QWORD ; (LPVOID LoadedFileBase);
ResourcerExtractResourceFromFileEx PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, const char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerExtractResourceFromFile PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerExtractResourceFromFileW PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, char* szResourceType, const char* szResourceName, const char* szExtractedFileName);
ResourcerFindResource           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szResourceType, DWORD ResourceType, const char* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerFindResourceW          PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szResourceType, DWORD ResourceType, const wchar_t* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerFindResourceEx         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, const wchar_t* szResourceType, DWORD ResourceType, const wchar_t* szResourceName, DWORD ResourceName, DWORD ResourceLanguage, PULONG_PTR pResourceData, LPDWORD pResourceSize);
ResourcerEnumerateResource      PROTO :QWORD, :QWORD ; (const char* szFileName, void* CallBack);
ResourcerEnumerateResourceW     PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, void* CallBack);
ResourcerEnumerateResourceEx    PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD FileSize, void* CallBack);

; TitanEngine.Threader.functions:
ThreaderImportRunningThreadData PROTO :QWORD ; (DWORD ProcessId);
ThreaderGetThreadInfo           PROTO :QWORD, :QWORD ; (HANDLE hThread, DWORD ThreadId);
ThreaderEnumThreadInfo          PROTO :QWORD ; (void* EnumCallBack);
ThreaderPauseThread             PROTO :QWORD ; (HANDLE hThread);
ThreaderResumeThread            PROTO :QWORD ; (HANDLE hThread);
ThreaderTerminateThread         PROTO :QWORD, :QWORD ; (HANDLE hThread, DWORD ThreadExitCode);
ThreaderPauseAllThreads         PROTO :QWORD ; (bool LeaveMainRunning);
ThreaderResumeAllThreads        PROTO :QWORD ; (bool LeaveMainPaused);
ThreaderPauseProcess            PROTO
ThreaderResumeProcess           PROTO
ThreaderCreateRemoteThread      PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR ThreadStartAddress, bool AutoCloseTheHandle, LPVOID ThreadPassParameter, LPDWORD ThreadId);
ThreaderInjectAndExecuteCode    PROTO :QWORD, :QWORD, :QWORD ; (LPVOID InjectCode, DWORD StartDelta, DWORD InjectSize);
ThreaderCreateRemoteThreadEx    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR ThreadStartAddress, bool AutoCloseTheHandle, LPVOID ThreadPassParameter, LPDWORD ThreadId);
ThreaderInjectAndExecuteCodeEx  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID InjectCode, DWORD StartDelta, DWORD InjectSize);
ThreaderSetCallBackForNextExitThreadEvent PROTO :QWORD ; (LPVOID exitThreadCallBack);
ThreaderIsThreadStillRunning    PROTO :QWORD ; (HANDLE hThread);
ThreaderIsThreadActive          PROTO :QWORD ; (HANDLE hThread);
ThreaderIsAnyThreadActive       PROTO
ThreaderExecuteOnlyInjectedThreads PROTO
ThreaderGetOpenHandleForThread  PROTO :QWORD ; (DWORD ThreadId);
ThreaderIsExceptionInMainThread PROTO

; TitanEngine.Debugger.functions:
StaticDisassembleEx             PROTO :QWORD, :QWORD ; (ULONG_PTR DisassmStart, LPVOID DisassmAddress);
StaticDisassemble               PROTO :QWORD ; (LPVOID DisassmAddress);
DisassembleEx                   PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID DisassmAddress, bool ReturnInstructionType);
;Disassemble                     PROTO :QWORD ; (LPVOID DisassmAddress);
StaticLengthDisassemble         PROTO :QWORD ; (LPVOID DisassmAddress);
LengthDisassembleEx             PROTO :QWORD, :QWORD ; (HANDLE hProcess, LPVOID DisassmAddress);
LengthDisassemble               PROTO :QWORD ; (LPVOID DisassmAddress);
InitDebug                       PROTO :QWORD, :QWORD, :QWORD ; (char* szFileName, char* szCommandLine, char* szCurrentFolder);
InitDebugW                      PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder);
InitDebugEx                     PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szCommandLine, const char* szCurrentFolder, LPVOID EntryCallBack);
InitDebugExW                    PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, LPVOID EntryCallBack);
InitDLLDebug                    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, bool ReserveModuleBase, const char* szCommandLine, const char* szCurrentFolder, LPVOID EntryCallBack);
InitDLLDebugW                   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, bool ReserveModuleBase, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, LPVOID EntryCallBack);
StopDebug                       PROTO
SetBPXOptions                   PROTO :QWORD ; (long DefaultBreakPointType);
IsBPXEnabled                    PROTO :QWORD ; (ULONG_PTR bpxAddress);
EnableBPX                       PROTO :QWORD ; (ULONG_PTR bpxAddress);
DisableBPX                      PROTO :QWORD ; (ULONG_PTR bpxAddress);
SetBPX                          PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR bpxAddress, DWORD bpxType, LPVOID bpxCallBack);
DeleteBPX                       PROTO :QWORD ; (ULONG_PTR bpxAddress);
SafeDeleteBPX                   PROTO :QWORD ; (ULONG_PTR bpxAddress);
SetAPIBreakPoint                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxType, DWORD bpxPlace, LPVOID bpxCallBack);
DeleteAPIBreakPoint             PROTO :QWORD, :QWORD, :QWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxPlace);
SafeDeleteAPIBreakPoint         PROTO :QWORD, :QWORD, :QWORD ; (const char* szDLLName, const char* szAPIName, DWORD bpxPlace);
SetMemoryBPX                    PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory, LPVOID bpxCallBack);
SetMemoryBPXEx                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory, DWORD BreakPointType, bool RestoreOnHit, LPVOID bpxCallBack);
RemoveMemoryBPX                 PROTO :QWORD, :QWORD ; (ULONG_PTR MemoryStart, SIZE_T SizeOfMemory);
GetContextFPUDataEx             PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, void* FPUSaveArea);
Getx87FPURegisters              PROTO :QWORD, :QWORD, :QWORD ; (x87FPURegister_t x87FPURegisters[8], TITAN_ENGINE_CONTEXT_t* titcontext);
GetMMXRegisters                 PROTO :QWORD, :QWORD ; (uint64_t mmx[8], TITAN_ENGINE_CONTEXT_t* titcontext);
GetFullContextDataEx            PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
SetFullContextDataEx            PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
GetContextDataEx                PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, DWORD IndexOfRegister);
GetContextData                  PROTO :QWORD ; (DWORD IndexOfRegister);
SetContextFPUDataEx             PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, void* FPUSaveArea);
SetContextDataEx                PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hActiveThread, DWORD IndexOfRegister, ULONG_PTR NewRegisterValue);
SetContextData                  PROTO :QWORD, :QWORD ; (DWORD IndexOfRegister, ULONG_PTR NewRegisterValue);
GetAVXContext                   PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
SetAVXContext                   PROTO :QWORD, :QWORD ; (HANDLE hActiveThread, TITAN_ENGINE_CONTEXT_t* titcontext);
ClearExceptionNumber            PROTO
CurrentExceptionNumber          PROTO
MatchPatternEx                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, void* MemoryToCheck, int SizeOfMemoryToCheck, void* PatternToMatch, int SizeOfPatternToMatch, PBYTE WildCard);
MatchPattern                    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (void* MemoryToCheck, int SizeOfMemoryToCheck, void* PatternToMatch, int SizeOfPatternToMatch, PBYTE WildCard);
externdef C FindEx             :PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, LPBYTE WildCard);

Find                            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; Find(LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, LPBYTE WildCard);
FillEx                          PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, PBYTE FillByte);
Fill                            PROTO :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, PBYTE FillByte);
PatchEx                         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID ReplacePattern, DWORD ReplaceSize, bool AppendNOP, bool PrependNOP);
Patch                           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, LPVOID ReplacePattern, DWORD ReplaceSize, bool AppendNOP, bool PrependNOP);
ReplaceEx                       PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, DWORD NumberOfRepetitions, LPVOID ReplacePattern, DWORD ReplaceSize, PBYTE WildCard);
Replace                         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, LPVOID SearchPattern, DWORD PatternSize, DWORD NumberOfRepetitions, LPVOID ReplacePattern, DWORD ReplaceSize, PBYTE WildCard);
GetDebugData                    PROTO
GetTerminationData              PROTO
GetExitCode                     PROTO
GetDebuggedDLLBaseAddress       PROTO
GetDebuggedFileBaseAddress      PROTO
GetRemoteString                 PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, LPVOID StringAddress, LPVOID StringStorage, int MaximumStringSize);
GetFunctionParameter            PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD FunctionType, DWORD ParameterNumber, DWORD ParameterType);
GetJumpDestinationEx            PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR InstructionAddress, bool JustJumps);
GetJumpDestination              PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR InstructionAddress);
IsJumpGoingToExecuteEx          PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, HANDLE hThread, ULONG_PTR InstructionAddress, ULONG_PTR RegFlags);
IsJumpGoingToExecute            PROTO
SetCustomHandler                PROTO :QWORD, :QWORD ; (DWORD ExceptionId, LPVOID CallBack);
ForceClose                      PROTO
StepInto                        PROTO :QWORD ; (LPVOID traceCallBack);
StepOver                        PROTO :QWORD ; (LPVOID traceCallBack);
StepOut                         PROTO :QWORD, :QWORD ; (LPVOID StepOut, bool StepFinal);
SingleStep                      PROTO :QWORD, :QWORD ; (DWORD StepCount, LPVOID StepCallBack);
GetUnusedHardwareBreakPointRegister PROTO :QWORD ; (LPDWORD RegisterIndex);
SetHardwareBreakPointEx         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hActiveThread, ULONG_PTR bpxAddress, DWORD IndexOfRegister, DWORD bpxType, DWORD bpxSize, LPVOID bpxCallBack, LPDWORD IndexOfSelectedRegister);
SetHardwareBreakPoint           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR bpxAddress, DWORD IndexOfRegister, DWORD bpxType, DWORD bpxSize, LPVOID bpxCallBack);
DeleteHardwareBreakPoint        PROTO :QWORD ; (DWORD IndexOfRegister);
RemoveAllBreakPoints            PROTO :QWORD ; (DWORD RemoveOption);
TitanGetProcessInformation      PROTO ; returns pointer to PROCESS_INFORMATION
TitanGetStartupInformation      PROTO ; returns pointer to STARTUPINFOW
DebugLoop                       PROTO
SetDebugLoopTimeOut             PROTO :QWORD ; (DWORD TimeOut);
SetNextDbgContinueStatus        PROTO :QWORD ; (DWORD SetDbgCode);
AttachDebugger                  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, bool KillOnExit, LPVOID DebugInfo, LPVOID CallBack);
DetachDebugger                  PROTO :QWORD ; (DWORD ProcessId);
DetachDebuggerEx                PROTO :QWORD ; (DWORD ProcessId);
DebugLoopEx                     PROTO :QWORD ; (DWORD TimeOut);
AutoDebugEx                     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, bool ReserveModuleBase, const char* szCommandLine, const char* szCurrentFolder, DWORD TimeOut, LPVOID EntryCallBack);
AutoDebugExW                    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, bool ReserveModuleBase, const wchar_t* szCommandLine, const wchar_t* szCurrentFolder, DWORD TimeOut, LPVOID EntryCallBack);
IsFileBeingDebugged             PROTO
SetErrorModel                   PROTO :QWORD ; (bool DisplayErrorMessages);

; TitanEngine.FindOEP.functions:
FindOEPInit                     PROTO
FindOEPGenerically              PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, LPVOID TraceInitCallBack, LPVOID CallBack);
FindOEPGenericallyW             PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID TraceInitCallBack, LPVOID CallBack);

; TitanEngine.Importer.functions:
ImporterAddNewDll               PROTO :QWORD, :QWORD ; (const char* szDLLName, ULONG_PTR FirstThunk);
ImporterAddNewAPI               PROTO :QWORD, :QWORD ; (const char* szAPIName, ULONG_PTR ThunkValue);
ImporterAddNewOrdinalAPI        PROTO :QWORD, :QWORD ; (ULONG_PTR OrdinalNumber, ULONG_PTR ThunkValue);
ImporterGetAddedDllCount        PROTO
ImporterGetAddedAPICount        PROTO
ImporterExportIAT               PROTO :QWORD, :QWORD, :QWORD ; (ULONG_PTR StorePlace, ULONG_PTR FileMapVA, HANDLE hFileMap);
ImporterEstimatedSize           PROTO
ImporterExportIATEx             PROTO :QWORD, :QWORD, :QWORD ; (const char* szDumpFileName, const char* szExportFileName, const char* szSectionName);
ImporterExportIATExW            PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szDumpFileName, const wchar_t* szExportFileName, const wchar_t* szSectionName = L".RL!TEv2");
ImporterFindAPIWriteLocation    PROTO :QWORD ; (const char* szAPIName);
ImporterFindOrdinalAPIWriteLocation PROTO :QWORD ; (ULONG_PTR OrdinalNumber);
ImporterFindAPIByWriteLocation  PROTO :QWORD ; (ULONG_PTR APIWriteLocation);
ImporterFindDLLByWriteLocation  PROTO :QWORD ; (ULONG_PTR APIWriteLocation);
ImporterGetDLLName              PROTO :QWORD ; (ULONG_PTR APIAddress);
ImporterGetDLLNameW             PROTO :QWORD ; (ULONG_PTR APIAddress);
ImporterGetAPIName              PROTO :QWORD ; (ULONG_PTR APIAddress);
ImporterGetAPIOrdinalNumber     PROTO :QWORD ; (ULONG_PTR APIAddress);
ImporterGetAPINameEx            PROTO :QWORD, :QWORD ; (ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetRemoteAPIAddress     PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetRemoteAPIAddressEx   PROTO :QWORD, :QWORD ; (const char* szDLLName, const char* szAPIName);
ImporterGetLocalAPIAddress      PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLNameFromDebugee   PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLNameFromDebugeeW  PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetAPINameFromDebugee   PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetAPIOrdinalNumberFromDebugee      PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetDLLIndexEx           PROTO :QWORD, :QWORD ; (ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetDLLIndex             PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetRemoteDLLBase        PROTO :QWORD, :QWORD ; (HANDLE hProcess, HMODULE LocalModuleBase);
ImporterGetRemoteDLLBaseEx      PROTO :QWORD, :QWORD ; (HANDLE hProcess, const char* szModuleName);
ImporterGetRemoteDLLBaseExW     PROTO :QWORD, :QWORD ; (HANDLE hProcess, const wchar_t* szModuleName);
ImporterIsForwardedAPI          PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedAPIName     PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedDLLName     PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetForwardedDLLIndex    PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress, ULONG_PTR DLLBasesList);
ImporterGetForwardedAPIOrdinalNumber PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetNearestAPIAddress    PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterGetNearestAPIName       PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR APIAddress);
ImporterCopyOriginalIAT         PROTO :QWORD, :QWORD ; (const char* szOriginalFile, const char* szDumpFile);
ImporterCopyOriginalIATW        PROTO :QWORD, :QWORD ; (const wchar_t* szOriginalFile, const wchar_t* szDumpFile);
ImporterLoadImportTable         PROTO :QWORD ; (const char* szFileName);
ImporterLoadImportTableW        PROTO :QWORD ; (const wchar_t* szFileName);
ImporterMoveOriginalIAT         PROTO :QWORD, :QWORD, :QWORD ; (const char* szOriginalFile, const char* szDumpFile, const char* szSectionName);
ImporterMoveOriginalIATW        PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szOriginalFile, const wchar_t* szDumpFile, const char* szSectionName);
ImporterAutoSearchIAT           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const char* szFileName, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterAutoSearchIATW          PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessIds, const wchar_t* szFileName, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterAutoSearchIATEx         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, ULONG_PTR ImageBase, ULONG_PTR SearchStart, LPVOID pIATStart, LPVOID pIATSize);
ImporterEnumAddedData           PROTO :QWORD ; (LPVOID EnumCallBack);
ImporterAutoFixIATEx            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const char* szDumpedFile, const char* szSectionName, bool DumpRunningProcess, bool RealignFile, ULONG_PTR EntryPointAddress, ULONG_PTR ImageBase, ULONG_PTR SearchStart, bool TryAutoFix, bool FixEliminations, LPVOID UnknownPointerFixCallback);
ImporterAutoFixIATExW           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const wchar_t* szDumpedFile, const wchar_t* szSectionName, bool DumpRunningProcess, bool RealignFile, ULONG_PTR EntryPointAddress, ULONG_PTR ImageBase, ULONG_PTR SearchStart,  bool TryAutoFix, bool FixEliminations, LPVOID UnknownPointerFixCallback);
ImporterAutoFixIAT              PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const char* szDumpedFile, ULONG_PTR SearchStart);
ImporterAutoFixIATW             PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, const wchar_t* szDumpedFile, ULONG_PTR SearchStart);
ImporterDeleteAPI               PROTO :QWORD ; (DWORD_PTR apiAddr);

; Global.Engine.Hook.functions:
HooksSafeTransitionEx           PROTO :QWORD, :QWORD, :QWORD ; (LPVOID HookAddressArray, int NumberOfHooks, bool TransitionStart);
HooksSafeTransition             PROTO :QWORD, :QWORD ; (LPVOID HookAddress, bool TransitionStart);
HooksIsAddressRedirected        PROTO :QWORD ; (LPVOID HookAddress);
HooksGetTrampolineAddress       PROTO :QWORD ; (LPVOID HookAddress);
HooksGetHookEntryDetails        PROTO :QWORD ; (LPVOID HookAddress);
HooksInsertNewRedirection       PROTO :QWORD, :QWORD, :QWORD ; (LPVOID HookAddress, LPVOID RedirectTo, int HookType);
HooksInsertNewIATRedirectionEx  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR LoadedModuleBase, const char* szHookFunction, LPVOID RedirectTo);
HooksInsertNewIATRedirection    PROTO :QWORD, :QWORD, :QWORD ; (const char* szModuleName, const char* szHookFunction, LPVOID RedirectTo);
HooksRemoveRedirection          PROTO :QWORD, :QWORD ; (LPVOID HookAddress, bool RemoveAll);
HooksRemoveRedirectionsForModule PROTO :QWORD ; (HMODULE ModuleBase);
HooksRemoveIATRedirection       PROTO :QWORD, :QWORD, :QWORD ; (const char* szModuleName, const char* szHookFunction, bool RemoveAll);
HooksDisableRedirection         PROTO :QWORD, :QWORD ; (LPVOID HookAddress, bool DisableAll);
HooksDisableRedirectionsForModule PROTO :QWORD ; (HMODULE ModuleBase);
HooksDisableIATRedirection      PROTO :QWORD, :QWORD, :QWORD ; (const char* szModuleName, const char* szHookFunction, bool DisableAll);
HooksEnableRedirection          PROTO :QWORD, :QWORD ; (LPVOID HookAddress, bool EnableAll);
HooksEnableRedirectionsForModule PROTO :QWORD ; (HMODULE ModuleBase);
HooksEnableIATRedirection       PROTO :QWORD, :QWORD, :QWORD ; (const char* szModuleName, const char* szHookFunction, bool EnableAll);
HooksScanModuleMemory           PROTO :QWORD, :QWORD ; (HMODULE ModuleBase, LPVOID CallBack);
HooksScanEntireProcessMemory    PROTO :QWORD ; (LPVOID CallBack);
HooksScanEntireProcessMemoryEx  PROTO

; TitanEngine.Tracer.functions:
TracerInit                      PROTO
TracerLevel1                    PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace);
HashTracerLevel1                PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD InputNumberOfInstructions);
TracerDetectRedirection         PROTO :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace);
TracerFixKnownRedirection       PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD RedirectionId);
TracerFixRedirectionViaModule   PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HMODULE hModuleHandle, HANDLE hProcess, ULONG_PTR AddressToTrace, DWORD IdParameter);
TracerFixRedirectionViaImpRecPlugin PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const char* szPluginName, ULONG_PTR AddressToTrace);

; TitanEngine.Exporter.functions:
ExporterCleanup                 PROTO
ExporterSetImageBase            PROTO :QWORD ; (ULONG_PTR ImageBase);
ExporterInit                    PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (DWORD MemorySize, ULONG_PTR ImageBase, DWORD ExportOrdinalBase, const char* szExportModuleName);
ExporterAddNewExport            PROTO :QWORD, :QWORD ; (const char* szExportName, DWORD ExportRelativeAddress);
ExporterAddNewOrdinalExport     PROTO :QWORD, :QWORD ; (DWORD OrdinalNumber, DWORD ExportRelativeAddress);
ExporterGetAddedExportCount     PROTO
ExporterEstimatedSize           PROTO
ExporterBuildExportTable        PROTO :QWORD, :QWORD ; (ULONG_PTR StorePlace, ULONG_PTR FileMapVA);
ExporterBuildExportTableEx      PROTO :QWORD, :QWORD ; (const char* szExportFileName, const char* szSectionName);
ExporterBuildExportTableExW     PROTO :QWORD, :QWORD ; (const wchar_t* szExportFileName, const char* szSectionName);
ExporterLoadExportTable         PROTO :QWORD ; (const char* szFileName);
ExporterLoadExportTableW        PROTO :QWORD ; (const wchar_t* szFileName);

; TitanEngine.Librarian.functions:
LibrarianSetBreakPoint          PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szLibraryName, DWORD bpxType, bool SingleShoot, LPVOID bpxCallBack);
LibrarianRemoveBreakPoint       PROTO :QWORD, :QWORD ; (const char* szLibraryName, DWORD bpxType);
LibrarianGetLibraryInfo         PROTO :QWORD ; (const char* szLibraryName);
LibrarianGetLibraryInfoW        PROTO :QWORD ; (const wchar_t* szLibraryName);
LibrarianGetLibraryInfoEx       PROTO :QWORD ; (void* BaseOfDll);
LibrarianGetLibraryInfoExW      PROTO :QWORD ; (void* BaseOfDll);
LibrarianEnumLibraryInfo        PROTO :QWORD ; (void* EnumCallBack);
LibrarianEnumLibraryInfoW       PROTO :QWORD ; (void* EnumCallBack);

; TitanEngine.Process.functions:
GetActiveProcessId              PROTO :QWORD ; (const char* szImageName);
GetActiveProcessIdW             PROTO :QWORD ; (const wchar_t* szImageName);
EnumProcessesWithLibrary        PROTO :QWORD, :QWORD ; (const char* szLibraryName, void* EnumFunction);
TitanOpenProcess                PROTO :QWORD, :QWORD, :QWORD ; (DWORD dwDesiredAccess, bool bInheritHandle, DWORD dwProcessId);

; TitanEngine.TLSFixer.functions:
TLSBreakOnCallBack              PROTO :QWORD, :QWORD, :QWORD ; (LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks, LPVOID bpxCallBack);
TLSGrabCallBackData             PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, LPVOID ArrayOfCallBacks, LPDWORD NumberOfCallBacks);
TLSGrabCallBackDataW            PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID ArrayOfCallBacks, LPDWORD NumberOfCallBacks);
TLSBreakOnCallBackEx            PROTO :QWORD, :QWORD ; (const char* szFileName, LPVOID bpxCallBack);
TLSBreakOnCallBackExW           PROTO :QWORD, :QWORD ; (const wchar_t* szFileName, LPVOID bpxCallBack);
TLSRemoveCallback               PROTO :QWORD ; (const char* szFileName);
TLSRemoveCallbackW              PROTO :QWORD ; (const wchar_t* szFileName);
TLSRemoveTable                  PROTO :QWORD ; (const char* szFileName);
TLSRemoveTableW                 PROTO :QWORD ; (const wchar_t* szFileName);
TLSBackupData                   PROTO :QWORD ; (const char* szFileName);
TLSBackupDataW                  PROTO :QWORD ; (const wchar_t* szFileName);
TLSRestoreData                  PROTO
TLSBuildNewTable                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, ULONG_PTR StorePlace, ULONG_PTR StorePlaceRVA, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);
TLSBuildNewTableEx              PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szSectionName, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);
TLSBuildNewTableExW             PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const char* szSectionName, LPVOID ArrayOfCallBacks, DWORD NumberOfCallBacks);

; TitanEngine.TranslateName.functions:
TranslateNativeName             PROTO :QWORD ; (const char* szNativeName);
TranslateNativeNameW            PROTO :QWORD ; (const wchar_t* szNativeName);

; TitanEngine.Handler.functions:
HandlerGetActiveHandleCount     PROTO :QWORD ; (DWORD ProcessId);
HandlerIsHandleOpen             PROTO :QWORD, :QWORD ; (DWORD ProcessId, HANDLE hHandle);
HandlerGetHandleName            PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, bool TranslateName);
HandlerGetHandleNameW           PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, bool TranslateName);
HandlerEnumerateOpenHandles     PROTO :QWORD, :QWORD, :QWORD ; (DWORD ProcessId, LPVOID HandleBuffer, DWORD MaxHandleCount);
HandlerGetHandleDetails         PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, HANDLE hHandle, DWORD InformationReturn);
HandlerCloseRemoteHandle        PROTO :QWORD, :QWORD ; (HANDLE hProcess, HANDLE hHandle);
HandlerEnumerateLockHandles     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated, LPVOID HandleDataBuffer, DWORD MaxHandleCount);
HandlerEnumerateLockHandlesW    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated, LPVOID HandleDataBuffer, DWORD MaxHandleCount);
HandlerCloseAllLockHandles      PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerCloseAllLockHandlesW     PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerIsFileLocked             PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);
HandlerIsFileLockedW            PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileOrFolderName, bool NameIsFolder, bool NameIsTranslated);

; TitanEngine.Handler[Mutex].functions:
HandlerEnumerateOpenMutexes     PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, LPVOID HandleBuffer, DWORD MaxHandleCount);
HandlerGetOpenMutexHandle       PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, const char* szMutexString);
HandlerGetOpenMutexHandleW      PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, DWORD ProcessId, const wchar_t* szMutexString);
HandlerGetProcessIdWhichCreatedMutex PROTO :QWORD ; (const char* szMutexString);
HandlerGetProcessIdWhichCreatedMutexW PROTO :QWORD ; (const wchar_t* szMutexString);

; TitanEngine.Injector.functions:
RemoteLoadLibrary               PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const char* szLibraryFile, bool WaitForThreadExit);
RemoteLoadLibraryW              PROTO :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, const wchar_t* szLibraryFile, bool WaitForThreadExit);
RemoteFreeLibrary               PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, HMODULE hModule, const char* szLibraryFile, bool WaitForThreadExit);
RemoteFreeLibraryW              PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hProcess, HMODULE hModule, const wchar_t* szLibraryFile, bool WaitForThreadExit);
RemoteExitProcess               PROTO :QWORD ; (HANDLE hProcess, DWORD ExitCode);

; TitanEngine.StaticUnpacker.functions:
StaticFileLoad                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD DesiredAccess, bool SimulateLoad, LPHANDLE FileHandle, LPDWORD LoadedSize, LPHANDLE FileMap, PULONG_PTR FileMapVA);
StaticFileLoadW                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD DesiredAccess, bool SimulateLoad, LPHANDLE FileHandle, LPDWORD LoadedSize, LPHANDLE FileMap, PULONG_PTR FileMapVA);
StaticFileUnload                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, bool CommitChanges, HANDLE FileHandle, DWORD LoadedSize, HANDLE FileMap, ULONG_PTR FileMapVA);
StaticFileUnloadW               PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, bool CommitChanges, HANDLE FileHandle, DWORD LoadedSize, HANDLE FileMap, ULONG_PTR FileMapVA);
StaticFileOpen                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, DWORD DesiredAccess, LPHANDLE FileHandle, LPDWORD FileSizeLow, LPDWORD FileSizeHigh);
StaticFileOpenW                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, DWORD DesiredAccess, LPHANDLE FileHandle, LPDWORD FileSizeLow, LPDWORD FileSizeHigh);
StaticFileGetContent            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE FileHandle, DWORD FilePositionLow, LPDWORD FilePositionHigh, void* Buffer, DWORD Size);
StaticFileClose                 PROTO :QWORD ; (HANDLE FileHandle);
StaticMemoryDecrypt             PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionType, DWORD DecryptionKeySize, ULONG_PTR DecryptionKey);
StaticMemoryDecryptEx           PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionKeySize, void* DecryptionCallBack);
StaticMemoryDecryptSpecial      PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (LPVOID MemoryStart, DWORD MemorySize, DWORD DecryptionKeySize, DWORD SpecDecryptionType, void* DecryptionCallBack);
StaticSectionDecrypt            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (ULONG_PTR FileMapVA, DWORD SectionNumber, bool SimulateLoad, DWORD DecryptionType, DWORD DecryptionKeySize, ULONG_PTR DecryptionKey);
StaticMemoryDecompress          PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (void* Source, DWORD SourceSize, void* Destination, DWORD DestinationSize, int Algorithm);
StaticRawMemoryCopy             PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, ULONG_PTR FileMapVA, ULONG_PTR VitualAddressToCopy, DWORD Size, bool AddressIsRVA, const char* szDumpFileName);
StaticRawMemoryCopyW            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, ULONG_PTR FileMapVA, ULONG_PTR VitualAddressToCopy, DWORD Size, bool AddressIsRVA, const wchar_t* szDumpFileName);
StaticRawMemoryCopyEx           PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, DWORD RawAddressToCopy, DWORD Size, const char* szDumpFileName);
StaticRawMemoryCopyExW          PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, DWORD RawAddressToCopy, DWORD Size, const wchar_t* szDumpFileName);
StaticRawMemoryCopyEx64         PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, DWORD64 RawAddressToCopy, DWORD64 Size, const char* szDumpFileName);
StaticRawMemoryCopyEx64W        PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (HANDLE hFile, DWORD64 RawAddressToCopy, DWORD64 Size, const wchar_t* szDumpFileName);
StaticHashMemory                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (void* MemoryToHash, DWORD SizeOfMemory, void* HashDigest, bool OutputString, int Algorithm);
StaticHashFileW                 PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, char* HashDigest, bool OutputString, int Algorithm);
StaticHashFile                  PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, char* HashDigest, bool OutputString, int Algorithm);

; TitanEngine.Engine.functions:
EngineUnpackerInitialize        PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szUnpackedFileName, bool DoLogData, bool DoRealignFile, bool DoMoveOverlay, void* EntryCallBack);
EngineUnpackerInitializeW       PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szUnpackedFileName, bool DoLogData, bool DoRealignFile, bool DoMoveOverlay, void* EntryCallBack);
EngineUnpackerSetBreakCondition PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (void* SearchStart, DWORD SearchSize, void* SearchPattern, DWORD PatternSize, DWORD PatternDelta, ULONG_PTR BreakType, bool SingleBreak, DWORD Parameter1, DWORD Parameter2);
EngineUnpackerSetEntryPointAddress PROTO :QWORD ; (ULONG_PTR UnpackedEntryPointAddress);
EngineUnpackerFinalizeUnpacking PROTO

; TitanEngine.Engine.functions:
SetEngineVariable               PROTO :QWORD, :QWORD ; (DWORD VariableId, bool VariableSet);
EngineCreateMissingDependencies  PROTO :QWORD, :QWORD, :QWORD ; (const char* szFileName, const char* szOutputFolder, bool LogCreatedFiles);
EngineCreateMissingDependenciesW PROTO :QWORD, :QWORD, :QWORD ; (const wchar_t* szFileName, const wchar_t* szOutputFolder, bool LogCreatedFiles);
EngineFakeMissingDependencies   PROTO :QWORD ; (HANDLE hProcess);
EngineDeleteCreatedDependencies PROTO
EngineCreateUnpackerWindow      PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; (const char* WindowUnpackerTitle, const char* WindowUnpackerLongTitle, const char* WindowUnpackerName, const char* WindowUnpackerAuthor, void* StartUnpackingCallBack);
EngineAddUnpackerWindowLogMessage PROTO :QWORD ; (const char* szLogMessage);
EngineCheckStructAlignment      PROTO :QWORD, :QWORD ; (DWORD StructureType, ULONG_PTR StructureSize);

; Global.Engine.Extension.Functions:
ExtensionManagerIsPluginLoaded  PROTO :QWORD ; (const char* szPluginName);
ExtensionManagerIsPluginEnabled PROTO :QWORD ; (const char* szPluginName);
ExtensionManagerDisableAllPlugins PROTO
ExtensionManagerDisablePlugin   PROTO :QWORD ; (const char* szPluginName);
ExtensionManagerEnableAllPlugins PROTO
ExtensionManagerEnablePlugin    PROTO :QWORD ; (const char* szPluginName);
ExtensionManagerUnloadAllPlugins PROTO
ExtensionManagerUnloadPlugin    PROTO :QWORD ; (const char* szPluginName);
ExtensionManagerGetPluginInfo   PROTO :QWORD ; (const char* szPluginName);

; Scylla imports
scylla_addImport                PROTO :VARARG
scylla_addModule                PROTO :VARARG
scylla_cutImport                PROTO :VARARG
scylla_dumpProcessA             PROTO :VARARG
scylla_dumpProcess equ <scylla_dumpProcessA>

scylla_dumpProcessW             PROTO :VARARG
scylla_enumImportTree           PROTO :VARARG
scylla_estimatedIATSize         PROTO :VARARG
scylla_findImportNameByWriteLocation PROTO :VARARG
scylla_findImportWriteLocation  PROTO :VARARG
scylla_findModuleNameByWriteLocation PROTO :VARARG
scylla_findOrdinalImportWriteLocation PROTO :VARARG
scylla_fixDump                  PROTO :VARARG
scylla_fixMappedDump            PROTO :VARARG
scylla_getImportCount           PROTO :VARARG
scylla_getImports               PROTO :VARARG
scylla_getModuleCount           PROTO :VARARG
scylla_importsValid             PROTO :VARARG
scylla_rebuildFileA             PROTO :VARARG
scylla_rebuildFile equ <scylla_rebuildFileA>

scylla_rebuildFileW             PROTO :VARARG
scylla_searchIAT                PROTO :VARARG


; Global.Constant.Structure.Declaration:
; Engine.External:
IFNDEF TITANENGINE
TITANENGINE                             EQU 1
ENDIF

UE_STRUCT_PE32STRUCT                    EQU 1
UE_STRUCT_PE64STRUCT                    EQU 2
UE_STRUCT_PESTRUCT                      EQU 3
UE_STRUCT_IMPORTENUMDATA                EQU 4
UE_STRUCT_THREAD_ITEM_DATA              EQU 5
UE_STRUCT_LIBRARY_ITEM_DATA             EQU 6
UE_STRUCT_LIBRARY_ITEM_DATAW            EQU 7
UE_STRUCT_PROCESS_ITEM_DATA             EQU 8
UE_STRUCT_HANDLERARRAY                  EQU 9
UE_STRUCT_PLUGININFORMATION             EQU 10
UE_STRUCT_HOOK_ENTRY                    EQU 11
UE_STRUCT_FILE_STATUS_INFO              EQU 12
UE_STRUCT_FILE_FIX_INFO                 EQU 13
UE_STRUCT_X87FPUREGISTER                EQU 14
UE_STRUCT_X87FPU                        EQU 15
UE_STRUCT_TITAN_ENGINE_CONTEXT          EQU 16

UE_ACCESS_READ                          EQU 0
UE_ACCESS_WRITE                         EQU 1
UE_ACCESS_ALL                           EQU 2

UE_HIDE_PEBONLY                         EQU 0
UE_HIDE_BASIC                           EQU 1

UE_PLUGIN_CALL_REASON_PREDEBUG          EQU 1
UE_PLUGIN_CALL_REASON_EXCEPTION         EQU 2
UE_PLUGIN_CALL_REASON_POSTDEBUG         EQU 3
UE_PLUGIN_CALL_REASON_UNHANDLEDEXCEPTION EQU 4

TEE_HOOK_NRM_JUMP                       EQU 1
TEE_HOOK_NRM_CALL                       EQU 3
TEE_HOOK_IAT                            EQU 5

UE_ENGINE_ALOW_MODULE_LOADING           EQU 1
UE_ENGINE_AUTOFIX_FORWARDERS            EQU 2
UE_ENGINE_PASS_ALL_EXCEPTIONS           EQU 3
UE_ENGINE_NO_CONSOLE_WINDOW             EQU 4
UE_ENGINE_BACKUP_FOR_CRITICAL_FUNCTIONS EQU 5
UE_ENGINE_CALL_PLUGIN_CALLBACK          EQU 6
UE_ENGINE_RESET_CUSTOM_HANDLER          EQU 7
UE_ENGINE_CALL_PLUGIN_DEBUG_CALLBACK    EQU 8
UE_ENGINE_SET_DEBUG_PRIVILEGE           EQU 9

UE_OPTION_REMOVEALL                     EQU 1
UE_OPTION_DISABLEALL                    EQU 2
UE_OPTION_REMOVEALLDISABLED             EQU 3
UE_OPTION_REMOVEALLENABLED              EQU 4

UE_STATIC_DECRYPTOR_XOR                 EQU 1
UE_STATIC_DECRYPTOR_SUB                 EQU 2
UE_STATIC_DECRYPTOR_ADD                 EQU 3

UE_STATIC_DECRYPTOR_FOREWARD            EQU 1
UE_STATIC_DECRYPTOR_BACKWARD            EQU 2

UE_STATIC_KEY_SIZE_1                    EQU 1
UE_STATIC_KEY_SIZE_2                    EQU 2
UE_STATIC_KEY_SIZE_4                    EQU 4
UE_STATIC_KEY_SIZE_8                    EQU 8

UE_STATIC_APLIB                         EQU 1
UE_STATIC_APLIB_DEPACK                  EQU 2
UE_STATIC_LZMA                          EQU 3

UE_STATIC_HASH_MD5                      EQU 1
UE_STATIC_HASH_SHA1                     EQU 2
UE_STATIC_HASH_CRC32                    EQU 3

UE_RESOURCE_LANGUAGE_ANY                EQU -1

UE_PE_OFFSET                            EQU 0
UE_IMAGEBASE                            EQU 1
UE_OEP                                  EQU 2
UE_SIZEOFIMAGE                          EQU 3
UE_SIZEOFHEADERS                        EQU 4
UE_SIZEOFOPTIONALHEADER                 EQU 5
UE_SECTIONALIGNMENT                     EQU 6
UE_IMPORTTABLEADDRESS                   EQU 7
UE_IMPORTTABLESIZE                      EQU 8
UE_RESOURCETABLEADDRESS                 EQU 9
UE_RESOURCETABLESIZE                    EQU 10
UE_EXPORTTABLEADDRESS                   EQU 11
UE_EXPORTTABLESIZE                      EQU 12
UE_TLSTABLEADDRESS                      EQU 13
UE_TLSTABLESIZE                         EQU 14
UE_RELOCATIONTABLEADDRESS               EQU 15
UE_RELOCATIONTABLESIZE                  EQU 16
UE_TIMEDATESTAMP                        EQU 17
UE_SECTIONNUMBER                        EQU 18
UE_CHECKSUM                             EQU 19
UE_SUBSYSTEM                            EQU 20
UE_CHARACTERISTICS                      EQU 21
UE_NUMBEROFRVAANDSIZES                  EQU 22
UE_BASEOFCODE                           EQU 23
UE_BASEOFDATA                           EQU 24
;leaving some enum space here for future additions
UE_SECTIONNAME                          EQU 40
UE_SECTIONVIRTUALOFFSET                 EQU 41
UE_SECTIONVIRTUALSIZE                   EQU 42
UE_SECTIONRAWOFFSET                     EQU 43
UE_SECTIONRAWSIZE                       EQU 44
UE_SECTIONFLAGS                         EQU 45

UE_VANOTFOUND                           EQU -2;

UE_CH_BREAKPOINT                        EQU 1
UE_CH_SINGLESTEP                        EQU 2
UE_CH_ACCESSVIOLATION                   EQU 3
UE_CH_ILLEGALINSTRUCTION                EQU 4
UE_CH_NONCONTINUABLEEXCEPTION           EQU 5
UE_CH_ARRAYBOUNDSEXCEPTION              EQU 6
UE_CH_FLOATDENORMALOPERAND              EQU 7
UE_CH_FLOATDEVIDEBYZERO                 EQU 8
UE_CH_INTEGERDEVIDEBYZERO               EQU 9
UE_CH_INTEGEROVERFLOW                   EQU 10
UE_CH_PRIVILEGEDINSTRUCTION             EQU 11
UE_CH_PAGEGUARD                         EQU 12
UE_CH_EVERYTHINGELSE                    EQU 13
UE_CH_CREATETHREAD                      EQU 14
UE_CH_EXITTHREAD                        EQU 15
UE_CH_CREATEPROCESS                     EQU 16
UE_CH_EXITPROCESS                       EQU 17
UE_CH_LOADDLL                           EQU 18
UE_CH_UNLOADDLL                         EQU 19
UE_CH_OUTPUTDEBUGSTRING                 EQU 20
UE_CH_AFTEREXCEPTIONPROCESSING          EQU 21
UE_CH_SYSTEMBREAKPOINT                  EQU 23
UE_CH_UNHANDLEDEXCEPTION                EQU 24
UE_CH_RIPEVENT                          EQU 25
UE_CH_DEBUGEVENT                        EQU 26

UE_OPTION_HANDLER_RETURN_HANDLECOUNT    EQU 1
UE_OPTION_HANDLER_RETURN_ACCESS         EQU 2
UE_OPTION_HANDLER_RETURN_FLAGS          EQU 3
UE_OPTION_HANDLER_RETURN_TYPENAME       EQU 4

UE_BREAKPOINT_INT3                      EQU 1
UE_BREAKPOINT_LONG_INT3                 EQU 2
UE_BREAKPOINT_UD2                       EQU 3

UE_BPXREMOVED                           EQU 0
UE_BPXACTIVE                            EQU 1
UE_BPXINACTIVE                          EQU 2

UE_BREAKPOINT                           EQU 0
UE_SINGLESHOOT                          EQU 1
UE_HARDWARE                             EQU 2
UE_MEMORY                               EQU 3
UE_MEMORY_READ                          EQU 4
UE_MEMORY_WRITE                         EQU 5
UE_MEMORY_EXECUTE                       EQU 6
UE_BREAKPOINT_TYPE_INT3                 EQU 10000000h
UE_BREAKPOINT_TYPE_LONG_INT3            EQU 20000000h
UE_BREAKPOINT_TYPE_UD2                  EQU 30000000h

UE_HARDWARE_EXECUTE                     EQU 4
UE_HARDWARE_WRITE                       EQU 5
UE_HARDWARE_READWRITE                   EQU 6

UE_HARDWARE_SIZE_1                      EQU 7
UE_HARDWARE_SIZE_2                      EQU 8
UE_HARDWARE_SIZE_4                      EQU 9
UE_HARDWARE_SIZE_8                      EQU 10

UE_ON_LIB_LOAD                          EQU 1
UE_ON_LIB_UNLOAD                        EQU 2
UE_ON_LIB_ALL                           EQU 3

UE_APISTART                             EQU 0
UE_APIEND                               EQU 1

UE_PLATFORM_x86                         EQU 1
UE_PLATFORM_x64                         EQU 2
UE_PLATFORM_ALL                         EQU 3

UE_FUNCTION_STDCALL                     EQU 1
UE_FUNCTION_CCALL                       EQU 2
UE_FUNCTION_FASTCALL                    EQU 3
UE_FUNCTION_STDCALL_RET                 EQU 4
UE_FUNCTION_CCALL_RET                   EQU 5
UE_FUNCTION_FASTCALL_RET                EQU 6
UE_FUNCTION_STDCALL_CALL                EQU 7
UE_FUNCTION_CCALL_CALL                  EQU 8
UE_FUNCTION_FASTCALL_CALL               EQU 9
UE_PARAMETER_BYTE                       EQU 0
UE_PARAMETER_WORD                       EQU 1
UE_PARAMETER_DWORD                      EQU 2
UE_PARAMETER_QWORD                      EQU 3
UE_PARAMETER_PTR_BYTE                   EQU 4
UE_PARAMETER_PTR_WORD                   EQU 5
UE_PARAMETER_PTR_DWORD                  EQU 6
UE_PARAMETER_PTR_QWORD                  EQU 7
UE_PARAMETER_STRING                     EQU 8
UE_PARAMETER_UNICODE                    EQU 9

UE_EAX                                  EQU 1
UE_EBX                                  EQU 2
UE_ECX                                  EQU 3
UE_EDX                                  EQU 4
UE_EDI                                  EQU 5
UE_ESI                                  EQU 6
UE_EBP                                  EQU 7
UE_ESP                                  EQU 8
UE_EIP                                  EQU 9
UE_EFLAGS                               EQU 10
UE_DR0                                  EQU 11
UE_DR1                                  EQU 12
UE_DR2                                  EQU 13
UE_DR3                                  EQU 14
UE_DR6                                  EQU 15
UE_DR7                                  EQU 16
UE_RAX                                  EQU 17
UE_RBX                                  EQU 18
UE_RCX                                  EQU 19
UE_RDX                                  EQU 20
UE_RDI                                  EQU 21
UE_RSI                                  EQU 22
UE_RBP                                  EQU 23
UE_RSP                                  EQU 24
UE_RIP                                  EQU 25
UE_RFLAGS                               EQU 26
UE_R8                                   EQU 27
UE_R9                                   EQU 28
UE_R10                                  EQU 29
UE_R11                                  EQU 30
UE_R12                                  EQU 31
UE_R13                                  EQU 32
UE_R14                                  EQU 33
UE_R15                                  EQU 34
UE_CIP                                  EQU 35
UE_CSP                                  EQU 36
IFDEF _WIN64
UE_CFLAGS                               EQU UE_RFLAGS
ELSE
UE_CFLAGS                               EQU UE_EFLAGS
ENDIF
UE_SEG_GS                               EQU 37
UE_SEG_FS                               EQU 38
UE_SEG_ES                               EQU 39
UE_SEG_DS                               EQU 40
UE_SEG_CS                               EQU 41
UE_SEG_SS                               EQU 42
UE_x87_r0                               EQU 43
UE_x87_r1                               EQU 44
UE_x87_r2                               EQU 45
UE_x87_r3                               EQU 46
UE_x87_r4                               EQU 47
UE_x87_r5                               EQU 48
UE_x87_r6                               EQU 49
UE_x87_r7                               EQU 50
UE_X87_STATUSWORD                       EQU 51
UE_X87_CONTROLWORD                      EQU 52
UE_X87_TAGWORD                          EQU 53
UE_MXCSR                                EQU 54
UE_MMX0                                 EQU 55
UE_MMX1                                 EQU 56
UE_MMX2                                 EQU 57
UE_MMX3                                 EQU 58
UE_MMX4                                 EQU 59
UE_MMX5                                 EQU 60
UE_MMX6                                 EQU 61
UE_MMX7                                 EQU 62
UE_XMM0                                 EQU 63
UE_XMM1                                 EQU 64
UE_XMM2                                 EQU 65
UE_XMM3                                 EQU 66
UE_XMM4                                 EQU 67
UE_XMM5                                 EQU 68
UE_XMM6                                 EQU 69
UE_XMM7                                 EQU 70
UE_XMM8                                 EQU 71
UE_XMM9                                 EQU 72
UE_XMM10                                EQU 73
UE_XMM11                                EQU 74
UE_XMM12                                EQU 75
UE_XMM13                                EQU 76
UE_XMM14                                EQU 77
UE_XMM15                                EQU 78
UE_x87_ST0                              EQU 79
UE_x87_ST1                              EQU 80
UE_x87_ST2                              EQU 81
UE_x87_ST3                              EQU 82
UE_x87_ST4                              EQU 83
UE_x87_ST5                              EQU 84
UE_x87_ST6                              EQU 85
UE_x87_ST7                              EQU 86
UE_YMM0                                 EQU 87
UE_YMM1                                 EQU 88
UE_YMM2                                 EQU 89
UE_YMM3                                 EQU 90
UE_YMM4                                 EQU 91
UE_YMM5                                 EQU 92
UE_YMM6                                 EQU 93
UE_YMM7                                 EQU 94
UE_YMM8                                 EQU 95
UE_YMM9                                 EQU 96
UE_YMM10                                EQU 97
UE_YMM11                                EQU 98
UE_YMM12                                EQU 99
UE_YMM13                                EQU 100
UE_YMM14                                EQU 101
UE_YMM15                                EQU 102

IFNDEF CONTEXT_EXTENDED_REGISTERS
CONTEXT_EXTENDED_REGISTERS              EQU 0
ENDIF

TEE_MAXIMUM_HOOK_SIZE                   EQU 14
TEE_MAXIMUM_HOOK_RELOCS                 EQU 7
IFDEF _WIN64
TEE_MAXIMUM_HOOK_INSERT_SIZE            EQU 14
ELSE
TEE_MAXIMUM_HOOK_INSERT_SIZE            EQU 5
ENDIF

UE_DEPTH_SURFACE                        EQU 0
UE_DEPTH_DEEP                           EQU 1

UE_UNPACKER_CONDITION_SEARCH_FROM_EP    EQU 1

UE_UNPACKER_CONDITION_LOADLIBRARY       EQU 1
UE_UNPACKER_CONDITION_GETPROCADDRESS    EQU 2
UE_UNPACKER_CONDITION_ENTRYPOINTBREAK   EQU 3
UE_UNPACKER_CONDITION_RELOCSNAPSHOT1    EQU 4
UE_UNPACKER_CONDITION_RELOCSNAPSHOT2    EQU 5

UE_FIELD_OK                             EQU 0
UE_FIELD_BROKEN_NON_FIXABLE             EQU 1
UE_FIELD_BROKEN_NON_CRITICAL            EQU 2
UE_FIELD_BROKEN_FIXABLE_FOR_STATIC_USE  EQU 3
UE_FIELD_BROKEN_BUT_CAN_BE_EMULATED     EQU 4
UE_FIELD_FIXABLE_NON_CRITICAL           EQU 5
UE_FIELD_FIXABLE_CRITICAL               EQU 6
UE_FIELD_NOT_PRESET                     EQU 7
UE_FIELD_NOT_PRESET_WARNING             EQU 8

UE_RESULT_FILE_OK                       EQU 10
UE_RESULT_FILE_INVALID_BUT_FIXABLE      EQU 11
UE_RESULT_FILE_INVALID_AND_NON_FIXABLE  EQU 12
UE_RESULT_FILE_INVALID_FORMAT           EQU 13
















