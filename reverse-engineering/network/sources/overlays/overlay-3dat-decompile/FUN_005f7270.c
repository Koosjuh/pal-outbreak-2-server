FUNCTION FUN_005f7270 @ 0x005f7270  size=464
CALLERS (2): FUN_005f6d20@0x005f6d20, FUN_005f6b00@0x005f6b00
CALLEES (4): FUN_005f7440@0x005f7440, FUN_005be700@0x005be700, FUN_005be690@0x005be690, FUN_005f70b0@0x005f70b0
----------------------------------------------------------------

undefined4 FUN_005f7270(int param_1,undefined8 param_2)

{
  short sVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  switch(*(undefined1 *)(param_1 + 0x429)) {
  case 0:
    *(undefined1 *)(param_1 + 0x429) = 1;
    break;
  case 1:
    *(undefined2 *)(param_1 + 0x16) = 900;
    switch((uint)param_2 & 0xff) {
    case 0:
    case 2:
    case 7:
      *(undefined1 *)(param_1 + 0x429) = 2;
      *(undefined1 *)(param_1 + 0x42b) = 0x20;
      FUN_005be690(0x5f7490);
      uVar3 = 0;
      break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
      *(undefined1 *)(param_1 + 0x429) = 2;
      *(undefined1 *)(param_1 + 0x42b) = 0x20;
      FUN_005be700(0x5f7490);
    }
    break;
  case 2:
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    lVar2 = func_0x001ee360();
    if ((lVar2 != 0) || (*(short *)(param_1 + 0x16) < 0)) {
      *(undefined1 *)(param_1 + 0x429) = 3;
    }
    FUN_005f70b0(0,param_2);
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x429) = 4;
    *(undefined2 *)(param_1 + 0x16) = 0x1e;
    FUN_005f70b0(0);
    break;
  case 4:
    sVar1 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar1;
    if (sVar1 < 0) {
      *(undefined1 *)(param_1 + 0x429) = 5;
      *(undefined1 *)(param_1 + 0x42a) = 0;
    }
    FUN_005f70b0(0,param_2);
    break;
  case 5:
    switch((uint)param_2 & 0xff) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
      uVar3 = 1;
      break;
    case 1:
    case 3:
      lVar2 = FUN_005f7440();
      if (lVar2 == 0) {
        FUN_005f70b0(1,param_2);
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}



================================================================