FUNCTION FUN_00637710 @ 0x00637710  size=404
CALLERS (2): FUN_006345e0@0x006345e0, FUN_00637140@0x00637140
CALLEES (0): 
----------------------------------------------------------------

void FUN_00637710(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)((int)piRam00715da8 + 0x1d);
  if (cVar1 == '\x06') {
    *piRam00715da8 = (int)&PTR_DAT_006923ec;
  }
  else if (((cVar1 == '\n') || (cVar1 == '\t')) || (cVar1 == '\b')) {
    uVar2 = (uint)*(byte *)((int)piRam00715da8 + 0x1e);
    if (uVar2 != 0xb) {
      if (uVar2 != 3) {
        if (uVar2 == 0xf) {
          *piRam00715da8 = (int)&PTR_DAT_006923c4;
        }
        else if (uVar2 == 7) {
          *piRam00715da8 = (int)&PTR_DAT_006923b0;
        }
        else if (uVar2 == 10) {
          *piRam00715da8 = (int)&PTR_DAT_0069239c;
        }
        else if (uVar2 == 2) {
          *piRam00715da8 = (int)&PTR_DAT_00692388;
        }
        else {
          *piRam00715da8 = uVar2 * 0x14 + 0x692220;
        }
        goto LAB_0063784c;
      }
      *(undefined1 *)((int)piRam00715da8 + 0x1e) = 0xb;
    }
    *piRam00715da8 = (int)&PTR_DAT_006923d8;
  }
  else if (cVar1 == '\a') {
    *piRam00715da8 = (int)&PTR_DAT_00692374;
  }
  else {
    *piRam00715da8 = (uint)*(byte *)((int)piRam00715da8 + 0x1e) * 0x14 + 0x692220;
  }
LAB_0063784c:
  if ((*(char *)((int)piRam00715da8 + 0x1f) == '\x04') &&
     ((*(byte *)((int)piRam00715da8 + 0x35) & 0xf) != 0)) {
    if ((piRam00715da8[8] & 0x8000U) == 0) {
      *piRam00715da8 = (int)&PTR_DAT_0069234c;
    }
    else {
      *piRam00715da8 = (int)&PTR_DAT_006922ac;
    }
  }
  return;
}



================================================================