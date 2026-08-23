FUNCTION FUN_005b0210 @ 0x005b0210  size=828
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005b035c) */
/* WARNING: Removing unreachable block (ram,0x005b03e8) */

void FUN_005b0210(int param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar6;
  undefined8 *puVar7;
  ushort uStack_30;
  ushort uStack_2e;
  undefined4 auStack_2c [3];
  undefined8 auStack_20 [4];
  
  puVar6 = &uStack_30;
  puVar7 = (undefined8 *)&DAT_006389f0;
  iVar5 = 2;
  do {
    uVar1 = *puVar7;
    uVar3 = *(undefined4 *)(puVar7 + 1);
    uVar4 = *(undefined4 *)((int)puVar7 + 0xc);
    iVar5 = iVar5 + -1;
    *(int *)puVar6 = (int)uVar1;
    *(int *)((int)puVar6 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined4 *)((int)puVar6 + 8) = uVar3;
    *(undefined4 *)((int)puVar6 + 0xc) = uVar4;
    puVar7 = puVar7 + 2;
    puVar6 = (ushort *)((int)puVar6 + 0x10);
  } while (0 < iVar5);
  *(undefined8 *)puVar6 = *puVar7;
  cVar2 = *(char *)(param_1 + 4);
  if (cVar2 == '\x02') {
    if ((ulong)*(byte *)(param_1 + 0x38) == (long)cRam006c5497) {
      if (*(char *)(param_1 + 8) != '\0') {
        *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + -1;
        return;
      }
      cVar2 = *(char *)(param_1 + 9) + -1;
      *(char *)(param_1 + 9) = cVar2;
      if (cVar2 < '\x01') {
        if (*(char *)(param_1 + 3) == '\0') {
          *(undefined2 *)(param_1 + 0x28) =
               *(undefined2 *)((int)auStack_2c + (uint)*(byte *)(param_1 + 0x38) * 4 + -2);
        }
        else {
          *(undefined2 *)(param_1 + 0x26) =
               *(undefined2 *)(auStack_2c + (*(byte *)(param_1 + 0x38) - 1));
        }
        *(undefined1 *)(param_1 + 4) = 1;
        return;
      }
      *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x4c);
      if (*(char *)(param_1 + 3) == '\0') {
        *(short *)(param_1 + 0x28) = (short)(int)*(float *)(param_1 + 0x50);
        return;
      }
      *(short *)(param_1 + 0x26) = (short)(int)*(float *)(param_1 + 0x50);
      return;
    }
    if (*(char *)(param_1 + 3) == '\0') {
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)((int)auStack_2c + cRam006c5497 * 4 + -2);
    }
    else {
      *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(auStack_2c + cRam006c5497 + -1);
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(char *)(param_1 + 0x38) = cRam006c5497;
  }
  else if (cVar2 != '\x01') {
    if (cVar2 != '\0') {
      return;
    }
    *(short *)(param_1 + 0x22) = *(char *)(param_1 + 3) + 0x138;
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    if (*(char *)(param_1 + 3) == '\0') {
      *(undefined2 *)(param_1 + 0x26) = 0;
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)((int)auStack_2c + cRam006c5497 * 4 + -2);
    }
    else {
      *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(auStack_2c + cRam006c5497 + -1);
      *(undefined2 *)(param_1 + 0x28) = 0;
    }
    *(undefined4 *)(param_1 + 0x2c) = 0x80ff0000;
    *(char *)(param_1 + 0x38) = cRam006c5497;
  }
  if ((ulong)*(byte *)(param_1 + 0x38) != (long)cRam006c5497) {
    *(char *)(param_1 + 0x38) = cRam006c5497;
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    if (*(char *)(param_1 + 3) == '\0') {
      *(undefined1 *)(param_1 + 8) = 5;
      *(undefined1 *)(param_1 + 9) = 8;
      *(float *)(param_1 + 0x50) = (float)(int)*(short *)(param_1 + 0x28);
      *(float *)(param_1 + 0x4c) =
           ((float)*(ushort *)((int)auStack_2c + (uint)*(byte *)(param_1 + 0x38) * 4 + -2) -
           (float)(int)*(short *)(param_1 + 0x28)) / 16.0;
    }
    else {
      *(undefined1 *)(param_1 + 8) = 0;
      *(undefined1 *)(param_1 + 9) = 8;
      *(float *)(param_1 + 0x50) = (float)(int)*(short *)(param_1 + 0x26);
      *(float *)(param_1 + 0x4c) =
           ((float)*(ushort *)(auStack_2c + (*(byte *)(param_1 + 0x38) - 1)) -
           (float)(int)*(short *)(param_1 + 0x26)) / 16.0;
    }
  }
  return;
}



================================================================