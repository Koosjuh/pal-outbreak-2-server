FUNCTION FUN_00002d9c @ 0x00002d9c size=384
CALLERS (1): FUN_0000223c@0x0000223c
CALLEES (7): FUN_00000fa0@0x00000fa0, FUN_00004314@0x00004314, FUN_0000139c@0x0000139c, FUN_00001018@0x00001018, FUN_00011d00@0x00011d00, FUN_00004254@0x00004254, FUN_000010a8@0x000010a8

undefined4 FUN_00002d9c(undefined4 param_1,short param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  iVar2 = FUN_00004254((int)param_2);
  uVar3 = 0xffffffff;
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)FUN_00000fa0();
    uVar3 = 0xffffffff;
    if (puVar4 != (undefined4 *)0x0) {
      DAT_000164f8 = FUN_000010a8((int)*(short *)(iVar2 + 0x14));
      DAT_000164fa = FUN_000010a8(0x800);
      DAT_000164fc = *(undefined1 *)(iVar2 + 0x16);
      DAT_000164fd = 4;
      DAT_000164fe = FUN_000010a8(1);
      FUN_00011d00(&DAT_00016500,iVar2 + 0x18,*(undefined1 *)(iVar2 + 0x16));
      bVar5 = *(byte *)(iVar2 + 0x16);
      FUN_00011d00(&DAT_00016500 + bVar5,iVar2 + 4,4);
      puVar6 = &DAT_00016504 + bVar5;
      bVar5 = 0;
      if (*(char *)(iVar2 + 0x16) != '\0') {
        do {
          *puVar6 = 0;
          bVar5 = bVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (bVar5 < *(byte *)(iVar2 + 0x16));
      }
      FUN_00011d00(puVar6,local_res0,4);
      *puVar4 = 1;
      *(ushort *)(puVar4 + 2) = (ushort)*(byte *)(iVar2 + 0x16) * 2 + 0x10;
      FUN_0000139c(puVar4 + 3,&DAT_000164f8);
      sVar1 = FUN_00004314(puVar4,iVar2 + 0x1e,4,(int)param_2);
      if (sVar1 == 0) {
        FUN_00001018(puVar4);
        uVar3 = 0;
      }
      else {
        FUN_00001018(puVar4);
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}


================================================================