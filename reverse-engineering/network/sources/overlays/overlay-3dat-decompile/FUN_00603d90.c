FUNCTION FUN_00603d90 @ 0x00603d90  size=168
CALLERS (1): FUN_006052f0@0x006052f0
CALLEES (1): FUN_00618b60@0x00618b60
----------------------------------------------------------------

void FUN_00603d90(char *param_1)

{
  if (*param_1 == '\f') {
    param_1[0xe] = '\x03';
    param_1[0xf] = '\0';
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x907] = '\0';
    param_1[0x908] = param_1[0x44c];
    param_1[0x909] = '\0';
    FUN_00618b60();
    param_1[1] = '\0';
  }
  else {
    if (*param_1 == '\x04') {
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
    param_1[1] = '\0';
  }
  return;
}



================================================================