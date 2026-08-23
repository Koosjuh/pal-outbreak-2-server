FUNCTION FUN_005c2d70 @ 0x005c2d70  size=280
CALLERS (1): FUN_005c2f40@0x005c2f40
CALLEES (0): 
----------------------------------------------------------------

char FUN_005c2d70(int param_1,undefined8 param_2,uint param_3,char *param_4,int param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  cVar2 = '\0';
  for (iVar5 = 0; iVar5 < (int)(param_3 & 0xff); iVar5 = iVar5 + 1) {
    if (param_4[2] != '\0') {
      iVar3 = param_5 + *param_4 * 0x120;
      cVar1 = *(char *)(iVar3 + 0x1f);
      *(char *)(param_1 + 0x43) = cVar1;
      func_0x00109eb8(param_1 + 1,iVar3);
      *(char *)(param_1 + 0x42) = param_4[3];
      *(char *)(param_1 + 0x44) = param_4[1];
      for (iVar4 = 0; iVar4 < (int)(uint)(ushort)(short)cVar1; iVar4 = iVar4 + 1) {
        func_0x00109eb8(param_1 + iVar4 * 0x41 + 0x65,iVar3 + iVar4 * 0x20 + 0x20);
      }
      cVar2 = cVar2 + '\x01';
      param_1 = param_1 + 0x14a5;
    }
    param_4 = param_4 + 4;
  }
  return cVar2;
}



================================================================