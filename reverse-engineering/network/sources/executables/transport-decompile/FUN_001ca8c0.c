
void FUN_001ca8c0(void)

{
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_3c;
  undefined1 auStack_30 [4];
  code *pcStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  
  uRam003688d0 = 0;
  uRam003688d8 = 0;
  uRam003688e0 = 0;
  uStack_48 = 0;
  uStack_4c = 1;
  uStack_3c = 0;
  DAT_00248868 = CreateSema(auStack_50);
  uStack_48 = 0;
  uStack_4c = 1;
  uStack_3c = 0;
  DAT_00248860 = CreateSema(auStack_50);
  uStack_48 = 0;
  uStack_4c = 1;
  uStack_3c = 0;
  DAT_00248848 = CreateSema(auStack_50);
  uStack_24 = 0x2000;
  puStack_20 = &_mips_gp0_value;
  pcStack_2c = FUN_001ca810;
  uStack_28 = 0x3688f0;
  uStack_1c = 4;
  DAT_00248858 = CreateThread(auStack_30);
  _StartThread(DAT_00248858,0);
  return;
}

