FUNCTION FUN_0062b2c0 @ 0x0062b2c0  size=572
CALLERS (0): 
CALLEES (3): FUN_0062b500@0x0062b500, FUN_0062fea0@0x0062fea0, FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_0062b2c0(undefined4 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_190 [128];
  undefined1 auStack_110 [128];
  undefined1 auStack_90 [128];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = param_1[2];
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x1d')) {
    cRam006c4fbb = '\0';
    if ((char)uStack_10 == '\0') {
      iVar1 = iRam006c5ff0 * 0x25;
      if (*(char *)(iVar1 + 0x6c5be5) == '\0') {
        uVar2 = FUN_0062fea0(0x1a);
        func_0x00109728(auStack_90,0x66ad98,iRam006c5ff0 * 0x25 + 0x6c5bd5,uVar2);
      }
      else {
        func_0x00109728(auStack_90,0x66ad80,iVar1 + 0x6c5bd5,iVar1 + 0x6c5be5);
      }
      uRam006c5c44 = 2;
      uVar2 = FUN_0062fea0(0x5f);
      func_0x00109ab0(auStack_90,uVar2);
    }
    else {
      iVar1 = iRam006c5ff0 * 0x25;
      if (*(char *)(iVar1 + 0x6c5be5) == '\0') {
        uVar2 = FUN_0062fea0(0x1a);
        func_0x00109728(auStack_90,0x66ad98,iRam006c5ff0 * 0x25 + 0x6c5bd5,uVar2);
      }
      else {
        uVar2 = FUN_0062fea0(0x1a);
        func_0x00109728(auStack_90,0x66ad80,iVar1 + 0x6c5bd5,iVar1 + 0x6c5be5,uVar2);
      }
      uRam006c5c44 = 1;
      FUN_005be9a0(auStack_110);
      func_0x00106b60(auStack_190,0,0x40);
      FUN_0062b500(auStack_110,auStack_190);
      func_0x00109ab0(auStack_90,auStack_190);
    }
    func_0x00109ab0(auStack_90,0x66ada8);
    func_0x00109ab0(0x6c517c,auStack_90);
  }
  return;
}



================================================================