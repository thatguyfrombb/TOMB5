#pragma once
#include "types.h"
#include "math_tbls.h"

// Variable macros
#define VAR_U_(address, type)			(*(type*)(address)) // uninitialized variable
#define VAR_I_(address, type, value)	(*(type*)(address)) // initialized variable (value is just for info)
#define ARRAY_(address, type, length)	(*(type(*)length)(address)) // array (can be multidimensional)

//vars
#define input VAR_U_(0x00878D98, int)
#define dbinput   VAR_U_(0x00878DAC, int)
#define lara_coll   VAR_U_(0x00508778, COLL_INFO*)
#define lara    VAR_U_(0x00E5BD60, LARA_INFO)
#define lara_item    VAR_U_(0x00E5BF08, ITEM_INFO*)
#define DashTimer VAR_U_(0x00E5BF04, ushort)
#define anims	VAR_U_(0x00875158, ANIM_STRUCT*)
#define items	VAR_U_(0x00EEEFF0, ITEM_INFO*)
#define effects	VAR_U_(0x00E5C5E0, FX_INFO*)
#define room	VAR_U_(0x00875154, ROOM_INFO*)
#define	meshes	VAR_U_(0x00875170, short**)
#define bones	VAR_U_(0x00875178, long*)
#define height_type VAR_U_(0x00EEEFF4, int)
#define trigger_index VAR_U_(0x00EEEF9C, short*)
#define xfront VAR_U_(0x00EEf928, long)
#define zfront VAR_U_(0x00EEf92C, long)
#define GLOBAL_cutseq_frame VAR_U_(0x00E7F024, int)
#define old_lara_holster VAR_U_(0x00E7EFE0, ushort)
#define actor_chat_cnt VAR_U_(0x0051CAB6, char)
#define lara_chat_cnt	VAR_U_(0x0051CAB5, char)
#define gfCurrentLevel VAR_U_(0x00E5C2D0, uchar)
#define gfLevelComplete VAR_U_(0x00E5C2F0, uchar)
#define gfLevelFlags	VAR_U_(0x00E5C2A0, short)
#define gfGameMode	VAR_U_(0x005082C0, uchar)
#define cutseq_num	VAR_U_(0x0051CAA8, int)
#define cutseq_trig	VAR_U_(0x0051CAAC, int)
#define cutseq_busy_timeout	VAR_U_(0x0051CAB4, char)
#define bTrackCamInit	VAR_U_(0x0051D010, int)
#define bUseSpotCam	VAR_U_(0x0051D018, int)
#define SetDebounce	VAR_U_(0x00EEEA38, int)
#define framecount	VAR_U_(0x0051CA78, int)
#define GlobalCounter	VAR_U_(0x0051CA58, ushort)
#define cdtrack	VAR_U_(0x00506C64, short)
#define bDisableLaraControl	VAR_U_(0x0051D01C, int)
#define GLOBAL_enterinventory	VAR_U_(0x00508E18, int)
#define GLOBAL_playing_cutseq	VAR_U_(0x0051CAB0, int)
#define GLOBAL_inventoryitemchosen	VAR_U_(0x00508E1C, int)
#define reset_flag	VAR_U_(0x0051CA6C, int)
#define FadeScreenHeight	VAR_U_(0x0051D074, short)
#define thread_started	VAR_U_(0x00876C48, bool)
#define SniperCamActive	VAR_U_(0x0051CA1D, char)
#define BinocularRange	VAR_U_(0x0051CA30, long)
#define BinocularOn	VAR_U_(0x0051CA34, long)
#define BinocularOldCamera	VAR_U_(0x0051CA38, camera_type)
#define LaserSight	VAR_U_(0x0051CA3C, long)
#define InfraRed	VAR_U_(0x0051CA40, long)
#define inputBusy	VAR_U_(0x00878C94, int)
#define GotLaraSpheres	VAR_U_(0x00E51F2E, char)
#define InItemControlLoop	VAR_U_(0x0051CA53, uchar)
#define next_item_active	VAR_U_(0x00E5BF22, short)
#define next_fx_active	VAR_U_(0x00E5C5FC, short)
#define KillEverythingFlag	VAR_U_(0x0051CDF4, long)
#define SmokeCountL	VAR_U_(0x00E6C9E8, long)
#define SmokeCountR	VAR_U_(0x00E6C9EC, long)
#define SplashCount	VAR_U_(0x0051CDF8, long)
#define WeaponDelay	VAR_U_(0x0051CA52, uchar)
#define wibble	VAR_U_(0x0051CDF0, long)
#define XSoff1	VAR_U_(0x0055D200, short)
#define XSoff2	VAR_U_(0x0055D1FC, short)
#define YSoff1	VAR_U_(0x0055D210, short)
#define YSoff2	VAR_U_(0x0055D214, short)
#define	ZSoff1	VAR_U_(0x0055D244, short)
#define ZSoff2	VAR_U_(0x0055D248, short)
#define PoisonFlag	VAR_U_(0x00E5BF3E, char)
#define LaraDrawType	VAR_U_(0x00EEEAD0, char)
#define CamRot	VAR_U_(0x00E4B0E0, SVECTOR)
#define SmashedMeshCount	VAR_U_(0x0051CA5C, short)
#define health_bar_timer	VAR_U_(0x0051CEA8, int)
#define GameTimer	VAR_U_(0x00E5C27C, ulong)
#define Gameflow	VAR_U_(0x00E5C2BC, GAMEFLOW*)
#define camera	VAR_U_(0x00EEF940, CAMERA_INFO)
#define CamOldPos	VAR_U_(0x00EEFB00, PHD_VECTOR)
#define savegame	VAR_U_(0x00E52EB3, SAVEGAME_INFO)
#define NumRPickups	VAR_U_(0x00E5970C, uchar)
#define AnimatingWaterfallsVOffset	VAR_U_(0x0051CF54, int)
#define next_blood	VAR_U_(0x0051D088, long)
#define floor_data	VAR_U_(0x00875168, short*)
#define rand_1	VAR_U_(0x00516A38, long)
#define	rand_2	VAR_U_(0x00516A3C, long)
#define	last_target	VAR_U_(0x00EEFA30, GAME_VECTOR)
#define	last_ideal	VAR_U_(0x00EEFA40, GAME_VECTOR)
#define UseForcedFixedCamera	VAR_U_(0x00EEFA50, char)
#define	InGameCnt	VAR_U_(0x00E5BF0C, uchar)
#define	cheat_hit_points	VAR_U_(0x00E5BBF8, short)
#define	gfNumPickups	VAR_U_(0x0051CE38, uchar)
#define gfNumTakeaways	VAR_U_(0x0051CE39, uchar)
#define	disable_horizon	VAR_U_(0x0051CAA4, uchar)
#define	level_items	VAR_U_(0x0051CEB8, int)
#define	cutseq_num	VAR_U_(0x0051CAA8, int)
#define	cutseq_trig	VAR_U_(0x0051CAAC, int)
#define	numnailed	VAR_U_(0x00E6E4E4, int)
#define	GLOBAL_cutme	VAR_U_(0x00E711B0, NEW_CUTSCENE*)
#define	dels_cutseq_player	VAR_U_(0x0051CE2C, ushort)
#define	GLOBAL_oldcamtype	VAR_U_(0x00E711AC, camera_type)
#define	CurrentAtmosphere	VAR_U_(0x00EEEB90, uchar)
#define	IsAtmospherePlaying	VAR_U_(0x00EEEFFC, uchar)
#define gfRequiredStartPos	VAR_U_(0x00E5C2B4, uchar)
#define	ScreenFade	VAR_U_(0x0051D068, short)
#define	dScreenFade	VAR_U_(0x0051D06A, short)
#define	ScreenFadeBack	VAR_U_(0x0051D06C, short)
#define ScreenFadeSpeed	VAR_U_(0x0050A178, short)
#define	ScreenFadedOut	VAR_U_(0x0051D06E, short)
#define ScreenFading	VAR_U_(0x0051D070, short)
#define	cut_seethrough	VAR_U_(0x00506D9C, int)
#define	cutrot	VAR_U_(0x0051CAA0, int)
#define bDoCredits	VAR_U_(0x0051CE35, uchar)
#define num_fmvs	VAR_U_(0x0051CE25, char)
#define gfScriptWad	VAR_U_(0x0051CE20, uchar*)
#define	gfStringWad	VAR_U_(0x00E5C310, char*)
#define	gfFilenameWad	VAR_U_(0x00E5C2CC, char*)
#define gfScriptOffset	VAR_U_(0x0051CE10, ushort*)
#define	gfStringOffset	VAR_U_(0x00E5C2AC, ushort*)
#define gfStringOffset_bis	VAR_U_(0x00E5C2B8, ushort*)
#define gfStatus	VAR_U_(0x00E5C2B0, int)
#define gfLegend	VAR_U_(0x00E5C348, uchar)
#define gfLegendTime	VAR_U_(0x0051CE34, uchar)
#define gfUVRotate	VAR_U_(0x00E5C349, char)
#define gfNumMips	VAR_U_(0x0051CE37, uchar)
#define gfMirrorRoom	VAR_U_(0x00E5C24C, uchar)
#define gfMirrorZPlane	VAR_U_(0x00E6D748, long)
#define gfInitialiseGame	VAR_U_(0x005082C1, uchar)	
#define	gfLayer1Col	VAR_U_(0x00E5C2A4, CVECTOR)
#define gfLayer2Col	VAR_U_(0x00E5C280, CVECTOR)
#define	gfLayer1Vel	VAR_U_(0x00E5C276, char)
#define	gfLayer2Vel	VAR_U_(0x00E5C275, char)	
#define gfLensFlare	VAR_U_(0x00E5C2E0, PHD_VECTOR)
#define gfLensFlareColour	VAR_U_(0x00E5C2F4, CVECTOR)
#define gfResetHubDest	VAR_U_(0x00E5C2C8, uchar)
#define gfCutNumber	VAR_U_(0x0051CE36, uchar)
#define	changes	VAR_U_(0x0087515C, CHANGE_STRUCT*)
#define ranges	VAR_U_(0x00875160, RANGE_STRUCT*)
#define commands	VAR_U_(0x0087517C, short*)
#define	FXType	VAR_U_(0x00EEF900, short)
#define flipeffect	VAR_U_(0x00506C60, int)
#define	KeyTriggerActive	VAR_U_(0x0051CA56, uchar)
#define TriggerTimer	VAR_U_(0x0051CA5A, char)
#define OnObject	VAR_U_(0x00EEEAC8, int)
#define FootPrintNum	VAR_U_(0x00E5C350, int)
#define	number_dynamics	VAR_U_(0x00E6D82C, int)
#define	tiltyoff	VAR_U_(0x00EEEADC, int)
#define	tiltxoff	VAR_U_(0x00EEEAD4, int)
#define	baddie_slots	VAR_U_(0x00E5B834, CREATURE_INFO*)
#define stats_mode	VAR_U_(0x0051CF26, short)
#define go_select	VAR_U_(0x00E59E2A, uchar)
#define	go_deselect	VAR_U_(0x00E5992C, uchar)
#define go_right	VAR_U_(0x00E5989C, uchar)
#define	go_left	VAR_U_(0x00E59899, uchar)
#define go_up	VAR_U_(0x00E59922, uchar)
#define go_down	VAR_U_(0x00E59929, uchar)
#define keypadx	VAR_U_(0x0051CF30, uchar)
#define keypady	VAR_U_(0x0051CF31, uchar)
#define keypadnuminputs	VAR_U_(0x0051CF32, uchar)
#define keypadpause	VAR_U_(0x0051CF33, uchar)
#define GnFrameCounter	VAR_U_(0x00E4B0FC, ulong)
#define use_the_bitch	VAR_U_(0x00E59921, char)	
#define menu_active	VAR_U_(0x00E5989A, char)
#define inventry_xpos	VAR_U_(0x0051CF34, short)
#define inventry_ypos	VAR_U_(0x0051CF36, short)
#define SmokeWeapon	VAR_U_(0x00E6CAA0, long)
#define HKTimer	VAR_U_(0x0051CEC9, char)
#define HKShotsFired	VAR_U_(0x0051CEC8, char)
#define joy_fire	VAR_U_(0x00878D9C, int)
#define joy_x	VAR_U_(0x00878DA0, int)
#define joy_y	VAR_U_(0x00878DA4, int)
#define XATrack	VAR_U_(0x00510B14, long)
#define MusicVolume	VAR_U_(0x00E4B0EC, int)
#define TargetSnaps	VAR_U_(0x0051CA2D, char)
#define SniperCount	VAR_U_(0x0051CA1C, char)
#define TLFlag	VAR_U_(0x0051CA44, char)
#define SniperOverlay	VAR_U_(0x0051D022, char)
#define sound_effects	VAR_U_(0x00E5C5F8, OBJECT_VECTOR*)
#define number_sound_effects	VAR_U_(0x00E5C5F0, int)
#define sound_active	VAR_U_(0x0051D004, int)
#define sample_infos	VAR_U_(0x00E528A8, SAMPLE_INFO*)
#define _wf	VAR_U_(0x005078F0, long)
#define sample_lut	VAR_U_(0x00E528A4, short*)
#define examine_mode	VAR_U_(0x0051CF24, short)
#define boxes	VAR_U_(0x00EEFB64, BOX_INFO*)
#define SubHitCount	VAR_U_(0x0051CEE4, char)
#define subsuit	VAR_U_(0x00E5B850, SUBSUIT_INFO)
#define OldPickupPos	VAR_U_(0x00E59700, PHD_VECTOR)
#define CurrentSequence	VAR_U_(0x00E4EA61, uchar)
#define FlashFadeR	VAR_U_(0x0051D07A, short)
#define FlashFadeG	VAR_U_(0x0051D07C, short)
#define FlashFadeB	VAR_U_(0x0051D07E, short)
#define FlashFader	VAR_U_(0x0051D080, short)
#define PickupX	VAR_U_(0x00E5BF38, short)
#define PickupY	VAR_U_(0x00E5BF26, short)
#define PickupVel	VAR_U_(0x00E5BF3A, short)
#define CurrentPickup	VAR_U_(0x00E5BF3C, short)
#define Chris_Menu	VAR_U_(0x0051CE2E, char)
#define title_controls_locked_out	VAR_U_(0x00E5C2A8, char)
#define jobyfrigger	VAR_U_(0x0051CA9C, char)
#define CurrentPistolsAmmoType	VAR_U_(0x0051CF06, char)
#define CurrentUziAmmoType	VAR_U_(0x0051CF11, char)
#define CurrentRevolverAmmoType	VAR_U_(0x0051CF0A, char)
#define CurrentShotGunAmmoType	VAR_U_(0x0051CF0B, char)
#define CurrentGrenadeGunAmmoType	VAR_U_(0x0051CF00, char)
#define CurrentCrossBowAmmoType	VAR_U_(0x0051CF1C, char)
#define AmountPistolsAmmo	VAR_U_(0x0051CF16, short)
#define AmountRevolverAmmo	VAR_U_(0x0051CF14, short)
#define AmountHKAmmo1	VAR_U_(0x0051CF08, short)
#define AmountCrossBowAmmo1	VAR_U_(0x0051CF0E, short)
#define AmountCrossBowAmmo2	VAR_U_(0x0051CF0C, short)
#define AmountShotGunAmmo1	VAR_U_(0x0051CF04, short)
#define AmountShotGunAmmo2	VAR_U_(0x0051CF02, short)
#define AmountUziAmmo	VAR_U_(0x0051CF1A, short)
#define current_selected_option	VAR_U_(0x00E598F9, char)
#define ammo_active	VAR_U_(0x00E5991F, char)
#define right_repeat	VAR_U_(0x00E59915, uchar)
#define right_debounce	VAR_U_(0x00E59914, uchar)
#define left_repeat	VAR_U_(0x00E59E29, uchar)
#define left_debounce	VAR_U_(0x00E5989B, uchar)
#define	ammo_selector_fade_dir	VAR_U_(0x00E59926, short)
#define	ammo_selector_fade_val	VAR_U_(0x00E5990A, short)
#define	ammo_selector_flag	VAR_U_(0x00E59928, char)
#define num_ammo_slots	VAR_U_(0x00E598A4, char)
#define current_ammo_type	VAR_U_(0x00E59918, char*)
#define OBJLIST_SPACING	VAR_U_(0x00E59894, int)
#define combine_ring_fade_dir	VAR_U_(0x00E5991C, short)
#define	combine_obj1	VAR_U_(0x00E59912, short)
#define	combine_obj2	VAR_U_(0x00E59910, short)
#define	combine_ring_fade_val	VAR_U_(0x00E598F6, short)
#define	combine_type_flag	VAR_U_(0x00E59E28, short)
#define seperate_type_flag	VAR_U_(0x00E598F8, short)
#define loading_or_saving	VAR_U_(0x00E5989D, char)
#define normal_ring_fade_dir	VAR_U_(0x00E59924, short)
#define normal_ring_fade_val	VAR_U_(0x00E59908, short)
#define StashedCurrentPistolsAmmoType	VAR_U_(0x0051CF12, char)//static
#define StashedCurrentUziAmmoType	VAR_U_(0x0051CF01, char)//static
#define StashedCurrentRevolverAmmoType	VAR_U_(0x0051CF1D, char)//static
#define StashedCurrentShotGunAmmoType	VAR_U_(0x0051CF18, char)//static
#define StashedCurrentGrenadeGunAmmoType	VAR_U_(0x0051CF10, char)//static
#define StashedCurrentCrossBowAmmoType	VAR_U_(0x0051CF13, char)//static
#define Stashedcurrent_selected_option	VAR_U_(0x00E5992B, char)//static
#define	GLOBAL_invkeypadmode	VAR_U_(0x0051CF28, int)
#define up_debounce	VAR_U_(0x00E5992A, uchar)
#define down_debounce	VAR_U_(0x00E598D8, uchar)
#define GLOBAL_lastinvitem	VAR_U_(0x00508E14, int)
#define select_debounce	VAR_U_(0x00E59920, uchar)
#define deselect_debounce	VAR_U_(0x00E598F2, uchar)
#define friggrimmer	VAR_U_(0x00E598F4, char)
#define friggrimmer2	VAR_U_(0x00E598F3, char)
#define oldLaraBusy	VAR_U_(0x00E59898, char)
#define GLOBAL_numcutseq_frames	VAR_U_(0x00E7F020, int)
#define camera_pnodes	VAR_U_(0x00E7EE9C, PACKNODE*)
#define GLaraShadowframe	VAR_U_(0x00E86300, short*)
#define malloc_buffer	VAR_U_(0x00E4B10C, char*)
#define malloc_ptr	VAR_U_(0x00E4B0DC, char*)
#define malloc_size	VAR_U_(0x00E4B058, int)
#define malloc_used	VAR_U_(0x00E4B0F0, int)
#define malloc_free	VAR_U_(0x00E4B0F4, int)
#define ShatterItem	VAR_U_(0x00EEFAE0, SHATTER_ITEM)
#define GLOBAL_invkeypadcombination	VAR_U_(0x0051CF2C, int)
#define DestFadeScreenHeight	VAR_U_(0x0051D076, short)
#define dels_cutseq_selector_flag	VAR_U_(0x0051CE2A, short)
#define pcring1	VAR_U_(0x00E59BC0, RINGME)
#define pcring2	VAR_U_(0x00E59940, RINGME)
#define InventoryActive	VAR_U_(0x0051CF20, int)
#define xoffset	VAR_U_(0x00E598A0, int)//inv
#define yoffset	VAR_U_(0x00E5990C, int)//inv
#define pcbright	VAR_U_(0x00508E10, long)//inv
#define gfFog	VAR_U_(0x0051CE30, CVECTOR)
#define GlobalFogOff	VAR_U_(0x0051CE04, int)
#define LiftDoor	VAR_U_(0x0051CB40, char)
#define GlobalSoftReset	VAR_U_(0x00E5C2F8, int)
#define GlobalAlpha	VAR_U_(0x00506D3C, int)
#define current_item	VAR_U_(0x009158A8, ITEM_INFO*)
#define aGlobalSkinMesh	VAR_U_(0x00921680, int)
/*************************************************/
#define phd_top	VAR_U_(0x0051D0A8, long)
#define phd_bottom	VAR_U_(0x0055D204, long)
#define phd_left	VAR_U_(0x0055D20C, long)
#define phd_right	VAR_U_(0x0055DA3C, long)
#define	phd_winxmax	VAR_U_(0x0055D218, short)
#define	phd_winxmin	VAR_U_(0x0055D234, short)
#define	phd_winymax	VAR_U_(0x0055D240, short)
#define	phd_winymin	VAR_U_(0x0055D1E8, short)
#define phd_mxptr	VAR_U_(0x00E4B0F8, long*)
#define aMXPtr	VAR_U_(0x0055DA2C, float*)//formerly named phd_dxptr!
#define IM_rate	VAR_U_(0x00E6E464, long)
#define IM_frac	VAR_U_(0x00E6D734, long)
#define IMptr	VAR_U_(0x00E6E468, long*)
#define aIMXPtr	VAR_U_(0x00E6D834, float*)
#define aIFMStack	ARRAY_(0x00E6D860, float, [768])
#define	IMstack	ARRAY_(0x00E6CB00, long, [768])
#define f_mpersp	VAR_U_(0x0051D15C, float)
#define f_mznear	VAR_U_(0x0051D158, float)
#define	f_znear	VAR_U_(0x0055D24C, float)
#define	f_mzfar	VAR_U_(0x0055DA38, float)
#define f_moneopersp	VAR_U_(0x0055D254, float)
#define	f_oneopersp	VAR_U_(0x0055D1F8, float)
#define phd_centery	VAR_U_(0x0055D1B4, int)
#define	phd_centerx	VAR_U_(0x0055D1B0, int)
#define font_height	VAR_U_(0x00E4DEA8, int)
#define	tqFontHeight	VAR_U_(0x00E4DEAC, int)
#define	CurrentFov	VAR_U_(0x00E4F504, short)
#define	phd_winheight	VAR_U_(0x0055D164, int)
#define	phd_winwidth	VAR_U_(0x0055D29C, int)
#define	f_persp	VAR_U_(0x0055D268, float)
#define	f_perspoznear	VAR_U_(0x0055D238, float)
#define	mone	VAR_U_(0x0050A444, float)
#define one	VAR_U_(0x0050A440, float)
#define	phd_persp	VAR_U_(0x0055D208, int)
#define	LfAspectCorrection	VAR_U_(0x0055DA30, float)
#define	f_mperspoznear	VAR_U_(0x0055D668, float)
#define D3DMView	VAR_U_(0x00D9AD50, D3DMATRIX)
#define clip_left	VAR_U_(0x007EE0CC, float)
#define clip_right	VAR_U_(0x007ED698, float)
#define clip_top	VAR_U_(0x007EE0B0, float)
#define clip_bottom	VAR_U_(0x007E8EF0, float)
#define f_left	VAR_U_(0x0055D250, float)
#define f_right	VAR_U_(0x0051D160, float)
#define f_top	VAR_U_(0x0055D664, float)
#define f_bottom	VAR_U_(0x0055DA34, float)
#define f_centerx	VAR_U_(0x0055D22C, float)
#define f_centery	VAR_U_(0x0055D230, float)
#define f_a	VAR_U_(0x0051D150, float)
#define f_boo	VAR_U_(0x0055D220, float)
/*************************************************/
#define IsRoomOutsideNo	VAR_U_(0x00EEF902, short)
#define _CutSceneTriggered1	VAR_U_(0x00EEF004, ulong)
#define _CutSceneTriggered2	VAR_U_(0x00EEF000, ulong)
#define richcutfrigflag	VAR_U_(0x0051CA5E, char)
#define number_los_rooms VAR_U_(0x0051CA70, int)
#define LaserSightActive VAR_U_(0x0051D072, char)
#define LaserSightY VAR_U_(0x00E4C9A0, long)
#define LaserSightZ VAR_U_(0x00E4C9A4, long)
#define LaserSightX VAR_U_(0x00E4C9A8, long)
#define LaserSightCol VAR_U_(0x0051D073, char)
#define GetLaraOnLOS VAR_U_(0x0051CA64, char)
#define ClosestDist VAR_U_(0x00EEF4A4, int)
#define ClosestCoord VAR_U_(0x00EEF460, PHD_VECTOR)
#define ClosestItem VAR_U_(0x00EEEFF8, int)
#define nRope VAR_U_(0x0051CA60, int)
#define CurrentPendulum VAR_U_(0x00EEF020, PENDULUM)
#define NullPendulum VAR_U_(0x0051CFD0, PENDULUM)
#define CamPos	VAR_U_(0x00E4B0D0, PHD_VECTOR)
#define bLaraUnderWater	VAR_U_(0x0057A150, int)
#define bLaraSkinBits	VAR_U_(0x0057A458, int)
#define aMappedNormals	VAR_U_(0x0057A45C, LPD3DVECTOR)
#define skinMatrixPtr	VAR_U_(0x00E5B918, long*)
#define bLaraInWater	VAR_U_(0x0057A468, char)
#define SmokeWindZ	VAR_U_(0x00E6C9E4, long)
#define SmokeWindX	VAR_U_(0x00E6C9E0, long)
#define hair_wind	VAR_U_(0x0051CEA4, int)
#define hair_dwind_angle	VAR_U_(0x005084D4, int)
#define hair_wind_angle	VAR_U_(0x005084D0, int)
#define lGlobalMeshPos	VAR_U_(0x0091F3B8, AFRVECTOR)
#define GlobalAmbient	VAR_U_(0x0092167C, long)
#define App	VAR_U_(0x00D9AB38, WINAPP)
#define aAmbientR	VAR_U_(0x0087AD0C, int)
#define aAmbientG	VAR_U_(0x0087AD08, int)
#define aAmbientB	VAR_U_(0x0087AD04, int)
#define textinfo	VAR_U_(0x008751B0, TEXTURESTRUCT*)
#define nTextures	VAR_U_(0x00D9A868, int)
#define GLOBAL_resident_depack_buffers	VAR_U_(0x00E7EFDC, char*)
#define lastcamnum	VAR_U_(0x00E711A8, int)
#define next_fire_spark	VAR_U_(0x0050A17C, int)
#define next_smoke_spark	VAR_U_(0x0051D084, int)
#define next_gunshell	VAR_U_(0x0051D08C, int)
#define next_bubble	VAR_U_(0x0051D090, int)
#define next_drip	VAR_U_(0x0051D094, int)
#define next_debris	VAR_U_(0x0051CA8C, int)
#define WB_room	VAR_U_(0x00EEF044, short)
#define GlobalPulleyFrigItem	VAR_U_(0x00E5BF24, short)
#define globoncuttrig	VAR_U_(0x00EEEFA0, char)
#define HeavyTriggered	VAR_U_(0x00EEEA34, uchar)
#define LastSequence	VAR_U_(0x00E51F2C, short)
#define fliptimer	VAR_U_(0x0051CA68, int)
#define FileData	VAR_U_(0x00874964, char*)
#define textinfo	VAR_U_(0x008751B0, TEXTURESTRUCT*)
#define MaxRoomLights	VAR_U_(0x0087B0EC, int)
#define LevelFogBulbCnt	VAR_U_(0x007E7FE8, int)
#define number_rooms	VAR_U_(0x0087514C, short)
#define cd_drive	VAR_U_(0x00874960, char)
#define SubsuitAir	VAR_U_(0x0051CEE0, short)
#define WB_item VAR_U_(0x00EEEACC, ITEM_INFO*)
#define wbx VAR_U_(0x0051CEBC, short)
#define wbz VAR_U_(0x0051CEBE, short)
#define ItemNewRoomNo	VAR_U_(0x0051CA54, short)
#define cSaveGameSelect	VAR_U_(0x008FBDA0, int)
#define spriteinfo	VAR_U_(0x008751B4, SPRITESTRUCT*)
#define clipflags	VAR_U_(0x00D9AB34, short*)
#define Rats	VAR_U_(0x00EEEFEC, RAT_STRUCT*)
#define Bats	VAR_U_(0x00EEEFE8, BAT_STRUCT*)
#define next_rat	VAR_U_(0x0051CF94, long)
#define next_bat	VAR_U_(0x0051CA18, long)
#define outside	VAR_U_(0x00E6CAF8, long)
#define LightningCount	VAR_U_(0x00E6D74C, short)
#define LightningRand	VAR_U_(0x00E6D73C, short)
#define dLightningRand	VAR_U_(0x00E6E4DC, short)
#define LightningSFXDelay	VAR_U_(0x0051CC5C, short)
#define nPolyType	VAR_U_(0x00E4B100, long)
#define SkyPos	VAR_U_(0x00E6E4B0, short)
#define SkyPos2	VAR_U_(0x00E6D73E, short)
#define torchroom	VAR_U_(0x00507AB0, short)
/***********************/
//Spotcams
#define number_spotcams	VAR_U_(0x00E4F428, short)
#define CameraFade	VAR_U_(0x00E4F36C, long)
#define LastFov	VAR_U_(0x00E4F506, short)
#define spotcam_timer	VAR_U_(0x0051D00C, short)
#define spotcam_loopcnt	VAR_U_(0x00E4F488, short)
#define LaraHealth	VAR_U_(0x00E51F20, long)
#define LaraAir	VAR_U_(0x00E4F6A8, long)
#define InitialCameraPosition	VAR_U_(0x00E4F3D0, PHD_VECTOR)
#define InitialCameraTarget	VAR_U_(0x00E4F350, PHD_VECTOR)
#define LaraFixedPosition	VAR_U_(0x00E4F360, PHD_VECTOR)
#define InitialCameraRoom	VAR_U_(0x00E4F588, short)
#define current_sequence	VAR_U_(0x00E4F502, short)
#define current_spline_camera	VAR_U_(0x00E4F500, short)
#define first_camera	VAR_U_(0x00E51F24, short)
#define last_camera	VAR_U_(0x00E4F6AC, short)
#define current_camera_cnt	VAR_U_(0x00E4EAA0, short)
#define current_spline_position	VAR_U_(0x00E51F28, short)
#define spline_to_camera	VAR_U_(0x00E4F48C, long)
#define spline_from_camera	VAR_U_(0x00E4F3DC, long)
#define bCheckTrigger	VAR_U_(0x0051D014, long)
#define SlowMotion	VAR_U_(0x0051CA50, short)
#define SCOverlay	VAR_U_(0x0051D020, char)
#define SCNoDrawLara	VAR_U_(0x0051D021, char)
#define quakecam	VAR_U_(0x00E4F520, QUAKE_CAM)

