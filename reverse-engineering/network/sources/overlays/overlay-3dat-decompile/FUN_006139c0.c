FUNCTION FUN_006139c0 @ 0x006139c0  size=216
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (4): FUN_0060f8b0@0x0060f8b0, FUN_006146e0@0x006146e0, FUN_00614870@0x00614870, FUN_00614720@0x00614720
----------------------------------------------------------------

void FUN_006139c0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long extraout_a0;
  undefined8 extraout_t0;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  iVar1 = FUN_0060f8b0();
  if (extraout_a0 == 0) {
    FUN_00614720(0xffffffff80000080);
    func_0x00109eb8(auStack_100,*(undefined4 *)(iVar1 + 0x28));
    func_0x00109728(auStack_200,0x654148,param_2 + 1,auStack_100);
    FUN_006146e0(param_3,param_4,auStack_200);
    FUN_00614720(0xffffffff80808080);
  }
  else {
    FUN_00614870(auStack_100,extraout_a0,extraout_t0);
    func_0x00109728(auStack_200,0x654148,param_2 + 1,auStack_100);
    FUN_006146e0(param_3,param_4,auStack_200);
  }
  return;
}



================================================================