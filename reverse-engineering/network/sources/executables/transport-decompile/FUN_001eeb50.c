
void FUN_001eeb50(undefined4 *param_1)

{
  short sVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  
  sVar1 = FUN_001f04a0(&uStack_30);
  if (-1 < sVar1) {
    param_1[1] = uStack_30;
    *param_1 = uStack_2c;
    switch(uStack_28) {
    case 0:
      *(undefined2 *)(param_1 + 3) = 0;
      break;
    case 1:
      *(undefined2 *)(param_1 + 3) = 1;
      break;
    case 2:
      *(undefined2 *)(param_1 + 3) = 2;
      break;
    case 3:
      *(undefined2 *)(param_1 + 3) = 3;
      break;
    case 4:
      *(undefined2 *)(param_1 + 3) = 4;
      break;
    case 5:
      *(undefined2 *)(param_1 + 3) = 5;
      break;
    case 6:
      *(undefined2 *)(param_1 + 3) = 6;
      break;
    case 7:
      *(undefined2 *)(param_1 + 3) = 7;
      break;
    default:
      *(undefined2 *)(param_1 + 3) = 8;
      break;
    case 9:
      *(undefined2 *)(param_1 + 3) = 9;
    }
    param_1[2] = uStack_24;
    *(undefined2 *)((int)param_1 + 0xe) = uStack_20;
    switch(uStack_1e) {
    case 0:
      *(undefined2 *)(param_1 + 4) = 0;
      break;
    case 1:
      *(undefined2 *)(param_1 + 4) = 1;
      break;
    case 2:
      *(undefined2 *)(param_1 + 4) = 2;
      break;
    case 3:
      *(undefined2 *)(param_1 + 4) = 3;
      break;
    case 4:
      *(undefined2 *)(param_1 + 4) = 4;
      break;
    case 5:
      *(undefined2 *)(param_1 + 4) = 5;
      break;
    case 6:
      *(undefined2 *)(param_1 + 4) = 6;
      break;
    case 7:
      *(undefined2 *)(param_1 + 4) = 7;
      break;
    case 8:
      *(undefined2 *)(param_1 + 4) = 8;
      break;
    case 9:
      *(undefined2 *)(param_1 + 4) = 9;
      break;
    case 10:
      *(undefined2 *)(param_1 + 4) = 10;
      break;
    default:
      *(undefined2 *)(param_1 + 4) = 0xb;
      break;
    case 0xc:
      *(undefined2 *)(param_1 + 4) = 0xc;
      break;
    case 0xd:
      *(undefined2 *)(param_1 + 4) = 0xd;
    }
  }
  return;
}

