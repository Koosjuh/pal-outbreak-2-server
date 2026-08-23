FUNCTION FUN_00004f20 @ 0x00004f20 size=192
CALLERS (3): FUN_00001cb0@0x00001cb0, FUN_0000d3e0@0x0000d3e0, FUN_00004fe0@0x00004fe0
CALLEES (3): FUN_0000a720@0x0000a720, FUN_00010c38@0x00010c38, FUN_0000a624@0x0000a624

undefined4 FUN_00004f20(short param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x81) {
    FUN_0000a720(&DAT_00014994);
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PPP: phase ==> Link Dead\n");
    }
    DAT_00014990 = '\0';
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
    if (param_1 == 0x82) {
      if (DAT_00014990 == '\0') {
        if ((DAT_00012efc & 2) != 0) {
          FUN_00010c38("  PPP: phase ==> Link Establishment\n");
        }
        DAT_00014990 = '\x01';
      }
      FUN_0000a624(&DAT_00014994);
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================