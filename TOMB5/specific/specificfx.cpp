#include "../tomb5/pch.h"
#include "specificfx.h"
#include "3dmath.h"
#include "../game/delstuff.h"
#include "../game/control.h"
#include "../specific/function_table.h"
#include "../game/objects.h"
#ifdef DEBUG_FEATURES
#include "dxshell.h"
#endif

#ifdef cunt
#define LINE_POINTS	8	//number of points in each grid line
#define NUM_TRIS	82	//number of triangles needed to create the shadow (this depends on what shape you're doing)
#else
#define LINE_POINTS	4	//number of points in each grid line
#define NUM_TRIS	14	//number of triangles needed to create the shadow (this depends on what shape you're doing)
#endif
#define GRID_POINTS	(LINE_POINTS * LINE_POINTS)	//number of points in the whole grid
#define POINT_HEIGHT_CORRECTION	196	//if the difference between the floor below Lara and the floor height below the point is greater than this value, point height is corrected to lara's floor level.

long ShadowTable[NUM_TRIS * 3] =	//num of triangles * 3 points
{
	//shadow is split in 3 parts. top, middle, bottom, each part made of triangles. first 4 tris are the top part,
	//the following 6 are the middle part, and the last 4 are the bottom part.

	//tris for each part go left to right. i.e the first line for the top part is the leftmost tri, 4th one is the rightmost, and so on
	//but this isn't a hard rule at all, it's just how Core did it
/*
	the default shadow grid is 4 x 4 points
	0	1	2	3

	4	5	6	7

	8	9	10	11

	12	13	14	15

	the values here are which grid points the tri points are at.
	for example, the first tri, 4, 1, 5. connect the dots. 4 -> 1 -> 5
	which makes the top left tri.
	and so on.
*/
#ifdef cunt
	16, 9, 17,
	9, 2, 10,
	9, 10, 17,
	17, 10, 18,
	2, 10, 3,
	10, 3, 11,
	10, 11, 18,
	18, 11, 19,
	3, 4, 11,
	11, 4, 12,
	11, 12, 19,
	19, 12, 20,
	4, 5, 12,
	12, 5, 13,
	20, 12, 13,
	20, 13, 21,
	5, 13, 14,
	13, 21, 14,
	21, 14, 22,
	14, 22, 23,
	16, 17, 24,
	24, 17, 25,
	17, 18, 25,
	25, 18, 26,
	18, 19, 26,
	26, 19, 27,
	19, 20, 27,
	27, 20, 28,
	20, 21, 28,
	28, 21, 29,
	21, 22, 29,
	29, 22, 30,
	22, 23, 30,
	30, 23, 31,
	24, 25, 32,
	32, 25, 33,
	25, 26, 33,
	33, 26, 34,
	26, 27, 34,
	34, 27, 35,
	27, 28, 35,
	35, 28, 36,
	28, 29, 36,
	36, 29, 37,
	29, 30, 37,
	37, 30, 38,
	30, 31, 38,
	38, 31, 39,
	32, 33, 40,
	40, 33, 41,
	33, 34, 41,
	41, 34, 42,
	34, 35, 42,
	42, 35, 43,
	35, 36, 43,
	43, 36, 44,
	36, 37, 44,
	44, 37, 45,
	37, 38, 45,
	45, 38, 46,
	38, 39, 46,
	46, 39, 47,
	40, 49, 41,
	41, 42, 49,
	49, 42, 50,
	42, 43, 50,
	50, 43, 51,
	43, 44, 51,
	51, 44, 52,
	44, 45, 52,
	52, 45, 53,
	45, 46, 53,
	53, 46, 54,
	46, 47, 54,
	49, 50, 58,
	50, 51, 58,
	58, 51, 59,
	51, 52, 59,
	59, 52, 60,
	52, 53, 60,
	60, 53, 61,
	53, 54, 61
#else
4, 1, 5,
5, 1, 6,	//top part
6, 1, 2,
6, 2, 7,
//
8, 4, 9,
9, 4, 5,
9, 5, 10,	//middle part
10, 5, 6,
10, 6, 11,
11, 6, 7,
//
13, 8, 9,
13, 9, 14,	//bottom part
14, 9, 10,
14, 10, 11
#endif
};

