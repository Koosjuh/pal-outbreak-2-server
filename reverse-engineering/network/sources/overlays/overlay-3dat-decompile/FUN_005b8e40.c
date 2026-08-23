FUNCTION FUN_005b8e40 @ 0x005b8e40  size=280
CALLERS (1): FUN_00628210@0x00628210
CALLEES (2): FUN_005b8f60@0x005b8f60, FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b8e40(ulong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  long lVar2;
  ulong uVar3;
  
  uRam006c4fcf = 0;
  uRam006c4fcd = 0xff;
  uRam006c4fce = 1;
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 0x30) = 0;
    *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
    uVar3 = param_1 & 0xff;
    puVar1[2] = (char)param_1;
    *(code **)(puVar1 + 0xc) = FUN_005b9150;
    if ((uVar3 == 0x86) || (uVar3 == 0x88)) {
      *(undefined2 *)(puVar1 + 0x22) = 0x8e;
    }
    else {
      *(undefined2 *)(puVar1 + 0x22) = 0x8d;
    }
    *(undefined4 *)(puVar1 + 0x10) = param_3;
    if ((uVar3 == 0x86) || (uVar3 == 0x88)) {
      FUN_005b8f60(1,param_1,param_2);
    }
    else if (uVar3 == 0xaf) {
      FUN_005b8f60(2,param_1,param_2);
    }
    else {
      FUN_005b8f60(0,param_1,param_2);
    }
  }
  return;
}



================================================================