
void FUN_001cf570(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined1 *)
   (((uint)*(byte *)(param_1 + 3) * 0x208 + (uint)*(byte *)(param_1 + 3)) * 4 + 0x4288f0) = 0;
  if (*(int *)((param_2 & 0xff) * 0x14 + 0x3bfcec) != 0) {
    FUN_001a7b70(0x15,2);
    FUN_001a7b70(1,0x800);
    FUN_001a7b70(0x12,0x8000);
    FUN_001a7b70(0x62,1);
    FUN_001a7b70(0xc,0);
    FUN_001a7b70(0x66,1);
    FUN_001a7b70(2,0);
    FUN_001a7b70(0,0);
    *(undefined1 *)
     (((uint)*(byte *)(param_1 + 3) * 0x208 + (uint)*(byte *)(param_1 + 3)) * 4 + 0x4288f0) = 1;
    iVar1 = ((uint)*(byte *)(param_1 + 3) * 0x208 + (uint)*(byte *)(param_1 + 3)) * 4;
    uVar2 = FUN_001ab460(0x20);
    *(undefined4 *)(iVar1 + 0x4290fc) = uVar2;
    *(undefined4 *)(iVar1 + 0x42910c) = 0;
  }
  return;
}

