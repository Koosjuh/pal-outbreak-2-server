FUNCTION FUN_00612ca0 @ 0x00612ca0  size=108
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (4): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_00614720@0x00614720, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00612ca0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00614720(0xffffffff80008080);
  uVar1 = FUN_0060f830(0x653f90,*(undefined1 *)(iRam0070d1c0 + 0x4c));
  uVar2 = FUN_006147a0(uVar1,0x16);
  FUN_006146e0(uVar2,0x20,uVar1);
  FUN_00614720(0xffffffff80808080);
  return;
}



================================================================