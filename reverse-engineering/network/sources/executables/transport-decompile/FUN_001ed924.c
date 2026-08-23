
undefined4 FUN_001ed924(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_001ebd04(param_2);
  uVar2 = FUN_001ebca8(param_1);
  if (iVar1 - 0x2cU < uVar2) {
    uVar3 = 0xffffe0c2;
  }
  else {
    iVar1 = FUN_001ebca8(param_1);
    FUN_001069a8(param_2 + 0x10,param_1 + 0x10,iVar1 + 0x1c);
    uVar4 = FUN_001ebca8(param_1);
    FUN_001ebcd0(param_2,uVar4);
    FUN_001ebc10(param_2,0xffff);
    uVar4 = FUN_001ebbd0(param_1,0);
    FUN_001ebbd0(param_2,uVar4);
    uVar3 = 0;
  }
  return uVar3;
}

