FUNCTION FUN_0001306c @ 0x0001306c size=96
CALLERS (1): FUN_000086c8@0x000086c8
CALLEES (2): FUN_00012ff8@0x00012ff8, FUN_00012eb0@0x00012eb0

void FUN_0001306c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 4) && (iVar1 = FUN_00012eb0(param_4,param_5,param_6,0), iVar1 != 0)) {
    uVar2 = FUN_00012ff8(*(undefined4 *)(iVar1 + 0x18),param_3);
    *(undefined4 *)(iVar1 + 0x18) = uVar2;
  }
  return;
}


================================================================