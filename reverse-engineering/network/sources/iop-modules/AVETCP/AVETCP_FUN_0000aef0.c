FUNCTION FUN_0000aef0 @ 0x0000aef0 size=148
CALLERS (1): FUN_0000adf8@0x0000adf8
CALLEES (0): 

undefined4 FUN_0000aef0(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0001619b != 0) {
    iVar1 = 0;
    do {
      iVar1 = (iVar1 >> 0x10) * 0x17c + DAT_00016180;
      if (((*(short *)(iVar1 + 0x138) != 0) && (iVar1 != param_1)) &&
         (param_2 == *(short *)(iVar1 + 0x144))) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
  }
  return 0;
}


================================================================