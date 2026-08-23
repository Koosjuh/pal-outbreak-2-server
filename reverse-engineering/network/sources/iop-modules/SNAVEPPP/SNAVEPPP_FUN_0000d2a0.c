FUNCTION FUN_0000d2a0 @ 0x0000d2a0 size=248
CALLERS (0): 
CALLEES (1): FUN_00010ae4@0x00010ae4

void FUN_0000d2a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  puVar5 = *(ushort **)(param_1 + 0x30);
  if ((puVar5[2] & 0x20) != 0) {
    uVar1 = FUN_00010ae4();
    uVar2 = FUN_00010ae4();
    uVar3 = FUN_00010ae4();
    iVar4 = FUN_00010ae4();
    *(uint *)(puVar5 + 8) =
         *(int *)(puVar5 + 8) +
         (uVar1 >> 0x18 | uVar2 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | iVar4 << 0x18);
  }
  *(undefined4 *)(puVar5 + 0xe) = *(undefined4 *)(puVar5 + 2);
  *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)(puVar5 + 4);
  *(undefined4 *)(puVar5 + 0x12) = *(undefined4 *)(puVar5 + 6);
  *(undefined4 *)(puVar5 + 0x14) = *(undefined4 *)(puVar5 + 8);
  *(undefined4 *)(puVar5 + 0x16) = *(undefined4 *)(puVar5 + 10);
  *(undefined4 *)(puVar5 + 0x18) = *(undefined4 *)(puVar5 + 0xc);
  puVar5[0x28] = 0;
  *puVar5 = *puVar5 | puVar5[2];
  puVar5[0x1a] = puVar5[0x1a] | puVar5[0x1c];
  return;
}


================================================================