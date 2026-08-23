FUNCTION FUN_0000231c @ 0x0000231c size=80
CALLERS (2): FUN_00007894@0x00007894, FUN_00007a90@0x00007a90
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010bd0@0x00010bd0

undefined4 FUN_0000231c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00010bd0();
  uVar2 = 0;
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, (DAT_00012efc & 1) != 0)) {
    FUN_00010c38("aveppp: PP_ComReadedLen return (ERROR)\n");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================