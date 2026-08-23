FUNCTION FUN_0000f228 @ 0x0000f228 size=80
CALLERS (4): FUN_0000353c@0x0000353c, FUN_0000af84@0x0000af84, FUN_0000b3d4@0x0000b3d4, FUN_00004ec4@0x00004ec4
CALLEES (1): FUN_0000f60c@0x0000f60c

undefined4 * FUN_0000f228(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = FUN_0000f60c();
  if (sVar1 == -1) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = &DAT_00018350 + sVar1 * 7;
  }
  return puVar2;
}


================================================================