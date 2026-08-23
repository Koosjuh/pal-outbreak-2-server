
undefined1 FUN_0017e900(undefined8 param_1)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 auStack_50 [16];
  
  if ((*(int *)((int)param_1 * 0x334 + 0x277c0c) == 0) && (lVar2 = FUN_0017eb98(param_1), lVar2 < 0)
     ) {
    return 0;
  }
  lVar2 = FUN_0017ecc0(param_1);
  if (lVar2 == 0) {
    lVar2 = FUN_0017fc10(param_1,0x101800c,(uint)auStack_50 | 4,auStack_50);
    if (-1 < lVar2) {
      return auStack_50[0];
    }
  }
  else {
    puVar1 = (undefined1 *)FUN_0017ec58(param_1);
    if (*(int *)(puVar1 + 4) != 0) {
      return *puVar1;
    }
    lVar2 = FUN_0017eb98(param_1);
    if (-1 < lVar2) {
      return *puVar1;
    }
  }
  *(undefined4 *)((int)param_1 * 0x334 + 0x277c0c) = 0;
  FUN_0017eb20(param_1);
  return 0;
}

