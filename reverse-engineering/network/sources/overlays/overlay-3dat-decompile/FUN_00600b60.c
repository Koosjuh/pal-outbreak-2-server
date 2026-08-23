FUNCTION FUN_00600b60 @ 0x00600b60  size=432
CALLERS (2): FUN_005fede0@0x005fede0, FUN_00600200@0x00600200
CALLEES (2): FUN_00600aa0@0x00600aa0, FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

undefined4 FUN_00600b60(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  lVar4 = FUN_005b14b0(0x800);
  if (lVar4 == 0) {
    lVar4 = FUN_005b14b0(0x400);
    if (lVar4 != 0) {
      bVar1 = *(byte *)(param_1 + 0x908);
      uVar5 = FUN_00600aa0(bVar1,1);
      if ((ulong)bVar1 == (uVar5 & 0xff)) {
        cVar2 = *(char *)(param_1 + 0x908);
        iVar6 = (cVar2 * 0x3c - (int)cVar2) * 0x10 + param_1;
        if (*(char *)(iVar6 + 0x30ac) == '\0') {
          uVar3 = FUN_00600aa0(cVar2,1);
          *(undefined1 *)(param_1 + 0x908) = uVar3;
          uVar7 = 1;
        }
        else {
          lVar4 = func_0x00109d70(param_1 + 0x3f6c,iVar6 + 0x30ac);
          if (lVar4 != 0) {
            uVar7 = 1;
          }
        }
        if ((long)*(char *)(param_1 + 0x908) == (ulong)bVar1) {
          uVar7 = 0;
        }
      }
      else {
        *(char *)(param_1 + 0x908) = (char)uVar5;
        uVar7 = 1;
        func_0x001b0140(0);
      }
    }
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x908);
    uVar5 = FUN_00600aa0(bVar1,0);
    if ((ulong)bVar1 != (uVar5 & 0xff)) {
      *(char *)(param_1 + 0x908) = (char)uVar5;
      uVar7 = 1;
      func_0x001b0140(0);
      cVar2 = *(char *)(param_1 + 0x3f6c);
      goto LAB_00600cd4;
    }
    cVar2 = *(char *)(param_1 + 0x908);
    iVar6 = (cVar2 * 0x3c - (int)cVar2) * 0x10 + param_1;
    if (*(char *)(iVar6 + 0x30ac) == '\0') {
      uVar3 = FUN_00600aa0(cVar2,0);
      *(undefined1 *)(param_1 + 0x908) = uVar3;
      uVar7 = 1;
    }
    else {
      lVar4 = func_0x00109d70(param_1 + 0x3f6c,iVar6 + 0x30ac);
      if (lVar4 != 0) {
        uVar7 = 1;
      }
    }
    if ((long)*(char *)(param_1 + 0x908) == (ulong)bVar1) {
      uVar7 = 0;
    }
  }
  cVar2 = *(char *)(param_1 + 0x3f6c);
LAB_00600cd4:
  if (cVar2 == '\0') {
    uVar3 = FUN_00600aa0(*(undefined1 *)(param_1 + 0x908),0);
    *(undefined1 *)(param_1 + 0x908) = uVar3;
  }
  *(undefined1 *)(param_1 + 0x44c) = *(undefined1 *)(param_1 + 0x908);
  return uVar7;
}



================================================================