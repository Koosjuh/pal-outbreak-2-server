
undefined4 FUN_001c3c90(int param_1,uint param_2,char param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x28);
  iVar3 = *(int *)(param_1 + 0x30);
  FUN_00106b60(iVar2,0,8);
  param_2 = param_2 & 0xffff;
  *(char *)(iVar2 + 2) = param_3;
  if (param_2 == 0) {
    *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(iVar3 + 3);
    *(undefined1 *)(iVar2 + 4) = *(undefined1 *)(iVar3 + 4);
  }
  else {
    *(undefined *)(iVar2 + 3) = (&DAT_002484c0)[param_2];
    *(undefined *)(iVar2 + 4) = (&DAT_00248510)[param_2];
  }
  if (param_3 == '\x02') {
    *(undefined1 *)(iVar2 + 5) = *(undefined1 *)(iVar3 + 5);
  }
  else {
    if ((param_3 != '\x10') && (param_3 != '\x01')) {
      *(undefined1 *)(iVar2 + 6) = param_4;
      goto LAB_001c3d6c;
    }
    cVar1 = *(char *)(param_1 + 0x3d);
    *(char *)(param_1 + 0x3d) = cVar1 + '\x01';
    *(char *)(iVar2 + 5) = cVar1;
  }
  *(undefined1 *)(iVar2 + 6) = param_4;
LAB_001c3d6c:
  *(undefined1 *)(iVar2 + 7) = 0xff;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return *(undefined4 *)(param_1 + 0x2c);
}

