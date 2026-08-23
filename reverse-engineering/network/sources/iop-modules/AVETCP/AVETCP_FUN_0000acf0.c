FUNCTION FUN_0000acf0 @ 0x0000acf0 size=84
CALLERS (3): FUN_00007000@0x00007000, FUN_0000a9f8@0x0000a9f8, FUN_0000b3d4@0x0000b3d4
CALLEES (2): FUN_00004254@0x00004254, FUN_00014e24@0x00014e24

short FUN_0000acf0(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_00004254(0);
  sVar1 = *(short *)(iVar2 + 2);
  if ((DAT_00016178 & 2) != 0) {
    FUN_00014e24("AT_TCP_Mss: MTU %d MSS %d\n",sVar1,sVar1 + -0x28);
  }
  return sVar1 + -0x28;
}


================================================================