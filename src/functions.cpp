#include "functions.h"

void ModifyProcessMemory(HANDLE hProcess, DWORD baseAddress, const std::vector<DWORD>& offsets, DWORD newValue) {
    DWORD targetAddress = baseAddress;

    // iterates through the offsets to find final address
    for (DWORD offset : offsets) {
        ReadProcessMemory(hProcess, (LPVOID)targetAddress, &targetAddress, sizeof(targetAddress), nullptr);
        targetAddress += offset;
    }

    // write the new value to the final address
    WriteProcessMemory(hProcess, (LPVOID)targetAddress, &newValue, sizeof(newValue), nullptr);
}