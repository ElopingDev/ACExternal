#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>

void ModifyProcessMemory(HANDLE hProcess, DWORD baseAddress, const std::vector<DWORD>& offsets, DWORD newValue);
void NopMemory(HANDLE hProcess, LPVOID targetAddress, size_t size, std::vector<BYTE>& originalInstructions);
void PrintInstructions(const std::vector<BYTE>& instructions);
void RestoreMemory(HANDLE hProcess, LPVOID targetAddress, size_t size, std::vector<BYTE>& instructions);

