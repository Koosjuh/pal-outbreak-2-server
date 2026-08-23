FUNCTION FUN_006366a0 @ 0x006366a0  size=492
CALLERS (1): FUN_00636890@0x00636890
CALLEES (1): FUN_006381e0@0x006381e0
----------------------------------------------------------------

void FUN_006366a0(float param_1,short param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  float *pfVar3;
  undefined2 uStack_10;
  short sStack_e;
  undefined2 uStack_c;
  short sStack_a;
  undefined4 uStack_8;
  
  bVar1 = *(byte *)((int)piRam00715da8 + 0x1f);
  if (bVar1 == 5) {
    bVar2 = *(byte *)((int)piRam00715da8 + 0x25);
    if (*(char *)(*(int *)(*piRam00715da8 + 8) +
                 (uint)*(byte *)(piRam00715da8 + 9) * 4 + (uint)bVar2) != '\x05') goto LAB_006367a4;
  }
  else if (bVar1 == 4) {
    bVar2 = *(byte *)((int)piRam00715da8 + 0x25);
    if (*(char *)(*(int *)(*piRam00715da8 + 8) +
                 (uint)*(byte *)(piRam00715da8 + 9) * 4 + (uint)bVar2) != '\x04') goto LAB_006367a4;
  }
  else {
    if ((((char)piRam00715da8[0xc] != '\x01') || (*(char *)((int)piRam00715da8 + 0x26) != '\0')) ||
       ((&DAT_00692400)[(uint)bVar1 * 2] != *(byte *)(piRam00715da8 + 9))) goto LAB_006367a4;
    bVar2 = *(byte *)((int)piRam00715da8 + 0x25);
  }
  if ((&DAT_00692401)[(uint)bVar1 * 2] == bVar2) {
    return;
  }
LAB_006367a4:
  pfVar3 = (float *)(*(int *)(*piRam00715da8 + 4) +
                    *(char *)(*(int *)(*piRam00715da8 + 8) +
                             (uint)(byte)(&DAT_00692400)[(uint)bVar1 * 2] * 4 +
                             (uint)(byte)(&DAT_00692401)[(uint)bVar1 * 2]) * 8);
  uStack_10 = (undefined2)(int)(param_1 + *pfVar3 * (float)piRam00715da8[5]);
  uStack_c = (undefined2)
             (int)(param_1 +
                  (float)piRam00715da8[5] *
                  (*pfVar3 + *(float *)(&DAT_00690d70 + (uint)*(ushort *)((int)pfVar3 + 6) * 8)));
  sStack_e = param_2 + *(short *)(pfVar3 + 1);
  sStack_a = param_2 + *(short *)(pfVar3 + 1) +
             *(short *)(&DAT_00690d74 + (uint)*(ushort *)((int)pfVar3 + 6) * 8);
  uStack_8 = param_3;
  FUN_006381e0(&uStack_10,0xffffffffffffffe4);
  return;
}



================================================================