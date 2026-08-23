
int FUN_001ecdc0(int param_1)

{
  int iVar1;
  ulong uVar2;
  int iStack_1c;
  undefined4 auStack_18 [2];
  
  uVar2 = FUN_001eb2d4(param_1);
  if (((uVar2 == *(ushort *)(param_1 + 0x5c)) &&
      (uVar2 = FUN_001eb2d4(param_1 + 0x14), uVar2 == *(ushort *)(param_1 + 0x62))) &&
     (uVar2 = FUN_001eb2d4(param_1 + 0x28), uVar2 == *(ushort *)(param_1 + 0x68))) {
    iStack_1c = 0;
    do {
      while( true ) {
        if (iStack_1c == -0x1b56) {
          iStack_1c = 0;
          while( true ) {
            while( true ) {
              if (iStack_1c == -0x1b56) {
                iStack_1c = 0;
                while( true ) {
                  while( true ) {
                    if (iStack_1c == -0x1b56) {
                      FUN_001e2010(param_1);
                      return 0;
                    }
                    iVar1 = FUN_001eb434(param_1 + 0x28,auStack_18);
                    if (iVar1 != -0x1b56) break;
                    iStack_1c = -0x1b56;
                  }
                  if (iVar1 != 0) break;
                  iStack_1c = FUN_001ee024(auStack_18[0]);
                  if (iStack_1c != 0) {
                    return iStack_1c;
                  }
                }
                return iVar1;
              }
              iVar1 = FUN_001eb434(param_1 + 0x14,auStack_18);
              if (iVar1 != -0x1b56) break;
              iStack_1c = -0x1b56;
            }
            if (iVar1 != 0) break;
            iStack_1c = FUN_001ee024(auStack_18[0]);
            if (iStack_1c != 0) {
              return iStack_1c;
            }
          }
          return iVar1;
        }
        iStack_1c = FUN_001eb434(param_1,auStack_18);
        if (iStack_1c != -0x1b56) break;
        iStack_1c = -0x1b56;
      }
    } while ((iStack_1c == 0) && (iStack_1c = FUN_001ee024(auStack_18[0]), iStack_1c == 0));
  }
  else {
    iStack_1c = -7999;
  }
  return iStack_1c;
}

