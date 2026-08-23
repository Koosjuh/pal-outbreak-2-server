FUNCTION FUN_005b0550 @ 0x005b0550  size=260
CALLERS (0): 
CALLEES (2): FUN_005b0660@0x005b0660, FUN_005b0750@0x005b0750
----------------------------------------------------------------

void FUN_005b0550(int param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uStack_30;
  
  puVar5 = (undefined8 *)&DAT_00638a20;
  puVar6 = &uStack_30;
  iVar4 = 2;
  do {
    uVar1 = *puVar5;
    uVar2 = *(undefined4 *)(puVar5 + 1);
    uVar3 = *(undefined4 *)((int)puVar5 + 0xc);
    iVar4 = iVar4 + -1;
    *(int *)puVar6 = (int)uVar1;
    *(int *)((int)puVar6 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined4 *)(puVar6 + 1) = uVar2;
    *(undefined4 *)((int)puVar6 + 0xc) = uVar3;
    puVar5 = puVar5 + 2;
    puVar6 = puVar6 + 2;
  } while (0 < iVar4);
  *puVar6 = *puVar5;
  if (*(char *)(param_1 + 4) == '\x01') {
    if (*(char *)(param_1 + 5) == '\0') {
      FUN_005b0660();
    }
    else {
      FUN_005b0750();
    }
  }
  else if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 6) = 0;
    *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
    if (*(char *)(param_1 + 3) == cRam006c5497) {
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined1 *)(param_1 + 5) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x2c) = 0xffffff;
      *(undefined1 *)(param_1 + 5) = 1;
    }
    *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)((int)&uStack_30 + *(char *)(param_1 + 3) * 4);
    *(undefined2 *)(param_1 + 0x28) =
         *(undefined2 *)((int)&uStack_30 + *(char *)(param_1 + 3) * 4 + 2);
  }
  return;
}



================================================================