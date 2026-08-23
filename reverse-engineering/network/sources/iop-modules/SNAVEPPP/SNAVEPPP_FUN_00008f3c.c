FUNCTION FUN_00008f3c @ 0x00008f3c size=112
CALLERS (3): FUN_0000e0e0@0x0000e0e0, FUN_0000985c@0x0000985c, FUN_00006f6c@0x00006f6c
CALLEES (2): FUN_00001c68@0x00001c68, FUN_0000075c@0x0000075c

undefined4 FUN_00008f3c(undefined1 *param_1,undefined4 param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 auStack_e [6];
  
  if (param_1 != (undefined1 *)0x0) {
    sVar1 = FUN_0000075c(param_2,&local_10,4);
    if (3 < sVar1) {
      *param_1 = local_10;
      param_1[1] = local_f;
      uVar2 = FUN_00001c68(auStack_e);
      *(undefined2 *)(param_1 + 2) = uVar2;
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================