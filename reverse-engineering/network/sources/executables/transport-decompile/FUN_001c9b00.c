
undefined8 FUN_001c9b00(undefined8 param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  
  piVar5 = (int *)param_1;
  iVar1 = piVar5[0xc];
  sVar2 = (short)piVar5[4] + -1;
  *(short *)(piVar5 + 4) = sVar2;
  if (sVar2 < 1) {
    FUN_001c3420(param_1,8);
    lVar4 = FUN_001c9780();
    if (lVar4 == 0) {
      piVar5[0x37] = 5;
      *(undefined1 *)(piVar5 + 3) = 7;
      *(undefined1 *)((int)piVar5 + 0xd) = 0;
      *(undefined1 *)((int)piVar5 + 0xe) = 0;
      *(undefined1 *)((int)piVar5 + 0xf) = 0;
      *(undefined2 *)(piVar5 + 4) = 0;
      *(undefined2 *)((int)piVar5 + 0x12) = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      *(undefined2 *)((int)piVar5 + 0x16) = 0;
    }
  }
  else {
    lVar4 = FUN_001ee430(piVar5[7],0x35a714);
    if (lVar4 < 0) {
      FUN_001c3420(param_1,9);
      piVar5[0x37] = 6;
      *(undefined1 *)(piVar5 + 3) = 7;
      *(undefined1 *)((int)piVar5 + 0xd) = 0;
      *(undefined1 *)((int)piVar5 + 0xe) = 0;
      *(undefined1 *)((int)piVar5 + 0xf) = 0;
      *(undefined2 *)(piVar5 + 4) = 0;
      *(undefined2 *)((int)piVar5 + 0x12) = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      *(undefined2 *)((int)piVar5 + 0x16) = 0;
    }
    else if (sRam0035a714 == 4) {
      lVar4 = FUN_001c3880(param_1);
      if (lVar4 != 0) {
        if (lVar4 == -1) {
          FUN_001c3420(param_1,0xb);
          piVar5[0x37] = 8;
          *(undefined1 *)(piVar5 + 3) = 7;
          *(undefined1 *)((int)piVar5 + 0xd) = 0;
          *(undefined1 *)((int)piVar5 + 0xe) = 0;
          *(undefined1 *)((int)piVar5 + 0xf) = 0;
          *(undefined2 *)(piVar5 + 4) = 0;
          *(undefined2 *)((int)piVar5 + 0x12) = 0;
          *(undefined2 *)(piVar5 + 5) = 0;
          *(undefined2 *)((int)piVar5 + 0x16) = 0;
        }
        else {
          *(undefined2 *)(piVar5 + 4) = 0x708;
          for (iVar3 = 0; iVar3 < 0x49; iVar3 = iVar3 + 1) {
            if (((((&DAT_00248560)[iVar3] != '\b') &&
                 ((&DAT_002485b0)[iVar3] == *(char *)(iVar1 + 2))) &&
                ((&DAT_002484c0)[iVar3] == *(char *)(iVar1 + 3))) &&
               (((&DAT_00248510)[iVar3] == *(char *)(iVar1 + 4) &&
                (*(code **)(&DAT_00248600 + iVar3 * 4) != (code *)0x0)))) {
              lVar4 = (**(code **)(&DAT_00248600 + iVar3 * 4))(param_1);
              if (lVar4 < 0) {
                piVar5[0x37] = (int)lVar4;
                *(undefined1 *)(piVar5 + 3) = 7;
                *(undefined1 *)((int)piVar5 + 0xd) = 0;
                *(undefined1 *)((int)piVar5 + 0xe) = 0;
                *(undefined1 *)((int)piVar5 + 0xf) = 0;
                *(undefined2 *)(piVar5 + 4) = 0;
                *(undefined2 *)((int)piVar5 + 0x12) = 0;
                *(undefined2 *)(piVar5 + 5) = 0;
                *(undefined2 *)((int)piVar5 + 0x16) = 0;
                return 0;
              }
              if (lVar4 == 1) {
                if ((char)piVar5[3] == '\a') {
                  return 0;
                }
                *(char *)(piVar5 + 3) = (char)piVar5[3] + '\x01';
                return 0;
              }
              break;
            }
          }
          lVar4 = 0;
          switch(*(undefined1 *)((int)piVar5 + 0xd)) {
          case 0:
            lVar4 = FUN_001c3450(param_1,0x10,1);
            break;
          case 2:
            FUN_001c3450(param_1,0x1e,1);
            lVar4 = FUN_001c42d0();
            break;
          case 3:
            lVar4 = FUN_001c3450(param_1,0x1f,1);
            break;
          case 4:
            if (*piVar5 == 1) {
              FUN_001c3450(param_1,0x3c);
            }
            lVar4 = FUN_001c6dc0(param_1);
            break;
          case 5:
            if (*piVar5 == 1) {
              lVar4 = FUN_001c3450(param_1,0x3e);
            }
            break;
          case 6:
            if (*piVar5 == 1) {
              FUN_001c3450(param_1,0x3f,2);
            }
            lVar4 = FUN_001c7000(param_1);
            break;
          case 7:
            if (*piVar5 == 1) {
              lVar4 = FUN_001c3450(param_1,0x46,2);
            }
            break;
          case 8:
            FUN_001c3450(param_1,0x47,1);
            lVar4 = FUN_001c7580();
            break;
          case 9:
            lVar4 = FUN_001c3450(param_1,0x4a,1);
            break;
          case 10:
            FUN_001c3450(param_1,0x4b,4);
            lVar4 = FUN_001c7980();
            break;
          case 0xb:
            lVar4 = FUN_001c3450(param_1,0x54,4);
            break;
          case 0xc:
            FUN_001c3450(param_1,0x55,1);
            lVar4 = FUN_001c85c0();
            break;
          case 0xd:
            lVar4 = FUN_001c3450(param_1,0x59,1);
            break;
          case 0xe:
            FUN_001c3450(param_1,0x3a,1);
            lVar4 = FUN_001c43c0();
            break;
          case 0xf:
            lVar4 = FUN_001c3450(param_1,0x3b,1);
            break;
          case 0x10:
            FUN_001c3450(param_1,0x29,1);
            lVar4 = FUN_001c48c0();
            break;
          case 0x11:
            lVar4 = FUN_001c3450(param_1,0x2d,1);
            break;
          case 0x12:
            FUN_001c3450(param_1,0x2e,4);
            lVar4 = FUN_001c4c80();
            break;
          case 0x13:
            lVar4 = FUN_001c3450(param_1,0x37,4);
            break;
          case 0x14:
            FUN_001c3450(param_1,0x38,1);
            lVar4 = FUN_001c4560();
            break;
          case 0x15:
            lVar4 = FUN_001c3450(param_1,0x39,1);
            break;
          case 0x17:
            FUN_001c94c0(param_1);
            lVar4 = FUN_001c3450(param_1,0x11,4);
            break;
          case 0x18:
            lVar4 = FUN_001c3450(param_1,0x1d,4);
            break;
          case 0x19:
            FUN_001c3450(param_1,0x32,1);
            lVar4 = FUN_001c4fb0();
            break;
          case 0x1a:
            lVar4 = FUN_001c3450(param_1,0x3b,1);
            break;
          case 0x1b:
            FUN_001c3450(param_1,0x3c,2);
            lVar4 = FUN_001c51a0();
            break;
          case 0x1c:
            lVar4 = FUN_001c3450(param_1,0x50,2);
            break;
          case 0x1d:
            FUN_001c46a0(param_1);
            lVar4 = FUN_001c3450(param_1,0x1e,1);
            break;
          case 0x1e:
            lVar4 = FUN_001c3450(param_1,0x20,1);
            break;
          case 0x1f:
            FUN_001c3450(param_1,0x1e,1);
            lVar4 = FUN_001c5900();
            break;
          case 0x20:
            lVar4 = FUN_001c3450(param_1,0x20,1);
            break;
          case 0x21:
            FUN_001c3450(param_1,0x21,2);
            lVar4 = FUN_001c5bd0();
            break;
          case 0x22:
            lVar4 = FUN_001c3450(param_1,0x31,2);
            break;
          case 0x23:
            FUN_001c67b0(param_1);
            lVar4 = FUN_001c3450(param_1,0x1e,1);
            break;
          case 0x24:
            lVar4 = FUN_001c3450(param_1,0x20,1);
            break;
          case 0x25:
            lVar4 = FUN_001c69b0(param_1);
            break;
          case 0x27:
            lVar4 = FUN_001c6b90(param_1);
            break;
          case 0x29:
            FUN_001c3450(param_1,0x11,1);
            lVar4 = FUN_001c5ea0();
            break;
          case 0x2a:
            lVar4 = FUN_001c3450(param_1,0x13,1);
            break;
          case 0x2b:
            FUN_001c3450(param_1,0x14,2);
            lVar4 = FUN_001c6060();
            break;
          case 0x2c:
            lVar4 = FUN_001c3450(param_1,0x1d,2);
            break;
          case 0x2d:
            lVar4 = FUN_001c8b60(param_1);
            break;
          case 0x2f:
            lVar4 = FUN_001c8d30(param_1);
            break;
          case 0x31:
            FUN_001c3450(param_1,0x5a,1);
            lVar4 = FUN_001c8dd0();
            *(undefined1 *)((int)piVar5 + 0xd) = 0x33;
            break;
          case 0x32:
            lVar4 = FUN_001c3450(param_1,0x5b,1);
            break;
          case 0x33:
            lVar4 = FUN_001c3450(param_1,0x5d,1);
            break;
          case 0x34:
            lVar4 = FUN_001c8f50(param_1);
            break;
          case 0x37:
            lVar4 = FUN_001c8ad0(param_1);
            break;
          case 0x39:
            lVar4 = FUN_001c8af0(param_1);
            break;
          case 0x3b:
            lVar4 = FUN_001c5480(param_1);
            break;
          case 0x3d:
            lVar4 = FUN_001c5630(param_1);
            break;
          case 0x3f:
            lVar4 = FUN_001c6330(param_1);
            break;
          case 0x41:
            lVar4 = FUN_001c64f0(param_1);
          }
          if (lVar4 < 0) {
            piVar5[0x37] = (int)lVar4;
            *(undefined1 *)(piVar5 + 3) = 7;
            *(undefined1 *)((int)piVar5 + 0xd) = 0;
            *(undefined1 *)((int)piVar5 + 0xe) = 0;
            *(undefined1 *)((int)piVar5 + 0xf) = 0;
            *(undefined2 *)(piVar5 + 4) = 0;
            *(undefined2 *)((int)piVar5 + 0x12) = 0;
            *(undefined2 *)(piVar5 + 5) = 0;
            *(undefined2 *)((int)piVar5 + 0x16) = 0;
          }
        }
      }
    }
    else {
      FUN_001c3420(param_1,10);
      piVar5[0x37] = 7;
      *(undefined1 *)(piVar5 + 3) = 7;
      *(undefined1 *)((int)piVar5 + 0xd) = 0;
      *(undefined1 *)((int)piVar5 + 0xe) = 0;
      *(undefined1 *)((int)piVar5 + 0xf) = 0;
      *(undefined2 *)(piVar5 + 4) = 0;
      *(undefined2 *)((int)piVar5 + 0x12) = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      *(undefined2 *)((int)piVar5 + 0x16) = 0;
    }
  }
  return 0;
}

