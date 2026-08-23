FUNCTION FUN_005effc0 @ 0x005effc0  size=172
CALLERS (1): FUN_005eb250@0x005eb250
CALLEES (0): 
----------------------------------------------------------------

void FUN_005effc0(int param_1,int param_2)

{
  char cVar1;
  
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    *(undefined1 *)(param_1 + 0x4c) = *(undefined1 *)(param_2 + 0x4c);
    cVar1 = *(char *)(param_2 + 0x4d);
    *(char *)(param_2 + 0x4d) = cVar1 + '\x01';
    *(char *)(param_1 + 0x4d) = cVar1;
    *(undefined1 *)(param_1 + 0x45) = *(undefined1 *)(param_2 + 0x45);
    *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 0x32);
    *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(param_2 + 0x30);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iRam007012a0 + 0xf18);
    *(undefined1 *)(param_1 + 0x4a) = *(undefined1 *)(iRam007012a0 + 0xf16);
    *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(iRam007012a0 + 0xf17);
    *(undefined1 *)(param_1 + 0x46) = *(undefined1 *)(param_2 + 0x46);
    *(undefined1 *)(param_1 + 0x44) = 0;
    *(undefined2 *)(param_1 + 0x20) = 0;
    *(ushort *)(param_1 + 0x1c) =
         *(short *)(param_2 + 0x1c) +
         ((ushort)*(byte *)(param_1 + 0x45) + *(short *)(param_1 + 0x32)) * -2;
  }
  return;
}



================================================================