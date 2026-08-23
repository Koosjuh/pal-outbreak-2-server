FUNCTION FUN_00618c90 @ 0x00618c90  size=412
CALLERS (0): 
CALLEES (5): FUN_00619220@0x00619220, FUN_00619170@0x00619170, FUN_00636890@0x00636890, FUN_00637170@0x00637170, FUN_00618e30@0x00618e30
----------------------------------------------------------------

void FUN_00618c90(void)

{
  long lVar1;
  byte *pbVar2;
  int iVar3;
  
  func_0x001a7440();
  func_0x001a7b70(0x6c,1);
  func_0x001a7b70(99,0x10000);
  if (cRam006c4fd7 != '\0') {
    FUN_00619220();
  }
  iVar3 = 0;
  pbVar2 = (byte *)0x7133f0;
  do {
    if (((*pbVar2 & pbVar2[1]) != 0) && (*(int *)(pbVar2 + 0x30) == 1)) {
      FUN_00618e30(pbVar2);
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 0x54;
  } while (iVar3 < 0x40);
  iVar3 = 0;
  pbVar2 = (byte *)0x7133f0;
  do {
    if (((*pbVar2 & pbVar2[1]) != 0) && (*(int *)(pbVar2 + 0x30) == 0)) {
      FUN_00618e30(pbVar2);
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 0x54;
  } while (iVar3 < 0x40);
  if (cRam006c5538 != '\0') {
    FUN_00619170();
  }
  iVar3 = 0;
  pbVar2 = (byte *)0x7133f0;
  do {
    if (((*pbVar2 & pbVar2[1]) != 0) && (*(int *)(pbVar2 + 0x30) == 2)) {
      FUN_00618e30(pbVar2);
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 0x54;
  } while (iVar3 < 0x40);
  func_0x001a7b70(99,0);
  func_0x001a7b70(0x6c,1);
  lVar1 = FUN_00637170();
  if ((lVar1 != 0) && (sRam006c5524 == 0)) {
    FUN_00636890(0);
  }
  if (cRam006c4fde != '\0') {
    func_0x001a8a00();
  }
  return;
}



================================================================