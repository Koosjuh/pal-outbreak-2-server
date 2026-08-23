FUNCTION FUN_000029c8 @ 0x000029c8 size=68
CALLERS (1): FUN_00011450@0x00011450
CALLEES (1): FUN_00002728@0x00002728

undefined4 FUN_000029c8(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00002728(param_1,1,6,param_2,param_3,0);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}


================================================================