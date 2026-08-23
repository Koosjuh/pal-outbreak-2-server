FUNCTION FUN_0000ef14 @ 0x0000ef14 size=392
CALLERS (1): FUN_00011414@0x00011414
CALLEES (4): FUN_00001454@0x00001454, FUN_0000139c@0x0000139c, FUN_00011da8@0x00011da8, FUN_000010c0@0x000010c0

short FUN_0000ef14(ushort param_1,undefined4 param_2,char param_3)

{
  short sVar1;
  int iVar2;
  short sVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined1 auStack_28 [8];
  
  if (param_3 == '\0') {
    sVar1 = 0;
    sVar3 = 0;
    if (param_1 != 0) {
      while (0xf < param_1) {
        while( true ) {
          if ((int)(uint)DAT_0001619a <= (int)sVar3) {
            return sVar1;
          }
          if (((&DAT_000183fe)[sVar3 * 0xe] & 1) != 0) break;
          sVar3 = sVar3 + 1;
        }
        iVar2 = (int)sVar3;
        if ((int)(uint)DAT_0001619a <= iVar2) {
          return sVar1;
        }
        sVar1 = sVar1 + 1;
        sVar3 = sVar3 + 1;
        param_1 = param_1 - 0x10;
        local_38 = (&DAT_000183f0)[iVar2 * 7];
        local_34 = (&DAT_000183f8)[iVar2 * 7];
        local_30 = (&DAT_000183fc)[iVar2 * 0xe];
        local_2e = (&DAT_000183fe)[iVar2 * 0xe];
        local_2c = 1;
        FUN_0000139c(auStack_28,&local_38);
        FUN_000010c0(param_2,auStack_28,0x10);
        FUN_00001454(param_2,0x10);
        if (param_1 == 0) {
          return sVar1;
        }
      }
    }
  }
  else {
    FUN_00011da8(0xffffffff);
    sVar1 = 0;
  }
  return sVar1;
}


================================================================