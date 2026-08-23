FUNCTION FUN_00635500 @ 0x00635500  size=148
CALLERS (2): FUN_00630750@0x00630750, FUN_00637bf0@0x00637bf0
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_00635500(short param_1)

{
  if (param_1 == 0xa8) {
    uRam00715b78 = 4;
  }
  else if (param_1 == 0x7e) {
    uRam00715b78 = 3;
  }
  else if (param_1 == 0xb4) {
    uRam00715b78 = 2;
  }
  else if (param_1 == 0x60) {
    uRam00715b78 = 1;
  }
  else if (param_1 == 0x5e) {
    uRam00715b78 = 0;
  }
  else {
    uRam00715b78 = 0xff;
  }
  return uRam00715b78;
}



================================================================