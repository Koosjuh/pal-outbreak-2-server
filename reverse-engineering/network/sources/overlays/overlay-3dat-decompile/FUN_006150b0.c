FUNCTION FUN_006150b0 @ 0x006150b0  size=752
CALLERS (2): FUN_00610580@0x00610580, FUN_00610830@0x00610830
CALLEES (0): 
----------------------------------------------------------------

void FUN_006150b0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  
  iVar2 = iRam0070d1c0;
  uRam0035bfe0 = 0;
  piVar4 = (int *)(iRam0070d1c0 + 0xed0);
  func_0x00106b60(0x35bee0,0,0x100);
  uRam0035bed8 = 0;
  uRam0035bed0 = 0;
  func_0x00106b60(0x35bcc0,0,0x100);
  func_0x00106b60(0x35bbb0,0,0x100);
  func_0x00106b60(0x35bab0,0,0x100);
  uRam0035ba98 = 0;
  uRam0035ba90 = 0;
  uRam0035ba88 = 0;
  uRam0035bcb8 = 0;
  uRam0035bcb0 = 0;
  func_0x00106b60(0x35bdd0,0,0xf0);
  func_0x00106b60(0x35bdc0,0,0x10);
  uRam0035bec0 = 0;
  uRam0035baa0 = 3;
  if (*(char *)(param_1 + 0x1320) == '\x01') {
    uRam0035bec8 = 1;
    func_0x00109eb8(0x35bcc0,param_1 + 0x200);
    cVar3 = *(char *)(param_1 + 0x600);
  }
  else {
    if (*(char *)(param_1 + 0x1325) == '\x01') {
      uRam0035bec8 = 2;
      func_0x00109eb8(0x35bbb0,param_1 + 0xb00);
      func_0x00109eb8(0x35bab0,param_1 + 0xc00);
    }
    else {
      uRam0035bec8 = 0;
      uRam0035ba98 = func_0x001c0690(param_1 + 0x300);
      uRam0035ba90 = func_0x001c0690(param_1 + 0x400);
      uRam0035ba88 = func_0x001c0690(param_1 + 0x500);
    }
    cVar3 = *(char *)(param_1 + 0x600);
  }
  if (cVar3 != '\0') {
    uRam0035bcb8 = func_0x001c0690(param_1 + 0x600);
  }
  if (*(char *)(param_1 + 0x700) != '\0') {
    uRam0035bcb0 = func_0x001c0690(param_1 + 0x700);
  }
  iVar1 = *(int *)(param_1 + 0x1310);
  if (iVar1 == 6) {
    uRam0035baa8 = 4;
  }
  else if (iVar1 == 5) {
    uRam0035baa8 = 3;
  }
  else if (iVar1 == 3) {
    uRam0035baa8 = 0;
  }
  else if (iVar1 == 2) {
    uRam0035baa8 = 1;
  }
  else {
    uRam0035baa8 = 0;
  }
  bRam00701be0 = 0;
  func_0x00106b60(0x701d00,0,0x100);
  func_0x00106b60(0x701bf0,0,0x100);
  if (*piVar4 == 1) {
    bRam00701be0 = 1;
    func_0x00109728(0x701d00,0x654168,iVar2 + 0xed8,*(undefined2 *)(iVar2 + 0xed4));
    if (*(char *)(iVar2 + 0xfd8) != '\0') {
      bRam00701be0 = bRam00701be0 | 2;
      func_0x00109728(0x701bf0,0x654178,iVar2 + 0xfd8,*(undefined2 *)(iVar2 + 0xed6));
    }
  }
  return;
}



================================================================