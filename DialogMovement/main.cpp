#include "main.h"

BOOL APIENTRY DllMain(_In_ HMODULE hModule, _In_ DWORD dwReasonForCall,
                      _In_ LPVOID lpvReserved) {

    if (dwReasonForCall == DLL_PROCESS_ATTACH) {
        // Don't interrupt us about thread events
        DisableThreadLibraryCalls(hModule);

        // Seeking for our pattern
        uintptr_t entry =
            memwrapper::search_memory_pattern(kModule, kPattern, kMask);

        // Got an error while seeking the pattern
        if (entry == NULL)
            return FALSE; // Unloading

        // Setups and installs patch
        /*
            CURSOR_LOCKCAMANDCONTROL            -> CURSOR_LOCKCAM
            .text:....... 6A 02     push    2   -> 
            .text:....... 6A 03     push    3
        */
        patch_set_cursor_mode.add({ entry + kShiftToOperand,
                                    { CURSOR_LOCKCAM },
                                    { CURSOR_LOCKCAMANDCONTROL } });
        patch_set_cursor_mode.install();
    }

    return TRUE;
}