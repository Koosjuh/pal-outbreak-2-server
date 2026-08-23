FUNCTION FUN_005f4e40 @ 0x005f4e40  size=136
CALLERS (1): FUN_005f50d0@0x005f50d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f4e40(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = iRam003435d4;
  *(int *)(iRam003435d4 + 0xc9358) = *(int *)(iRam003435d4 + 0xc9358) + 1;
  if (0x31 < *(int *)(iVar2 + 0xc9358)) {
    *(int *)(iVar2 + 0xc9358) = *(int *)(iVar2 + 0xc9358) + -0x32;
  }
  iVar1 = *(int *)(iVar2 + 0xc9360);
  if (*(int *)(iVar2 + 0xc9358) == iVar1) {
    *(int *)(iVar2 + 0xc9360) = iVar1 + 1;
    if (0x31 < *(int *)(iVar2 + 0xc9360)) {
      *(int *)(iVar2 + 0xc9360) = *(int *)(iVar2 + 0xc9360) + -0x32;
    }
    if ((cRam006c50fb != '\0') && (iVar1 == *(int *)(iVar2 + 0xc935c))) {
      *(undefined4 *)(iVar2 + 0xc935c) = *(undefined4 *)(iVar2 + 0xc9360);
    }
  }
  return;
}



================================================================