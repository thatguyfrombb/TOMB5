#pragma once
#include "../global/vars.h"

void inject_lara(bool replace);

extern void (*lara_control_routines[])(ITEM_INFO* item, COLL_INFO* coll);
extern void (*lara_collision_routines[])(ITEM_INFO* item, COLL_INFO* coll);

void LaraDeflectEdgeJump(ITEM_INFO* item, COLL_INFO* coll);
void GetLaraCollisionInfo(ITEM_INFO* item, COLL_INFO* coll);
int LaraLandedBad(ITEM_INFO* item, COLL_INFO* coll);
int TestLaraSlide(ITEM_INFO* item, COLL_INFO* coll);
int LaraDeflectEdge(ITEM_INFO* item, COLL_INFO* coll);
void LaraCollideStop(ITEM_INFO* item, COLL_INFO* coll);
int LaraHitCeiling(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_fastback(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_fastback(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_fallback(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_fallback(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_jumper(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_leftjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_leftjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_rightjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_rightjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_backjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_backjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_forwardjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_forwardjump(ITEM_INFO* item, COLL_INFO* coll);
void LookUpDown();
void LookLeftRight();
void ResetLook();
void lara_void_func(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_walk(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_walk(ITEM_INFO* item, COLL_INFO* coll);
int LaraFallen(ITEM_INFO* item, COLL_INFO* coll);
int TestLaraVault(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_null(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_run(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_run(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_stop(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_stop(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_back(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_back(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_wade(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_wade(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_dash(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_dash(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_dashdive(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_dashdive(ITEM_INFO* item, COLL_INFO* coll);
void lara_default_col(ITEM_INFO* item, COLL_INFO* coll);
int TestWall(ITEM_INFO* item, long front, long right, long down);
short LaraFloorFront(ITEM_INFO* item, short ang, long dist);
short LaraCeilingFront(ITEM_INFO* item, short ang, long dist, long h);
void lara_as_turn_r(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_turn_r(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_turn_l(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_turn_l(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_death(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_death(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_fastfall(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_fastfall(ITEM_INFO* item, COLL_INFO* coll);
void LaraSlideEdgeJump(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_hang(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_hang(ITEM_INFO* item, COLL_INFO* coll);
int CanLaraHangSideways(ITEM_INFO* item, COLL_INFO* coll, short angle);
void lara_as_reach(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_reach(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_splat(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_splat(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_land(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_compress(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_compress(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_fastturn(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_fastturn(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_stepright(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_stepright(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_stepleft(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_stepleft(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_roll2(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_slide(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_slide(ITEM_INFO* item, COLL_INFO* coll);
void lara_slide_slope(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_upjump(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_upjump(ITEM_INFO* item, COLL_INFO* coll);
void MonkeySwingSnap(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_hangleft(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_hangleft(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_hangright(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_hangright(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_slideback(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_slideback(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pushblock(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pullblock(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_ppready(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_usepuzzle(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_usekey(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_switchoff(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_switchon(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pickupflare(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pickup(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_special(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_swandive(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_swandive(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_fastdive(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_fastdive(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_gymnast(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_duck(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_duck(ITEM_INFO* item, COLL_INFO* coll);
void MonkeySwingFall(ITEM_INFO* item);
void lara_as_hang2(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_hang2(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_monkeyswing(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_monkeyswing(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_monkeyl(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_monkeyl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_monkeyr(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_monkeyr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_monkey180(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_monkey180(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_all4s(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_all4s(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_crawl(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_crawl(ITEM_INFO* item, COLL_INFO* coll);
int LaraDeflectEdgeDuck(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_hangturnl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_hangturnr(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_hangturnlr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_all4turnl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_all4turnr(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_all4turnlr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_crawlb(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_crawlb(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_crawl2hang(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_controlled(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_controlledl(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_roll(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_pose(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_waterout(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_deathslide(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_turnswitch(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_poleleft(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_poleright(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_polestat(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_poleup(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_poledown(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_duckl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_duckr(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_ducklr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_extcornerl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_extcornerr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_intcornerl(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_intcornerr(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pulley(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_rope(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_rope(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_climbrope(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_climbroped(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_ropefwd(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_ropel(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_roper(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_trpose(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_trwalk(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_trfall(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_parallelbars(ITEM_INFO* item, COLL_INFO* coll);
void lara_as_pbleapoff(ITEM_INFO* item, COLL_INFO* coll);
void LaraAboveWater(ITEM_INFO* item, COLL_INFO* coll);
void FallFromRope(ITEM_INFO* item);
void UpdateRopeSwing(ITEM_INFO* item);
void ApplyVelocityToRope(int node, ushort angle, ushort n);
void JumpOffRope(ITEM_INFO* item);
int LaraHangTest(ITEM_INFO* item, COLL_INFO* coll);

#ifndef GENERAL_FIXES
void lara_as_duckroll(ITEM_INFO* item, COLL_INFO* coll);
void lara_col_duckroll(ITEM_INFO* item, COLL_INFO* coll);
#endif

#define LaraTestClimbStance	( (int(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x00445580 )
#define LaraHangLeftCornerTest	( (int(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x0044A2B0 )
#define LaraHangRightCornerTest	( (int(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x00449CC0 )
#define LaraTestEdgeCatch	( (int(__cdecl*)(ITEM_INFO*, COLL_INFO*, long*)) 0x00444890 )
#define LaraTestHangOnClimbWall	( (int(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x00444970 )
#define TestHangSwingIn	( (int(__cdecl*)(ITEM_INFO*, short)) 0x00444B30 )
#define TestMonkeyLeft	( (short(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x00446810 )
#define TestMonkeyRight	( (short(__cdecl*)(ITEM_INFO*, COLL_INFO*)) 0x00446960 )
#define SetCornerAnim	( (void(__cdecl*)(ITEM_INFO*, COLL_INFO*, short, short)) 0x0044A980 )
#define GetTighRopeFallOff	( (void(__cdecl*)(long)) 0x0044D570 )
#define SnapLaraToEdgeOfBlock	( (void(__cdecl*)(ITEM_INFO*, COLL_INFO*, short)) 0x004466C0 )
