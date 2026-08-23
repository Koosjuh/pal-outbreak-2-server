FUNCTION FUN_005c2f40 @ 0x005c2f40  size=588
CALLERS (1): FUN_005c3190@0x005c3190
CALLEES (9): FUN_005c2ae0@0x005c2ae0, FUN_005c2d70@0x005c2d70, FUN_005c2bc0@0x005c2bc0, FUN_005c2ad0@0x005c2ad0, FUN_005bf1e0@0x005bf1e0, FUN_005c2b90@0x005c2b90, FUN_005c2e90@0x005c2e90, FUN_005c4f00@0x005c4f00, FUN_005c2b20@0x005c2b20
----------------------------------------------------------------

void FUN_005c2f40(char param_1)

{
  short sVar1;
  undefined2 uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  undefined1 uStack_4;
  byte bStack_3;
  byte bStack_2;
  byte bStack_1;
  
  func_0x00106b60(0x6d2294,0,0x294a3);
  sVar1 = FUN_005bf1e0(0);
  uVar2 = FUN_005c4f00();
  pbVar3 = (byte *)FUN_005c2ae0(sVar1 + -1,uVar2);
  func_0x00106b60(&uStack_8,0,8);
  uStack_8 = 0;
  bStack_7 = *pbVar3 & 0x3f;
  bStack_6 = (char)*pbVar3 >> 7 & 1;
  uStack_4 = 1;
  bStack_5 = (char)*pbVar3 >> 6 & 1;
  bStack_3 = pbVar3[1] & 0x3f;
  bStack_2 = (char)pbVar3[1] >> 7 & 1;
  bStack_1 = (char)pbVar3[1] >> 6 & 1;
  uVar6 = FUN_005c2e90(0);
  uVar4 = FUN_005c2bc0(0x6d2297,0,2,&uStack_8,uVar6);
  uVar6 = FUN_005c2e90(1);
  uVar5 = FUN_005c2d70((uVar4 & 0xff) * 0x14a5 + 0x6d2297,1,pbVar3[2],pbVar3 + 3,uVar6);
  iVar8 = (uVar4 & 0xff) + (uVar5 & 0xff);
  uVar6 = FUN_005c2ad0();
  cRam006d2296 = FUN_005c2d70(iVar8 * 0x14a5 + 0x6d2297,2,pbVar3[0x2b],pbVar3 + 0x2c,uVar6);
  cRam006d2296 = cRam006d2296 + (char)iVar8;
  if (param_1 == '\x01') {
    func_0x00106b60(0x6cc01a,0,0x4a);
    iVar7 = 0x6d2297;
    for (iVar8 = 0; iVar8 < (int)(uint)uRam007005d0; iVar8 = iVar8 + 1) {
      *(undefined1 *)(iVar8 + 0x6cc044) = *(undefined1 *)(iVar8 + 0x7005d9);
      *(undefined1 *)(iVar7 + 0x44) = *(undefined1 *)(iVar8 + 0x7005d9);
      iVar7 = iVar7 + 0x14a5;
    }
  }
  else if (param_1 == '\0') {
    sVar1 = FUN_005bf1e0(0);
    uRam006d2294 = FUN_005c2b20(sVar1 + -1);
    sVar1 = FUN_005bf1e0(0);
    uRam006d2295 = FUN_005c2b90(sVar1 + -1);
  }
  return;
}



================================================================