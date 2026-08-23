FUNCTION FUN_005db8a0 @ 0x005db8a0  size=596
CALLERS (0): 
CALLEES (2): FUN_005dfee0@0x005dfee0, FUN_005e07c0@0x005e07c0
----------------------------------------------------------------

void FUN_005db8a0(int param_1)

{
  char cVar1;
  int iVar2;
  float fVar3;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (((((cVar1 == '\x03') || (cVar1 == '\x02')) || (cVar1 == '\x01')) || (cVar1 != '\0')) &&
          ((*(char *)(iRam00701070 + 0x34) == '\0' &&
           ((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 != 0)))) {
    iVar2 = (int)(short)(*(short *)(iRam00701070 + 0x1a) + 0x17c);
    if (cVar1 == '\x02') {
      FUN_005e07c0(*(undefined4 *)(param_1 + 0x34),(float)iVar2,0x41800000,0x41800000,0x10,0);
      fVar3 = *(float *)(param_1 + 0x34);
    }
    else {
      FUN_005e07c0(*(undefined4 *)(param_1 + 0x34),(float)iVar2,0x41800000,0x41800000,0xc,0);
      fVar3 = *(float *)(param_1 + 0x34);
    }
    FUN_005e07c0(fVar3 + 16.0,(float)iVar2,0x44120000,0x14,0);
    if (*(char *)(iRam00701070 + 0x2b) != '\0') {
      *(short *)(iRam00701070 + 0x28) =
           *(short *)(iRam00701070 + 0x20) +
           (short)((*(int *)(iRam00701070 + 4) * 0x228) / *(int *)(iRam00701070 + 0xc)) + 0x10;
      FUN_005e07c0((float)(int)*(short *)(iRam00701070 + 0x28),(float)iVar2,
                   (float)(int)*(short *)(iRam00701070 + 0x26),0x41800000,0x15,0);
    }
    if (*(char *)(param_1 + 6) == '\x03') {
      FUN_005e07c0(0x44130000,(float)iVar2,0x41800000,0x41800000,0x11,0);
    }
    else {
      FUN_005e07c0(0x44130000,(float)iVar2,0x41800000,0x41800000,0xd,0);
    }
  }
  return;
}



================================================================