FUNCTION FUN_005dbf00 @ 0x005dbf00  size=164
CALLERS (1): FUN_005cd320@0x005cd320
CALLEES (1): FUN_005dfde0@0x005dfde0
----------------------------------------------------------------

void FUN_005dbf00(int param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  if (param_1 == 1) {
    lVar2 = FUN_005dfde0(3,0);
    puVar1 = (undefined1 *)lVar2;
    if (lVar2 != 0) {
      puVar1[1] = 1;
      *puVar1 = 1;
      *(undefined1 **)(puVar1 + 0x14) = &LAB_005dbfb0;
      *(code **)(puVar1 + 0x18) = FUN_005dc010;
      *(undefined4 *)(puVar1 + 0x34) = 0x43480000;
      *(undefined4 *)(puVar1 + 0x38) = 0x43160000;
      *(undefined4 *)(puVar1 + 0x4c) = 0;
      *(undefined4 *)(puVar1 + 0x50) = 0;
      *(undefined4 *)(puVar1 + 0x40) = 0x43480000;
      *(undefined4 *)(puVar1 + 0x44) = 0x43160000;
      puVar1[6] = 0;
      puVar1[7] = 0;
      *(undefined2 *)(puVar1 + 10) = 0;
      *(undefined2 *)(puVar1 + 0xc) = 0;
      *(undefined2 *)(puVar1 + 0xe) = 0;
      *(undefined2 *)(puVar1 + 0x10) = 0;
      *(undefined1 *)(iRam00701068 + 0x68e83) = 0;
    }
  }
  return;
}



================================================================