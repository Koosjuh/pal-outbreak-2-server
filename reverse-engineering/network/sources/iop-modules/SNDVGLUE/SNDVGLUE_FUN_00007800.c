FUNCTION FUN_00007800 @ 0x00007800 size=116
CALLERS (0): 
CALLEES (2): FUN_0000804c@0x0000804c, FUN_0000810c@0x0000810c

undefined4 FUN_00007800(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000804c(0,param_1,0);
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_000095c0);
    FUN_0000810c("POE_ethAllocBuffer: addr 0x%08x len %d\n",uVar1,param_1);
  }
  return uVar1;
}


================================================================