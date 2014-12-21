char AVGN_name[] = "AVGN";
float AVGN_speedFactor = 1.0;
u16 AVGN_barLength = 0;

//Vocals
u16 AVGN_noteCount1 = 437;
u8 AVGN_channel1Active = 1;
u16 AVGN_channel1[] = {PAU, F_3, F_3, PAU, F_3, C_4, C_4, C_4, C_4, AS3, AS3, C_4, GS3, PAU, F_3, C_4, C_4, C_4, C_4, AS3, AS3, C_4, GS3, GS3, C_4, GS3, GS3, PAU, GS3, C_4, CS4, AS3, PAU, C_4, CS4, DS4, DS4, DS4, DS4, DS4, CS4, C_4, GS3, PAU, GS3, C_4, GS3, GS3, PAU, GS3, C_4, CS4, AS3, AS3, PAU, AS3, AS3, C_4, CS4, DS4, PAU, DS4, DS4, CS4, C_4, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, C_4, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, AS3, AS3, AS3, AS3, GS3, PAU, C_4, C_4, C_4, AS3, AS3, C_4, GS3, PAU, GS3, C_4, C_4, C_4, C_4, PAU, AS3, GS3, DS4, PAU, GS3, GS3, GS3, C_4, GS3, GS3, PAU, GS3, GS3, C_4, CS4, AS3, PAU, C_4, C_4, CS4, DS4, DS4, DS4, DS4, DS4, DS4, CS4, C_4, GS3, PAU, GS3, GS3, GS3, C_4, GS3, GS3, PAU, GS3, GS3, C_4, CS4, AS3, PAU, C_4, C_4, CS4, DS4, DS4, DS4, DS4, DS4, CS4, C_4, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, C_4, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, AS3, AS3, AS3, AS3, GS3, PAU, AS3, AS3, AS3, AS3, CS4, CS4, CS4, CS4, PAU, C_4, C_4, C_4, C_4, C_4, C_4, DS4, DS4, DS4, DS4, DS4, CS4, C_4, AS3, PAU, AS3, AS3, AS3, AS3, CS4, CS4, GS3, CS4, PAU, G_3, G_3, C_4, G_3, C_4, G_3, PAU, C_4, G_3, C_4, G_3, C_4, G_3, CS4, G_3, PAU, F_3, C_4, C_4, C_4, C_4, AS3, AS3, C_4, GS3, PAU, F_3, C_4, C_4, C_4, AS3, AS3, AS3, C_4, GS3, GS3, GS3, GS3, C_4, GS3, GS3, PAU, GS3, GS3, AS3, C_4, CS4, AS3, PAU, C_4, C_4, CS4, DS4, PAU, DS4, DS4, DS4, DS4, CS4, C_4, GS3, PAU, GS3, GS3, GS3, GS3, C_4, GS3, GS3, PAU, GS3, GS3, GS3, C_4, CS4, AS3, PAU, C_4, C_4, CS4, DS4, PAU, DS4, PAU, DS4, CS4, C_4, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, AS3, C_4, GS3, GS3, PAU, GS3, GS3, C_4, C_4, C_4, C_4, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, C_4, C_4, AS3, AS3, C_4, GS3, GS3, PAU, GS3, AS3, C_4, C_4, C_4, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, AS3, GS3, PAU, GS3, AS3, C_4, C_4, AS3, AS3, AS3, AS3, GS3, PAU, };
//289920
u16 AVGN_timing1[] = {240, 240, 240, 720, 480, 480, 480, 480, 480, 480, 480, 480, 960, 2880, 480, 480, 480, 480, 480, 480, 480, 480, 960, 480, 720, 240, 1440, 960, 480, 720, 240, 1920, 960, 480, 480, 480, 480, 480, 480, 480, 480, 480, 1920, 960, 480, 720, 240, 1440, 960, 480, 720, 240, 480, 1440, 480, 240, 240, 480, 480, 480, 480, 960, 480, 480, 480, 1920, 1440, 480, 480, 480, 480, 480, 480, 480, 480, 360, 120, 1920, 1440, 480, 480, 480, 960, 480, 960, 480, 1920, 1440, 480, 480, 480, 960, 480, 480, 480, 360, 120, 1920, 1440, 480, 480, 480, 1440, 240, 240, 480, 960, 2880, 3360, 480, 480, 480, 480, 480, 480, 960, 2880, 480, 480, 480, 480, 480, 480, 480, 480, 480, 240, 240, 240, 240, 720, 240, 960, 1440, 240, 240, 480, 480, 960, 1440, 480, 480, 480, 480, 480, 240, 240, 480, 480, 480, 480, 960, 1680, 240, 240, 240, 480, 480, 960, 1440, 240, 240, 480, 480, 960, 1440, 480, 480, 480, 480, 480, 480, 480, 720, 720, 480, 960, 1920, 480, 480, 480, 480, 480, 480, 480, 480, 360, 120, 1920, 1440, 480, 480, 480, 960, 480, 960, 480, 1920, 1440, 480, 480, 480, 960, 480, 480, 480, 360, 120, 1920, 1440, 480, 480, 480, 1440, 240, 240, 480, 960, 2880, 2400, 480, 720, 240, 960, 480, 480, 480, 960, 3360, 240, 240, 240, 240, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 1440, 480, 480, 480, 480, 960, 480, 480, 480, 2880, 480, 480, 240, 480, 240, 480, 2160, 240, 480, 240, 480, 240, 480, 480, 480, 4320, 480, 480, 480, 480, 480, 480, 480, 480, 960, 2880, 480, 480, 960, 480, 240, 480, 240, 480, 960, 480, 480, 240, 240, 480, 960, 960, 480, 480, 480, 480, 240, 960, 720, 480, 480, 480, 480, 480, 480, 240, 240, 480, 480, 480, 480, 2400, 480, 240, 240, 480, 480, 240, 960, 720, 480, 480, 480, 480, 240, 960, 720, 480, 480, 480, 1080, 120, 1200, 120, 600, 720, 1440, 2880, 2400, 480, 480, 480, 480, 480, 480, 480, 480, 360, 120, 1920, 1440, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 1920, 960, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 1440, 1440, 480, 480, 960, 480, 480, 240, 480, 240, 480, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 480, 480, 720, 1920, 960, 480, 480, 960, 1920, 240, 240, 240, 3120, 4800, 0, };
u8 AVGN_volume1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
s8 AVGN_replayC1 = 0;
u8 AVGN_insturment1 = 0;

