FUNCTION FUN_0000e750 @ 0x0000e750 size=156
CALLERS (1): FUN_00003f40@0x00003f40
CALLEES (2): FUN_00011d48@0x00011d48, FUN_000042b8@0x000042b8

undefined4 FUN_0000e750(short param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  DAT_00016ed4 = &DAT_000168e8;
  puVar1 = (undefined1 *)FUN_000042b8((int)param_1);
  if (puVar1 == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    *puVar1 = 1;
    *(undefined2 *)(puVar1 + 2) = 0x5dc;
    *(undefined4 *)(puVar1 + 8) = 0xffffffff;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined2 *)(puVar1 + 0x14) = 1;
    puVar1[0x16] = 6;
    FUN_00011d48(puVar1 + 0x1e,0xff,6);
    uVar2 = 0;
    puVar1[1] = 1;
  }
  return uVar2;
}


================================================================