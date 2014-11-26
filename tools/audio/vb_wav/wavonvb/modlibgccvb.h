// DogP's gccVB header

#ifndef _LIBGCCVB_H_
#define _LIBGCCVB_H_

// Easier to type/remember...
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char BYTE;
typedef unsigned short HWORD;
typedef unsigned long WORD;

volatile HWORD* const VIP_REGS =		(HWORD*)0x0005F800;
HWORD* const BGMM =		(HWORD*)0x00020000;
HWORD* const WAM =		(HWORD*)0x0003D800;
HWORD* const COLUMN_TABLE =	(HWORD*)0x0003DC00;
HWORD* const OAM =		(HWORD*)0x0003E000;

/****** VIP Register Mnemonics ******/
#define INTPND	0x00
#define INTENB	0x01
#define INTCLR	0x02

#define DPSTTS	0x10
#define DPCTRL	0x11
#define BRTA	0x12
#define BRTB	0x13
#define BRTC	0x14
#define REST	0x15

#define FRMCYC	0x17
#define CTA	0x18

#define XPSTTS	0x20
#define XPCTRL	0x21
#define VER	0x22

#define SPT0	0x24
#define SPT1	0x25
#define SPT2	0x26
#define SPT3	0x27

#define GPLT0	0x30
#define GPLT1	0x31
#define GPLT2	0x32
#define GPLT3	0x33

#define JPLT0	0x34
#define JPLT1	0x35
#define JPLT2	0x36
#define JPLT3	0x37

#define BKCOL	0x38

typedef struct SOUNDREG
{
	//this table is for the most part untested, but looks to be accurate
	//                 |      D7      ||      D6      ||      D5      ||      D4      ||      D3      ||      D2      ||      D1      ||      D0      |
	u8 SxINT; //       [----Enable----][--XXXXXXXXXX--][-Interval/??--][--------------------------------Interval Data---------------------------------]
	u8 spacer1[3];
	u8 SxLRV; //       [---------------------------L Level----------------------------][---------------------------R Level----------------------------]
	u8 spacer2[3];
	u8 SxFQL; //       [------------------------------------------------------Frequency Low Byte------------------------------------------------------]
	u8 spacer3[3];
	u8 SxFQH; //       [--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--------------Frequency High Byte-------------]
	u8 spacer4[3];
	u8 SxEV0; //       [---------------------Initial Envelope Value-------------------][------U/D-----][-----------------Envelope Step----------------]
	u8 spacer5[3];
		 //Ch. 1-4 [--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][------R/S-----][----On/Off----]
	         //Ch. 5   [--XXXXXXXXXX--][------E/D-----][----?/Short---][--Mod./Sweep--][--XXXXXXXXXX--][--XXXXXXXXXX--][------R/S-----][----On/Off----]
	u8 SxEV1; //Ch. 6  [--XXXXXXXXXX--][----------------------E/D---------------------][--XXXXXXXXXX--][--XXXXXXXXXX--][------R/S-----][----On/Off----]
	u8 spacer6[3];
	//Ch. 1-5 only (I believe address is only 3 bits, but may be 4, needs testing)
	u8 SxRAM; //       [--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--XXXXXXXXXX--][--------------Waveform RAM Address------------]
	u8 spacer7[3];
	//Ch. 5 only
	u8 S5SWP; //       [------CLK-----][-------------Sweep/Modulation Time------------][------U/D-----][----------------Number of Shifts--------------]
	u8 spacer8[35];
} SOUNDREG;

//wave data number does not necessarily correspond to channel number(value set in Waveform RAM Address in soundreg)
u8* const WAVEDATA1 =		(u8*)0x01000000;
u8* const WAVEDATA2 =		(u8*)0x01000080;
u8* const WAVEDATA3 =		(u8*)0x01000100;
u8* const WAVEDATA4 =		(u8*)0x01000180;
u8* const WAVEDATA5 =		(u8*)0x01000200;
u8* const MODDATA =		(u8*)0x01000280;
SOUNDREG* const SND_REGS =	(SOUNDREG*)0x01000400;
#define SSTOP			*(u8*)0x01000580 //Sound Stop: 0x01 = Stop (all other bits ignored)

/***** Sound Register Mnemonics *****/
#define	WAVE1	0x00	// Voluntary wave channel #1
#define	WAVE2	0x01	// Voluntary wave channel #2
#define	WAVE3	0x02	// Voluntary wave channel #3
#define	WAVE4	0x03	// Voluntary wave channel #4
#define	SWEEP	0x04	// Sweep/modulation channel
#define	NOISE	0x05	// Pseudorandom noise channel

volatile BYTE* HW_REGS = (BYTE*)0x02000000;
/***** Hardware Register Mnemonics *****/
#define	CCR	0x00	// Link Port Control 1
#define	CCSR	0x04	// Link Port Control 2
#define	CDTR	0x08	// Link Port Transmit
#define	CDRR	0x0C	// Link Port Receive
#define	SDLR	0x10	// Keypad Low Byte
#define	SDHR	0x14	// Keypad High Byte
#define	TLR	0x18	// Timer Low Byte
#define	THR	0x1C	// Timer High Byte
#define	TCR	0x20	// Timer Control Register
#define	WCR	0x24	// Wait-state Control Register
#define	SCR	0x28	// Keypad (controller) Control Register

#define ROM1W 0x01 // ROM Area 1 Wait State
#define EXP1W 0x02 // Expansion Area 1 Wait State

/***** Handy Video RAM Locations *****/
#define	CharSeg0	0x6000
#define	CharSeg1	0xE000
#define	CharSeg2	0x16000
#define	CharSeg3	0x1E000
#define BGMMBase	0x20000
#define BGMap(x)	(BGMMBase+(0x2000*x))
#define World(x)	(0x3D800+(x*0x20))
#define	ObjectSeg	0x3E000
#define	Object(x)	(0x3E000+(8*x))

/***** Interrupt Functions *****/
/*void key_vector(void){}   // Controller Interrupt Handler
void tim_vector(void){}   // Timer Interrupt Handler
void cro_vector(void){}   // Expantion Port Interupt Handler
void com_vector(void){}   // Link Port Interrupt Handler
void vpu_vector(void){}   // Video Retrace Interrupt Handler*/

/***** World Functions *****/
void vbSetWorld (int nw, HWORD header, HWORD gx, HWORD gp, HWORD gy, HWORD mx, HWORD mp, HWORD my, HWORD width, HWORD height) {
	HWORD tmp = (nw<<5)>>1;

	WAM[tmp++] = header;
	WAM[tmp++] = gx;
	WAM[tmp++] = gp;
	WAM[tmp++] = gy;
	WAM[tmp++] = mx;
	WAM[tmp++] = mp;
	WAM[tmp++] = my;
	WAM[tmp++] = width;
	WAM[tmp] = height;
}

/* Macros for world manipulation */
#define WORLD_HEAD(n,head)		WAM[((n << 5) >> 1)    ] = head;
#define WORLD_GSET(n,gx,gp,gy)	WAM[((n << 5) >> 1) + 1] = gx; WAM[((n << 5) >> 1) + 2] = gp; WAM[((n << 5) >> 1) + 3] = gy;
#define WORLD_MSET(n,mx,mp,my)	WAM[((n << 5) >> 1) + 4] = mx; WAM[((n << 5) >> 1) + 5] = mp;	WAM[((n << 5) >> 1) + 6] = my;
#define WORLD_SIZE(n,w,h)		WAM[((n << 5) >> 1) + 7] = w; WAM[((n << 5) >> 1) + 8] = h;
#define WORLD_PARAM(n,p)		WAM[((n << 5) >> 1) + 9] = (p << 4);

/* "vbSetWorld" header flags */
/* (OR these together to build a World Header) */

typedef struct WORLD {
	u16 head;
	u16 gx;
	s16 gp;
	u16 gy;
	u16 mx;
	s16 mp;
	u16 my;
	u16 w;
	u16 h;
	u16 param;
	u16 ovr;
	u16 spacer[5];
} WORLD;

WORLD* const WA = (WORLD*)0x0003D800;

#define	WRLD_ON		0xC000
#define	WRLD_LON	0x8000
#define	WRLD_RON	0x4000
#define	WRLD_OBJ	0x3000
#define	WRLD_AFFINE	0x2000
#define	WRLD_HBIAS	0x1000
#define	WRLD_BGMAP	0x0000

#define	WRLD_1x1	0x0000
#define	WRLD_1x2	0x0100
#define	WRLD_1x4	0x0200
#define	WRLD_1x8	0x0300
#define	WRLD_2x1	0x0400
#define	WRLD_2x2	0x0500
#define	WRLD_2x4	0x0600
#define	WRLD_4x2	0x0900
#define	WRLD_4x1	0x0800
#define	WRLD_8x1	0x0C00

#define	WRLD_OVR	0x0080
#define	WRLD_END	0x0040


/***** Object (sprite) Functions *****/

