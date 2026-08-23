FUNCTION FUN_00010f00 @ 0x00010f00 size=236
CALLERS (0): 
CALLEES (3): FUN_0000e1c8@0x0000e1c8, FUN_0000e180@0x0000e180, FUN_0000a9c0@0x0000a9c0

undefined4 FUN_00010f00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [2];
  
  iVar1 = FUN_0000e180();
  uVar2 = 0xfffffe00;
  if (iVar1 == 0) {
    iVar1 = FUN_0000e180(param_1 + 0x20);
    uVar2 = 0xfffffe00;
    if (iVar1 == 0) {
      if (((*(uint *)(param_1 + 0x30) & 4) != 0) &&
         (iVar1 = FUN_0000e180(param_1 + 0x10), iVar1 != 0)) {
        return 0xfffffe00;
      }
      uVar2 = 0xfffffe00;
      if ((*(uint *)(param_1 + 0x30) & 0x19) == 0) {
        FUN_0000a9c0(param_1 + 4,&local_20,4);
        FUN_0000a9c0(param_1 + 0x14,&local_1c,4);
        FUN_0000a9c0(param_1 + 0x24,local_18,4);
        uVar2 = FUN_0000e1c8(local_20,local_1c,local_18[0],*(undefined4 *)(param_1 + 0x30),
                             *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                             param_1 + 0x3c);
      }
    }
  }
  return uVar2;
}


================================================================