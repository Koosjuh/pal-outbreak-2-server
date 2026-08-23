FUNCTION FUN_005ae310 @ 0x005ae310  size=140
CALLERS (1): FUN_005ae130@0x005ae130
CALLEES (3): FUN_005ac380@0x005ac380, FUN_005c8810@0x005c8810, thunk_FUN_006235f0@0x006088a0
----------------------------------------------------------------

undefined8 FUN_005ae310(int param_1)

{
  long lVar1;
  
  lVar1 = FUN_005c8810();
  if (lVar1 != -100) {
    if ((lVar1 == -1) || (lVar1 == 1)) {
      FUN_005ac380();
      *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
      return 0;
    }
    if (lVar1 == 0) {
      return 0;
    }
  }
  thunk_FUN_006235f0();
  FUN_005ac380();
  *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
  return 0;
}



================================================================