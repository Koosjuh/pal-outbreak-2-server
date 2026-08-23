FUNCTION FUN_00012608 @ 0x00012608 size=48
CALLERS (12): FUN_00003840@0x00003840, FUN_0000adf8@0x0000adf8, FUN_0000b3d4@0x0000b3d4, FUN_00003bac@0x00003bac, FUN_00007000@0x00007000, FUN_00013650@0x00013650, FUN_00001930@0x00001930, FUN_00004ec4@0x00004ec4, FUN_0000353c@0x0000353c, FUN_0000a930@0x0000a930, FUN_00005828@0x00005828, FUN_0000af84@0x0000af84
CALLEES (1): FUN_00011fac@0x00011fac

undefined4 FUN_00012608(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  iVar1 = FUN_00011fac(0,local_10);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_10[0];
  }
  return uVar2;
}


================================================================