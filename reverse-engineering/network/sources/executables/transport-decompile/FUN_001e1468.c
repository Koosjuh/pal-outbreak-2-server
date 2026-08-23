
undefined4 * FUN_001e1468(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_001e1e4c(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
    *puVar1 = 0;
    FUN_001eb22c(puVar1 + 2,0);
  }
  return puVar1;
}

