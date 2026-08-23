
undefined4 FUN_001c5a20(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  undefined1 auStack_20 [32];
  
  piVar5 = (int *)param_1;
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
    cVar1 = FUN_001c3a60();
    if (cVar1 == '\0') {
      uVar2 = 0xffffffc2;
      *(undefined1 *)((int)piVar5 + 0xd) = 0x31;
    }
    else if (cVar1 == '\x01') {
      iVar3 = FUN_001c3b10(param_1);
      piVar5[0x2a] = iVar3;
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
          piVar5[0x2c] = iVar3;
          if (piVar5[0x2c] == 0) {
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
          else {
            piVar5[0x34] = 0;
            *(undefined2 *)(piVar5 + 0x2b) = 0x2d2;
            *(undefined1 *)((int)piVar5 + 0xd) = 0x21;
          }
          uVar2 = 0;
        }
        else {
          uVar2 = 0xffffffc3;
        }
      }
    }
    else {
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
  }
  return uVar2;
}

