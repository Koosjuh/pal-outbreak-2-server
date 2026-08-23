FUNCTION FUN_00605790 @ 0x00605790  size=520
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_00605790(int param_1)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
  }
  if (*(char *)(((uint)*(byte *)(param_1 + 2) * 0x3c - (uint)*(byte *)(param_1 + 2)) * 0x10 +
               0x6c7c2c) == '\0') {
    iVar3 = FUN_0062fdf0(6);
    FUN_005af2e0(*(undefined1 *)(iVar3 + 0x25));
    FUN_005af2c0(*(undefined1 *)(iVar3 + 0x26));
    FUN_005af1e0(*(undefined2 *)(iVar3 + 0x28),*(short *)(param_1 + 0x28) + 6,
                 *(undefined1 *)(iVar3 + 0x27),*(undefined4 *)(iVar3 + 0x2c));
  }
  else {
    if (cRam006c5497 == *(char *)(param_1 + 3)) {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    FUN_005af2c0(0x11);
    func_0x00109728(auStack_80,0x64a078,
                    ((uint)*(byte *)(param_1 + 2) * 0x3c - (uint)*(byte *)(param_1 + 2)) * 0x10 +
                    0x6c7c3c);
    FUN_005af1e0(0x48,*(short *)(param_1 + 0x28) + 6,0,auStack_80);
    iVar3 = ((uint)*(byte *)(param_1 + 2) * 0x3c - (uint)*(byte *)(param_1 + 2)) * 0x10;
    FUN_005af2c0(0);
    if (*(short *)(iVar3 + 0x6c7d1a) == 0) {
      uVar1 = func_0x001b6950(*(undefined2 *)(iVar3 + 0x6c7d18));
      func_0x00109728(auStack_80,0x64a080,uVar1,(&PTR_DAT_0068ae30)[*(short *)(iVar3 + 0x6c7d1c)]);
      FUN_005af1e0(0x192,*(short *)(param_1 + 0x28) + 6,0,auStack_80);
    }
    else {
      lVar2 = FUN_005fe4b0(*(undefined2 *)(iVar3 + 0x6c7d18));
      if ((-1 < lVar2) && (lVar2 = func_0x001b68b0(lVar2), lVar2 != 0)) {
        FUN_005af1e0(0x192,*(short *)(param_1 + 0x28) + 6,0,lVar2);
      }
    }
  }
  return;
}



================================================================