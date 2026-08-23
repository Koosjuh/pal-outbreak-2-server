FUNCTION FUN_005c2bc0 @ 0x005c2bc0  size=428
CALLERS (1): FUN_005c2f40@0x005c2f40
CALLEES (0): 
----------------------------------------------------------------

int FUN_005c2bc0(int param_1,undefined8 param_2,undefined8 param_3,char *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_4[2] != '\0') {
    uVar3 = (int)param_4[1] >> 2 & 3;
    uVar1 = (((int)param_4[1] >> 4 & 3U) - uVar3) + 1;
    *(char *)(param_1 + 0x43) = (char)uVar1;
    *(byte *)(param_1 + 0x44) = (param_4[1] & 3U) - (char)uVar3;
    iVar5 = param_5 + *param_4 * 0x120;
    func_0x00109eb8(param_1 + 1,iVar5);
    *(char *)(param_1 + 0x42) = param_4[3];
    for (iVar2 = 0; iVar2 < (int)(uVar1 & 0xffff); iVar2 = iVar2 + 1) {
      func_0x00109eb8(param_1 + iVar2 * 0x41 + 0x65,iVar5 + (iVar2 + uVar3) * 0x20 + 0x20);
    }
    iVar5 = 1;
    param_1 = param_1 + 0x14a5;
  }
  if (param_4[6] != '\0') {
    iVar2 = ((int)param_4[5] >> 3 & 7U) + 1;
    *(char *)(param_1 + 0x43) = (char)iVar2;
    *(byte *)(param_1 + 0x44) = param_4[5] & 7;
    param_5 = param_5 + param_4[4] * 0x120;
    func_0x00109eb8(param_1 + 1,param_5);
    *(char *)(param_1 + 0x42) = param_4[7];
    for (iVar4 = 0; iVar4 < iVar2; iVar4 = iVar4 + 1) {
      func_0x00109eb8(param_1 + iVar4 * 0x41 + 0x65,param_5 + iVar4 * 0x20 + 0x20);
    }
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}



================================================================