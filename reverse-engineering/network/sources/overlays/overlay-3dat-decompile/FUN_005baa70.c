FUNCTION FUN_005baa70 @ 0x005baa70  size=492
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005baa70(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [32];
  
  if (200.0 <= fRam006c552c) {
    FUN_00618c20();
  }
  else {
    cVar1 = *(char *)(param_1 + 4);
    if (cVar1 == '\x02') {
      FUN_00618c20();
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 != '\0') {
          return;
        }
        *(undefined1 *)(param_1 + 1) = 1;
        *(undefined2 *)(param_1 + 0x24) = 0x200;
        *(undefined2 *)(param_1 + 0x26) =
             *(undefined2 *)(&DAT_00639e30 + (uint)*(byte *)(param_1 + 2) * 4);
        *(undefined2 *)(param_1 + 0x28) =
             *(undefined2 *)(&DAT_00639e32 + (uint)*(byte *)(param_1 + 2) * 4);
        *(undefined2 *)(param_1 + 0x3c) =
             *(undefined2 *)(&DAT_00639e38 + (uint)*(byte *)(param_1 + 2) * 4);
        *(undefined2 *)(param_1 + 0x3e) =
             *(undefined2 *)(&DAT_00639e3a + (uint)*(byte *)(param_1 + 2) * 4);
      }
      if (*(char *)(param_1 + 2) == '\x01') {
        if (fRam006c552c <= 0.0) {
          *(undefined1 *)(param_1 + 1) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 1) = 1;
          *(short *)(param_1 + 0x3c) = (short)(int)(DAT_006928c0 * fRam006c552c);
        }
        func_0x00109728(auStack_40,0x639e40,(int)fRam006c552c);
        func_0x00109728(auStack_20,0x639e48,auStack_40);
        iVar2 = func_0x001ae3e0(auStack_20);
        FUN_005af2c0(0);
        FUN_005af2e0(0x14);
        lVar3 = ((long)(iVar2 * 5) << 0x21) >> 0x21;
        if (iVar2 * 10 < 0) {
          lVar3 = (long)(iVar2 * 10 + 1 >> 1);
        }
        iVar2 = (int)lVar3;
        if (lVar3 < 0) {
          iVar2 = iVar2 + 1;
        }
        FUN_005af1e0(0x140 - (iVar2 >> 1),0x136,2,auStack_20);
      }
    }
  }
  return;
}



================================================================