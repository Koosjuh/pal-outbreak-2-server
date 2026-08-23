
void FUN_001cda90(int param_1,undefined1 param_2,undefined2 param_3)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = FUN_001cdc00(param_2,param_3);
  if (lVar1 != 0) {
    pcVar2 = (char *)lVar1;
    if ((param_1 == 1) && (((pcVar2[3] & 2U) != 0 || ((pcVar2[3] & 4U) != 0)))) {
      *pcVar2 = *pcVar2 + -1;
      pcVar2[3] = pcVar2[3] & 0xfe;
    }
    else if ((param_1 == 4) && ((pcVar2[3] & 2U) != 0)) {
      *pcVar2 = *pcVar2 + -1;
      pcVar2[3] = pcVar2[3] & 0xfb;
    }
    else {
      *pcVar2 = '\x01';
      FUN_001cdbb0();
    }
  }
  return;
}

