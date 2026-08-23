FUNCTION FUN_0061f600 @ 0x0061f600  size=128
CALLERS (3): FUN_00625670@0x00625670, FUN_00626e70@0x00626e70, FUN_00623800@0x00623800
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061f600(undefined1 param_1)

{
  switch(param_1) {
  case 1:
  case 2:
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
  case 0xd:
  case 0xe:
  case 0xf:
    if (cRam00715313 < '\b') {
      *(undefined1 *)(cRam00715313 + 0x715330) = param_1;
      *(undefined1 *)(cRam00715313 + 0x715338) = 3;
      cRam00715313 = cRam00715313 + '\x01';
    }
  }
  return;
}



================================================================