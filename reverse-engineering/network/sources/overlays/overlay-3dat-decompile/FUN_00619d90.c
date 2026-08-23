FUNCTION FUN_00619d90 @ 0x00619d90  size=108
CALLERS (1): FUN_00619e00@0x00619e00
CALLEES (0): 
----------------------------------------------------------------

bool FUN_00619d90(int param_1)

{
  bool bVar1;
  int iStack_4;
  
  iStack_4 = iRam00715430;
  if (param_1 != -1) {
    iStack_4 = *(int *)(param_1 * 4 + 0x7153f0);
  }
  bVar1 = iStack_4 != 0;
  if (bVar1) {
    func_0x00194050(1,&iStack_4);
    func_0x0018c8d0(4,iStack_4);
  }
  return bVar1;
}



================================================================