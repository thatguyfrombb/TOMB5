#include "../tomb5/pch.h"
#include "draw.h"
#include "../specific/3dmath.h"
#include "../specific/output.h"
#include "delstuff.h"
#include "deltapak.h"
#include "../specific/drawlara.h"
#include "health.h"

short* GetBoundsAccurate(ITEM_INFO* item)
{
	int rate, frac;
	short* frmptr[2];
	short* bptr;
	
	frac = GetFrames(item, frmptr, &rate);

	if (frac == 0)
		return frmptr[0];

	bptr = interpolated_bounds;

	for (int i = 0; i < 6; i++, bptr++, frmptr[0]++, frmptr[1]++)
		*bptr = *frmptr[0] + (*frmptr[1] - *frmptr[0]) * frac / rate;

	return interpolated_bounds;
}

short* GetBestFrame(ITEM_INFO* item)
{
	short* frm[2];
	int rate;
	int ret;
	
	ret = GetFrames(item, frm, &rate);

	if (ret > (rate >> 1))
		return frm[1];
	else
		return frm[0];
}

void InitInterpolate(int frac, int rate)
{
	IM_rate = rate;
	IM_frac = frac;
	IMptr = IMstack;
	aIMXPtr = aIFMStack;
	memcpy(IMstack, phd_mxptr, 48);
	memcpy(aIFMStack, aMXPtr, 48);
}

void phd_PopMatrix_I()
{
	phd_PopMatrix();
	IMptr -= 12;
	aIMXPtr -= 12;
}

void phd_PushMatrix_I()
{
	phd_PushMatrix();
	memcpy(IMptr + 12, IMptr, 48);
	memcpy(aIMXPtr + 12, aIMXPtr, 48);
	IMptr += 12;
	aIMXPtr += 12;
}

