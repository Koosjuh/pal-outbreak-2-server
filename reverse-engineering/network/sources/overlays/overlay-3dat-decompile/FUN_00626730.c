FUNCTION FUN_00626730 @ 0x00626730  size=444
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_00626730(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_40 [64];
  
  if (*param_1 == '\0') {
    cRam007152e1 = cRam007152e1 + '\x01';
  }
  else if (*param_1 == '\'') {
    uRam0086f7e0 = 0;
    cRam007152e1 = '\x05';
    for (iVar2 = 0; iVar2 < (int)(uint)uRam00365bb0; iVar2 = iVar2 + 1) {
      if (*(int *)(iVar2 * 4 + 0x365bb4) == *(int *)(param_2 + 4)) {
        if (*(int *)(param_2 + 4) != 0x13) {
          cRam007152e1 = 5;
          uRam007152ea = (short)iVar2;
          uRam0086f7e0 = 0;
          return;
        }
        cRam007152e1 = 5;
        uRam007152ea = (short)iVar2;
        uRam0086f7e0 = 1;
        return;
      }
    }
    uVar3 = *(uint *)(param_2 + 4);
    if (uVar3 == 0x11) {
      iVar2 = 2;
      uRam0086f7e0 = 2;
      uVar3 = 0x331;
    }
    else if (uVar3 == 0x13) {
      iVar2 = 0;
      uVar3 = 0x32c;
      uRam0086f7e0 = 1;
    }
    else {
      iVar2 = 1;
      if (uVar3 < 0x19) {
        uVar3 = uVar3 + 0x334 & 0xffff;
      }
      else {
        uVar3 = 0x332;
      }
    }
    iVar1 = *(int *)(&DAT_0066a810 + (uint)bRam0034359d * 4);
    func_0x00106b60(0x6fc5e8,0,0x300);
    func_0x00109eb8(0x6fc5e8,**(undefined4 **)(iVar2 * 4 + iVar1 + 4));
    func_0x00109ab0(0x6fc5e8,**(undefined4 **)(iVar1 + 0x10));
    func_0x00109728(auStack_40,0x66a848,uVar3);
    func_0x00109ab0(0x6fc5e8,auStack_40);
  }
  return;
}



================================================================