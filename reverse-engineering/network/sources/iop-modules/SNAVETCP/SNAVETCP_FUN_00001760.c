FUNCTION FUN_00001760 @ 0x00001760 size=76
CALLERS (5): FUN_00006844@0x00006844, FUN_00006a8c@0x00006a8c, FUN_000060c0@0x000060c0, FUN_00006978@0x00006978, FUN_0000663c@0x0000663c
CALLEES (1): FUN_00006e48@0x00006e48

undefined4 FUN_00001760(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 4) != '\x02')) {
    uVar2 = 0xffffffff;
  }
  else {
    sVar1 = FUN_00006e48();
    uVar2 = 0xffffffff;
    if (sVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================