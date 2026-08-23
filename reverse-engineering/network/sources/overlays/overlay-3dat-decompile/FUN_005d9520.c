FUNCTION FUN_005d9520 @ 0x005d9520  size=204
CALLERS (1): FUN_005ed6e0@0x005ed6e0
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d9520(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = ((uint)param_2 & 0xffff) + 0x14;
  uVar1 = ((uint)param_1 & 0xffff) + 0x14;
  FUN_005da650(uVar1,uVar2);
  FUN_005cab10(0xc,1,param_1,param_2,uVar1 & 0xffff,uVar2 & 0xffff,0xffffffffff000001,0);
  return;
}



================================================================