FUNCTION FUN_00012bb8 @ 0x00012bb8 size=184
CALLERS (0): 
CALLEES (3): FUN_0001287c@0x0001287c, FUN_0001296c@0x0001296c, FUN_00012ac4@0x00012ac4

uint FUN_00012bb8(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 auStack_20 [16];
  
  FUN_0001287c(auStack_20,param_1,0x10);
  iVar5 = 0;
  uVar3 = 0;
  puVar4 = auStack_20;
  do {
    iVar1 = FUN_0001296c(puVar4,&DAT_00015bf0);
    puVar4 = (undefined1 *)0x0;
    if (iVar1 == 0) break;
    uVar2 = FUN_00012ac4(iVar1);
    if (0xff < uVar2) {
      uVar3 = 0;
      break;
    }
    iVar5 = iVar5 + 1;
    uVar3 = uVar3 * 0x100 + uVar2;
  } while (iVar5 < 4);
  return uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
}


================================================================