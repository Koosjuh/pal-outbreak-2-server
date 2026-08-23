FUNCTION FUN_005c1220 @ 0x005c1220  size=440
CALLERS (0): 
CALLEES (2): FUN_005c7d00@0x005c7d00, FUN_005c2ab0@0x005c2ab0
----------------------------------------------------------------

void FUN_005c1220(char *param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char acStack_22 [34];
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cb9dd = 1;
    iVar7 = param_2 + 0xc;
    iVar1 = *(int *)(param_2 + 8);
    iVar6 = 0;
    while( true ) {
      if (iVar1 <= iVar6) break;
      func_0x00106b60(acStack_22 + 2,0,0x14);
      func_0x00109eb8(acStack_22 + 2,iVar7);
      iVar3 = func_0x0010a050(acStack_22 + 2);
      iVar5 = (acStack_22[iVar3] + -0x30) * 10 + acStack_22[iVar3 + 1] + -0x30;
      iVar3 = iVar5 + -1;
      if ((-1 < iVar3) && (iVar3 < 10)) {
        iVar3 = iVar3 * 0x24;
        func_0x00109eb8(iVar3 + 0x6fec08,iVar7);
        uVar4 = iVar5 - 1;
        iVar5 = uVar4 * 0x144;
        *(undefined4 *)(iVar3 + 0x6fec28) = *(undefined4 *)(iVar7 + 0x20);
        *(undefined4 *)(iVar3 + 0x6fec18) = *(undefined4 *)(iVar7 + 0x10);
        *(undefined4 *)(iVar3 + 0x6fec20) = *(undefined4 *)(iVar7 + 0x18);
        *(undefined4 *)(iVar3 + 0x6fec1c) = *(undefined4 *)(iVar7 + 0x14);
        *(undefined4 *)(iVar3 + 0x6fec24) = *(undefined4 *)(iVar7 + 0x1c);
        *(short *)(iVar5 + 0x6ce5de) = (short)*(undefined4 *)(iVar7 + 0x10);
        uVar2 = FUN_005c2ab0(uVar4 & 0xffff);
        *(undefined1 *)(iVar5 + 0x6ce5f0) = uVar2;
      }
      iVar7 = iVar7 + 0x24;
      iVar6 = iVar6 + 1;
    }
    uRam006ce5be = 10;
  }
  else if (*param_1 == '\'') {
    uRam006cb9dd = 2;
  }
  return;
}



================================================================