FUNCTION FUN_0060e440 @ 0x0060e440  size=324
CALLERS (1): FUN_006153b0@0x006153b0
CALLEES (3): FUN_0060f0f0@0x0060f0f0, FUN_0060ea60@0x0060ea60, FUN_0060f350@0x0060f350
----------------------------------------------------------------

void FUN_0060e440(undefined8 param_1,int param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  func_0x00106b60(param_1,0,0xa20);
  puVar5 = (undefined4 *)param_1;
  *puVar5 = *(undefined4 *)(param_2 + 0x1300);
  if (*(char *)(param_2 + 0x1325) == '\x01') {
    func_0x00109eb8(puVar5 + 3,param_2 + 0xb00);
    func_0x00109eb8(puVar5 + 0x83,param_2 + 0xc00);
    cVar1 = *(char *)(param_2 + 0x600);
  }
  else {
    *(undefined1 *)((int)puVar5 + 5) = 1;
    if (*(char *)(param_2 + 0x1320) != -1) {
      if (*(char *)(param_2 + 0x1320) == '\x01') {
        func_0x00109eb8(puVar5 + 0x103,param_2 + 0x200);
      }
      else {
        *(undefined1 *)((int)puVar5 + 6) = 1;
        FUN_0060f0f0(param_2 + 0x300,puVar5 + 0x183);
        FUN_0060f0f0(param_2 + 0x400,puVar5 + 0x184);
        FUN_0060f0f0(param_2 + 0x500,puVar5 + 0x185);
      }
    }
    cVar1 = *(char *)(param_2 + 0x600);
  }
  if (cVar1 != '\0') {
    *(undefined1 *)((int)puVar5 + 7) = 1;
    FUN_0060f0f0(param_2 + 0x600,puVar5 + 0x186);
    FUN_0060f0f0(param_2 + 0x700,puVar5 + 0x187);
  }
  lVar2 = FUN_0060ea60(puVar5 + 0x186);
  if (lVar2 == 0) {
    *(undefined1 *)((int)puVar5 + 7) = 0;
    iVar3 = 0;
    do {
      *(undefined1 *)((int)puVar5 + iVar3 + 0x618) = 0;
      iVar4 = iVar3 + 1;
      *(undefined1 *)((int)puVar5 + iVar3 + 0x61c) = 0;
      iVar3 = iVar4;
    } while (iVar4 < 4);
  }
  FUN_0060f350(puVar5 + 0x188,param_3);
  return;
}



================================================================