void vbSetObject (HWORD n, BYTE header, HWORD x, HWORD p, HWORD y, HWORD chr)
{
	HWORD temp1, temp2, signbit;

	signbit=(p & 0x8000) >> 2;

	temp1 = (header & 0xC0) << 8;
	temp2 = (p & 0xFF) | signbit | temp1;

	temp1 = ((header & 0x3C) << 10) | (chr & 0x7FF);

	OAM[n<<2] = x;
	OAM[(n<<2)+1] = temp2;
	OAM[(n<<2)+2] = y;
	OAM[(n<<2)+3] = temp1;
}

/*** (Obsoleted by vbSetObject and the OBJ_* macros...)
void vbObjectMove (int num, int x, int y, int p)
{
	HWORD rmw;

	OAM[(n << 2)] = x;

	rmw = OAM[(n << 2) + 1] & 0xC000;
	OAM[(n << 2) + 1] = rmw | p;

	OAM[(n << 2) + 2] = y;
}
***/

#define OBJ_XSET(n,x)	OAM[n << 2] = x;
#define OBJ_YSET(n,y)	OAM[(n << 2) + 2] = y;
#define OBJ_PSET(n,p)	OAM[(n << 2) + 1] = (OAM[(n << 2) + 1] & 0xC000) | p;
#define OBJ_CSET(n,c)	OAM[(n << 2) + 3] = (OAM[(n << 2) + 3] & 0xF000) | (HWORD)c;
#define OBJ_HSET(n,h)	OAM[(n << 2) + 3] = (OAM[(n << 2) + 3] & 0xDFFF) | (((HWORD)h << 13) & 0x2000);
#define OBJ_VSET(n,v)	OAM[(n << 2) + 3] = (OAM[(n << 2) + 3] & 0xEFFF) | (((HWORD)h << 12) & 0x1000);
// #define OBJ_PALSET(n,pal)
// #define OBJ_VIS(n,v)

/* "vbSetObject" header flags */
/* (OR these together to build an Object Header) */
#define	OBJ_ON		0x00C0
#define	OBJ_LON		0x0080
#define	OBJ_RON		0x0040

#define	OBJ_PAL0	0x0000
#define	OBJ_PAL1	0x0010
#define	OBJ_PAL2	0x0020
#define	OBJ_PAL3	0x0030

#define	OBJ_HFLIP	0x0008
#define	OBJ_VFLIP	0x0004

/* Keypad Definitions */
#define K_ANY	0xFFFC		/* All keys - bat/sgn			*/
#define K_BTNS	0x303C		/* All buttons; no d-pads		*/
#define K_PAD	0xCFC0		/* All d-pad dirs				*/
#define K_PWR	0x0001		/* Low Battery					*/
#define K_SGN	0x0002		/* Signature; 1 = Standard Pad	*/
#define K_A	0x0004		/* A Button						*/
#define K_B	0x0008		/* B Button						*/
#define K_RT	0x0010		/* R Trigger					*/
#define K_LT	0x0020		/* L Trigger					*/
#define K_RU	0x0040		/* Right Pad, Up				*/
#define K_RR	0x0080		/* Right Pad, Right				*/
#define K_LR	0x0100		/* Left Pad,  Right				*/
#define K_LL	0x0200		/* Left Pad,  Left				*/
#define K_LD	0x0400		/* Left Pad,  Down				*/
#define K_LU	0x0800		/* Left Pad,  Up				*/
#define K_STA	0x1000		/* Start Button					*/
#define K_SEL	0x2000		/* Select Button				*/
#define K_RL	0x4000		/* Right Pad, Left				*/
#define K_RD	0x8000		/* Right Pad, Down				*/

/*                NEW STUFF FROM VUCC                */
/*	World attribute */
#define	WA_Ctl		0x0000 	/* World attribute control data */
#define	WA_GX		0x0002 	/* BG Destination X*/
#define	WA_GP		0x0004 	/* BG Destination Paralax*/
#define	WA_GY		0x0006 	/* BG Destination Y*/
#define	WA_MX		0x0008 	/* BG Source X*/
#define	WA_MP		0x000a 	/* BG Source Paralax*/
#define	WA_MY		0x000c 	/* BG Source Y*/
#define	WA_W		0x000e 	/* Window Width*/
#define	WA_H		0x0010 	/* Window Hight*/
#define	WA_PB		0x0012 	/* Param_Base*/
#define	WA_OC		0x0014 	/* OverPlane_Character*/
#define	WA_Size		0x0020 	/* Size*/
#define	WRLD_OFF	0xBFFE
#define	WRLD_LOFF	0x7FFF
#define	WRLD_ROFF	0x3FFF
/*	Object attribute */
#define	JX		0 	/* Display pointer X*/
#define	JP		2 	/* Paralax*/
#define	JY		4 	/* Display pointer Y*/
#define	JCA		6 	/* Character No.*/
#define	JLON		0x8000 	/* */
#define	JRON		0x4000 	/* */
#define	SCX1		0x0000 	/* 1 Segment */
#define	SCX2		0x0400 	/* 2 Segment */
#define	SCX3		0x0800 	/* 3 Segment */
#define	SCX4		0x0c00 	/* 4 Segment */
#define	SCY1		0x0000 	/* 1 Segment */
#define	SCY2		0x0100 	/* 2 Segment */
#define	SCY3		0x0200 	/* 3 Segment */
#define	SCY4		0x0300 	/* 4 Segment */
#define	OVEROFF		0x0000 	/* Over Plane off（It designates around BG as the repeat character）*/
/*	The control which is the rear end */
#define	K_Int_Dis	0x80 	/* It clears the key-in interruption and interrupts and makes ディスイネーブル */
#define	K_Int_Enb	0x00 
#define	ParaS		0x20 	/* When doing software loading, the ぱ and others rear end signal is generated */
#define	ParaH		0x00 
#define	Soft_CK		0x10 	/* When doing software loading, when,1 is written, the transfer く ろ っ く is generated.  */
#define	HW_SI		0x04 	/* The key loading by the hardware starts. */
#define	SI_Stat		0x02 	/* It is while 1 the key loading by the hardware.  */
#define	S_Dis		0x01	/* Hardware loading suspension/inhibitation */
#define	S_Abt		0x00 	/* Hardware loading authorization */
#define	WORLD_ATT31	0x3dbe0
#define	CHR_RAM		0x78000 /* Character RAM */
/*	Indicatory control register flag (DPSTTS,DPCTRL) */
#define	LOCK		0x0400 			/* VPU SELECT CTA */
#define	LOCKOFF		LOCK^0xffff 
#define	SYNCE		0x0200 			/* L,R_SYNC TO VPU */
#define	SYNCEOFF	SYNCE^0xffff 
#define	RE		0x0100 			/* MEMORY REFLASH CYCLE ON */
#define	REOFF		RE^0xffff 
#define	DISP		0x0002 			/* DISPLAY ON */
#define	DISPOFF		DISP^0xffff 
#define	DPRST		0x0001 			/* RESET VPU COUNTER AND WAIT FCLK */
#define	DPRSTOFF	DPRST^0xffff 
#define	FCLK		0x0080 			
#define	SCANRDY		0x0040 
/*	Register for interrupt control	*/
#define	TIMEERR		0x8000
#define	XPEND		0x4000
#define	SBHIT		0x2000 
#define	FRAMESTART	0x0010
#define	GAMESTART	0x0008
#define	RFBEND		0x0004
#define	LFBEND		0x0002
#define	SCANERR		0x0001
/*	Register for drawing control */
#define	XPEN		0x0002 	/* Start of drawing */
#define	XPENOFF		XPEN^0xffff 
#define	XPRST		0x0001 	/* Forcing idling */
#define	XPRSTOFF	XPRST^0xFFFF 
#define	SBOUT		0x8000 	/* In FrameBuffer drawing included */
#define	OVERTIME	0x0010 	/* Processing */
#define	XPBSYI		0x0000 	/* Idling */
#define	XPBSY0		0x0004 	/* In the midst of FrameBuffer0 picture editing */
#define	XPBSY1		0x0008 	/* In the midst of FrameBuffer1 picture editing */
#define	XPBSYR		0x000C 	/* In the midst of drawing processing reset */
/*                END NEW STUFF FROM VUCC                */

/* Reads the keypad, returns the result in a HWORD */
HWORD vbReadPad (void) {
	HW_REGS[SCR] = 0x84;
	while(HW_REGS[SCR] & 2);
	return (HW_REGS[SDHR] << 8) | HW_REGS[SDLR];
}

