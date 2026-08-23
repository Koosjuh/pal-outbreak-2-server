FUNCTION FUN_005d7e00 @ 0x005d7e00  size=376
CALLERS (1): FUN_005d80c0@0x005d80c0
CALLEES (5): FUN_005dedc0@0x005dedc0, FUN_005d7760@0x005d7760, FUN_005d7410@0x005d7410, FUN_005d7cf0@0x005d7cf0, FUN_005df340@0x005df340
----------------------------------------------------------------

void FUN_005d7e00(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 auStack_100 [256];
  
  FUN_005dedc0(auStack_100,param_1 + 4);
  uVar2 = FUN_005d7410();
  lVar3 = FUN_005df340(uVar2,auStack_100);
  if (lVar3 == 0) {
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 2;
    *(undefined1 *)(param_1 + 0x125) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  else {
    lVar3 = FUN_005d7760(auStack_100,*(undefined1 *)(param_1 + 0x10c),param_1 + 0x108);
    if (lVar3 == 0) {
      *(undefined4 *)(param_1 + 0x104) = 6;
      *(undefined1 *)(param_1 + 0x124) = 8;
      *(undefined1 *)(param_1 + 0x125) = 0;
    }
    else {
      iVar5 = (int)lVar3;
      *(int *)(param_1 + 0x114) = iVar5;
      iVar1 = *(int *)(iVar5 + 0x104);
      if (iVar1 != 6) {
        if (iVar1 == 3) {
          *(undefined4 *)(param_1 + 0x104) = 3;
          uVar2 = func_0x01212970();
          *(int *)(param_1 + 0x118) = (int)uVar2;
          uVar4 = 1;
          if ((*(char *)(param_1 + 0x10c) != '\x06') && (*(char *)(param_1 + 0x10c) != '\x02')) {
            uVar4 = 0;
          }
          FUN_005d7cf0(uVar2,iVar5 + 4,uRam00701be0,0x701d00,0x701bf0,uVar4,
                       *(undefined4 *)(iVar5 + 0x10c),0x8000);
        }
        else if (iVar1 == 2) {
          *(undefined4 *)(param_1 + 0x104) = 5;
          *(undefined4 *)(param_1 + 0x118) = 0;
        }
      }
    }
  }
  return;
}



================================================================