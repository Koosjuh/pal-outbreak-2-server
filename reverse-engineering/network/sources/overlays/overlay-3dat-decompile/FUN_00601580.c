FUNCTION FUN_00601580 @ 0x00601580  size=272
CALLERS (0): 
CALLEES (1): FUN_005c2740@0x005c2740
----------------------------------------------------------------

void FUN_00601580(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  char cStack_10;
  
  uVar4 = *param_1;
  if ((cRam006c4b90 != '\x06') &&
     (func_0x00106b60(0x6c79ac,0,0xec0), cStack_10 = (char)uVar4, cStack_10 == '\0')) {
    uVar3 = 0;
    puVar2 = (undefined1 *)(iRam003435d4 + 0xc942c);
    do {
      iVar1 = uVar3 * 0x3b0;
      FUN_005c2740(uVar3 & 0xffff,iVar1 + 0x6c7c2c,iVar1 + 0x6c7c3c,iVar1 + 0x6c7c50);
      func_0x00106b60(puVar2,0,0x830);
      func_0x00109eb8(puVar2 + 0x14,iVar1 + 0x6c7c2c);
      func_0x00109eb8(puVar2 + 4,iVar1 + 0x6c7c3c);
      if (puVar2[4] != '\0') {
        *puVar2 = 1;
        puVar2[1] = 1;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 0x830;
    } while ((int)uVar3 < 4);
  }
  return;
}



================================================================