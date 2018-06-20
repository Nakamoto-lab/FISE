
#include "instsim.h"

void op_add(uint32_t reg1, uint32_t reg2)
{
	uint32_t cc = CurrentCore;
	Context[cc].reg[reg2] +=  Context[cc].reg[reg1]));

#ifdef DELAY
	Context[cc].delay += delay_add * TargetClock;
#endif
}


