
void FUN_001ee430(undefined2 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  long lVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)param_2;
  uVar1 = FUN_001ef830(param_1,param_2,puVar3 + 2,puVar3 + 3);
  lVar2 = FUN_001ee150(uVar1);
  if (-1 < lVar2) {
    switch(*puVar3) {
    case 0:
      *puVar3 = 0;
      break;
    case 1:
      *puVar3 = 1;
      break;
    case 2:
      *puVar3 = 2;
      break;
    case 3:
      *puVar3 = 3;
      break;
    case 4:
      *puVar3 = 4;
      break;
    case 5:
      *puVar3 = 5;
      break;
    case 6:
      *puVar3 = 6;
      break;
    default:
      *puVar3 = 7;
      break;
    case 8:
      *puVar3 = 8;
      break;
    case 9:
      *puVar3 = 9;
      break;
    case 10:
      *puVar3 = 10;
      break;
    case 0xffff:
      *puVar3 = 0xb;
    }
  }
  return;
}

