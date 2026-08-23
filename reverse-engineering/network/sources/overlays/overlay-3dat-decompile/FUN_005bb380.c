FUNCTION FUN_005bb380 @ 0x005bb380  size=180
CALLERS (1): FUN_005b9150@0x005b9150
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fd30@0x0062fd30, FUN_005bb270@0x005bb270, FUN_005af2c0@0x005af2c0, FUN_005bb1f0@0x005bb1f0
----------------------------------------------------------------

void FUN_005bb380(undefined8 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  FUN_005af2c0(0);
  FUN_005af2e0(0x14);
  pcVar3 = (char *)FUN_0062fd30(param_1);
  while( true ) {
    FUN_005bb1f0(pcVar3[3]);
    uVar2 = *(undefined4 *)(pcVar3 + 8);
    uVar1 = *(undefined2 *)(pcVar3 + 6);
    iVar4 = func_0x001ae3e0(uVar2);
    iVar5 = iVar4 * -10 + 0x280;
    if (iVar5 < 0) {
      iVar5 = iVar4 * -10 + 0x281;
    }
    FUN_005bb270((short)(iVar5 >> 1),uVar1,uVar2);
    if (*pcVar3 != '\0') break;
    pcVar3 = pcVar3 + 0xc;
  }
  return;
}



================================================================