FUNCTION FUN_00616a58 @ 0x00616a58  size=84
CALLERS (1): FUN_00616b40@0x00616b40
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_00616a58(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = func_0x0011b8e0();
  iVar1 = DAT_00654208;
  DAT_00654208 = 0xffffffff;
  if (lVar2 != 0) {
    func_0x0011b938();
  }
  if (-1 < iVar1) {
    func_0x001128b0(iVar1);
  }
  return 0;
}



================================================================