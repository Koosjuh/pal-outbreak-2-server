FUNCTION FUN_00000b78 @ 0x00000b78 size=148
CALLERS (1): FUN_00000a64@0x00000a64
CALLEES (3): FUN_00002cf4@0x00002cf4, FUN_00002cfc@0x00002cfc, FUN_00002cec@0x00002cec

undefined4 FUN_00000b78(short param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  sVar3 = FUN_00002cfc(iVar6);
  uVar4 = 0xffffffff;
  if (sVar3 == 0) {
    iVar5 = FUN_00002cec(iVar6);
    if (iVar5 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined1 *)(iVar5 + 0x1c);
      uVar2 = *(undefined1 *)(iVar5 + 0x1d);
      *param_2 = *(undefined4 *)(iVar5 + 0x18);
      *(undefined1 *)(param_2 + 1) = uVar1;
      *(undefined1 *)((int)param_2 + 5) = uVar2;
      sVar3 = FUN_00002cf4(iVar6);
      uVar4 = 0xffffffff;
      if (sVar3 == 0) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


================================================================