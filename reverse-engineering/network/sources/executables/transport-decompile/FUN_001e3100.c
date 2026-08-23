
undefined4 FUN_001e3100(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  psVar3 = (short *)FUN_001e2a28(param_1);
  if (psVar3 == (short *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6c;
    uVar4 = 0xffffffff;
  }
  else if (psVar3[2] == -1) {
    if (param_3 == 0x10) {
      if (psVar3[1] == 1) {
        *(undefined4 *)(psVar3 + 0xe) = *(undefined4 *)(param_2 + 4);
        *(uint *)(psVar3 + 0x10) = (uint)*(ushort *)(param_2 + 2);
      }
      else {
        if (psVar3[1] != 2) {
          puVar2 = (undefined4 *)FUN_00103de8();
          *puVar2 = 0x6c;
          return 0xffffffff;
        }
        sVar1 = FUN_001efee0(0,0,*(undefined2 *)(param_2 + 2));
        FUN_00114ac8(0x259628,sVar1);
        if (sVar1 == -4) {
          puVar2 = (undefined4 *)FUN_00103de8();
          *puVar2 = 0x7d;
          return 0xffffffff;
        }
        if (sVar1 == -3) {
          puVar2 = (undefined4 *)FUN_00103de8();
          *puVar2 = 0xffff;
          return 0xffffffff;
        }
        *psVar3 = sVar1;
        psVar3[1] = 2;
        psVar3[2] = 0x7f;
      }
      uVar4 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0xe;
      uVar4 = 0xffffffff;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6b;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

