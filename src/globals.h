#pragma once
#include <Windows.h>
#include <vector>

namespace addr {
	DWORD baseAddress = 0x057E0A8;
}

namespace offsets {

	std::vector<DWORD> ammoOffsets{ 0x364, 0x14, 0x0 };
	std::vector<DWORD> healthOffsets{ 0xEC };

}