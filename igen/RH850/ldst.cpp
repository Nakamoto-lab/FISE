#include "instsim.h"



void op_ld23dw(uint32_t disp23, uint32_t reg1, uint32_t reg2)
{
	uint32_t cc = CurrentCore;
	memcp((uint8_t  *)(Context[cc].reg[reg1]) + disp23, (uint8_t  *)(&(Context[cc].reg[reg2])), 4);
	memcp((uint8_t  *)(Context[cc].reg[reg1]) + disp23 + 4, (uint8_t  *)(&(Context[cc].reg[reg2 + 1])), 4);

#ifdef DELAY
	Context[cc].delay += delay_ld23dw * TargetClock;
#endif
}



void op_st23dw(uint32_t reg2, int disp23, uint32_t reg1)
{
	uint32_t cc = CurrentCore;	
	memcp((uint8_t  *)(&(Context[cc].reg[reg2])), (uint8_t  *)(Context[cc].reg[reg1]) + disp23, 4);
	memcp((uint8_t  *)(&(Context[cc].reg[reg2 + 1])), (uint8_t  *)(Context[cc].reg[reg1]) + disp23 + 4, 4);

#ifdef DELAY
	Context[cc].delay += delay_st23dw * TargetClock;
#endif
}
