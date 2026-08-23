FUNCTION FUN_00001d0c @ 0x00001d0c size=176
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (3): FUN_0000d8c0@0x0000d8c0, FUN_00010be0@0x00010be0, FUN_0000d5a8@0x0000d5a8

undefined4 FUN_00001d0c(int param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  FUN_00010be0();
  sVar2 = FUN_0000d5a8(&DAT_00014994,param_1);
  uVar3 = 0xffffffef;
  if (sVar2 == 0) {
    sVar2 = FUN_0000d8c0(&DAT_00014994);
    iVar1 = DAT_000149c4;
    uVar3 = 0xffffffef;
    if ((sVar2 == 0) && (uVar3 = 0, *(short *)(param_1 + 6) == 4)) {
      sVar2 = *(short *)(DAT_000149c4 + 0x58);
      if (sVar2 == -0x3fdd) {
        *(undefined2 *)(param_1 + 6) = 0x80;
        sVar2 = *(short *)(iVar1 + 0x58);
      }
      uVar3 = 0;
      if (sVar2 == -0x3ddd) {
        *(undefined2 *)(param_1 + 6) = 0x82;
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


================================================================