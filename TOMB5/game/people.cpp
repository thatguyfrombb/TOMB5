#include "../tomb5/pch.h"
#include "people.h"
#include "../global/types.h"
#include "draw.h"
#include "control.h"
#include "objects.h"
#include "sound.h"
#include "tomb4fx.h"
#include "sphere.h"
#include "box.h"
#include "debris.h"

int TargetVisible(ITEM_INFO* item, AI_info* info)
{
	GAME_VECTOR start;
	GAME_VECTOR target;
	creature_info* creature;
	ITEM_INFO* enemy;
	short* bounds;

	creature = (creature_info*)item->data;
	enemy = creature->enemy;

	if (!enemy || enemy->hit_points <= 0 || !enemy->data || (info->angle - creature->joint_rotation[2]) <= -8192 ||
		(info->angle - creature->joint_rotation[2]) >= 0x2000 || info->distance >= 0x4000000)
		return 0;

	start.x = item->pos.x_pos;
	start.y = item->pos.y_pos - 768;
	start.z = item->pos.z_pos;
	start.room_number = item->room_number;
	target.x = enemy->pos.x_pos;
	bounds = GetBestFrame(enemy);
	target.y = enemy->pos.y_pos + ((((bounds[2] << 1) + bounds[2]) + bounds[3]) >> 2);
	target.z = enemy->pos.z_pos;
	return LOS(&start, &target);
}

int Targetable(ITEM_INFO* item, AI_info* info)
{
	short* bounds;
	GAME_VECTOR start, target;
	creature_info* creature = (creature_info*)item->data;
	ITEM_INFO* enemy = creature->enemy;

	if (!enemy || enemy->hit_points <= 0 || !enemy->data || !info->ahead || info->distance >= 0x4000000)
		return 0;
 
	bounds = GetBestFrame(item);
	start.x = item->pos.x_pos;

	if (item->object_number == SNIPER)
		start.y = item->pos.y_pos - 768;
	else
		start.y = item->pos.y_pos + ((bounds[3] + 3 * bounds[2]) >> 2);

	start.z = item->pos.z_pos;
	start.room_number = item->room_number;
	bounds = GetBestFrame(enemy);
	target.x = enemy->pos.x_pos;
	target.y = enemy->pos.y_pos + ((bounds[3] + 3 * bounds[2]) >> 2);
	target.z = enemy->pos.z_pos;
	return LOS(&start, &target);
}

short GunShot(long x, long y, long z, short speed, int yrot, int room_number)
{
	return -1;
}

short GunHit(long x, long y, long z, short speed, int yrot, int room_number)
{
	PHD_VECTOR pos;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	GetJointAbsPosition(lara_item, &pos, (25 * GetRandomControl()) / 0x7FFF);
	DoBloodSplat(pos.x, pos.y, pos.z, (GetRandomControl() & 3) + 3, lara_item->pos.y_rot, lara_item->room_number);
	SoundEffect(SFX_LARA_INJURY_RND, &lara_item->pos, SFX_DEFAULT);
	return GunShot(x, y, z, speed, yrot, room_number);
}

short GunMiss(long x, long y, long z, short speed, int yrot, int room_number)
{
	GAME_VECTOR pos;

	pos.x = lara_item->pos.x_pos + ((GetRandomControl() - 0x4000) << 9) / 0x7FFF;
	pos.y = lara_item->floor;
	pos.z = lara_item->pos.z_pos + ((GetRandomControl() - 0x4000) << 9) / 0x7FFF;
	pos.room_number = lara_item->room_number;
	Richochet(&pos);
	return GunShot(x, y, z, speed, yrot, room_number);
}

int ShotLara(ITEM_INFO* item, AI_info* info, BITE_INFO* gun, short extra_rotation, int damage)
{
	int hit, targetable, random, distance;
	GAME_VECTOR start;
	GAME_VECTOR target;
	PHD_VECTOR pos;
	creature_info* creature;
	ITEM_INFO* enemy;
	PHD_VECTOR v;
	MESH_INFO* StaticMesh;

	creature = (creature_info*)item->data;
	enemy = creature->enemy;

	if (info->distance <= 0x4000000 && Targetable(item, info))
	{
		distance = SIN(info->enemy_facing) * enemy->speed * 0x4000000 / 300 >> 14;
		distance = info->distance + SQUARE(distance);

		if (distance <= 0x4000000)
		{
			random = (0x4000000 - info->distance) / 3276 + 0x2000;
			hit = (GetRandomControl() < random);
		}
		else
			hit = 0;

		targetable = 1;
	}
	else
	{
		hit = 0;
		targetable = 0;
	}

	if (damage)
	{
		if (enemy == lara_item)
		{
			if (hit)
			{
				CreatureEffect(item, gun, GunHit);
				lara_item->hit_points -= damage;
				lara_item->hit_status = 1;
			}
			else if (targetable)
				CreatureEffect(item, gun, GunMiss);
		}
		else
		{
			CreatureEffect(item, gun, GunShot);

			if (hit)
			{
				enemy->hit_points -= damage / 10;
				enemy->hit_status = 1;
				random = GetRandomControl() & 0xF;

				if (random > 14)
					random = 0;

				pos.x = 0;
				pos.y = 0;
				pos.z = 0;
				GetJointAbsPosition(enemy, &pos, random);
				DoBloodSplat(pos.x, pos.y, pos.z, (GetRandomControl() & 3) + 4, enemy->pos.y_rot, enemy->room_number);
			}
		}
	}

	start.x = item->pos.x_pos;
	start.y = item->pos.y_pos - 768;
	start.z = item->pos.z_pos;
	start.room_number = item->room_number;
	target.x = enemy->pos.x_pos;
	target.y = enemy->pos.y_pos - 768;
	target.z = enemy->pos.z_pos;
	target.x += (target.x - start.x) >> 1;
	target.y += (target.y - start.y) >> 1;
	target.z += (target.z - start.z) >> 1;

	if (ObjectOnLOS2(&start, &target, &pos, &StaticMesh) & 0x8000)
	{
		if (StaticMesh->static_number >= 50 && StaticMesh->static_number < 58)
		{
			ShatterObject(0, StaticMesh, 128, start.room_number, 0);
			SmashedMesh[SmashedMeshCount] = StaticMesh;
			SmashedMeshCount++;
			v.x = StaticMesh->x;
			v.y = StaticMesh->y;
			v.z = StaticMesh->z;
			SoundEffect(ShatterSounds[gfCurrentLevel - 5][StaticMesh->static_number], (PHD_3DPOS*)&v, SFX_DEFAULT);
			TriggerRicochetSpark(&target, item->pos.y_rot, 3, 0);
			StaticMesh->Flags &= 0x00FE;//check
		}
	}

	return targetable;
}

void inject_people()
{
	INJECT(0x004671E0, TargetVisible);
	INJECT(0x004672F0, Targetable);
	INJECT(0x00467420, GunShot);
	INJECT(0x00467440, GunHit);
	INJECT(0x00467530, GunMiss);
	INJECT(0x00467610, ShotLara);
}