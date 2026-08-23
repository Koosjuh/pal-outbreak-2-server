FUNCTION FUN_005e60c0 @ 0x005e60c0  size=1388
CALLERS (1): FUN_005e7070@0x005e7070
CALLEES (2): FUN_005e5e50@0x005e5e50, FUN_005ec920@0x005ec920
----------------------------------------------------------------

void FUN_005e60c0(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_110 [272];
  
  *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 0xc;
  do {
    do {
      func_0x00106b60(auStack_110,0,0x110);
      lVar5 = FUN_005e5e50(auStack_110,0x110);
      if (lVar5 != 0) {
        return;
      }
      uVar4 = FUN_005ec920(auStack_110,0x6479f0,0x60);
      lVar5 = func_0x0010a700(auStack_110,0x648190);
    } while (lVar5 == 0);
    iVar8 = (int)lVar5;
    *(undefined *)(iVar8 + 1) = (&DAT_00648090)[*(byte *)(iVar8 + 1)];
    *(undefined *)(iVar8 + 2) = (&DAT_00648090)[*(byte *)(iVar8 + 2)];
    uVar6 = func_0x0010a050(0x648198);
    lVar5 = func_0x0010a338(iVar8 + 1,0x648198,uVar6);
    bVar1 = lVar5 == 0;
    switch(uVar4) {
    case 0:
      *(undefined1 *)(iRam00701068 + 0x4f8b9) = 0;
      if (*(char *)(iVar8 + 3) == ':') {
        bVar3 = *(byte *)(iVar8 + 4);
        if ((0x2f < bVar3) && (bVar3 < 0x3a)) {
          *(byte *)(iRam00701068 + 0x4f8b9) = bVar3 - 0x30;
        }
      }
      break;
    case 1:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfffe | (ushort)bVar1;
      break;
    case 2:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfffd | (ushort)bVar1 << 1;
      *(undefined1 *)(iRam007012a0 + 0xfbc2) = 0;
      if ((bVar1) && (*(char *)(iVar8 + 3) == ':')) {
        bVar3 = *(byte *)(iVar8 + 4);
        if ((0x2f < bVar3) && (bVar3 < 0x3a)) {
          *(byte *)(iRam007012a0 + 0xfbc2) = bVar3 - 0x30;
        }
      }
      else if ((!bVar1) && (*(char *)(iVar8 + 4) == ':')) {
        bVar3 = *(byte *)(iVar8 + 5);
        if ((0x2f < bVar3) && (bVar3 < 0x3a)) {
          *(byte *)(iRam007012a0 + 0xfbc2) = bVar3 - 0x30;
        }
      }
      break;
    case 3:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfffb | (ushort)bVar1 << 2;
      break;
    case 4:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfff7 | (ushort)bVar1 << 3;
      func_0x00106b60(iRam007012a0 + 0xe980,0,0x100);
      if (bVar1) {
        if (*(char *)(iVar8 + 3) == ':') {
          func_0x001069a8(iRam007012a0 + 0xe980,iVar8 + 4,0xff);
        }
        else {
          iVar7 = iVar8 + 4;
          if (*(char *)(iVar8 + 3) == ';') {
            for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iRam00701068 + 0x4f8b9); iVar8 = iVar8 + 1)
            {
              lVar5 = func_0x0010a700(iVar7,0x6481a0);
              iVar7 = (int)lVar5 + 1;
              if (lVar5 == 0) {
                return;
              }
            }
            for (iVar8 = 0;
                ((iVar8 < 0xff && (cVar2 = *(char *)(iVar7 + iVar8), cVar2 != ';')) &&
                (cVar2 != '\0')); iVar8 = iVar8 + 1) {
              *(char *)(iRam007012a0 + iVar8 + 0xe980) = cVar2;
            }
          }
        }
      }
      else if (*(char *)(iVar8 + 4) == ':') {
        func_0x001069a8(iRam007012a0 + 0xe980,iVar8 + 5,0xff);
      }
      break;
    case 5:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xffef | (ushort)bVar1 << 4;
      break;
    case 6:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xffdf | (ushort)bVar1 << 5;
      break;
    case 7:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xffbf | (ushort)bVar1 << 6;
      break;
    case 8:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xff7f | (ushort)bVar1 << 7;
      break;
    case 9:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfeff | (ushort)bVar1 << 8;
      break;
    case 10:
      *(ushort *)(iRam007012a0 + 0xe97e) =
           *(ushort *)(iRam007012a0 + 0xe97e) & 0xfdff | (ushort)bVar1 << 9;
      break;
    case 0xb:
      *(undefined1 *)(iRam007012a0 + 0xfbc1) = 0;
      if (*(char *)(iVar8 + 3) == ':') {
        bVar3 = *(byte *)(iVar8 + 4);
        if ((0x2f < bVar3) && (bVar3 < 0x3a)) {
          *(byte *)(iRam007012a0 + 0xfbc1) = bVar3 - 0x30;
        }
      }
    }
  } while( true );
}



================================================================