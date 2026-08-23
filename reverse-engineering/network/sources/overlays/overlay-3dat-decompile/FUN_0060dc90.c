FUNCTION FUN_0060dc90 @ 0x0060dc90  size=452
CALLERS (1): FUN_0060dea0@0x0060dea0
CALLEES (0): 
----------------------------------------------------------------

long FUN_0060dc90(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  lVar3 = func_0x00193d20();
  if (lVar3 != 0) {
    uStack_50 = 0;
    uVar8 = (uint)lVar3 >> 0x10;
    uStack_3c = 4;
    uStack_38 = 8;
    uStack_30 = 0xff;
    uStack_2c = 8;
    iVar1 = (uVar8 - 1) * 0x38;
    uStack_28 = 8;
    uStack_24 = 0xff;
    uStack_20 = 8;
    uStack_14 = 8;
    uStack_10 = 0x18;
    uStack_18 = 0xff;
    uStack_c = 0xff;
    uStack_34 = 0;
    uStack_1c = 0x10;
    uStack_4c = 0x100;
    uStack_48 = 1;
    uStack_44 = 0x400;
    func_0x00193aa0(&uStack_50,lVar3,param_1);
    uVar2 = func_0x00184170(*(undefined4 *)(iVar1 + 0x27f288),2);
    *(undefined4 *)(iVar1 + 0x27f2a4) = uVar2;
    if (*(int *)(iVar1 + 0x27f2a4) == 0) {
      func_0x00193fa0(uVar8);
      lVar3 = 0;
    }
    else {
      iVar1 = func_0x001841c0();
      puVar7 = (undefined1 *)(param_2 + 0x36);
      uVar8 = 0;
      do {
        uVar4 = uVar8 & 0x1f;
        uVar5 = uVar8 & 0xe0;
        uVar8 = uVar8 + 1;
        puVar6 = (undefined1 *)(iVar1 + (uVar5 + (byte)(&DAT_0064b600)[uVar4]) * 4);
        puVar6[2] = *puVar7;
        puVar6[1] = puVar7[1];
        *puVar6 = puVar7[2];
        puVar7 = puVar7 + 4;
        puVar6[3] = 0x80;
      } while ((int)uVar8 < 0x100);
      func_0x00193c10(lVar3,param_1);
    }
  }
  return lVar3;
}



================================================================