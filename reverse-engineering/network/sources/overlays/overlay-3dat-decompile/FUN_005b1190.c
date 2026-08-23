FUNCTION FUN_005b1190 @ 0x005b1190  size=648
CALLERS (5): FUN_005f60d0@0x005f60d0, FUN_0062d1b0@0x0062d1b0, FUN_005f8fc0@0x005f8fc0, FUN_00627f20@0x00627f20, FUN_00604180@0x00604180
CALLEES (2): FUN_005b16c0@0x005b16c0, FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

undefined4 FUN_005b1190(char *param_1,byte *param_2,byte param_3,byte param_4,byte param_5)

{
  byte bVar1;
  long lVar2;
  byte bVar3;
  
  lVar2 = FUN_005b14b0(0x10001);
  if (lVar2 != 0) {
    sRam006ca080 = 0x14;
LAB_005b1274:
    *param_2 = *param_2 - 1;
    if ((char)*param_2 < '\0') {
      if (*param_1 == '\0') {
        if (param_5 < 2) {
          if (param_3 < param_4) {
            *param_1 = '\0';
            *param_2 = param_3 - 1;
            if (param_3 < 2) {
              return 1;
            }
          }
          else {
            *param_1 = param_3 - param_4;
            *param_2 = param_4 - 1;
          }
          func_0x001b0140(0);
        }
        else {
          *param_2 = 0;
        }
      }
      else {
        *param_1 = *param_1 + -1;
        *param_2 = 0;
        func_0x001b0140(0);
      }
    }
    else {
      func_0x001b0140(0);
    }
    return 1;
  }
  lVar2 = FUN_005b14b0(0x20002);
  if (lVar2 == 0) {
    if (sRam006ca080 != 0) {
      sRam006ca080 = sRam006ca080 + -1;
      return 0;
    }
    lVar2 = FUN_005b16c0(0x10001);
    if (lVar2 != 0) {
      sRam006ca080 = 5;
      goto LAB_005b1274;
    }
    lVar2 = FUN_005b16c0(0x20002);
    if (lVar2 == 0) {
      return 0;
    }
    sRam006ca080 = 5;
  }
  else {
    sRam006ca080 = 0x14;
  }
  *param_2 = *param_2 + 1;
  bVar1 = *param_2;
  if ((int)(param_4 - 1) < (int)(uint)bVar1) {
    bVar3 = (byte)(param_4 - 1);
    if ((int)((uint)bVar1 + (int)*param_1) < (int)(uint)param_3) {
      *param_1 = *param_1 + '\x01';
      *param_2 = bVar3;
    }
    else {
      if (1 < param_5) {
        *param_2 = bVar3;
        return 1;
      }
      *param_1 = '\0';
      *param_2 = 0;
    }
  }
  else if ((int)(uint)param_3 <= (int)((uint)bVar1 + (int)*param_1)) {
    if (1 < param_5) {
      *param_2 = bVar1 - 1;
      return 1;
    }
    *param_1 = '\0';
    *param_2 = 0;
    if (param_3 < 2) {
      return 1;
    }
  }
  func_0x001b0140(0);
  return 1;
}



================================================================