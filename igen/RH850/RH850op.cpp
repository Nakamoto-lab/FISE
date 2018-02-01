
#include "RH850Mcoresim.h"

CoreContext Context[MAXCORE];
uint32_t CurrentCore;

/* cpoy n bytes from s to d */
void memcp(uint8_t *s, uint8_t *d, int n) {
	int i;
	for (i = 0; i < n; i++) {
		*d++ = *s++;
	}
}


void initRH850sim()
{
	for (int i = 0; i < MAXCORE; i++) {
		Context[i].reg[REG0] = 0;  /* REG should be ZERO */
		Context[i].reg[SP] = STACKSIZE; /* sp points to the bottom of stack at init */
	}
}

void op_ld23dw(uint32_t disp23, uint32_t reg1, uint32_t reg2)
{
	uint32_t cc = CurrentCore;
	memcp((uint8_t  *)(Context[cc].reg[reg1]) + disp23, (uint8_t  *)(&(Context[cc].reg[reg2])), 4);
	memcp((uint8_t  *)(Context[cc].reg[reg1]) + disp23 + 4, (uint8_t  *)(&(Context[cc].reg[reg2 + 1])), 4);

	Context[cc].delay += delay_ld23dw * TargetClock;
}



void op_st23dw(uint32_t reg2, int disp23, uint32_t reg1)
{
	uint32_t cc = CurrentCore;	
	memcp((uint8_t  *)(&(Context[cc].reg[reg2])), (uint8_t  *)(Context[cc].reg[reg1]) + disp23, 4);
	memcp((uint8_t  *)(&(Context[cc].reg[reg2 + 1])), (uint8_t  *)(Context[cc].reg[reg1]) + disp23 + 4, 4);

	Context[cc].delay += delay_st23dw * TargetClock;
}

void op_addfd(uint32_t reg1, uint32_t reg2, uint32_t reg3)
{
	uint32_t cc = CurrentCore;
	longdouble  d1, d2, d3;
	/* RH850‚Ì”{¸“x•‚“®¬”“_”‚ðC‚Ì”{¸“x•‚“®¬”“_”‚É•ÏŠ·*/
	d1.twolong32.tw = Context[cc].reg[reg1];  d1.twolong32.bw = Context[cc].reg[reg1 + 1];
	d2.twolong32.tw = Context[cc].reg[reg2];  d2.twolong32.bw = Context[cc].reg[reg2 + 1];
	/* C‚Ì”{¸“x•‚“®¬”“_”‚Å‚Ì‰ÁŽZ*/
	d3.d64 = d1.d64 + d2.d64;
	/* C‚Ì”{¸“x•‚“®¬”“_”‚ðRH850‚Ì”{¸“x•‚“®¬”“_”‚É•ÏŠ· */
	Context[cc].reg[reg3] = d3.twolong32.tw; Context[cc].reg[reg3 + 1] = d3.twolong32.bw;

	Context[cc].delay += delay_addfd * TargetClock;

}


void op_subfd(uint32_t reg1, uint32_t reg2, uint32_t reg3)
{
	uint32_t cc = CurrentCore;
	longdouble  d1, d2, d3;
	/* RH850‚Ì”{¸“x•‚“®¬”“_”‚ðC‚Ì”{¸“x•‚“®¬”“_”‚É•ÏŠ·*/
	d1.twolong32.tw = Context[cc].reg[reg1];  d1.twolong32.bw = Context[cc].reg[reg1 + 1];
	d2.twolong32.tw = Context[cc].reg[reg2];  d2.twolong32.bw = Context[cc].reg[reg2 + 1];
	/* C‚Ì”{¸“x•‚“®¬”“_”‚Å‚ÌŒ¸ŽZ*/
	d3.d64 = d2.d64 - d1.d64;
	/* C‚Ì”{¸“x•‚“®¬”“_”‚ðRH850‚Ì”{¸“x•‚“®¬”“_”‚É•ÏŠ· */
	Context[cc].reg[reg3] = d3.twolong32.tw; Context[cc].reg[reg3 + 1] = d3.twolong32.bw;
 
	Context[cc].delay += delay_subfd * TargetClock;
}

