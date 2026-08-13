// FH6 Trainer - Trainer shell
#include "../include/Trainer.h"
#include <iostream>

namespace FH6 {

bool Trainer::Attach() {
    DWORD pid = Memory::FindProcess(L"ForzaHorizon6.exe");
    if (pid == 0) return false;
    return m_mem.Open(pid);
}

int Trainer::Run() {
    // Hotkey loop: INSERT toggles overlay, F1-F8 toggle features
    while (true) {
        if (GetAsyncKeyState(VK_INSERT) & 1) m_overlay.Toggle();
        if (GetAsyncKeyState(VK_F1) & 1) m_features.ToggleUnlimitedMoney(true);
        if (GetAsyncKeyState(VK_F4) & 1) m_features.UnlockAllCars();
        if (GetAsyncKeyState(VK_F6) & 1) m_features.InstantWin();
        Sleep(50);
    }
    return 0;
}

} // namespace FH6
