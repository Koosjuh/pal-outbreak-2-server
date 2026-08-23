FUNCTION FUN_005ad530 @ 0x005ad530  size=324
CALLERS (1): FUN_005ace00@0x005ace00
CALLEES (7): FUN_005bfd80@0x005bfd80, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005b14b0@0x005b14b0, FUN_005b68e0@0x005b68e0, FUN_005bfbe0@0x005bfbe0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ad530(int param_1)

{
  undefined2 uVar1;
  long lVar2;
  
  switch(*(undefined1 *)(param_1 + 0xf)) {
  case 0:
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 7;
    FUN_005bfbe0(0,0xb,0x5ada90);
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x992) = 0;
    break;
  case 1:
    FUN_005b6900();
    break;
  case 2:
    uRam006c45fc = 1;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 5;
    uVar1 = FUN_005adc80(1);
    FUN_005bfd80(uVar1,0x5adbe0);
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    break;
  case 3:
    FUN_005b6900();
    break;
  case 4:
    FUN_005b9060(0x14,param_1 + 0x5ec);
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined2 *)(param_1 + 0x16) = 0x10;
    break;
  case 5:
    if (*(short *)(param_1 + 0x16) == 0) {
      lVar2 = FUN_005b14b0(0x210);
      if (lVar2 != 0) {
        func_0x001b0140(1);
        *(undefined1 *)(param_1 + 0xe) = 1;
        *(undefined1 *)(param_1 + 0xf) = 2;
      }
    }
    else {
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    }
  }
  return;
}



================================================================