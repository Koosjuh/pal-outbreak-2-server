FUNCTION FUN_00608680 @ 0x00608680  size=172
CALLERS (2): FUN_00617270@0x00617270, FUN_006176a0@0x006176a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00608680(int param_1)

{
  int iVar1;
  int iVar2;
  
  func_0x007df320();
  for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(param_1 + 0x990); iVar2 = iVar2 + 1) {
    iVar1 = param_1 + iVar2 * 0x3b0;
    func_0x007df390((char)iVar2,*(undefined1 *)(iVar1 + 0x22c8),*(undefined1 *)(iVar1 + 0x22ca),
                    iVar1 + 0x21dc,iVar1 + 0x21ec);
  }
  uRam00874f38 = *(undefined2 *)(param_1 + 0x1f18);
  uRam00874f3a = (char)*(undefined2 *)(param_1 + 0x1f1a);
  uRam00874f37 = (char)*(undefined2 *)(param_1 + 0x1f1c);
  uRam00874f3b = (char)*(undefined2 *)(param_1 + 6);
  return;
}



================================================================