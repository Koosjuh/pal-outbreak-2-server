
char FUN_001cce80(undefined8 param_1,int param_2,undefined8 param_3,uint param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined1 auStack_100 [256];
  
  if ((param_2 == -1) && (param_2 = DAT_0024c7f8, DAT_0024c7f8 == -1)) {
    cVar4 = '\0';
  }
  else {
    lVar2 = FUN_001cc170(param_2,param_1,1,param_4 >> 0x1d);
    if (lVar2 == 0) {
      cVar4 = '\0';
    }
    else {
      lVar3 = FUN_0010a050(lVar2);
      if (lVar3 == 0) {
        cVar4 = '\0';
      }
      else {
        FUN_00109eb8(auStack_100,lVar2);
        FUN_00109ab0(auStack_100,0x24c9b8);
        uVar1 = uRam0036b9b8;
        lVar3 = FUN_001cb360(auStack_100,uRam0036b9b8,1,0);
        cVar4 = 0 < lVar3;
        if ((bool)cVar4) {
          FUN_001d1740(param_3,uVar1,0);
          FUN_001ab6c0(param_3);
          FUN_001d1960(param_3,uVar1,param_4 & 0xff);
        }
        FUN_00109eb8(auStack_100,lVar2);
        FUN_00109ab0(auStack_100,0x24c9c0);
        uVar1 = uRam0036b9b8;
        lVar2 = FUN_001cb360(auStack_100,uRam0036b9b8,1,0);
        if (0 < lVar2) {
          *(undefined1 *)((int)param_3 + 0x81c) = 0;
          FUN_001ccd50(param_2,param_3,uVar1);
          cVar4 = cVar4 + '\x02';
        }
      }
    }
  }
  return cVar4;
}

