FUNCTION FUN_005c9900 @ 0x005c9900  size=256
CALLERS (0): 
CALLEES (5): FUN_005de0f0@0x005de0f0, FUN_005d7410@0x005d7410, FUN_005ca6a0@0x005ca6a0, FUN_005dee40@0x005dee40, FUN_005de110@0x005de110
----------------------------------------------------------------

void FUN_005c9900(void)

{
  undefined8 uVar1;
  long lVar2;
  
  FUN_005ca6a0();
  FUN_005dee40();
  FUN_005de0f0();
  FUN_005de110(*(undefined4 *)(iRam00701068 + 0x68dd0));
  uVar1 = FUN_005d7410();
  lVar2 = func_0x00109d70(uVar1,0x642cc0);
  if (lVar2 != 0) {
    uVar1 = FUN_005d7410();
    lVar2 = func_0x00109d70(uVar1,0x642cd0);
    if (lVar2 != 0) {
      uVar1 = FUN_005d7410();
      lVar2 = func_0x00109d70(uVar1,0x642d00);
      if (lVar2 != 0) {
        *(undefined1 *)(iRam00701068 + 0x60dc5) = 0;
        goto LAB_005c99c4;
      }
    }
  }
  *(undefined1 *)(iRam00701068 + 0x60dc5) = 1;
LAB_005c99c4:
  *(undefined1 *)(iRam00701070 + 0x37) = 0;
  *(undefined1 *)(iRam00701070 + 0x2e) = 3;
  *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
  return;
}



================================================================