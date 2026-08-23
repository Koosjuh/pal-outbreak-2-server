
void FUN_00186320(undefined1 (*param_1) [16])

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  auVar1 = _lqc2(auRam0027f200);
  auVar2 = _lqc2(auRam0027f210);
  auVar3 = _lqc2(auRam0027f220);
  auVar4 = _lqc2(auRam0027f230);
  auVar1 = _sqc2(auVar1);
  *param_1 = auVar1;
  auVar1 = _sqc2(auVar2);
  param_1[1] = auVar1;
  auVar1 = _sqc2(auVar3);
  param_1[2] = auVar1;
  auVar1 = _sqc2(auVar4);
  param_1[3] = auVar1;
  return;
}

