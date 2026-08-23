FUNCTION FUN_00003bac @ 0x00003bac size=200
CALLERS (1): FUN_000032d4@0x000032d4
CALLEES (3): FUN_00012608@0x00012608, FUN_00003c74@0x00003c74, FUN_000010a8@0x000010a8

undefined2 FUN_00003bac(void)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  
  if (DAT_0001616e == 0) {
    uVar1 = FUN_00012608();
    DAT_0001616e = uVar1 & 0x3ff | 0x400;
  }
  while( true ) {
    DAT_0001616e = DAT_0001616e + 1;
    uVar2 = FUN_000010a8((int)(short)DAT_0001616e);
    sVar3 = FUN_00003c74(uVar2);
    if (sVar3 != 1) break;
    if (0x7fe < DAT_0001616e) {
      DAT_0001616e = 0x400;
    }
  }
  uVar2 = FUN_000010a8((int)(short)DAT_0001616e);
  return uVar2;
}


================================================================