void phd_RotY_I(short ang)
{
	long* mxptr;
	float* amxptr;

	phd_RotY(ang);
	mxptr = phd_mxptr;
	amxptr = aMXPtr;
	phd_mxptr = IMptr;
	aMXPtr = aIMXPtr;
	phd_RotY(ang);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void phd_RotX_I(short ang)
{
	long* mxptr;
	float* amxptr;

	phd_RotX(ang);
	mxptr = phd_mxptr;
	amxptr = aMXPtr;
	phd_mxptr = IMptr;
	aMXPtr = aIMXPtr;
	phd_RotX(ang);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void phd_RotZ_I(short ang)
{
	long* mxptr;
	float* amxptr;

	phd_RotZ(ang);
	mxptr = phd_mxptr;
	amxptr = aMXPtr;
	phd_mxptr = IMptr;
	aMXPtr = aIMXPtr;
	phd_RotZ(ang);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void phd_TranslateRel_I(int x, int y, int z)
{
	long* mxptr;
	float* amxptr;

	phd_TranslateRel(x, y, z);
	mxptr = phd_mxptr;
	phd_mxptr = IMptr;
	amxptr = aMXPtr;
	aMXPtr = aIMXPtr;
	phd_TranslateRel(x, y, z);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void phd_TranslateRel_ID(int x, int y, int z, int x2, int y2, int z2)
{
	long* mxptr;
	float* amxptr;

	phd_TranslateRel(x, y, z);
	mxptr = phd_mxptr;
	amxptr = aMXPtr;
	phd_mxptr = IMptr;
	aMXPtr = aIMXPtr;
	phd_TranslateRel(x2, y2, z2);
	aMXPtr = amxptr;
	phd_mxptr = mxptr;
}

void phd_RotYXZ_I(short y, short x, short z)
{
	long* mxptr;
	float* amxptr;

	phd_RotYXZ(y, x, z);
	mxptr = phd_mxptr;
	phd_mxptr = IMptr;
	amxptr = aMXPtr;
	aMXPtr = aIMXPtr;
	phd_RotYXZ(y, x, z);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void gar_RotYXZsuperpack_I(short** pprot1, short** pprot2, int skip)
{
	long* mxptr;
	float* amxptr;

	gar_RotYXZsuperpack(pprot1, skip);
	mxptr = phd_mxptr;
	amxptr = aMXPtr;
	phd_mxptr = IMptr;
	aMXPtr = aIMXPtr;
	gar_RotYXZsuperpack(pprot2, skip);
	phd_mxptr = mxptr;
	aMXPtr = amxptr;
}

void gar_RotYXZsuperpack(short** pprot, int skip)
{
	ushort* prot;
//	long packed;

	while (skip)
	{
		prot = (ushort*)*pprot;

		if (*prot & (49152))
			*pprot += 1;
		else
			*pprot += 2;

		skip--;
	}

	prot = (ushort*)*pprot;

	if ((*prot >> 14))
	{
		if ((*prot >> 14) == 1)
			phd_RotX((short)((*prot & 4095) << 4));
		else if ((*prot >> 14) == 2)
			phd_RotY((short)((*prot & 4095) << 4));
		else
			phd_RotZ((short)((*prot & 4095) << 4));
	}
	else
	{
		phd_RotYXZpack(((ushort)**pprot << 16) + (ushort)(*pprot)[1]);
		*pprot += 2;
		return;
	}

	++*pprot;
}

void phd_PutPolygons_I(short* ptr, int clip)
{
	phd_PushMatrix();
	InterpolateMatrix();
	phd_PutPolygons(ptr, clip);
	phd_PopMatrix();
}

void aInterpolateMatrix()
{
	float* matrixp;
	float* iMatrixp;

	matrixp = aMXPtr;
	iMatrixp = aIMXPtr;

	if (IM_rate == 2)
	{
		matrixp[0] = (float)((iMatrixp[0] + matrixp[0]) * 0.5);
		matrixp[1] = (float)((iMatrixp[1] + matrixp[1]) * 0.5);
		matrixp[2] = (float)((iMatrixp[2] + matrixp[2]) * 0.5);
		matrixp[3] = (float)((iMatrixp[3] + matrixp[3]) * 0.5);
		matrixp[4] = (float)((iMatrixp[4] + matrixp[4]) * 0.5);
		matrixp[5] = (float)((iMatrixp[5] + matrixp[5]) * 0.5);
		matrixp[6] = (float)((iMatrixp[6] + matrixp[6]) * 0.5);
		matrixp[7] = (float)((iMatrixp[7] + matrixp[7]) * 0.5);
		matrixp[8] = (float)((iMatrixp[8] + matrixp[8]) * 0.5);
		matrixp[9] = (float)((iMatrixp[9] + matrixp[9]) * 0.5);
		matrixp[10] = (float)((iMatrixp[10] + matrixp[10]) * 0.5);
		matrixp[11] = (float)((iMatrixp[11] + matrixp[11]) * 0.5);
		return;
	}

	if (IM_frac == 2)
	{
		if (IM_rate != 4)
		{
			matrixp[0] = iMatrixp[0] - (float)((iMatrixp[0] - matrixp[0]) * 0.25);
			matrixp[1] = iMatrixp[1] - (float)((iMatrixp[1] - matrixp[1]) * 0.25);
			matrixp[2] = iMatrixp[2] - (float)((iMatrixp[2] - matrixp[2]) * 0.25);
			matrixp[3] = iMatrixp[3] - (float)((iMatrixp[3] - matrixp[3]) * 0.25);
			matrixp[4] = iMatrixp[4] - (float)((iMatrixp[4] - matrixp[4]) * 0.25);
			matrixp[5] = iMatrixp[5] - (float)((iMatrixp[5] - matrixp[5]) * 0.25);
			matrixp[6] = iMatrixp[6] - (float)((iMatrixp[6] - matrixp[6]) * 0.25);
			matrixp[7] = iMatrixp[7] - (float)((iMatrixp[7] - matrixp[7]) * 0.25);
			matrixp[8] = iMatrixp[8] - (float)((iMatrixp[8] - matrixp[8]) * 0.25);
			matrixp[9] = iMatrixp[9] - (float)((iMatrixp[9] - matrixp[9]) * 0.25);
			matrixp[10] = iMatrixp[10] - (float)((iMatrixp[10] - matrixp[10]) * 0.25);
			matrixp[11] = iMatrixp[11] - (float)((iMatrixp[11] - matrixp[11]) * 0.25);
			return;
		}

		matrixp[0] = (float)((iMatrixp[0] + matrixp[0]) * 0.5);
		matrixp[1] = (float)((iMatrixp[1] + matrixp[1]) * 0.5);
		matrixp[2] = (float)((iMatrixp[2] + matrixp[2]) * 0.5);
		matrixp[3] = (float)((iMatrixp[3] + matrixp[3]) * 0.5);
		matrixp[4] = (float)((iMatrixp[4] + matrixp[4]) * 0.5);
		matrixp[5] = (float)((iMatrixp[5] + matrixp[5]) * 0.5);
		matrixp[6] = (float)((iMatrixp[6] + matrixp[6]) * 0.5);
		matrixp[7] = (float)((iMatrixp[7] + matrixp[7]) * 0.5);
		matrixp[8] = (float)((iMatrixp[8] + matrixp[8]) * 0.5);
		matrixp[9] = (float)((iMatrixp[9] + matrixp[9]) * 0.5);
		matrixp[10] = (float)((iMatrixp[10] + matrixp[10]) * 0.5);
		matrixp[11] = (float)((iMatrixp[11] + matrixp[11]) * 0.5);
		return;
	}

	if (IM_frac != 1)
	{
		matrixp[0] = iMatrixp[0] - (float)((iMatrixp[0] - matrixp[0]) * 0.25);
		matrixp[1] = iMatrixp[1] - (float)((iMatrixp[1] - matrixp[1]) * 0.25);
		matrixp[2] = iMatrixp[2] - (float)((iMatrixp[2] - matrixp[2]) * 0.25);
		matrixp[3] = iMatrixp[3] - (float)((iMatrixp[3] - matrixp[3]) * 0.25);
		matrixp[4] = iMatrixp[4] - (float)((iMatrixp[4] - matrixp[4]) * 0.25);
		matrixp[5] = iMatrixp[5] - (float)((iMatrixp[5] - matrixp[5]) * 0.25);
		matrixp[6] = iMatrixp[6] - (float)((iMatrixp[6] - matrixp[6]) * 0.25);
		matrixp[7] = iMatrixp[7] - (float)((iMatrixp[7] - matrixp[7]) * 0.25);
		matrixp[8] = iMatrixp[8] - (float)((iMatrixp[8] - matrixp[8]) * 0.25);
		matrixp[9] = iMatrixp[9] - (float)((iMatrixp[9] - matrixp[9]) * 0.25);
		matrixp[10] = iMatrixp[10] - (float)((iMatrixp[10] - matrixp[10]) * 0.25);
		matrixp[11] = iMatrixp[11] - (float)((iMatrixp[11] - matrixp[11]) * 0.25);
		return;
	}

	matrixp[0] += (float)((iMatrixp[0] - matrixp[0]) * 0.25);
	matrixp[1] += (float)((iMatrixp[1] - matrixp[1]) * 0.25);
	matrixp[2] += (float)((iMatrixp[2] - matrixp[2]) * 0.25);
	matrixp[3] += (float)((iMatrixp[3] - matrixp[3]) * 0.25);
	matrixp[4] += (float)((iMatrixp[4] - matrixp[4]) * 0.25);
	matrixp[5] += (float)((iMatrixp[5] - matrixp[5]) * 0.25);
	matrixp[6] += (float)((iMatrixp[6] - matrixp[6]) * 0.25);
	matrixp[7] += (float)((iMatrixp[7] - matrixp[7]) * 0.25);
	matrixp[8] += (float)((iMatrixp[8] - matrixp[8]) * 0.25);
	matrixp[9] += (float)((iMatrixp[9] - matrixp[9]) * 0.25);
	matrixp[10] += (float)((iMatrixp[10] - matrixp[10]) * 0.25);
	matrixp[11] += (float)((iMatrixp[11] - matrixp[11]) * 0.25);
}

long DrawPhaseGame()
{
	CalcLaraMatrices(0);
	phd_PushUnitMatrix();
	CalcLaraMatrices(1);
	phd_PopMatrix();

	if (GLOBAL_playing_cutseq)
		frigup_lara();

	SetLaraUnderwaterNodes();
	DrawRooms(camera.pos.room_number);
	DrawGameInfo(1);
	S_OutputPolyList();
	camera.number_frames = S_DumpScreen();
	S_AnimateTextures(camera.number_frames);
	return camera.number_frames;
}

void inject_draw()
{
	INJECT(0x0042CF80, GetBoundsAccurate);
	INJECT(0x0042D020, GetBestFrame);
	INJECT(0x0042BE90, InitInterpolate);
	INJECT(0x0042BF00, phd_PopMatrix_I);
	INJECT(0x0042BF50, phd_PushMatrix_I);
	INJECT(0x0042BFC0, phd_RotY_I);
	INJECT(0x0042C030, phd_RotX_I);
	INJECT(0x0042C0A0, phd_RotZ_I);
	INJECT(0x0042C110, phd_TranslateRel_I);
	INJECT(0x0042C190, phd_TranslateRel_ID);
	INJECT(0x0042C210, phd_RotYXZ_I);
	INJECT(0x0042C290, gar_RotYXZsuperpack_I);
	INJECT(0x0042C310, gar_RotYXZsuperpack);
	INJECT(0x0042C3F0, phd_PutPolygons_I);
	INJECT(0x0042C440, aInterpolateMatrix);
	INJECT(0x0042A400, DrawPhaseGame);
}
