FUNCTION FUN_00002758 @ 0x00002758 size=556
CALLERS (0): 
CALLEES (18): FUN_00002a28@0x00002a28, FUN_00002720@0x00002720, FUN_00002b84@0x00002b84, FUN_00002a40@0x00002a40, FUN_00002bd0@0x00002bd0, FUN_00002bfc@0x00002bfc, FUN_00002bf4@0x00002bf4, FUN_00002b20@0x00002b20, FUN_00002bc8@0x00002bc8, FUN_00002a04@0x00002a04, FUN_00002a50@0x00002a50, FUN_000020e0@0x000020e0, FUN_000029f4@0x000029f4, FUN_00001f60@0x00001f60, FUN_000029dc@0x000029dc, FUN_00002a58@0x00002a58, FUN_00002b50@0x00002b50, FUN_00002b30@0x00002b30

uint FUN_00002758(int param_1,undefined4 param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined1 auStack_70 [56];
  ushort local_38;
  
  if (param_1 < 0) {
    if (((DAT_000032c8 == 0) && (DAT_000032cc == 0)) || (DAT_000032d0 != 0)) {
      FUN_000029dc(&DAT_000033dc);
      FUN_00002b30(DAT_000032c4);
      FUN_00002b20(DAT_000032c4);
      FUN_00002b84(DAT_000032c0);
      if (DAT_000032bc != 0) {
        FUN_00002a04(&DAT_000033dc);
      }
      if (DAT_000032d4 != 0) {
        FUN_00002b50(FUN_00001210,&DAT_000032a0);
      }
      iVar3 = 2;
      FUN_00002bfc(&DAT_00002990);
      FUN_00002a50(1,0);
      FUN_00002a58(1,0);
      do {
        FUN_00002a28(iVar3,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 7);
      FUN_00002a40(0x68);
      uVar1 = 1;
      *DAT_000032a4 = 0;
    }
    else {
      FUN_000029f4("smap: can\'t unload (busy)\n");
      uVar1 = 2;
    }
  }
  else {
    DAT_000032d8 = 0xffffffff;
    iVar3 = FUN_00002bf4(&DAT_00002990);
    if (iVar3 == 0) {
      FUN_00001f60();
      iVar3 = FUN_00002bd0(&DAT_00003268);
      pcVar2 = "smap: dev9 module not found\n";
      if (-1 < iVar3) {
        iVar3 = FUN_00002bc8(iVar3,auStack_70);
        if (iVar3 < 0) {
          pcVar2 = "smap: can\'t get dev9 module status\n";
        }
        else {
          if (0x203 < local_38) {
            iVar3 = FUN_000020e0(param_1,param_2);
            if (-1 < iVar3) {
              iVar3 = FUN_00002720();
              return (uint)(iVar3 != 0) << 1;
            }
            FUN_000029f4("smap: smap_init -> %d\n",iVar3);
            FUN_00002bfc(&DAT_00002990);
            return iVar3 << 2 | 1;
          }
          pcVar2 = "smap: dev9 module version must be 2.4 or later\n";
        }
      }
    }
    else {
      pcVar2 = "smap: module already loaded\n";
    }
    FUN_000029f4(pcVar2);
    uVar1 = 1;
  }
  return uVar1;
}


================================================================