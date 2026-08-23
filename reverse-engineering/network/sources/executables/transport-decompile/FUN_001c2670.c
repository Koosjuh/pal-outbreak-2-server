
undefined4
FUN_001c2670(undefined1 *param_1,char *param_2,undefined8 param_3,undefined8 param_4,
            undefined2 *param_5,undefined2 *param_6,undefined2 *param_7)

{
  undefined4 uVar1;
  long lVar2;
  byte bVar3;
  
  bVar3 = bRam0035b74c;
  if (bRam0035b74d < bRam0035b74c) {
    bVar3 = bRam0035b74d + 1;
  }
  bRam0035b74d = bVar3;
  if (*param_2 == '\x01') {
    lVar2 = FUN_001c2770(param_3,param_4);
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      *param_1 = 0;
      uVar1 = 4;
      *param_2 = '\0';
      *(undefined1 *)param_3 = 0;
      *(undefined2 *)param_4 = 0;
      *param_5 = 0;
      *param_6 = 0;
      *param_7 = 0;
    }
  }
  else if (*param_2 == '\0') {
    uVar1 = 0;
    *param_2 = '\x01';
    *(undefined1 *)param_3 = 0;
    *(undefined2 *)param_4 = 0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

