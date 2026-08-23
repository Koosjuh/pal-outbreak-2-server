FUNCTION FUN_006365d0 @ 0x006365d0  size=200
CALLERS (1): FUN_00636890@0x00636890
CALLEES (1): FUN_006381e0@0x006381e0
----------------------------------------------------------------

void FUN_006365d0(float param_1,short param_2,undefined4 param_3)

{
  float *pfVar1;
  undefined2 uStack_10;
  short sStack_e;
  undefined2 uStack_c;
  short sStack_a;
  undefined4 uStack_8;
  
  pfVar1 = *(float **)(iRam00715da8 + 4);
  uStack_10 = (undefined2)(int)(param_1 + *pfVar1 * *(float *)(iRam00715da8 + 0x14));
  uStack_c = (undefined2)
             (int)(param_1 +
                  *(float *)(iRam00715da8 + 0x14) *
                  (*pfVar1 + *(float *)(&DAT_00690d70 + (uint)*(ushort *)((int)pfVar1 + 6) * 8)));
  sStack_e = param_2 + *(short *)(pfVar1 + 1);
  sStack_a = param_2 + *(short *)(pfVar1 + 1) +
             *(short *)(&DAT_00690d74 + (uint)*(ushort *)((int)pfVar1 + 6) * 8);
  uStack_8 = param_3;
  FUN_006381e0(&uStack_10,0xffffffffffffffe4);
  return;
}



================================================================