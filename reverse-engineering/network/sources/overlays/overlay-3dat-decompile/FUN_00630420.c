FUNCTION FUN_00630420 @ 0x00630420  size=808
CALLERS (1): FUN_006352e0@0x006352e0
CALLEES (3): FUN_00630c30@0x00630c30, FUN_00630c50@0x00630c50, FUN_006343b0@0x006343b0
----------------------------------------------------------------

bool FUN_00630420(short *param_1)

{
  byte bVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  bVar2 = false;
  if ((*(char *)(iRam00715da8 + 0x1f) != '\x04') && (*(char *)(iRam00715da8 + 0x1f) != '\x05')) {
    uVar7 = (uint)*(byte *)(iRam00715da8 + 0x4a4);
    if ((0x53 < uVar7) && (uVar7 < 100)) {
      bVar2 = true;
    }
    lVar3 = FUN_00630c50();
    bVar1 = (&DAT_0068b6b0)[*(byte *)(iRam00715da8 + 0x1e)];
    uVar5 = (uint)(lVar3 != 0) ^ bVar1 & 1;
    if (uVar7 == 0x35) {
      *param_1 = *(short *)(&DAT_0068b690 + ((int)*(char *)(iRam00715da8 + 0x34) + uVar5 * 7) * 2);
    }
    else {
      if (uVar7 == 0x87) {
        uVar7 = 0;
      }
      if (uVar7 == 0x89) {
        uVar7 = 1;
      }
      if (uVar7 == 0x31) {
        uVar7 = 0x32;
      }
      if (((*(char *)(iRam00715da8 + 0x34) != '\x01') && (*(char *)(iRam00715da8 + 0x34) != '\x06'))
         && (uVar7 == 100)) {
        uVar7 = 2;
      }
      if (bVar2) {
        *param_1 = *(short *)(&DAT_0068b068 + uVar7 * 2);
      }
      else {
        lVar4 = FUN_006343b0();
        uVar6 = (uint)(lVar3 != 0);
        if (lVar4 == 0) {
          if (bVar1 == 0) {
            return false;
          }
          switch(*(undefined1 *)(iRam00715da8 + 0x34)) {
          default:
            return false;
          case 1:
          case 6:
            *param_1 = *(short *)((int)&PTR_LAB_0068af40 +
                                 (uVar7 + uVar6 * 0x72 + (bVar1 - 1 & 0xff) * 0x39) * 2);
            break;
          case 2:
          case 3:
          case 4:
          case 5:
            lVar3 = FUN_00630c30();
            if (lVar3 == 0) {
              *param_1 = *(short *)((uVar7 + uVar5 * 0x39) * 2 +
                                   (*(char *)(iRam00715da8 + 0x34) + -2) * 0xe4 + 0x68b130);
            }
            else {
              *param_1 = *(short *)(uVar7 * 2 +
                                   (*(char *)(iRam00715da8 + 0x34) + -2) * 0x72 + 0x68b4c0);
            }
          }
        }
        else {
          *param_1 = *(short *)(&DAT_0068ae50 + (uVar7 + uVar6 * 0x39) * 2);
        }
      }
    }
    return *param_1 != -1;
  }
  return false;
}



================================================================