
void FUN_001cf8e0(char param_1,uint param_2,uint param_3,uint param_4,long param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  
  uVar5 = 0;
  if ((sRam003433a8 != 1) && (param_5 != 0)) {
    uVar5 = 0xffffffff80000000;
  }
  if (param_1 == '\x01') {
    iVar6 = *(int *)((param_3 & 0xff) * 8 + 0x3c2250);
    FUN_001cbc20((param_2 & 0xff) * 4 + 0x1300);
    uVar5 = uVar5 | 0x20000000;
  }
  else {
    iVar6 = *(int *)((param_3 & 0xff) * 8 + 0x3c18b0);
    FUN_001cbc20((param_2 & 0xff) * 4 + 0x1200);
  }
  FUN_001cf360();
  iVar1 = (param_2 & 0xff) * 0x1468;
  uVar2 = FUN_001ab460(0x20,9);
  *(undefined4 *)(iVar1 + 0x498578) = uVar2;
  puVar3 = (undefined1 *)(iVar6 + (param_4 & 0xff) * 0x10);
  *(int *)(iVar1 + 0x497d70) = iVar1 + 0x498590;
  *(int *)(iVar1 + 0x497d74) = iVar1 + 0x498790;
  *(int *)(iVar1 + 0x498588) = iVar1 + 0x498990;
  lVar4 = FUN_001cde00((int *)(iVar1 + 0x497d70),*puVar3,puVar3[1],uVar5 | 2,puVar3[4]);
  if (lVar4 == 0) {
    FUN_001ab580(*(undefined4 *)(iVar1 + 0x498578));
    *(undefined4 *)(iVar1 + 0x498578) = 0;
  }
  return;
}

