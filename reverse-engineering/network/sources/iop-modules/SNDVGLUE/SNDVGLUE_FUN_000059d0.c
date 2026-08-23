FUNCTION FUN_000059d0 @ 0x000059d0 size=464
CALLERS (3): FUN_00000b04@0x00000b04, FUN_00000d2c@0x00000d2c, FUN_00000c58@0x00000c58
CALLEES (7): FUN_00005d14@0x00005d14, FUN_0000678c@0x0000678c, FUN_0000803c@0x0000803c, FUN_00007a20@0x00007a20, FUN_00008044@0x00008044, FUN_00006dd8@0x00006dd8, FUN_00007874@0x00007874

int FUN_000059d0(int param_1,ushort param_2,ushort *param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int local_28;
  undefined2 local_24;
  short local_22;
  ushort local_20 [4];
  
  FUN_00006dd8();
  sVar1 = FUN_00007874(&local_28,&local_24);
  if (sVar1 == 0) {
    if (param_3 == (ushort *)0x0) {
      return 0;
    }
    *param_3 = 0;
    return 0;
  }
  FUN_00008044(&local_22,local_28 + 0xc,2);
  if ((local_22 == 0x6388) || (iVar4 = 0, local_22 == 0x6488)) {
    iVar2 = FUN_0000803c(local_28,&DAT_0000eca8,6);
    iVar4 = 0;
    if ((iVar2 == 0) && (*(char *)(local_28 + 0xe) == '\x11')) {
      if (local_22 == 0x6388) {
        iVar4 = FUN_0000678c(local_28,local_24);
      }
      else {
        FUN_00008044(local_20,local_28 + 0x12,2);
        iVar4 = 0;
        local_20[0] = local_20[0] << 8 | local_20[0] >> 8;
        iVar2 = local_28 + 0x14;
        if ((((param_1 != 0) && (local_20[0] <= param_2)) &&
            (psVar3 = (short *)FUN_00005d14(local_28,local_24), psVar3 != (short *)0x0)) &&
           (*psVar3 == 4)) {
          FUN_00008044(param_1,iVar2,local_20[0]);
          if (param_3 != (ushort *)0x0) {
            *param_3 = local_20[0];
          }
          FUN_00007a20(local_28);
          iVar4 = ((int)(psVar3 + -0x6f48) * 0x265b7d4d >> 2) << 0x10;
          goto LAB_00005b7c;
        }
      }
    }
  }
  FUN_00007a20(local_28);
  iVar4 = iVar4 << 0x10;
  if (param_3 != (ushort *)0x0) {
    *param_3 = 0;
  }
LAB_00005b7c:
  return iVar4 >> 0x10;
}


================================================================