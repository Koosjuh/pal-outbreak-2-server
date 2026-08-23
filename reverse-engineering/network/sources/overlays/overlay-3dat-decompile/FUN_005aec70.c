FUNCTION FUN_005aec70 @ 0x005aec70  size=324
CALLERS (8): FUN_005fe620@0x005fe620, FUN_00616c40@0x00616c40, FUN_0062d5e0@0x0062d5e0, FUN_005ff950@0x005ff950, FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40, FUN_00617a50@0x00617a50, FUN_005acab0@0x005acab0
CALLEES (6): FUN_00616bd0@0x00616bd0, FUN_006179e0@0x006179e0, FUN_005ff830@0x005ff830, FUN_005f7690@0x005f7690, FUN_005f8c20@0x005f8c20, FUN_0062d560@0x0062d560
----------------------------------------------------------------

undefined4 FUN_005aec70(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1[0x45a] != '\0') {
    if (param_1[0x455] == '\0') {
      if (param_1[0x991] == '\x01') {
        FUN_006179e0(param_1,0);
        uVar2 = 1;
      }
      else if (param_1[0x991] == '\x02') {
        FUN_006179e0();
        uVar2 = 1;
      }
      else {
        cVar1 = *param_1;
        if (cVar1 == '\x0e') {
          if (param_1[0x45d] == '\x01') {
            FUN_0062d560(param_1,0);
            return 1;
          }
        }
        else if (cVar1 == '\x04') {
          if (param_1[0x45d] == '\x01') {
            FUN_005ff830();
            return 1;
          }
        }
        else if (cVar1 == '\x03') {
          if (param_1[0x45c] == '\x01') {
            FUN_005f8c20();
            return 1;
          }
          if (param_1[0x45d] == '\x01') {
            FUN_005f8c20(param_1,2);
            return 1;
          }
        }
        else if ((cVar1 == '\x02') && ((param_1[0x45b] == '\x01' || (param_1[0x45c] == '\x01')))) {
          FUN_005f7690(param_1,1);
          return 1;
        }
        uVar2 = 0;
      }
    }
    else {
      FUN_00616bd0();
      uVar2 = 1;
    }
  }
  return uVar2;
}



================================================================