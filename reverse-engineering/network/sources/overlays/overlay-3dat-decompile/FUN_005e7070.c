FUNCTION FUN_005e7070 @ 0x005e7070  size=1680
CALLERS (1): FUN_005e7a30@0x005e7a30
CALLEES (4): FUN_005da430@0x005da430, FUN_005e60c0@0x005e60c0, FUN_005e5f80@0x005e5f80, FUN_005e67a0@0x005e67a0
----------------------------------------------------------------

void FUN_005e7070(void)

{
  char *pcVar1;
  bool bVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_10 [10];
  undefined1 uStack_6;
  
  bVar2 = false;
  if ((**(char **)(iRam007012a0 + 0xd964) == 'M') &&
     (lVar4 = func_0x0010a338(*(char **)(iRam007012a0 + 0xd964),0x6481b8,0xe), lVar4 == 0)) {
    *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 0xe;
    cVar3 = *(char *)(*(int *)(iRam007012a0 + 0xd964) + 1);
    if (cVar3 == '3') {
      bVar2 = true;
    }
    else if (cVar3 == '2') {
      bVar2 = true;
    }
    if ((bVar2) && (lVar4 = func_0x0010a700(*(int *)(iRam007012a0 + 0xd964),0x6481d0), lVar4 != 0))
    {
      *(int *)(iRam007012a0 + 0xd964) = (int)lVar4 + 0x13;
    }
  }
  else if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    while( true ) {
      pcVar1 = *(char **)(iRam007012a0 + 0xd964);
      cVar3 = *pcVar1;
      if (cVar3 == '\0') break;
      if (cVar3 == '-') {
        lVar4 = func_0x0010a338(pcVar1,0x6481e8,3);
        if (lVar4 == 0) {
          return;
        }
      }
      else if (cVar3 == '<') {
        lVar4 = func_0x0010a338(pcVar1,0x6481f0,0xc);
        if (lVar4 != 0) {
          return;
        }
        FUN_005e60c0();
        return;
      }
      *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 1;
    }
  }
  else if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    cVar3 = FUN_005e5f80(*(undefined4 *)(iRam007012a0 + 0xd964),0x647e30,0x160);
    if (cVar3 == '\0') {
      if (*(char *)(iRam007012a0 + 0x191) != '\0') {
        while( true ) {
          pcVar1 = *(char **)(iRam007012a0 + 0xd964);
          cVar3 = *pcVar1;
          if (cVar3 == '\0') break;
          if (cVar3 == '-') {
            lVar4 = func_0x0010a338(pcVar1,0x6481e8,3);
            if (lVar4 == 0) {
              return;
            }
          }
          else if (cVar3 == '<') {
            lVar4 = func_0x0010a338(pcVar1,0x648218,5);
            if (lVar4 != 0) {
              return;
            }
            FUN_005e67a0(*(undefined1 *)(iRam007012a0 + 0x191));
            return;
          }
          *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 1;
        }
      }
    }
    else if (cVar3 == 'c') {
      *(undefined1 *)(iRam007012a0 + 0x192) = 1;
    }
    else if (cVar3 == 'b') {
      if (*(char *)(iRam007012a0 + 0x191) == '\x01') {
        *(undefined1 *)(iRam007012a0 + 0x191) = 2;
      }
    }
    else if (cVar3 == '%') {
      *(undefined1 *)(iRam007012a0 + 0x18e) = 0x25;
    }
    else if (cVar3 == '!') {
      *(undefined1 *)(iRam007012a0 + 0x191) = 7;
      *(undefined1 *)(iRam007012a0 + 0x18e) = 0x21;
    }
    else if ((((((cVar3 != ' ') && (cVar3 != '\x1f')) && (cVar3 != '\x1e')) &&
              ((cVar3 != '\x1d' && (cVar3 != '\x1c')))) &&
             ((cVar3 != '\x1b' && ((cVar3 != '\x1a' && (cVar3 != '\x19')))))) &&
            ((cVar3 != '\x18' &&
             ((((cVar3 != '\x17' && (cVar3 != '\x16')) && (cVar3 != '\x15')) && (cVar3 != '\x14'))))
            )) {
      if (cVar3 == '\x13') {
        *(undefined1 *)(iRam007012a0 + 0x191) = 6;
        *(undefined1 *)(iRam007012a0 + 0x18e) = 0x13;
      }
      else if (((cVar3 == '\x11') || (cVar3 == '\x10')) || ((cVar3 == '\x0e' || (cVar3 == '\r')))) {
        *(char *)(iRam007012a0 + 0x191) = cVar3 + -0xc;
      }
      else if (cVar3 == '\f') {
        *(undefined1 *)(iRam007012a0 + 400) = 1;
      }
      else if (cVar3 == '\t') {
        if (*(char *)(iRam007012a0 + 0x18e) == '\x04') {
          *(undefined1 *)(iRam007012a0 + 399) = 9;
          func_0x0010a4f0(auStack_10,*(int *)(iRam007012a0 + 0xd964) + (uint)DAT_00647e74 + 2,10);
          uStack_6 = 0;
          FUN_005da430(auStack_10);
        }
        else if (*(char *)(iRam007012a0 + 0x18e) == '%') {
          iVar6 = *(int *)(iRam007012a0 + 0xd964) + (uint)DAT_00647e74 + 2;
          lVar4 = func_0x0010a700(*(int *)(iRam007012a0 + 0xd964),0x648200);
          if (lVar4 != 0) {
            iVar5 = (int)lVar4 - iVar6;
            if (0xf < iVar5) {
              iVar5 = 0xf;
            }
            func_0x001069a8(auStack_10,iVar6,iVar5);
            auStack_10[iVar5] = 0;
            FUN_005da430(auStack_10);
          }
        }
      }
      else if (((cVar3 == '/') || (cVar3 == '.')) ||
              (((cVar3 == '-' || (((cVar3 == ',' || (cVar3 == '(')) || (cVar3 == '\v')))) ||
               ((cVar3 == '\n' || (cVar3 == '\b')))))) {
        *(char *)(iRam007012a0 + 399) = cVar3;
      }
      else if (cVar3 != 'a') {
        if (((cVar3 != '+') && (cVar3 != '*')) &&
           ((cVar3 != ')' &&
            ((((cVar3 != '\x12' && (cVar3 != '\a')) && (cVar3 != '\x06')) &&
             ((cVar3 != '\x05' && (cVar3 != '\x03')))))))) {
          if ((cVar3 != '\x04') && ((cVar3 != '\x02' && (cVar3 != '\x01')))) {
            return;
          }
          *(undefined1 *)(iRam007012a0 + 400) = 1;
        }
        *(char *)(iRam007012a0 + 0x18e) = cVar3;
      }
    }
  }
  return;
}



================================================================