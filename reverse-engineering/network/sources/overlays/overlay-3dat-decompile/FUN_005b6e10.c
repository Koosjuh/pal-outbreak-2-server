FUNCTION FUN_005b6e10 @ 0x005b6e10  size=136
CALLERS (0): 
CALLEES (2): FUN_0062fe70@0x0062fe70, FUN_005b7de0@0x005b7de0
----------------------------------------------------------------

void FUN_005b6e10(undefined1 param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if (cRam006c4fe4 != '\0') {
    iVar1 = FUN_0062fe70(param_1);
    iVar2 = (param_2 & 0xff) * 8;
    FUN_005b7de0(*(undefined4 *)(&DAT_00638e90 + iVar2),*(undefined4 *)(&DAT_00638e94 + iVar2),0,0,0
                 ,*(undefined4 *)(iVar1 + (param_3 & 0xff) * 4));
  }
  return;
}



================================================================