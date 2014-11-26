#ifndef MATH_H_
#define MATH_H_

//Fixed Point macros
#define fix7_9				s16
#define fix13_3				s16
#define fix13_3				s16
#define fix23_9				s32


// round functions
#define FIX23_9_ROUNDTOI(n)	((FIX23_9TOI(n)) + (((n) & 0x000001FF) >> 8))

#define F_ROUND(n)		(int)((n) + 0.5f)
//floor and ceil
#define F_FLOOR(n)		(int) ((n)-0.5f)
#define F_CEIL(n)			(int)((n)+0.5f)

//convert a float to fixed point and back
#define FTOFIX7_9(n)		(fix7_9) ((n) * 512.0f+0.5f)
#define FTOFIX13_3(n)		(fix13_3)((n) *   8.0f+0.5f)
#define FTOFIX23_9(n)		(fix23_9)((n) * 512.0f+0.5f)

#define FIX7_9TOF(n)		(float)  ((n) / 512.0f)
#define FIX13_3TOF(n)		(float)  ((n) /   8.0f)
#define FIX23_9TOF(n)		(float)  ((n) / 512.0f)

//convert an int to fixed point and back
#define ITOFIX7_9(n)		(fix7_9) ((n)<<9)
#define ITOFIX13_3(n)		(fix13_3)((n)<<3)
#define ITOFIX23_9(n)		(fix23_9)((n)<<9)

#define FIX7_9TOI(n)		(s16)    ((n)>>9)
#define FIX13_3TOI(n)		(s16)    ((n)>>3)
#define FIX23_9TOI(n)		(s32)    ((n)>>9)

#define FIX23_9TOFIX13_3(n)	(fix7_9)((n)>>6)
#define FIX23_9TOFIX7_9(n)	(fix7_9)(n)
#define FIX7_9TOFIX23_9(n)	(fix23_9)(n)
#define FIX13_3TOFIX7_9(n)	(fix7_9) ((n)<<6)
#define FIX7_9TOFIX13_3(n)	(fix13_3)((n)>>6)

//Return fractional part of fixed
#define FIX7_9_FRAC(n)		((n)&0x01FF)
#define FIX13_3_FRAC(n)		((n)&0x0007)
#define FIX23_9_FRAC(n)		((n)&0x01FF)

//fixed multiplication, what a mess of brackets
//question how do we return an s32 from s16*s16 without forcing a promotion to s32
#define FIX7_9_MULT(a,b)	(fix7_9) ((((s32)(a))*((s32)(b)))>>9)
#define FIX13_3_MULT(a,b)	(fix13_3)((((s32)(a))*((s32)(b)))>>3)
#define FIX23_9_MULT(a,b)	(fix23_9)((((s64)(a))*((s64)(b)))>>9)

//Fixed division
#define FIX7_9_DIV(a,b)		(fix7_9) ((((s32)(a))<<9)/((s32)(b)))
#define FIX13_3_DIV(a,b)	(fix13_3)((((s32)(a))<<3)/((s32)(b)))
#define FIX23_9_DIV(a,b)	(fix23_9)((((s64)(a))<<9)/((s64)(b)))


