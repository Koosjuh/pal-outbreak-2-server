FUNCTION FUN_00601d50 @ 0x00601d50  size=900
CALLERS (0): 
CALLEES (10): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00618c20@0x00618c20, FUN_0062fdf0@0x0062fdf0, FUN_005adc80@0x005adc80, FUN_00603940@0x00603940, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005f54d0@0x005f54d0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_00601d50(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined1 auStack_80 [128];
  
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
    }
    iVar2 = FUN_0062fdf0(3);
    if (*(char *)(param_1 + 3) == '\0') {
      FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
      cVar1 = FUN_005adc80(2);
      iVar4 = (char)(cVar1 + -1) * 0x15c;
      func_0x00109728(auStack_80,0x649d60,*(undefined2 *)(iVar4 + 0x6c0762),
                      *(undefined2 *)(iVar4 + 0x6c0764),*(undefined4 *)(iVar2 + 8));
      FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 3),
                   auStack_80);
      FUN_005af2e0(*(undefined1 *)(iVar2 + 0xd));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 0xe));
      func_0x00109728(auStack_80,0x649d70,iVar4 + 0x6c0778);
      FUN_005af1e0(*(undefined2 *)(iVar2 + 0x10),*(undefined2 *)(iVar2 + 0x12),
                   *(undefined1 *)(iVar2 + 0xf),auStack_80);
      cVar1 = *(char *)(param_1 + 2);
    }
    else {
      FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
      func_0x00109728(auStack_80,0x649d78,uRam006c0602,*(undefined4 *)(iVar2 + 8));
      FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 3),
                   auStack_80);
      FUN_005af2e0(*(undefined1 *)(iVar2 + 0xd));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 0xe));
      uVar5 = FUN_0062fea0(0x47);
      FUN_005af1e0(*(undefined2 *)(iVar2 + 0x10),*(undefined2 *)(iVar2 + 0x12),
                   *(undefined1 *)(iVar2 + 0xf),uVar5);
      cVar1 = *(char *)(param_1 + 2);
    }
    iVar4 = iRam003435d4;
    if (cVar1 == '\0') {
      FUN_005f54d0(2);
    }
    else {
      FUN_005af2e0(*(undefined1 *)(iVar2 + 0x19));
      FUN_005af2c0(0x10);
      func_0x00109728(auStack_80,0x649d70,0x6c8afc);
      FUN_005af1e0(*(undefined2 *)(iVar2 + 0x1c),*(undefined2 *)(iVar2 + 0x1e),
                   *(undefined1 *)(iVar2 + 0x1b),auStack_80);
      FUN_005af2e0(*(undefined1 *)(iVar2 + 0x25));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 0x26));
      FUN_005af1e0(*(undefined2 *)(iVar2 + 0x28),*(undefined2 *)(iVar2 + 0x2a),
                   *(undefined1 *)(iVar2 + 0x27),*(undefined4 *)(iVar2 + 0x2c));
      FUN_005af2c0(0x15);
      iVar3 = func_0x001ae3e0(*(undefined4 *)(iVar2 + 0x2c));
      if (*(short *)(iVar4 + 0xcf68a) == 0) {
        uVar5 = func_0x001b6950(*(undefined2 *)(iVar4 + 0xcf688));
        func_0x00109728(auStack_80,0x649d88,uVar5,(&PTR_DAT_0068ae30)[*(short *)(iVar4 + 0xcf68c)]);
        cVar1 = *(char *)(iVar2 + 0x25);
      }
      else {
        lVar6 = FUN_005fe4b0(*(undefined2 *)(iVar4 + 0xcf688));
        if (lVar6 < 0) {
          func_0x00109728(auStack_80,0x649d90);
        }
        else {
          lVar6 = func_0x001b68b0(lVar6);
          if (lVar6 == 0) {
            func_0x00109728(auStack_80,0x649d90);
          }
          else {
            func_0x00109728(auStack_80,0x649d70,lVar6);
          }
        }
        cVar1 = *(char *)(iVar2 + 0x25);
      }
      iVar4 = (int)cVar1;
      if (cVar1 < '\0') {
        iVar4 = iVar4 + 1;
      }
      FUN_005af1e0((int)*(short *)(iVar2 + 0x28) + (iVar4 >> 1) * iVar3,
                   *(undefined2 *)(iVar2 + 0x2a),*(undefined1 *)(iVar2 + 0x27),auStack_80);
      FUN_005af2e0(0x12);
      FUN_005af2c0(4);
      uVar5 = FUN_0062fea0(*(undefined2 *)(cRam006c553b * 2 + 0x649d58));
      FUN_005af1e0(0x34,0x7e,0,uVar5);
      FUN_00603940();
    }
  }
  return;
}



================================================================