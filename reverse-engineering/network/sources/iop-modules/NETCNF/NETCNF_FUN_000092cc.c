FUNCTION FUN_000092cc @ 0x000092cc size=100
CALLERS (2): FUN_00001198@0x00001198, FUN_00000da8@0x00000da8
CALLEES (2): FUN_00008af0@0x00008af0, FUN_00008c68@0x00008c68

undefined4 FUN_000092cc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00008c68(param_1,0);
  if (iVar1 == -1) {
    uVar2 = FUN_00008af0(param_1);
  }
  else {
    uVar2 = (&DAT_0000c338)[iVar1 * 0x49];
  }
  return uVar2;
}


================================================================