/* Turn the display on */
void vbDisplayOn () {
	VIP_REGS[REST] = 0;
	VIP_REGS[XPCTRL] = VIP_REGS[XPSTTS] | XPEN;
	VIP_REGS[DPCTRL] = VIP_REGS[DPSTTS] | SYNCE|RE|DISP;
	VIP_REGS[FRMCYC] = 0;
	VIP_REGS[INTCLR] = VIP_REGS[INTPND];
	while (!(VIP_REGS[DPSTTS] & 0x3C));  //required?

	VIP_REGS[BRTA]  = 0;
	VIP_REGS[BRTB]  = 0;
	VIP_REGS[BRTC]  = 0;
	VIP_REGS[GPLT0] = 0x00e4;
	VIP_REGS[GPLT1] = 0x009c;
	VIP_REGS[GPLT2] = 0x0078;
	VIP_REGS[GPLT3] = 0x00d8;
	VIP_REGS[JPLT0] = 0x00e0;
	VIP_REGS[JPLT1] = 0x009c;
	VIP_REGS[JPLT2] = 0x0078;
	VIP_REGS[JPLT3] = 0x00d8;
	VIP_REGS[BKCOL] = 0;	/* Clear the screen to black before rendering */
}

static BYTE colTable[128] = {
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xe0, 0xbc,
	0xa6, 0x96, 0x8a, 0x82, 0x7a, 0x74, 0x6e, 0x6a,
	0x66, 0x62, 0x60, 0x5c, 0x5a, 0x58, 0x56, 0x54,
	0x52, 0x50, 0x50, 0x4e, 0x4c, 0x4c, 0x4a, 0x4a,
	0x48, 0x48, 0x46, 0x46, 0x46, 0x44, 0x44, 0x44,
	0x42, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3c,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c
};

/* Setup the default Column Table */
void vbSetColTable(void) {
	int i;

	for (i = 0; i < 128; i++) {
		COLUMN_TABLE[i] = colTable[i];
		COLUMN_TABLE[i + 0x0080] = colTable[127 - i];
		COLUMN_TABLE[i + 0x0100] = colTable[i];
		COLUMN_TABLE[i + 0x0180] = colTable[127 - i];
	}
}

/* Call this after the display is on and you want the image to show up */
void vbDisplayShow (void) {
	VIP_REGS[BRTA]  = 32;
	VIP_REGS[BRTB]  = 64;
	VIP_REGS[BRTC]  = 32;
}

/* Call this to hide the image; e.g. while setting things up */
void vbDisplayHide (void) {
	VIP_REGS[BRTA]  = 0;
	VIP_REGS[BRTB]  = 0;
	VIP_REGS[BRTC]  = 0;
}

/* Delay execution - OLD WAITFRAME */
/*void vbWaitFrame (int count) {
	int i = 0,
		tmp;

	for (i = 0; i <= count; i++) {
		tmp = VIP_REGS[XPSTTS];
		while (tmp == VIP_REGS[XPSTTS]);
	}
}*/

/* Delay execution */
/*void vbWaitFrame(u16 count) {
	u16 i,tmp;
	for (i = 0; i <= count; i++) {
	while (!(VIP_REGS[XPSTTS] & XPBSYR));
	while (VIP_REGS[XPSTTS] & XPBSYR);
	}
}*/

void vbWaitFrame(u32 count) {
	volatile u32 i;
	for (i = 0; i <= 1000*count; i++);
}

#if 0
void vbWaitFrame(int count) {

	asm("
	jr	3f
	1:
	movea	0xB2F,r0,r10
	add	-1,%0 /* decrement counter remaining to 0 */
	2:
	add	-1,r10 /* decrement inner loop to 0 */
	cmp	0,r10
	bgt	2b
	3:
	cmp	0,%0 /* compare num with 0 to tell when done */
	bgt	1b /* loop if count remaining is greater than 0 */
	"
	: /* No Output */
	: "r" (count) /* Input */
	: "r10" /* No regs used */
	);

}
#endif

void vbFXFadeIn (int wait) {
	volatile int i;

	for (i = 0; i <= 32; i++) {
		vbWaitFrame(wait);
		VIP_REGS[BRTA] = i;
		VIP_REGS[BRTB] = i*2;
		VIP_REGS[BRTC] = i;
	}
}

void vbFXFadeOut (int wait) {
	int i;

	for (i = 32; i >= 0; i--) {
		vbWaitFrame(wait);
		VIP_REGS[BRTA] = i;
		VIP_REGS[BRTB] = i*2;
		VIP_REGS[BRTC] = i;
	}
}

/* Macro to set the brightness for the colors */
#define SET_BRIGHT(a,b,c)       VIP_REGS[BRTA]=a; VIP_REGS[BRTB]=b; VIP_REGS[BRTC]=c;

/* Macro to set the GPLT (BGMap palette) */
#define SET_GPLT(n,pal)         VIP_REGS[GPLT0+n]=pal;

/* Macro to set the JPLT (OBJ palette) */
#define SET_JPLT(n,pal)         VIP_REGS[JPLT0+n]=pal;

u32* const   L_FRAME0 =   (u32*)0x00000000;                // L FrameBuff0
u32* const   L_FRAME1 =   (u32*)0x00008000;                // L FrameBuff1
u32* const   R_FRAME0 =   (u32*)0x00010000;                // R FrameBuff0
u32* const   R_FRAME1 =   (u32*)0x00018000;                // R FrameBuff1

u8* const   SAVERAM =   (u8*)0x06000000;                // Cartridge's Battery-backed SRAM

/***** Ancillary Functions *****/

// Copy a block of data from one area in memory to another.
void copymem (BYTE* dest, const BYTE* src, int num) {
	int i;
	for (i = 0; i < num; i++) dest[i] = src[i];
}

void copyword (WORD* dest, const WORD* src, int num) {
	int i;
	for (i = 0; i < num; i++) dest[i] = src[i];
}

// Set each byte in a block of data to a given value.
void setmem (BYTE* dest, BYTE src, int num) {
	int i;
	for (i = 0; i < num; i++) dest[i] = src;
}

void sethword (HWORD* dest, HWORD src, int num) {
	int i;
	for (i = 0; i < num; i++) dest[i] = src;
}

//Copy a block of data from one area in memory to another, adding a given value to each byte, first.
void addmem(BYTE* dest, const BYTE* src, int num, BYTE offset) {
 	int i;
	for (i = 0; i < num; i++) dest[i] = (src[i] + offset);
}

void vbTextOut (int bgmap, int col, int row, char t_string[])
/* The font must reside in Character segment 3 */
{
	int i = 0;
	int pos = row * 64 + col;
	while(t_string[i])
	{
		BGMM[(0x1000 * bgmap) + pos + i] = (HWORD)t_string[i] - 32 + 0x600;
		i++;
	}
}

void buffvln(int xcoord, int ycoord, int length, int shade, int parallax)
// Draws a vertical line in the L/R Display Buffers
{
	int pos;
	int prevpos = 0;
	int shift = (ycoord & 0x0F);
	int offset = ((xcoord << 4) + (ycoord >> 4));
	int data = 0;
	parallax <<= 4;

	for (pos = 0; pos <= length; pos++)
	{
		data |= (shade << (shift << 1));
		shift++;
		if ((shift & 0x0F) == 0)
		{
			L_FRAME0[(offset + (pos >> 4) - parallax)] |= data;
			R_FRAME0[(offset + (pos >> 4) + parallax)] |= data;
			prevpos = (pos + 16);
			shift = 0;
			data = 0;
		}
	}
	if (shift != 0)
	{
		L_FRAME0[(offset + (prevpos >> 4) - parallax)] |= data;
		R_FRAME0[(offset + (prevpos >> 4) + parallax)] |= data;
	}
}

void buffhln(int xcoord, int ycoord, int length, int shade, int parallax)
// Draws a horizontal line in the L/R Display Buffers
{
	int pos;
	int offset = ((xcoord << 4) + (ycoord >> 4));
	int data;
	
	for (pos = 0; pos <= (ycoord & 0x0F); pos++)
		data = (shade << (pos << 1));
	for (pos = 0; pos <= length; pos++)
	{
		L_FRAME0[((pos - parallax) << 4) + offset] |= data;
		R_FRAME0[((pos + parallax) << 4) + offset] |= data;
	}
}

void buffln(int sxcoord, int sycoord, int dxcoord, int dycoord, int shade, int parallax)
// Draws a line in the L/R Display Buffers between two points

