FUNCTION FUN_000055b0 @ 0x000055b0 size=84
CALLERS (0): 
CALLEES (0): 

undefined4 FUN_000055b0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    (&DAT_0000de90)[(iVar1 >> 0x10) * 0x70a] = 0xffff;
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 < 1);
  return 0;
}


================================================================