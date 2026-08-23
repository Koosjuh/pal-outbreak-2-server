FUNCTION FUN_00607fe0 @ 0x00607fe0  size=164
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_00607fe0(int param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uStack_30;
  undefined4 auStack_28 [2];
  undefined8 auStack_20 [4];
  
  puVar6 = &uStack_30;
  puVar7 = (undefined8 *)&DAT_0064a0d0;
  iVar5 = 2;
  do {
    uVar1 = *puVar7;
    uVar3 = *(undefined4 *)(puVar7 + 1);
    uVar4 = *(undefined4 *)((int)puVar7 + 0xc);
    iVar5 = iVar5 + -1;
    *(int *)puVar6 = (int)uVar1;
    *(int *)((int)puVar6 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined4 *)(puVar6 + 1) = uVar3;
    *(undefined4 *)((int)puVar6 + 0xc) = uVar4;
    puVar7 = puVar7 + 2;
    puVar6 = puVar6 + 2;
  } while (0 < iVar5);
  *puVar6 = *puVar7;
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 1) = 1;
    *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
  }
  uVar2 = (ulong)cRam006c5497;
  if (10 < uVar2) {
    uVar2 = 10;
  }
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)((int)&uStack_30 + (int)uVar2 * 4);
  return;
}



================================================================