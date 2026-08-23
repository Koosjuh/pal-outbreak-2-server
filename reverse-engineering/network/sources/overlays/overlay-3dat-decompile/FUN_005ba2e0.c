FUNCTION FUN_005ba2e0 @ 0x005ba2e0  size=476
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_005b9120@0x005b9120, FUN_005b7cd0@0x005b7cd0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ba2e0(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else if (cVar1 == '\x01') {
    if (*(int *)(iVar4 + 0x10) == 0) {
      *(undefined1 *)(iVar4 + 4) = 2;
    }
    else {
      lVar3 = FUN_005b9120();
      if (lVar3 == 0) {
        if (*(char *)(iVar4 + 2) == '\x01') {
          FUN_005af2e0(0x14);
          FUN_005af2c0(2);
          iVar2 = func_0x001ae3e0(0x6c9d33);
          lVar3 = ((long)(iVar2 * 5) << 0x21) >> 0x21;
          if (iVar2 * 10 < 0) {
            lVar3 = (long)(iVar2 * 10 + 1 >> 1);
          }
          iVar2 = (int)lVar3;
          if (lVar3 < 0) {
            iVar2 = iVar2 + 1;
          }
          FUN_005af1e0(0x140 - (iVar2 >> 1),0x4c,2,0x6c9d33);
          FUN_005b7cd0(0x430c0000,0x42c60000,0x40000000,*(undefined4 *)(iVar4 + 0x10));
        }
        else if (*(char *)(iVar4 + 3) == '\0') {
          FUN_005b7cd0(0x430c0000,0x42880000,0x40000000,*(undefined4 *)(iVar4 + 0x10));
        }
        else {
          FUN_005b7cd0(0x430c0000,0x42500000,0x40000000,*(undefined4 *)(iVar4 + 0x10));
        }
      }
      else {
        if (cRam006c4fcd != -1) {
          uRam006c4fce = 0;
        }
        *(undefined1 *)(iVar4 + 4) = 2;
      }
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar4 + 4) = 1;
    *(undefined1 *)(iVar4 + 1) = 1;
    if (*(char *)(iVar4 + 2) == '\x01') {
      uRam006ca04d = 1;
    }
    lVar3 = FUN_005b9120(param_1);
    if (lVar3 != 0) {
      if (cRam006c4fcd != -1) {
        uRam006c4fce = 0;
      }
      *(undefined1 *)(iVar4 + 4) = 2;
    }
  }
  return;
}



================================================================