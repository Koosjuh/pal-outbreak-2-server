FUNCTION FUN_00007660 @ 0x00007660 size=564
CALLERS (2): FUN_00005f54@0x00005f54, FUN_000054a8@0x000054a8
CALLEES (10): FUN_00008698@0x00008698, FUN_00008454@0x00008454, FUN_0000876c@0x0000876c, FUN_00007e7c@0x00007e7c, FUN_00007b20@0x00007b20, FUN_00007b80@0x00007b80, FUN_00007ddc@0x00007ddc, FUN_00008270@0x00008270, FUN_00007a90@0x00007a90, FUN_00007fb4@0x00007fb4

int FUN_00007660(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_38;
  undefined *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  DAT_00014b90 = *(undefined4 *)(param_2 + 0x14);
  DAT_00014b94 = *(undefined4 *)(param_2 + 0x18);
  DAT_00014b98 = *(undefined4 *)(param_2 + 0x1c);
  DAT_00014b9c = *(undefined4 *)(param_2 + 0x20);
  DAT_00014ba0 = &DAT_00011e24;
  FUN_00007a90();
  local_38 = param_1;
  do {
    do {
      DAT_00014bb4 = 0;
      DAT_00014bb0 = 0;
      DAT_00014bac = 0;
      DAT_00014ba8 = 0;
      sVar1 = FUN_00007b20(local_38,&DAT_000153c0,&local_38);
      if (sVar1 == 0) {
        FUN_00007a90(&DAT_000153c0);
        return 0;
      }
      local_34 = &DAT_000153c0;
      sVar1 = FUN_00007b80(&DAT_000153c0,&DAT_000155c0,&local_34);
    } while (sVar1 == 0);
    sVar1 = FUN_00007ddc(&DAT_000155c0);
    iVar4 = (int)sVar1;
    if (iVar4 == -1) {
      FUN_00007a90();
      return 4;
    }
    iVar2 = *(int *)(&DAT_00011d10 + iVar4 * 0x14);
    iVar3 = 0;
    local_30 = 0;
    local_2c = 0;
    if (0 < iVar2) {
      do {
        sVar1 = FUN_00007b80(local_34,&DAT_000155c0,&local_34);
        if (sVar1 == 0) break;
        FUN_00007e7c(iVar4,iVar3,&DAT_000155c0,&local_30,&local_2c);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    switch(iVar4) {
    case 0:
      iVar4 = FUN_00007fb4(*(undefined4 *)(param_2 + 4));
      iVar4 = iVar4 << 0x10;
      break;
    case 1:
      iVar4 = FUN_00008270();
      iVar4 = iVar4 << 0x10;
      break;
    case 2:
      iVar4 = FUN_00008454(*(undefined4 *)(param_2 + 4));
      iVar4 = iVar4 << 0x10;
      break;
    case 3:
      iVar4 = FUN_00008698(*(undefined4 *)(param_2 + 4));
      iVar4 = iVar4 << 0x10;
      break;
    case 4:
      iVar4 = FUN_0000876c();
      iVar4 = iVar4 << 0x10;
      break;
    default:
      iVar4 = 0x40000;
    }
    if (iVar4 >> 0x10 != 0) {
      FUN_00007a90();
      return iVar4 >> 0x10;
    }
  } while( true );
}


================================================================