FUNCTION FUN_00002000 @ 0x00002000 size=224
CALLERS (1): FUN_000020e0@0x000020e0
CALLEES (1): FUN_000029f4@0x000029f4

undefined4 FUN_00002000(byte *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 10;
  pbVar4 = param_1;
  if ((*param_1 == 0x30) && (param_1[1] != 0)) {
    iVar6 = 8;
    pbVar4 = param_1 + 1;
    if (param_1[1] == 0x78) {
      pbVar4 = param_1 + 2;
      iVar6 = 0x10;
    }
  }
  bVar1 = *pbVar4;
  iVar5 = 0;
  if (*pbVar4 == 0) {
LAB_000020b8:
    FUN_000029f4("smap: %s: %s - invalid digit\n","scan_number");
    uVar2 = 0xffffffff;
  }
  else {
    do {
      if (bVar1 - 0x30 < 10) {
        iVar3 = (char)bVar1 + -0x30;
      }
      else {
        if (5 < bVar1 - 0x61) goto LAB_000020b8;
        iVar3 = (char)bVar1 + -0x57;
      }
      if (iVar6 <= iVar3) goto LAB_000020b8;
      pbVar4 = pbVar4 + 1;
      bVar1 = *pbVar4;
      iVar5 = iVar5 * iVar6 + iVar3;
    } while (*pbVar4 != 0);
    *param_2 = iVar5;
    uVar2 = 0;
  }
  return uVar2;
}


================================================================