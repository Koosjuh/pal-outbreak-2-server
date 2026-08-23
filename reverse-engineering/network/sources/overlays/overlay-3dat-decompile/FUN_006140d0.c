FUNCTION FUN_006140d0 @ 0x006140d0  size=1116
CALLERS (1): FUN_00613c30@0x00613c30
CALLEES (6): FUN_0060f8b0@0x0060f8b0, FUN_006146e0@0x006146e0, FUN_00614550@0x00614550, FUN_00614870@0x00614870, FUN_0060f880@0x0060f880, FUN_00616570@0x00616570
----------------------------------------------------------------

void FUN_006140d0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  short sVar7;
  undefined1 auStack_400 [512];
  undefined1 auStack_200 [512];
  
  puVar3 = (undefined4 *)FUN_0060f8b0();
  iVar4 = iRam0070d1c0 + *(char *)(iRam0070d1c0 + 0x13) * 0x14;
  iVar1 = *(int *)(iVar4 + 0x268);
  if ((*(int *)(iVar4 + 600) == 1) &&
     (((iVar5 = *(char *)(iRam0070d1c0 + 0x13) * 0x1340 + iRam0070d1c0,
       *(char *)(iVar5 + 0xb700) == '\0' || (*(int *)(iVar5 + 0xc200) != 2)) ||
      (*(char *)(iVar5 + 0xc225) != -1)))) {
    func_0x00109728(auStack_200,0x654150,puVar3[9],*(undefined4 *)(iVar4 + 0x260),
                    *(undefined4 *)(iVar4 + 0x264));
    func_0x00109eb8(auStack_400,auStack_200);
  }
  else {
    func_0x00109eb8(auStack_400,puVar3[10]);
  }
  FUN_006146e0(0x44,0x82,auStack_400);
  if (((iVar1 != 0) && (*(int *)(iVar4 + 600) == 1)) &&
     ((iVar4 = *(char *)(iRam0070d1c0 + 0x13) * 0x1340 + iRam0070d1c0,
      *(char *)(iVar4 + 0xb700) == '\0' ||
      ((*(int *)(iVar4 + 0xc200) != 2 || (*(char *)(iVar4 + 0xc225) != -1)))))) {
    iVar4 = *(int *)(iVar1 + 0x1310);
    uVar6 = 4;
    if ((iVar4 != 6) &&
       (((uVar6 = 3, iVar4 != 5 && (uVar6 = 2, iVar4 != 3)) && (uVar6 = 1, iVar4 != 2)))) {
      uVar6 = 0;
    }
    uVar6 = FUN_0060f880(uVar6);
    func_0x00109728(auStack_200,0x654160,*puVar3,uVar6);
    FUN_00614870(auStack_400,auStack_200,0x2c);
    FUN_006146e0(0x44,0x9b,auStack_400);
    sVar7 = 0xb4;
    if (*(char *)(iVar1 + 0x1325) == '\x01') {
      FUN_00614870(auStack_200,iVar1 + 0xb00,0x1c);
      FUN_00616570(auStack_200,auStack_400,0x100);
      func_0x00109728(auStack_200,0x654160,puVar3[1],auStack_400);
      FUN_006146e0(0x44,0xb4,auStack_200);
      sVar7 = 0xcd;
    }
    else if (*(char *)(iVar1 + 0x1320) == '\x01') {
      if (*(char *)(iVar1 + 0x200) == '\0') {
        func_0x00109eb8(auStack_200,puVar3[8]);
        uVar2 = puVar3[2];
      }
      else {
        FUN_00614870(auStack_200,iVar1 + 0x200,0x1c);
        uVar2 = puVar3[2];
      }
      func_0x00109728(auStack_400,0x654160,uVar2,auStack_200);
      FUN_006146e0(0x44,0xb4,auStack_400);
      sVar7 = 0xcd;
    }
    else if (*(char *)(iVar1 + 0x300) != '\0') {
      FUN_00614550(auStack_400,iVar1 + 0x300);
      func_0x00109728(auStack_200,0x654160,puVar3[3],auStack_400);
      FUN_006146e0(0x44,0xb4,auStack_200);
      FUN_00614550(auStack_400,iVar1 + 0x400);
      func_0x00109728(auStack_200,0x654160,puVar3[4],auStack_400);
      FUN_006146e0(0x44,0xcd,auStack_200);
      FUN_00614550(auStack_400,iVar1 + 0x500);
      func_0x00109728(auStack_200,0x654160,puVar3[5],auStack_400);
      FUN_006146e0(0x44,0xe6,auStack_200);
      sVar7 = 0xff;
    }
    if (*(char *)(iVar1 + 0x600) == '\0') {
      func_0x00109eb8(auStack_200,puVar3[8]);
      uVar2 = puVar3[6];
    }
    else {
      FUN_00614550(auStack_200,iVar1 + 0x600);
      uVar2 = puVar3[6];
    }
    func_0x00109728(auStack_400,0x654160,uVar2,auStack_200);
    FUN_006146e0(0x44,sVar7,auStack_400);
    if (*(char *)(iVar1 + 0x700) == '\0') {
      func_0x00109eb8(auStack_200,puVar3[8]);
      uVar2 = puVar3[7];
    }
    else {
      FUN_00614550(auStack_200,iVar1 + 0x700);
      uVar2 = puVar3[7];
    }
    func_0x00109728(auStack_400,0x654160,uVar2,auStack_200);
    FUN_006146e0(0x44,sVar7 + 0x19,auStack_400);
  }
  return;
}



================================================================