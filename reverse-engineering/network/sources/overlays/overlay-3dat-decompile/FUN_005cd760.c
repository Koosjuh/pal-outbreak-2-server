FUNCTION FUN_005cd760 @ 0x005cd760  size=88
CALLERS (1): FUN_005c9460@0x005c9460
CALLEES (0): 
----------------------------------------------------------------

void FUN_005cd760(void)

{
  *puRam00701078 = 1;
  puRam00701078[1] = 0;
  *(undefined2 *)(puRam00701078 + 0x10) = 0x96;
  *(undefined2 *)(puRam00701078 + 0x12) = 100;
  *(undefined4 *)(puRam00701078 + 0x14) = 0;
  *(undefined4 *)(puRam00701078 + 0x18) = 0;
  return;
}



================================================================