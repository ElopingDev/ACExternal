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

void NopMemory(HANDLE hProcess, LPVOID targetAddress, size_t size, std::vector<BYTE>& originalInstructions) {

    // creates a buffer with nop instructions
    std::vector<BYTE> nopInstructions(size, 0x90);

    // reads original instructions for later restore
    ReadProcessMemory(hProcess, targetAddress, originalInstructions.data(), size, nullptr);

    // Write the NOP instructions to the target address
    WriteProcessMemory(hProcess, targetAddress, nopInstructions.data(), size, nullptr);
}

void PrintInstructions(const std::vector<BYTE>& instructions) {
    std::cout << "Original Instructions: ";

    for (BYTE instruction : instructions) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(instruction) << " ";
    }

    std::cout << std::dec << std::endl;
}