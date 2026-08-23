FUNCTION FUN_00011938 @ 0x00011938 size=72
CALLERS (1): FUN_00000aa0@0x00000aa0
CALLEES (1): FUN_00004620@0x00004620

undefined4 FUN_00011938(void)

{
  short sVar1;
  undefined4 uVar2;
  
  DAT_00016ee0 = 0;
  sVar1 = FUN_00004620();
  if (sVar1 == 0) {
    DAT_00016ee0 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}


================================================================