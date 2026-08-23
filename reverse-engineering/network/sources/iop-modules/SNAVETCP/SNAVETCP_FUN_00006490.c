FUNCTION FUN_00006490 @ 0x00006490 size=208
CALLERS (1): FUN_00005f68@0x00005f68
CALLEES (2): FUN_00006714@0x00006714, FUN_00006978@0x00006978

undefined4 *
FUN_00006490(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00006714();
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00006978();
    puVar3 = (undefined4 *)FUN_00006714();
    if (puVar3 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  *(undefined1 *)((int)puVar3 + 0xb) = 0;
  *(undefined1 *)((int)puVar3 + 10) = param_4;
  puVar2 = DAT_0001689c;
  *puVar3 = param_1;
  *(undefined2 *)((int)puVar3 + 6) = param_3;
  *(undefined2 *)(puVar3 + 1) = param_2;
  if (puVar2 == (undefined4 *)0x0) {
    puVar3[3] = 0;
    DAT_0001689c = puVar3;
    DAT_000168a0 = puVar3;
  }
  else {
    puVar3[3] = 0;
    piVar1 = (int *)((int)DAT_000168a0 + 0xc);
    DAT_000168a0 = puVar3;
    *piVar1 = (int)puVar3;
  }
  puVar3[5] = 0;
  puVar3[4] = 0;
  return puVar3;
}


================================================================