FUNCTION FUN_00603e40 @ 0x00603e40  size=228
CALLERS (4): FUN_005fe620@0x005fe620, FUN_005ff950@0x005ff950, FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40
CALLEES (3): FUN_00603f30@0x00603f30, FUN_00618b60@0x00618b60, FUN_00604180@0x00604180
----------------------------------------------------------------

void FUN_00603e40(char *param_1)

{
  long lVar1;
  
  if (param_1[0xe] == '\x01') {
    lVar1 = FUN_00604180();
    if (lVar1 == 0) {
      param_1[1] = '\0';
      if (*param_1 == '\f') {
        param_1[0xe] = '\x03';
        param_1[0xf] = '\0';
        param_1[0x10] = '\0';
        param_1[0x11] = '\0';
        param_1[0x907] = '\0';
        param_1[0x908] = param_1[0x44c];
        param_1[0x909] = '\0';
        FUN_00618b60();
      }
      else if (*param_1 == '\x04') {
        param_1[0xe] = '\0';
        param_1[0xf] = '\x06';
        param_1[0x10] = '\0';
        param_1[0x11] = '\0';
      }
      else {
        if (param_1[0x10b3] == '\0') {
          param_1[0xe] = '\0';
        }
        else {
          param_1[0xe] = '\x04';
        }
        param_1[0xf] = '\0';
        param_1[0x10] = '\0';
        param_1[0x11] = '\0';
      }
    }
  }
  else if (param_1[0xe] == '\0') {
    param_1[0xe] = '\x01';
    FUN_00603f30();
  }
  return;
}



================================================================