void S_PrintShadow(short size, short* box, ITEM_INFO* item, short unknown)
{
	FLOOR_INFO* floor;
	TEXTURESTRUCT Tex;
	D3DTLVERTEX v[4];
	PHD_VECTOR vector;
	float* pmxz;
	long* phxz;
	long* h;
	long* mptr;
	float mxz[GRID_POINTS * 3];//x y z for each point, for drawing
	float fx, fy, fz;
	long hxz[GRID_POINTS * 2];//x z for each point, for calculating shadow coords/height
	long height[GRID_POINTS];//height for each point
	long x1, y1, z1, x2, y2, z2, x3, y3, z3;
	long x, y, z, sx, sz, xextent, zextent, sxstep, szstep, color, a, b, c;
	short room_number;

	xextent = size * (box[1] - box[0]) / 192;
	zextent = size * (box[5] - box[4]) / 192;
	pmxz = mxz;
	phxz = hxz;
	sxstep = xextent / LINE_POINTS;
	szstep = zextent / LINE_POINTS;
	sx = -sxstep - (sxstep >> 1);
	sz = szstep + (szstep >> 1);

	for (int i = 0; i < LINE_POINTS; i++, sz -= szstep)
	{
		for (int j = 0; j < LINE_POINTS; j++, pmxz += 3, phxz += 2, sx += sxstep)
		{
			pmxz[0] = (float)sx;
			pmxz[2] = (float)sz;
			phxz[0] = sx;
			phxz[1] = sz;
		}

		sx = -sxstep - (sxstep >> 1);
	}

	phd_PushUnitMatrix();

	if (item == lara_item)
	{
#ifdef cunt
		vector.x = -60;
		vector.y = 0;
		vector.z = 30;
#else
		vector.x = 0;
		vector.y = 0;
		vector.z = 0;
#endif
		GetLaraJointPos(&vector, 7);
		room_number = lara_item->room_number;
		floor = GetFloor(vector.x, vector.y, vector.z, &room_number);
		y = GetHeight(floor, vector.x, vector.y, vector.z);

		if (y == NO_HEIGHT)
			y = item->floor;
	}
	else
	{
		vector.x = item->pos.x_pos;
		y = item->floor;
		vector.z = item->pos.z_pos;
	}

	phd_TranslateRel(vector.x, y - 16, vector.z);
	phd_RotY(item->pos.y_rot);
	mptr = phd_mxptr;
	phxz = hxz;

	for (int i = 0; i < GRID_POINTS; i++, phxz += 2)
	{
		x = phxz[0];
		z = phxz[1];
		phxz[0] = (x * mptr[0] + z * mptr[2] + mptr[3]) >> 14;
		phxz[1] = (x * mptr[8] + z * mptr[10] + mptr[11]) >> 14;
	}

	phd_PopMatrix();
	phxz = hxz;
	h = height;

	for (int i = 0; i < GRID_POINTS; i++, phxz += 2, h++)
	{
		room_number = item->room_number;
		floor = GetFloor(phxz[0], item->floor, phxz[1], &room_number);
		*h = GetHeight(floor, phxz[0], item->floor, phxz[1]);

		if (ABS(*h - item->floor) > POINT_HEIGHT_CORRECTION)
			*h = item->floor;
	}

	phd_PushMatrix();
	phd_TranslateAbs(vector.x, y - 16, vector.z);
	phd_RotY(item->pos.y_rot);
	mptr = phd_mxptr;
	pmxz = mxz;
	h = height;

	for (int i = 0; i < GRID_POINTS; i++, pmxz += 3, h++)
	{
		fx = pmxz[0];
		fy = (float)(*h - item->floor);
		fz = pmxz[2];
		pmxz[0] = aMXPtr[0] * fx + aMXPtr[1] * fy + aMXPtr[2] * fz + aMXPtr[3];
		pmxz[1] = aMXPtr[4] * fx + aMXPtr[5] * fy + aMXPtr[6] * fz + aMXPtr[7];
		pmxz[2] = aMXPtr[8] * fx + aMXPtr[9] * fy + aMXPtr[10] * fz + aMXPtr[11];
	}

	phd_PopMatrix();
	pmxz = mxz;
	color = 0x4F000000;

#ifdef DEBUG_FEATURES
	//drawing the grid
	D3DTLVERTEX vertex;
	float px, py, pz, pzv;

	for (int i = 0; i < GRID_POINTS; i++)
	{
		px = pmxz[(i * 3) + 0];
		py = pmxz[(i * 3) + 1];
		pz = pmxz[(i * 3) + 2];
		pzv = f_mpersp / pz;
		vertex.sx = px * pzv + f_centerx;
		vertex.sy = py * pzv + f_centery;
		vertex.rhw = pzv * f_moneopersp;
		vertex.sz = f_a - f_boo * vertex.rhw;
		vertex.color = 0xFFFFFFFF;		//opaque white
		vertex.specular = 0xFF000000;
		App.dx.lpD3DDevice->SetTexture(0, 0);
		DXAttempt(App.dx.lpD3DDevice->DrawPrimitive(D3DPT_POINTLIST, D3DFVF_TLVERTEX, &vertex, 1, 1));
	}
#endif

	for (int i = 0; i < NUM_TRIS; i++)
	{
		a = ShadowTable[(i * 3) + 0] * 3;
		b = ShadowTable[(i * 3) + 1] * 3;
		c = ShadowTable[(i * 3) + 2] * 3;
		x1 = (long)pmxz[a + 0];
		y1 = (long)pmxz[a + 1];
		z1 = (long)pmxz[a + 2];
		x2 = (long)pmxz[b + 0];
		y2 = (long)pmxz[b + 1];
		z2 = (long)pmxz[b + 2];
		x3 = (long)pmxz[c + 0];
		y3 = (long)pmxz[c + 1];
		z3 = (long)pmxz[c + 2];
		setXYZ3(v, x1, y1, z1, x2, y2, z2, x3, y3, z3, clipflags);
		v[0].color = color;
		v[1].color = color;
		v[2].color = color;
		v[3].color = color;

		if (item->after_death)
		{
			v[0].color &= 0x00FFFFFF;
			v[1].color &= 0x00FFFFFF;
			v[2].color &= 0x00FFFFFF;
			v[3].color &= 0x00FFFFFF;
			v[0].color |= (128 - item->after_death) << 24;
			v[1].color |= (128 - item->after_death) << 24;
			v[2].color |= (128 - item->after_death) << 24;
			v[3].color |= (128 - item->after_death) << 24;
		}

		v[0].specular = 0xFF000000;
		v[1].specular = 0xFF000000;
		v[2].specular = 0xFF000000;
		v[3].specular = 0xFF000000;
		Tex.drawtype = 3;
		Tex.flag = 0;
		Tex.tpage = 0;
		Tex.u1 = 0;
		Tex.v1 = 0;
		Tex.u2 = 0;
		Tex.v2 = 0;
		Tex.u3 = 0;
		Tex.v3 = 0;
		Tex.u4 = 0;
		Tex.v4 = 0;
		AddTriSorted(v, 0, 1, 2, &Tex, 1);
	}
}

