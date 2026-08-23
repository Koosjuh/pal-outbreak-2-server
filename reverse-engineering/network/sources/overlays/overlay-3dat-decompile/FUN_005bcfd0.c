FUNCTION FUN_005bcfd0 @ 0x005bcfd0  size=632
CALLERS (0): 
CALLEES (4): FUN_005c7f20@0x005c7f20, FUN_005c7e30@0x005c7e30, FUN_005bc860@0x005bc860, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bcfd0(undefined4 *param_1)

{
  long lVar1;
  long lVar2;
  undefined1 auStack_50 [64];
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  iStack_8 = param_1[2];
  if ((char)uStack_10 == '\0') {
    lVar1 = func_0x001bf030();
    if (lVar1 == 0) {
      FUN_005bc860(0xb);
      func_0x001de648(uRam006febac,0xfffffffff7e00001,0x5bcee0);
    }
    else {
      FUN_005c7e30();
      FUN_005bdf90(2,0);
    }
  }
  else {
    func_0x00106b60(0x6fc5e8,0,0x300);
    if (iStack_8 == -0x3a) {
      func_0x0010a4f0(0x6fc5e8,uRam00365df8,0x300);
      FUN_005bdf90(2,0);
    }
    else {
      if (iStack_8 == -0x3b) {
        lVar2 = 1;
        lVar1 = 0x3b;
      }
      else if (iStack_8 == -0x3c) {
        lVar2 = 1;
        lVar1 = 0x3c;
      }
      else if (iStack_8 == -0x3d) {
        lVar2 = 1;
        lVar1 = 0x3d;
      }
      else if (iStack_8 == -0x3e) {
        lVar2 = 1;
        lVar1 = 0x3e;
      }
      else if (iStack_8 == -0x3f) {
        lVar2 = 1;
        lVar1 = 0x3f;
      }
      else if (iStack_8 == -1) {
        lVar2 = 1;
        lVar1 = 1;
      }
      else if (iStack_8 == 8) {
        lVar2 = 1;
        lVar1 = 8;
      }
      else if (iStack_8 == 6) {
        lVar2 = 1;
        lVar1 = 6;
      }
      else if (iStack_8 == 5) {
        lVar2 = 1;
        lVar1 = 5;
      }
      else if (iStack_8 == 4) {
        lVar2 = 1;
        lVar1 = 4;
      }
      else if (iStack_8 == 7) {
        lVar2 = 0;
        lVar1 = 7;
      }
      else if (iStack_8 == 3) {
        lVar2 = 0;
        lVar1 = 3;
      }
      else if (iStack_8 == 2) {
        lVar2 = 0;
        lVar1 = 2;
      }
      else {
        lVar2 = 1;
        lVar1 = lVar2;
        if (iStack_8 == 1) {
          lVar2 = 0;
          lVar1 = 0;
        }
      }
      if (lVar2 == 0) {
        FUN_005c7e30(8);
      }
      else {
        FUN_005c7e30(9);
      }
      FUN_005c7f20(0xe);
      func_0x00109728(auStack_50,0x639e68,lVar1);
      func_0x00109ab0(0x6fc5e8,auStack_50);
      FUN_005bdf90(2,0);
    }
  }
  return;
}



================================================================