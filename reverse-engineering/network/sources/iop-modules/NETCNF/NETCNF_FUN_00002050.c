FUNCTION FUN_00002050 @ 0x00002050 size=96
CALLERS (8): FUN_00003f98@0x00003f98, FUN_00002280@0x00002280, FUN_00003988@0x00003988, FUN_00003060@0x00003060, FUN_000023e0@0x000023e0, FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_000027e4@0x000027e4
CALLEES (2): FUN_00009660@0x00009660, FUN_00001bf4@0x00001bf4

uint FUN_00002050(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00001bf4(&DAT_0000b5f8,param_2,0);
  if (iVar1 == 0) {
    iVar1 = FUN_00009660(&DAT_0000b5f8,0,10);
    uVar2 = (uint)(iVar1 == param_1);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================