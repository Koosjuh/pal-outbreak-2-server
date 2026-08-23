FUNCTION FUN_00621fe0 @ 0x00621fe0  size=324
CALLERS (1): FUN_00622130@0x00622130
CALLEES (1): FUN_005f47e0@0x005f47e0
----------------------------------------------------------------

void FUN_00621fe0(void)

{
  int iStack_4;
  
  iStack_4 = *(int *)(iRam00715298 + 0x110);
  if (iStack_4 != 0) {
    *(float *)(iRam00715298 + 0x18c) = *(float *)(iRam00715298 + 0x18c) + DAT_00694410;
    if (512.0 <= *(float *)(iRam00715298 + 0x18c)) {
      *(float *)(iRam00715298 + 0x18c) = *(float *)(iRam00715298 + 0x18c) - 512.0;
    }
    *(float *)(iRam00715298 + 400) = *(float *)(iRam00715298 + 400) + DAT_00694408;
    if (512.0 <= *(float *)(iRam00715298 + 400)) {
      *(float *)(iRam00715298 + 400) = *(float *)(iRam00715298 + 400) - 512.0;
    }
    func_0x001a7440();
    func_0x001a7b70(0xd,0);
    func_0x001a7b70(0x5f,5);
    func_0x001a7b70(0x60,0);
    func_0x001a7b70(99,0);
    func_0x001a7b70(0x6c,0);
    func_0x00194050(1,&iStack_4);
    func_0x001a7b70(4,iStack_4);
    func_0x001a75e0(4,5);
    FUN_005f47e0(*(undefined4 *)(iRam00715298 + 0x18c),0x6496a0);
    FUN_005f47e0(*(undefined4 *)(iRam00715298 + 400),0x6496a0);
  }
  return;
}



================================================================