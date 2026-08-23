FUNCTION FUN_00011fb8 @ 0x00011fb8 size=384
CALLERS (1): FUN_00012170@0x00012170
CALLEES (16): FUN_00019a08@0x00019a08, FUN_00019a20@0x00019a20, FUN_00019978@0x00019978, FUN_00015cb8@0x00015cb8, FUN_00019ad0@0x00019ad0, FUN_0000d41c@0x0000d41c, FUN_00019920@0x00019920, FUN_0000b4d4@0x0000b4d4, FUN_0000d508@0x0000d508, FUN_000198fc@0x000198fc, FUN_00019928@0x00019928, FUN_0000d3d4@0x0000d3d4, FUN_00017d38@0x00017d38, FUN_00018c1c@0x00018c1c, FUN_00019954@0x00019954, FUN_00019a8c@0x00019a8c

undefined4 FUN_00011fb8(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_10 [2];
  
  uVar2 = 0;
  FUN_0000d3d4();
  FUN_00019920(local_10);
  iVar1 = FUN_00019954(&DAT_00019780);
  if (iVar1 == 0) {
    iVar1 = FUN_00019954(&DAT_00019860);
    uVar2 = 1;
    if (iVar1 == 0) {
      FUN_00019a20(DAT_0001b2f0);
      FUN_00019a08(DAT_0001b2f0);
      FUN_00019ad0(DAT_0001b2e8);
      FUN_00019ad0(DAT_0001b2ec);
      FUN_0000d508(&DAT_0001b308,1);
      FUN_0000d508(&DAT_0001b300,1);
      for (piVar3 = (int *)DAT_0001b85c; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        if (piVar3[0x13] != 0) {
          FUN_00019a8c();
        }
        if (*(int *)piVar3[0x68] != 0) {
          FUN_00019a20();
          FUN_00019a08(*(undefined4 *)piVar3[0x68]);
        }
      }
      FUN_00018c1c();
      FUN_00015cb8();
      FUN_0000b4d4();
      FUN_00017d38();
      FUN_000198fc(DAT_0001b9e4);
      FUN_00019928(local_10[0]);
      return 1;
    }
  }
  FUN_00019928(local_10[0]);
  FUN_00019978("inet: can\'t unload (busy%d)\n",uVar2);
  FUN_0000d41c();
  return 2;
}


================================================================