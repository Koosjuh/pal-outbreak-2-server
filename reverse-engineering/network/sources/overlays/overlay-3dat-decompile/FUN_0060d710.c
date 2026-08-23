FUNCTION FUN_0060d710 @ 0x0060d710  size=540
CALLERS (1): FUN_0060d4f0@0x0060d4f0
CALLEES (0): 
----------------------------------------------------------------

long FUN_0060d710(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
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
    uVar6 = (uint)lVar3 >> 0x10;
    uStack_3c = 4;
    uStack_38 = 8;
    uStack_30 = 0xff;
    uStack_2c = 8;
    iVar1 = (uVar6 - 1) * 0x38;
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
      func_0x00193fa0(uVar6);
      lVar3 = 0;
    }
    else {
      iVar1 = func_0x001841c0();
      puVar4 = puRam0070d1b0;
      for (uVar6 = 0; uVar6 < uRam0070d1b4; uVar6 = uVar6 + 1 & 0xffff) {
        puVar5 = (undefined1 *)
                 (iVar1 + ((uVar6 & 0xe0) + (uint)(byte)(&DAT_0064b600)[uVar6 & 0x1f]) * 4);
        *puVar5 = *puVar4;
        puVar5[1] = puVar4[1];
        puVar5[2] = puVar4[2];
        puVar4 = puVar4 + 3;
        if (cRam0070d124 == '\0') {
          puVar5[3] = 0x80;
        }
        else if ((uVar6 < uRam0070d1bc) && (*(char *)(iRam0070d1b8 + uVar6) != -1)) {
          puVar5[3] = 0;
        }
        else {
          puVar5[3] = 0x80;
        }
      }
      func_0x00193c10(lVar3,param_1);
    }
  }
  return lVar3;
}



================================================================