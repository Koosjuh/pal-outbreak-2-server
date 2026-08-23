
undefined4 FUN_001c5c90(undefined8 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_20 [32];
  
  piVar5 = (int *)param_1;
  bVar1 = false;
  if (*(char *)(piVar5[0xc] + 6) == -1) {
    piVar5[0x37] = 9;
    *(undefined1 *)(piVar5 + 3) = 7;
    uVar2 = 0;
    *(undefined1 *)((int)piVar5 + 0xd) = 0;
    *(undefined1 *)((int)piVar5 + 0xe) = 0;
    *(undefined1 *)((int)piVar5 + 0xf) = 0;
    *(undefined2 *)(piVar5 + 4) = 0;
    *(undefined2 *)((int)piVar5 + 0x12) = 0;
    *(undefined2 *)(piVar5 + 5) = 0;
    *(undefined2 *)((int)piVar5 + 0x16) = 0;
  }
  else {
    lVar4 = FUN_001c3b90(param_1,auStack_20,piVar5[0x29]);
    if (lVar4 < 0) {
      piVar5[0x37] = -1;
      *(undefined1 *)(piVar5 + 3) = 7;
      uVar2 = 0;
      *(undefined1 *)((int)piVar5 + 0xd) = 0;
      *(undefined1 *)((int)piVar5 + 0xe) = 0;
      *(undefined1 *)((int)piVar5 + 0xf) = 0;
      *(undefined2 *)(piVar5 + 4) = 0;
      *(undefined2 *)((int)piVar5 + 0x12) = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      *(undefined2 *)((int)piVar5 + 0x16) = 0;
    }
    else {
      lVar4 = FUN_0010a338(auStack_20,piVar5[0x28],piVar5[0x29]);
      if (lVar4 == 0) {
        iVar3 = FUN_001c3b10(param_1);
        if (piVar5[0x34] == iVar3) {
          uVar7 = iVar3 + (uint)*(ushort *)(piVar5 + 0x2b);
          if (*piVar5 == 3) {
            uVar6 = 0x8000;
          }
          else {
            uVar6 = 0x1000;
          }
          if (uVar7 < (uint)piVar5[0x2c]) {
            if (uVar7 < uVar6) {
              *(undefined1 *)((int)piVar5 + 0xd) = 0x21;
            }
            else {
              bVar1 = true;
              *(short *)(piVar5 + 0x2b) = (short)uVar6 - (short)iVar3;
            }
          }
          else {
            bVar1 = true;
            *(short *)(piVar5 + 0x2b) = (short)piVar5[0x2c] - (short)iVar3;
          }
          lVar4 = FUN_001c3b90(param_1,piVar5[0x35] + iVar3,(short)piVar5[0x2b]);
          if (lVar4 < 0) {
            piVar5[0x37] = -1;
            *(undefined1 *)(piVar5 + 3) = 7;
            uVar2 = 0;
            *(undefined1 *)((int)piVar5 + 0xd) = 0;
            *(undefined1 *)((int)piVar5 + 0xe) = 0;
            *(undefined1 *)((int)piVar5 + 0xf) = 0;
            *(undefined2 *)(piVar5 + 4) = 0;
            *(undefined2 *)((int)piVar5 + 0x12) = 0;
            *(undefined2 *)(piVar5 + 5) = 0;
            *(undefined2 *)((int)piVar5 + 0x16) = 0;
          }
          else {
            if (bVar1) {
              piVar5[0x3a] = iVar3 + (uint)*(ushort *)(piVar5 + 0x2b);
              if (*piVar5 == 3) {
                *(undefined1 *)((int)piVar5 + 0xd) = 0x31;
              }
              else if (*piVar5 == 0) {
                *(undefined1 *)((int)piVar5 + 0xd) = 0x19;
              }
              else {
                *(undefined1 *)((int)piVar5 + 0xd) = 0x3f;
              }
            }
            piVar5[0x34] = uVar7;
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0xffffffc4;
        }
      }
      else {
        uVar2 = 0xffffffc3;
      }
    }
  }
  return uVar2;
}

