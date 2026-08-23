FUNCTION FUN_005d7f80 @ 0x005d7f80  size=320
CALLERS (1): FUN_005d80c0@0x005d80c0
CALLEES (5): FUN_005d78d0@0x005d78d0, FUN_005dedc0@0x005dedc0, FUN_005d7410@0x005d7410, FUN_005d7cf0@0x005d7cf0, FUN_005df340@0x005df340
----------------------------------------------------------------

void FUN_005d7f80(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
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
    lVar3 = FUN_005d78d0(auStack_100,*(undefined1 *)(param_1 + 0x10c),param_1 + 0x108);
    if (lVar3 != 0) {
      iVar4 = (int)lVar3;
      *(int *)(param_1 + 0x114) = iVar4;
      iVar1 = *(int *)(iVar4 + 0x104);
      if (iVar1 != 6) {
        if (iVar1 == 3) {
          *(undefined4 *)(param_1 + 0x104) = 3;
          uVar2 = func_0x01212970();
          *(int *)(param_1 + 0x118) = (int)uVar2;
          FUN_005d7cf0(uVar2,iVar4 + 4,uRam00701be0,0x701d00,0x701bf0,cRam00701000 == '\x05',
                       *(undefined4 *)(*(char *)((int)uVar2 + 0x46) * 4 + 0x701020),0x4000);
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