{
	int pos;
	int ylen = (dycoord - sycoord);
	int xlen = (dxcoord - sxcoord);
	int remainder;
	int fill;
	int slide = 0;
	int slope;
	int nextpos;
	int remmult = 1;
	int lenplus;
	int temp;
	//vars for horizontal/vertical drawing embedded
	int pos1;
	int thecoord;
	int offset;
	int length;
	int prevpos;
	int shift;
	int data;
	
	if (((xlen + ylen) < 0) || (((xlen + ylen) == 0) && (dxcoord < sxcoord))) // flip so any coordinates work for source or destination
	{
		temp = sxcoord;
		sxcoord = dxcoord;
		dxcoord = temp;
		temp = sycoord;
		sycoord = dycoord;
		dycoord = temp;
		xlen = (dxcoord-sxcoord);
		ylen = (dycoord-sycoord);
	}
		
	if (xlen < 0) // actually make it the length
		xlen = ~xlen + 1;
	if (ylen < 0)
		ylen = ~ylen + 1;

	if (ylen == 0)			// prevent div by 0 and make more efficient
	{
		buffhln(sxcoord, sycoord, xlen, shade, parallax);
		return;
	}
	else if (xlen == 0)		// prevent div by 0 and make more efficient
	{
		buffvln(sxcoord, sycoord, ylen, shade, parallax);
		return;
	}
	
	if ((xlen / ylen) < 1)		// Y longer than X
	{
		ylen++;
		lenplus = (xlen + 1);
		slope = (ylen / lenplus);
		remainder = (ylen % lenplus);
		nextpos = sycoord;
		for (pos = 0; pos <= xlen; pos++)
		{
			if (pos == ((remmult * lenplus) / (remainder + 1)))
			{
				fill = 0;
				slide++;
				if (remmult < remainder)
					remmult++;
			}
			else
				fill = -1;

			if ((dxcoord-sxcoord) < 0)
			{
				prevpos = 0;
				shift = (nextpos & 0x0F);
				data = 0;
				length = (slope + fill);
				thecoord = (sxcoord - pos);
				offset = ((thecoord << 4) + (nextpos >> 4));
				parallax <<= 4;
			
				for (pos1 = 0; pos1 <= length; pos1++)
				{
					data |= (shade << (shift << 1));
					shift++;
					if ((shift & 0x0F) == 0)
					{
						L_FRAME0[(offset + (pos1 >> 4) - parallax)] |= data;
						R_FRAME0[(offset + (pos1 >> 4) + parallax)] |= data;
						prevpos = (pos1 + 16);
						shift = 0;
						data = 0;
					}
				}
				if (shift != 0)
				{
					L_FRAME0[(offset + (prevpos >> 4) - parallax)] |= data;
					R_FRAME0[(offset + (prevpos >> 4) + parallax)] |= data;
				}
			}
			else
			{
				prevpos = 0;
				shift = (nextpos & 0x0F);
				data = 0;
				length = (slope + fill);
				thecoord = (sxcoord + pos);
				offset = ((thecoord << 4) + (nextpos >> 4));
				parallax <<= 4;
			
				for (pos1 = 0; pos1 <= length; pos1++)
				{
					data |= (shade << (shift << 1));
					shift++;
					if ((shift & 0x0F) == 0)
					{
						L_FRAME0[(offset + (pos1 >> 4) - parallax)] |= data;
						R_FRAME0[(offset + (pos1 >> 4) + parallax)] |= data;
						prevpos = (pos1 + 16);
						shift = 0;
						data = 0;
					}
				}
				if (shift != 0)
				{
					L_FRAME0[(offset + (prevpos >> 4) - parallax)] |= data;
					R_FRAME0[(offset + (prevpos >> 4) + parallax)] |= data;
				}
			}
			nextpos = (sycoord + (pos + 1) * slope + slide);
		}
	}

	else			// X longer or same as Y
	{
		xlen++;
		lenplus = (ylen + 1);
		slope = (xlen / lenplus);
		remainder = (xlen % lenplus);
		nextpos = sxcoord;
		for (pos = 0; pos <= ylen; pos++)
		{
			if (pos == ((remmult * lenplus) / (remainder + 1)))
			{
				fill = 0;
				slide++;
				if (remmult < remainder)
					remmult++;
			}
			else
				fill = -1;
			
			if ((dycoord-sycoord) < 0)
			{
				thecoord = (sycoord - pos);
				offset = ((nextpos << 4) + (thecoord >> 4));
				length = (slope + fill);
				
				for (pos1 = 0; pos1 <= (thecoord & 0x0F); pos1++)
					data = (shade << (pos1 << 1));
				for (pos1 = 0; pos1 <= length; pos1++)
				{
					L_FRAME0[((pos1 - parallax) << 4) + offset] |= data;
					R_FRAME0[((pos1 + parallax) << 4) + offset] |= data;
				}
			}
			else
			{
				thecoord = (sycoord + pos);
				offset = ((nextpos << 4) + (thecoord >> 4));
				length = (slope + fill);
				
				for (pos1 = 0; pos1 <= (thecoord & 0x0F); pos1++)
					data = (shade << (pos1 << 1));
				for (pos1 = 0; pos1 <= length; pos1++)
				{
					L_FRAME0[((pos1 - parallax) << 4) + offset] |= data;
					R_FRAME0[((pos1 + parallax) << 4) + offset] |= data;
				}
			}
			nextpos = (sxcoord + (pos + 1) * slope + slide);
		}
	}
}

int readpixel(int xcoord, int ycoord, int parallax)
// Reads the data of a pixel
{
	int pos;
	int offset = ((xcoord << 4) + (ycoord >> 4));
	int data;
	
	data = L_FRAME0[((0 - parallax) << 4) + offset];
	data &= R_FRAME0[(parallax << 4) + offset];
	
	for (pos = 0; pos != (ycoord & 0x0F); pos++); // gets pos to the right position

	return ((data >> (pos << 1)) & 3); // shifts to first 2 bits and masks
}

int randseed()
/* When run at startup gets a random number based on the changing CTA */
{
	int random = 1;
	int rand;
	int prevnum = 0;
	int count = 1;
	
	while (count < 30000)	//repeat through many times to make more random and to allow the CTA value to change multiple times
	{
		rand = (*(BYTE*)(0x0005F830));	//CTA
		if (random == 0)		//prevent % by zero
			random = 1;
			
		random += ((rand*count) + (count%random));	//just randomly doing stuff to the number
	
		if (rand == prevnum)		//if the CTA value doesnt change then count up
			count++;
		else
			count = 0;		//if the number does change then restart the counter
		prevnum = rand;			//keep track of the last number
	}
	return random;		//returns the random seed
}

int randnum(int seed, int randnums)
/* Returns a random number in the requested range from the random seed */
{
	return (seed%randnums);	//returns the random number
}

/////////////////LB's STUFF

/*void vbPrint(u8 bgmap, u16 col, u16 row, char t_string[], u16 bplt)
{
// Font consists of the last 256 chars (1792-2047)
	u16 i = 0,
		pos = 0,
		x = col,
		y = row;

	while(t_string[i])
	{
		pos = (y << 6) + x;

		switch(t_string[i])
		{
			case 7:
				// Bell (!)
				break;
			case 9:
				// Horizontal Tab (?)
				x = (x / 4 + 1) * 4;
				break;
			case 10:
				y++;
				x = col;
				break;
			default:
				BGMM[(0x1000 * bgmap) + pos] = ((u16)t_string[i] + 0x700) | (bplt << 14);
				if (x++ > 63)
				{
					x = col;
					y++;
				}
				break;
		}
	}
}*/

