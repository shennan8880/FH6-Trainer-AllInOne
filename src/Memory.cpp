// FH6 Trainer - Process attach and memory read/write
#include "../include/Trainer.h"
#include <tlhelp32.h>

namespace FH6 {

DWORD Memory::FindProcess(const wchar_t* name) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return 0;
    PROCESSENTRY32W pe = {};
    pe.dwSize = sizeof(pe);
    DWORD pid = 0;
    if (Process32FirstW(snap, &pe)) {
        do {
            if (wcscmp(pe.szExeFile, name) == 0) { pid = pe.th32ProcessID; break; }
        } while (Process32NextW(snap, &pe));
    }
    CloseHandle(snap);
    return pid;
}

bool Memory::Open(DWORD pid) {
    m_handle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION,
        FALSE, pid);
    return m_handle != nullptr;
}

bool Memory::Read(uintptr_t address, void* buffer, SIZE_T size) {
    SIZE_T read = 0;
    return ReadProcessMemory(m_handle, (LPCVOID)address, buffer, size, &read) && read == size;
}

bool Memory::Write(uintptr_t address, const void* buffer, SIZE_T size) {
    SIZE_T written = 0;
    return WriteProcessMemory(m_handle, (LPVOID)address, buffer, size, &written) && written == size;
}

} // namespace FH6