// Unused Channel
u16 AVGN_noteCount2 = 0;
u8 AVGN_channel2Active = 0;
u16 AVGN_channel2[] = {PAU};
u16 AVGN_timing2[] = {0};
u8 AVGN_volume2[] = {0};
s8 AVGN_replayC2 = 0;
u8 AVGN_insturment2 = 0;

// Unused Channel
u16 AVGN_noteCount3 = 0;
u8 AVGN_channel3Active = 0;
u16 AVGN_channel3[] = {PAU};
u16 AVGN_timing3[] = {0};
u8 AVGN_volume3[] = {0};
s8 AVGN_replayC3 = 0;
u8 AVGN_insturment3 = 0;

// Unused Channel
u16 AVGN_noteCount4 = 0;
u8 AVGN_channel4Active = 0;
u16 AVGN_channel4[] = {PAU};
u16 AVGN_timing4[] = {0};
u8 AVGN_volume4[] = {0};
s8 AVGN_replayC4 = 0;
u8 AVGN_insturment4 = 0;

// Unused Channel
u16 AVGN_noteCount5 = 0;
u8 AVGN_channel5Active = 0;
u16 AVGN_channel5[] = {PAU};
u16 AVGN_timing5[] = {0};
u8 AVGN_volume5[] = {0};
s8 AVGN_replayC5 = 0;
u8 AVGN_insturment5 = 0;



/*
#include "../music/AVGN.h"

ml_music_n[i] = AVGN_name;
ml_music_sf[i] = AVGN_speedFactor;
//ml_music_bl[i] = AVGN_barLength;
ml_music_c1[i] = AVGN_channel1;
ml_music_ca1[i] = AVGN_channel1Active;
ml_music_nc1[i] = AVGN_noteCount1;
ml_music_t1[i] = AVGN_timing1;
ml_music_v1[i] = AVGN_volume1;
ml_music_r1[i] = AVGN_replayC1;
ml_music_in1[i] = AVGN_insturment1;
ml_music_c2[i] = AVGN_channel2;
ml_music_ca2[i] = AVGN_channel2Active;
ml_music_nc2[i] = AVGN_noteCount2;
ml_music_t2[i] = AVGN_timing2;
ml_music_v2[i] = AVGN_volume2;
ml_music_r2[i] = AVGN_replayC2;
ml_music_in2[i] = AVGN_insturment2;
ml_music_c3[i] = AVGN_channel3;
ml_music_ca3[i] = AVGN_channel3Active;
ml_music_nc3[i] = AVGN_noteCount3;
ml_music_t3[i] = AVGN_timing3;
ml_music_v3[i] = AVGN_volume3;
ml_music_r3[i] = AVGN_replayC3;
ml_music_in3[i] = AVGN_insturment3;
ml_music_c4[i] = AVGN_channel4;
ml_music_ca4[i] = AVGN_channel4Active;
ml_music_nc4[i] = AVGN_noteCount4;
ml_music_t4[i] = AVGN_timing4;
ml_music_v4[i] = AVGN_volume4;
ml_music_r4[i] = AVGN_replayC4;
ml_music_in4[i] = AVGN_insturment4;
ml_music_c5[i] = AVGN_channel5;
ml_music_ca5[i] = AVGN_channel5Active;
ml_music_nc5[i] = AVGN_noteCount5;
ml_music_t5[i] = AVGN_timing5;
ml_music_v5[i] = AVGN_volume5;
ml_music_r5[i] = AVGN_replayC5;
ml_music_in5[i] = AVGN_insturment5;
i++;
*/