const static HWORD chAsciiMap[] = {
    //0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, // Char 0
    //0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 0
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // Char 0
    0x7FFD, 0xD557, 0xDD77, 0xD557, 0xDFF7, 0xD7D7, 0xD557, 0x7FFD, // Char 1
    0x7FFD, 0xFFFF, 0xF7DF, 0xFFFF, 0xF55F, 0xFD7F, 0xFFFF, 0x7FFD, // Char 2
    0x5F7D, 0x7FFF, 0x7FFF, 0x7FFF, 0x5FFD, 0x57F5, 0x55D5, 0x5555, // Char 3
    0x55D5, 0x57F5, 0x5FFD, 0x7FFF, 0x5FFD, 0x57F5, 0x55D5, 0x5555, // Char 4
    0x57F5, 0x5FFD, 0x57F5, 0x7FFF, 0x7FFF, 0x7DDF, 0x55D5, 0x57F5, // Char 5
    0x55D5, 0x55D5, 0x57F5, 0x5FFD, 0x7FFF, 0x5FFD, 0x55D5, 0x57F5, // Char 6
    0x5555, 0x5555, 0x57D5, 0x5FF5, 0x5FF5, 0x57D5, 0x5555, 0x5555, // Char 7
    0xFFFF, 0xFFFF, 0xFD7F, 0xF55F, 0xF55F, 0xFD7F, 0xFFFF, 0xFFFF, // Char 8
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 9
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 10
    0xFF55, 0xFD55, 0xFF55, 0xDFFD, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, // Char 11
    0x5FF5, 0x7D7D, 0x7D7D, 0x7D7D, 0x5FF5, 0x57D5, 0x7FFD, 0x57D5, // Char 12
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 13
    0xFFFD, 0xF57D, 0xFFFD, 0xF57D, 0xF57D, 0xFD7D, 0x7D7F, 0x555F, // Char 14
    0xD7D7, 0x77DD, 0x5FF5, 0xFD7F, 0xFD7F, 0x5FF5, 0x77DD, 0xD7D7, // Char 15
    0x5557, 0x557F, 0x57FF, 0x7FFF, 0x57FF, 0x557F, 0x5557, 0x5555, // Char 16
    0x7555, 0x7F55, 0x7FF5, 0x7FFF, 0x7FF5, 0x7F55, 0x7555, 0x5555, // Char 17
    0x57D5, 0x5FF5, 0x7FFD, 0x57D5, 0x57D5, 0x7FFD, 0x5FF5, 0x57D5, // Char 18
    0x7D7D, 0x7D7D, 0x7D7D, 0x7D7D, 0x7D7D, 0x5555, 0x7D7D, 0x5555, // Char 19
    0xFFFD, 0xF7DF, 0xF7DF, 0xF7FD, 0xF7D5, 0xF7D5, 0xF7D5, 0x5555, // Char 20
    0x7FFD, 0xF55F, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5F57, 0x57FF, // Char 21
    0x5555, 0x5555, 0x5555, 0x5555, 0x7FFD, 0x7FFD, 0x7FFD, 0x5555, // Char 22
    0x57D5, 0x5FF5, 0x7FFD, 0x57D5, 0x7FFD, 0x5FF5, 0x57D5, 0xFFFF, // Char 23
    0x57D5, 0x5FF5, 0x7FFD, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x5555, // Char 24
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x7FFD, 0x5FF5, 0x57D5, 0x5555, // Char 25
    0x5555, 0x57D5, 0x5F55, 0x7FFF, 0x5F55, 0x57D5, 0x5555, 0x5555, // Char 26
    0x5555, 0x55F5, 0x557D, 0x7FFF, 0x557D, 0x55F5, 0x5555, 0x5555, // Char 27
    0x5555, 0x5555, 0x555F, 0x555F, 0x555F, 0x7FFF, 0x5555, 0x5555, // Char 28
    0x5555, 0x5D75, 0x7D7D, 0xFFFF, 0x7D7D, 0x5D75, 0x5555, 0x5555, // Char 29
    0x5555, 0x57D5, 0x5FF5, 0x7FFD, 0xFFFF, 0xFFFF, 0x5555, 0x5555, // Char 30
    0x5555, 0xFFFF, 0xFFFF, 0x7FFD, 0x5FF5, 0x57D5, 0x5555, 0x5555, // Char 31
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 32
    0x55F5, 0x57FD, 0x57FD, 0x55F5, 0x55F5, 0x5555, 0x55F5, 0x5555, // Char 33
    0x5F7D, 0x5F7D, 0x5F7D, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 34
    0x5F7D, 0x5F7D, 0x7FFF, 0x5F7D, 0x7FFF, 0x5F7D, 0x5F7D, 0x5555, // Char 35
    0x55F5, 0x5FFD, 0x555F, 0x57FD, 0x5F55, 0x57FF, 0x55F5, 0x5555, // Char 36
    0x5555, 0x7D5F, 0x5F5F, 0x57D5, 0x55F5, 0x7D7D, 0x7D5F, 0x5555, // Char 37
    0x57F5, 0x5F7D, 0x57F5, 0x7DFD, 0x5FDF, 0x5F5F, 0x7DFD, 0x5555, // Char 38
    0x557D, 0x557D, 0x555F, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 39
    0x57D5, 0x55F5, 0x557D, 0x557D, 0x557D, 0x55F5, 0x57D5, 0x5555, // Char 40
    0x557D, 0x55F5, 0x57D5, 0x57D5, 0x57D5, 0x55F5, 0x557D, 0x5555, // Char 41
    0x5555, 0x7D7D, 0x5FF5, 0xFFFF, 0x5FF5, 0x7D7D, 0x5555, 0x5555, // Char 42
    0x5555, 0x55F5, 0x55F5, 0x5FFF, 0x55F5, 0x55F5, 0x5555, 0x5555, // Char 43
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x55FD, 0x55F5, 0x557D, // Char 44
    0x5555, 0x5555, 0x5555, 0x5FFF, 0x5555, 0x5555, 0x5555, 0x5555, // Char 45
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x55F5, 0x55F5, 0x5555, // Char 46
    0x7D55, 0x5F55, 0x57D5, 0x55F5, 0x557D, 0x555F, 0x5557, 0x5555, // Char 47
    0x57FD, 0x5F5F, 0x5FDF, 0x5FFF, 0x5F7F, 0x5F5F, 0x57FD, 0x5555, // Char 48
    0x55F5, 0x55FF, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x5FFF, 0x5555, // Char 49
    0x57FD, 0x5F5F, 0x5F55, 0x57F5, 0x557D, 0x5F5F, 0x5FFF, 0x5555, // Char 50
    0x57FD, 0x5F5F, 0x5F55, 0x57F5, 0x5F55, 0x5F5F, 0x57FD, 0x5555, // Char 51
    0x5FD5, 0x5FF5, 0x5F7D, 0x5F5F, 0x7FFF, 0x5F55, 0x5F55, 0x5555, // Char 52
    0x5FFF, 0x555F, 0x57FF, 0x5F55, 0x5F55, 0x5F5F, 0x57FD, 0x5555, // Char 53
    0x57F5, 0x557D, 0x555F, 0x57FF, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 54
    0x5FFF, 0x5F5F, 0x5F55, 0x57D5, 0x55F5, 0x557D, 0x557D, 0x5555, // Char 55
    0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 56
    0x57FD, 0x5F5F, 0x5F5F, 0x5FFD, 0x5F55, 0x57D5, 0x55FD, 0x5555, // Char 57
    0x5555, 0x5555, 0x55F5, 0x55F5, 0x5555, 0x55F5, 0x55F5, 0x5555, // Char 58
    0x5555, 0x5555, 0x55F5, 0x55F5, 0x5555, 0x55FD, 0x55F5, 0x557D, // Char 59
    0x57D5, 0x55F5, 0x557D, 0x555F, 0x557D, 0x55F5, 0x57D5, 0x5555, // Char 60
    0x5555, 0x5555, 0x5FFF, 0x5555, 0x5FFF, 0x5555, 0x5555, 0x5555, // Char 61
    0x557D, 0x55F5, 0x57D5, 0x5F55, 0x57D5, 0x55F5, 0x557D, 0x5555, // Char 62
    0x57FD, 0x5F5F, 0x5F55, 0x57D5, 0x55F5, 0x5555, 0x55F5, 0x5555, // Char 63
    0x5FFD, 0x7D5F, 0x7FDF, 0x7FDF, 0x7FDF, 0x555F, 0x57FD, 0x5555, // Char 64
    0x55F5, 0x57FD, 0x5F5F, 0x5F5F, 0x5FFF, 0x5F5F, 0x5F5F, 0x5555, // Char 65
    0x5FFF, 0x7D7D, 0x7D7D, 0x5FFD, 0x7D7D, 0x7D7D, 0x5FFF, 0x5555, // Char 66
    0x5FF5, 0x7D7D, 0x555F, 0x555F, 0x555F, 0x7D7D, 0x5FF5, 0x5555, // Char 67
    0x5FFF, 0x5F7D, 0x7D7D, 0x7D7D, 0x7D7D, 0x5F7D, 0x5FFF, 0x5555, // Char 68
    0x7FFF, 0x757D, 0x577D, 0x57FD, 0x577D, 0x757D, 0x7FFF, 0x5555, // Char 69
    0x7FFF, 0x757D, 0x577D, 0x57FD, 0x577D, 0x557D, 0x55FF, 0x5555, // Char 70
    0x5FF5, 0x7D7D, 0x555F, 0x555F, 0x7F5F, 0x7D7D, 0x7FF5, 0x5555, // Char 71
    0x5F5F, 0x5F5F, 0x5F5F, 0x5FFF, 0x5F5F, 0x5F5F, 0x5F5F, 0x5555, // Char 72
    0x57FD, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 73
    0x7FD5, 0x5F55, 0x5F55, 0x5F55, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 74
    0x7D7F, 0x7D7D, 0x5F7D, 0x57FD, 0x5F7D, 0x7D7D, 0x7D7F, 0x5555, // Char 75
    0x55FF, 0x557D, 0x557D, 0x557D, 0x757D, 0x7D7D, 0x7FFF, 0x5555, // Char 76
    0x7D5F, 0x7F7F, 0x7FFF, 0x7DDF, 0x7D5F, 0x7D5F, 0x7D5F, 0x5555, // Char 77
    0x7D5F, 0x7D7F, 0x7DFF, 0x7FDF, 0x7F5F, 0x7D5F, 0x7D5F, 0x5555, // Char 78
    0x57F5, 0x5F7D, 0x7D5F, 0x7D5F, 0x7D5F, 0x5F7D, 0x57F5, 0x5555, // Char 79
    0x5FFF, 0x7D7D, 0x7D7D, 0x5FFD, 0x557D, 0x557D, 0x55FF, 0x5555, // Char 80
    0x57FD, 0x5F5F, 0x5F5F, 0x5F5F, 0x5FDF, 0x57FD, 0x5FD5, 0x5555, // Char 81
    0x5FFF, 0x7D7D, 0x7D7D, 0x5FFD, 0x57FD, 0x5F7D, 0x7D7F, 0x5555, // Char 82
    0x57FD, 0x5F5F, 0x557F, 0x57F5, 0x5FD5, 0x5F5F, 0x57FD, 0x5555, // Char 83
    0x5FFF, 0x5DF7, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 84
    0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5FFF, 0x5555, // Char 85
    0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x55F5, 0x5555, // Char 86
    0x7D5F, 0x7D5F, 0x7D5F, 0x7DDF, 0x7FFF, 0x7F7F, 0x7D5F, 0x5555, // Char 87
    0x7D5F, 0x7D5F, 0x5F7D, 0x57F5, 0x5F7D, 0x7D5F, 0x7D5F, 0x5555, // Char 88
    0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 89
    0x7FFF, 0x5F5F, 0x57D7, 0x55F5, 0x757D, 0x7D5F, 0x7FFF, 0x5555, // Char 90
    0x57FD, 0x557D, 0x557D, 0x557D, 0x557D, 0x557D, 0x57FD, 0x5555, // Char 91
    0x555F, 0x557D, 0x55F5, 0x57D5, 0x5F55, 0x7D55, 0x7555, 0x5555, // Char 92
    0x57FD, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57FD, 0x5555, // Char 93
    0x55D5, 0x57F5, 0x5F7D, 0x7D5F, 0x5555, 0x5555, 0x5555, 0x5555, // Char 94
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0xFFFF, // Char 95
    0x55F5, 0x55F5, 0x57D5, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 96
    0x5555, 0x5555, 0x57FD, 0x5F55, 0x5FFD, 0x5F5F, 0x7DFD, 0x5555, // Char 97
    0x557F, 0x557D, 0x5FFD, 0x7D7D, 0x7D7D, 0x7D7D, 0x5FF7, 0x5555, // Char 98
    0x5555, 0x5555, 0x57FD, 0x5F5F, 0x555F, 0x5F5F, 0x57FD, 0x5555, // Char 99
    0x5FD5, 0x5F55, 0x5F55, 0x5FFD, 0x5F5F, 0x5F5F, 0x7DFD, 0x5555, // Char 100
    0x5555, 0x5555, 0x57FD, 0x5F5F, 0x5FFF, 0x555F, 0x57FD, 0x5555, // Char 101
    0x57F5, 0x5F7D, 0x557D, 0x55FF, 0x557D, 0x557D, 0x55FF, 0x5555, // Char 102
    0x5555, 0x5555, 0x7DFD, 0x5F5F, 0x5F5F, 0x5FFD, 0x5F55, 0x57FF, // Char 103
    0x557F, 0x557D, 0x5F7D, 0x7DFD, 0x7D7D, 0x7D7D, 0x7D7F, 0x5555, // Char 104
    0x55F5, 0x5555, 0x55FD, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 105
    0x57D5, 0x5555, 0x57FD, 0x57D5, 0x57D5, 0x57D5, 0x57DF, 0x55FD, // Char 106
    0x557F, 0x557D, 0x7D7D, 0x5F7D, 0x57FD, 0x5F7D, 0x7D7F, 0x5555, // Char 107
    0x55FD, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 108
    0x5555, 0x5555, 0x5F7F, 0x7FFF, 0x7DDF, 0x7D5F, 0x7D5F, 0x5555, // Char 109
    0x5555, 0x5555, 0x57FF, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5555, // Char 110
    0x5555, 0x5555, 0x57FD, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 111
    0x5555, 0x5555, 0x5FDF, 0x7D7D, 0x7D7D, 0x5FFD, 0x557D, 0x55FF, // Char 112
    0x5555, 0x5555, 0x7DFD, 0x5F5F, 0x5F5F, 0x5FFD, 0x5F55, 0x7FD5, // Char 113
    0x5555, 0x5555, 0x57DF, 0x5F7D, 0x5F7D, 0x557D, 0x55FF, 0x5555, // Char 114
    0x5555, 0x5555, 0x5FFD, 0x555F, 0x57FD, 0x5F55, 0x57FF, 0x5555, // Char 115
    0x55D5, 0x55F5, 0x5FFD, 0x55F5, 0x55F5, 0x5DF5, 0x57D5, 0x5555, // Char 116
    0x5555, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x7DFD, 0x5555, // Char 117
    0x5555, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x55F5, 0x5555, // Char 118
    0x5555, 0x5555, 0x7D5F, 0x7D5F, 0x7DDF, 0x7FFF, 0x5F7D, 0x5555, // Char 119
    0x5555, 0x5555, 0x7D5F, 0x5F7D, 0x57F5, 0x5F7D, 0x7D5F, 0x5555, // Char 120
    0x5555, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x5FFD, 0x5F55, 0x57FF, // Char 121
    0x5555, 0x5555, 0x5FFF, 0x57D7, 0x55F5, 0x5D7D, 0x5FFF, 0x5555, // Char 122
    0x5FD5, 0x55F5, 0x55F5, 0x557F, 0x55F5, 0x55F5, 0x5FD5, 0x5555, // Char 123
    0x57D5, 0x57D5, 0x57D5, 0x5555, 0x57D5, 0x57D5, 0x57D5, 0x5555, // Char 124
    0x557F, 0x55F5, 0x55F5, 0x5FD5, 0x55F5, 0x55F5, 0x557F, 0x5555, // Char 125
    0x7DFD, 0x5FDF, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, // Char 126
    0x55D5, 0x57F5, 0x5F7D, 0x7D5F, 0x7D5F, 0x7D5F, 0x7FFF, 0x5555, // Char 127
    0x57FD, 0x5F5F, 0x555F, 0x5F5F, 0x57FD, 0x57D5, 0x5F55, 0x57FD, // Char 128
    0x5555, 0x5F5F, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x7FFD, 0x5555, // Char 129
    0x5FD5, 0x5555, 0x57FD, 0x5F5F, 0x5FFF, 0x555F, 0x57FD, 0x5555, // Char 130
    0x7FFD, 0xF55F, 0x5FF5, 0x7D55, 0x7FF5, 0x7D7D, 0xFFF5, 0x5555, // Char 131
    0x5F5F, 0x5555, 0x57FD, 0x5F55, 0x5FFD, 0x5F5F, 0x7FFD, 0x5555, // Char 132
    0x557F, 0x5555, 0x57FD, 0x5F55, 0x5FFD, 0x5F5F, 0x7FFD, 0x5555, // Char 133
    0x55F5, 0x55F5, 0x57FD, 0x5F55, 0x5FFD, 0x5F5F, 0x7FFD, 0x5555, // Char 134
    0x5555, 0x5555, 0x5FFD, 0x555F, 0x555F, 0x5FFD, 0x7D55, 0x5FF5, // Char 135
    0x7FFD, 0xF55F, 0x5FF5, 0x7D7D, 0x7FFD, 0x557D, 0x5FF5, 0x5555, // Char 136
    0x5F5F, 0x5555, 0x57FD, 0x5F5F, 0x5FFF, 0x555F, 0x57FD, 0x5555, // Char 137
    0x557F, 0x5555, 0x57FD, 0x5F5F, 0x5FFF, 0x555F, 0x57FD, 0x5555, // Char 138
    0x5F5F, 0x5555, 0x55FD, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 139
    0x5FFD, 0x7D5F, 0x57F5, 0x57D5, 0x57D5, 0x57D5, 0x5FF5, 0x5555, // Char 140
    0x557F, 0x5555, 0x55FD, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 141
    0x5F5F, 0x55F5, 0x57FD, 0x5F5F, 0x5F5F, 0x5FFF, 0x5F5F, 0x5555, // Char 142
    0x55F5, 0x55F5, 0x5555, 0x57FD, 0x5F5F, 0x5FFF, 0x5F5F, 0x5555, // Char 143
    0x5FD5, 0x5555, 0x5FFF, 0x557D, 0x57FD, 0x557D, 0x5FFF, 0x5555, // Char 144
    0x5555, 0x5555, 0xFFFD, 0x5F55, 0xFFFD, 0x5F5F, 0xFFFD, 0x5555, // Char 145
    0x7FF5, 0x5F7D, 0x5F5F, 0x7FFF, 0x5F5F, 0x5F5F, 0x7F5F, 0x5555, // Char 146
    0x57FD, 0x5F5F, 0x5555, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 147
    0x5555, 0x5F5F, 0x5555, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 148
    0x5555, 0x557F, 0x5555, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 149
    0x57FD, 0x5F5F, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x7FFD, 0x5555, // Char 150
    0x5555, 0x557F, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x7FFD, 0x5555, // Char 151
    0x5555, 0x5F5F, 0x5555, 0x5F5F, 0x5F5F, 0x5FFF, 0x5F55, 0x57FF, // Char 152
    0x7D5F, 0x57F5, 0x5FFD, 0x7D5F, 0x7D5F, 0x5FFD, 0x57F5, 0x5555, // Char 153
    0x5F5F, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 154
    0x57D5, 0x57D5, 0x7FFD, 0x555F, 0x555F, 0x7FFD, 0x57D5, 0x57D5, // Char 155
    0x57F5, 0x5F7D, 0x5D7D, 0x55FF, 0x557D, 0x7D7F, 0x5FFF, 0x5555, // Char 156
    0x5F5F, 0x5F5F, 0x57FD, 0x5FFF, 0x55F5, 0x5FFF, 0x55F5, 0x5555, // Char 157
    0x55FF, 0x57DF, 0x57DF, 0x5DFF, 0x5F5F, 0x7FDF, 0x5F5F, 0x7F55, // Char 158
    0x7F55, 0xF7D5, 0x57D5, 0x7FFD, 0x57D5, 0x57D5, 0x57DF, 0x55FD, // Char 159
    0x5FD5, 0x5555, 0x57FD, 0x5F55, 0x5FFD, 0x5F5F, 0x7FFD, 0x5555, // Char 160
    0x57F5, 0x5555, 0x55FD, 0x55F5, 0x55F5, 0x55F5, 0x57FD, 0x5555, // Char 161
    0x5555, 0x5FD5, 0x5555, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 162
    0x5555, 0x5FD5, 0x5555, 0x5F5F, 0x5F5F, 0x5F5F, 0x7FFD, 0x5555, // Char 163
    0x5555, 0x57FF, 0x5555, 0x57FF, 0x5F5F, 0x5F5F, 0x5F5F, 0x5555, // Char 164
    0x5FFF, 0x5555, 0x5F5F, 0x5F7F, 0x5FFF, 0x5FDF, 0x5F5F, 0x5555, // Char 165
    0x5FF5, 0x5F7D, 0x5F7D, 0x7FF5, 0x5555, 0x7FFD, 0x5555, 0x5555, // Char 166
    0x5FF5, 0x7D7D, 0x7D7D, 0x5FF5, 0x5555, 0x7FFD, 0x5555, 0x5555, // Char 167
    0x55F5, 0x5555, 0x55F5, 0x557D, 0x555F, 0x5F5F, 0x57FD, 0x5555, // Char 168
    0x5555, 0x5555, 0x5555, 0x5FFF, 0x555F, 0x555F, 0x5555, 0x5555, // Char 169
    0x5555, 0x5555, 0x5555, 0x5FFF, 0x5F55, 0x5F55, 0x5555, 0x5555, // Char 170
    0x7D5F, 0x5F5F, 0x57DF, 0x7FF5, 0xF57D, 0x7F5F, 0x57D7, 0xFFD5, // Char 171
    0x7D5F, 0x5F5F, 0x57DF, 0xF5FF, 0xFD7D, 0xFF5F, 0xFFD7, 0xF555, // Char 172
    0x5555, 0x57D5, 0x5555, 0x57D5, 0x57D5, 0x5FF5, 0x5FF5, 0x57D5, // Char 173
    0x5555, 0xF5F5, 0x7D7D, 0x5F5F, 0x7D7D, 0xF5F5, 0x5555, 0x5555, // Char 174
    0x5555, 0x5F5F, 0x7D7D, 0xF5F5, 0x7D7D, 0x5F5F, 0x5555, 0x5555, // Char 175
    0x7575, 0x5757, 0x7575, 0x5757, 0x7575, 0x5757, 0x7575, 0x5757, // Char 176
    0xDDDD, 0x7777, 0xDDDD, 0x7777, 0xDDDD, 0x7777, 0xDDDD, 0x7777, // Char 177
    0xDFDF, 0xFDFD, 0xDFDF, 0xFDFD, 0xDFDF, 0xFDFD, 0xDFDF, 0xFDFD, // Char 178
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, // Char 179
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57FF, 0x57D5, 0x57D5, 0x57D5, // Char 180
    0x57D5, 0x57D5, 0x57FF, 0x57D5, 0x57FF, 0x57D5, 0x57D5, 0x57D5, // Char 181
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7DFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 182
    0x5555, 0x5555, 0x5555, 0x5555, 0x7FFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 183
    0x5555, 0x5555, 0x57FF, 0x57D5, 0x57FF, 0x57D5, 0x57D5, 0x57D5, // Char 184
    0x7DF5, 0x7DF5, 0x7DFF, 0x7D55, 0x7DFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 185
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, // Char 186
    0x5555, 0x5555, 0x7FFF, 0x7D55, 0x7DFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 187
    0x7DF5, 0x7DF5, 0x7DFF, 0x7D55, 0x7FFF, 0x5555, 0x5555, 0x5555, // Char 188
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0x7FFF, 0x5555, 0x5555, 0x5555, // Char 189
    0x57D5, 0x57D5, 0x57FF, 0x57D5, 0x57FF, 0x5555, 0x5555, 0x5555, // Char 190
    0x5555, 0x5555, 0x5555, 0x5555, 0x57FF, 0x57D5, 0x57D5, 0x57D5, // Char 191
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0xFFD5, 0x5555, 0x5555, 0x5555, // Char 192
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 193
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFFF, 0x57D5, 0x57D5, 0x57D5, // Char 194
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0xFFD5, 0x57D5, 0x57D5, 0x57D5, // Char 195
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 196
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0xFFFF, 0x57D5, 0x57D5, 0x57D5, // Char 197
    0x57D5, 0x57D5, 0xFFD5, 0x57D5, 0xFFD5, 0x57D5, 0x57D5, 0x57D5, // Char 198
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0xFDF5, 0x7DF5, 0x7DF5, 0x7DF5, // Char 199
    0x7DF5, 0x7DF5, 0xFDF5, 0x55F5, 0xFFF5, 0x5555, 0x5555, 0x5555, // Char 200
    0x5555, 0x5555, 0xFFF5, 0x55F5, 0xFDF5, 0x7DF5, 0x7DF5, 0x7DF5, // Char 201
    0x7DF5, 0x7DF5, 0xFDFF, 0x5555, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 202
    0x5555, 0x5555, 0xFFFF, 0x5555, 0xFDFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 203
    0x7DF5, 0x7DF5, 0xFDF5, 0x55F5, 0xFDF5, 0x7DF5, 0x7DF5, 0x7DF5, // Char 204
    0x5555, 0x5555, 0xFFFF, 0x5555, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 205
    0x7DF5, 0x7DF5, 0xFDFF, 0x5555, 0xFDFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 206
    0x57D5, 0x57D5, 0xFFFF, 0x5555, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 207
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0xFFFF, 0x5555, 0x5555, 0x5555, // Char 208
    0x5555, 0x5555, 0xFFFF, 0x5555, 0xFFFF, 0x57D5, 0x57D5, 0x57D5, // Char 209
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 210
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0xFFF5, 0x5555, 0x5555, 0x5555, // Char 211
    0x57D5, 0x57D5, 0xFFD5, 0x57D5, 0xFFD5, 0x5555, 0x5555, 0x5555, // Char 212
    0x5555, 0x5555, 0xFFD5, 0x57D5, 0xFFD5, 0x57D5, 0x57D5, 0x57D5, // Char 213
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFF5, 0x7DF5, 0x7DF5, 0x7DF5, // Char 214
    0x7DF5, 0x7DF5, 0x7DF5, 0x7DF5, 0xFDFF, 0x7DF5, 0x7DF5, 0x7DF5, // Char 215
    0x57D5, 0x57D5, 0xFFFF, 0x5555, 0xFFFF, 0x57D5, 0x57D5, 0x57D5, // Char 216
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57FF, 0x5555, 0x5555, 0x5555, // Char 217
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFD5, 0x57D5, 0x57D5, 0x57D5, // Char 218
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, // Char 219
    0x5555, 0x5555, 0x5555, 0x5555, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, // Char 220
    0x55FF, 0x55FF, 0x55FF, 0x55FF, 0x55FF, 0x55FF, 0x55FF, 0x55FF, // Char 221
    0xFF55, 0xFF55, 0xFF55, 0xFF55, 0xFF55, 0xFF55, 0xFF55, 0xFF55, // Char 222
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5555, 0x5555, 0x5555, 0x5555, // Char 223
    0x5555, 0x5555, 0x7DFD, 0x5FDF, 0x575F, 0x5FDF, 0x7DFD, 0x5555, // Char 224
    0x5555, 0x57FD, 0x5F5F, 0x57FF, 0x5F5F, 0x57FF, 0x555F, 0x555F, // Char 225
    0x5555, 0x7FFF, 0x7D5F, 0x555F, 0x555F, 0x555F, 0x555F, 0x5555, // Char 226
    0x5555, 0x7FFF, 0x5F7D, 0x5F7D, 0x5F7D, 0x5F7D, 0x5F7D, 0x5555, // Char 227
    0x7FFF, 0x7D7D, 0x55F5, 0x57D5, 0x55F5, 0x7D7D, 0x7FFF, 0x5555, // Char 228
    0x5555, 0x5555, 0x7FFD, 0x5F5F, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 229
    0x5555, 0x7D7D, 0x7D7D, 0x7D7D, 0x7D7D, 0x5FFD, 0x557D, 0x555F, // Char 230
    0x5555, 0x7DFD, 0x5FDF, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x5555, // Char 231
    0x5FFF, 0x55F5, 0x57FD, 0x5F5F, 0x5F5F, 0x57FD, 0x55F5, 0x5FFF, // Char 232
    0x57F5, 0x5F7D, 0x7D5F, 0x7FFF, 0x7D5F, 0x5F7D, 0x57F5, 0x5555, // Char 233
    0x57F5, 0x5F7D, 0x7D5F, 0x7D5F, 0x5F7D, 0x5F7D, 0x7F7F, 0x5555, // Char 234
    0x5FD5, 0x55F5, 0x57D5, 0x5FFD, 0x5F5F, 0x5F5F, 0x57FD, 0x5555, // Char 235
    0x5555, 0x5555, 0x7FFD, 0xF7DF, 0xF7DF, 0x7FFD, 0x5555, 0x5555, // Char 236
    0x7D55, 0x5F55, 0x7FFD, 0xF7DF, 0xF7DF, 0x7FFD, 0x557D, 0x555F, // Char 237
    0x5FF5, 0x557D, 0x555F, 0x5FFF, 0x555F, 0x557D, 0x5FF5, 0x5555, // Char 238
    0x57FD, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5F5F, 0x5555, // Char 239
    0x5555, 0x5FFF, 0x5555, 0x5FFF, 0x5555, 0x5FFF, 0x5555, 0x5555, // Char 240
    0x55F5, 0x55F5, 0x5FFF, 0x55F5, 0x55F5, 0x5555, 0x5FFF, 0x5555, // Char 241
    0x557D, 0x55F5, 0x57D5, 0x55F5, 0x557D, 0x5555, 0x5FFF, 0x5555, // Char 242
    0x57D5, 0x55F5, 0x557D, 0x55F5, 0x57D5, 0x5555, 0x5FFF, 0x5555, // Char 243
    0x7F55, 0xF7D5, 0xF7D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, // Char 244
    0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57D5, 0x57DF, 0x57DF, 0x55FD, // Char 245
    0x55F5, 0x55F5, 0x5555, 0x5FFF, 0x5555, 0x55F5, 0x55F5, 0x5555, // Char 246
    0x5555, 0x75FD, 0x5FD7, 0x5555, 0x75FD, 0x5FD7, 0x5555, 0x5555, // Char 247
    0x57F5, 0x5F7D, 0x5F7D, 0x57F5, 0x5555, 0x5555, 0x5555, 0x5555, // Char 248
    0x5555, 0x5555, 0x5555, 0x57D5, 0x57D5, 0x5555, 0x5555, 0x5555, // Char 249
    0x5555, 0x5555, 0x5555, 0x5555, 0x57D5, 0x5555, 0x5555, 0x5555, // Char 250
    0xFF55, 0x5F55, 0x5F55, 0x5F55, 0x5F7F, 0x5F7D, 0x5FF5, 0x5FD5, // Char 251
    0x57FD, 0x5F7D, 0x5F7D, 0x5F7D, 0x5F7D, 0x5555, 0x5555, 0x5555, // Char 252
    0x57FD, 0x5F55, 0x57F5, 0x557D, 0x5FFD, 0x5555, 0x5555, 0x5555, // Char 253
    0x5555, 0x5555, 0x5FF5, 0x5FF5, 0x5FF5, 0x5FF5, 0x5555, 0x5555, // Char 254
    0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555, 0x5555  // Char 255
};


