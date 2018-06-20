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
