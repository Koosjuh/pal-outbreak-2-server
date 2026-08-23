FUNCTION FUN_005b5ac0 @ 0x005b5ac0  size=584
CALLERS (0): 
CALLEES (2): FUN_005c4d20@0x005c4d20, FUN_005c0920@0x005c0920
----------------------------------------------------------------

void FUN_005b5ac0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_200 [200];
  short sStack_138;
  short sStack_136;
  undefined1 auStack_120 [16];
  undefined1 auStack_110 [20];
  undefined1 auStack_fc [244];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (cRam006c4b90 == '\x05') {
    FUN_005c0920(auStack_120);
    if (cRam006c550e != '\0') {
      uStack_4 = 1;
      uStack_8 = 0;
      FUN_005c4d20(auStack_120,&uStack_8,8,0);
    }
  }
  else if ((cRam006c4b90 == '\x04') || (cRam006c4b90 == '\x0e')) {
    FUN_005c0920(auStack_120);
    func_0x001069a8(auStack_200,auStack_fc,0xd4);
    uStack_8 = 0;
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar2 = iVar3 * 0x3b0;
      if (*(char *)(iVar2 + 0x6c7c3c) != '\0') {
        if (sStack_136 == 0) {
          if (*(short *)(iVar2 + 0x6c7d1a) == 0) {
            sVar1 = *(short *)(iVar2 + 0x6c7d18);
joined_r0x005b5bf8:
            if (sVar1 == sStack_138) {
LAB_005b5c20:
              if (cRam006c550e == '\0') {
                return;
              }
              uStack_4 = 1;
              FUN_005c4d20(auStack_120,&uStack_8,8,0);
              return;
            }
          }
          else if ((sStack_138 == 6) && (*(short *)(iVar2 + 0x6c7d18) == 0x5b)) goto LAB_005b5c20;
        }
        else {
          if (*(short *)(iVar2 + 0x6c7d1a) != 0) {
            sVar1 = *(short *)(iVar2 + 0x6c7d18);
            goto joined_r0x005b5bf8;
          }
          if ((sStack_138 == 0x5b) && (*(short *)(iVar2 + 0x6c7d18) == 6)) goto LAB_005b5c20;
        }
      }
    }
    if (cRam006c550e != '\0') {
      uStack_4 = 0;
      FUN_005c4d20(auStack_120,&uStack_8,8,0);
    }
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar2 = iVar3 * 0x3b0;
      if (*(char *)(iVar2 + 0x6c7c3c) == '\0') {
        func_0x00109eb8(iVar2 + 0x6c7c2c,auStack_120);
        func_0x00109eb8(iVar2 + 0x6c7c3c,auStack_110);
        func_0x001069a8(iVar2 + 0x6c7c50,auStack_fc,0xf0);
        return;
      }
    }
  }
  return;
}



================================================================