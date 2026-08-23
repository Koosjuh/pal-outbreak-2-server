FUNCTION FUN_0000a930 @ 0x0000a930 size=200
CALLERS (1): FUN_00004620@0x00004620
CALLEES (2): FUN_00012608@0x00012608, FUN_00011d00@0x00011d00

undefined4 FUN_0000a930(void)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  DAT_0001616a = 0;
  FUN_00011d00(&DAT_000168d4,&DAT_00015748,4);
  iVar1 = DAT_00016180;
  uVar3 = (uint)DAT_0001619b;
  iVar5 = 0;
  if (uVar3 != 0) {
    do {
      sVar2 = (short)iVar5;
      iVar5 = iVar5 + 1;
      iVar4 = sVar2 * 0x17c + iVar1;
      *(undefined2 *)(iVar4 + 0x13c) = 0xffff;
      *(undefined2 *)(iVar4 + 0x138) = 0;
    } while (iVar5 * 0x10000 >> 0x10 < (int)uVar3);
  }
  DAT_000168d8 = DAT_000161a4;
  DAT_00016164 = FUN_00012608();
  DAT_00016170 = 0;
  return 0;
}


================================================================