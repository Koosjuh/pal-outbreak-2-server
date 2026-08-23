FUNCTION FUN_005e88c0 @ 0x005e88c0  size=152
CALLERS (0): 
CALLEES (3): FUN_005ef220@0x005ef220, FUN_005ef040@0x005ef040, FUN_005ef200@0x005ef200
----------------------------------------------------------------

undefined8 FUN_005e88c0(int *param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_005ef200();
  *(char *)(iRam007012a0 + 0x2d3) = (&DAT_006494b0)[*(byte *)(*param_1 + -1) - 0x30 & 0xff] + '0';
  *(undefined1 *)(iRam007012a0 + 0x2d4) = 0;
  iVar1 = func_0x0010a700(*param_1,0x648248);
  *param_1 = iVar1 + 1;
  FUN_005ef040(param_2);
  FUN_005ef220();
  return 0;
}



================================================================