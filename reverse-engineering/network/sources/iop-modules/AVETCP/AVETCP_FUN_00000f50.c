FUNCTION FUN_00000f50 @ 0x00000f50 size=80
CALLERS (1): FUN_00004620@0x00004620
CALLEES (0): 

undefined4 FUN_00000f50(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    (&DAT_00016268)[(iVar1 >> 0x10) * 0x9c] = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 5);
  return 0;
}


================================================================