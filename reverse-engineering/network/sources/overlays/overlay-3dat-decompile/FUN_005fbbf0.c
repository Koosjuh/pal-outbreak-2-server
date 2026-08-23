FUNCTION FUN_005fbbf0 @ 0x005fbbf0  size=1036
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fdf0@0x0062fdf0, FUN_005bac80@0x005bac80, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005fbcc8) */

void FUN_005fbbf0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined1 auStack_80 [128];
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else if (cVar1 == '\x01') {
    if (*(char *)(param_1 + 2) == '\x02') {
      if (cRam006c4fd9 == *(char *)(param_1 + 3)) {
        *(undefined1 *)(param_1 + 1) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 1;
      }
    }
    else if (cRam006c4fd9 == *(char *)(param_1 + 3)) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    if (*(char *)(param_1 + 2) == '\0') {
      iVar5 = FUN_0062fdf0(2);
      iVar4 = (char)(cRam006c4fd8 + *(char *)(param_1 + 3)) * 0x15c;
      pbVar9 = (byte *)(iVar4 + 0x6c076e);
      iVar7 = iVar5 + (uint)*pbVar9 * 0xc;
      FUN_005af2e0(*(undefined1 *)(iVar7 + 1));
      FUN_005af2c0(*(undefined1 *)(iVar7 + 2));
      FUN_005af1e0(*(undefined2 *)(iVar7 + 4),
                   (int)*(short *)(iVar7 + 6) + *(char *)(param_1 + 3) * 0x38,
                   *(undefined1 *)(iVar7 + 3),*(undefined4 *)(iVar7 + 8));
      if (*pbVar9 < 3) {
        func_0x00109728(auStack_80,0x649878,*(undefined4 *)(iVar5 + 0xb0));
        cVar1 = *(char *)(param_1 + 3);
      }
      else {
        func_0x00109728(auStack_80,0x649870,*(undefined2 *)(iVar4 + 0x6c0762),
                        *(undefined2 *)(iVar4 + 0x6c0764),*(undefined4 *)(iVar5 + 0xb0));
        cVar1 = *(char *)(param_1 + 3);
      }
      FUN_005af1e0(*(undefined2 *)(iVar5 + 0xac),(int)*(short *)(iVar5 + 0xae) + cVar1 * 0x38,
                   *(undefined1 *)(iVar5 + 0xab),auStack_80);
      FUN_005af2e0(*(undefined1 *)(iVar5 + 0x79));
      FUN_005af2c0(*(undefined1 *)(iVar5 + 0x7a));
      func_0x00109728(auStack_80,0x649880,*(undefined2 *)(iVar4 + 0x6c0760));
      FUN_005af1e0(*(undefined2 *)(iVar5 + 0x7c),
                   (int)*(short *)(iVar5 + 0x7e) + *(char *)(param_1 + 3) * 0x38,
                   *(undefined1 *)(iVar5 + 0x7b),auStack_80);
      FUN_005af2e0(*(undefined1 *)(iVar5 + 0x85));
      if (cRam006c4fd9 == *(char *)(param_1 + 3)) {
        FUN_005af2c0(0xf);
        uVar2 = *(undefined1 *)(iVar5 + 0x9d);
      }
      else {
        FUN_005af2c0(0);
        uVar2 = *(undefined1 *)(iVar5 + 0x9d);
      }
      FUN_005af2e0(uVar2);
      func_0x00109728(auStack_80,0x649888,iVar4 + 0x6c0778);
      FUN_005af1e0(*(undefined2 *)(iVar5 + 0xa0),
                   (int)*(short *)(iVar5 + 0xa2) + *(char *)(param_1 + 3) * 0x38,
                   *(undefined1 *)(iVar5 + 0x9f),auStack_80);
      if (2 < *pbVar9) {
        uVar3 = *(uint *)(iVar4 + 0x6c0774);
        if (((uVar3 & 0x10000) != 0) || ((uVar3 & 0x20000) != 0)) {
          FUN_005af2e0(*(undefined1 *)(iVar5 + 0x91));
          uVar6 = FUN_005bac80(*(undefined1 *)(iVar4 + 0x6c0774));
          func_0x00109728(auStack_80,0x649888,uVar6);
          FUN_005af1e0(*(undefined2 *)(iVar5 + 0x94),
                       (int)*(short *)(iVar5 + 0x96) + *(char *)(param_1 + 3) * 0x38,
                       *(undefined1 *)(iVar5 + 0x93),auStack_80);
        }
      }
      pcVar8 = (char *)(iVar5 + 0xb4);
      if (*(char *)(param_1 + 3) == '\0') {
        while( true ) {
          FUN_005af2e0(pcVar8[1]);
          FUN_005af2c0(pcVar8[2]);
          FUN_005af1e0(*(undefined2 *)(pcVar8 + 4),*(undefined2 *)(pcVar8 + 6),pcVar8[3],
                       *(undefined4 *)(pcVar8 + 8));
          if (*pcVar8 != '\0') break;
          pcVar8 = pcVar8 + 0xc;
        }
      }
    }
    else if (*(char *)(param_1 + 2) == '\x01') {
      if (*(char *)(param_1 + 1) == '\0') {
        *(undefined2 *)(param_1 + 0x40) = 0;
      }
      *(undefined2 *)(param_1 + 0x42) = 0;
      *(undefined2 *)(param_1 + 0x44) = 0x40;
      *(undefined2 *)(param_1 + 0x46) = 0x40;
      *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) - *(short *)(param_1 + 0x3a);
      *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0x3f;
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined2 *)(param_1 + 0x26) = 0x28;
    *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649860 + *(char *)(param_1 + 3) * 2);
  }
  return;
}



================================================================