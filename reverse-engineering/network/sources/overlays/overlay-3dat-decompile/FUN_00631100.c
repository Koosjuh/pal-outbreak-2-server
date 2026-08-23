FUNCTION FUN_00631100 @ 0x00631100  size=300
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (4): FUN_00637540@0x00637540, FUN_00631240@0x00631240, FUN_00637690@0x00637690, FUN_00637140@0x00637140
----------------------------------------------------------------

void FUN_00631100(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  bVar1 = *(byte *)(iRam00715da8 + 0x1e);
  pbVar3 = (byte *)(iRam00715da8 + 0x1e);
  if (bVar1 < 0x10) {
    switch((uint)bVar1) {
    default:
      uVar2 = *(uint *)(iRam00715da8 + 0x20);
      if ((uVar2 & 4) == 0) {
        *pbVar3 = 2;
      }
      else if ((uVar2 & 0x400) == 0) {
        *pbVar3 = 10;
      }
      else if ((uVar2 & 0x80) == 0) {
        *pbVar3 = 7;
      }
      else {
        if ((uVar2 & 0x8000) != 0) {
          return;
        }
        *pbVar3 = 0xf;
      }
      *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
      break;
    case 2:
    case 6:
    case 7:
      FUN_00631240();
      break;
    case 10:
    case 0xe:
    case 0xf:
      if ((*(byte *)(iRam00715da8 + 0x33) & 1) != 0) {
        return;
      }
      if ((*(uint *)(iRam00715da8 + 0x20) & 1 << (bVar1 - 8 & 0x1f)) != 0) {
        return;
      }
      *pbVar3 = bVar1 ^ 8;
      break;
    case 0xb:
    case 0xc:
    case 0xd:
      return;
    }
    FUN_00637540();
    FUN_00637690();
    FUN_00637140();
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  }
  return;
}



================================================================