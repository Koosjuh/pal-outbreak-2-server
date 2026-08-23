FUNCTION FUN_005db130 @ 0x005db130  size=228
CALLERS (1): FUN_005cd320@0x005cd320
CALLEES (1): FUN_005dfde0@0x005dfde0
----------------------------------------------------------------

void FUN_005db130(int param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  if (param_1 == 1) {
    lVar2 = FUN_005dfde0(2,0);
    puVar1 = (undefined1 *)lVar2;
    if (lVar2 != 0) {
      puVar1[1] = 1;
      *puVar1 = 1;
      *(undefined1 **)(puVar1 + 0x14) = &LAB_005db220;
      *(code **)(puVar1 + 0x18) = FUN_005db300;
      *(float *)(puVar1 + 0x34) = (float)(0x270 - *(short *)(iRam00701070 + 0x20));
      *(float *)(puVar1 + 0x38) = (float)(int)*(short *)(iRam00701070 + 0x1a);
      *(undefined4 *)(puVar1 + 0x4c) = 0;
      *(undefined4 *)(puVar1 + 0x50) = 0;
      *(undefined4 *)(puVar1 + 0x40) = 0x41800000;
      *(undefined4 *)(puVar1 + 0x44) = 0x43be0000;
      puVar1[6] = 0;
      puVar1[7] = 0;
      *(undefined2 *)(puVar1 + 10) = 0;
      *(undefined2 *)(puVar1 + 0xc) = 0;
      *(undefined2 *)(puVar1 + 0xe) = 0;
      *(undefined2 *)(puVar1 + 0x10) = 0;
      puVar1[0x30] = 0;
      *(undefined1 *)(iRam00701068 + 0x68e80) = 2;
    }
  }
  return;
}



================================================================