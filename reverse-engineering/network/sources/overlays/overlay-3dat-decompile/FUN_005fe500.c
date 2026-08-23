FUNCTION FUN_005fe500 @ 0x005fe500  size=288
CALLERS (2): FUN_005f99c0@0x005f99c0, FUN_005fada0@0x005fada0
CALLEES (7): FUN_005c0f60@0x005c0f60, FUN_005c2820@0x005c2820, FUN_005c0a00@0x005c0a00, FUN_005c02b0@0x005c02b0, FUN_005bffa0@0x005bffa0, FUN_005f4b70@0x005f4b70, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_005fe500(void)

{
  undefined1 uVar1;
  
  uRam006c4b9e = 0;
  uRam006c4b9f = 0;
  uRam006c4b90 = 4;
  uRam006c4ba0 = 0;
  uRam006c4ba1 = 0;
  uRam006c4fdc = 0;
  FUN_005f4b70();
  FUN_005aec20(0x6c4b90);
  uVar1 = uRam006c4600;
  uRam006c4fe8 = 0;
  uRam006c4fe6 = 0;
  uRam006c5514 = 0x1e;
  uRam006c550d = 1;
  uRam006c4fe4 = 1;
  uRam006c5510 = 0;
  if (cRam0034363e == '\x01') {
    uRam006c5514 = 0x19;
  }
  uRam006c550f = 0;
  uRam006c5518 = 0x14;
  FUN_005c0a00(uRam006c4600,0x600de0);
  FUN_005bffa0(uVar1,0x600f50);
  FUN_005c0f60(uVar1,0x600ff0);
  FUN_005c2820(uVar1,0x601060);
  FUN_005c02b0(uVar1,0x601170);
  return;
}



================================================================