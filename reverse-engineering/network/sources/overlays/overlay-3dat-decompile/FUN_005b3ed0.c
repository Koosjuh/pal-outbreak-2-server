FUNCTION FUN_005b3ed0 @ 0x005b3ed0  size=732
CALLERS (1): FUN_005b3c30@0x005b3c30
CALLEES (11): FUN_005ba7b0@0x005ba7b0, FUN_005b9110@0x005b9110, FUN_00618b60@0x00618b60, FUN_005b14b0@0x005b14b0, FUN_005b47a0@0x005b47a0, FUN_005ba570@0x005ba570, FUN_005b45f0@0x005b45f0, FUN_005b7fd0@0x005b7fd0, FUN_005b4c80@0x005b4c80, FUN_005b6c90@0x005b6c90, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_005b3ed0(int param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)param_2;
  cVar1 = puVar3[1];
  switch(cVar1) {
  case '\0':
    FUN_00618b60();
    FUN_005b4c80(1);
    FUN_005ba570(0x20);
    FUN_005b7fd0(0,0,param_1 + 0x43c,3);
    FUN_005ba7b0();
    *(undefined1 *)(param_1 + 0x43c) = 0;
    puVar3[1] = puVar3[1] + '\x01';
    break;
  case '\x01':
    puVar3[1] = cVar1 + '\x01';
    break;
  case '\x02':
    lVar2 = FUN_005b09b0(param_1 + 0x43c,1,2);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x10);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x200);
        if (lVar2 != 0) {
          func_0x001b0140(2);
          FUN_00618b60();
          FUN_005b4c80(9);
          FUN_005ba570(0x20);
          FUN_005b7fd0(0xb,0,puVar3 + 7,3);
          FUN_005ba7b0();
          FUN_005b6c90(2,1,0);
          *puVar3 = 1;
          puVar3[1] = 0;
        }
      }
      else {
        func_0x001b0140(1);
        puVar3[1] = puVar3[1] + '\x01';
      }
    }
    break;
  case '\x03':
    *(undefined1 *)(param_1 + 0x443) = 1;
    FUN_005b9110(0x4c);
    puVar3[1] = puVar3[1] + '\x01';
    break;
  case '\x04':
    puVar3[1] = cVar1 + '\x01';
    break;
  case '\x05':
    if (*(char *)(param_1 + 0x43c) == '\0') {
      puVar3[1] = 6;
      puVar3[2] = 0;
      puVar3[3] = 0;
    }
    else {
      puVar3[1] = 7;
      puVar3[2] = 0;
      puVar3[3] = 0;
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
        puVar3[1] = 0;
      }
    }
    break;
  case '\a':
    lVar2 = FUN_005b45f0(param_2,2);
    if (lVar2 != 0) {
      puVar3[1] = puVar3[1] + '\x01';
    }
    break;
  case '\b':
    if (puVar3[2] == '\0') {
      if (*(char *)((char)puVar3[7] * 0x14 + 0x6c4674) == '\0') {
        puVar3[2] = 1;
        puVar3[3] = 0;
        FUN_00618b60();
        FUN_005ba7b0();
      }
      else {
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
    }
    else {
      lVar2 = FUN_005b47a0(param_2);
      if (lVar2 != 0) {
        puVar3[1] = 0;
        puVar3[2] = 0;
        func_0x00109eb8((char)puVar3[7] * 0x14 + 0x6c4674,0x6c4a84);
      }
    }
  }
  return 0;
}



================================================================