FUNCTION FUN_005bad10 @ 0x005bad10  size=276
CALLERS (2): FUN_00616d30@0x00616d30, FUN_006173c0@0x006173c0
CALLEES (0): 
----------------------------------------------------------------

char FUN_005bad10(int param_1,int param_2,char param_3,char param_4)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  char cVar5;
  long lVar6;
  char cVar7;
  undefined1 auStack_e0 [60];
  ushort auStack_a4 [82];
  
  uVar3 = (long)param_4 & 0xf;
  iVar1 = (int)uVar3;
  cVar7 = '\x03';
  lVar6 = 0;
  if (((long)param_4 < 0) && (uVar3 != 0)) {
    iVar1 = iVar1 + -0x10;
  }
  for (; lVar6 < param_3; lVar6 = (long)((int)lVar6 + 1)) {
    func_0x00106b60(auStack_e0,0,0xd4);
    func_0x001069a8(auStack_e0,param_1 + 0x2a4,0xd4);
    cVar5 = '\0';
    iVar4 = 0;
    iVar2 = param_2;
    do {
      if ((long)*(char *)(iVar2 + 0x12e8) <= (long)(ulong)auStack_a4[iVar1]) {
        cVar5 = (char)iVar4 + '\x01';
      }
      iVar4 = iVar4 + 1;
      iVar2 = param_2 + iVar4;
    } while (iVar4 < 3);
    if (cVar5 < cVar7) {
      cVar7 = cVar5;
    }
    param_1 = param_1 + 0x3b0;
  }
  return cVar7;
}



================================================================