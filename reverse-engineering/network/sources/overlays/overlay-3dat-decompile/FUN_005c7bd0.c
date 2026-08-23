FUNCTION FUN_005c7bd0 @ 0x005c7bd0  size=204
CALLERS (1): FUN_00606fc0@0x00606fc0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c7bd0(ulong param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *param_2 = (short)param_1;
    iVar2 = ((int)(param_1 & 0xffff) + -1) * 0x260;
    func_0x00109eb8(param_2 + 0x24,iVar2 + 0x365e5f);
    func_0x00109eb8(param_2 + 4,iVar2 + 0x365e20);
    func_0x00109eb8(param_2 + 0x2c,iVar2 + 0x365e77);
    iVar2 = *(int *)(iVar2 + 0x365f80);
    param_2[1] = *(undefined2 *)(iVar2 + 300);
    param_2[2] = *(undefined2 *)(iVar2 + 0x12a);
    if (((ulong)uRam0086f800 != 0) && ((ulong)uRam0086f800 == (param_1 & 0xffff))) {
      param_2[1] = uRam0086f7f8;
    }
    uVar1 = 0;
  }
  return uVar1;
}



================================================================