FUNCTION FUN_0061cce0 @ 0x0061cce0  size=912
CALLERS (3): FUN_0061d210@0x0061d210, FUN_0061d080@0x0061d080, FUN_0061c9f0@0x0061c9f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061cce0(int param_1,int param_2,undefined2 param_3,long param_4,long param_5,long param_6)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iStack_110;
  undefined1 auStack_100 [4];
  undefined1 uStack_fc;
  undefined1 uStack_fb;
  undefined1 auStack_80 [128];
  
  iStack_110 = 0;
  lVar3 = func_0x001aeff0(0);
  iVar2 = (int)param_6;
  if (lVar3 == 0) {
    iVar4 = (iVar2 << 1) / 3;
  }
  else {
    iVar4 = iVar2 >> 1;
    if (param_6 < 0) {
      iVar4 = iVar2 + 1 >> 1;
    }
  }
  while( true ) {
    iStack_110 = iStack_110 + 1;
    if (199 < iStack_110) {
      return;
    }
    iVar2 = func_0x00109be0(param_1,0x25);
    if (iVar2 == 0) break;
    func_0x00106b60(auStack_80,0,0x80);
    iVar5 = iVar2 - param_1;
    func_0x0010a4f0(auStack_100,param_1,iVar5);
    auStack_100[iVar5] = 0;
    func_0x0010a188(auStack_80,param_1,iVar5);
    iVar5 = func_0x001ae3e0(auStack_100);
    func_0x001af080((short)param_2,param_3);
    func_0x001af0b0(0);
    if (5 < param_4) {
      param_4 = 5;
    }
    func_0x001af0c0(*(undefined4 *)((int)param_4 * 4 + 0x669c00));
    func_0x001af190(auStack_80);
    param_2 = param_2 + iVar4 * iVar5;
    func_0x001af080((short)param_2,param_3);
    if (5 < param_5) {
      param_5 = 5;
    }
    func_0x001af0c0(*(undefined4 *)((int)param_5 * 4 + 0x669c00));
    cVar1 = *(char *)(iVar2 + 1);
    if (cVar1 == 'v') {
      auStack_100[1] = 0x2e;
      uStack_fb = 0;
      auStack_100[0] = uRam006ca064;
      auStack_100[2] = uRam006ca065;
      auStack_100[3] = uRam006ca066;
      uStack_fc = uRam006ca067;
      func_0x001af190(auStack_100);
      param_2 = param_2 + iVar4 * 5;
    }
    else if (cVar1 == '2') {
      func_0x00109eb8(auStack_100,PTR_DAT_00669bf0);
      func_0x001af190(auStack_100);
      param_2 = param_2 + iVar4;
    }
    else if (cVar1 == '1') {
      func_0x00109eb8(auStack_100,PTR_DAT_00669bec);
      func_0x001af190(auStack_100);
      param_2 = param_2 + iVar4;
    }
    else if (cVar1 == 'y') {
      func_0x00109728(auStack_100,0x669c18,uRam0071535a);
      func_0x001af190(auStack_100);
      param_2 = param_2 + iVar4 * 3;
    }
    else if (cVar1 == 's') {
      func_0x00109eb8(auStack_100,(&PTR_DAT_00669bec)[cRam00715359]);
      func_0x001af190(auStack_100);
      param_2 = param_2 + iVar4;
    }
    else {
      if (4 < param_4) {
        param_4 = 4;
      }
      func_0x001af0c0(*(undefined4 *)((int)param_4 * 4 + 0x669c00));
      func_0x001af190(0x669c20);
      param_2 = param_2 + iVar4;
      iVar2 = iVar2 + -1;
    }
    param_1 = iVar2 + 2;
  }
  func_0x001af080((short)param_2,param_3);
  if (4 < param_4) {
    param_4 = 4;
  }
  func_0x001af0c0(*(undefined4 *)((int)param_4 * 4 + 0x669c00));
  func_0x001af0d0(param_1);
  return;
}



================================================================