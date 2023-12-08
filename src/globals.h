#pragma once
#include <Windows.h>
#include <vector>

namespace globals {
	DWORD baseAddress = 0x057E0A8;
	DWORD recoilAddress = 0x04C2EC3;
	std::vector<DWORD> ammoOffsets{ 0x364, 0x14, 0x0 };
	std::vector<DWORD> healthOffsets{ 0xEC };
}