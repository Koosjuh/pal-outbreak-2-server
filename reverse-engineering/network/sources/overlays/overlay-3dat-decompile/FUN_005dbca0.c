FUNCTION FUN_005dbca0 @ 0x005dbca0  size=584
CALLERS (0): 
CALLEES (5): FUN_005dfee0@0x005dfee0, FUN_005ddc20@0x005ddc20, FUN_005de330@0x005de330, FUN_005e07c0@0x005e07c0, FUN_005d7410@0x005d7410
----------------------------------------------------------------

void FUN_005dbca0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (((((cVar1 == '\x03') || (cVar1 == '\x02')) || (cVar1 == '\x01')) || (cVar1 != '\0')) &&
          (((*(char *)(iRam00701070 + 0x34) == '\0' &&
            ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 != 0)) &&
           (FUN_005e07c0(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                         *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),6,0),
           *(char *)(iRam00701068 + 0x68e84) != '\x01')))) {
    iVar2 = *(int *)(iRam00701068 + 0x5ffc0);
    if (iVar2 != 0) {
      cVar1 = *(char *)(param_1 + 6);
      if (cVar1 == '\x03') {
        FUN_005ddc20(*(float *)(param_1 + 0x34) + 2.0,*(float *)(param_1 + 0x38) + 2.0,0xe,
                     0xffffffffff000001,0,0x10,*(undefined4 *)(iVar2 + 100));
      }
      else if (cVar1 == '\x02') {
        uVar3 = FUN_005de330(4,0);
        FUN_005ddc20(*(float *)(param_1 + 0x34) + 2.0,*(float *)(param_1 + 0x38) + 2.0,0xe,
                     0xffffffffff000001,0,0x10,uVar3);
        uVar3 = FUN_005d7410();
        FUN_005ddc20(*(float *)(param_1 + 0x34) + 2.0 + 72.0,*(float *)(param_1 + 0x38) + 2.0,0xe,
                     0xffffffffff000001,0,0x10,uVar3);
      }
      else if ((cVar1 == '\x01') && (*(int *)(iVar2 + 0x60) != 0)) {
        FUN_005ddc20(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),0xe,
                     0xffffffffff000001,0,0x14);
      }
    }
    if (*(char *)(iRam00701078 + 1) == '\0') {
      func_0x001af030();
    }
  }
  return;
}



================================================================