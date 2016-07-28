;--------------------------------------------------------------------------------------------------------
; x64dbg plugin SDK for JWasm64 - fearless 2015 - www.LetTheLight.in
;
; Supports 64bit x64dbg only
;
; The x64dbg plugin SDK for Masm32 can be downloaded from here:
; https://bitbucket.org/mrfearless/x64dbg-plugin-sdk-for-masm/overview
;
; Provided for ease of use in including the required lib and inc files used with the x64dbg plugin SDK 
;
; x64dbg website    : http://x64dbg.com
; x64dbg source     : https://github.com/x64dbg/x64dbg
; x64dbg testplugin : https://github.com/x64dbg/testplugin
;
; The most upto date libraries and corresponding .dll's can be found in the x64dbg source
; and/or from the latest snapshots downloadable from: http://sourceforge.net/projects/x64dbg
;
;--------------------------------------------------------------------------------------------------------

include windows.inc           ; Windows include file for MASM32 / JWasm64
include psapi.inc             ; MS Process Status include for psapi.dll exports.

IFDEF _WIN64
include x64dbg.inc            ; Plugin SDK include for x64dbg.dll exports, constants and structures.
include x64bridge.inc         ; Plugin SDK include for x64bridge.dll exports, constants and structures.
include dbghelp_x64.inc       ; MS Debugging Tools include for dbghelp.dll exports, constants and structures.
include TitanEngine_x64.inc   ; Plugin SDK include for TitanEngine.dll exports, constants and structures.
ELSE
ENDIF

includelib user32.lib
includelib gdi32.lib
includelib kernel32.lib
includelib comdlg32.lib
includelib psapi.lib          ; MS Process Status library for psapi.dll

IFDEF _WIN64
includelib x64dbg.lib         ; Plugin SDK library for x64dbg.dll
includelib x64bridge.lib      ; Plugin SDK library for x64bridge.dll
includelib dbghelp_x64.lib    ; MS Debugging Tools library for dbghelp.dll
includelib TitanEngine_x64.lib; Plugin SDK library for TitanEngine.dll
ELSE
ENDIF
