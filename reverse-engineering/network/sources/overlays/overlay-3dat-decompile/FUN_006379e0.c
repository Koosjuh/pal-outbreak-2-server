FUNCTION FUN_006379e0 @ 0x006379e0  size=424
CALLERS (2): FUN_00636890@0x00636890, FUN_00635900@0x00635900
CALLEES (9): FUN_00637c40@0x00637c40, FUN_00637bf0@0x00637bf0, FUN_00637ca0@0x00637ca0, FUN_00637c70@0x00637c70, FUN_00637430@0x00637430, FUN_00632290@0x00632290, FUN_00637980@0x00637980, FUN_00637ba0@0x00637ba0, FUN_00637b90@0x00637b90
----------------------------------------------------------------

undefined8 FUN_006379e0(char *param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (*(short *)(param_1 + 4) == 0) {
    uVar3 = 1;
  }
  else if (param_1[2] == '\x01') {
    lVar2 = FUN_00637430(param_1[3],0,0);
    uVar3 = uVar4;
    if (lVar2 != 0) {
      uVar3 = 1;
    }
  }
  else {
    lVar2 = FUN_00632290();
    uVar3 = 1;
    if (lVar2 == 1) {
      if (((param_1[2] != '\x02') || (param_1[3] != '\x01')) &&
         (lVar2 = FUN_00637980(*(undefined2 *)(param_1 + 4)), uVar3 = uVar4, lVar2 != 0)) {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 0;
      if ((*param_1 != -0x2f) && (uVar3 = uVar4, *param_1 != '}')) {
        cVar1 = *(char *)(iRam00715da8 + 0x1d);
        if (cVar1 == '\x06') {
          lVar2 = FUN_00637c40(*(undefined2 *)(param_1 + 4));
          if ((lVar2 == 0) && (lVar2 = FUN_00637c70(*(undefined2 *)(param_1 + 4)), lVar2 == 0)) {
            uVar3 = 1;
          }
        }
        else if (cVar1 == '\a') {
          lVar2 = FUN_00637ca0(*(undefined2 *)(param_1 + 4));
          if (lVar2 == 0) {
            uVar3 = 1;
          }
        }
        else {
          if ((cVar1 != '\x01') && (cVar1 != '\x02')) {
            if (cVar1 != '\x05') {
              if (cVar1 != '\x0f') {
                return 0;
              }
              lVar2 = FUN_00637b90(*(undefined2 *)(param_1 + 4));
              if (lVar2 != 0) {
                return 0;
              }
              return 1;
            }
            lVar2 = FUN_00637bf0(*(undefined2 *)(param_1 + 4));
            if (lVar2 == 0) {
              return 1;
            }
          }
          lVar2 = FUN_00637ba0(*(undefined2 *)(param_1 + 4));
          if (lVar2 == 0) {
            uVar3 = 1;
          }
        }
      }
    }
  }
  return uVar3;
}



================================================================