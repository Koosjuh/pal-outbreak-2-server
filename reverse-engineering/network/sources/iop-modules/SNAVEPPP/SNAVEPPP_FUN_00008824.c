FUNCTION FUN_00008824 @ 0x00008824 size=244
CALLERS (1): FUN_00008454@0x00008454
CALLEES (4): FUN_00007894@0x00007894, FUN_00010abc@0x00010abc, FUN_000103cc@0x000103cc, FUN_00010b44@0x00010b44

undefined4 FUN_00008824(undefined4 param_1,ushort param_2,short param_3)

{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  
  DAT_00013608 = FUN_000103cc();
  DAT_0001360c = param_3 * 1000;
  if (0x200 < param_2) {
    param_2 = 0x200;
  }
  puVar2 = &DAT_00015fc0;
  iVar3 = (int)(short)param_2;
  while( true ) {
    sVar1 = FUN_00007894(puVar2,iVar3);
    if (sVar1 != 0) {
      return 0xffffffff;
    }
    iVar3 = (int)(short)param_2;
    sVar1 = FUN_00010abc(&DAT_00015fc0,param_1,iVar3);
    if (sVar1 == 0) break;
    FUN_00010b44(&DAT_00015fc0,&DAT_00015fc1,iVar3 + -1);
    puVar2 = (undefined *)(iVar3 + 0x15fbf);
    iVar3 = 1;
  }
  return 0;
}


================================================================