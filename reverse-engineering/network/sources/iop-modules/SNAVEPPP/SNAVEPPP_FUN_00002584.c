FUNCTION FUN_00002584 @ 0x00002584 size=460
CALLERS (1): FUN_0000fc50@0x0000fc50
CALLEES (5): FUN_00010b4c@0x00010b4c, FUN_00010b3c@0x00010b3c, FUN_00010c38@0x00010c38, FUN_0000277c@0x0000277c, FUN_00002750@0x00002750

undefined4 FUN_00002584(undefined4 param_1)

{
  undefined *puVar1;
  undefined2 local_18 [4];
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","PP_init_glue");
    FUN_00010c38("called (arg=0x%x).\n",param_1);
  }
  DAT_000131f0 = 1;
  FUN_00002750(&DAT_000131f8);
  FUN_0000277c(&DAT_00013210,1);
  FUN_00010b4c(&DAT_00012fb8,0,0x230);
  DAT_00012fc4 = 0x17;
  DAT_00012fbc = 0;
  DAT_00012fb8 = 0;
  DAT_00012fc0 = 2;
  DAT_000131e8 = 1;
  DAT_000131ec = &DAT_00012fb8;
  DAT_00012fc8 = "AVE-PPP 1.3a Network Driver (Glue version)";
  DAT_00012fcc = FUN_00002fa0;
  DAT_00012fd0 = FUN_0000301c;
  DAT_00012fd4 = FUN_00003084;
  DAT_00012fd8 = FUN_00003194;
  DAT_00012fdc = FUN_0000325c;
  DAT_00012fe0 = FUN_000032f4;
  DAT_00012fe8 = 0;
  DAT_000130e8 = 0;
  DAT_00012fe4 = FUN_00003384;
  DAT_000132d4 = &DAT_00013228;
  FUN_00010b4c(&DAT_00013228,0,0xac);
  FUN_00010b4c(DAT_000132d4,0,0x40);
  local_18[0] = 8;
  puVar1 = DAT_000132d4 + 0x44;
  *(undefined4 *)(DAT_000132d4 + 0x40) = 0;
  FUN_00010b3c(puVar1,&DAT_00011240,6);
  FUN_00010b3c(DAT_000132d4 + 0x4a,&DAT_00011248,6);
  FUN_00010b3c(DAT_000132d4 + 0x50,local_18,2);
  DAT_000131f0 = 2;
  return 0;
}


================================================================