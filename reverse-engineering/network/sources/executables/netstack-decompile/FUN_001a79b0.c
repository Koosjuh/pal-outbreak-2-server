
void FUN_001a79b0(ushort *param_1,ushort *param_2)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        uVar1 = uVar5 & uVar4;
        if (uVar4 == 0) {
          uVar5 = (uint)(short)*param_1;
          uVar4 = 0x8000;
          param_1 = param_1 + 1;
          uVar1 = uVar5 & 0x8000;
        }
        uVar4 = (int)uVar4 >> 1;
        if (uVar1 != 0) break;
        *param_2 = *param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
      uVar1 = (uint)*param_1;
      uVar3 = (uint)(*param_1 >> 0xb);
      if (uVar3 == 0) {
        uVar3 = (uint)param_1[1];
        param_1 = param_1 + 2;
      }
      else {
        uVar1 = uVar1 & 0x7ff;
        param_1 = param_1 + 1;
      }
      if (uVar1 == 0) break;
      puVar2 = param_2 + -uVar1;
      do {
        uVar3 = uVar3 - 1;
        *param_2 = *puVar2;
        puVar2 = puVar2 + 1;
        param_2 = param_2 + 1;
      } while (uVar3 != 0);
    }
    if (uVar3 == 0) break;
    do {
      *param_2 = 0;
      uVar3 = uVar3 - 1;
      param_2 = param_2 + 1;
    } while (uVar3 != 0);
  }
  return;
}