void vbPrint(u8 bgmap, u16 x, u16 y, char *t_string, u16 bplt)
{
/* Font consists of the last 256 chars (1792-2047) */
	u16 i=0,pos=0,col=x;

	while(t_string[i])
	{
		pos = (y << 6) + x;

		switch(t_string[i])
		{
			case 7:
				// Bell (!)
				break;
			case 9:
				// Horizontal Tab
				x = (x / 4 + 1) * 4;
				break;
			case 10:
				// Carriage Return
				y++;
				x = col;
				break;
			case 13:
				// Line Feed
				// x = col;
				break;
			default:
				BGMM[(0x1000 * bgmap) + pos] = ((u16)t_string[i] + 0x780) | (bplt << 14);
				if (x++ > 63)
				{
					x = col;
					y++;
				}
				break;
		}
		i++;
	}
}

char word[33];

char* num2str(int num, int base)
{
	int count = 0;
	int length = 0;
	char temp;

	temp = '0' + num%base;
	if (temp > '9')
		temp += 7;
	word[count] = temp;
	num /= base;
	length++;
	for (count = 1; num != 0; count++)
	{
		temp = '0' + num%base;
		if (temp > '9')
			temp += 7;
		word[count] = temp;
		num /= base;
		length++;
	}
	word[length] = 0;
	
	//reverse chars
	for (count = 0; count < length/2; count++)
	{
		temp = word[count];
		word[count] = word[length - count - 1];
		word[length - count - 1] = temp;
	}

	return word;
}

