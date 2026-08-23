
undefined4 FUN_001d4e7c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    FUN_001eccd8(*(undefined4 *)(DAT_0025b78c + 0x520),param_2);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(iVar1 + 0x524);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(iVar1 + 0x528);
    *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar1 + 0x52c);
    *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(iVar1 + 0x530);
    *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(iVar1 + 0x534);
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(iVar1 + 0x538);
    *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(iVar1 + 0x53c);
    *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(iVar1 + 0x540);
    *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(iVar1 + 0x544);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

