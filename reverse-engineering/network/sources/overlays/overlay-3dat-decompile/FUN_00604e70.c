FUNCTION FUN_00604e70 @ 0x00604e70  size=540
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00604810@0x00604810, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00604e70(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    if (cRam006c5495 == '\0') {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x400;
      *(undefined4 *)(param_1 + 0x2c) = 0xff804000;
      *(undefined2 *)(param_1 + 0x3a) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x26) = 0x28;
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_0064a010 + cRam006c5497 * 2);
  if (*(char *)(param_1 + 2) == '\0') {
    iVar2 = FUN_0062fdf0(4);
    FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
    FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
    if (sRam006c54a4 == 0) {
      uVar3 = FUN_0062fea0(5);
      func_0x00109728(auStack_80,0x64a030,*(undefined4 *)(iVar2 + 8),cRam006c5495,
                      *(undefined4 *)(iVar2 + 0x14),uVar3);
      uVar1 = *(undefined2 *)(iVar2 + 4);
    }
    else {
      func_0x00109728(auStack_80,0x64a020,*(undefined4 *)(iVar2 + 8),cRam006c5495,
                      *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x20),sRam006c54a4,
                      *(undefined4 *)(iVar2 + 0x2c));
      uVar1 = *(undefined2 *)(iVar2 + 4);
    }
    FUN_005af1e0(uVar1,*(undefined2 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 3),auStack_80);
    FUN_005af2e0(*(undefined1 *)(iVar2 + 0x31));
    FUN_005af2c0(*(undefined1 *)(iVar2 + 0x32));
    uVar3 = FUN_00604810(0x694700,0x32);
    func_0x00109728(auStack_80,0x64a040,*(undefined4 *)(iVar2 + 0x38),uVar3,
                    *(undefined4 *)(iVar2 + 0x44));
    FUN_005af1e0(*(undefined2 *)(iVar2 + 0x34),*(undefined2 *)(iVar2 + 0x36),
                 *(undefined1 *)(iVar2 + 0x33),auStack_80);
    pcVar4 = (char *)(iVar2 + 0x48);
    while( true ) {
      FUN_005af2e0(pcVar4[1]);
      FUN_005af2c0(pcVar4[2]);
      FUN_005af1e0(*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),pcVar4[3],
                   *(undefined4 *)(pcVar4 + 8));
      if (*pcVar4 != '\0') break;
      pcVar4 = pcVar4 + 0xc;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0x40;
    *(undefined2 *)(param_1 + 0x46) = 0x40;
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) - *(short *)(param_1 + 0x3a);
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0x3f;
  }
  return;
}



================================================================