void DrawLaserSightSprite()
{
	SPRITESTRUCT* sprite;
	D3DTLVERTEX v[4];
	TEXTURESTRUCT Tex;
	long* TempIDK;
	short* TempDist;
	short* TempXY;
	float zv, u1, u2, v1, v2;
	long results[3];

	phd_PushMatrix();
	phd_TranslateAbs(lara_item->pos.x_pos, lara_item->pos.y_pos, lara_item->pos.z_pos);
	TempDist = (short*)&UNK_EffectDistance;
	TempXY = (short*)&UNK_EffectXY;
	TempIDK = (long*)&UNK_00E913E0;
	TempDist[0] = (short)(LaserSightX - lara_item->pos.x_pos);
	TempDist[1] = (short)(LaserSightY - lara_item->pos.y_pos);
	TempDist[2] = (short)(LaserSightZ - lara_item->pos.z_pos);
	results[0] = phd_mxptr[0] * TempDist[0] + phd_mxptr[1] * TempDist[1] + phd_mxptr[2] * TempDist[2] + phd_mxptr[3];
	results[1] = phd_mxptr[4] * TempDist[0] + phd_mxptr[5] * TempDist[1] + phd_mxptr[6] * TempDist[2] + phd_mxptr[7];
	results[2] = phd_mxptr[8] * TempDist[0] + phd_mxptr[9] * TempDist[1] + phd_mxptr[10] * TempDist[2] + phd_mxptr[11];
	zv = f_persp / (float)results[2];
	TempXY[0] = short(float(results[0] * zv + f_centerx));
	TempXY[1] = short(float(results[1] * zv + f_centery));
	TempIDK[0] = results[2] >> 14;//?????????????????????? why lmao
	phd_PopMatrix();
	sprite = &spriteinfo[objects[DEFAULT_SPRITES].mesh_index + 14];
	setXY4(v, TempXY[0] - 2, TempXY[1] - 2, TempXY[0] + 2, TempXY[1] - 2, TempXY[0] - 2, TempXY[1] + 2, TempXY[0] + 2, TempXY[1] + 2, (int)f_mznear, clipflags);
	v[0].color = LaserSightCol ? 0x0000FF00 : 0x00FF0000;//if LaserSightCol is on, it turns green
	v[1].color = v[0].color;
	v[2].color = v[0].color;
	v[3].color = v[0].color;
	v[0].specular = 0xFF000000;
	v[1].specular = 0xFF000000;
	v[2].specular = 0xFF000000;
	v[3].specular = 0xFF000000;
	u1 = sprite->x2;
	u2 = sprite->x1;
	v1 = sprite->y2;
	v2 = sprite->y1;
	Tex.drawtype = 2;
	Tex.flag = 0;
	Tex.tpage = sprite->tpage;
	Tex.u1 = u1;
	Tex.v1 = v1;
	Tex.u2 = u2;
	Tex.v2 = v1;
	Tex.u3 = u2;
	Tex.v3 = v2;
	Tex.u4 = u1;
	Tex.v4 = v2;
	AddQuadSorted(v, 0, 1, 2, 3, &Tex, 0);
	LaserSightCol = 0;
	LaserSightActive = 0;
}

void inject_specificfx(bool replace)
{
	INJECT(0x004C2F10, S_PrintShadow, replace);
	INJECT(0x004C7320, DrawLaserSightSprite, replace);
}
