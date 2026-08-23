FUNCTION FUN_005ec1b0 @ 0x005ec1b0  size=364
CALLERS (54): FUN_005e8530@0x005e8530, FUN_005e9dd0@0x005e9dd0, FUN_005e9330@0x005e9330, FUN_005eac40@0x005eac40, FUN_005eb9f0@0x005eb9f0, FUN_005eab70@0x005eab70, FUN_005e9ca0@0x005e9ca0, FUN_005eaa70@0x005eaa70, FUN_005ebaf0@0x005ebaf0, FUN_005ea190@0x005ea190, FUN_005eb990@0x005eb990, FUN_005e95e0@0x005e95e0, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ec1b0(undefined4 *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  pbVar5 = (byte *)*param_1;
  iVar4 = 0;
  iVar3 = 0;
LAB_005ec300:
  bVar1 = *pbVar5;
  do {
    uVar6 = (uint)bVar1;
    if ((uVar6 == 0) || (param_3 + -3 < iVar3)) {
LAB_005ec30c:
      *param_2 = 0;
      *param_1 = pbVar5;
      return;
    }
    if (iVar4 == 3) {
      pbVar2 = pbVar5;
      if ((bVar1 & 0x80) == 0) {
        if (((&DAT_006491b0)[uVar6] & 4) != 0) {
          *param_2 = 0;
          *param_1 = pbVar5;
          return;
        }
        *param_2 = bVar1;
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 1;
      }
      else {
        do {
          pbVar5 = pbVar2;
          uVar6 = (uVar6 & 0xff) << 1;
          iVar3 = iVar3 + 1;
          *param_2 = *pbVar5;
          param_2 = param_2 + 1;
          pbVar2 = pbVar5 + 1;
        } while ((uVar6 & 0x80) != 0);
      }
      goto LAB_005ec2fc;
    }
    if (iVar4 == 2) {
      pbVar2 = pbVar5;
      if ((bVar1 & 0x80) == 0) {
        if (uVar6 == 0x22) {
          *param_2 = 0;
          *param_1 = pbVar5;
          return;
        }
        *param_2 = bVar1;
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 1;
      }
      else {
        do {
          pbVar5 = pbVar2;
          uVar6 = (uVar6 & 0xff) << 1;
          iVar3 = iVar3 + 1;
          *param_2 = *pbVar5;
          param_2 = param_2 + 1;
          pbVar2 = pbVar5 + 1;
        } while ((uVar6 & 0x80) != 0);
      }
      goto LAB_005ec2fc;
    }
    if (iVar4 != 1) {
      if (iVar4 != 0) {
        pbVar5 = pbVar5 + 1;
        goto LAB_005ec300;
      }
      iVar4 = 1;
      if (uVar6 != 0x3d) goto LAB_005ec30c;
      goto LAB_005ec2fc;
    }
    iVar4 = 3;
    if (uVar6 == 0x22) break;
    bVar1 = *pbVar5;
  } while( true );
  iVar4 = 2;
LAB_005ec2fc:
  pbVar5 = pbVar5 + 1;
  goto LAB_005ec300;
}



================================================================