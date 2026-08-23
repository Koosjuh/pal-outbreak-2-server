FUNCTION FUN_005eca10 @ 0x005eca10  size=1216
CALLERS (2): FUN_005f3150@0x005f3150, FUN_005ed0c0@0x005ed0c0
CALLEES (4): FUN_005d9bd0@0x005d9bd0, FUN_005d8b90@0x005d8b90, FUN_005d9ca0@0x005d9ca0, FUN_005d8c90@0x005d8c90
----------------------------------------------------------------

void FUN_005eca10(undefined8 param_1,short param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = func_0x0010a050(iRam007012a0 + 0x20);
  if ((lVar3 != 0) || (*(char *)(iRam007012a0 + 0xe96b) != '\0')) {
    cVar1 = *(char *)(iRam007012a0 + 0x17f);
    uVar2 = (uint)param_1;
    if (cVar1 == '\x03') {
      param_2 = param_2 + *(short *)(param_3 + 2);
      FUN_005d8b90(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                   *(undefined4 *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 0x128),
                   *(byte *)(iRam007012a0 + 0x180),
                   (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                   iRam007012a0 + 0x20);
    }
    else if (cVar1 == '\x02') {
      if (*(char *)(iRam007012a0 + 0x17d) == '\0') {
        if (*(char *)(iRam007012a0 + 0x17e) == '\0') {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d8c90(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20,iRam007012a0 + 0x9f6);
        }
        else {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d9ca0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20,iRam007012a0 + 0x9f6);
        }
      }
      else {
        param_2 = param_2 + *(short *)(param_3 + 2);
        FUN_005d9bd0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                     *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                     (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                     iRam007012a0 + 0x20,iRam007012a0 + 0x9f6);
      }
    }
    else if (cVar1 == '\x01') {
      if (*(char *)(iRam007012a0 + 0x17d) == '\0') {
        if (*(char *)(iRam007012a0 + 0x17e) == '\0') {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d8c90(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20,iRam007012a0 + 0x8f6);
        }
        else {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d9ca0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20,iRam007012a0 + 0x8f6);
        }
      }
      else {
        param_2 = param_2 + *(short *)(param_3 + 2);
        FUN_005d9bd0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                     *(undefined4 *)(iRam007012a0 + 0x178),*(byte *)(iRam007012a0 + 0x180),
                     (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                     iRam007012a0 + 0x20,iRam007012a0 + 0x8f6);
      }
    }
    else if (cVar1 == '\0') {
      *(undefined1 *)(iRam007012a0 + 0x8f6) = 0;
      if (*(char *)(iRam007012a0 + 0x17d) == '\0') {
        if (*(char *)(iRam007012a0 + 0x17e) == '\0') {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d8b90(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 0x128),
                       *(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20);
        }
        else {
          param_2 = param_2 + *(short *)(param_3 + 2);
          FUN_005d9ca0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                       *(undefined4 *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 0x128),
                       *(byte *)(iRam007012a0 + 0x180),
                       (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                       iRam007012a0 + 0x20,iRam007012a0 + 0x8f6);
        }
      }
      else {
        param_2 = param_2 + *(short *)(param_3 + 2);
        FUN_005d9bd0(param_1,param_2 - (ushort)*(byte *)(iRam007012a0 + 0x180),
                     *(undefined4 *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 0x128),
                     *(byte *)(iRam007012a0 + 0x180),
                     (uVar2 & 0xffff) + (uint)*(ushort *)(iRam007012a0 + 0xd8c8) & 0xffff,param_2,
                     iRam007012a0 + 0x20,iRam007012a0 + 0x8f6);
      }
    }
  }
  return;
}



================================================================