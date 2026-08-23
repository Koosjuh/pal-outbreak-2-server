FUNCTION FUN_00601c00 @ 0x00601c00  size=324
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00601ac0@0x00601ac0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00601c00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_40 [64];
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 1) = 0;
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  }
  iVar1 = iRam006c5510;
  iVar2 = iRam006c5510 / 0x3c;
  if (99 < iVar2) {
    iVar2 = 99;
  }
  func_0x00106b60(auStack_40,0,0x40);
  FUN_00601ac0(auStack_40,iVar2,iVar1 % 0x3c);
  FUN_005af2c0(0);
  FUN_005af2e0(0x10);
  if (iRam006c5510 < 0xb) {
    if ((iRam006c5510 < 0xb) && (iRam006c5510 != 0)) {
      uVar3 = FUN_0062fea0(0x44);
      iVar2 = func_0x001ae3e0(uVar3);
      uVar3 = FUN_0062fea0(0x44);
      FUN_005af1e0(iVar2 * -8 + 600,0x20,1,uVar3);
    }
  }
  else {
    iVar2 = func_0x001ae3e0(auStack_40);
    FUN_005af1e0(iVar2 * -8 + 600,0x20,1,auStack_40);
  }
  return;
}



================================================================