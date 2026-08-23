FUNCTION FUN_0062ab50 @ 0x0062ab50  size=608
CALLERS (1): FUN_0062a8c0@0x0062a8c0
CALLEES (5): FUN_005c3e70@0x005c3e70, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b68e0@0x005b68e0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

undefined4 FUN_0062ab50(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  long lVar3;
  
  switch(*(undefined1 *)(param_2 + 2)) {
  case 0:
    sVar2 = *(short *)(param_2 + 4) + -1;
    *(short *)(param_2 + 4) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
      *(undefined4 *)(param_1 + 0x1460) = 0;
      *(undefined2 *)(param_2 + 6) = 0;
      func_0x00106b60(param_1 + 0x5ec,0,0x300);
      func_0x00109eb8(param_1 + 0x5ec,0x66ad50);
    }
    break;
  case 1:
    *(undefined1 *)(param_1 + 0x10b4) = 0;
    while (uVar1 = *(uint *)(param_1 + 0x1460), uVar1 < 3) {
      if (*(char *)(param_1 + uVar1 * 0x25 + 0x1055) != '\0') {
        *(undefined1 *)(param_2 + 2) = 2;
        FUN_005b68e0();
        *(undefined1 *)(param_1 + 0x42b) = 0x1d;
        FUN_005c3e70(param_1 + *(int *)(param_1 + 0x1460) * 0x25 + 0x1055,param_1 + 0xfc4,0x62b2c0);
        return 0;
      }
      *(uint *)(param_1 + 0x1460) = uVar1 + 1;
    }
    *(undefined1 *)(param_2 + 2) = 3;
    *(undefined2 *)(param_2 + 4) = 6;
    FUN_005b9110(0x4c);
    break;
  case 2:
    if (*(char *)(param_1 + 0x10b4) != '\0') {
      *(int *)(param_1 + 0x1460) = *(int *)(param_1 + 0x1460) + 1;
      *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
      *(undefined1 *)(param_2 + 2) = 1;
    }
    break;
  case 3:
    sVar2 = *(short *)(param_2 + 4) + -1;
    *(short *)(param_2 + 4) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
      *(undefined2 *)(param_2 + 4) = 0x4c;
      func_0x00109ab0(param_1 + 0x5ec,0x66ad70);
      FUN_005b9060(0xe,param_1 + 0x5ec);
    }
    break;
  case 4:
    sVar2 = *(short *)(param_2 + 4) + -1;
    *(short *)(param_2 + 4) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
      *(undefined2 *)(param_2 + 4) = 0;
    }
    break;
  case 5:
    lVar3 = FUN_005b14b0(0x210);
    if (lVar3 != 0) {
      *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x4c);
    }
    break;
  case 6:
    sVar2 = *(short *)(param_2 + 4) + -1;
    *(short *)(param_2 + 4) = sVar2;
    if (sVar2 < 0) {
      return 1;
    }
  }
  return 0;
}



================================================================