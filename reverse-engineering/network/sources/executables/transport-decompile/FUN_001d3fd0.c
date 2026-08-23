
void FUN_001d3fd0(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  func_0x005f4250();
  uVar1 = uRam003435bc;
  iVar4 = 0;
  do {
    lVar2 = FUN_001cbcb0(iVar4 + 0x4000);
    if (lVar2 == 0) {
      if ((((iVar4 == 0x16) || (iVar4 == 8)) || (iVar4 == 5)) ||
         (((iVar4 == 4 || (iVar4 == 2)) || (iVar4 == 0)))) {
        uVar3 = FUN_001cf2b0((&PTR_s_data_rom_netwk_pal_lobby_01_tm2_0024d8b0)[iVar4]);
        lVar2 = FUN_001cb360(uVar3,uVar1,0x10001,0);
      }
      else {
        lVar2 = FUN_001cb360((&PTR_s_data_rom_netwk_pal_lobby_01_tm2_0024d8b0)[iVar4],uVar1,0x10001,
                             0);
      }
      if (lVar2 != 0) {
        FUN_001cb5f0(iVar4 + 0x4000,uVar1);
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x18);
  return;
}

