FUNCTION FUN_0000a1d0 @ 0x0000a1d0 size=148
CALLERS (1): FUN_00007000@0x00007000
CALLEES (1): FUN_00010bc0@0x00010bc0

undefined4 FUN_0000a1d0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xc4);
  while (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0xc4) = 0;
    FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0xd4),0,
                 (int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8)) *
                      0x10000) >> 0x10);
    cVar1 = *(char *)(param_1 + 0xc4);
  }
  return 0;
}


================================================================