FUNCTION FUN_00001458 @ 0x00001458 size=324
CALLERS (0): 
CALLEES (3): FUN_00001164@0x00001164, FUN_00002164@0x00002164, FUN_00001300@0x00001300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001458(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = _DAT_bf801466;
  uVar1 = _DAT_bf801464;
  if (DAT_00002650 != 0) {
    if ((_DAT_b4000004 & 4) == 0) {
      FUN_00002164("dev9: unknown dev9 interrupt\n");
      return 0;
    }
    _DAT_b4000004 = 4;
  }
  if (((_DAT_bf801464 & 3) != 0) || ((_DAT_bf801466 & 3) != 0)) {
    if (DAT_000025cc != (code *)0x0) {
      (*DAT_000025cc)(1);
    }
    FUN_00001300();
    FUN_00001164();
  }
  if (((uVar1 & 0x80) == 0) && ((uVar2 & 0x80) == 0)) {
    FUN_00002164("dev9: dev9 interrupt, CSTC1:%04x, CSTC2:%04x\n",uVar1,uVar2);
  }
  else if (DAT_000025cc != (code *)0x0) {
    (*DAT_000025cc)(0);
  }
  _DAT_bf80147e = 0;
  return 1;
}


================================================================