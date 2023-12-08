#include <Windows.h>
#include <iostream>
#include <vector>
#include "functions.h"
#include "globals.h"



int main(int argc, char** argv)
{
	HWND acWindow = FindWindow(NULL, "AssaultCube");
	DWORD pid = 0;
	GetWindowThreadProcessId(acWindow, &pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, true, pid);

	ModifyProcessMemory(hProcess, addr::baseAddress, offsets::ammoOffsets, 666);
	ModifyProcessMemory(hProcess, addr::baseAddress, offsets::healthOffsets, 666);

	return 0;
}