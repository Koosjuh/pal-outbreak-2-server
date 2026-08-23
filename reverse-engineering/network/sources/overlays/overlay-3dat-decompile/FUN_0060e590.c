FUNCTION FUN_0060e590 @ 0x0060e590  size=204
CALLERS (1): FUN_0060e820@0x0060e820
CALLEES (1): FUN_006166f0@0x006166f0
----------------------------------------------------------------

void FUN_0060e590(int param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  
  FUN_006166f0(param_2);
  iVar2 = (int)param_2;
  func_0x00109eb8(iVar2 + 0xe00,param_1 + 0x820);
  func_0x00109eb8(iVar2 + 0xf00,param_1 + 0x920);
  if (*(char *)(param_1 + 9) == '\x01') {
    *(undefined4 *)(iVar2 + 0x130c) = 3;
  }
  else {
    *(undefined4 *)(iVar2 + 0x130c) = 1;
  }
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\x04') {
    *(undefined4 *)(iVar2 + 0x1310) = 6;
  }
  else if (cVar1 == '\x03') {
    *(undefined4 *)(iVar2 + 0x1310) = 5;
  }
  else if (cVar1 == '\x02') {
    *(undefined4 *)(iVar2 + 0x1310) = 3;
  }
  else if (cVar1 == '\x01') {
    *(undefined4 *)(iVar2 + 0x1310) = 2;
  }
  else {
    *(undefined4 *)(iVar2 + 0x1310) = 1;
  }
  return;
}



================================================================