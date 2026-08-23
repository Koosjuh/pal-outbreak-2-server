FUNCTION FUN_005e5650 @ 0x005e5650  size=704
CALLERS (1): FUN_005dd660@0x005dd660
CALLEES (5): FUN_005ddb40@0x005ddb40, FUN_005ddc20@0x005ddc20, FUN_005de330@0x005de330, FUN_005e1670@0x005e1670, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005e57d0) */

void FUN_005e5650(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 unaff_s1_lo;
  float fVar4;
  
  FUN_005e1670(*(float *)(param_1 + 0x34),*(float *)(param_1 + 0x38),
               *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x40),
               *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x44));
  uVar3 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar3,(int)(*(float *)(param_1 + 0x34) + 198.0),
               (int)(*(float *)(param_1 + 0x38) + 185.0),0x54,0x20,0x2a,0);
  if (cRam00700ff0 == '\0') {
    uVar3 = FUN_005de330(8,0);
    FUN_005ddc20(*(float *)(param_1 + 0x34) + 20.0,*(float *)(param_1 + 0x38) + 85.0,0,
                 0xffffffffffffffff,0,0x14,uVar3);
  }
  else {
    uVar3 = FUN_005de330(8,2);
    FUN_005ddc20(*(float *)(param_1 + 0x34) + 20.0,*(float *)(param_1 + 0x38) + 85.0,0,
                 0xffffffffffffffff,0,0x14,uVar3);
  }
  uVar3 = FUN_005de330(8,1);
  iVar2 = func_0x0010a050(uVar3);
  fVar4 = *(float *)(param_1 + 0x34);
  uVar3 = FUN_005de330(8,1);
  FUN_005ddc20(fVar4 + 198.0 + (float)(0x54 - ((uint)(iVar2 * 0x14) >> 1) >> 1),
               *(float *)(param_1 + 0x38) + 185.0 + 6.0,0xd,0xffffffffffffffff,1,0x14,uVar3);
  if (*(char *)(iRam00701078 + 2) == '\x01') {
    unaff_s1_lo = (undefined2)(int)(*(float *)(param_1 + 0x34) + 198.0);
    cVar1 = *(char *)(param_1 + 7);
  }
  else {
    cVar1 = *(char *)(param_1 + 7);
  }
  if (cVar1 == '\x01') {
    uVar3 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffff808080,uVar3,unaff_s1_lo,(int)(*(float *)(param_1 + 0x38) + 185.0),0x54
                 ,0x1f,0x2a,0x20);
    func_0x001af030();
  }
  return;
}



================================================================