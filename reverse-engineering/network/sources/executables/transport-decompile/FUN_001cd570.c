
uint FUN_001cd570(void)

{
  char *pcVar1;
  uint uVar2;
  long lVar3;
  undefined1 extraout_a3_lo;
  undefined8 extraout_a3;
  ulong extraout_t0;
  undefined8 extraout_t1;
  undefined1 *puVar4;
  
  lVar3 = FUN_001cd500();
  if (lVar3 == 0) {
    lVar3 = FUN_001cd470(extraout_a3);
    if (lVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      puVar4 = (undefined1 *)lVar3;
      *(short *)(puVar4 + 0x12) = (short)extraout_t0;
      *puVar4 = 1;
      puVar4[0xf] = extraout_a3_lo;
      puVar4[0x10] = (char)extraout_t1;
      FUN_001cd820(extraout_t1,extraout_t0 & 0x7fff,puVar4 + 2);
      uVar2 = (uint)(byte)puVar4[0xe];
    }
  }
  else {
    pcVar1 = (char *)lVar3;
    pcVar1[0xf] = (byte)extraout_a3 | pcVar1[0xf] & ~(byte)extraout_a3;
    *pcVar1 = *pcVar1 + '\x01';
    uVar2 = (uint)(byte)pcVar1[0xe];
  }
  return uVar2;
}

