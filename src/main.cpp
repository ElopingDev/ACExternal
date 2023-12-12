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
	std::vector<BYTE> rapidfireOriginalInstructions(5);

	bool recoilSetOnce = false;
	bool rapidFireSetOnce = false;



	while (!GetAsyncKeyState(VK_END)) {
	ModifyProcessMemory(hProcess, globals::baseAddress, globals::ammoOffsets, 666);
	ModifyProcessMemory(hProcess, globals::baseAddress, globals::healthOffsets, 666);

	if (recoilSetOnce == false)
	{
		NopMemory(hProcess, (void*)globals::recoilAddress, 5, originalInstructions);
		PrintInstructions(originalInstructions);
		recoilSetOnce = true;
	}

	if (rapidFireSetOnce == false)
	{
		NopMemory(hProcess, (void*)globals::rapidfireAddress, 5, rapidfireOriginalInstructions);
		PrintInstructions(rapidfireOriginalInstructions);
		rapidFireSetOnce = true;
	}

	}
	
	RestoreMemory(hProcess, (void*)globals::recoilAddress, 5, originalInstructions);
	RestoreMemory(hProcess, (void*)globals::rapidfireAddress, 5, rapidfireOriginalInstructions);

	return 0;
}