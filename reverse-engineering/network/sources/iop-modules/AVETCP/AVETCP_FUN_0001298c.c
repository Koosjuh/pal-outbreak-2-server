FUNCTION FUN_0001298c @ 0x0001298c size=312
CALLERS (0): 
CALLEES (2): FUN_000127d0@0x000127d0, FUN_00012688@0x00012688

uint FUN_0001298c(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 != 0) {
    if (*param_1 == 0) goto LAB_00012a8c;
    while (*param_2 != 0) {
      uVar4 = (uint)*param_1;
      bVar1 = *param_2;
      uVar3 = (uint)bVar1;
      sVar2 = FUN_000127d0(uVar4);
      if (sVar2 != 0) {
        uVar4 = FUN_00012688(uVar4);
      }
      sVar2 = FUN_000127d0(bVar1);
      if (sVar2 != 0) {
        uVar3 = FUN_00012688(bVar1);
      }
      if (uVar4 << 0x10 != uVar3 << 0x10) {
        return (int)((uVar4 - uVar3) * 0x10000) >> 0x10;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      if ((param_3 == 0) || (*param_1 == 0)) break;
    }
  }
  if (*param_1 != 0) {
    return (uint)(param_3 != 0);
  }
LAB_00012a8c:
  uVar4 = 0;
  if (*param_2 != 0) {
    uVar4 = (uint)(param_3 != 0);
  }
  return uVar4;
}


================================================================