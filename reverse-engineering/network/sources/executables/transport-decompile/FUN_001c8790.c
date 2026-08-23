
undefined8 FUN_001c8790(undefined8 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  uint unaff_s2_lo;
  ulong unaff_s3;
  char cVar7;
  
  piVar6 = (int *)param_1;
  if (*(char *)(piVar6[0xc] + 6) == -1) {
    iVar5 = *piVar6;
    if ((iVar5 == 5) || (iVar5 == 4)) {
      *(undefined1 *)((int)piVar6 + 0xd) = 4;
    }
    else if (((iVar5 == 1) || (iVar5 == 7)) || (iVar5 == 0)) {
      piVar6[0x37] = 9;
      *(undefined1 *)(piVar6 + 3) = 7;
      *(undefined1 *)((int)piVar6 + 0xd) = 0;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      *(undefined1 *)((int)piVar6 + 0xf) = 0;
      *(undefined2 *)(piVar6 + 4) = 0;
      *(undefined2 *)((int)piVar6 + 0x12) = 0;
      *(undefined2 *)(piVar6 + 5) = 0;
      *(undefined2 *)((int)piVar6 + 0x16) = 0;
    }
    else {
      *(undefined1 *)((int)piVar6 + 0xd) = 0x31;
    }
  }
  else {
    uVar3 = FUN_001c3a60();
    unaff_s3 = uVar3 & 0xff;
    unaff_s2_lo = (uint)*(ushort *)
                         (((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78);
    if (unaff_s3 == uRam00365e1a) {
      for (cVar7 = '\0';
          ((long)cVar7 < (long)unaff_s3 &&
          ((int)((uint)uRam00365e10 + (int)cVar7) < (int)unaff_s2_lo)); cVar7 = cVar7 + '\x01') {
        uVar1 = FUN_001c3ab0(param_1);
        *(undefined2 *)
         (*(int *)(((uint)uRam00365e10 + (int)cVar7) * 4 +
                   ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) + 300) =
             uVar1;
      }
    }
    lVar4 = FUN_001c3b90(param_1,((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365e20,
                         0x3e);
    if (lVar4 < 0) {
      piVar6[0x37] = -1;
      *(undefined1 *)(piVar6 + 3) = 7;
      *(undefined1 *)((int)piVar6 + 0xd) = 0;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      *(undefined1 *)((int)piVar6 + 0xf) = 0;
      *(undefined2 *)(piVar6 + 4) = 0;
      *(undefined2 *)((int)piVar6 + 0x12) = 0;
      *(undefined2 *)(piVar6 + 5) = 0;
      *(undefined2 *)((int)piVar6 + 0x16) = 0;
      return 0;
    }
  }
  uVar2 = (uint)uRam00365e10 + ((uint)unaff_s3 & 0xff);
  if (uVar2 < (unaff_s2_lo & 0xffff)) {
    uRam00365e10 = (ushort)uVar2;
    iVar5 = (unaff_s2_lo & 0xffff) - (uVar2 & 0xffff);
    if (iVar5 < (int)(uint)uRam00365e1a) {
      uRam00365e1a = (ushort)iVar5;
    }
    *(undefined1 *)((int)piVar6 + 0xd) = 0xc;
  }
  else {
    iVar5 = *piVar6;
    if (iVar5 == 4) {
      *(undefined1 *)((int)piVar6 + 0xd) = 0x10;
    }
    else if (((iVar5 == 5) || (iVar5 == 1)) || ((iVar5 == 7 || (iVar5 == 0)))) {
      uRam00365e0c = uRam00365e0c + 1;
      if (uRam00365e0c < uRam00365e1e) {
        uRam00365e18 = 0;
        uRam00365e10 = 0;
        *(undefined1 *)((int)piVar6 + 0xd) = 0xc;
      }
      else {
        *(undefined1 *)((int)piVar6 + 0xd) = 0x31;
      }
    }
    else {
      piVar6[0x37] = -1;
      *(undefined1 *)(piVar6 + 3) = 7;
      *(undefined1 *)((int)piVar6 + 0xd) = 0;
      *(undefined1 *)((int)piVar6 + 0xe) = 0;
      *(undefined1 *)((int)piVar6 + 0xf) = 0;
      *(undefined2 *)(piVar6 + 4) = 0;
      *(undefined2 *)((int)piVar6 + 0x12) = 0;
      *(undefined2 *)(piVar6 + 5) = 0;
      *(undefined2 *)((int)piVar6 + 0x16) = 0;
    }
  }
  return 0;
}

