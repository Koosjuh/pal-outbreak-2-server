FUNCTION FUN_005f50d0 @ 0x005f50d0  size=528
CALLERS (1): FUN_005b53f0@0x005b53f0
CALLEES (2): FUN_005f5c60@0x005f5c60, FUN_005f4e40@0x005f4e40
----------------------------------------------------------------

void FUN_005f50d0(undefined8 param_1,undefined8 param_2,int param_3,undefined1 param_4,
                 undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  undefined1 auStack_50 [76];
  undefined1 auStack_4 [4];
  
  iVar1 = iRam003435d4;
  iVar7 = iRam003435d4 + 0xc8000;
  lVar5 = FUN_005f5c60(param_1,param_2,param_5);
  if (lVar5 == 0) {
    func_0x00109eb8(iVar7 + *(int *)(iVar1 + 0xc9358) * 0x10,param_1);
    func_0x00109eb8(iVar7 + *(int *)(iVar1 + 0xc9358) * 0x11 + 800,param_2);
    *(undefined1 *)(*(int *)(iVar1 + 0xc9358) + iVar7 + 0x1364) = param_4;
    *(char *)(*(int *)(iVar1 + 0xc9358) + iVar7 + 0x1396) = (char)param_5;
    *(undefined1 *)(*(int *)(iVar1 + 0xc9358) + iVar7 + 0x13c8) = param_6;
    *(undefined1 *)(*(int *)(iVar1 + 0xc9358) + iVar7 + 0x13fa) = param_7;
    iVar2 = func_0x001ae3e0(param_2);
    iVar3 = func_0x001ae3e0(param_3);
    iVar4 = func_0x001ae3e0(param_2);
    if (iVar2 + 1 + iVar3 < 0x32) {
      func_0x00109eb8(iVar7 + *(int *)(iVar1 + 0xc9358) * 0x42 + 0x672,param_3);
      FUN_005f4e40();
    }
    else {
      iVar2 = 0;
      do {
        uVar6 = func_0x001af430(param_3,auStack_4);
        iVar3 = (int)uVar6;
        if (-(iVar4 + 1) + 0x30 <= iVar2 + iVar3) break;
        func_0x0010a4f0(auStack_50 + iVar2,param_3,uVar6);
        iVar2 = iVar2 + iVar3;
        param_3 = param_3 + iVar3;
      } while (iVar2 < -(iVar4 + 1) + 0x31);
      auStack_50[iVar2] = 0;
      func_0x00109eb8(iVar7 + *(int *)(iVar1 + 0xc9358) * 0x42 + 0x672,auStack_50);
      FUN_005f4e40();
      *(undefined1 *)(*(int *)(iVar1 + 0xc9358) * 0x11 + iVar7 + 800) = 0;
      func_0x00109eb8(iVar7 + *(int *)(iVar1 + 0xc9358) * 0x42 + 0x672,param_3);
      FUN_005f4e40();
    }
  }
  return;
}



================================================================