//==========================================================
static const s16 SINLUT[] = {
   0,    6,   12,   18,   25,   31,   37,   43, //1
  50,   56,   62,   68,   75,   81,   87,   93, //2
  99,  106,  112,  118,  124,  130,  136,  142, //3
 148,  154,  160,  166,  172,  178,  184,  190, //4
 195,  201,  207,  213,  218,  224,  230,  235, //5
 241,  246,  252,  257,  263,  268,  273,  279, //6
 284,  289,  294,  299,  304,  310,  314,  319, //7
 324,  329,  334,  339,  343,  348,  353,  357, //8
 362,  366,  370,  375,  379,  383,  387,  391, //9
 395,  399,  403,  407,  411,  414,  418,  422, //10
 425,  429,  432,  435,  439,  442,  445,  448, //11
 451,  454,  457,  460,  462,  465,  468,  470, //12
 473,  475,  477,  479,  482,  484,  486,  488, //13
 489,  491,  493,  495,  496,  498,  499,  500, //14
 502,  503,  504,  505,  506,  507,  508,  508, //15
 509,  510,  510,  511,  511,  511,  511,  512, //16
 511,  511,  511,  511,  511,  511,  510,  510, //17
 509,  508,  508,  507,  506,  505,  504,  503, //18
 502,  500,  499,  498,  496,  495,  493,  491, //19
 489,  488,  486,  484,  482,  479,  477,  475, //20
 473,  470,  468,  465,  462,  460,  457,  454, //21
 451,  448,  445,  442,  439,  435,  432,  429, //22
 425,  422,  418,  414,  411,  407,  403,  399, //23
 395,  391,  387,  383,  379,  375,  370,  366, //24
 362,  357,  353,  348,  343,  339,  334,  329, //25
 324,  319,  314,  310,  304,  299,  294,  289, //26
 284,  279,  273,  268,  263,  257,  252,  246, //27
 241,  235,  230,  224,  218,  213,  207,  201, //28
 195,  190,  184,  178,  172,  166,  160,  154, //29
 148,  142,  136,  130,  124,  118,  112,  106, //30
  99,   93,   87,   81,   75,   68,   62,   56, //31
  50,   43,   37,   31,   25,   18,   12,    6, //32
   0,   -6,  -12,  -18,  -25,  -31,  -37,  -43, //33
 -50,  -56,  -62,  -68,  -75,  -81,  -87,  -93, //34
 -99, -106, -112, -118, -124, -130, -136, -142, //35
-148, -154, -160, -166, -172, -178, -184, -190, //36
-195, -201, -207, -213, -218, -224, -230, -235, //37
-241, -246, -252, -257, -263, -268, -273, -279, //38
-284, -289, -294, -299, -305, -310, -315, -319, //39
-324, -329, -334, -339, -343, -348, -353, -357, //40
-362, -366, -370, -375, -379, -383, -387, -391, //41
-395, -399, -403, -407, -411, -414, -418, -422, //42
-425, -429, -432, -435, -439, -442, -445, -448, //43
-451, -454, -457, -460, -462, -465, -468, -470, //44
-473, -475, -477, -479, -482, -484, -486, -488, //45
-489, -491, -493, -495, -496, -498, -499, -500, //46
-502, -503, -504, -505, -506, -507, -508, -508, //47
-509, -510, -510, -511, -511, -511, -511, -512, //48
-511, -511, -511, -511, -511, -511, -510, -510, //49
-509, -508, -508, -507, -506, -505, -504, -503, //50
-502, -500, -499, -498, -496, -495, -493, -491, //51
-489, -488, -486, -484, -482, -479, -477, -475, //52
-473, -470, -468, -465, -462, -460, -457, -454, //53
-451, -448, -445, -442, -439, -435, -432, -429, //54
-425, -422, -418, -414, -411, -407, -403, -399, //55
-395, -391, -387, -383, -379, -375, -370, -366, //56
-362, -357, -353, -348, -343, -339, -334, -329, //57
-324, -319, -314, -310, -304, -299, -294, -289, //58
-284, -279, -273, -268, -263, -257, -252, -246, //59
-241, -235, -230, -224, -218, -213, -207, -201, //60
-195, -190, -184, -178, -172, -166, -160, -154, //61
-148, -142, -136, -130, -124, -118, -112, -106, //62
 -99,  -93,  -87,  -81,  -75,  -68,  -62,  -56, //63
 -50,  -43,  -37,  -31,  -25,  -18,  -12,   -6 };//64



#define COS(x) SINLUT[((x)+128)&0x1FF]
#define SIN(x) SINLUT[(x)&0x1FF]

#define COSF(x) FIX7_9TOF(SINLUT[((x)+128)&0x1FF])
#define SINF(x) FIX7_9TOF(SINLUT[(x)&0x1FF])

float squareRootFloat(float number);
//
#endif //MATH_H