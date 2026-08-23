FUNCTION FUN_0061f680 @ 0x0061f680  size=212
CALLERS (11): FUN_00624850@0x00624850, FUN_00623be0@0x00623be0, FUN_00627540@0x00627540, FUN_00625190@0x00625190, FUN_00625670@0x00625670, FUN_00620d60@0x00620d60, FUN_00625ea0@0x00625ea0, FUN_00626900@0x00626900, FUN_0061f9f0@0x0061f9f0, FUN_0061fd70@0x0061fd70, FUN_00622d60@0x00622d60
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061f680(undefined1 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 0xd:
  case 0xe:
    if (cRam00715312 < '\b') {
      *(undefined1 *)(cRam00715312 + 0x715320) = param_1;
      *(undefined1 *)(cRam00715312 + 0x715328) = 1;
      cRam00715312 = cRam00715312 + '\x01';
    }
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xf:
  case 0x10:
    if (cRam00715313 < '\b') {
      *(undefined1 *)(cRam00715313 + 0x715330) = param_1;
      *(undefined1 *)(cRam00715313 + 0x715338) = 1;
      cRam00715313 = cRam00715313 + '\x01';
    }
  }
  return;
}



================================================================