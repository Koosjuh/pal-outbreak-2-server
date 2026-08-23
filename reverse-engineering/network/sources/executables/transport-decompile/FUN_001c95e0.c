
undefined4 FUN_001c95e0(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  undefined1 auStack_20 [32];
  
  piVar3 = (int *)param_1;
  lVar4 = 0;
  if ((*piVar3 == 0) || (uVar1 = 0, *piVar3 == 7)) {
    if (*(char *)(piVar3[0xc] + 6) == -1) {
      piVar3[0x37] = 9;
      *(undefined1 *)(piVar3 + 3) = 7;
      uVar1 = 0;
      *(undefined1 *)((int)piVar3 + 0xd) = 0;
      *(undefined1 *)((int)piVar3 + 0xe) = 0;
      *(undefined1 *)((int)piVar3 + 0xf) = 0;
      *(undefined2 *)(piVar3 + 4) = 0;
      *(undefined2 *)((int)piVar3 + 0x12) = 0;
      *(undefined2 *)(piVar3 + 5) = 0;
      *(undefined2 *)((int)piVar3 + 0x16) = 0;
    }
    else {
      FUN_00106b60(auStack_20,0,0x20);
      lVar2 = FUN_001c3b90(param_1,auStack_20,10);
      if (lVar2 < 0) {
        piVar3[0x37] = -1;
        *(undefined1 *)(piVar3 + 3) = 7;
        uVar1 = 0;
        *(undefined1 *)((int)piVar3 + 0xd) = 0;
        *(undefined1 *)((int)piVar3 + 0xe) = 0;
        *(undefined1 *)((int)piVar3 + 0xf) = 0;
        *(undefined2 *)(piVar3 + 4) = 0;
        *(undefined2 *)((int)piVar3 + 0x12) = 0;
        *(undefined2 *)(piVar3 + 5) = 0;
        *(undefined2 *)((int)piVar3 + 0x16) = 0;
      }
      else {
        lVar2 = FUN_0010a338(auStack_20,0x365dd1,10);
        if (lVar2 == 0) {
          lVar2 = FUN_001c3b10(param_1);
          iVar5 = (int)lVar2;
          if (lVar2 < 0x8000) {
            lVar4 = FUN_001c3b90(param_1,iRam00365df0 + iVar5,0x8000 - iVar5);
          }
          if (lVar4 < 0) {
            piVar3[0x37] = -1;
            *(undefined1 *)(piVar3 + 3) = 7;
            uVar1 = 0;
            *(undefined1 *)((int)piVar3 + 0xd) = 0;
            *(undefined1 *)((int)piVar3 + 0xe) = 0;
            *(undefined1 *)((int)piVar3 + 0xf) = 0;
            *(undefined2 *)(piVar3 + 4) = 0;
            *(undefined2 *)((int)piVar3 + 0x12) = 0;
            *(undefined2 *)(piVar3 + 5) = 0;
            *(undefined2 *)((int)piVar3 + 0x16) = 0;
          }
          else {
            if (piVar3[0x1c] == iVar5 + (int)lVar4) {
              *(undefined1 *)((int)piVar3 + 0xd) = 0x31;
            }
            else {
              *(undefined1 *)((int)piVar3 + 0xd) = 0x17;
            }
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0xffffffc1;
        }
      }
    }
  }
  return uVar1;
}