const char nums[16]="0123456789ABCDEF";

static char *itoa(u32 num, u8 base, u8 digits) {
	int i;
	static char rev[11];

	for (i = 0; i < 10; i++) {
		rev[9-i] = nums[num%base];
		num /= base;
	}

	i=0;
	while (rev[i] == '0') i++;
	if (i >= (10-digits)) i=(10-digits);

	rev[10] = 0;

	return rev+i;
}

static char *s_itoa(s32 num, u8 base, u8 digits) {
	int i;
	static char rev[12];

	if (num<0)
	{
		num=-num;
		for (i = 0; i < 10; i++) {
			rev[9-i] = nums[num%base];
			num /= base;
		}

		i=0;
		while (rev[i] == '0') i++;
		if (i >= (10-digits)) i=(10-digits);
		i--;
		rev[i]='-';

		rev[10] = 0;
	}
	else
	{
		for (i = 0; i < 10; i++) {
			rev[9-i] = nums[num%base];
			num /= base;
		}

		i=0;
		while (rev[i] == '0') i++;
		if (i >= (10-digits)) i=(10-digits);

		rev[10] = 0;
	}

	return rev+i;
}

void cls(int bgmap) {
	//setmem((void*)(BGMap(0)+(128*4)), 0, 8192-(128*4));
	setmem((void*)(BGMap(bgmap)), 0, 8192*4);
}

