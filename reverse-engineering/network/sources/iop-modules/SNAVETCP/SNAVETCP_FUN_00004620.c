FUNCTION FUN_00004620 @ 0x00004620 size=180
CALLERS (1): FUN_00011938@0x00011938
CALLEES (7): FUN_00004820@0x00004820, FUN_00003f40@0x00003f40, FUN_00002110@0x00002110, FUN_00003270@0x00003270, FUN_0000a930@0x0000a930, FUN_00006ba0@0x00006ba0, FUN_00000f50@0x00000f50

undefined4 FUN_00004620(undefined4 param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_00000f50();
  uVar2 = 0xffffffff;
  if (sVar1 == 0) {
    sVar1 = FUN_00003f40();
    uVar2 = 0xffffffff;
    if (sVar1 == 0) {
      sVar1 = FUN_00004820(param_1);
      uVar2 = 0xffffffff;
      if (sVar1 == 0) {
        sVar1 = FUN_00002110();
        uVar2 = 0xffffffff;
        if (sVar1 == 0) {
          sVar1 = FUN_00003270();
          uVar2 = 0xffffffff;
          if (sVar1 == 0) {
            sVar1 = FUN_0000a930();
            if (sVar1 == 0) {
              sVar1 = FUN_00006ba0();
              uVar2 = 0xffffffff;
              if (sVar1 == 0) {
                uVar2 = 0;
              }
            }
            else {
              uVar2 = 0xffffffff;
            }
          }
        }
      }
    }
  }
  return uVar2;
}


================================================================