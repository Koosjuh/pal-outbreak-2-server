FUNCTION FUN_0000f280 @ 0x0000f280 size=132
CALLERS (0): 
CALLEES (3): FUN_000199c4@0x000199c4, FUN_0000a9c0@0x0000a9c0, FUN_0000bd30@0x0000bd30

undefined4 FUN_0000f280(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_30 [24];
  undefined4 local_18 [2];
  
  FUN_0000a9c0(param_3 + 4,local_18,4);
  FUN_0000bd30(auStack_30,local_18[0]);
  iVar1 = FUN_000199c4(auStack_30);
  if (iVar1 + 1 <= param_2) {
    FUN_0000a9c0(auStack_30,param_1);
  }
  return 0;
}


================================================================