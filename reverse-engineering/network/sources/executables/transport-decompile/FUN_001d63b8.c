
void FUN_001d63b8(int param_1,undefined4 param_2)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  puVar1 = (ushort *)FUN_001ed2c0(param_2,0x10);
  if (puVar1 != (ushort *)0x0) {
    *puVar1 = 0x6000;
    *puVar1 = *puVar1 | 0x10;
    uVar2 = FUN_001ed60c(param_2);
    *(undefined4 *)(puVar1 + 6) = uVar2;
    *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 0x44);
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[1] = 0;
  }
  return;
}

