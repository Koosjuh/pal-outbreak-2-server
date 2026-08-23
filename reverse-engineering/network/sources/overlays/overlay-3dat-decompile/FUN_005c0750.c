FUNCTION FUN_005c0750 @ 0x005c0750  size=248
CALLERS (6): FUN_0062e800@0x0062e800, FUN_0062dc40@0x0062dc40, FUN_005ff760@0x005ff760, FUN_005fb9b0@0x005fb9b0, FUN_005fada0@0x005fada0, FUN_005c1c80@0x005c1c80
CALLEES (3): FUN_005be0a0@0x005be0a0, FUN_005bf130@0x005bf130, FUN_005c2080@0x005c2080
----------------------------------------------------------------

long FUN_005c0750(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  code *extraout_a2_lo;
  int iVar4;
  undefined1 auStack_10 [12];
  undefined4 uStack_4;
  
  if (cRam006ff2b1 == '\0') {
    FUN_005bf130(2);
    auStack_10[0] = 0;
    (*extraout_a2_lo)(auStack_10,auStack_10);
    lVar3 = 0;
  }
  else {
    lVar2 = FUN_005be0a0(1,0,param_1);
    lVar3 = -1;
    if (lVar2 != -1) {
      cRam006ff2b1 = '\x03';
      if (cRam006ff2b0 != '\0') {
        uStack_4 = 0x40000000;
        func_0x001dd33c(uRam006febac,0x53544154,&uStack_4,4,0,0x5c06b0);
      }
      uVar1 = FUN_005c2080(2);
      iVar4 = (int)lVar2 * 0x20;
      *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
      uVar1 = func_0x001dd1dc(uRam006febac,0x5c06c0);
      *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
      lVar3 = lVar2;
    }
  }
  return lVar3;
}



================================================================