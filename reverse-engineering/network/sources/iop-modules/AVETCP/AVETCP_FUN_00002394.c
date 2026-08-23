FUNCTION FUN_00002394 @ 0x00002394 size=528
CALLERS (1): FUN_000044b4@0x000044b4
CALLEES (7): FUN_000010a8@0x000010a8, FUN_00002cb4@0x00002cb4, FUN_00002728@0x00002728, FUN_00002f1c@0x00002f1c, FUN_00002198@0x00002198, FUN_00004254@0x00004254, FUN_00011d00@0x00011d00

undefined4 FUN_00002394(int param_1,undefined4 param_2,uint param_3,short param_4)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined4 local_28;
  int local_24;
  
  iVar3 = FUN_00004254((int)param_4);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  puVar5 = (undefined2 *)(param_1 + (param_3 & 0xffff));
  sVar2 = FUN_000010a8((int)(short)puVar5[1]);
  if (sVar2 != 0x800) {
    return 0xffffffff;
  }
  if (*(char *)((int)puVar5 + 5) != '\x04') {
    return 0xffffffff;
  }
  bVar1 = *(byte *)(puVar5 + 2);
  puVar6 = puVar5 + 4;
  FUN_00011d00(&local_28,(int)puVar6 + (uint)bVar1,4);
  FUN_00011d00(&local_24,
               (int)puVar6 + (uint)bVar1 + (uint)*(byte *)((int)puVar5 + 5) +
               (uint)*(byte *)(puVar5 + 2),4);
  if (local_24 == *(int *)(iVar3 + 4)) {
    sVar2 = FUN_000010a8((int)(short)puVar5[3]);
    if (sVar2 == 1) {
      pbVar4 = (byte *)FUN_00002198(local_28,3);
      if (pbVar4 == (byte *)0x0) {
        iVar3 = FUN_00002728(local_28,*puVar5,*(undefined1 *)(puVar5 + 2),puVar6,0,(int)param_4);
        if (iVar3 == 0) {
          return 0xffffffff;
        }
      }
      else if ((*pbVar4 & 1) != 0) {
        FUN_00011d00(pbVar4 + 0x18,puVar6,pbVar4[1]);
        *pbVar4 = *pbVar4 & 0xfe | 2;
        sVar2 = FUN_00002cb4();
        if (sVar2 != 0) {
          return 0xffffffff;
        }
      }
      sVar2 = FUN_00002f1c(puVar6,local_28,(int)param_4);
    }
    else {
      sVar2 = FUN_000010a8((int)(short)puVar5[3]);
      if (sVar2 != 2) {
        return 0xffffffff;
      }
      pbVar4 = (byte *)FUN_00002198(local_28,1);
      if (pbVar4 == (byte *)0x0) {
        return 0;
      }
      FUN_00011d00(pbVar4 + 0x18,puVar6,pbVar4[1]);
      *pbVar4 = *pbVar4 & 0xfe | 2;
      sVar2 = FUN_00002cb4();
    }
    if (sVar2 == 0) {
      return 0;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}


================================================================