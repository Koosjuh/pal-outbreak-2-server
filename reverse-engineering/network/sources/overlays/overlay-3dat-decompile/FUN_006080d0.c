FUNCTION FUN_006080d0 @ 0x006080d0  size=516
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005b7cd0@0x005b7cd0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_006080d0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 auStack_20 [32];
  
  iVar3 = cRam006c5497 * 0x158;
  FUN_005b7cd0(0x42f00000,0x439c0000,0,iVar3 + 0x70c058);
  FUN_005af2c0(0);
  FUN_005af2e0(0x14);
  iVar1 = func_0x001ae3e0(iVar3 + 0x70c048);
  iVar2 = (int)((ulong)((long)(iVar1 * 5) << 0x21) >> 0x20);
  if (iVar1 * 10 < 0) {
    iVar2 = iVar1 * 10 + 1;
  }
  FUN_005af1e0(0x140 - (iVar2 >> 1),0x48,0,iVar3 + 0x70c048);
  FUN_005af2c0(0);
  FUN_005af2e0(0x10);
  uVar4 = FUN_0062fea0(0x48);
  FUN_005af1e0(0x142,0xe8,0,uVar4);
  uVar4 = FUN_0062fea0(7);
  func_0x00109728(auStack_20,0x64a0f8,*(undefined2 *)(iVar3 + 0x70c002),uVar4);
  FUN_005af1e0(0x198,0xf8,0,auStack_20);
  uVar4 = FUN_0062fea0(0x49);
  FUN_005af1e0(0x142,0xc0,0,uVar4);
  uVar4 = FUN_0062fea0(7);
  func_0x00109728(auStack_20,0x64a0f8,*(undefined2 *)(iVar3 + 0x70c004),uVar4);
  FUN_005af1e0(0x198,0xd0,0,auStack_20);
  FUN_005af2e0(0x10);
  FUN_005af2c0(0);
  func_0x00109728(auStack_20,0x64a100,cRam006c5497 + 1,uRam008744f8);
  lVar5 = func_0x001ae3e0(auStack_20);
  iVar3 = (int)lVar5;
  if (lVar5 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar2 = (iVar3 >> 1) * 10;
  iVar3 = (int)((ulong)((long)((iVar3 >> 1) * 5) << 0x21) >> 0x20);
  if (iVar2 < 0) {
    iVar3 = iVar2 + 1;
  }
  FUN_005af1e0(0x140 - (iVar3 >> 1),0x120,0,auStack_20);
  return;
}



================================================================