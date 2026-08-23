FUNCTION FUN_00013000 @ 0x00013000 size=232
CALLERS (0): 
CALLEES (3): FUN_00014e24@0x00014e24, FUN_00014dd4@0x00014dd4, FUN_00014ddc@0x00014ddc

undefined * FUN_00013000(undefined *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined *puVar4;
  undefined4 local_18 [2];
  
  FUN_00014dd4(local_18);
  bVar3 = false;
  puVar4 = (undefined *)0x0;
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    iVar1 = (iVar1 >> 0x10) * 0x634;
    if ((&DAT_00022d78 + iVar1 <= param_1) && (param_1 <= &DAT_00023394 + iVar1)) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
    if (0x1f < iVar2 * 0x10000 >> 0x10) {
LAB_000130a4:
      if (!bVar3) {
        FUN_00014e24("AT_InetSeekPkt Pt Error[%08x]\n",param_1);
      }
      FUN_00014ddc(local_18[0]);
      return puVar4;
    }
  }
  bVar3 = true;
  puVar4 = &DAT_00022d60 + iVar1;
  goto LAB_000130a4;
}


================================================================