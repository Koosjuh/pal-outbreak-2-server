FUNCTION FUN_006290e0 @ 0x006290e0  size=128
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (3): FUN_00629a40@0x00629a40, FUN_00629d00@0x00629d00, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

undefined4 FUN_006290e0(undefined8 param_1,undefined8 param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)param_2;
  *(short *)(pcVar1 + 4) = *(short *)(pcVar1 + 4) + -1;
  if (*(short *)(pcVar1 + 4) < 0) {
    *pcVar1 = *pcVar1 + '\x01';
    pcVar1[0x14] = '\0';
    FUN_00629a40(param_2,1);
    FUN_00629d00(param_2,1);
    pcVar1[0xc] = '\x01';
    pcVar1[0xd] = '\0';
    FUN_005b7fd0(9,1,pcVar1 + 0xc,3);
  }
  return 0xffffffff;
}



================================================================