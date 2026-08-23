FUNCTION FUN_005bba20 @ 0x005bba20  size=356
CALLERS (0): 
CALLEES (18): FUN_005bbf20@0x005bbf20, FUN_005bc0e0@0x005bc0e0, FUN_005c7d00@0x005c7d00, thunk_FUN_005c61b0@0x005bc340, FUN_005bbe00@0x005bbe00, FUN_005bc1c0@0x005bc1c0, FUN_005bc270@0x005bc270, FUN_005bc2a0@0x005bc2a0, FUN_005bc350@0x005bc350, FUN_005bc110@0x005bc110, FUN_005bc230@0x005bc230, FUN_005bc2f0@0x005bc2f0, ...
----------------------------------------------------------------

void FUN_005bba20(int param_1,int param_2)

{
  FUN_005c7d00();
  switch(*(undefined1 *)(param_2 + 8)) {
  case 1:
    FUN_005bbb90(*(undefined4 *)(param_1 + 8));
    return;
  case 2:
    FUN_005bbc20(*(undefined4 *)(param_1 + 8));
    break;
  case 3:
    FUN_005bbf20(*(undefined4 *)(param_1 + 8));
    break;
  case 4:
    FUN_005bbfc0(*(undefined4 *)(param_1 + 8));
    break;
  case 5:
    FUN_005bc0e0(*(undefined4 *)(param_1 + 8));
    break;
  case 6:
    FUN_005bc110(*(undefined4 *)(param_1 + 8));
    break;
  case 7:
    FUN_005bc1c0(*(undefined4 *)(param_1 + 8));
    break;
  case 8:
    FUN_005bc230(*(undefined4 *)(param_1 + 8));
    break;
  case 9:
    FUN_005bc2a0(*(undefined4 *)(param_1 + 8));
    break;
  case 10:
    FUN_005bc240(*(undefined4 *)(param_1 + 8));
    break;
  case 0xb:
    FUN_005bc270(*(undefined4 *)(param_1 + 8));
    break;
  case 0xc:
    FUN_005bbe00(*(undefined4 *)(param_1 + 8));
    break;
  case 0xd:
    FUN_005bc2f0(*(undefined4 *)(param_1 + 8));
    break;
  case 0xe:
    thunk_FUN_005c61b0(*(undefined4 *)(param_1 + 8));
    break;
  case 0xf:
    FUN_005bc350(*(undefined4 *)(param_1 + 8));
    break;
  case 0x10:
    FUN_005bc050(*(undefined4 *)(param_1 + 8));
    break;
  case 0x11:
    FUN_005bbea0(*(undefined4 *)(param_1 + 8),param_2 + 8);
  }
  return;
}



================================================================