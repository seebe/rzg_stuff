
#define TRUE  1
#define FALSE 0
#define NULL  0x0

void* pStimulusBase = NULL;

unsigned long nPortMask = 0x1;
unsigned long nChannel  = 0;
enum {
  STP_G_DMTS   = 0x0,
  STP_G_DM     = 0x8,
  STP_G_DTS    = 0x10,
  STP_G_D      = 0x18,
  STP_G_FLAGTS = 0x60,
  STP_G_FLAG   = 0x68,
  STP_G_TRIGTS = 0x70,
  STP_G_TRIG   = 0x78,
  STP_I_DMTS   = 0x80,
  STP_I_DM     = 0x88,
  STP_I_DTS    = 0x90,
  STP_I_D      = 0x98,
  STP_I_FLAGTS = 0xE0,
  STP_I_FLAG   = 0xE8,
  STP_I_TRIGTS = 0xF0,
  STP_I_TRIG   = 0xF8
} eStimulusType;

char  bByteStimulusEnable      = 0;
char  bWordStimulusEnable      = 0;
char  bLongStimulusEnable      = 0;
char  bQuadStimulusEnable      = 0;
char  bAlternateStimulusEnable = 0;

char            pPrintfString[512] = {0,};
unsigned char   nByteStimulus = 0;
unsigned short  nWordStimulus = 0;
unsigned int    nLongStimulus = 0;
unsigned long   nQuadStimulus = 0;

#define STP_TRACE_D8(_pstmbase_,_channel_,_stimuliport_,_type_,_data_)    ((*(volatile unsigned char  *)(_pstmbase_+0x1000*_channel_+_stimuliport_*0x100+_type_))=(unsigned char )(_data_))
#define STP_TRACE_D16(_pstmbase_,_channel_,_stimuliport_,_type_,_data_)   ((*(volatile unsigned short *)(_pstmbase_+0x1000*_channel_+_stimuliport_*0x100+_type_))=(unsigned short)(_data_))
#define STP_TRACE_D32(_pstmbase_,_channel_,_stimuliport_,_type_,_data_)   ((*(volatile unsigned int   *)(_pstmbase_+0x1000*_channel_+_stimuliport_*0x100+_type_))=(unsigned int  )(_data_))
#define STP_TRACE_D64(_pstmbase_,_channel_,_stimuliport_,_type_,_data_)   ((*(volatile unsigned long  *)(_pstmbase_+0x1000*_channel_+_stimuliport_*0x100+_type_))=(unsigned long )(_data_))

void vTransferHook()
{
  asm("nop");
}

void stmPrint(unsigned long nChannel, unsigned long nPort, char * pString)
{
  if (pString[0]) {
    while (pString[0]) {
      STP_TRACE_D8(pStimulusBase, nChannel, nPort, STP_G_D, *pString++);
    }
    // the last STM packet is of type FLAG -> flush TRACE32 PrintfTrace
    STP_TRACE_D8(pStimulusBase, nChannel, nPort, STP_G_FLAG, 0);
  }
}

void (*monHook)(void) __attribute__ ((section (".data"))) = 0;
extern void (*watchdogTrigger)(void);

int main()
{
  int nCurrentPort;

  while(TRUE) {
    vTransferHook();
    
    if (monHook)
      monHook();
    if (watchdogTrigger)
      watchdogTrigger();
      
    for (nCurrentPort = 0; nCurrentPort < 32; nCurrentPort++) {
      if (nPortMask & (1<<nCurrentPort)) {
        if (pStimulusBase != NULL) {
          if (pPrintfString[0]!=0x0) {
            stmPrint(nChannel, nCurrentPort, pPrintfString);
          }

          if (bByteStimulusEnable) {
            STP_TRACE_D8 (pStimulusBase, nChannel, nCurrentPort, eStimulusType, nByteStimulus);
          }

          if (bWordStimulusEnable) {
            STP_TRACE_D16(pStimulusBase, nChannel, nCurrentPort, eStimulusType, nWordStimulus);
          }

          if (bLongStimulusEnable) {
            STP_TRACE_D32(pStimulusBase, nChannel, nCurrentPort, eStimulusType, nLongStimulus);
          }
          
          if (bQuadStimulusEnable) {
            STP_TRACE_D64(pStimulusBase, nChannel, nCurrentPort, eStimulusType, nQuadStimulus);
          }
        }
      }
    }
    
    if (bAlternateStimulusEnable) {
      if (bByteStimulusEnable) nByteStimulus = ~nByteStimulus;
      if (bWordStimulusEnable) nWordStimulus = ~nWordStimulus;
      if (bLongStimulusEnable) nLongStimulus = ~nLongStimulus;
      if (bQuadStimulusEnable) nQuadStimulus = ~nQuadStimulus;
    }
  }
}
