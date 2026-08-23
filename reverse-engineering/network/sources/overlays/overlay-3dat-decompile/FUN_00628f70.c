FUNCTION FUN_00628f70 @ 0x00628f70  size=368
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (5): FUN_00629160@0x00629160, FUN_0062b9e0@0x0062b9e0, FUN_005b14b0@0x005b14b0, FUN_0062a5c0@0x0062a5c0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_00628f70(undefined8 param_1,char *param_2)

{
  char cVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  cVar1 = param_2[10];
  lVar3 = FUN_005b09b0(param_2 + 10,9,2);
  if (lVar3 == 0) {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 == 0) {
      lVar3 = FUN_005b14b0(0x200);
      if (lVar3 != 0) {
        func_0x001b0140(2);
        return 0xfffffffe;
      }
    }
    else {
      func_0x001b0140(1);
      if (*(short *)(param_2 + 10) == 9) {
        FUN_0062b9e0(param_1);
        *param_2 = '\x05';
        param_2[1] = '\0';
        param_2[3] = '\0';
      }
      else if (*(short *)(param_2 + 10) == 8) {
        FUN_0062a5c0(param_1);
        *param_2 = '\x06';
        param_2[1] = '\0';
        param_2[3] = '\0';
      }
      else {
        *param_2 = *param_2 + '\x01';
        param_2[0x14] = '\x01';
        param_2[4] = '\b';
        param_2[5] = '\0';
        func_0x001b0140();
        iVar7 = (int)param_1;
        puVar5 = (undefined1 *)(iVar7 + 0xefa);
        iVar4 = 0xa5;
        puVar6 = (undefined1 *)(*(short *)(param_2 + 10) * 0xa5 + iVar7 + 0x9d2);
        do {
          iVar4 = iVar4 + -1;
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        } while (0 < iVar4);
        *(undefined1 *)(*(short *)(param_2 + 10) * 0xa5 + iVar7 + 0x9d2) = 0;
      }
    }
  }
  else {
    uVar2 = FUN_00629160(param_2[10],cVar1);
    *(undefined2 *)(param_2 + 10) = uVar2;
  }
  return 0xffffffff;
}



================================================================