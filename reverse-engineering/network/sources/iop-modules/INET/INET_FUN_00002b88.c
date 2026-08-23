FUNCTION FUN_00002b88 @ 0x00002b88 size=564
CALLERS (1): FUN_0000cdd4@0x0000cdd4
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_00002b88(int param_1)

{
  if (param_1 == -0x1fc) {
    FUN_00011d90("connection-does-not-exist");
    return;
  }
  if (param_1 < -0x1fb) {
    if (param_1 == -0x203) {
      FUN_00011d90("host-not-found");
      return;
    }
    if (param_1 < -0x202) {
      if (param_1 == -0x205) {
        FUN_00011d90("no-recovery");
        return;
      }
      if (-0x205 < param_1) {
        FUN_00011d90("try-again");
        return;
      }
      if (param_1 == -0x206) {
        FUN_00011d90(s_no_data_0001b5b0);
        return;
      }
    }
    else {
      if (param_1 == -0x1fe) {
        FUN_00011d90("connection-reset");
        return;
      }
      if (-0x1fe < param_1) {
        FUN_00011d90("connection-closing");
        return;
      }
      if (param_1 == -0x1ff) {
        FUN_00011d90("connection-refused");
        return;
      }
    }
  }
  else {
    if (param_1 == -0x1f8) {
      FUN_00011d90("insufficient-resources");
      return;
    }
    if (param_1 < -0x1f7) {
      if (param_1 == -0x1fa) {
        FUN_00011d90("foreign-socket-unspecified");
        return;
      }
      if (param_1 < -0x1f9) {
        FUN_00011d90("connection-already-exists");
        return;
      }
      FUN_00011d90("local-socket-unspecified");
      return;
    }
    if (param_1 == -0x1f5) {
      FUN_00011d90(s_abort_0001b5a8);
      return;
    }
    if (param_1 < -500) {
      if (param_1 == -0x1f7) {
        FUN_00011d90("link-down");
        return;
      }
    }
    else {
      if (param_1 == -500) {
        FUN_00011d90(s_timeout_0001b5a0);
        return;
      }
      if (param_1 == 0) {
        FUN_00011d90(&DAT_0001b59c);
        return;
      }
    }
  }
  FUN_00011d90(&DAT_0001b4c8);
  return;
}


================================================================