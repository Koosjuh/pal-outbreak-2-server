
undefined4 FUN_001ce420(long param_1)

{
  long lVar1;
  long lVar2;
  long extraout_t3;
  char *pcVar3;
  
  if (param_1 != 0) {
    pcVar3 = (char *)0x36c350;
    for (lVar2 = 0; lVar2 < 0x10; lVar2 = (long)((int)lVar2 + 1)) {
      if ((((*pcVar3 != '\0') && ((pcVar3[3] & 4U) != 0)) && (*(int *)(pcVar3 + 4) != 0)) &&
         (lVar1 = FUN_001ce360(*(int *)(pcVar3 + 4),param_1), lVar2 = extraout_t3, lVar1 != 0)) {
        return 1;
      }
      pcVar3 = pcVar3 + 0xc;
    }
  }
  return 0;
}

