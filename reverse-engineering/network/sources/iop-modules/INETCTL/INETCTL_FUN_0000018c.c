FUNCTION FUN_0000018c @ 0x0000018c size=164
CALLERS (17): FUN_0000203c@0x0000203c, FUN_00002c3c@0x00002c3c, FUN_00001688@0x00001688, FUN_000003b0@0x000003b0, FUN_00000530@0x00000530, FUN_0000059c@0x0000059c, FUN_00000a4c@0x00000a4c, FUN_00001c6c@0x00001c6c, FUN_00000360@0x00000360, FUN_00000290@0x00000290, FUN_00001894@0x00001894, FUN_00001b80@0x00001b80, FUN_00000230@0x00000230, FUN_000002f0@0x000002f0, FUN_00000328@0x00000328, FUN_00000400@0x00000400, FUN_0000043c@0x0000043c
CALLEES (3): FUN_00003d40@0x00003d40, FUN_00003df0@0x00003df0, FUN_00003c7c@0x00003c7c

undefined4 FUN_0000018c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_00003c7c(param_1,param_2,param_3,param_4);
    if (-1 < iVar1) {
      return 0;
    }
    if (iVar1 != -0x1f6) break;
    FUN_00003df0(100000);
  }
  FUN_00003d40("inetctl: sceInetInterfaceControl(0x%x,0x%x,0x%p,%d) -> %d\n",param_1,param_2,param_3
               ,param_4,iVar1);
  return 0xffffffff;
}


================================================================