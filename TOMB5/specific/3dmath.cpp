#include "../tomb5/pch.h"
#include "3dmath.h"


void AlterFOV(short fov)
{
	static short old_fov;

	old_fov = fov;

	if (fov)
		old_fov = fov;
	else
		fov = old_fov;

	CurrentFOV = fov;
	phd_persp = phd_winwidth / 2 * phd_cos(fov / 2) / (phd_sin(fov / 2));
	f_persp_bis = (float)phd_persp;
	flt_55D1F8 = dword_50A440 / f_persp_bis;
	f_persp_bis_over_znear3 = f_persp_bis / f_znear3;
	LfAspectCorrection = (4.0f / 3.0f) / (phd_winwidth / phd_winheight);
	f_persp = (float)phd_persp;
	f_oneopersp = one / f_persp;
	f_perspoznear = f_persp / f_znear;
}

void gte_sttr(PHD_VECTOR* vec)
{
	vec->x = phd_mxptr[3] >> 14;
	vec->y = phd_mxptr[7] >> 14;
	vec->z = phd_mxptr[11] >> 14;
}

void inject_3dmath()
{
	INJECT(0x0048EDC0, AlterFOV);
	INJECT(0x00491320, gte_sttr);
}