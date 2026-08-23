FUNCTION FUN_006177d0 @ 0x006177d0  size=148
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (6): thunk_FUN_00617a00@0x006179d0, FUN_00617870@0x00617870, thunk_FUN_00617a00@0x006179c0, FUN_00617910@0x00617910, FUN_00617980@0x00617980, FUN_006178a0@0x006178a0
----------------------------------------------------------------

void FUN_006177d0(int param_1)

{
  switch(*(undefined1 *)(param_1 + 0xe)) {
  case 0:
    FUN_00617870();
    break;
  case 1:
    FUN_006178a0();
    break;
  case 2:
    FUN_00617910();
    break;
  case 3:
    FUN_00617980();
    break;
  case 4:
    thunk_FUN_00617a00();
    break;
  case 5:
    thunk_FUN_00617a00();
  }
  return;
}



================================================================