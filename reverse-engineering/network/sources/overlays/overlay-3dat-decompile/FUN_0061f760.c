FUNCTION FUN_0061f760 @ 0x0061f760  size=212
CALLERS (11): FUN_00627400@0x00627400, FUN_00627540@0x00627540, FUN_00625190@0x00625190, FUN_00625670@0x00625670, FUN_006265f0@0x006265f0, FUN_00619e00@0x00619e00, FUN_00620d60@0x00620d60, FUN_00625ea0@0x00625ea0, FUN_00626e70@0x00626e70, FUN_00626900@0x00626900, FUN_0061fd70@0x0061fd70
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061f760(undefined1 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 5:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    if (cRam00715313 < '\b') {
      *(undefined1 *)(cRam00715313 + 0x715330) = param_1;
      *(undefined1 *)(cRam00715313 + 0x715338) = 2;
      cRam00715313 = cRam00715313 + '\x01';
    }
    break;
  case 3:
  case 4:
  case 6:
    if (cRam00715312 < '\b') {
      *(undefined1 *)(cRam00715312 + 0x715320) = param_1;
      *(undefined1 *)(cRam00715312 + 0x715328) = 2;
      cRam00715312 = cRam00715312 + '\x01';
    }
  }
  return;
}



================================================================