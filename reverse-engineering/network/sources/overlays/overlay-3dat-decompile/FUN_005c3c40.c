FUNCTION FUN_005c3c40 @ 0x005c3c40  size=164
CALLERS (1): FUN_005c3b10@0x005c3b10
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c3c40(int param_1,int param_2,uint param_3,char *param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  for (iVar3 = 0; iVar3 < (int)(param_3 & 0xff); iVar3 = iVar3 + 1) {
    if (param_4[2] == '\0') {
      bVar1 = param_4[1];
    }
    else {
      bVar1 = *(byte *)(param_2 + uVar2);
      uVar2 = uVar2 + 1 & 0xff;
    }
    iVar4 = param_5 + *param_4 * 0x120;
    for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(iVar4 + 0x1e); iVar5 = iVar5 + 1) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(iVar4 + 0x1d) + iVar5) =
           *(undefined1 *)(iVar4 + (uint)bVar1 * 0x20 + iVar5 + 0x3e);
    }
    param_4 = param_4 + 4;
  }
  return;
}



================================================================