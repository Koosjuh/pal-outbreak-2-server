FUNCTION FUN_005ec320 @ 0x005ec320  size=272
CALLERS (2): FUN_005e9ea0@0x005e9ea0, FUN_005e93f0@0x005e93f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ec320(undefined4 *param_1,undefined1 *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  pbVar5 = (byte *)*param_1;
  iVar4 = 0;
  iVar3 = 0;
LAB_005ec414:
  bVar1 = *pbVar5;
  do {
    uVar2 = (uint)bVar1;
    if ((uVar2 == 0) || (param_3 + -2 < iVar3)) {
LAB_005ec420:
      *param_2 = 0;
      *param_1 = pbVar5;
      return;
    }
    if (iVar4 == 3) {
      if (((&DAT_006491b0)[uVar2] & 4) != 0) {
        *param_2 = 0;
        *param_1 = pbVar5;
        return;
      }
      iVar3 = iVar3 + 1;
      *param_2 = (&DAT_006493b0)[uVar2];
      param_2 = param_2 + 1;
      goto LAB_005ec410;
    }
    if (iVar4 == 2) {
      if (uVar2 == 0x22) {
        *param_2 = 0;
        *param_1 = pbVar5;
        return;
      }
      iVar3 = iVar3 + 1;
      *param_2 = (&DAT_006493b0)[uVar2];
      param_2 = param_2 + 1;
      goto LAB_005ec410;
    }
    if (iVar4 != 1) {
      if (iVar4 != 0) {
        pbVar5 = pbVar5 + 1;
        goto LAB_005ec414;
      }
      iVar4 = 1;
      if (uVar2 != 0x3d) goto LAB_005ec420;
      goto LAB_005ec410;
    }
    iVar4 = 3;
    if (uVar2 == 0x22) break;
    bVar1 = *pbVar5;
  } while( true );
  iVar4 = 2;
LAB_005ec410:
  pbVar5 = pbVar5 + 1;
  goto LAB_005ec414;
}



================================================================