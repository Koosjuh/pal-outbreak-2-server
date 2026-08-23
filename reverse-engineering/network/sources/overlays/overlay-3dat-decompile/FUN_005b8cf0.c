FUNCTION FUN_005b8cf0 @ 0x005b8cf0  size=168
CALLERS (31): FUN_00606fc0@0x00606fc0, FUN_005b25c0@0x005b25c0, FUN_0062c580@0x0062c580, FUN_0062be30@0x0062be30, FUN_005fb270@0x005fb270, FUN_005b8da0@0x005b8da0, FUN_005f6a20@0x005f6a20, FUN_00604180@0x00604180, FUN_00628210@0x00628210, FUN_006293f0@0x006293f0, FUN_005fe8d0@0x005fe8d0, FUN_005ad350@0x005ad350, ...
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b8cf0(char param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  uRam006c4fcf = 0;
  uRam006c4fcd = 0xff;
  uRam006c4fce = 1;
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 0x30) = 0;
    *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
    puVar1[2] = param_1;
    *(code **)(puVar1 + 0xc) = FUN_005b9150;
    if (((param_1 == -0x7a) || (param_1 == -0x51)) || (param_1 == -0x78)) {
      *(undefined2 *)(puVar1 + 0x22) = 0x8e;
    }
    else {
      *(undefined2 *)(puVar1 + 0x22) = 0x8d;
    }
  }
  return;
}



================================================================