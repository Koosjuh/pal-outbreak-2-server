FUNCTION FUN_005e0140 @ 0x005e0140  size=292
CALLERS (1): FUN_005e0270@0x005e0270
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e0140(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = uRam003435bc;
  if ((long)*(char *)(iRam00701068 + 0x609c0) != 0x80) {
    func_0x001cb360(param_1,uRam003435bc,0x10001,0);
    if (param_2 == 1) {
      func_0x001cb6a0(*(char *)(iRam00701068 + 0x609c0) + 0x5000,uVar1);
    }
    else if (param_2 == 0) {
      func_0x001cb5f0(*(char *)(iRam00701068 + 0x609c0) + 0x5000,uVar1);
    }
    uVar1 = func_0x001cbcb0(*(char *)(iRam00701068 + 0x609c0) + 0x5000);
    *(undefined4 *)(*(char *)(iRam00701068 + 0x609c0) * 4 + iRam00701068 + 0x607c0) = uVar1;
    *(char *)(iRam00701068 + 0x609c0) = *(char *)(iRam00701068 + 0x609c0) + '\x01';
  }
  return;
}



================================================================