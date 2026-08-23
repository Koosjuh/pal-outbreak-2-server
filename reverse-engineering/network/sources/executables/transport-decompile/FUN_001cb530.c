
void FUN_001cb530(undefined8 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  if ((*piVar1 != 0) &&
     (*(short *)((int)piVar1 + 0xe) = *(short *)((int)piVar1 + 0xe) + -1,
     *(short *)((int)piVar1 + 0xe) < 1)) {
    FUN_001cb490(*piVar1);
    FUN_00106b60(param_1,0,0x10);
  }
  return;
}

