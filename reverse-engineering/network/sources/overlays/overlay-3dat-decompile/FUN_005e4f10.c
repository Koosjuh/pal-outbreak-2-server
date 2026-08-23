FUNCTION FUN_005e4f10 @ 0x005e4f10  size=744
CALLERS (1): FUN_005dd660@0x005dd660
CALLEES (5): FUN_005ddb40@0x005ddb40, FUN_005ddc20@0x005ddc20, FUN_005de330@0x005de330, FUN_005e1670@0x005e1670, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005e4ff0) */
/* WARNING: Removing unreachable block (ram,0x005e509c) */

void FUN_005e4f10(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 unaff_s0_lo;
  float fVar4;
  float fVar5;
  
  FUN_005e1670(*(float *)(param_1 + 0x34),*(float *)(param_1 + 0x38),
               *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x40),
               *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x44));
  uVar3 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar3,
               (int)(*(float *)(param_1 + 0x34) + (*(float *)(param_1 + 0x40) - 84.0) / 2.0),
               (int)(*(float *)(param_1 + 0x38) + 145.0),0x54,0x20,0x2a,0);
  uVar3 = FUN_005de330(7,3);
  iVar2 = func_0x0010a050(uVar3);
  fVar5 = *(float *)(param_1 + 0x40);
  fVar4 = *(float *)(param_1 + 0x34);
  uVar3 = FUN_005de330(7,3);
  FUN_005ddc20(fVar4 + (fVar5 - (float)((uint)(iVar2 * 0x14) >> 1)) / 2.0,
               *(float *)(param_1 + 0x38) + 85.0,0,0xffffffffffffffff,0,0x14,uVar3);
  uVar3 = FUN_005de330(7,4);
  iVar2 = func_0x0010a050(uVar3);
  fVar5 = *(float *)(param_1 + 0x40);
  fVar4 = *(float *)(param_1 + 0x34);
  uVar3 = FUN_005de330(7,4);
  FUN_005ddc20(fVar4 + (fVar5 - (float)((uint)(iVar2 * 0x14) >> 1)) / 2.0,
               *(float *)(param_1 + 0x38) + 145.0 + 6.0,0xd,0xffffffffffffffff,1,0x14,uVar3);
  if (*(char *)(iRam00701078 + 2) == '\x01') {
    unaff_s0_lo = (undefined2)
                  (int)(*(float *)(param_1 + 0x34) + (*(float *)(param_1 + 0x40) - 84.0) / 2.0);
    cVar1 = *(char *)(param_1 + 7);
  }
  else {
    cVar1 = *(char *)(param_1 + 7);
  }
  if (cVar1 == '\x01') {
    uVar3 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffff808080,uVar3,unaff_s0_lo,(int)(*(float *)(param_1 + 0x38) + 145.0),0x54
                 ,0x20,0x2a,0x20);
    func_0x001af030();
  }
  return;
}



================================================================