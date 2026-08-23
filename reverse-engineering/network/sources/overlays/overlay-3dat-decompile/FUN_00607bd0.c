FUNCTION FUN_00607bd0 @ 0x00607bd0  size=288
CALLERS (1): FUN_00607a10@0x00607a10
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_00607bd0(int param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  
  *(short *)(param_2 + 0x14) = *(short *)(param_2 + 0x14) + 1;
  cVar1 = param_2[1];
  if (cVar1 == '\x02') {
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
    iVar2 = *(int *)(param_2 + 0x18);
    uVar3 = 0xfffffffe;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return 0xffffffff;
      }
      FUN_005b09b0(param_2 + 7,cRam008744f8 + -1);
      lVar4 = FUN_005b14b0(0x10);
      if (lVar4 != 0) {
        param_2[1] = param_2[1] + '\x01';
        uRam00874f33 = 0;
        func_0x001b0140(1);
        *(undefined1 *)(param_1 + 0x454) = 0;
        *(undefined4 *)(param_2 + 0x18) = 8;
        return 0xffffffff;
      }
      lVar4 = FUN_005b14b0(0x200);
      if (lVar4 == 0) {
        return 0xffffffff;
      }
      *param_2 = 4;
      param_2[1] = 0;
      func_0x001b0140(2);
      return 0xffffffff;
    }
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
    iVar2 = *(int *)(param_2 + 0x18);
    uVar3 = 0;
  }
  if (-1 < iVar2) {
    return 0xffffffff;
  }
  return uVar3;
}



================================================================