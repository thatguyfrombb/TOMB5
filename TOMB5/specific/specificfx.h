#pragma once
#include "../global/vars.h"

void inject_specificfx();

void S_PrintShadow(short size, short* box, ITEM_INFO* item, short unknown);

#define setXY4	( (void(__cdecl*)(D3DTLVERTEX*, int, int, int, int, int, int, int, int, int, short*)) 0x004C05B0 )
#define setXYZ3	( (void(__cdecl*)(D3DTLVERTEX*, long, long, long, long, long, long, long, long, long, short*)) 0x004C0F30 )

#define DXAttempt	( (void(__cdecl*)(HRESULT)) 0x0049F1C0 )//doesn't belong here
