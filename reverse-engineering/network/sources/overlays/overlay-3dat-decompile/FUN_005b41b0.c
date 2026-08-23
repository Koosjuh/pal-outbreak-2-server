FUNCTION FUN_005b41b0 @ 0x005b41b0  size=1088
CALLERS (1): FUN_005b3c30@0x005b3c30
CALLEES (8): FUN_005ba7b0@0x005ba7b0, FUN_005b4860@0x005b4860, FUN_00618b60@0x00618b60, FUN_005b47a0@0x005b47a0, FUN_005ba570@0x005ba570, FUN_005b45f0@0x005b45f0, FUN_005b7fd0@0x005b7fd0, FUN_005b4c80@0x005b4c80
----------------------------------------------------------------

undefined4 FUN_005b41b0(int param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)param_2;
  cVar1 = puVar3[1];
  switch(cVar1) {
  case '\0':
    puVar3[1] = cVar1 + '\x01';
    puVar3[3] = 0;
    puVar3[2] = 0;
    break;
  case '\x01':
    lVar2 = FUN_005b45f0(param_2,10);
    if (lVar2 != 0) {
      puVar3[1] = puVar3[1] + '\x01';
      puVar3[3] = 0;
      puVar3[2] = 0;
    }
    break;
  case '\x02':
    if (puVar3[2] == '\0') {
      if (*(char *)((char)puVar3[7] * 0x14 + 0x6c4674) == '\0') {
        if (cRam006c4630 == '\0') {
          puVar3[2] = 1;
          puVar3[3] = 0;
          FUN_00618b60();
          FUN_005ba7b0();
          return 0xffffffff;
        }
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
      else {
        puVar3[1] = cVar1 + '\x01';
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
    }
    else {
      lVar2 = FUN_005b47a0(param_2);
      if (lVar2 != 0) {
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
    }
    break;
  case '\x03':
    cVar1 = puVar3[2];
    if (cVar1 == '\x02') {
      cVar1 = *(char *)(param_1 + 0x43c);
      if ((cVar1 == -1) || (cVar1 == '\x01')) {
        if (cRam006c4630 == '\0') {
          puVar3[1] = 0;
          puVar3[2] = 0;
        }
        else {
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
        }
      }
      else if (cVar1 == '\0') {
        puVar3[1] = 5;
        puVar3[2] = 0;
        func_0x00109eb8(0x6c4a84,(char)puVar3[7] * 0x14 + 0x6c4674);
      }
    }
    else if (cVar1 == '\x01') {
      lVar2 = FUN_005b4860();
      if (lVar2 != 0) {
        puVar3[2] = puVar3[2] + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      puVar3[2] = 1;
      puVar3[3] = 0;
      *(undefined1 *)(param_1 + 0x43c) = 1;
      FUN_00618b60();
      FUN_005b4c80(3);
      FUN_005ba570(0x20);
      FUN_005b7fd0(0x17,1,param_1 + 0x43c,2);
      FUN_005ba7b0();
    }
    break;
  case '\x04':
    cVar1 = puVar3[2];
    if (cVar1 == '\x03') {
      lVar2 = FUN_005b45f0(param_2,10);
      if (lVar2 != 0) {
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
    }
    else if (cVar1 == '\x02') {
      if (*(char *)(param_1 + 0x43c) == '\0') {
        puVar3[1] = 6;
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
      else if (*(char *)(param_1 + 0x43c) < '\x01') {
        *puVar3 = 0;
        puVar3[1] = 0;
      }
      else {
        puVar3[2] = 3;
        puVar3[3] = 0;
      }
    }
    else if (cVar1 == '\x01') {
      lVar2 = FUN_005b4860();
      if (lVar2 != 0) {
        puVar3[2] = puVar3[2] + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      puVar3[2] = 1;
      puVar3[3] = 0;
      FUN_00618b60();
      FUN_005b4c80(3);
      FUN_005ba570(0x20);
      *(undefined1 *)(param_1 + 0x43c) = 1;
      FUN_005b7fd0(0x16,1,param_1 + 0x43c,2);
      FUN_005ba7b0();
    }
    break;
  case '\x05':
    if (puVar3[2] == '\0') {
      if (*(char *)((char)puVar3[7] * 0x14 + 0x6c4674) != '\0') {
        return 1;
      }
      puVar3[2] = 1;
      puVar3[3] = 0;
    }
    else {
      lVar2 = FUN_005b47a0(param_2);
      if (lVar2 != 0) {
        puVar3[1] = 4;
        puVar3[2] = 0;
      }
    }
    break;
  case '\x06':
    if (puVar3[2] == '\0') {
      if (*(char *)((char)puVar3[7] * 0x14 + 0x6c4674) != '\0') {
        return 1;
      }
      puVar3[2] = 1;
      puVar3[3] = 0;
    }
    else {
      lVar2 = FUN_005b47a0(param_2);
      if (lVar2 != 0) {
        puVar3[1] = 4;
        puVar3[2] = 0;
      }
    }
  }
  return 0xffffffff;
}



================================================================