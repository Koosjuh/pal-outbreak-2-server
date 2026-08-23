FUNCTION FUN_005b2e40 @ 0x005b2e40  size=548
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (15): thunk_FUN_0061f0d0@0x0061ea00, FUN_005ba7b0@0x005ba7b0, FUN_005c4ae0@0x005c4ae0, FUN_00620d40@0x00620d40, FUN_005af300@0x005af300, FUN_00620d60@0x00620d60, FUN_005b68e0@0x005b68e0, FUN_005f6970@0x005f6970, thunk_FUN_00619800@0x0061e900, FUN_005af310@0x005af310, FUN_005c4ad0@0x005c4ad0, FUN_005b6900@0x005b6900, ...
----------------------------------------------------------------

void FUN_005b2e40(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    *(undefined1 *)(param_1 + 0x45a) = 0;
    FUN_005c4ae0(param_1 + 0x54c0);
    FUN_00620d40();
    FUN_005af300(0,10);
    break;
  case '\x01':
    lVar2 = FUN_005af310();
    if (lVar2 != 0) {
      func_0x003adb80();
      FUN_005f4440();
      func_0x001a7de0();
      func_0x001a7e90(0x618c90);
      func_0x001a7de0();
      FUN_00618b60();
      thunk_FUN_0061f0d0(0);
      FUN_005f42c0(0x7153f0,0x715430);
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    }
    break;
  case '\x02':
    lVar2 = FUN_00620d60();
    thunk_FUN_00619800(0);
    if (lVar2 == 1) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      thunk_FUN_0061f0d0(0);
      FUN_00618b60();
      FUN_005f4440();
      FUN_005ba7b0();
    }
    else if (lVar2 == -1) {
      *(undefined1 *)(param_1 + 0xf) = 6;
      thunk_FUN_0061f0d0(0);
      FUN_00618b60();
      FUN_005f4440();
      FUN_005ba7b0();
    }
    break;
  case '\x03':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    func_0x001d3fd0(0,0,0);
    func_0x001a7de0();
    func_0x001a7e20(0x618c90);
    break;
  case '\x04':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    *(undefined1 *)(param_1 + 0x45a) = 1;
    FUN_005b68e0();
    FUN_005c4ad0();
    break;
  case '\x05':
    FUN_005b6900();
    break;
  case '\x06':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    func_0x001d3fd0(0,0,0);
    func_0x001a7de0();
    func_0x001a7e20(0x618c90);
    break;
  case '\a':
    *(undefined1 *)(param_1 + 0x45a) = 1;
    FUN_005f6970();
  }
  return;
}



================================================================