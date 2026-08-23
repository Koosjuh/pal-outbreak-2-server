FUNCTION FUN_00002bac @ 0x00002bac size=132
CALLERS (0): 
CALLEES (0): 

undefined4 FUN_00002bac(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    (&DAT_00009718)[iVar2] = 0;
    *(undefined4 *)((int)&DAT_0000db84 + iVar1) = 2;
    *(undefined4 *)((int)&DAT_0000db88 + iVar1) = 0;
    *(undefined4 *)((int)&DAT_0000db8c + iVar1) = 1;
    *(undefined4 *)((int)&DAT_0000db90 + iVar1) = 6;
    *(undefined4 *)((int)&DAT_0000db94 + iVar1) = 1;
    *(undefined2 *)((int)&DAT_0000db98 + iVar1) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x1c;
  } while (iVar2 < 2);
  return 0;
}


================================================================