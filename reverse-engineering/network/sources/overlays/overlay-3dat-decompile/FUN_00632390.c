FUNCTION FUN_00632390 @ 0x00632390  size=2156
CALLERS (1): FUN_00636890@0x00636890
CALLEES (8): FUN_006340d0@0x006340d0, FUN_00634010@0x00634010, FUN_005af2c0@0x005af2c0, FUN_00637ed0@0x00637ed0, FUN_006341d0@0x006341d0, FUN_00634160@0x00634160, FUN_00637e90@0x00637e90, FUN_00632c00@0x00632c00
----------------------------------------------------------------

void FUN_00632390(float param_1,short param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  int *piVar9;
  undefined1 auStack_260 [512];
  undefined2 auStack_60 [48];
  
  func_0x001af060(0x14,0x14);
  iVar6 = iRam00715da8;
  if (*(char *)(iRam00715da8 + 0x2f) == '\x02') {
    uVar5 = 2;
    iVar3 = *(int *)(iRam00715da8 + 0x3c);
    iVar2 = (*(ushort *)(iRam00715da8 + 0x2a) + 2) - iVar3;
  }
  else if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
    iVar3 = *(int *)(iRam00715da8 + 0x3c);
    uVar5 = 1;
    iVar2 = FUN_00634160(iRam00715da8 + 0x46c);
    iVar2 = ((uint)*(ushort *)(iVar6 + 0x2a) + iVar2) - iVar3;
  }
  else {
    uVar5 = (uint)(*(short *)(iRam00715da8 + 0x260) != 0);
    iVar3 = *(int *)(iRam00715da8 + 0x3c);
    iVar2 = (*(ushort *)(iRam00715da8 + 0x2a) + uVar5) - iVar3;
  }
  piVar9 = (int *)(iVar6 + 0x3c);
  if (iVar2 < 2) {
    if (iVar3 < 0x2d) {
      *piVar9 = 0;
    }
    else {
      *piVar9 = *piVar9 + -0x2a;
      if (*(int *)(iRam00715da8 + 0x3c) < 0) {
        *(undefined4 *)(iRam00715da8 + 0x3c) = 0;
      }
    }
  }
  iVar6 = iRam00715da8;
  if (*(char *)(iRam00715da8 + 0x2f) == '\x02') {
    iVar3 = (*(ushort *)(iRam00715da8 + 0x2a) + 2) - *(int *)(iRam00715da8 + 0x3c);
  }
  else if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
    piVar9 = (int *)(iRam00715da8 + 0x3c);
    iVar3 = FUN_00634160(iRam00715da8 + 0x46c);
    uVar1 = *(ushort *)(iVar6 + 0x2a);
    iVar2 = FUN_00634160(iVar6 + 0x47c);
    iVar3 = ((uint)uVar1 + iVar3 + iVar2) - *piVar9;
  }
  else {
    iVar3 = (*(ushort *)(iRam00715da8 + 0x2a) + uVar5) - *(int *)(iRam00715da8 + 0x3c);
  }
  if (0x2c < iVar3) {
    *(int *)(iVar6 + 0x3c) = *(int *)(iVar6 + 0x3c) + iVar3 + -0x26;
    uVar4 = FUN_006340d0(iRam00715da8 + 0x4c,*(undefined4 *)(iRam00715da8 + 0x3c));
    *(undefined4 *)(iRam00715da8 + 0x3c) = uVar4;
  }
  lVar7 = FUN_00634160(iRam00715da8 + 0x4c);
  if ((long)(ulong)*(ushort *)(iRam00715da8 + 0x3c) < lVar7) {
    uVar5 = FUN_006341d0(iRam00715da8 + 0x4c);
    FUN_00637ed0(auStack_60,iRam00715da8 + (uVar5 & 0xffff) * 2 + 0x4c,0x2c);
    uVar5 = FUN_006341d0(auStack_60,0x2c);
    auStack_60[uVar5 & 0xffff] = 0;
    if ((*(char *)(iRam00715da8 + 0x1d) == '\x05') || (*(char *)(iRam00715da8 + 0x1d) == '\n')) {
      iVar6 = FUN_00637e90(auStack_60);
      for (iVar3 = 0; iVar3 < iVar6; iVar3 = iVar3 + 1) {
        auStack_60[iVar3] = 0x2a;
      }
    }
    lVar7 = FUN_00634160(auStack_60);
    if (0x2b < lVar7) {
      lVar7 = FUN_00634010(auStack_60,0x2b);
      if (lVar7 == 2) {
        uVar5 = FUN_006341d0(auStack_60,0x2b);
        auStack_60[uVar5 & 0xffff] = 0;
      }
    }
    func_0x001af0b0(0);
    FUN_005af2c0(0);
    func_0x001af080((int)param_1,param_2);
    FUN_00632c00(auStack_60,0x715bb0);
    func_0x001af0a0(0xffffffffffffffe6);
    func_0x001af190(0x68b6c8,0x715bb0);
  }
  if (*(short *)(iRam00715da8 + 0x260) != 0) {
    iVar6 = (uint)*(ushort *)(iRam00715da8 + 0x2a) - *(int *)(iRam00715da8 + 0x3c);
    uVar5 = 0;
    if (iVar6 < 0) {
      uVar5 = *(int *)(iRam00715da8 + 0x3c) - (uint)*(ushort *)(iRam00715da8 + 0x2a);
      iVar6 = 0;
    }
    if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
      iVar3 = FUN_00634160(iRam00715da8 + 0x46c,iRam00715da8 + 0x260);
      if ((int)uVar5 < iVar3) {
        uVar5 = FUN_006341d0(iRam00715da8 + 0x46c,uVar5 & 0xffff);
        FUN_00637ed0(auStack_60,iRam00715da8 + (uVar5 & 0xffff) * 2 + 0x46c,8);
        func_0x001af0b0(1);
        FUN_005af2c0(5);
        func_0x001af080((int)(param_1 + (float)iVar6 * 10.0),param_2);
        FUN_00632c00(auStack_60,0x715bb0);
        func_0x001af0a0(0xffffffffffffffe6);
        func_0x001af190(0x68b6c8,0x715bb0);
        iVar3 = FUN_00634160(auStack_60);
        iVar6 = iVar6 + iVar3;
        uVar5 = 0;
      }
      iVar3 = FUN_00634160(iRam00715da8 + 0x47c);
      if ((int)uVar5 < iVar3) {
        uVar5 = FUN_006341d0(iRam00715da8 + 0x47c,uVar5 & 0xffff);
        uVar8 = -iVar6 + 0x2c;
        FUN_00637ed0(auStack_60,iRam00715da8 + (uVar5 & 0xffff) * 2 + 0x47c,uVar8);
        uVar5 = FUN_006341d0(auStack_60,uVar8 & 0xffff);
        uVar8 = -iVar6 + 0x2b;
        auStack_60[uVar5 & 0xffff] = 0;
        lVar7 = FUN_00634010(auStack_60,uVar8);
        if (lVar7 == 2) {
          uVar5 = FUN_006341d0(auStack_60,uVar8 & 0xffff);
          auStack_60[uVar5 & 0xffff] = 0;
        }
        *(int *)(iRam00715da8 + 0x25c) = iVar6;
        func_0x001af0b0(1);
        FUN_005af2c0(3);
        func_0x001af080((int)(param_1 + (float)iVar6 * 10.0),param_2);
        FUN_00632c00(auStack_60,0x715bb0);
        func_0x001af0a0(0xffffffffffffffe6);
        func_0x001af190(0x68b6c8,0x715bb0);
        iVar3 = FUN_00634160(auStack_60);
        iVar6 = iVar6 + iVar3;
      }
      if (iVar6 < 0x2c) {
        uVar5 = -iVar6 + 0x2c;
        FUN_00637ed0(auStack_60,iRam00715da8 + 0x48c,uVar5);
        uVar5 = FUN_006341d0(auStack_60,uVar5 & 0xffff);
        uVar8 = -iVar6 + 0x2b;
        auStack_60[uVar5 & 0xffff] = 0;
        lVar7 = FUN_00634010(auStack_60,uVar8);
        if (lVar7 == 2) {
          uVar5 = FUN_006341d0(auStack_60,uVar8 & 0xffff);
          auStack_60[uVar5 & 0xffff] = 0;
        }
        func_0x001af0b0(1);
        FUN_005af2c0(5);
        func_0x001af080((int)(param_1 + (float)iVar6 * 10.0),param_2);
        FUN_00632c00(auStack_60,0x715bb0);
        func_0x001af0a0(0xffffffffffffffe6);
        func_0x001af190(0x68b6c8,0x715bb0);
      }
    }
    else {
      FUN_00637ed0(auStack_260,iRam00715da8 + 0x260,0xfa);
      iVar3 = FUN_00634160(iRam00715da8 + 0x260);
      if ((int)uVar5 < iVar3) {
        uVar5 = FUN_006341d0(auStack_260,uVar5 & 0xffff);
        FUN_00637ed0(auStack_60,auStack_60 + ((uVar5 & 0xffff) - 0x100),0x2c);
        uVar5 = FUN_006341d0(auStack_60,-iVar6 + 0x2cU & 0xffff);
        uVar8 = -iVar6 + 0x2b;
        auStack_60[uVar5 & 0xffff] = 0;
        lVar7 = FUN_00634010(auStack_60,uVar8);
        if (lVar7 == 2) {
          uVar5 = FUN_006341d0(auStack_60,uVar8 & 0xffff);
          auStack_60[uVar5 & 0xffff] = 0;
        }
        func_0x001af0b0(1);
        FUN_005af2c0(5);
        func_0x001af080((int)(param_1 + (float)iVar6 * 10.0),param_2);
        FUN_00632c00(auStack_60,0x715bb0);
        func_0x001af0a0(0xffffffffffffffe6);
        func_0x001af190(0x68b6c8,0x715bb0);
      }
    }
  }
  if (((*(char *)(iRam00715da8 + 0x2f) == '\0') && (*(char *)(iRam00715da8 + 0x27) != '\0')) &&
     ((*(byte *)(iRam00715da8 + 0x28) & 0x20) == 0)) {
    func_0x001af0b0(0);
    FUN_005af2c0(0);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80001080);
    func_0x001af060(0x14,0x16);
    func_0x001af0a0(0xffffffffffffffe6);
    func_0x001af080((short)(int)(param_1 +
                                (float)(int)(((uint)*(ushort *)(iRam00715da8 + 0x2a) +
                                             (uint)*(ushort *)(iRam00715da8 + 0x2c)) -
                                            *(int *)(iRam00715da8 + 0x3c)) * 10.0) + -4,param_2 + -2
                   );
    func_0x001af190(0x68b6d0);
  }
  return;
}



================================================================