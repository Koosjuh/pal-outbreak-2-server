FUNCTION FUN_000048fc @ 0x000048fc size=228
CALLERS (1): FUN_00004b68@0x00004b68
CALLEES (0): 

undefined4 FUN_000048fc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  *(uint *)(param_2 + 0x18) = uVar2;
  uVar1 = *(uint *)(param_1 + 0x1c);
  if (((uVar1 < *(uint *)(param_1 + 0x18)) && (uVar1 != 0)) || (uVar1 == 0xffffffff)) {
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  }
  else {
    *(uint *)(param_2 + 0x1c) = uVar2 >> 1;
  }
  uVar1 = *(uint *)(param_1 + 0x20);
  if (((*(uint *)(param_2 + 0x1c) < uVar1) && (uVar1 < *(uint *)(param_1 + 0x18))) ||
     (uVar1 == 0xffffffff)) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    *(uint *)(param_2 + 0x20) =
         (*(uint *)(param_2 + 0x18) >> 2) * 3 + (*(uint *)(param_2 + 0x1c) >> 2);
  }
  if (((*(int *)(param_2 + 0x18) != 0) && (*(int *)(param_2 + 0x1c) != 0)) &&
     (*(int *)(param_2 + 0x20) != 0)) {
    return 0;
  }
  return 0xffffffff;
}


================================================================