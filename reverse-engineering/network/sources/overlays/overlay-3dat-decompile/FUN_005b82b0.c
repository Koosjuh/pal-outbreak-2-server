FUNCTION FUN_005b82b0 @ 0x005b82b0  size=1036
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_005b82b0(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  float fVar6;
  
  iVar5 = (int)param_1;
  cVar1 = *(char *)(iVar5 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 != '\0') {
      return;
    }
    *(undefined1 *)(iVar5 + 4) = 1;
    *(undefined1 *)(iVar5 + 8) = 0x14;
    *(undefined1 *)(iVar5 + 9) = 0;
    *(undefined1 *)(iVar5 + 10) = 0xff;
    *(undefined2 *)(iVar5 + 0x3a) = 0;
    *(ushort *)(iVar5 + 0x24) = *(ushort *)(iVar5 + 0x24) | 0x80;
  }
  *(undefined1 *)(iVar5 + 1) = 1;
  if (cRam006c4fd3 != '\0') {
    FUN_00618c20();
    return;
  }
  cVar1 = *(char *)(iVar5 + 2);
  if (cVar1 == '!') {
    *(undefined4 *)(iVar5 + 0x30) = 0;
    cVar1 = *(char *)(iVar5 + 0xb);
  }
  else {
    if (cVar1 == ' ') goto LAB_005b85d4;
    if (cVar1 == '\x02') {
      cVar1 = **(char **)(iVar5 + 0x10);
      cVar4 = *(char *)(iVar5 + 0xb) + -1;
      param_1 = (long)cVar4;
      if (*(char *)(iVar5 + 3) == '\0') {
        if (cVar1 == '\0') {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      else if (cVar1 == cVar4) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      if (cRam006c5499 == '\0') {
        *(undefined1 *)(iVar5 + 1) = 1;
      }
      else {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      goto LAB_005b85d4;
    }
    if (cVar1 == '\"') {
      iVar2 = *(int *)(iVar5 + 0x10);
      if (*(char *)(iVar5 + 3) == '\0') {
        if (*(short *)(iVar2 + 0xe) == 0) {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      else {
        param_1 = (long)*(short *)(iVar2 + 8);
        if (param_1 < 7) {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
        else if ((long)*(short *)(iVar2 + 0xe) == (long)(*(short *)(iVar2 + 8) + -7)) {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      goto LAB_005b85d4;
    }
    if (cVar1 == '#') {
      if (*(short *)(*(int *)(iVar5 + 0x10) + 8) < 8) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      if (*(char *)(*(int *)(iVar5 + 0x10) + 0x17) != '\0') {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      goto LAB_005b85d4;
    }
    if ((cVar1 == '\n') || (cVar1 == '\x11')) {
      if (*(char *)(iVar5 + 3) == '\0') {
        if (cRam006c5498 == '\0') {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      else if (cRam006c5495 < '\a') {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      else if ((long)cRam006c5498 == (long)(cRam006c5495 + -7)) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      goto LAB_005b85d4;
    }
    if (cVar1 == '\x06') {
      if (*(char *)(iVar5 + 3) == '\0') {
        if (cRam006c4fda == '\0') {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      else if (uRam006c45fe < 7) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      else if ((long)cRam006c4fda == (long)(int)(uRam006c45fe - 7)) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      goto LAB_005b85d4;
    }
    if (cVar1 == '\b') {
      if (*(char *)(iVar5 + 3) == '\0') {
        if (cRam006c4fd8 == '\0') {
          *(undefined1 *)(iVar5 + 1) = 0;
        }
      }
      else if (uRam006c4602 < 5) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      else if ((long)cRam006c4fd8 == (long)(int)(uRam006c4602 - 5)) {
        *(undefined1 *)(iVar5 + 1) = 0;
      }
      goto LAB_005b85d4;
    }
    cVar1 = *(char *)(iVar5 + 0xb);
  }
  cVar4 = **(char **)(iVar5 + 0x10);
  param_1 = (long)(char)(cVar1 + -1);
  if (*(char *)(iVar5 + 3) == '\0') {
    if (cVar4 == '\0') {
      *(undefined1 *)(iVar5 + 1) = 0;
    }
  }
  else if (cVar4 == (char)(cVar1 + -1)) {
    *(undefined1 *)(iVar5 + 1) = 0;
  }
LAB_005b85d4:
  *(short *)(iVar5 + 0x3a) = *(short *)(iVar5 + 0x3a) + 0x400;
  *(ushort *)(iVar5 + 0x3a) = *(ushort *)(iVar5 + 0x3a) & 0x7fff;
  if (*(char *)(iVar5 + 9) != '\0') {
    *(undefined2 *)(iVar5 + 0x3a) = 0x4000;
    *(undefined1 *)(iVar5 + 9) = 0;
  }
  fVar6 = (float)func_0x001886c0((DAT_006928c8 * (float)*(ushort *)(iVar5 + 0x3a)) / 65536.0,param_1
                                );
  fVar6 = fVar6 * 255.0;
  *(uint *)(iVar5 + 0x2c) = (uint)((ulong)((long)*(int *)(iVar5 + 0x2c) << 0x28) >> 0x28);
  if (fVar6 < 2.1474836e+09) {
    uVar3 = *(uint *)(iVar5 + 0x2c);
  }
  else {
    fVar6 = fVar6 - 2.1474836e+09;
    uVar3 = *(uint *)(iVar5 + 0x2c);
  }
  *(uint *)(iVar5 + 0x2c) = uVar3 | (int)fVar6 << 0x18;
  return;
}



================================================================