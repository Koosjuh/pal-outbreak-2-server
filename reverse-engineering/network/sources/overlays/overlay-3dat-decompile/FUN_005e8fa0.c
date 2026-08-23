FUNCTION FUN_005e8fa0 @ 0x005e8fa0  size=484
CALLERS (0): 
CALLEES (1): FUN_005ec1b0@0x005ec1b0
----------------------------------------------------------------

undefined8 FUN_005e8fa0(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  byte abStack_110 [272];
  
  FUN_005ec1b0(param_1,abStack_110,0x100);
  iVar3 = 0;
  sVar4 = 0;
  while( true ) {
    bVar1 = abStack_110[iVar3];
    uVar5 = (ushort)bVar1;
    if ((uVar5 == 0) || (uVar5 == 0x2c)) break;
    if ((0x2f < bVar1) && (bVar1 < 0x3a)) {
      sVar6 = sVar4 + (uVar5 - 0x30);
      sVar4 = sVar6 * 10;
      *(short *)(iRam007012a0 + 0x1538) = sVar6;
    }
    iVar3 = iVar3 + 1;
  }
  if (uVar5 != 0) {
    sVar4 = 0;
    while( true ) {
      iVar2 = iVar3 + 1;
      bVar1 = abStack_110[iVar3 + 1];
      uVar5 = (ushort)bVar1;
      if ((uVar5 == 0) || (uVar5 == 0x2c)) break;
      iVar3 = iVar2;
      if ((0x2f < bVar1) && (bVar1 < 0x3a)) {
        sVar6 = sVar4 + (uVar5 - 0x30);
        sVar4 = sVar6 * 10;
        *(short *)(iRam007012a0 + 0x153a) = sVar6;
      }
    }
    if (uVar5 != 0) {
      iVar3 = iVar3 + 2;
      sVar4 = 0;
      while( true ) {
        bVar1 = abStack_110[iVar3];
        uVar5 = (ushort)bVar1;
        if ((uVar5 == 0) || (uVar5 == 0x2c)) break;
        if ((0x2f < bVar1) && (bVar1 < 0x3a)) {
          sVar6 = sVar4 + (uVar5 - 0x30);
          sVar4 = sVar6 * 10;
          *(short *)(iRam007012a0 + 0x153c) = sVar6;
        }
        iVar3 = iVar3 + 1;
      }
      if (uVar5 != 0) {
        sVar4 = 0;
        while( true ) {
          iVar2 = iVar3 + 1;
          bVar1 = abStack_110[iVar3 + 1];
          uVar5 = (ushort)bVar1;
          if ((uVar5 == 0) || (uVar5 == 0x2c)) break;
          iVar3 = iVar2;
          if ((0x2f < bVar1) && (bVar1 < 0x3a)) {
            sVar6 = sVar4 + (uVar5 - 0x30);
            sVar4 = sVar6 * 10;
            *(short *)(iRam007012a0 + 0x153e) = sVar6;
          }
        }
      }
    }
  }
  return 0;
}



================================================================