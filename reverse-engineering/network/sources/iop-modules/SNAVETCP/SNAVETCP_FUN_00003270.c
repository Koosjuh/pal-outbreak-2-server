FUNCTION FUN_00003270 @ 0x00003270 size=100
CALLERS (1): FUN_00004620@0x00004620
CALLEES (0): 

undefined4 FUN_00003270(void)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_000161a0;
  uVar3 = (uint)DAT_0001617e;
  iVar4 = 0;
  if (uVar3 != 0) {
    do {
      sVar2 = (short)iVar4;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(iVar1 + sVar2 * 0x30 + 8) = 0;
    } while (iVar4 * 0x10000 >> 0x10 < (int)uVar3);
  }
  DAT_0001616e = 0;
  return 0;
}


================================================================