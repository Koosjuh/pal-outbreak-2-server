FUNCTION FUN_00006ecc @ 0x00006ecc size=160
CALLERS (1): FUN_00001e44@0x00001e44
CALLEES (2): FUN_00010aac@0x00010aac, FUN_00010aa4@0x00010aa4

undefined4 FUN_00006ecc(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_3 + 0x30);
  uVar1 = FUN_00010aac();
  if (0x7f < uVar1) {
    *(undefined1 *)(param_1 + 0x7f) = 0;
  }
  uVar1 = FUN_00010aac(param_2);
  if (0x7f < uVar1) {
    *(undefined1 *)(param_2 + 0x7f) = 0;
  }
  FUN_00010aa4(&DAT_00013490,param_1);
  FUN_00010aa4(&DAT_00013510,param_2);
  *puVar2 = &DAT_00013490;
  puVar2[1] = &DAT_00013510;
  return 0;
}


================================================================