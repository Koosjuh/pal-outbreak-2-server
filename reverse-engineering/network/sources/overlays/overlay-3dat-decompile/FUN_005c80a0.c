FUNCTION FUN_005c80a0 @ 0x005c80a0  size=1084
CALLERS (5): FUN_005ae260@0x005ae260, FUN_00624c70@0x00624c70, FUN_00608300@0x00608300, FUN_006076c0@0x006076c0, FUN_006088b0@0x006088b0
CALLEES (8): FUN_005de0f0@0x005de0f0, FUN_005d6d50@0x005d6d50, FUN_00634550@0x00634550, FUN_0061f8d0@0x0061f8d0, FUN_005e02e0@0x005e02e0, FUN_005da780@0x005da780, FUN_005dfcf0@0x005dfcf0, FUN_005ca8f0@0x005ca8f0
----------------------------------------------------------------

void FUN_005c80a0(char param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0061f8d0(0);
  FUN_005e02e0();
  FUN_005d6d50();
  FUN_005de0f0();
  uRam00700fe8 = 0;
  uRam00700ff0 = 0;
  *(undefined1 *)(iRam00715da8 + 0x49c) = 0;
  *(undefined1 *)(iRam00715da8 + 0x49d) = 0;
  if (cRam00701f20 == '\x01') {
    func_0x01212860();
    func_0x00106b60(iRam00701070,0,0x5c8);
    *(undefined1 *)(iRam00701068 + 0x60dcc) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dca) = 0;
    *(undefined4 *)(iRam00701068 + 0x68f90) = 0;
  }
  else {
    FUN_005dfcf0();
    func_0x01212860();
    uRam00701080 = 0x8710e0;
    iRam00701070 = iRam00701068 + 0x4f980;
    iRam00701078 = iRam00701068 + 0x4ff48;
    func_0x00106b60(iRam00701070,0,0x5c8);
    func_0x00106b60(uRam00701080,0,0x332c);
    func_0x00106b60(iRam00701078,0,0x24);
    func_0x00106b60(iRam00701068 + 0x68f94,0,0x80);
    FUN_005ca8f0();
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iRam00701068 + iVar1 + 0x5ffc0) = 0;
    } while (iVar2 < 500);
    *(undefined1 *)(iRam00701068 + 0x60dcc) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dce) = 1;
    *(undefined1 *)(iRam00701068 + 0x60dcd) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dcb) = 1;
    *(undefined2 *)(iRam00701070 + 0x18) = 0x2e7;
    if (param_1 == '\x01') {
      *(undefined1 *)(iRam00701070 + 0x36) = 1;
      *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
    }
    else {
      *(undefined1 *)(iRam00701070 + 0x36) = 0;
      *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
    }
    FUN_005da780(0,0);
    *(undefined1 *)(iRam00701068 + 0x60dc8) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dc9) = 0;
    *(undefined2 *)(iRam00701068 + 0x68e78) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dca) = 0;
    *(undefined4 *)(iRam00701068 + 0x68f90) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dc5) = 0;
    *(undefined4 *)(iRam00701068 + 0x68dd0) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dcf) = 0;
    *(undefined1 *)(iRam00701068 + 0x60dc4) = 0;
    func_0x00106b60(iRam00701068 + 0x68dd8,0,0x50);
    func_0x00106b60(iRam00701068 + 0x68e28,0,0x28);
    func_0x00106b60(iRam00701068 + 0x68e50,0,0x28);
    func_0x00106b60(iRam00701068 + 0x60dd0,0,0x8000);
    *(int *)(iRam00701068 + 0x68dd4) = iRam00701068 + 0x60dd0;
    func_0x001069a8(uRam00701088,0x870f10,0x1d0);
    *(int *)(iRam00701068 + 0x4db5c) = iRam00701068 + 0x4d35c;
    *(undefined4 *)(iRam00701068 + 0x4db60) = 0;
    *(undefined4 *)(iRam00701068 + 0x4db64) = 0;
    FUN_00634550(uRam0034359d);
    func_0x001b2470(3);
    func_0x001ad210(7);
  }
  return;
}



================================================================