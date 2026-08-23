FUNCTION FUN_00000944 @ 0x00000944 size=160
CALLERS (1): FUN_00007658@0x00007658
CALLEES (3): FUN_00009650@0x00009650, FUN_00007da0@0x00007da0, FUN_00009610@0x00009610

undefined4 FUN_00000944(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_38 [24];
  undefined4 local_20 [2];
  
  uVar2 = 0xffffffff;
  if (*param_3 == 0) {
    FUN_00009610(param_3 + 1,local_20,4);
    FUN_00007da0(auStack_38,local_20[0]);
    iVar1 = FUN_00009650(auStack_38);
    if (iVar1 + 1 <= param_2) {
      FUN_00009610(auStack_38,param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================