FUNCTION FUN_00017d38 @ 0x00017d38 size=96
CALLERS (1): FUN_00011fb8@0x00011fb8
CALLEES (3): FUN_0000d508@0x0000d508, FUN_0000ae24@0x0000ae24, FUN_00019a50@0x00019a50

void FUN_00017d38(void)

{
  if (DAT_0001e418 != 0) {
    FUN_00019a50(FUN_000175ac,&DAT_0001e410);
    DAT_0001e418 = 0;
  }
  FUN_0000d508(&DAT_0001e410,1);
  FUN_0000ae24(&DAT_0001e410,0x20);
  return;
}


================================================================