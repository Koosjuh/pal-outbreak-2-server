FUNCTION FUN_005e02e0 @ 0x005e02e0  size=64
CALLERS (2): FUN_005c80a0@0x005c80a0, FUN_005c8870@0x005c8870
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e02e0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  uRam00701098 = 0;
  uRam00701090 = 0;
  do {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar1 + 0x7010a0) = 0;
  } while (iVar2 < 0x80);
  return;
}



================================================================