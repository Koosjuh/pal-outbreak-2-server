FUNCTION FUN_000045bc @ 0x000045bc size=64
CALLERS (4): FUN_0000497c@0x0000497c, FUN_00004fb0@0x00004fb0, FUN_00005af8@0x00005af8, FUN_000058d0@0x000058d0
CALLEES (2): FUN_000041c8@0x000041c8, FUN_00004558@0x00004558

undefined4 FUN_000045bc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000041c8();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00004558(param_1,iVar1);
  }
  return uVar2;
}


================================================================