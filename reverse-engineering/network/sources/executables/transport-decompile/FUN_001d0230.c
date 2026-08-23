
void FUN_001d0230(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [32];
  
  FUN_001cbc20(0x2400);
  FUN_001a7b70(0x15,2);
  FUN_001a7b70(1,0);
  FUN_001a7b70(0x12,0);
  FUN_001a7b70(0x62,1);
  FUN_001a7b70(0xc,0);
  FUN_001a7b70(0x66,0);
  FUN_001a7b70(2,0);
  FUN_001a7b70(0x12,0);
  FUN_001a7b70(0,0);
  FUN_00106b60(auStack_20,0,0x20);
  uVar1 = uRam0034357a;
  FUN_00109728(auStack_20,0x24cc90,uRam0034357a);
  FUN_00109728(auStack_40,0x24cca0,uVar1);
  iVar2 = iRam003435bc;
  iVar4 = iRam003435bc + 0x2ff000;
  uVar3 = FUN_001ab460(0x200,10);
  *(undefined4 *)(iVar2 + 0x2ff808) = uVar3;
  *(undefined4 *)(iVar2 + 0x2ff818) = 0;
  iVar2 = iRam003435bc;
  *(int *)(iRam003435bc + 0x301018) = iVar4;
  *(undefined4 *)(iVar2 + 0x301020) = 0;
  *(undefined4 *)(iVar2 + 0x301024) = 0;
  *(int *)(iVar2 + 0x30101c) = iRam003435bc + 0x301100;
  if (cRam00343577 == '\0') {
    FUN_001cce80(uRam0034357a,0xffffffffffffffff,iVar4,2);
    uVar3 = *(undefined4 *)(iVar2 + 0x30101c);
  }
  else {
    FUN_001a1750(auStack_20,iVar4,0x2400,0x10002);
    FUN_00109728(auStack_40,0x24ccc0,uVar1);
    uVar3 = *(undefined4 *)(iVar2 + 0x30101c);
  }
  FUN_001cb360(auStack_40,uVar3,0x10001,0);
  *(int *)(iVar2 + 0x30101c) = iRam003435bc + 0x301500;
  return;
}

