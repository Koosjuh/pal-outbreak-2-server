FUNCTION FUN_005f85e0 @ 0x005f85e0  size=892
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005f85e0(undefined1 *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_40 [64];
  
  if (param_1[4] != '\x01') {
    if (param_1[4] != '\0') {
      return;
    }
    param_1[4] = 1;
    *param_1 = 1;
    param_1[1] = 1;
    *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(&DAT_00649780 + (char)param_1[3] * 4);
    *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649782 + (char)param_1[3] * 4);
    *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(&DAT_006497e0 + (char)param_1[3] * 2);
  }
  cVar1 = param_1[3];
  if ((long)cVar1 < 6) {
    cVar2 = *(char *)(cVar1 + 0x70b410);
    if ((cVar2 == -1) || (cVar2 == '\0')) {
      *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(&DAT_00649818 + cVar1 * 2);
      *(undefined2 *)(param_1 + 0x28) = 0x145;
      *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(&DAT_006497f8 + (char)param_1[3] * 2);
      if ((param_1[3] != '\0') && (cRam006c5497 == param_1[3])) {
        FUN_005af2e0(0x12);
        FUN_005af2c0(0);
        iVar3 = func_0x001ae3e0(0x649840);
        iVar3 = iVar3 * 9;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 1;
        }
        FUN_005af1e0((uint)*(ushort *)(&DAT_00649828 + (char)param_1[3] * 2) - (iVar3 >> 1),0x172,0,
                     0x649840);
      }
    }
    else if ((cRam006c4600 == '\0') || ((long)(int)(bRam006c45fc - 1) != (long)cVar1)) {
      *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(&DAT_00649780 + cVar1 * 4);
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649782 + (char)param_1[3] * 4);
      *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(&DAT_006497e0 + (char)param_1[3] * 2);
      if (param_1[3] == '\0') {
        if (cRam006c4600 == '\0') {
          param_1[1] = 1;
          FUN_005af2e0(0x12);
          FUN_005af2c0(0);
          uVar4 = FUN_0062fea0(7);
          func_0x00109728(auStack_40,0x649838,uRam006c3032,uVar4);
          FUN_005af1e0(*(undefined2 *)(&DAT_00649828 + (char)param_1[3] * 2),0x172,0,auStack_40);
        }
        else {
          param_1[1] = 0;
        }
      }
      else {
        FUN_005af2e0(0x12);
        FUN_005af2c0(0);
        if (cRam006c5497 == param_1[3]) {
          uVar4 = func_0x001b6f50(*(undefined1 *)((char)param_1[3] + 0x70b410));
          iVar3 = func_0x001ae3e0(uVar4);
          iVar3 = iVar3 * 9;
          if (iVar3 < 0) {
            iVar3 = iVar3 + 1;
          }
          uVar4 = func_0x001b6f50(*(undefined1 *)((char)param_1[3] + 0x70b410));
          FUN_005af1e0((uint)*(ushort *)(&DAT_00649828 + (char)param_1[3] * 2) - (iVar3 >> 1),0x172,
                       0,uVar4);
        }
      }
    }
    else {
      *(short *)(param_1 + 0x26) = *(short *)(&DAT_00649818 + cVar1 * 2) + 6;
      *(undefined2 *)(param_1 + 0x28) = 0x146;
      *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(&DAT_00649808 + (char)param_1[3] * 2);
    }
  }
  return;
}



================================================================