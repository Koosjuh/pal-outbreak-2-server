
undefined8 FUN_001c4d40(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = (int)param_1;
  if (*(char *)(*(int *)(iVar4 + 0x30) + 6) == -1) {
    *(undefined4 *)(iVar4 + 0xdc) = 9;
    *(undefined1 *)(iVar4 + 0xc) = 7;
    *(undefined1 *)(iVar4 + 0xd) = 0;
    *(undefined1 *)(iVar4 + 0xe) = 0;
    *(undefined1 *)(iVar4 + 0xf) = 0;
    *(undefined2 *)(iVar4 + 0x10) = 0;
    *(undefined2 *)(iVar4 + 0x12) = 0;
    *(undefined2 *)(iVar4 + 0x14) = 0;
    *(undefined2 *)(iVar4 + 0x16) = 0;
    FUN_001c2f30();
  }
  else {
    uVar1 = FUN_001c3ab0();
    if ((uVar1 & 0xffff) == (uint)bRam00368421) {
      uVar2 = FUN_001c3b10(param_1);
      if (uVar2 == uRam00368424) {
        uRam00368424 = uVar2 + 0x2f2;
        iVar6 = (uVar1 & 0xffff) * 4;
        puVar5 = (uint *)(iVar6 + 0x36846c);
        uVar1 = *puVar5;
        uVar7 = 0x2f2;
        if (uRam00368424 < uVar1) {
          *(undefined1 *)(iVar4 + 0xd) = 0x12;
        }
        else {
          uRam00368424 = 0;
          uVar7 = uVar1 - uVar2 & 0xffff;
          bRam00368421 = bRam00368421 + 1;
          if (bRam00368421 < uRam0036842a) {
            *(undefined1 *)(iVar4 + 0xd) = 0x12;
          }
          else {
            uRam00368428 = uRam0036842a;
            uRam00368420 = 1;
            FUN_0010a4f0(0x36842c,0x36844c,0x20);
            *(undefined1 *)(iVar4 + 0xd) = 0x14;
          }
        }
        if ((*puVar5 != 0) &&
           (lVar3 = FUN_001c3b90(param_1,*(int *)(iVar6 + 0x368474) + uVar2,uVar7), lVar3 < 0)) {
          FUN_001c2f30();
          *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
          *(undefined1 *)(iVar4 + 0xc) = 7;
          *(undefined1 *)(iVar4 + 0xd) = 0;
          *(undefined1 *)(iVar4 + 0xe) = 0;
          *(undefined1 *)(iVar4 + 0xf) = 0;
          *(undefined2 *)(iVar4 + 0x10) = 0;
          *(undefined2 *)(iVar4 + 0x12) = 0;
          *(undefined2 *)(iVar4 + 0x14) = 0;
          *(undefined2 *)(iVar4 + 0x16) = 0;
        }
      }
      else {
        FUN_001c2f30();
        *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
        *(undefined1 *)(iVar4 + 0xc) = 7;
        *(undefined1 *)(iVar4 + 0xd) = 0;
        *(undefined1 *)(iVar4 + 0xe) = 0;
        *(undefined1 *)(iVar4 + 0xf) = 0;
        *(undefined2 *)(iVar4 + 0x10) = 0;
        *(undefined2 *)(iVar4 + 0x12) = 0;
        *(undefined2 *)(iVar4 + 0x14) = 0;
        *(undefined2 *)(iVar4 + 0x16) = 0;
      }
    }
    else {
      FUN_001c2f30();
      *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar4 + 0xc) = 7;
      *(undefined1 *)(iVar4 + 0xd) = 0;
      *(undefined1 *)(iVar4 + 0xe) = 0;
      *(undefined1 *)(iVar4 + 0xf) = 0;
      *(undefined2 *)(iVar4 + 0x10) = 0;
      *(undefined2 *)(iVar4 + 0x12) = 0;
      *(undefined2 *)(iVar4 + 0x14) = 0;
      *(undefined2 *)(iVar4 + 0x16) = 0;
    }
  }
  return 0;
}

