FUNCTION FUN_000005a8 @ 0x000005a8 size=284
CALLERS (0): 
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000005a8(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      if (*(code **)((int)&DAT_000026b8 + iVar2) != (code *)0x0) {
        (**(code **)((int)&DAT_000026b8 + iVar2))(param_1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 4;
    } while (iVar3 < 0x10);
  }
  uVar1 = _DAT_b0000028 & _DAT_b000002a;
  while (uVar1 != 0) {
    uVar4 = 0;
    do {
      if (((code *)(&DAT_000026b8)[uVar4] != (code *)0x0) &&
         (((int)(uint)(_DAT_b0000028 & _DAT_b000002a) >> (uVar4 & 0x1f) & 1U) != 0)) {
        (*(code *)(&DAT_000026b8)[uVar4])(param_1);
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    uVar1 = _DAT_b0000028 & _DAT_b000002a;
  }
  return 0;
}


================================================================