#define SpotCam	ARRAY_(0x00E4F6C0, SPOTCAM, [256])
#define CameraCnt	ARRAY_(0x00E51F10, uchar, [16])
#define SpotRemap	ARRAY_(0x00E4F4F0, uchar, [16])
#define camera_xposition	ARRAY_(0x00E4F440, long, [18])
#define camera_yposition	ARRAY_(0x00E4F600, long, [18])
#define camera_zposition	ARRAY_(0x00E4F540, long, [18])
#define camera_xtarget	ARRAY_(0x00E4F3E0, long, [18])
#define camera_ytarget	ARRAY_(0x00E51EC0, long, [18])
#define camera_ztarget	ARRAY_(0x00E4F5A0, long, [18])
#define camera_roll	ARRAY_(0x00E4F4A0, long, [18])
#define camera_fov	ARRAY_(0x00E4F380, long, [18])
#define camera_speed	ARRAY_(0x00E4F660, long, [18])
/***********************/
#define next_spider VAR_U_(0x0051D008, long)
#define Spiders VAR_U_(0x00EEF45C, SPIDER_STRUCT*)
#define NotHitLaraCount VAR_U_(0x0051D0A4, char)
#define nAIObjects	VAR_U_(0x00E5B842, short)
#define AIObjects	VAR_U_(0x00E5B844, AIOBJECT*)
#define gt VAR_U_(0x0051CE70, GUARDIAN_TARGET)

