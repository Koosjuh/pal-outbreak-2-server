
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_001d72a8(int param_1)

{
  uint *puVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  int aiStack_a8 [2];
  undefined1 auStack_a0 [2];
  short sStack_9e;
  uint uStack_9c;
  undefined8 uStack_90;
  undefined8 uStack_88;
  ulong uStack_80;
  ulong uStack_78;
  int iStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  undefined1 *puStack_44;
  ulong *puStack_40;
  
  puVar1 = DAT_0025b78c;
  aiStack_a8[0] = 0;
  if ((param_1 == 1) && (DAT_0025b78c != (uint *)0x0)) {
    puStack_40 = &uStack_80;
    for (puStack_44 = (undefined1 *)0x0; puStack_44 < 8;
        puStack_44 = (undefined1 *)((int)puStack_44 + 1)) {
      *(undefined1 *)puStack_40 = 0;
      puStack_40 = (ulong *)((int)puStack_40 + 1);
    }
    puStack_44 = (undefined1 *)&uStack_78;
    for (puStack_40 = (ulong *)0x0; puStack_40 < 8; puStack_40 = (ulong *)((int)puStack_40 + 1)) {
      *puStack_44 = 0;
      puStack_44 = puStack_44 + 1;
    }
    (&uStack_80)[puVar1[1] >> 6] =
         (&uStack_80)[puVar1[1] >> 6] | 1L << ((long)(int)puVar1[1] & 0x3fU);
    uStack_90 = 0;
    uStack_88 = 0;
    uStack_60 = FUN_001d53cc();
    puVar1[0x13f] = uStack_60;
    FUN_001d7104(puVar1);
    if (puVar1[0x143] == 0) {
      uStack_64 = puVar1[1] + 10;
      lVar6 = FUN_001eb2d4(puVar1[0x18] + 8);
      if (lVar6 == 0) {
        puVar1[0x150] = puVar1[0x150] + 1;
      }
      else {
        puVar1[0x14e] = puVar1[0x14e] + 1;
        uStack_5c = FUN_001ebd54(puVar1[0x18] + 8);
        lVar6 = FUN_001ebb90(uStack_5c,0x1000);
        if ((lVar6 == 0) &&
           ((uStack_60 <= (uint)(*(int *)puVar1[0x18] + *(int *)(puVar1[0x18] + 4)) ||
            (uVar7 = FUN_001eb2d4(puVar1[0x16] + 8), 9 < uVar7)))) {
          puVar1[0x14f] = puVar1[0x14f] + 1;
        }
        else {
          if (uStack_64 <= *puVar1) {
            uStack_64 = *puVar1 + 1;
          }
          (&uStack_78)[*puVar1 >> 6] =
               (&uStack_78)[*puVar1 >> 6] | 1L << ((long)(int)*puVar1 & 0x3fU);
        }
      }
      iStack_70 = FUN_001e3ba8(uStack_64,&uStack_80,&uStack_78,0,&uStack_90);
      while (0 < iStack_70) {
        iStack_70 = 0;
        if (((long)(&uStack_78)[*puVar1 >> 6] >> ((long)(int)*puVar1 & 0x3fU) & 1U) != 0) {
          puVar1[0x151] = puVar1[0x151] + 1;
          FUN_001d6468(puVar1,uStack_60);
          if (puVar1[0x143] != 0) {
            DAT_0025b790 = puVar1[0x143];
            return 0x27;
          }
        }
        if (((long)(&uStack_80)[puVar1[1] >> 6] >> ((long)(int)puVar1[1] & 0x3fU) & 1U) == 0) {
          puVar1[0x14d] = puVar1[0x14d] + 1;
        }
        else {
          puVar1[0x149] = puVar1[0x149] + 1;
          iStack_48 = FUN_001e40b0(puVar1[1],0x71045ead,&iStack_4c);
          if (iStack_48 != 0) {
            iStack_4c = 0x380;
          }
          if (0x380 < iStack_4c) {
            iStack_4c = 0x380;
          }
          iStack_48 = FUN_001ec1f8(puVar1[0x148],aiStack_a8,(undefined2)iStack_4c,1,0);
          if (iStack_48 != 0) {
            puVar1[0x14a] = puVar1[0x14a] + 1;
            break;
          }
          uStack_68 = 0x10;
          uVar8 = FUN_001ed6ec(aiStack_a8[0]);
          uStack_6c = FUN_001e3880(puVar1[1],aiStack_a8[0] + 0x2c,uVar8,0,auStack_a0,&uStack_68);
          iStack_50 = 1;
          puVar1[0x14b] = puVar1[0x14b] + 1;
          if ((uStack_9c != puVar1[0x13]) || (sStack_9e != *(short *)((int)puVar1 + 0x4a))) {
            iStack_50 = 0;
          }
          if (uStack_6c < 0x14) {
            iStack_50 = 0;
          }
          if (iStack_50 != 0) {
            FUN_001ebbd0(aiStack_a8[0],0x4000);
            iStack_54 = aiStack_a8[0] + uStack_6c + 0x28;
            FUN_001069a8(&uStack_58,iStack_54,4);
            uStack_6c = uStack_6c - 4;
            uVar3 = uStack_6c;
            uVar9 = uStack_58 << 0x18 | (uStack_58 & 0xff00) << 8 | (uStack_58 & 0xff0000) >> 8;
            uStack_58 = uVar9 | uStack_58 >> 0x18;
            if (uVar9 == 0xba476600) {
              uVar2 = (undefined2)uStack_6c;
              uStack_6c = uVar3;
              FUN_001ebcd0(aiStack_a8[0],uVar2);
              iStack_48 = FUN_001edd9c(aiStack_a8[0]);
              if (iStack_48 != 0) {
                iStack_50 = 0;
              }
            }
            else {
              iStack_50 = 0;
            }
          }
          if (iStack_50 == 0) {
            FUN_001ec9e0(puVar1[0x148],aiStack_a8[0]);
            aiStack_a8[0] = 0;
            puVar1[0x14c] = puVar1[0x14c] + 1;
          }
        }
      }
      if ((aiStack_a8[0] == 0) ||
         (iStack_48 = FUN_001d6988(aiStack_a8[0],puVar1,uStack_60,uStack_6c), iStack_48 == 0)) {
        iStack_48 = FUN_001e1c10(puVar1);
        if (iStack_48 == 0) {
          iStack_48 = FUN_001d6dfc(puVar1);
          if (iStack_48 == 0) {
            iVar5 = FUN_001d5460(puVar1,uStack_60);
            if (iVar5 == 0) {
              uVar4 = 0;
            }
            else {
              DAT_0025b790 = puVar1[0x143];
              uVar4 = 0x27;
            }
          }
          else {
            DAT_0025b790 = iStack_48 + 8000;
            uVar4 = 0x27;
          }
        }
        else {
          DAT_0025b790 = iStack_48 + 7000;
          uVar4 = 0x27;
        }
      }
      else {
        uVar4 = 0x27;
      }
    }
    else {
      DAT_0025b790 = puVar1[0x143];
      uVar4 = 0x27;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

