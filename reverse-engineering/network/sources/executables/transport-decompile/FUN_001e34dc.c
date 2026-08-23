
undefined4
FUN_001e34dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,int param_5
            ,int param_6)

{
  short sVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined2 uStack_38;
  
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  puVar3 = (undefined2 *)FUN_001e2a28(param_1);
  if (puVar3 == (undefined2 *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6c;
    param_3 = 0xffffffff;
  }
  else if (puVar3[2] == 0x7f) {
    if (puVar3[1] == 2) {
      if (param_6 == 0x10) {
        uStack_38 = (undefined2)param_3;
        sVar1 = FUN_001eff60(*puVar3,uStack_38,*(undefined4 *)(param_5 + 4),
                             *(undefined2 *)(param_5 + 2),param_2);
        if (sVar1 != 0) {
          puVar2 = (undefined4 *)FUN_00103de8();
          *puVar2 = 0xe;
          param_3 = 0xffffffff;
        }
      }
      else {
        puVar2 = (undefined4 *)FUN_00103de8();
        *puVar2 = 0x7d;
        param_3 = 0xffffffff;
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0x6b;
      param_3 = 0xffffffff;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    param_3 = 0xffffffff;
  }
  return param_3;
}

