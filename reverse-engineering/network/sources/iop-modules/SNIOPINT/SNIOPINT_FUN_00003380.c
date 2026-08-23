FUNCTION FUN_00003380 @ 0x00003380 size=204
CALLERS (1): FUN_00003590@0x00003590
CALLEES (6): FUN_00003788@0x00003788, FUN_00003778@0x00003778, FUN_00003694@0x00003694, FUN_00003728@0x00003728, FUN_0000368c@0x0000368c, FUN_000036b8@0x000036b8

undefined4 FUN_00003380(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10 [2];
  
  FUN_00003728("AVE-TCP EE<->IOP interface module ver0x%04x(%d-%d-%d) (%s)\n",0x13a,4,4,4,
               "2004/01/07");
  FUN_0000368c(local_10);
  iVar1 = FUN_000036b8(&DAT_000035d0);
  FUN_00003694(local_10[0]);
  uVar2 = 1;
  if (iVar1 == 0) {
    local_28 = 0x2000000;
    local_20 = &LAB_00002f74;
    local_18 = 9;
    local_1c = 0x4000;
    local_24 = 0;
    iVar1 = FUN_00003778(&local_28);
    if (iVar1 < 1) {
      uVar2 = 1;
    }
    else {
      FUN_00003788(iVar1,0);
      uVar2 = 2;
      DAT_0000c614 = iVar1;
    }
  }
  return uVar2;
}


================================================================