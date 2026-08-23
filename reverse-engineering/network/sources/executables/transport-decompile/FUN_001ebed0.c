
int FUN_001ebed0(int *param_1,ushort param_2,ushort param_3,ushort param_4)

{
  int iVar1;
  int iVar2;
  int iStack_34;
  undefined1 auStack_2c [28];
  
  iVar1 = FUN_001e1e4c(0x78);
  if (iVar1 == 0) {
    iStack_34 = -6999;
  }
  else {
    *(undefined2 *)(iVar1 + 0x5e) = 0xec;
    *(undefined2 *)(iVar1 + 100) = 0x22c;
    *(undefined2 *)(iVar1 + 0x6a) = 0x3ac;
    *(undefined2 *)(iVar1 + 0x70) = 6;
    *(undefined2 *)(iVar1 + 0x72) = 3;
    *(undefined2 *)(iVar1 + 0x74) = 3;
    FUN_001ecd28(iVar1);
    iStack_34 = FUN_001eb22c(iVar1,0);
    if (iStack_34 == 0) {
      *(undefined2 *)(iVar1 + 0x5c) = 0;
      while (*(ushort *)(iVar1 + 0x5c) < param_2) {
        iVar2 = FUN_001ebae0(iVar1,auStack_2c,*(undefined2 *)(iVar1 + 0x5e),0);
        if (iVar2 != 0) {
          return iVar2;
        }
        *(short *)(iVar1 + 0x5c) = *(short *)(iVar1 + 0x5c) + 1;
      }
      *(undefined2 *)(iVar1 + 0x60) = *(undefined2 *)(iVar1 + 0x5c);
      iStack_34 = FUN_001eb22c(iVar1 + 0x14,0);
      if (iStack_34 == 0) {
        *(undefined2 *)(iVar1 + 0x62) = 0;
        while (*(ushort *)(iVar1 + 0x62) < param_3) {
          iVar2 = FUN_001ebae0(iVar1 + 0x14,auStack_2c,*(undefined2 *)(iVar1 + 100),1);
          if (iVar2 != 0) {
            return iVar2;
          }
          *(short *)(iVar1 + 0x62) = *(short *)(iVar1 + 0x62) + 1;
        }
        *(undefined2 *)(iVar1 + 0x66) = *(undefined2 *)(iVar1 + 0x62);
        iStack_34 = FUN_001eb22c(iVar1 + 0x28,0);
        if (iStack_34 == 0) {
          *(undefined2 *)(iVar1 + 0x68) = 0;
          while (*(ushort *)(iVar1 + 0x68) < param_4) {
            iVar2 = FUN_001ebae0(iVar1 + 0x28,auStack_2c,*(undefined2 *)(iVar1 + 0x6a),2);
            if (iVar2 != 0) {
              return iVar2;
            }
            *(short *)(iVar1 + 0x68) = *(short *)(iVar1 + 0x68) + 1;
            iStack_34 = 0;
          }
          *(undefined2 *)(iVar1 + 0x6c) = *(undefined2 *)(iVar1 + 0x68);
          *param_1 = iVar1;
        }
      }
    }
  }
  return iStack_34;
}

