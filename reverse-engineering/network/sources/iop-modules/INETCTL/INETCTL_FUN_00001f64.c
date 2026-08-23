FUNCTION FUN_00001f64 @ 0x00001f64 size=144
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (1): FUN_00003d40@0x00003d40

void FUN_00001f64(undefined4 param_1)

{
  char *pcVar1;
  
  switch(param_1) {
  case 0:
    pcVar1 = "DETACHED";
    break;
  case 1:
    pcVar1 = "STARTING";
    break;
  case 2:
    pcVar1 = "RETRYING";
    break;
  case 3:
    pcVar1 = s_STARTED_0000463c;
    break;
  case 4:
    pcVar1 = "STOPPING";
    break;
  case 5:
    pcVar1 = s_STOPPED_00004644;
    break;
  default:
    pcVar1 = &DAT_0000464c;
  }
  FUN_00003d40(pcVar1);
  return;
}


================================================================