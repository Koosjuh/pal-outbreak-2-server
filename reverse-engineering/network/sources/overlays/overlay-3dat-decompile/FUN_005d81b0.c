FUNCTION FUN_005d81b0 @ 0x005d81b0  size=400
CALLERS (1): FUN_005d8340@0x005d8340
CALLEES (1): FUN_005de330@0x005de330
----------------------------------------------------------------

void FUN_005d81b0(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  
  func_0x00106b60(param_1,0);
  func_0x00109eb8(param_1,PTR_s_<html><head><title>_00643360);
  iVar1 = func_0x0010a050(PTR_s_<html><head><title>_00643360);
  iVar1 = (int)param_1 + iVar1;
  uVar5 = FUN_005de330(9,2);
  func_0x00109eb8(iVar1,uVar5);
  uVar5 = FUN_005de330(9,2);
  iVar2 = func_0x0010a050(uVar5);
  iVar1 = iVar1 + iVar2;
  func_0x00109eb8(iVar1,PTR_s_<_title><_head><body><h2>_00643364);
  iVar2 = func_0x0010a050(PTR_s_<_title><_head><body><h2>_00643364);
  iVar1 = iVar1 + iVar2;
  uVar5 = FUN_005de330(9,3);
  func_0x00109eb8(iVar1,uVar5);
  uVar5 = FUN_005de330(9,3);
  iVar2 = func_0x0010a050(uVar5);
  iVar1 = iVar1 + iVar2;
  func_0x00109eb8(iVar1,PTR_s_<_h2><hr>_00643368);
  iVar2 = func_0x0010a050(PTR_s_<_h2><hr>_00643368);
  iVar1 = iVar1 + iVar2;
  iVar2 = 0;
  while( true ) {
    piVar6 = (int *)(param_2 + iVar2 * 4);
    if (*piVar6 == 0) break;
    func_0x00109eb8(iVar1);
    iVar3 = func_0x0010a050(*piVar6);
    func_0x00109eb8(iVar1 + iVar3,PTR_DAT_0064336c);
    iVar4 = func_0x0010a050(PTR_DAT_0064336c);
    iVar1 = iVar1 + iVar3 + iVar4;
    iVar2 = iVar2 + 1;
  }
  func_0x00109eb8(iVar1,PTR_DAT_00643370);
  iVar2 = func_0x0010a050(PTR_DAT_00643370);
  func_0x00109eb8(iVar1 + iVar2,PTR_s_<_body><_html>_00643374);
  func_0x0010a050(PTR_s_<_body><_html>_00643374);
  return;
}



================================================================