/*title shit*/
#define sound_cut_flag	VAR_U_(0x0051CE58, int)//DoTitle and SoundEffect. flag before and after doing some title cutscene, 
//if 0 + playing cut menu selections dont make a sound. never seems to be the case though!

#define selected_option	VAR_U_(0x005082F0, __int64)

#define menu_to_display	VAR_U_(0x0051CE40, int)//which menu should we be displaying right now??
//0 main menu, del's cutseq selector. 1 level select. 2 the reload menu. 3 the options menu

#define DoFade	VAR_U_(0x00C87BF0, int)// 2 everywhere, 1 in loading screens

#define title_string	ARRAY_(0x0050842C, char, [8])

#define nframes	VAR_U_(0x005082C4, int)

#define selected_level	VAR_U_(0x0051CE50, int)//# (on the list) of the selected level in the level select menu

#define level_select_names	ARRAY_(0x005082C8, char, [40])

#define CreditsDone	VAR_U_(0x00E6D838, uchar)
#define CanLoad	VAR_U_(0x0051CE54, char)
#define JustLoaded	VAR_U_(0x0051D001, char)
/*title shit*/

//arrays
#define cutseq_meshbits	ARRAY_(0x00E7EEA0, ulong, [10])
#define objects	ARRAY_(0x0086CF50, OBJECT_INFO, [460])
#define SmashedMesh	ARRAY_(0x00EEF8C0, MESH_INFO*, [16])
#define SmashedMeshRoom	ARRAY_(0x00EEF480, short, [16])
#define blood	ARRAY_(0x00E4C9C0, BLOOD_STRUCT, [32])
#define RPickups	ARRAY_(0x00E596E0, uchar, [16])
#define AnimatingWaterfalls	ARRAY_(0x00E59720, TEXTURESTRUCT*, [6])
#define AnimatingWaterfallsV	ARRAY_(0x00E59760, float, [6])
#define interpolated_bounds	ARRAY_(0x00E6E4D0, short, [6])
#define LM	ARRAY_(0x00506B94, char, [15])
#define	keymap	ARRAY_(0x0086BB8C, char, [256])
#define gfTakeaways	ARRAY_(0x00E5C290, uchar, [16])
#define gfPickups	ARRAY_(0x00E5C300, uchar, [16])
#define	weapons	ARRAY_(0x005085B0, WEAPON_INFO, [9])
#define	DeadlyBounds	ARRAY_(0x00E6C3C0, long, [6])
#define cutseq_meshswapbits	ARRAY_(0x00E7EEE0, ulong, [10])
#define fmv_to_play	ARRAY_(0x0051CE28, char, [2])
#define gfResidentCut	ARRAY_(0x00E5C278, uchar, [4])
#define	LightningRGB	ARRAY_(0x00E6E4B8, ushort, [3])
#define LightningRGBs	ARRAY_(0x00E6CAF0, ushort, [3])
#define gfMips	ARRAY_(0x00E5C2C0, uchar, [8])
#define inventry_objects_list	ARRAY_(0x00508E38, INVOBJ, [100])
#define itemlist	ARRAY_(0x00E88EA0, ITEM_INFO*, [1024])//what the fucking fuck
#define meshlist	ARRAY_(0x00E872A0, MESH_INFO*, [1024])//what the fucking fuck
#define staticlist	ARRAY_(0x00E89EA0, MESH_INFO*, [1024])//what the fucking fuck
#define	FootPrint	ARRAY_(0x00E5C3E0, FOOTPRINT, [32])
#define	gfLevelNames	ARRAY_(0x00E5C320, uchar, [40])
#define	dynamics	ARRAY_(0x00E6C3E0, DYNAMIC, [64])
#define Slist	ARRAY_(0x00E51FE0, SPHERE, [34])
#define keypadinputs	ARRAY_(0x00E59778, uchar, [4])
#define hairs	ARRAY_(0x00E5C000, HAIR_STRUCT, [2][7])
#define smoke_spark	ARRAY_(0x00E4B940, SMOKE_SPARKS, [32])
#define layout	ARRAY_(0x00516C3C, short, [2][18])
#define conflict	ARRAY_(0x00878C4C, int, [18])
#define reg_class	ARRAY_(0x0057A080, char, [4])
#define flip_stats	ARRAY_(0x00EEF060, int, [255])
#define LaSlot	ARRAY_(0x00E52420, SoundSlot, [32])
#define rings	ARRAY_(0x00E59900, RINGME*, [2])
#define SequenceUsed	ARRAY_(0x00E4EA78, uchar, [6])
#define SequenceResults	ARRAY_(0x00E4EA80, uchar, [3][3][3])
#define Sequences	ARRAY_(0x00E4EA9C, uchar, [3])
#define ClosedDoors	ARRAY_(0x0051CAC0, long, [32])
#define flipmap	ARRAY_(0x00EEEBA0, int, [255])
#define spark	ARRAY_(0x00E5F380, SPARKS, [1024])
#define pickups	ARRAY_(0x00E5BF40, DISPLAYPU, [8])
#define twogun	ARRAY_(0x00EEEB00, TWOGUN_INFO, [4])
#define ammo_object_list	ARRAY_(0x00E598E0, AMMOLIST, [3])
#define current_options	ARRAY_(0x00E598C0, MENUTHANG, [3])
#define actor_pnodes	ARRAY_(0x00E71180, PACKNODE*, [10])
#define temp_rotation_buffer	ARRAY_(0x00E711C0, short, [160])
#define los_rooms ARRAY_(0x00EEEFC0, short, [20])
#define static_objects ARRAY_(0x00874988, STATIC_INFO, [70])
#define RopeList ARRAY_(0x00E54CC0, ROPE_STRUCT, [8])
#define lara_matricesF	ARRAY_(0x00E868E0, float, [180])
#define LaraNodeUnderwater	ARRAY_(0x00E862F0, uchar, [15])
#define lara_matrices	ARRAY_(0x00E86320, MATRIX3D, [15])
#define aScratchNormals	ARRAY_(0x0057A158, D3DVECTOR, [64])
#define duff_item	ARRAY_(0x00E71300, ITEM_INFO, [10])
#define SkinJoints ARRAY_(0x00508CB4, uchar, [14][4])
#define ScratchVertNums ARRAY_(0x00E7F080, char, [40][12])
#define PointsToCalc ARRAY_(0x00E5BAC0, uchar, [26][12])
#define LaraNodeAmbient	ARRAY_(0x0057A460, long, [2])
#define first_hair	ARRAY_(0x00E5BF60, int, [2])
#define aMappedEnvUV	ARRAY_(0x00920E18, ENVUV, [256])
#define aVertexBuffer	ARRAY_(0x007DFFE8, D3DTLVERTEX, [1024])
#define old_status_flags	ARRAY_(0x00E7F000, char, [32])
#define old_status_flags2	ARRAY_(0x00E7F040, ushort, [32])
#define cutseq_resident_addresses	ARRAY_(0x00E7EF20, char*, [47])
#define fire_spark	ARRAY_(0x00E4CE40, FIRE_SPARKS, [20])
#define Gunshells	ARRAY_(0x00E4BEC0, GUNSHELL_STRUCT, [24])
#define Gunflashes	ARRAY_(0x00E4D660, GUNFLASH_STRUCT, [4])
#define debris	ARRAY_(0x00E8CAC0, DEBRIS_STRUCT, [256])
#define splashes	ARRAY_(0x00E6CA00, SPLASH_STRUCT, [4])
#define ripples	ARRAY_(0x00E5C600, RIPPLE_STRUCT, [32])
#define Bubbles	ARRAY_(0x00E4D160, BUBBLE_STRUCT, [40])
#define Drips	ARRAY_(0x00E4D740, DRIP_STRUCT, [32])
#define ShockWaves	ARRAY_(0x00E4C1A0, SHOCKWAVE_STRUCT, [16])
#define ItemNewRooms	ARRAY_(0x00EEF4C0, short, [256][2])
#define SaveGames	ARRAY_(0x0087B828, SAVEGAMES, [15])
#define Lightning	ARRAY_(0x00E4C360, LIGHTNING_STRUCT, [16])
#define GlobalCollisionBounds ARRAY_(0x00EEF910, short, [6])

//defs
#define NO_HEIGHT -32512
#define	NO_ITEM	-1
#define NO_ROOM	255

//unknowns
#define UNK_00E916F0	VAR_U_(0x00E916F0, long)//special 1 control, special 2 init, special 3 init, special 4 init
#define UNK_EffectDistance	VAR_U_(0x00E914E0, short*)//used in a bunch of effect draw functions, seems to hold effect pos - lara pos values.
#define UNK_EffectXY	VAR_U_(0x00E912E0, short*)//has X and Y values for drawing effects???
#define UNK_00E913E0	VAR_U_(0x00E913E0, long*)//?????????????
