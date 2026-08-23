FUNCTION FUN_00602340 @ 0x00602340  size=712
CALLERS (0): 
CALLEES (8): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00618c20@0x00618c20, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005f54d0@0x005f54d0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_00602340(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char acStack_80 [128];
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 1) = 0;
    }
    iVar2 = FUN_0062fdf0(0xb);
    FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
    FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
    func_0x00109728(acStack_80,0x649d78,uRam006c0602,*(undefined4 *)(iVar2 + 8));
    FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 3),
                 acStack_80);
    FUN_005af2e0(*(undefined1 *)(iVar2 + 0xd));
    FUN_005af2c0(*(undefined1 *)(iVar2 + 0xe));
    uVar5 = FUN_0062fea0(0x47);
    FUN_005af1e0(*(undefined2 *)(iVar2 + 0x10),*(short *)(iVar2 + 0x12) + 1,
                 *(undefined1 *)(iVar2 + 0xf),uVar5);
    FUN_005af2e0(0x14);
    FUN_005af2c0(0x10);
    FUN_005af1e0(*(undefined2 *)(iVar2 + 0x1c),*(undefined2 *)(iVar2 + 0x1e),0,0x6c8afc);
    iVar4 = iRam003435d4;
    FUN_005af2c0(0);
    func_0x00109728(acStack_80,0x649d70,*(undefined4 *)(iVar2 + 0x2c));
    FUN_005af1e0(*(undefined2 *)(iVar2 + 0x28),*(undefined2 *)(iVar2 + 0x2a),0,acStack_80);
    FUN_005af2c0(0x15);
    iVar3 = func_0x001ae3e0(acStack_80);
    if (*(short *)(iVar4 + 0xcf68a) == 0) {
      uVar5 = func_0x001b6950(*(undefined2 *)(iVar4 + 0xcf688));
      func_0x00109728(acStack_80,0x649d88,uVar5,(&PTR_DAT_0068ae30)[*(short *)(iVar4 + 0xcf68c)]);
      iVar4 = (int)*(char *)(iVar2 + 0x25);
      if (*(char *)(iVar2 + 0x25) < '\0') {
        iVar4 = iVar4 + 1;
      }
      FUN_005af1e0((int)*(short *)(iVar2 + 0x28) + (iVar4 >> 1) * iVar3,
                   *(undefined2 *)(iVar2 + 0x2a),0,acStack_80);
    }
    else {
      lVar6 = FUN_005fe4b0(*(undefined2 *)(iVar4 + 0xcf688));
      if ((-1 < lVar6) && (lVar6 = func_0x001b68b0(lVar6), lVar6 != 0)) {
        iVar4 = (int)*(char *)(iVar2 + 0x25);
        if (*(char *)(iVar2 + 0x25) < '\0') {
          iVar4 = iVar4 + 1;
        }
        FUN_005af1e0((int)*(short *)(iVar2 + 0x28) + (iVar4 >> 1) * iVar3,
                     *(undefined2 *)(iVar2 + 0x2a),0,lVar6);
      }
    }
    FUN_005af2e0(0x10);
    iVar4 = iRam003435d4;
    if (*(char *)(iRam003435d4 + 0xcb4ef) != '\0') {
      iVar2 = 0;
      do {
        func_0x007deb80(iVar4 + 0xcb51c,sRam0070b468 + iVar2 & 0xffff,acStack_80);
        if (acStack_80[0] != '\0') {
          FUN_005af1e0(0xe8,iVar2 * 0x14 + 0xe8,0,acStack_80);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 5);
    }
    FUN_005f54d0(1);
  }
  return;
}



================================================================