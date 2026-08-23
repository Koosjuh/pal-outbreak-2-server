FUNCTION FUN_0000e318 @ 0x0000e318 size=280
CALLERS (1): FUN_0000081c@0x0000081c
CALLEES (1): FUN_0000e430@0x0000e430

undefined4 FUN_0000e318(ushort param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  
  sVar1 = DAT_00016196;
  if (param_2 == (short *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar4 = (int)(short)param_1;
    uVar3 = 0xffffffff;
    if (((((-1 < iVar4) && (uVar3 = 0xffffffff, iVar4 <= DAT_000168e0)) &&
         (uVar3 = 0xffffffff, (&DAT_00016190)[iVar4] == 0)) && (uVar3 = 0xffffffff, *param_2 == 0))
       && (((iVar4 = *(int *)(param_2 + 4), iVar4 == 0 || (iVar4 == 2)) ||
           (uVar3 = 0xffffffff, iVar4 == 4)))) {
      param_2[1] = param_1;
      uVar2 = FUN_0000e430(param_2,&DAT_00016190,(int)sVar1);
      if (((short)uVar2 < 0) || (uVar3 = 0xffffffff, uVar2 == param_1)) {
        *(short **)((int)&DAT_00016190 + ((int)((uint)param_1 << 0x10) >> 0xe)) = param_2;
        DAT_000168e0 = DAT_000168e0 + 1;
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


================================================================