
undefined8 FUN_001c08e0(char *param_1,undefined2 *param_2,int *param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  int iStack_4;
  
  if (*param_1 == '\x01') {
    lVar5 = FUN_001ee860(sRam0035cc10,&iStack_4);
    if (lVar5 == 1) {
      FUN_001ee810(sRam0035cc10);
      *param_1 = '\0';
      *param_2 = 0;
      *param_3 = iStack_4;
      iVar2 = uRam0035c3e0 * 0x104;
      FUN_0010a4f0(iVar2 + 0x35c3f0,param_4,0x100);
      *(int *)(iVar2 + 0x35c4f0) = iStack_4;
      uVar3 = uRam0035c3e0 + 1;
      uRam0035c3e0 = uVar3 & 7;
      if (((int)uVar3 < 0) && (uRam0035c3e0 != 0)) {
        uRam0035c3e0 = uRam0035c3e0 - 8;
      }
      uVar4 = 1;
    }
    else if (((lVar5 == -1) || (lVar5 == -2)) || (lVar5 != -3)) {
      FUN_001ee810(sRam0035cc10);
      *param_1 = '\0';
      uVar4 = 0xffffffffffffffff;
      *param_2 = 0;
    }
    else {
      uVar4 = 0;
    }
  }
  else if (*param_1 == '\0') {
    iVar2 = FUN_001c0690(param_4);
    *param_3 = iVar2;
    iVar2 = 0;
    if (*param_3 == 0) {
      bVar1 = true;
      while (bVar1) {
        lVar5 = FUN_0010a338(iVar2 * 0x104 + 0x35c3f0,param_4,0x100);
        if (lVar5 == 0) {
          *param_1 = '\0';
          *param_2 = 0;
          *param_3 = *(int *)(iVar2 * 0x104 + 0x35c4f0);
          return 1;
        }
        iVar2 = iVar2 + 1;
        bVar1 = iVar2 < 8;
      }
      sRam0035cc10 = FUN_001ee7c0(param_4);
      uVar4 = 0xffffffffffffffff;
      if (sRam0035cc10 != -1) {
        *param_1 = *param_1 + '\x01';
        *param_2 = 0;
        uVar4 = 0;
      }
    }
    else {
      *param_1 = '\0';
      uVar4 = 1;
      *param_2 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

