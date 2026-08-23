FUNCTION FUN_005ca6a0 @ 0x005ca6a0  size=592
CALLERS (12): FUN_005ca480@0x005ca480, FUN_005c9a00@0x005c9a00, FUN_005ca0a0@0x005ca0a0, FUN_005ca1a0@0x005ca1a0, FUN_005ca320@0x005ca320, FUN_005c9900@0x005c9900, FUN_005ca380@0x005ca380, FUN_005c9c50@0x005c9c50, FUN_005ca4f0@0x005ca4f0, FUN_005c9690@0x005c9690, FUN_005ca420@0x005ca420, FUN_005ca290@0x005ca290, ...
CALLEES (3): FUN_005e0320@0x005e0320, FUN_005dd920@0x005dd920, FUN_005dff90@0x005dff90
----------------------------------------------------------------

void FUN_005ca6a0(void)

{
  if (((*(char *)(iRam00701070 + 0x36) == '\0') || (*(char *)(iRam00701070 + 0x2e) == '\n')) ||
     (*(char *)(iRam00701070 + 0x3a) < '\0')) {
    if (*(char *)(iRam00701070 + 0x36) == '\0') {
      FUN_005dd920(0x14,*(undefined4 *)(iRam00701070 + 0x14));
    }
    else if ((*(char *)(iRam00701068 + 0x68e85) == '\x01') &&
            (*(char *)(iRam00701070 + 0x3a) == '\0')) {
      FUN_005dd920(0x14,*(undefined4 *)(iRam00701070 + 0x14));
    }
    else {
      FUN_005dd920(0x14,0xffffffffff000000);
    }
    if (*(char *)(iRam00701068 + 0x60dca) < '\x01') {
      if (*(char *)(iRam00701068 + 0x60dcb) == '\0') {
        FUN_005dff90(0);
        FUN_005e0320(0x5da8d0);
        FUN_005dff90(1);
        FUN_005e0320(0x5dae30);
        FUN_005dff90(2);
        FUN_005e0320(0x5db120);
        FUN_005e0320(0x5db6c0);
        FUN_005e0320(0x5dbb00);
        FUN_005dff90(3);
        FUN_005e0320(0x5dbef0);
        FUN_005dff90(4);
        FUN_005e0320(0x5dc3a0);
        if (*(char *)(iRam00701068 + 0x68e84) != '\x01') {
          if (*(char *)(iRam00701070 + 0x2e) == '\n') {
            FUN_005dff90(6);
            FUN_005e0320(0x5dd3a0);
            FUN_005dff90(8);
            FUN_005e0320(0x5dca60);
          }
          else {
            FUN_005dff90(8);
            FUN_005e0320(0x5dca60);
            FUN_005dff90(6);
            FUN_005e0320(0x5dd3a0);
          }
        }
      }
      else {
        FUN_005dff90(6);
        FUN_005e0320(0x5dd3a0);
      }
    }
    else {
      FUN_005dff90(6);
      FUN_005e0320(0x5dd3a0);
      FUN_005dff90(8);
      FUN_005e0320(0x5dca60);
    }
  }
  else {
    FUN_005dd920(0x14,0xffffffffff000000);
    FUN_005dff90(6);
    FUN_005e0320(0x5dd3a0);
  }
  return;
}



================================================================