FUNCTION FUN_00612b70 @ 0x00612b70  size=296
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (1): FUN_006146e0@0x006146e0
----------------------------------------------------------------

void FUN_00612b70(void)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(&DAT_00653f30 + (uint)bRam0034359d * 4);
  switch(*(undefined1 *)(iRam0070d1c0 + 0x4b)) {
  case 1:
    FUN_006146e0(0x122,400,*puVar1);
    return;
  case 2:
    FUN_006146e0(0xf6,400,*puVar1);
    FUN_006146e0(0x17a,400,puVar1[1]);
    break;
  case 3:
    FUN_006146e0(0x72,400,*puVar1);
    FUN_006146e0(0xf2,400,puVar1[1]);
    FUN_006146e0(0x192,400,puVar1[2]);
    break;
  case 4:
    FUN_006146e0(0x72,400,*puVar1);
    FUN_006146e0(0xf2,400,puVar1[1]);
    FUN_006146e0(0x192,400,puVar1[3]);
    break;
  case 5:
    FUN_006146e0(0x122,400,puVar1[4]);
  }
  return;
}



================================================================