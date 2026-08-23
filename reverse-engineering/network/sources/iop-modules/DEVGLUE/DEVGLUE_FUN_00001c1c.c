FUNCTION FUN_00001c1c @ 0x00001c1c size=312
CALLERS (1): FUN_00001d54@0x00001d54
CALLEES (0): 

char * FUN_00001c1c(int param_1)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return (char *)0x0;
  }
  pcVar2 = (char *)0x0;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    pcVar2 = "";
    break;
  case 1:
    pcVar2 = "\x01";
    break;
  case 2:
    pcVar2 = (char *)0x2580;
    break;
  case 3:
    pcVar2 = (char *)0x4b00;
    break;
  case 4:
    pcVar2 = "eceive packet\n";
    break;
  case 5:
    pcVar2 = (char *)0xe100;
    break;
  case 6:
    pcVar2 = (char *)0x1c200;
  }
  uVar1 = 0x80000000;
  if (*(int *)(param_1 + 4) == 1) {
    pcVar2 = (char *)((uint)pcVar2 | 0x80000000);
    uVar1 = 0x40000000;
LAB_00001cb4:
    pcVar2 = (char *)((uint)pcVar2 | uVar1);
  }
  else if (*(int *)(param_1 + 4) == 0) goto LAB_00001cb4;
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = 0x8000000;
  if (iVar3 == 1) {
LAB_00001ce4:
    pcVar2 = (char *)((uint)pcVar2 | uVar1);
  }
  else {
    if (iVar3 == 0) {
      uVar1 = 0x4000000;
      goto LAB_00001ce4;
    }
    uVar1 = 0xc000000;
    if (iVar3 == 2) goto LAB_00001ce4;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    pcVar2 = (char *)((uint)pcVar2 | 0x800000);
    uVar1 = 0x1000000;
  }
  else {
    uVar1 = 0x2000000;
    if (*(int *)(param_1 + 0xc) != 1) goto LAB_00001d18;
  }
  pcVar2 = (char *)((uint)pcVar2 | uVar1);
LAB_00001d18:
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = 0x20000000;
  }
  else {
    if (*(int *)(param_1 + 0x14) != 1) {
      return pcVar2;
    }
    uVar1 = 0x30000000;
  }
  return (char *)((uint)pcVar2 | uVar1);
}


================================================================