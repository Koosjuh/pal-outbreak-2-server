FUNCTION FUN_005b3d80 @ 0x005b3d80  size=336
CALLERS (1): FUN_005b3c30@0x005b3c30
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined8 FUN_005b3d80(undefined8 param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  cVar1 = param_2[1];
  if (cVar1 == '\x02') {
    cVar1 = param_2[7];
    if (*(char *)(cVar1 * 0x10 + 0x6c4634) == '\0') {
      if (*(char *)((cVar1 * 4 + (int)cVar1) * 4 + 0x6c4674) == '\0') {
        *param_2 = 3;
        param_2[1] = 0;
        param_2[2] = 0;
      }
      else {
        *param_2 = 3;
        param_2[1] = 4;
        param_2[2] = 0;
      }
    }
    else {
      *param_2 = 2;
      param_2[1] = 0;
      param_2[2] = 0;
    }
  }
  else if (cVar1 == '\x01') {
    iVar2 = *(int *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      param_2[1] = param_2[1] + '\x01';
    }
  }
  else if (((cVar1 == '\0') && (lVar3 = FUN_005b09b0(param_2 + 7,2,2), lVar3 == 0)) &&
          (lVar3 = FUN_005b14b0(0x10), lVar3 != 0)) {
    param_2[1] = param_2[1] + '\x01';
    *(undefined4 *)(param_2 + 0x18) = 2;
    func_0x001b0140(1);
    func_0x00109eb8(0x6c4a84,(char)param_2[7] * 0x14 + 0x6c4674);
  }
  return 0;
}



================================================================