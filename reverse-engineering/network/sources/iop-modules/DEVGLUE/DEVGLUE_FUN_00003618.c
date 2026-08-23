FUNCTION FUN_00003618 @ 0x00003618 size=148
CALLERS (1): FUN_00002c54@0x00002c54
CALLEES (4): FUN_0000818c@0x0000818c, FUN_000035e8@0x000035e8, FUN_000081a4@0x000081a4, FUN_0000810c@0x0000810c

undefined4 FUN_00003618(void)

{
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("called NDI_disp()\n");
  }
  DAT_0000dbc8 = 1;
  FUN_000035e8(&DAT_0000ddfc);
  if (DAT_0000de80 != 0) {
    FUN_000081a4(DAT_0000de84);
    FUN_0000818c(DAT_0000de84);
    DAT_0000de80 = 0;
  }
  return 0;
}


================================================================