FUNCTION FUN_00002540 @ 0x00002540 size=388
CALLERS (1): FUN_000035fc@0x000035fc
CALLEES (6): FUN_00003d40@0x00003d40, FUN_00003ce0@0x00003ce0, FUN_0000007c@0x0000007c, FUN_00003cf0@0x00003cf0, FUN_00003d74@0x00003d74, FUN_00002428@0x00002428

undefined4 FUN_00002540(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (DAT_000045d8 != 0) {
    FUN_00003d40("inetctl: Loading %s\n",param_1);
  }
  DAT_000045e4 = FUN_0000007c(DAT_000045e8);
  if (DAT_000045e4 == 0) {
    pcVar3 = "inetctl: no space for pool (%d)\n";
    iVar1 = DAT_000045e8;
  }
  else {
    PTR_DAT_000045e0 = (undefined *)&DAT_00004758;
    FUN_00003d74(&DAT_00004758,0x870);
    DAT_0000476c = 1;
    DAT_00004758 = 0;
    DAT_00004764 = DAT_000045e4;
    DAT_00004760 = DAT_000045e4;
    DAT_00004768 = DAT_000045e4 + DAT_000045e8;
    DAT_00004778 = DAT_000045d0;
    DAT_0000477c = DAT_000045d4;
    DAT_00004780 = DAT_000045d8;
    DAT_0000475c = param_1;
    iVar1 = FUN_00003ce0(&DAT_00004758);
    pcVar3 = "inetctl: sceNetCnfLoadConf -> %d\n";
    if (iVar1 == 0) {
      iVar1 = FUN_00003cf0(&DAT_00004758);
      if (iVar1 == 0) {
        uVar2 = FUN_00002428();
        if (DAT_000045d8 != 0) {
          FUN_00003d40("inetctl: [%d]",uVar2);
          iVar1 = (DAT_00004764 - DAT_000045e4) * 100;
          if (DAT_000045e8 == 0) {
            trap(0x1c00);
          }
          if ((DAT_000045e8 == -1) && (iVar1 == -0x80000000)) {
            trap(0x1800);
          }
          FUN_00003d40(" used pool = %d/%d (%d%%)\n",DAT_00004764 - DAT_000045e4,DAT_000045e8,
                       iVar1 / DAT_000045e8);
        }
        return 0;
      }
      pcVar3 = "inetctl: sceNetCnfMergeConf -> %d\n";
    }
  }
  FUN_00003d40(pcVar3,iVar1);
  return 0xffffffff;
}


================================================================