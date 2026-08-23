FUNCTION FUN_005f0480 @ 0x005f0480  size=860
CALLERS (2): FUN_005f0930@0x005f0930, FUN_005f0a10@0x005f0a10
CALLEES (1): FUN_005f0440@0x005f0440
----------------------------------------------------------------

undefined4 FUN_005f0480(undefined8 param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    *(char *)(iVar6 + 0x48) = *(char *)(param_3 + 0x48) + -1;
    *(undefined1 *)(iVar6 + 0x47) = *(undefined1 *)(param_3 + 0x47);
    *(undefined2 *)(iVar6 + 0x34) = *(undefined2 *)(param_3 + 0x34);
    *(undefined1 *)(iVar6 + 0x49) = *(undefined1 *)(param_3 + 0x49);
    *(undefined2 *)(iVar6 + 0x36) = *(undefined2 *)(param_3 + 0x18);
    *(undefined2 *)(param_3 + 0x42) = *(undefined2 *)(iVar6 + 0x18);
  }
  *(undefined2 *)(iVar6 + 0x40) = *(undefined2 *)(param_3 + 0x40);
  uVar2 = FUN_005f0440(param_1);
  *(undefined2 *)(iVar6 + 0x1c) = *(undefined2 *)(param_3 + 0x1c);
  cVar1 = *(char *)(iRam007012a0 + 0x186);
  if (cVar1 == -10) {
    *(undefined2 *)(iVar6 + 0x1e) = 0;
    *(undefined2 *)(iVar6 + 0x24) = 0;
    *(undefined1 *)(iVar6 + 0x44) = 0;
    *(undefined2 *)(iVar6 + 0x20) = *(undefined2 *)(param_3 + 0x20);
    *(undefined1 *)(iVar6 + 0x46) = *(undefined1 *)(param_3 + 0x46);
  }
  else if (cVar1 == '\x01') {
    if (*(char *)(iVar6 + 0x48) == '\x01') {
      uVar5 = (uint)*(ushort *)(iVar6 + 0x1e) +
              (uint)*(ushort *)(iVar6 + 0x30) +
              (uint)*(ushort *)(param_2 + 0x2a) + (uint)*(ushort *)(param_2 + 0x2e);
      uVar2 = (uint)*(ushort *)((uVar2 & 0xff) * 0x5c + iRam007012a0 + 0x250a) +
              (uint)*(ushort *)(iVar6 + 0x40);
      if (uVar5 < uVar2) {
        *(ushort *)(iVar6 + 0x1e) = *(ushort *)(iVar6 + 0x1e) + ((short)uVar2 - (short)uVar5);
      }
    }
    uVar2 = (uint)*(ushort *)(iVar6 + 0x1e) + (uint)*(ushort *)(iVar6 + 0x30) * 2;
    if (*(ushort *)(param_2 + 0x1e) < uVar2) {
      *(short *)(param_2 + 0x1e) = (short)uVar2;
    }
    else {
      *(ushort *)(iVar6 + 0x1e) = *(ushort *)(param_2 + 0x1e) + *(ushort *)(iVar6 + 0x30) * -2;
    }
  }
  else if (cVar1 == '\0') {
    uVar2 = (uint)*(ushort *)(iVar6 + 0x1e) + (uint)*(ushort *)(iVar6 + 0x30) * 2;
    if (*(ushort *)(param_2 + 0x1e) < uVar2) {
      *(short *)(param_2 + 0x1e) = (short)uVar2;
    }
    else {
      *(ushort *)(iVar6 + 0x1e) = *(ushort *)(param_2 + 0x1e) + *(ushort *)(iVar6 + 0x30) * -2;
    }
  }
  *(undefined2 *)(iVar6 + 0x28) = *(undefined2 *)(param_3 + 0x28);
  *(short *)(iVar6 + 0x2a) =
       *(short *)(iVar6 + 0x30) + *(short *)(param_2 + 0x2a) + *(short *)(param_2 + 0x2e);
  *(undefined2 *)(iVar6 + 0x2c) = 0;
  *(undefined2 *)(iVar6 + 0x2e) = 0;
  if (*(char *)(iVar6 + 0x47) == '\0') {
    *(short *)(param_2 + 0x2c) =
         *(short *)(param_2 + 0x2c) +
         *(short *)(iVar6 + 0x32) + *(short *)(iVar6 + 0x1c) + *(short *)(iVar6 + 0x30) * 2;
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      *(short *)(param_2 + 0x20) =
           *(short *)(param_2 + 0x20) +
           *(short *)(iVar6 + 0x32) + *(short *)(iVar6 + 0x1c) + *(short *)(iVar6 + 0x30) * 2;
      *(char *)(param_2 + 0x44) = *(char *)(param_2 + 0x44) + '\x01';
    }
  }
  else if (*(char *)(iVar6 + 0x49) != '\0') {
    *(undefined2 *)(iRam007012a0 + 0xd898) = *(undefined2 *)(iVar6 + 0x34);
    iVar4 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd898) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd898)) * 4;
    *(short *)(param_2 + 0x2c) =
         *(short *)(param_2 + 0x2c) +
         *(short *)(iVar4 + 0x2512) + *(short *)(iVar4 + 0x24fc) + *(short *)(iVar4 + 0x2510) * 2;
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      *(short *)(param_2 + 0x20) =
           *(short *)(param_2 + 0x20) +
           *(short *)(iVar4 + 0x2512) + *(short *)(iVar4 + 0x24fc) + *(short *)(iVar4 + 0x2510) * 2;
      *(char *)(param_2 + 0x44) = *(char *)(param_2 + 0x44) + '\x01';
    }
  }
  *(undefined1 *)(iVar6 + 0x4e) = 0;
  cVar1 = *(char *)(iRam007012a0 + 0xd892);
  if (cVar1 == '\0') {
    uVar3 = 0xffffffff;
  }
  else {
    *(char *)(iRam007012a0 + 0xd892) = cVar1 + -1;
    uVar3 = 0;
  }
  return uVar3;
}



================================================================