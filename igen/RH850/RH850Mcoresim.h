/* general definitions */
typedef unsigned long uint32_t;
typedef unsigned char uint8_t;



#define MEMSIZE     0x100
#define STACKSIZE	0x100
#define MAXREG		32
#define MAXCORE		2

#define REG0	0
#define REG1	1
#define REG2	2
#define REG3	3
#define REG4	4
#define REG5	5
#define REG6	6
#define REG7	7
#define REG8	8
#define REG9	9
#define REG10	10
#define REG11	11
#define REG12	12
#define REG13	13
#define REG14	14
#define REG15	15
#define REG16	16
#define REG17	17
#define REG18	18
#define REG19	19
#define REG20	20
#define REG21	21
#define REG22	22
#define REG23	23
#define REG24	24
#define REG25	25
#define REG26	26
#define REG27	27
#define REG28	28
#define REG29	29
#define REG30	30
#define REG31	31
#define SP		REG3
#define GP		REG4
#define TP		REG5
#define EP		REG30
#define LP		REG31

typedef struct context {
  uint32_t stack[STACKSIZE];
  uint32_t reg[MAXREG];
  uint32_t pws;
  double  delay;
} CoreContext;


typedef union {
	struct {
		unsigned long  tw;
		unsigned long  bw;
	} twolong32;
	double  d64;
}   longdouble;


extern CoreContext Context[MAXCORE];
extern uint32_t CurrentCore;

#define beginCore(cc)   CurrentCore = cc;
#define endCore(cc)    // So far no thing`

#define MeasuredClock		80.0
#define TargetClock		80.0

#define	delay_ld23dw  (0.0000006/MeasuredClock)
#define	delay_st23dw  (0.0000004/MeasuredClock)
#define delay_addfd   (0.0000007/MeasuredClock)
#define delay_subfd   (0.0000007/MeasuredClock)


typedef double		  real_T;  /* for compatibility with real_T in s-fucntion */
typedef double		  time_T;  /* for compatibility with time_T in s-fucntion */


void op_ld23dw(uint32_t disp23, uint32_t reg1, uint32_t reg2);
void op_st23dw(uint32_t reg2, int disp23, uint32_t reg1);
void op_addfd(uint32_t reg1, uint32_t reg2, uint32_t reg3);
void op_subfd(uint32_t reg1, uint32_t reg2, uint32_t reg3);


