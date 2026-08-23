FUNCTION FUN_005f60d0 @ 0x005f60d0  size=252
CALLERS (1): FUN_005f5f80@0x005f5f80
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005b1190@0x005b1190
----------------------------------------------------------------

bool FUN_005f60d0(int param_1)

{
  long lVar1;
  int iVar2;
  uint *puVar3;
  
  FUN_005b1190(param_1 + 0xe,param_1 + 0xc,*(undefined1 *)(param_1 + 10),7,2);
  lVar1 = FUN_005b14b0(0x40004);
  if (((lVar1 != 0) || (lVar1 = FUN_005b14b0(0x80008), lVar1 != 0)) &&
     (iVar2 = ((int)*(short *)(param_1 + 0xc) + (int)*(short *)(param_1 + 0xe)) * 0x30,
     *(char *)(iVar2 + 0x70a164) != '\0')) {
    puVar3 = (uint *)(iVar2 + 0x70a17c);
    *puVar3 = *puVar3 ^ 1;
    puVar3 = (uint *)(((int)*(short *)(param_1 + 0xc) + (int)*(short *)(param_1 + 0xe)) * 0x30 +
                     0x70a17c);
    *puVar3 = *puVar3 | 0x80;
    func_0x001b0140(0);
  }
  lVar1 = FUN_005b14b0(0x200);
  if (lVar1 != 0) {
    func_0x001b0140(2);
  }
  return lVar1 != 0;
}



================================================================