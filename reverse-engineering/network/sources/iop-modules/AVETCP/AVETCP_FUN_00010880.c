FUNCTION FUN_00010880 @ 0x00010880 size=140
CALLERS (1): FUN_000097cc@0x000097cc
CALLEES (2): FUN_00000168@0x00000168, FUN_000120e0@0x000120e0

undefined4 FUN_00010880(ushort param_1,int param_2,short param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = (int)((uint)param_1 << 0x10) >> 0xd;
    if (*(int *)((int)&DAT_00018864 + iVar1) != -1) {
      *(short *)(&DAT_00018862 + iVar1) = param_3;
      *(ushort *)(&DAT_00018860 + iVar1) = param_1;
      FUN_000120e0(*(undefined4 *)((int)&DAT_00018864 + iVar1));
    }
  }
  else {
    FUN_00000168((int)(short)param_1,param_2,(int)param_3,*param_4);
  }
  return 0;
}


================================================================