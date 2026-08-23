FUNCTION FUN_005fe300 @ 0x005fe300  size=428
CALLERS (3): FUN_005fa190@0x005fa190, FUN_005f91f0@0x005f91f0, FUN_0062d4e0@0x0062d4e0
CALLEES (2): FUN_005baf20@0x005baf20, FUN_005baf70@0x005baf70
----------------------------------------------------------------

void FUN_005fe300(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  func_0x00106b60(param_1 + 0x1a,0,0x400);
  iVar8 = 0;
  uVar2 = FUN_005baf20(bRam006c45f8 - 1);
  uVar7 = 0;
  uVar3 = 1;
  do {
    if ((uVar2 & 0xff & uVar3) != 0) {
      iVar4 = param_1 + iVar8 * 4;
      iVar8 = iVar8 + 1;
      *(undefined1 *)(iVar4 + 0x1a) = 0;
      uVar6 = 0;
      *(undefined1 *)(iVar4 + 0x1b) = 0;
      *(char *)(iVar4 + 0x1c) = (char)uVar7;
      bVar1 = *(byte *)(uVar7 + 0x341ac8);
      uVar3 = 1;
      do {
        if ((bVar1 & uVar3) != 0) {
          iVar4 = param_1 + iVar8 * 4;
          iVar8 = iVar8 + 1;
          *(undefined1 *)(iVar4 + 0x1a) = 0;
          *(char *)(iVar4 + 0x1c) = (char)uVar7;
          *(char *)(iVar4 + 0x1b) = (char)uVar6 + '\x01';
        }
        uVar6 = uVar6 + 1;
        uVar3 = 1 << (uVar6 & 0x1f);
      } while ((int)uVar6 < 4);
    }
    uVar7 = uVar7 + 1;
    uVar3 = 1 << (uVar7 & 0x1f);
  } while ((int)uVar7 < 8);
  iVar4 = FUN_005baf70(bRam006c45f8 - 1);
  uVar2 = 0;
  iVar5 = 0;
  do {
    uVar3 = uVar2 & 0x1f;
    if ((int)uVar2 < 0) {
      uVar7 = 0;
      if (uVar3 != 0) {
        uVar3 = uVar3 - 0x20;
        goto LAB_005fe414;
      }
    }
    else {
LAB_005fe414:
      uVar7 = uVar3 & 0x1f;
    }
    if ((*(uint *)(iVar5 * 4 + 0x341ad0) & 1 << uVar7) != 0) {
      uVar3 = uVar2 & 7;
      if ((int)uVar2 < 0) {
        uVar7 = 0;
        if (uVar3 != 0) {
          uVar3 = uVar3 - 8;
          goto LAB_005fe43c;
        }
      }
      else {
LAB_005fe43c:
        uVar7 = uVar3 & 0x1f;
      }
      if ((1 << uVar7 & (uint)*(byte *)(iVar4 + ((int)uVar2 >> 3))) != 0) {
        iVar5 = param_1 + iVar8 * 4;
        *(undefined1 *)(iVar5 + 0x1a) = 1;
        *(undefined1 *)(iVar5 + 0x1b) = 0;
        iVar8 = iVar8 + 1;
        *(char *)(iVar5 + 0x1c) = (char)*(undefined2 *)(uVar2 * 0xc + 0x3c4d50) + '\x01';
      }
    }
    uVar2 = uVar2 + 1;
    iVar5 = (int)uVar2 >> 5;
    if (0x7f < (int)uVar2) {
      *(short *)(param_1 + 10) = (short)iVar8;
      return;
    }
  } while( true );
}



================================================================