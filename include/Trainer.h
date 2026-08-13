// FH6 Trainer - Core types
#pragma once
#include <string>
#include <atomic>
#include <windows.h>

namespace FH6 {

class Memory {
public:
    static DWORD FindProcess(const wchar_t* name);
    bool Open(DWORD pid);
    bool Read(uintptr_t address, void* buffer, SIZE_T size);
    bool Write(uintptr_t address, const void* buffer, SIZE_T size);
private:
    HANDLE m_handle = nullptr;
};

struct Vec3 { float x, y, z; };

class Features {
public:
    void ToggleUnlimitedMoney(bool on);
    void SetSpeedMultiplier(float mult);
    void UnlockAllCars();
    void TeleportTo(float x, float y, float z);
    void ToggleNoDamage(bool on);
    void InstantWin();
private:
    std::atomic<bool> m_moneyEnabled{false};
    std::atomic<float> m_speedMult{1.0f};
    std::atomic<bool> m_noDamage{false};
    Vec3 m_teleportTarget = {};
    bool m_teleportPending = false;
};

class Overlay {
public:
    void Render(Features& f);
    void Toggle();
    bool IsVisible() const { return m_visible; }
private:
    bool m_visible = false;
};

class OffsetScanner {
public:
    uintptr_t FindPattern(HANDLE process, const std::string& pattern);
    bool UpdateOffsets(const std::string& configPath);
};

class Trainer {
public:
    bool Attach();
    int Run();
private:
    Memory m_mem;
    Features m_features;
    Overlay m_overlay;
};

} // namespace FH6
