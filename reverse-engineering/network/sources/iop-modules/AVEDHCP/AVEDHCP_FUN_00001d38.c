FUNCTION FUN_00001d38 @ 0x00001d38 size=984
CALLERS (3): FUN_00002110@0x00002110, FUN_00001788@0x00001788, FUN_00002130@0x00002130
CALLEES (7): FUN_00000900@0x00000900, FUN_000009e4@0x000009e4, FUN_000029ac@0x000029ac, FUN_00001568@0x00001568, FUN_00002d04@0x00002d04, FUN_000013ec@0x000013ec, FUN_00002530@0x00002530

/* WARNING: Type propagation algorithm not settling */

int FUN_00001d38(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = FUN_00002d04();
  if (DAT_00002f7c != 1) {
    if (1 < DAT_00002f7c) {
      if (DAT_00002f7c != 2) {
        return DAT_00002eb0;
      }
      if (DAT_00002f80 != 0) {
        if ((DAT_00002eb0 == 4) || (DAT_00002eb0 == 5)) {
          FUN_00001568(&DAT_00003664);
          DAT_000042a4 = 0;
        }
        FUN_000009e4();
        FUN_000029ac(&DAT_00003578);
        DAT_00002eb0 = 3;
        DAT_00002f7c = 0;
        return 3;
      }
      if (DAT_00002eb0 == 2) {
        if (uVar1 - DAT_00002f68 < 3000) {
          return 2;
        }
        DAT_00002f6c = DAT_00002f6c + -1;
        if (DAT_00002f6c < 1) {
          FUN_000009e4();
          DAT_00002eb0 = 0xffffffff;
          DAT_00002f50 = 7;
          DAT_00002f7c = 0xffffffff;
          return -1;
        }
      }
      else {
        if (DAT_00002eb0 == 4) {
          if (DAT_00002f70 == 0) {
            DAT_00002f50 = 8;
            return 4;
          }
          uVar3 = 8;
        }
        else {
          if (DAT_00002eb0 != 5) {
            return DAT_00002eb0;
          }
          if (DAT_00002f70 == 0) {
            DAT_00002f50 = 9;
            return 5;
          }
          uVar3 = 9;
        }
        if (uVar1 - DAT_00002f68 < DAT_00002f70) {
          DAT_00002f50 = uVar3;
          return DAT_00002eb0;
        }
      }
      DAT_00002f7c = 1;
      return DAT_00002eb0;
    }
    if (DAT_00002f7c != 0) {
      return DAT_00002eb0;
    }
    DAT_00004264 = uVar1 >> 0x18 | uVar1 >> 8 & 0xff00 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    if (DAT_00002eb0 == 2) {
      DAT_00002f6c = DAT_000042a8;
    }
    iVar2 = FUN_00000900();
    if (iVar2 != 0) {
      return DAT_00002eb0;
    }
    DAT_00002f7c = 1;
  }
  iVar2 = FUN_00002530(&DAT_00002f98);
  DAT_00002f80 = 0;
  uVar3 = 0xffffffff;
  if (DAT_00002eb0 == 4) {
    uVar3 = DAT_00004134;
  }
  if (iVar2 < 300) {
    iVar2 = 300;
  }
  iVar2 = FUN_000013ec((int)DAT_00002f88,uVar3,0x4300,(int)(short)iVar2,&DAT_00002f98);
  if (-1 < iVar2 << 0x10) {
    if (DAT_00002eb0 == 4) {
      uVar4 = DAT_000042a0 - DAT_000042a4;
    }
    else {
      if (DAT_00002eb0 != 5) {
        DAT_00002f68 = uVar1;
        DAT_00002f7c = 2;
        return DAT_00002eb0;
      }
      uVar4 = DAT_00004298 - DAT_000042a4;
    }
    if (uVar4 < 0x78) {
      DAT_00002f70 = 0;
    }
    else {
      DAT_00002f70 = (uVar4 >> 1) * 1000;
    }
    DAT_00002f7c = 2;
    DAT_00002f68 = uVar1;
    return DAT_00002eb0;
  }
  FUN_000009e4();
  DAT_00002eb0 = 0xfffffffe;
  DAT_00002f50 = 5;
  DAT_00002f7c = 0xffffffff;
  return -2;
}


================================================================