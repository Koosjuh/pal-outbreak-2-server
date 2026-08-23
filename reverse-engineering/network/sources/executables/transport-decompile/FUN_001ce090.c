
void FUN_001ce090(undefined2 param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
                 ulong param_5,undefined1 param_6,undefined8 param_7,long param_8)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  undefined1 auStack_100 [256];
  
  uVar2 = DAT_0024c7f8;
  bVar1 = (param_5 & 0x80) != 0;
  lVar5 = FUN_001cc170(DAT_0024c7f8,param_1,1,0);
  if (lVar5 != 0) {
    if (cRam00343577 == '\0') {
      if ((param_5 & 0x7f) < 2) {
        if (param_8 == 0) {
          return;
        }
      }
      else {
        FUN_00109eb8(auStack_100,lVar5);
        if (bVar1) {
          FUN_00109ab0(auStack_100,0x24ca68);
        }
        else {
          FUN_00109ab0(auStack_100,0x24c9b8);
        }
        uVar3 = uRam0036b9b8;
        lVar6 = FUN_001cb360(auStack_100,uRam0036b9b8,1,0);
        if (0 < lVar6) {
          FUN_001d1740(param_2,uVar3,param_3);
          FUN_001ab6c0(param_2);
          FUN_001d1960(param_2,uVar3,param_4 & 0xff);
        }
      }
      if ((param_8 != 0) && (!bVar1)) {
        FUN_00109eb8(auStack_100,lVar5);
        FUN_00109ab0(auStack_100,0x24c9c0);
        uVar3 = uRam0036b9b8;
        lVar5 = FUN_001cb360(auStack_100,uRam0036b9b8,1,0);
        if (0 < lVar5) {
          *(undefined1 *)((int)param_2 + 0x81c) = param_6;
          FUN_001ccd50(uVar2,param_2,uVar3);
        }
      }
    }
    else {
      lVar5 = FUN_0010a6b0(lVar5,0x5c);
      pcVar4 = (char *)0x0;
      if (lVar5 != 0) {
        pcVar4 = (char *)((int)lVar5 + 1);
      }
      pcVar7 = pcVar4;
      if (*pcVar4 == 'H') {
        pcVar7 = pcVar4 + 1;
      }
      if (*pcVar7 == 'E') {
        FUN_00109728(auStack_100,0x24ca58,pcVar4);
      }
      else {
        FUN_00109728(auStack_100,0x24ca60,pcVar4);
      }
      if (!bVar1) {
        *(undefined1 *)((int)param_2 + 0x81c) = param_6;
      }
      FUN_001a1b00(auStack_100,param_2,param_3,uVar2,param_4,param_5,param_8);
    }
  }
  return;
}

