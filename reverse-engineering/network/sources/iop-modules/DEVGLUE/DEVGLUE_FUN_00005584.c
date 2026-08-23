FUNCTION FUN_00005584 @ 0x00005584 size=40
CALLERS (0): 
CALLEES (0): 

undefined4 FUN_00005584(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = 4;
  do {
    *(undefined4 *)((int)&DAT_00009720 + iVar1) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + -4;
  } while (-1 < iVar2);
  return 0;
}


================================================================