FUNCTION FUN_000075dc @ 0x000075dc size=124
CALLERS (5): FUN_0000bc4c@0x0000bc4c, FUN_0000d5a8@0x0000d5a8, FUN_00001e44@0x00001e44, FUN_00001ec4@0x00001ec4, FUN_00001dbc@0x00001dbc
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_000075dc(char *param_1)

{
  param_1[2] = param_1[2] & 0xbfU | 0x80;
  if (*param_1 == '\0') {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PP_doppp_active: %s fsm state ==> Listen\n",**(undefined4 **)(param_1 + 0x2c))
      ;
    }
    *param_1 = '\x01';
  }
  return 0;
}


================================================================