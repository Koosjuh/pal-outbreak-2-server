FUNCTION FUN_005d9ea0 @ 0x005d9ea0  size=1220
CALLERS (1): FUN_005e67a0@0x005e67a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d9ea0(undefined1 param_1,byte param_2,undefined8 param_3)

{
  uint uVar1;
  
  uVar1 = func_0x0010a050(param_3);
  uVar1 = uVar1 & 0xff;
  if (9 < param_2) {
    param_2 = 9;
  }
  switch(param_1) {
  case 1:
    if (0xe < uVar1) {
      uVar1 = 0xe;
    }
    func_0x001069a8(iRam00701080,param_3,uVar1 + 1);
    return;
  case 2:
    if (10 < uVar1) {
      uVar1 = 10;
    }
    func_0x001069a8(iRam00701080 + 0x11,param_3,uVar1 + 1);
    break;
  case 4:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + 0x1c,param_3,uVar1 + 1);
    break;
  case 5:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + 0x11d,param_3,uVar1 + 1);
    break;
  case 6:
    if (0x10 < uVar1) {
      uVar1 = 0x10;
    }
    func_0x001069a8(iRam00701080 + 0x21e,param_3,uVar1 + 1);
    break;
  case 7:
    if (0x61 < uVar1) {
      uVar1 = 0x61;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x62 + 0x22f,param_3,uVar1 + 1);
    break;
  case 8:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x101 + 0x603,param_3,uVar1 + 1);
    break;
  case 9:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x101 + 0x100d,param_3,uVar1 + 1);
    break;
  case 10:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x101 + 0x1a17,param_3,uVar1 + 1);
    break;
  case 0xb:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + 0x2421,param_3,uVar1 + 1);
    break;
  case 0xc:
    if (0x20 < uVar1) {
      uVar1 = 0x20;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x21 + 0x2522,param_3,uVar1 + 1);
    break;
  case 0xd:
    if (0x20 < uVar1) {
      uVar1 = 0x20;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x21 + 0x266c,param_3,uVar1 + 1);
    break;
  case 0xe:
    if (0xe < uVar1) {
      uVar1 = 0xe;
    }
    func_0x001069a8(iRam00701080 + 0x27b6,param_3,uVar1 + 1);
    break;
  case 0xf:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + 0x27c7,param_3,uVar1 + 1);
    break;
  case 0x10:
    if (2 < uVar1) {
      uVar1 = 2;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 3 + 0x28c8,param_3,uVar1 + 1);
    break;
  case 0x11:
    if (4 < uVar1) {
      uVar1 = 4;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 5 + 0x28e6,param_3,uVar1 + 1);
    break;
  case 0x12:
    if (0x100 < uVar1) {
      uVar1 = 0;
    }
    func_0x001069a8(iRam00701080 + (uint)param_2 * 0x101 + 0x2918,param_3,uVar1 + 1);
  }
  return;
}



================================================================