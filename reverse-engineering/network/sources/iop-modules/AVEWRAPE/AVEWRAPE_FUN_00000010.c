FUNCTION FUN_00000010 @ 0x00000010 size=152
CALLERS (2): FUN_00000834@0x00000834, FUN_00000724@0x00000724
CALLEES (2): FUN_00002804@0x00002804, FUN_00000000@0x00000000

undefined4 FUN_00000010(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_38 [8];
  short local_30;
  short local_26;
  
  iVar1 = FUN_00000000();
  if ((iVar1 == 1) || (uVar2 = 0, iVar1 == 4)) {
    iVar1 = FUN_00002804(&DAT_00004156,0,auStack_38);
    if (iVar1 << 0x10 < 0) {
      param_1[6] = -0x10;
      uVar2 = 0xffffffff;
    }
    else if (local_30 == 4) {
      uVar2 = 0;
    }
    else {
      param_1[6] = -0x22;
      *param_1 = (int)local_26;
      uVar2 = 0xffffffff;
      param_1[1] = (int)local_30;
    }
  }
  return uVar2;
}


================================================================