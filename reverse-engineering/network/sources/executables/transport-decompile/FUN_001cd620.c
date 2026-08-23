
void FUN_001cd620(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char *pcVar2;
  long extraout_a3;
  
  lVar1 = FUN_001cd500(param_2,param_3,param_3,param_1);
  if (lVar1 != 0) {
    pcVar2 = (char *)lVar1;
    if ((extraout_a3 == 1) && (((pcVar2[0xf] & 2U) != 0 || ((pcVar2[0xf] & 4U) != 0)))) {
      *pcVar2 = *pcVar2 + -1;
      pcVar2[0xf] = pcVar2[0xf] & 0xfe;
    }
    else if ((extraout_a3 == 4) && ((pcVar2[0xf] & 2U) != 0)) {
      *pcVar2 = *pcVar2 + -1;
      pcVar2[0xf] = pcVar2[0xf] & 0xfb;
    }
    else {
      if ((pcVar2[0xf] & 4U) != 0) {
        *pcVar2 = '\x01';
      }
      FUN_001cd4c0();
    }
  }
  return;
}

