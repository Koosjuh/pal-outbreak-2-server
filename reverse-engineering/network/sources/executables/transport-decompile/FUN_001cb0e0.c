
void FUN_001cb0e0(undefined8 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined1 auStack_100 [256];
  
  puVar3 = puRam003435bc;
  uRam0036b900 = 0x36b920;
  uRam0036b9a4 = uRam005aa548;
  puRam0036b910 = puRam003435bc;
  FUN_00106b60(puRam003435bc,0,100);
  uVar6 = (int)puVar3 + 0xa3U & 0xffffffc0;
  FUN_00109728(auStack_100,0x248870,param_1);
  uVar4 = FUN_00183fd0(auStack_100);
  FUN_001cb360(auStack_100,uVar6,1,uVar4);
  uVar7 = uVar6 + (int)uVar4 + 0x3f & 0xffffffc0;
  iVar5 = uVar7 + 0x40;
  puRam0036b910[1] = uVar6;
  puRam0036b910[2] = *(int *)(uVar6 + 4) + -8;
  puRam0036b910[3] = (int)*(short *)(uVar6 + 8);
  puRam0036b910[4] = (int)*(short *)(uVar6 + 10);
  puRam0036b910[5] = *(undefined4 *)(uVar6 + 0xc);
  puRam0036b910[6] = 0;
  puRam0036b910[7] = (uint)puRam0036b910[3] >> 4;
  puRam0036b910[8] = (uint)puRam0036b910[4] >> 4;
  puRam0036b910[10] = uVar7;
  puRam0036b910[0xb] = iVar5;
  piVar1 = puRam0036b910 + 3;
  piVar2 = puRam0036b910 + 4;
  *puRam0036b910 = 0;
  iVar8 = *piVar1 * *piVar2 * 4;
  uVar6 = iVar5 + iVar8 + 0x3fU & 0xffffffc0;
  puRam0036b910[0xc] = uVar6;
  uVar6 = uVar6 + iVar8 + 0x3f & 0xffffffc0;
  puRam0036b910[0xd] = uVar6;
  puRam0036b910[0xf] = uVar6 + iVar8 + 0x3f & 0xffffffc0;
  uRam0036b920 = 1;
  return;
}

