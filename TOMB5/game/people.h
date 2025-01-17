#pragma once
#include "../global/vars.h"

void inject_people(bool replace);

int TargetVisible(ITEM_INFO* item, AI_INFO* info);
int Targetable(ITEM_INFO* item, AI_INFO* info);
short GunShot(long x, long y, long z, short speed, short yrot, short room_number);
short GunHit(long x, long y, long z, short speed, short yrot, short room_number);
short GunMiss(long x, long y, long z, short speed, short yrot, short room_number);
int ShotLara(ITEM_INFO* item, AI_INFO* info, BITE_INFO* gun, short extra_rotation, int damage);
