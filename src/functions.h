#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

void ModifyProcessMemory(HANDLE hProcess, DWORD baseAddress, const std::vector<DWORD>& offsets, DWORD newValue);