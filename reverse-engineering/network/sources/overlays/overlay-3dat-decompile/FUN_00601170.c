FUNCTION FUN_00601170 @ 0x00601170  size=236
CALLERS (0): 
CALLEES (2): FUN_005c0370@0x005c0370, FUN_005adc80@0x005adc80
----------------------------------------------------------------

void FUN_00601170(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uStack_10;
  
  uVar3 = *param_1;
  if (cRam006c4b90 != '\x06') {
    uVar2 = FUN_005adc80(2);
    uStack_10 = (char)uVar3;
    if (uStack_10 == '\0') {
      iVar1 = (uVar2 - 1) * 0x15c;
      FUN_005c0370(uVar2 & 0xffff,iVar1 + 0x6c0764,iVar1 + 0x6c0766,iVar1 + 0x6c0768,
                   iVar1 + 0x6c076a,iVar1 + 0x6c076c);
    }
    else {
      iVar1 = (uVar2 - 1) * 0x15c;
      *(undefined2 *)(iVar1 + 0x6c0764) = 0;
      *(undefined2 *)(iVar1 + 0x6c0766) = 0;
      *(undefined2 *)(iVar1 + 0x6c0768) = 0;
      *(undefined2 *)(iVar1 + 0x6c076a) = 0;
      *(undefined2 *)(iVar1 + 0x6c076c) = 0;
    }
  }
  return;
}



================================================================