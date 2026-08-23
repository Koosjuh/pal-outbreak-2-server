FUNCTION FUN_005b5520 @ 0x005b5520  size=360
CALLERS (0): 
CALLEES (2): FUN_00604860@0x00604860, FUN_005c3e80@0x005c3e80
----------------------------------------------------------------

void FUN_005b5520(void)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_b0 [16];
  undefined1 auStack_a0 [20];
  undefined1 auStack_8c [140];
  
  func_0x00106b60(auStack_b0,0,0xa4);
  FUN_005c3e80(auStack_b0,auStack_a0,auStack_8c);
  lVar1 = FUN_00604860(0x870880,0x1e,auStack_a0);
  iVar6 = 6;
  if (lVar1 == -1) {
    iVar5 = 7;
    do {
      puVar4 = (undefined1 *)(iVar6 * 0xa5 + 0x6c5562);
      puVar3 = (undefined1 *)(iVar5 * 0xa5 + 0x6c5562);
      iVar2 = 0xa5;
      do {
        iVar2 = iVar2 + -1;
        *puVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      } while (0 < iVar2);
      iVar5 = iVar5 + -1;
      iVar6 = iVar6 + -1;
    } while (0 < iVar5);
    func_0x0010a4f0(0x6c5563,auStack_b0,0x10);
    func_0x0010a4f0(0x6c5573,auStack_a0,0x10);
    func_0x0010a4f0(0x6c5587,auStack_8c,0x80);
    uRam006c5560 = 0xe0;
    uRam006c5562 = 1;
    uRam006c555f = 1;
    uRam006c5561 = 1;
    bRam006c555e = bRam006c555e + 1;
    if (8 < bRam006c555e) {
      bRam006c555e = 8;
    }
    func_0x001b0140(3);
  }
  return;
}



================================================================