FUNCTION FUN_00004170 @ 0x00004170 size=112
CALLERS (0): 
CALLEES (2): FUN_00008090@0x00008090, FUN_0000810c@0x0000810c

undefined4 FUN_00004170(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00008090(0,param_2,0);
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("sceInetAllocMem(size = %d) ==> %08x\n",param_2,uVar1);
  }
  return uVar1;
}


================================================================