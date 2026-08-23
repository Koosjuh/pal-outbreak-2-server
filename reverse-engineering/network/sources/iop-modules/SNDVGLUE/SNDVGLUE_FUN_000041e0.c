FUNCTION FUN_000041e0 @ 0x000041e0 size=84
CALLERS (0): 
CALLEES (2): FUN_00008098@0x00008098, FUN_0000810c@0x0000810c

void FUN_000041e0(undefined4 param_1,undefined4 param_2)

{
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("sceInetFreeMem(%08x)\n",param_2);
  }
  FUN_00008098(param_2);
  return;
}


================================================================