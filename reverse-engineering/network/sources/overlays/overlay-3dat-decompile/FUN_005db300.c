FUNCTION FUN_005db300 @ 0x005db300  size=952
CALLERS (0): 
CALLEES (2): FUN_005dfee0@0x005dfee0, FUN_005e07c0@0x005e07c0
----------------------------------------------------------------

void FUN_005db300(int param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (((((cVar1 == '\x03') || (cVar1 == '\x02')) || (cVar1 == '\x01')) || (cVar1 != '\0')) &&
          ((*(char *)(iRam00701070 + 0x34) == '\0' &&
           ((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 != 0)))) {
    sVar3 = 0x270 - *(short *)(iRam00701070 + 0x20);
    iVar4 = (int)sVar3;
    if (cVar1 == '\x02') {
      FUN_005e07c0((float)iVar4,(float)(int)*(short *)(iRam00701070 + 0x1a),0x41800000,0x41800000,
                   0xe,0);
    }
    else {
      FUN_005e07c0((float)iVar4,(float)(int)*(short *)(iRam00701070 + 0x1a),0x41800000,0x41800000,10
                   ,0);
    }
    iVar5 = (int)sVar3;
    FUN_005e07c0((float)iVar5,(float)(*(short *)(iRam00701070 + 0x1a) + 0x10),0x41800000,0x43be0000,
                 0x12,0);
    if (*(char *)(iRam00701070 + 0x2a) == '\0') {
      sVar3 = (0x17c - *(short *)(iRam00701070 + 0x1a)) - *(short *)(iRam00701070 + 0x1c);
    }
    else {
      if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) {
        sVar2 = *(short *)(iRam00701070 + 0x1a);
        sVar3 = (0x1a0 - sVar2) - *(short *)(iRam00701070 + 0x1c);
      }
      else {
        sVar2 = *(short *)(iRam00701070 + 0x1a);
        sVar3 = (0x17c - sVar2) - *(short *)(iRam00701070 + 0x1c);
      }
      *(short *)(iRam00701070 + 0x24) =
           sVar2 + (short)((*(int *)(iRam00701070 + 8) * (int)sVar3) / *(int *)(iRam00701070 + 0x10)
                          ) + 0xe;
      FUN_005e07c0(*(undefined4 *)(param_1 + 0x34),(float)(int)*(short *)(iRam00701070 + 0x24),
                   0x41800000,(float)(int)*(short *)(iRam00701070 + 0x22),0x13,0);
    }
    if ((int)(*(ushort *)(iRam00701070 + 0x18) & 4) >> 2 == 0) {
      if (*(char *)(param_1 + 6) == '\x03') {
        FUN_005e07c0((float)iVar5,(float)(0x1b0 - *(short *)(iRam00701070 + 0x1c)),0x41800000,
                     0x41800000,0xf,0);
      }
      else {
        FUN_005e07c0((float)iVar4,(float)(0x1b0 - *(short *)(iRam00701070 + 0x1c)),0x41800000,
                     0x41800000,0xb,0);
      }
    }
    else if (*(char *)(param_1 + 6) == '\x03') {
      FUN_005e07c0((float)iVar4,(float)((int)*(short *)(iRam00701070 + 0x1a) + (int)sVar3 + 0x10),
                   0x41800000,0x41800000,0xf,0);
    }
    else {
      FUN_005e07c0((float)iVar5,(float)((int)*(short *)(iRam00701070 + 0x1a) + (int)sVar3 + 0x10),
                   0x41800000,0x41800000,0xb,0);
    }
  }
  return;
}



================================================================