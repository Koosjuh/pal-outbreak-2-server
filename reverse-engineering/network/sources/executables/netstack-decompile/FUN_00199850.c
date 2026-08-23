
uint FUN_00199850(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_001999e0();
  uVar2 = puVar1[1];
  if ((*puVar1 & 0x80000000) != 0) {
    uVar2 = uVar2 - 1;
  }
  return uVar2;
}

