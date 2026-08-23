FUNCTION FUN_0000a720 @ 0x0000a720 size=140
CALLERS (3): FUN_0000d400@0x0000d400, FUN_00002050@0x00002050, FUN_00004f20@0x00004f20
CALLEES (2): FUN_00010070@0x00010070, FUN_000096d8@0x000096d8

void FUN_0000a720(undefined1 *param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    switch(*param_1) {
    default:
      goto switchD_0000a764_caseD_0;
    case 2:
    case 3:
    case 4:
      FUN_00010070(param_1 + 0x10);
      break;
    case 5:
      (**(code **)(*(int *)(param_1 + 0x2c) + 0x20))(param_1);
      break;
    case 6:
      break;
    }
    FUN_000096d8(param_1);
  }
switchD_0000a764_caseD_0:
  return;
}


================================================================