FUNCTION FUN_000111e4 @ 0x000111e4 size=204
CALLERS (0): 
CALLEES (2): FUN_00019a28@0x00019a28, FUN_00019a30@0x00019a30

undefined4 FUN_000111e4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 auStack_60 [32];
  undefined4 local_40;
  
  uVar2 = 0;
  if (param_1 - 9U < 0x73) {
    FUN_00019a30(0,auStack_60);
    FUN_00019a28(0,1);
    FUN_00019a28(DAT_0001b2f0,param_1);
    for (piVar1 = (int *)DAT_0001b85c; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      FUN_00019a28(*(undefined4 *)piVar1[0x68],param_1);
    }
    FUN_00019a28(0,local_40);
  }
  else {
    uVar2 = 0xfffffe6d;
  }
  return uVar2;
}


================================================================