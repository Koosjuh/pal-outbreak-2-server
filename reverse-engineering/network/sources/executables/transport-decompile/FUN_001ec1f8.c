
int FUN_001ec1f8(int param_1,undefined4 *param_2,ushort param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  long lVar2;
  ulong uVar3;
  int iStack_4c;
  
  iStack_4c = -0x1f3c;
  *param_2 = 0;
  if (param_4 == 0) {
    if ((uint)param_3 <= *(ushort *)(param_1 + 0x6a) - 0x2c) {
      lVar2 = FUN_001eb2fc(param_1 + 0x28,1);
      if ((lVar2 == 0) || (param_5 == 0)) {
        iStack_4c = FUN_001eb434(param_1 + 0x28,param_2);
        if (iStack_4c == 0) {
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          uVar3 = FUN_001eb2d4(param_1 + 0x28);
          if (uVar3 < *(ushort *)(param_1 + 0x6c)) {
            uVar1 = FUN_001eb2d4(param_1 + 0x28);
            *(undefined2 *)(param_1 + 0x6c) = uVar1;
          }
          uVar3 = FUN_001eb2d4(param_1 + 0x28);
          if (*(ushort *)(param_1 + 0x74) <= uVar3) {
            return 0;
          }
          FUN_001eb33c(param_1 + 0x28,1);
          return 0;
        }
        if (iStack_4c != -0x1b56) {
          return iStack_4c;
        }
      }
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    }
    if ((uint)param_3 <= *(ushort *)(param_1 + 100) - 0x2c) {
      lVar2 = FUN_001eb2fc(param_1 + 0x14,1);
      if ((lVar2 == 0) || (param_5 == 0)) {
        iStack_4c = FUN_001eb434(param_1 + 0x14,param_2);
        if (iStack_4c == 0) {
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
          uVar3 = FUN_001eb2d4(param_1 + 0x14);
          if (uVar3 < *(ushort *)(param_1 + 0x66)) {
            uVar1 = FUN_001eb2d4(param_1 + 0x14);
            *(undefined2 *)(param_1 + 0x66) = uVar1;
          }
          uVar3 = FUN_001eb2d4(param_1 + 0x14);
          if (*(ushort *)(param_1 + 0x72) <= uVar3) {
            return 0;
          }
          FUN_001eb33c(param_1 + 0x14,1);
          return 0;
        }
        if (iStack_4c != -0x1b56) {
          return iStack_4c;
        }
      }
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    }
    if (*(ushort *)(param_1 + 0x5e) - 0x2c < (uint)param_3) {
      return iStack_4c;
    }
    lVar2 = FUN_001eb2fc(param_1,1);
    if ((lVar2 == 0) || (param_5 == 0)) {
      iStack_4c = FUN_001eb434(param_1,param_2);
      if (iStack_4c == 0) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
        uVar3 = FUN_001eb2d4(param_1);
        if (uVar3 < *(ushort *)(param_1 + 0x60)) {
          uVar1 = FUN_001eb2d4(param_1);
          *(undefined2 *)(param_1 + 0x60) = uVar1;
        }
        uVar3 = FUN_001eb2d4(param_1);
        if (*(ushort *)(param_1 + 0x70) <= uVar3) {
          return 0;
        }
        FUN_001eb33c(param_1,1);
        return 0;
      }
      if (iStack_4c != -0x1b56) {
        return iStack_4c;
      }
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    return iStack_4c;
  }
  if ((uint)param_3 <= *(ushort *)(param_1 + 0x5e) - 0x2c) {
    lVar2 = FUN_001eb2fc(param_1,1);
    if ((lVar2 == 0) || (param_5 == 0)) {
      iStack_4c = FUN_001eb434(param_1,param_2);
      if (iStack_4c == 0) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
        uVar3 = FUN_001eb2d4(param_1);
        if (uVar3 < *(ushort *)(param_1 + 0x60)) {
          uVar1 = FUN_001eb2d4(param_1);
          *(undefined2 *)(param_1 + 0x60) = uVar1;
        }
        uVar3 = FUN_001eb2d4(param_1);
        if (*(ushort *)(param_1 + 0x70) <= uVar3) {
          return 0;
        }
        FUN_001eb33c(param_1,1);
        return 0;
      }
      if (iStack_4c != -0x1b56) {
        return iStack_4c;
      }
    }
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  }
  if ((uint)param_3 <= *(ushort *)(param_1 + 100) - 0x2c) {
    lVar2 = FUN_001eb2fc(param_1 + 0x14,1);
    if ((lVar2 == 0) || (param_5 == 0)) {
      iStack_4c = FUN_001eb434(param_1 + 0x14,param_2);
      if (iStack_4c == 0) {
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
        uVar3 = FUN_001eb2d4(param_1 + 0x14);
        if (uVar3 < *(ushort *)(param_1 + 0x66)) {
          uVar1 = FUN_001eb2d4(param_1 + 0x14);
          *(undefined2 *)(param_1 + 0x66) = uVar1;
        }
        uVar3 = FUN_001eb2d4(param_1 + 0x14);
        if (*(ushort *)(param_1 + 0x72) <= uVar3) {
          return 0;
        }
        FUN_001eb33c(param_1 + 0x14,1);
        return 0;
      }
      if (iStack_4c != -0x1b56) {
        return iStack_4c;
      }
    }
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  }
  if (*(ushort *)(param_1 + 0x6a) - 0x2c < (uint)param_3) {
    return iStack_4c;
  }
  lVar2 = FUN_001eb2fc(param_1 + 0x28,1);
  if ((lVar2 == 0) || (param_5 == 0)) {
    iStack_4c = FUN_001eb434(param_1 + 0x28,param_2);
    if (iStack_4c == 0) {
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      uVar3 = FUN_001eb2d4(param_1 + 0x28);
      if (uVar3 < *(ushort *)(param_1 + 0x6c)) {
        uVar1 = FUN_001eb2d4(param_1 + 0x28);
        *(undefined2 *)(param_1 + 0x6c) = uVar1;
      }
      uVar3 = FUN_001eb2d4(param_1 + 0x28);
      if (*(ushort *)(param_1 + 0x74) <= uVar3) {
        return 0;
      }
      FUN_001eb33c(param_1 + 0x28,1);
      return 0;
    }
    if (iStack_4c != -0x1b56) {
      return iStack_4c;
    }
  }
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return iStack_4c;
}

