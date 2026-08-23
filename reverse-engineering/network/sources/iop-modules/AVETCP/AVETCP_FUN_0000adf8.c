FUNCTION FUN_0000adf8 @ 0x0000adf8 size=248
CALLERS (1): FUN_0000ca20@0x0000ca20
CALLEES (3): FUN_000010a8@0x000010a8, FUN_00012608@0x00012608, FUN_0000aef0@0x0000aef0

undefined2 FUN_0000adf8(undefined4 param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  
  if (DAT_00016170 == 0) {
    uVar1 = FUN_00012608();
    DAT_00016170 = uVar1 & 0x3ff | 0x400;
  }
  while( true ) {
    DAT_00016170 = DAT_00016170 + 1;
    uVar2 = FUN_000010a8((int)(short)DAT_00016170);
    sVar3 = FUN_0000aef0(param_1,uVar2);
    if (sVar3 != 1) break;
    if (0x7fe < DAT_00016170) {
      DAT_00016170 = 0x400;
    }
  }
  if (0x7fe < DAT_00016170) {
    DAT_00016170 = 0x400;
  }
  uVar2 = FUN_000010a8((int)(short)DAT_00016170);
  return uVar2;
}


================================================================