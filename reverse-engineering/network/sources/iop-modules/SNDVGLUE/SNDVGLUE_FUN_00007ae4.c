FUNCTION FUN_00007ae4 @ 0x00007ae4 size=60
CALLERS (1): FUN_00006c1c@0x00006c1c
CALLEES (1): FUN_00004cdc@0x00004cdc

undefined4 FUN_00007ae4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00004cdc(DAT_0000970c);
  uVar2 = 0;
  if (iVar1 != 2) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================