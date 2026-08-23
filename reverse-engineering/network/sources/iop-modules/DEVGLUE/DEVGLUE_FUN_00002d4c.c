FUNCTION FUN_00002d4c @ 0x00002d4c size=164
CALLERS (1): FUN_00003a9c@0x00003a9c
CALLEES (3): FUN_00008140@0x00008140, FUN_0000822c@0x0000822c, FUN_000036f4@0x000036f4

undefined4 FUN_00002d4c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_00008140(&DAT_0000de28,0,0x54);
  DAT_0000de28 = FUN_000036f4(0);
  DAT_0000de32 = DAT_00008950;
  DAT_0000de36 = DAT_00008954;
  FUN_00008140(&DAT_0000de38,0,0x44);
  local_18 = 1;
  local_10 = 1;
  local_c = 1;
  local_14 = 0;
  iVar1 = FUN_0000822c(&local_18);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    DAT_0000de78 = iVar1;
  }
  return uVar2;
}


================================================================