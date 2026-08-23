FUNCTION FUN_005f58c0 @ 0x005f58c0  size=176
CALLERS (1): FUN_006020e0@0x006020e0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005f58c0(long param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  int unaff_s1_lo;
  int iVar4;
  long lVar3;
  
  if (param_1 == 2) {
    unaff_s1_lo = 0xb;
  }
  else if (param_1 == 1) {
    unaff_s1_lo = 5;
  }
  else if (param_1 == 0) {
    unaff_s1_lo = 10;
  }
  iVar4 = 0;
  bVar1 = 0 < unaff_s1_lo;
  while( true ) {
    if (!bVar1) {
      return;
    }
    lVar3 = FUN_00618ba0();
    puVar2 = (undefined1 *)lVar3;
    if (lVar3 == 0) break;
    *puVar2 = 1;
    puVar2[1] = 0;
    puVar2[2] = (char)param_1;
    puVar2[3] = (char)iVar4;
    *(code **)(puVar2 + 0xc) = FUN_005f5970;
    iVar4 = iVar4 + 1;
    bVar1 = iVar4 < unaff_s1_lo;
  }
  return;
}



================================================================