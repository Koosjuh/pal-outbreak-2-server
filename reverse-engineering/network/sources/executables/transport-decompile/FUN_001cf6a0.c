
void FUN_001cf6a0(uint param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xff) * 0x824;
  *(undefined1 *)(iVar2 + 0x426860) = 0;
  if (*(int *)((uint)param_2 * 0x14 + 0x3bfd8c) != 0) {
    FUN_001a7b70(0x15,2);
    FUN_001a7b70(1,0x800);
    FUN_001a7b70(0x12,0x8000);
    FUN_001a7b70(0x62,1);
    FUN_001a7b70(0xc,0);
    FUN_001a7b70(0x66,1);
    FUN_001a7b70(2,0);
    FUN_001a7b70(0,0);
    *(undefined1 *)(iVar2 + 0x426860) = 1;
    uVar1 = FUN_001ab460(0x20,3);
    *(undefined4 *)(iVar2 + 0x42706c) = uVar1;
    *(undefined4 *)(iVar2 + 0x42707c) = 0;
    FUN_001cd010(param_2,0xffffffffffffffff,iVar2 + 0x426864,3);
  }
  return;
}

