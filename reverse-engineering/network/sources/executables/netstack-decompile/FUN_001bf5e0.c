
undefined8 FUN_001bf5e0(void)

{
  long lVar1;
  
  FUN_001c0230();
  FUN_001bf530();
  uRam00354250 = 0;
  uRam00354258 = 0;
  FUN_001bf380(uRam007dfb28,1,0x2483f8,0,0);
  lVar1 = FUN_0011a660(0x248400);
  if (-1 < lVar1) {
    uRam0035c3c8 = 0x21;
    iRam0035c3b8 = DAT_002483c0;
    uRam0035c3bc = DAT_002483c4;
    uRam0035c3c0 = DAT_002483c8;
    uRam0035c3c4 = DAT_002483cc;
    puRam0035c3cc = PTR_DAT_002483d4;
    puRam0035c3d0 = PTR_s_Ethernet__Network_Adaptor__002483d8;
  }
  if (iRam0035c3b8 != -1) {
    uRam0035c3d8 = 0x35c3b8;
    FUN_001bf380(uRam007dfbe8,1,0x2483f8,0,0);
    FUN_001bf380(uRam007dfbb8,0,0,0,0);
    FUN_001bf380(uRam007dfb58,1,0x2483f8,0,0);
    FUN_001bf380(uRam007dfc18,9,0x248408,0,0);
    FUN_001bf380(uRam007dfb88,0,0,0,0);
    FUN_001bf5c0();
  }
  return 0;
}

