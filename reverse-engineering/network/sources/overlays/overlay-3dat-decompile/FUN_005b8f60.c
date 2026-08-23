FUNCTION FUN_005b8f60 @ 0x005b8f60  size=252
CALLERS (2): FUN_005b8e40@0x005b8e40, FUN_005b8da0@0x005b8da0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b8f60(char param_1,undefined1 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  long lVar2;
  
  uRam006c4fcf = 0;
  lVar2 = FUN_00618ba0();
  puVar1 = (undefined1 *)lVar2;
  if (lVar2 != 0) {
    *puVar1 = 1;
    *(undefined4 *)(puVar1 + 0x30) = 0;
    *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
    if (param_1 == '\x02') {
      *(undefined2 *)(puVar1 + 0x22) = 0x7f;
    }
    else {
      *(undefined2 *)(puVar1 + 0x22) = 0x7b;
    }
    puVar1[2] = param_2;
    puVar1[3] = param_1;
    *(undefined4 *)(puVar1 + 0x10) = param_3;
    *(code **)(puVar1 + 0xc) = FUN_005ba190;
    lVar2 = FUN_00618ba0();
    puVar1 = (undefined1 *)lVar2;
    if (lVar2 != 0) {
      *puVar1 = 1;
      *(undefined4 *)(puVar1 + 0x30) = 0;
      *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
      if (param_1 == '\x02') {
        *(undefined2 *)(puVar1 + 0x22) = 0x80;
      }
      else {
        *(undefined2 *)(puVar1 + 0x22) = 0x7c;
      }
      puVar1[2] = param_2;
      puVar1[3] = param_1;
      puVar1[0x38] = 1;
      *(undefined4 *)(puVar1 + 0x10) = param_3;
      *(code **)(puVar1 + 0xc) = FUN_005ba190;
    }
  }
  return;
}



================================================================