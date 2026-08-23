
void FUN_001d40e0(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  
  uVar1 = uRam003435bc;
  iVar3 = 0;
  do {
    if (-1 < *param_3) {
      lVar2 = FUN_001cb360((&PTR_s_data_rom_netwk_player_11_tm2_0024da30)[*param_3],uVar1,0x10001,0)
      ;
      if (lVar2 != 0) {
        FUN_001cb5f0(iVar3 + 0x4019,uVar1);
      }
    }
    iVar3 = iVar3 + 1;
    param_3 = param_3 + 1;
  } while (iVar3 < 4);
  return;
}

