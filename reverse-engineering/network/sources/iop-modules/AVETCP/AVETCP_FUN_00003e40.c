FUNCTION FUN_00003e40 @ 0x00003e40 size=156
CALLERS (1): FUN_00010130@0x00010130
CALLEES (0): 

undefined4 FUN_00003e40(short param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (int)param_1;
  if (((iVar2 < (int)(uint)DAT_0001617e) && (-1 < iVar2)) &&
     (iVar2 = iVar2 * 0x30 + DAT_000161a0, *(short *)(iVar2 + 8) != 0)) {
    uVar3 = 0;
    if (*(char *)(iVar2 + 0x14) != '\0') {
      uVar3 = *(undefined4 *)(iVar2 + 0x18);
    }
    *param_2 = uVar3;
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)(iVar2 + 0xc);
    uVar1 = 0;
    if (*(char *)(iVar2 + 0x15) != '\0') {
      uVar1 = *(undefined2 *)(iVar2 + 0xe);
    }
    *(undefined2 *)((int)param_2 + 6) = uVar1;
    return 0;
  }
  return 0xfffffffc;
}


================================================================