void bgmap_print(int bgmap, int col, int row, BYTE t_string[], int bplt)
/* Font map (0-255) must reside in the upper half of CharSeg3 */
{
	int i = 0;
	int pos = row * 64 + col;
	while(t_string[i])
	//while(i<10)
	{
		BGMM[(0x1000 * bgmap) + pos + i] = (HWORD)t_string[i] + 0x780 + ((bplt & 0x03) << 14);
		i++;
	}
}

void bgmap_print_blank(int bgmap, int col, int row, int len)
/* Font map (0-255) must reside in the upper half of CharSeg3 */
{
	int i;
	int pos = row * 64 + col;
	for (i=0; i<len; i++)
		BGMM[(0x1000 * bgmap) + pos + i] = 0x780;
}

/***** BGMap Functions *****/
void vbSetBGMapCell(int n, int x, int y, HWORD header, int num)
{
	int i;
	for (i = 0; i < num; i++)
		BGMM[(0x1000 * n) + (y * 64) + x + i] = header;
}

void vbSetBGMap(int n, HWORD header)
{
	int i;
	for (i = 0; i < 4096; i++)
		BGMM[(0x1000 * n) + i] = header;
}

#define BGM_CSET(n,x,y,c)	BGMM[(0x1000 * n) + (y * 64) + x] = (BGMM[(0x1000 * n) + (y * 64) + x] & 0xF000) | (HWORD)c;
#define BGM_HSET(n,x,y,h)	BGMM[(0x1000 * n) + (y * 64) + x] = (BGMM[(0x1000 * n) + (y * 64) + x] & 0xDFFF) | (((HWORD)h << 13) & 0x2000);
#define BGM_VSET(n,x,y,v)	BGMM[(0x1000 * n) + (y * 64) + x] = (BGMM[(0x1000 * n) + (y * 64) + x] & 0xEFFF) | (((HWORD)v << 12) & 0x1000);
#define BGM_PALSET(n,x,y,pal)    BGMM[(0x1000 * n) + (y * 64) + x] = ((pal << 14) & 0xC000) | (0x1000 * n) + (BGMM[(0x1000 * n) + (y * 64) + x] & 0x3FFF);

/* "vbSetBGMap" header flags */
/* (OR these together to build an BGMap Header) */
#define	BGM_PAL0	0x0000
#define	BGM_PAL1	0x4000
#define	BGM_PAL2	0x8000
#define	BGM_PAL3	0xC000

#define	BGM_HFLIP	0x2000
#define	BGM_VFLIP	0x1000


#endif
