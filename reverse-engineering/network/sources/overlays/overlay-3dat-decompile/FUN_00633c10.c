FUNCTION FUN_00633c10 @ 0x00633c10  size=912
CALLERS (1): FUN_00636890@0x00636890
CALLEES (3): FUN_006381e0@0x006381e0, FUN_005af2c0@0x005af2c0, FUN_00632c00@0x00632c00
----------------------------------------------------------------

void FUN_00633c10(float param_1,short param_2)

{
  short sVar1;
  float fVar2;
  undefined1 auStack_50 [64];
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  undefined4 uStack_8;
  
  if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
    if (*(float *)(iRam00715da8 + 0x14) == 1.0) {
      sVar1 = (short)(int)((float)*(int *)(iRam00715da8 + 0x25c) * 10.0 - 7.0);
    }
    else {
      sVar1 = (short)(int)((float)*(int *)(iRam00715da8 + 0x25c) * 10.0 - 28.0);
    }
    sStack_e = param_2 + 0x14;
    sStack_10 = (short)(int)(param_1 + (float)(int)sVar1 * *(float *)(iRam00715da8 + 0x14));
    sStack_c = sStack_10 + 0xa2;
    sStack_a = param_2 + 0x6a;
    uStack_8 = **(undefined4 **)(iRam00715da8 + 0x10);
    FUN_006381e0(&sStack_10,0xffffffffffffffe7);
    sStack_10 = sStack_10 + (short)(int)(*(float *)(iRam00715da8 + 0x14) * 5.0);
    sStack_c = sStack_c - (short)(int)(*(float *)(iRam00715da8 + 0x14) * 5.0);
    sStack_e = sStack_e + 5;
    sStack_a = sStack_a + -5;
    uStack_8 = 0xff303030;
    FUN_006381e0(&sStack_10,0xffffffffffffffe7);
    func_0x001af060(0x12,0x12);
    param_1 = param_1 + (float)*(int *)(iRam00715da8 + 0x25c) * 10.0;
    func_0x001af0b0(0);
    FUN_005af2c0(0);
    fVar2 = param_1 + 10.0;
    sVar1 = 0;
    do {
      if ((long)sVar1 == (long)(*(int *)(iRam00715da8 + 0x24c) % 3)) {
        func_0x001af0b0(1);
        FUN_005af2c0(3);
      }
      else {
        func_0x001af0b0(0);
        FUN_005af2c0(0);
      }
      func_0x001af080((short)(int)fVar2,(short)(int)((float)((int)param_2 + sVar1 * 0x14) + 26.0));
      FUN_00632c00(sVar1 * 0x10 + 0x715b30,0x715bb0);
      func_0x001af0a0(0xffffffffffffffe8);
      func_0x001af190(0x68f2d0,0x715bb0);
      sVar1 = sVar1 + 1;
    } while (sVar1 < 3);
    func_0x001af0b0(0);
    FUN_005af2c0(0);
    func_0x00109728(auStack_50,0x68f2d8,*(int *)(iRam00715da8 + 0x24c) + 1,
                    *(undefined4 *)(iRam00715da8 + 600));
    func_0x001af080((short)(int)(param_1 + 20.0),param_2 + 0x53);
    func_0x001af0a0(0xffffffffffffffe8);
    func_0x001af190(auStack_50);
  }
  return;
}



================================================================