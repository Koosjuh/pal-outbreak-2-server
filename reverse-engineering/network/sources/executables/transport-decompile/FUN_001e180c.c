
undefined4
FUN_001e180c(int param_1,int param_2,ushort param_3,ushort param_4,byte param_5,byte param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x50c) == 0) {
    iVar2 = FUN_001ebca8(param_2);
    if (iVar2 == param_4 + 0x10) {
      *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x44);
      *(ushort *)(param_2 + 0x2c) = param_3;
      *(ushort *)(param_2 + 0x2e) = (ushort)param_6;
      *(short *)(param_2 + 0x2e) = *(short *)(param_2 + 0x2e) << 8;
      *(ushort *)(param_2 + 0x2e) = *(ushort *)(param_2 + 0x2e) | (ushort)param_5;
      *(ushort *)(param_2 + 0x2c) = *(ushort *)(param_2 + 0x2c) | param_4 + 0x10 & 0x3ff;
      if ((param_3 & 0x8000) == 0) {
        FUN_001ebbd0(param_2,2);
        iVar2 = *(int *)(param_1 + 0xc);
        *(int *)(param_2 + 0x34) = iVar2;
        *(int *)(param_1 + 0xc) = iVar2 + 1;
      }
      else {
        FUN_001ed524(param_2,0x11);
        FUN_001ebbd0(param_2,0x8001);
      }
      FUN_001eb3b8(*(int *)(param_1 + 0x60) + 8,param_2);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x27;
    }
  }
  else {
    uVar1 = 0x27;
  }
  return uVar1;
}

