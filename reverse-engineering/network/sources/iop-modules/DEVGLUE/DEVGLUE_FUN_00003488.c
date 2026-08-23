FUNCTION FUN_00003488 @ 0x00003488 size=352
CALLERS (1): FUN_00002c30@0x00002c30
CALLEES (7): FUN_000035f4@0x000035f4, FUN_00008140@0x00008140, FUN_00004efc@0x00004efc, FUN_00004e7c@0x00004e7c, FUN_000035e8@0x000035e8, FUN_00008158@0x00008158, FUN_0000810c@0x0000810c

undefined4 FUN_00003488(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("called NDI_init()\n");
  }
  iVar1 = FUN_00004e7c(DAT_0000970c,&local_18);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    iVar1 = FUN_00004efc(DAT_0000970c,&local_14);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      DAT_0000dbc8 = 1;
      FUN_000035e8(&DAT_0000ddfc);
      FUN_000035f4(&DAT_0000de10);
      FUN_00008140(&DAT_0000dbcc,0,0x230);
      DAT_0000dbdc = "devglue";
      FUN_00008158(&DAT_0000dbfc,local_18,0x100);
      DAT_0000dcfb = 0;
      FUN_00008158(&DAT_0000dcfc,local_14,0x100);
      DAT_0000ddfb = 0;
      DAT_0000dbd0 = 0;
      DAT_0000dbcc = 0;
      DAT_0000dbe0 = FUN_00003a9c;
      DAT_0000dbe4 = FUN_00003b2c;
      DAT_0000dbe8 = FUN_00003bc4;
      DAT_0000dbec = FUN_00003c90;
      DAT_0000dbf0 = FUN_00003d48;
      DAT_0000dbf4 = FUN_00003dd8;
      DAT_0000dbf8 = FUN_00003e68;
      DAT_0000dbd4 = 0;
      DAT_0000dbd8 = 0;
      DAT_0000dbc8 = 2;
      DAT_0000de80 = 0;
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================