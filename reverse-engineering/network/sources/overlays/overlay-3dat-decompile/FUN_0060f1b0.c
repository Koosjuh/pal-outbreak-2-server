FUNCTION FUN_0060f1b0 @ 0x0060f1b0  size=92
CALLERS (1): FUN_00610830@0x00610830
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0060f1b0(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = func_0x00109d70(*(undefined4 *)(param_1 + 8),0x64b7b0);
  if ((lVar2 == 0) && (lVar2 = func_0x00109d70(*(undefined4 *)(param_1 + 0xc),0x64b7c0), lVar2 == 0)
     ) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================