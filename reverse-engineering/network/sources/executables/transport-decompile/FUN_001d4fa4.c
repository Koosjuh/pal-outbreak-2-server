
undefined4 FUN_001d4fa4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    FUN_001ecd28(*(undefined4 *)(DAT_0025b78c + 0x520));
    *(undefined4 *)(iVar1 + 0x524) = 0;
    *(undefined4 *)(iVar1 + 0x528) = 0;
    *(undefined4 *)(iVar1 + 0x52c) = 0;
    *(undefined4 *)(iVar1 + 0x530) = 0;
    *(undefined4 *)(iVar1 + 0x534) = 0;
    *(undefined4 *)(iVar1 + 0x538) = 0;
    *(undefined4 *)(iVar1 + 0x53c) = 0;
    *(undefined4 *)(iVar1 + 0x540) = 0;
    *(undefined4 *)(iVar1 + 0x544) = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

