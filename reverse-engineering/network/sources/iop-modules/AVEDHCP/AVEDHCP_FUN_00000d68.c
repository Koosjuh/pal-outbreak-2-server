FUNCTION FUN_00000d68 @ 0x00000d68 size=92
CALLERS (1): FUN_0000026c@0x0000026c
CALLEES (3): FUN_00000d3c@0x00000d3c, FUN_00002d0c@0x00002d0c, FUN_00001788@0x00001788

undefined4 FUN_00000d68(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00000d3c((int)param_1);
  do {
    iVar1 = FUN_00001788();
    FUN_00002d0c(0x10);
  } while (iVar1 == 6);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}


================================================================