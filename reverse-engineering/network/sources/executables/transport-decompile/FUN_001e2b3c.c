
short FUN_001e2b3c(undefined4 param_1,int param_2)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  psVar3 = (short *)FUN_001e2a28(param_1);
  if (psVar3 == (short *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    sVar1 = -1;
  }
  else if (psVar3[1] == 1) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6d;
    sVar1 = -1;
  }
  else if (psVar3[2] == -1) {
    sVar1 = FUN_001ef610(*(undefined4 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),0);
    if (-1 < sVar1) {
      *psVar3 = sVar1;
      sVar1 = 0;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    sVar1 = -1;
  }
  return sVar1;
}

