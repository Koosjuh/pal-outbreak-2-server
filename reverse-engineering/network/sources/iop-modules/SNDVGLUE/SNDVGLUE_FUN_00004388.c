FUNCTION FUN_00004388 @ 0x00004388 size=64
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00004388(void)

{
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("sceInetRand()\n");
  }
  return 1;
}


================================================================