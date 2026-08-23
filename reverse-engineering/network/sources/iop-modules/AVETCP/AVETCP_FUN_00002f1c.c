FUNCTION FUN_00002f1c @ 0x00002f1c size=364
CALLERS (1): FUN_00002394@0x00002394
CALLEES (7): FUN_000010a8@0x000010a8, FUN_0000139c@0x0000139c, FUN_00000fa0@0x00000fa0, FUN_00001018@0x00001018, FUN_00004314@0x00004314, FUN_00004254@0x00004254, FUN_00011d00@0x00011d00

undefined4 FUN_00002f1c(undefined4 param_1,undefined4 param_2,short param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  iVar3 = FUN_00004254((int)param_3);
  uVar4 = 0xffffffff;
  if (iVar3 != 0) {
    puVar5 = (undefined4 *)FUN_00000fa0();
    uVar4 = 0xffffffff;
    if (puVar5 != (undefined4 *)0x0) {
      DAT_000164f8 = FUN_000010a8((int)*(short *)(iVar3 + 0x14));
      DAT_000164fa = FUN_000010a8(0x800);
      DAT_000164fc = *(undefined1 *)(iVar3 + 0x16);
      DAT_000164fd = 4;
      DAT_000164fe = FUN_000010a8(2);
      FUN_00011d00(&DAT_00016500,iVar3 + 0x18,*(undefined1 *)(iVar3 + 0x16));
      bVar1 = *(byte *)(iVar3 + 0x16);
      FUN_00011d00(&DAT_00016500 + bVar1,iVar3 + 4,4);
      FUN_00011d00(&DAT_00016504 + bVar1,param_1,*(undefined1 *)(iVar3 + 0x16));
      FUN_00011d00(&DAT_00016504 + bVar1 + *(byte *)(iVar3 + 0x16),local_res4,4);
      *puVar5 = 1;
      *(ushort *)(puVar5 + 2) = (ushort)*(byte *)(iVar3 + 0x16) * 2 + 0x10;
      FUN_0000139c(puVar5 + 3,&DAT_000164f8);
      sVar2 = FUN_00004314(puVar5,param_1,4,(int)param_3);
      if (sVar2 == 0) {
        FUN_00001018(puVar5);
        uVar4 = 0;
      }
      else {
        FUN_00001018(puVar5);
        uVar4 = 0xffffffff;
      }
    }
  }
  return uVar4;
}


================================================================