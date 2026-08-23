FUNCTION FUN_00000758 @ 0x00000758 size=400
CALLERS (0): 
CALLEES (2): FUN_0000220c@0x0000220c, FUN_00002214@0x00002214

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00000758(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  if (((param_1 < 2) ||
      ((iVar1 = -1, (&DAT_00002708)[param_1] != 0 && (iVar1 = -1, (&DAT_00002718)[param_1] != 0))))
     && (iVar1 = FUN_00002214(DAT_000026b0), -1 < iVar1)) {
    if (_DAT_b0000002 < 0x11) {
      _DAT_b0000024 = (ushort)param_1 & 3 | 4;
    }
    else {
      _DAT_b0000024 = (ushort)param_1 & 1 | 6;
    }
    if ((code *)(&DAT_00002708)[param_1] != (code *)0x0) {
      (*(code *)(&DAT_00002708)[param_1])(param_3,param_4);
    }
    _DAT_bf801518 = param_4 | 0x41000200;
    do {
    } while ((_DAT_bf801518 & 0x1000000) != 0);
    _DAT_bf801510 = param_2;
    _DAT_bf801514 = param_3;
    if ((code *)(&DAT_00002718)[param_1] != (code *)0x0) {
      (*(code *)(&DAT_00002718)[param_1])(param_3,param_4);
    }
    FUN_0000220c(DAT_000026b0);
    iVar1 = 0;
  }
  return iVar1;
}


================================================================