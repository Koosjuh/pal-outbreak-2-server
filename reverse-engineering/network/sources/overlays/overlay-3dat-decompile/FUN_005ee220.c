FUNCTION FUN_005ee220 @ 0x005ee220  size=580
CALLERS (2): FUN_005f2e50@0x005f2e50, FUN_005ee610@0x005ee610
CALLEES (3): FUN_005ed630@0x005ed630, FUN_005d96a0@0x005d96a0, FUN_005d9790@0x005d9790
----------------------------------------------------------------

void FUN_005ee220(undefined8 param_1,short param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  short sVar4;
  
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    cVar1 = *(char *)(iRam007012a0 + 0x17f);
    uVar2 = (uint)param_1;
    if (cVar1 == '\x02') {
      uVar3 = FUN_005ed630(iRam007012a0 + 399);
      param_2 = param_2 + *(short *)(param_3 + 2);
      FUN_005d9790(param_1,param_2 - *(short *)(iRam007012a0 + 0xdf8),
                   (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xdf6) & 0xffff,param_2,
                   iRam007012a0 + 0xaf6,iRam007012a0 + 0x9f6,iRam007012a0 + 0xbf6,uVar3);
    }
    else if (cVar1 == '\x01') {
      uVar3 = FUN_005ed630(iRam007012a0 + 399);
      param_2 = param_2 + *(short *)(param_3 + 2);
      FUN_005d9790(param_1,param_2 - *(short *)(iRam007012a0 + 0xdf8),
                   (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xdf6) & 0xffff,param_2,
                   iRam007012a0 + 0xaf6,iRam007012a0 + 0x8f6,iRam007012a0 + 0xbf6,uVar3);
    }
    else if (cVar1 == '\0') {
      sVar4 = param_2 + *(short *)(param_3 + 2);
      FUN_005d96a0(param_1,sVar4 - *(short *)(iRam007012a0 + 0xdf8),
                   (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xdf6) & 0xffff,sVar4,
                   iRam007012a0 + 0xaf6,iRam007012a0 + 0xbf6);
      if (*(char *)(iRam007012a0 + 0xcf6) != '\0') {
        func_0x001069a8(iRam007012a0 + (uint)*(byte *)(iRam007012a0 + 0xfac0) * 0x104 + 0xea80,
                        iRam007012a0 + 0xcf6,0x100);
        *(short *)((uint)*(byte *)(iRam007012a0 + 0xfac0) * 0x104 + iRam007012a0 + 0xeb80) =
             (short)param_1;
        *(short *)((uint)*(byte *)(iRam007012a0 + 0xfac0) * 0x104 + iRam007012a0 + 0xeb82) =
             (param_2 + *(short *)(param_3 + 2)) - *(short *)(iRam007012a0 + 0xdf8);
        *(char *)(iRam007012a0 + 0xfac0) = *(char *)(iRam007012a0 + 0xfac0) + '\x01';
      }
    }
  }
  return;
}



================================================================