#include <Windows.h>
#include <iostream>
#include <vector>
#include "functions.h"
#include "globals.h"
#include <iomanip>




int main(int argc, char** argv)
{
	HWND acWindow = FindWindow(NULL, "AssaultCube");
	DWORD pid = 0;
	GetWindowThreadProcessId(acWindow, &pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, true, pid);
	std::vector<BYTE> originalInstructions(5);

	ModifyProcessMemory(hProcess, globals::baseAddress, globals::ammoOffsets, 666);
	ModifyProcessMemory(hProcess, globals::baseAddress, globals::healthOffsets, 666);
	NopMemory(hProcess, (void*)globals::recoilAddress, 5, originalInstructions);
	PrintInstructions(originalInstructions);

	return 0;
}