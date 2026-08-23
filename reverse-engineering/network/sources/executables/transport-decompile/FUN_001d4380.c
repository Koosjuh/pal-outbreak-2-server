
undefined4 FUN_001d4380(char *param_1)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if (cRam0036d648 == '\0') {
    *param_1 = '\0';
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_001f26e0(0,0,0);
    lVar3 = FUN_001f2728(0,0);
    uRam0036d5a8 = 1;
    lVar4 = FUN_001f2778(0);
    uRam0036d5a0 = 0;
    lVar5 = FUN_001f33e8(0,0);
    if ((((lVar2 == 0) && (lVar3 == 0)) && (lVar4 == 0)) && (lVar5 == 0)) {
      *param_1 = *param_1 + '\x01';
    }
    uVar1 = 1;
  }
  return uVar1;
}

