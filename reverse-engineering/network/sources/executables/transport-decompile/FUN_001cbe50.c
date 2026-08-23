
undefined4 FUN_001cbe50(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if ((param_2 & 0x8000) == 0) {
    if ((long)param_2 < 100) {
      FUN_00109728(0x36b9d0,0x24c8a0,(&PTR_s_DATA_ROM_TEX__0024c870)[iVar1],param_4,param_2,param_3)
      ;
    }
    else {
      FUN_00109728(0x36b9d0,0x24c8b0,(&PTR_s_DATA_ROM_TEX__0024c870)[iVar1],param_4,param_2,param_3)
      ;
    }
  }
  else if ((long)(param_2 & 0xffffffffffff7fff) < 100) {
    FUN_00109728(0x36b9d0,0x24c878,(&PTR_s_DATA_ROM_TEX__0024c870)[iVar1],param_4,param_2 & 0x7fff,
                 param_3);
  }
  else {
    FUN_00109728(0x36b9d0,0x24c888,(&PTR_s_DATA_ROM_TEX__0024c870)[iVar1],param_4,param_2 & 0x7fff,
                 param_3);
  }
  if (param_1 == 0) {
    FUN_00109ab0(0x36b9d0,0x24c898);
  }
  return 0x36b9d0;
}

