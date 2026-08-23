FUNCTION FUN_0060e250 @ 0x0060e250  size=488
CALLERS (1): FUN_0060e820@0x0060e820
CALLEES (4): FUN_0060ea60@0x0060ea60, FUN_006166f0@0x006166f0, FUN_0060f150@0x0060f150, FUN_0060f480@0x0060f480
----------------------------------------------------------------

void FUN_0060e250(int param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  int iVar3;
  
  FUN_006166f0(param_2);
  iVar3 = (int)param_2;
  *(undefined1 *)(iVar3 + 0x1324) = 0;
  if (*(char *)(param_1 + 9) == '\x01') {
    *(undefined4 *)(iVar3 + 0x1300) = 3;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1300) = 1;
  }
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(iVar3 + 0x1325) = 1;
    *(undefined1 *)(iVar3 + 0x1320) = 0;
    func_0x00109eb8(iVar3 + 0xb00,param_1 + 0xc);
    func_0x00109eb8(iVar3 + 0xc00,param_1 + 0x20c);
    func_0x00109eb8(iVar3 + 0xd00,0x64b7a8);
    *(undefined1 *)(iVar3 + 0x1323) = 1;
    *(undefined1 *)(iVar3 + 0x1324) = 4;
    *(undefined1 *)(iVar3 + 0x1326) = 0;
    *(undefined1 *)(iVar3 + 0x1327) = 0;
    *(undefined1 *)(iVar3 + 0x1328) = 0;
    *(undefined4 *)(iVar3 + 0x1304) = 0x5ae;
    *(undefined4 *)(iVar3 + 0x1300) = 2;
    *(undefined4 *)(iVar3 + 0x1308) = 0;
  }
  else {
    *(undefined1 *)(iVar3 + 0x1325) = 0xff;
    if (*(char *)(param_1 + 6) == '\0') {
      *(undefined1 *)(iVar3 + 0x1320) = 1;
      func_0x00109eb8(iVar3 + 0x200,param_1 + 0x40c);
      cVar1 = *(char *)(param_1 + 7);
      goto LAB_0060e364;
    }
    *(undefined1 *)(iVar3 + 0x1320) = 0;
    FUN_0060f150(iVar3 + 0x300,param_1 + 0x60c);
    FUN_0060f150(iVar3 + 0x400,param_1 + 0x610);
    FUN_0060f150(iVar3 + 0x500,param_1 + 0x614);
  }
  cVar1 = *(char *)(param_1 + 7);
LAB_0060e364:
  if (cVar1 == '\0') {
    if (*(char *)(iVar3 + 0x1320) != '\x01') {
      *(undefined1 *)(iVar3 + 0x1321) = 1;
      *(undefined1 *)(iVar3 + 0x1322) = 1;
    }
  }
  else {
    lVar2 = FUN_0060ea60(param_1 + 0x618);
    if (lVar2 != 0) {
      FUN_0060f150(iVar3 + 0x600,param_1 + 0x618);
    }
    lVar2 = FUN_0060ea60(param_1 + 0x61c);
    if (lVar2 != 0) {
      FUN_0060f150(iVar3 + 0x700,param_1 + 0x61c);
    }
    if (*(char *)(iVar3 + 0x600) == '\0') {
      func_0x00106b60(iVar3 + 0x600,0,0x100);
      func_0x00106b60(iVar3 + 0x700,0,0x100);
      *(undefined1 *)(iVar3 + 0x1321) = 1;
      *(undefined1 *)(iVar3 + 0x1322) = 1;
    }
    if (*(char *)(iVar3 + 0x700) == '\0') {
      func_0x00106b60(iVar3 + 0x700,0,0x100);
    }
  }
  FUN_0060f480(param_3,param_1 + 0x620);
  return;
}



================================================================