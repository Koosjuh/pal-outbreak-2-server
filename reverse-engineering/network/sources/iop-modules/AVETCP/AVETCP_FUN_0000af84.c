FUNCTION FUN_0000af84 @ 0x0000af84 size=1104
CALLERS (2): FUN_00007000@0x00007000, FUN_0000c088@0x0000c088
CALLEES (12): FUN_0000139c@0x0000139c, FUN_00000fa0@0x00000fa0, FUN_000010a8@0x000010a8, FUN_00001018@0x00001018, FUN_00012608@0x00012608, FUN_00001080@0x00001080, FUN_0000f308@0x0000f308, FUN_00011d00@0x00011d00, FUN_0000f228@0x0000f228, FUN_00004ec4@0x00004ec4, FUN_00003b30@0x00003b30, FUN_00014e24@0x00014e24

undefined4
FUN_0000af84(undefined4 param_1,short param_2,short param_3,undefined4 param_4,undefined4 param_5,
            byte param_6)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined1 local_5f;
  undefined2 local_5e;
  short local_58;
  short local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  byte local_4b;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_46 [3];
  undefined1 auStack_40 [2];
  undefined1 auStack_3e [2];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 auStack_32 [2];
  undefined1 auStack_30 [2];
  undefined1 auStack_2e [6];
  
  iVar4 = FUN_0000f228();
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  local_4b = param_6;
  local_46[0] = 0;
  local_48 = 0;
  local_4a = 0;
  local_50 = param_5;
  local_4c = 0x50;
  local_58 = param_2;
  local_56 = param_3;
  local_54 = param_4;
  puVar5 = (undefined4 *)FUN_00000fa0();
  if (puVar5 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *puVar5 = 1;
  puVar5[1] = 0x14;
  *(undefined2 *)(puVar5 + 2) = 0x14;
  FUN_00011d00(auStack_40,&local_58,2);
  FUN_00011d00(auStack_3e,&local_56,2);
  FUN_00011d00(auStack_3c,&local_54,4);
  FUN_00011d00(auStack_38,&local_50,4);
  FUN_00011d00(&uStack_34,&local_4c,1);
  FUN_00011d00(&uStack_33,&local_4b,1);
  FUN_00011d00(auStack_32,&local_4a,2);
  FUN_00011d00(auStack_30,&local_48,2);
  FUN_00011d00(auStack_2e,local_46,2);
  FUN_0000139c(puVar5 + 3,auStack_40);
  local_68 = FUN_0000f308(iVar4);
  local_60 = 0;
  local_5f = 6;
  local_64 = param_1;
  local_5e = FUN_000010a8((int)*(short *)(puVar5 + 1));
  uVar1 = FUN_00003b30(&local_68,puVar5,1);
  local_48 = CONCAT11((char)uVar1,(char)((ushort)uVar1 >> 8));
  FUN_00011d00(auStack_30,&local_48,2);
  if ((DAT_00016178 & 2) != 0) {
    uVar6 = FUN_00012608();
    uVar1 = FUN_000010a8((int)local_58);
    uVar2 = FUN_000010a8((int)local_56);
    FUN_00014e24("TCP SEND: %u SP %d DP %d ",uVar6,uVar1,uVar2);
  }
  if (((param_6 & 1) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157b0);
  }
  if (((param_6 & 2) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157b4);
  }
  if (((param_6 & 4) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157b8);
  }
  if (((param_6 & 8) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157bc);
  }
  if (((param_6 & 0x10) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157c0);
  }
  if ((param_6 & 0x20) == 0) {
LAB_0000b290:
    if ((DAT_00016178 & 2) != 0) {
      uVar6 = FUN_00001080(local_54);
      FUN_00014e24(" seq %u ",uVar6);
    }
  }
  else if ((DAT_00016178 & 2) != 0) {
    FUN_00014e24(&DAT_000157c4);
    goto LAB_0000b290;
  }
  if ((param_6 & 0x10) != 0) {
    if ((DAT_00016178 & 2) == 0) goto LAB_0000b354;
    uVar6 = FUN_00001080(local_50);
    FUN_00014e24("ack %u ",uVar6);
  }
  if (((DAT_00016178 & 2) != 0) && (FUN_00014e24("win %d len %d ",0,0), (DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_000157ec);
  }
LAB_0000b354:
  sVar3 = FUN_00004ec4(puVar5,param_1,0,0,0,0,0,0,6,0);
  if (sVar3 != 0) {
    FUN_00001018(puVar5);
    return 0xffffffff;
  }
  FUN_00001018(puVar5);
  return 0;
}


================================================================