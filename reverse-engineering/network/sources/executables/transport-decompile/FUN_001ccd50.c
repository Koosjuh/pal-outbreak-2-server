
void FUN_001ccd50(long param_1,undefined8 param_2,undefined8 param_3)

{
  if ((param_1 < 0x2000) || (0x20ff < param_1)) {
    if ((param_1 < 0x2400) || (0x24ff < param_1)) {
      if ((param_1 < 0x2a00) || (0x2fff < param_1)) {
        if ((param_1 < 0x1800) || (0x1fff < param_1)) {
          if ((param_1 < 0x2100) || (0x23ff < param_1)) {
            FUN_001d1d90(param_2,param_3);
            if ((*(int *)((int)param_2 + 4) != 0) && (*(char *)((int)param_2 + 0x81c) != '\x01')) {
              FUN_001d2900(param_2);
            }
          }
          else {
            FUN_001d2170(param_2,param_3);
          }
        }
        else {
          FUN_001d1e40(param_2,param_3,0x4de660,0x4e3080);
        }
      }
      else {
        FUN_001d2290(param_2,param_3);
      }
    }
    else {
      FUN_001d26f0(param_2,param_3,1);
    }
  }
  else {
    FUN_001d26f0(param_2,param_3,0);
  }
  return;
}

