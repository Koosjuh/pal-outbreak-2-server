FUNCTION FUN_00000af4 @ 0x00000af4 size=124
CALLERS (1): FUN_000002ec@0x000002ec
CALLEES (5): FUN_0000286c@0x0000286c, FUN_000027d4@0x000027d4, FUN_000027dc@0x000027dc, FUN_00002864@0x00002864, FUN_000027b0@0x000027b0

void FUN_00000af4(void)

{
  undefined4 local_10 [2];
  
  if (DAT_00003430 != 0) {
    FUN_000027d4(local_10);
    FUN_000027b0(DAT_00003430);
    FUN_000027dc(local_10[0]);
    DAT_00003434 = 0;
    DAT_00003430 = 0;
  }
  FUN_00002864(&DAT_00006100,&DAT_00006148);
  FUN_0000286c(&DAT_00006148);
  return;
}


================================================================