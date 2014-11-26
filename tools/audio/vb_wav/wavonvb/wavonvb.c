//VB WAV converter/player example
//By Pat Daderko (DogP) - www.projectvb.com

#include "modlibgccvb.h"

#include "you_suck.h"
#include "mario.h"
#include "final_lap.h"
#include "ding.h"

//waveform RAM contents
u8 wave1[]={
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F
};

//~1.6 usec delay, count needs to be volatile or the optimizer basically removes this function
void delay1p6us(volatile int count)
{
	asm("
	1:
	add	-1,%0 /*decrement count*/
	cmp	0,%0 /*compare num with 0 to tell when done*/
	bgt	1b /*loop if count remaining is greater than 0*/
	"
	: /* No Output */
	: "r" (count) /* Input */
	/* :  no regs used */
	);
}

void init_speech()
{
  int i;
  
  SSTOP = 1; //stop all sounds
  
  for (i=0; i<32; i++) //copy waveform data
    WAVEDATA1[i<<2]=wave1[i];
  
  //turn off channels
  SND_REGS[0].SxINT = 0x00;
  SND_REGS[1].SxINT = 0x00;
  SND_REGS[2].SxINT = 0x00;
  SND_REGS[3].SxINT = 0x00;
  SND_REGS[4].SxINT = 0x00;
  SND_REGS[5].SxINT = 0x00;
  
  SSTOP = 0; //allow sounds

  //use Waveform RAM0
  SND_REGS[0].SxRAM = 0x00;
  SND_REGS[1].SxRAM = 0x00;
  SND_REGS[2].SxRAM = 0x00;
  SND_REGS[3].SxRAM = 0x00;
  SND_REGS[4].SxRAM = 0x00;
  
  //mute all
  SND_REGS[0].SxLRV = 0x00;
  SND_REGS[1].SxLRV = 0x00;
  SND_REGS[2].SxLRV = 0x00;
  SND_REGS[3].SxLRV = 0x00;
  SND_REGS[4].SxLRV = 0x00;
  SND_REGS[5].SxLRV = 0x00;
  
  //set initial envelope to max
  SND_REGS[0].SxEV0 = 0xF0;
  SND_REGS[1].SxEV0 = 0xF0;
  SND_REGS[2].SxEV0 = 0xF0;
  SND_REGS[3].SxEV0 = 0xF0;
  SND_REGS[4].SxEV0 = 0xF0;
  SND_REGS[5].SxEV0 = 0x00;
  
  //disable envelope
  SND_REGS[0].SxEV1 = 0x00;
  SND_REGS[1].SxEV1 = 0x00;
  SND_REGS[2].SxEV1 = 0x00;
  SND_REGS[3].SxEV1 = 0x00;
  SND_REGS[4].SxEV1 = 0x00;
  
  //set low freq (doesn't matter since waveform is DC)
  SND_REGS[0].SxFQL = 0x00;
  SND_REGS[1].SxFQL = 0x00;
  SND_REGS[2].SxFQL = 0x00;
  SND_REGS[3].SxFQL = 0x00;
  SND_REGS[4].SxFQL = 0x00;
  SND_REGS[0].SxFQH = 0x00;
  SND_REGS[1].SxFQH = 0x00;
  SND_REGS[2].SxFQH = 0x00;
  SND_REGS[3].SxFQH = 0x00;
  SND_REGS[4].SxFQH = 0x00;
  
  SND_REGS[0].SxINT = 0x80; //enable channel 1
}

//plays wav data passed in with parameters
void wavplay(const u8 *wav_data, int channels, int len, int delaytime)
{
  int i;

  if (channels == 1) //mono
  {
    for (i=0; i<len; i++)
    {
      if (!(i&1)) //first half of packed data
        SND_REGS[0].SxLRV=(wav_data[i>>1]&0xF0)|(wav_data[i>>1]>>4);
      else //second half of packed data
        SND_REGS[0].SxLRV=((wav_data[i>>1]&0x0F)<<4)|(wav_data[i>>1]&0x0F);
      delay1p6us(delaytime);
    }
  }
  else //stereo
  {
    for (i=0; i<len; i++)
    {
      SND_REGS[0].SxLRV=wav_data[i];
      delay1p6us(delaytime);
    }
  }
}

//divide this number by sample rate for delay
//feel free free to tweak to get sound just right
//or just hardcode the delay once you get it
#define SR_DIV 675000

int main()
{
  vbDisplayOn();
  vbDisplayShow();
  
  init_speech(); //initialize sound regs for speech
    
  VIP_REGS[BKCOL]=3; //tells that we've started

  while(1)
  {
    wavplay(you_suck, YOU_SUCK_CH, YOU_SUCK_LEN, SR_DIV/YOU_SUCK_SR); //play "you suck"
    while(!(vbReadPad()&K_ANY));
    VIP_REGS[BKCOL]^=3;
    
    wavplay(mario, MARIO_CH, MARIO_LEN, SR_DIV/MARIO_SR); //play mario sound
    while(!(vbReadPad()&K_ANY));
    VIP_REGS[BKCOL]^=3;
    
    wavplay(final_lap, FINAL_LAP_CH, FINAL_LAP_LEN, SR_DIV/FINAL_LAP_SR); //play Mario Kart final lap sound
    while(!(vbReadPad()&K_ANY));
    VIP_REGS[BKCOL]^=3;
    
    wavplay(ding, DING_CH, DING_LEN, SR_DIV/DING_SR); //play Windows ding sound (stereo)
    while(!(vbReadPad()&K_ANY));
    VIP_REGS[BKCOL]^=3;
  }

	return 0;
}
