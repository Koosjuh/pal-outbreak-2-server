FUNCTION FUN_00011184 @ 0x00011184 size=96
CALLERS (0): 
CALLEES (3): FUN_0000e180@0x0000e180, FUN_0000a9c0@0x0000a9c0, FUN_0000e770@0x0000e770

undefined4 FUN_00011184(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  iVar1 = FUN_0000e180();
  uVar2 = 0xfffffe00;
  if (iVar1 == 0) {
    FUN_0000a9c0(param_1 + 4,local_18,4);
    uVar2 = FUN_0000e770(local_18[0]);
  }
  return uVar2;
}


================================================================