FUNCTION FUN_00002050 @ 0x00002050 size=116
CALLERS (1): FUN_00005f54@0x00005f54
CALLEES (3): FUN_0000a720@0x0000a720, FUN_00000664@0x00000664, FUN_00010c38@0x00010c38

undefined4 FUN_00002050(void)

{
  FUN_0000a720(&DAT_000149fc);
  FUN_0000a720(&DAT_000149c8);
  FUN_0000a720(&DAT_00014a30);
  FUN_0000a720(&DAT_00014994);
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PPP: phase ==> Link Dead\n");
  }
  DAT_00014990 = 0;
  FUN_00000664();
  return 0;
}


================================================================