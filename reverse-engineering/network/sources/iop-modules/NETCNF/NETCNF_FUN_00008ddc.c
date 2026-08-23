FUNCTION FUN_00008ddc @ 0x00008ddc size=332
CALLERS (7): FUN_000020f4@0x000020f4, FUN_00007974@0x00007974, FUN_000018b0@0x000018b0, FUN_00001198@0x00001198, FUN_00000da8@0x00000da8, FUN_000027e4@0x000027e4, FUN_00000fe4@0x00000fe4
CALLEES (5): FUN_00008b6c@0x00008b6c, FUN_00008d3c@0x00008d3c, FUN_00009684@0x00009684, FUN_00008bfc@0x00008bfc, FUN_00009640@0x00009640

int FUN_00008ddc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_30 [16];
  undefined4 local_20 [2];
  
  if ((DAT_0000c214 == FUN_00000000) || (iVar1 = FUN_00008b6c(), iVar1 == 0)) {
    iVar1 = FUN_00009684(param_1,param_2,param_3);
  }
  else {
    iVar1 = -1;
    if (DAT_0000c6b0 < 4) {
      iVar2 = FUN_00008d3c(param_1,auStack_30);
      if (iVar2 == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = (*DAT_0000c214)(auStack_30,iVar2,param_2,param_3,local_20);
        if (-1 < iVar1) {
          iVar3 = FUN_00008bfc(iVar1,1);
          iVar4 = iVar3 * 0x124;
          FUN_00009640(iVar4 + 0xc224,auStack_30);
          FUN_00009640(iVar4 + 0xc234,iVar2);
          *(undefined4 *)(&DAT_0000c334 + iVar4) = 0;
          *(undefined4 *)(&DAT_0000c33c + iVar4) = 0;
          (&DAT_0000c338)[iVar3 * 0x49] = local_20[0];
        }
      }
    }
  }
  return iVar1;
}


================================================================