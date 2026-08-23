
long FUN_001c4100(undefined8 param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 auStack_10 [4];
  ushort uStack_c;
  undefined1 auStack_a [6];
  undefined1 auStack_4 [4];
  
  bVar2 = bRam0035ba80;
  puVar4 = (undefined1 *)0x4;
  puVar6 = auStack_4;
  puVar1 = puVar6;
  while (puVar1 != (undefined1 *)0x0) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + -1;
    puVar1 = puVar4;
  }
  puVar4 = (undefined1 *)0x8;
  puVar6 = auStack_10;
  puVar1 = puVar6;
  while (puVar1 != (undefined1 *)0x0) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + -1;
    puVar1 = puVar4;
  }
  FUN_001bf2e0(auStack_10,auStack_10 + 2,&uStack_c,auStack_a);
  if (cRam00343571 != '\0') {
    uStack_c = uStack_c | 4;
  }
  auStack_4[0] = (undefined1)uStack_c;
  uVar3 = FUN_001c3ab0(param_1);
  iVar7 = (int)param_1;
  *(undefined2 *)(iVar7 + 0x4c) = uVar3;
  FUN_001c3c90(param_1,0,2,0);
  FUN_001c4020(param_1,0x3c9580);
  FUN_001c3da0(param_1,6);
  FUN_001c3da0(param_1,bVar2 | 0x10);
  FUN_001c4020(param_1,0x245e38);
  FUN_001c3da0(param_1,auStack_4[0]);
  FUN_001c3da0(param_1,auStack_4[1]);
  FUN_001c3da0(param_1,auStack_4[2]);
  FUN_001c3da0(param_1,auStack_4[3]);
  **(ushort **)(iVar7 + 0x28) = *(ushort *)(iVar7 + 0x38) << 8 | *(ushort *)(iVar7 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar7 + 0x1c),*(undefined4 *)(iVar7 + 0x28),
               (short)*(undefined4 *)(iVar7 + 0x38) + 8);
  lVar5 = FUN_001c3840(param_1);
  if (-2 < lVar5) {
    lVar5 = 0;
    *(undefined1 *)(iVar7 + 0xd) = 0x36;
  }
  return lVar5;
}

