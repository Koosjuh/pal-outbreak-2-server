
ulong FUN_001e2928(undefined4 param_1)

{
  long lVar1;
  undefined1 auStack_c0 [128];
  undefined4 uStack_40;
  ulong uStack_38;
  long lStack_30;
  long lStack_28;
  
  FUN_00109eb8(auStack_c0,param_1);
  uStack_40 = FUN_0010b6f0(auStack_c0,0x25b7b0);
  uStack_38 = FUN_00102678(uStack_40);
  uStack_40 = FUN_0010b6f0(0,0x25b7b0);
  lStack_30 = FUN_00102678(uStack_40);
  uStack_40 = FUN_0010b6f0(0,0x25b7b0);
  lStack_28 = FUN_00102678(uStack_40);
  uStack_40 = FUN_0010b6f0(0,0x25b7b0);
  lVar1 = FUN_00102678(uStack_40);
  return lStack_30 << 8 | uStack_38 | lStack_28 << 0x10 | lVar1 << 0x18;
}

