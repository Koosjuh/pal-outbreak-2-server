FUNCTION FUN_00623be0 @ 0x00623be0  size=3028
CALLERS (1): FUN_00623b10@0x00623b10
CALLEES (7): FUN_0061f0f0@0x0061f0f0, FUN_0061f2d0@0x0061f2d0, FUN_006247c0@0x006247c0, FUN_0061e730@0x0061e730, FUN_0061e860@0x0061e860, FUN_0061f680@0x0061f680, FUN_00624800@0x00624800
----------------------------------------------------------------

undefined4 FUN_00623be0(void)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  cVar1 = *(char *)(iRam00715298 + 0x161);
  if (cVar1 == 'c') {
    *(undefined4 *)(iRam00715298 + 0x180) = 0xffffffff;
    return 0;
  }
  if (cVar1 == '[') {
    if (*(int *)(iRam00715298 + 0x184) != 0) {
      *(int *)(iRam00715298 + 0x184) = *(int *)(iRam00715298 + 0x184) + -1;
      return 1;
    }
    if ((uRam003433b0 & 0xfff0) == 0) {
      return 1;
    }
    FUN_0061e730();
    return 0;
  }
  if (cVar1 == 'Z') {
    iVar2 = *(int *)(iRam00715298 + 0x184) + -1;
    *(int *)(iRam00715298 + 0x184) = iVar2;
    if (iVar2 != 0) {
      return 1;
    }
    if (*(int *)(iRam00715298 + 0x16c) != 0x62) {
      *(undefined4 *)(iRam00715298 + 0x16c) = 7;
      *(char *)(iRam00715298 + 0x161) = *(char *)(iRam00715298 + 0x161) + '\x01';
      *(undefined4 *)(iRam00715298 + 0x180) = 0;
      *(undefined4 *)(iRam00715298 + 0x184) = 0x1e;
      return 1;
    }
    return 0;
  }
  if (cVar1 == '\x1e') {
    FUN_0061f680(6);
    lVar3 = FUN_0061e860();
    if (lVar3 == -1) {
      FUN_0061f0f0(0x200000);
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      *(undefined1 *)(iRam00715298 + 0x161) = 0;
      *(undefined4 *)(iRam00715298 + 0x16c) = 0;
      *(undefined4 *)(iRam00715298 + 0x180) = 0;
      return 1;
    }
    if (lVar3 != 1) {
      return 1;
    }
    FUN_0061f0f0(0x200000);
    FUN_0061f0f0(0x80000);
    FUN_0061f0f0(0x100000);
    *(undefined4 *)(iRam00715298 + 0x16c) = 0;
    *(undefined4 *)(iRam00715298 + 0x180) = 0xffffffff;
    return 0;
  }
  if (cVar1 == '\x14') {
    iVar2 = *(int *)(iRam00715298 + 0x180);
    if ((((iVar2 == 6) || (iVar2 == 4)) || (iVar2 == 3)) || (iVar2 == 2)) {
      lVar3 = func_0x001f5630(0);
      if (lVar3 == 0) {
        *(undefined4 *)(iRam00715298 + 0x16c) = 4;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
        *(undefined4 *)(iRam00715298 + 0x180) = 5;
        goto LAB_00624778;
      }
    }
    else if (iVar2 == 1) goto LAB_006244b0;
    FUN_0061f680(6);
    lVar3 = FUN_0061e860();
    if (lVar3 == -1) {
      FUN_0061f0f0(0x200000);
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      *(undefined4 *)(iRam00715298 + 0x16c) = 0x98;
      *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
    }
    else {
      if (lVar3 != 1) {
        return 1;
      }
      FUN_0061f0f0(0x200000);
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      iVar2 = *(int *)(iRam00715298 + 0x180);
      if (iVar2 == 4) {
        *(undefined4 *)(iRam00715298 + 0x16c) = 0x67;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
        *(undefined4 *)(iRam00715298 + 0x180) = 0;
      }
      else {
        if (iVar2 == 6) {
          func_0x001f51b0(*(undefined4 *)(iRam00715298 + 0x164));
          *(undefined4 *)(iRam00715298 + 0x16c) = 0x6b;
          *(undefined1 *)(iRam00715298 + 0x161) = 10;
          *(undefined4 *)(iRam00715298 + 0x180) = 0;
          return 1;
        }
        if (iVar2 != 3) {
          if (iVar2 == 2) {
            FUN_006247c0();
            func_0x001f4ca0(*(undefined4 *)(iRam00715298 + 0x164),
                            *(undefined4 *)(iRam00715298 + 0x170));
            *(undefined4 *)(iRam00715298 + 0x16c) = 9;
            *(undefined1 *)(iRam00715298 + 0x161) = 0xf;
            *(undefined4 *)(iRam00715298 + 0x180) = 0;
            return 1;
          }
          if (iVar2 != 1) {
            return 1;
          }
LAB_006244b0:
          func_0x001f4770(*(undefined4 *)(iRam00715298 + 0x164),
                          *(undefined4 *)(iRam00715298 + 0x174));
          *(undefined4 *)(iRam00715298 + 0x16c) = 0x61;
          *(undefined1 *)(iRam00715298 + 0x161) = 5;
          *(undefined4 *)(iRam00715298 + 0x180) = 0;
          return 1;
        }
        *(undefined4 *)(iRam00715298 + 0x16c) = 0x6a;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
        *(undefined4 *)(iRam00715298 + 0x180) = 6;
      }
    }
  }
  else {
    if (cVar1 == '\x0f') {
      lVar3 = func_0x001f5620();
      if (lVar3 == -1) {
LAB_00624378:
        *(undefined4 *)(iRam00715298 + 0x188) = uRam0027e570;
        return 1;
      }
      if (lVar3 == -0xfe) {
        *(undefined4 *)(iRam00715298 + 0x16c) = 0x91;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
        *(undefined4 *)(iRam00715298 + 0x180) = 2;
        goto LAB_00624778;
      }
      if (lVar3 == -0x100) {
        *(undefined4 *)(iRam00715298 + 0x16c) = 0x69;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
        *(undefined4 *)(iRam00715298 + 0x180) = 0;
        goto LAB_00624778;
      }
      if (lVar3 == 0) {
        func_0x001f5650();
        *(undefined4 *)(iRam00715298 + 0x16c) = 10;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x5b;
        *(undefined4 *)(iRam00715298 + 0x180) = 0;
        *(undefined4 *)(iRam00715298 + 0x184) = 2;
        goto LAB_00624378;
      }
      *(undefined4 *)(iRam00715298 + 0x16c) = 0x69;
    }
    else {
      if (cVar1 != '\n') {
        if (cVar1 == '\x05') {
          lVar3 = func_0x001f5620();
          if (lVar3 == -1) {
LAB_00624114:
            *(undefined4 *)(iRam00715298 + 0x188) = uRam0027e570;
            return 1;
          }
          if (lVar3 == -0x100) {
            *(undefined4 *)(iRam00715298 + 0x16c) = 99;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
            *(undefined4 *)(iRam00715298 + 0x180) = 0;
          }
          else if (lVar3 == 0) {
            lVar3 = FUN_00624800();
            if (lVar3 == 0) {
              func_0x001f5650();
              *(undefined4 *)(iRam00715298 + 0x16c) = 0x62;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x5b;
              *(undefined4 *)(iRam00715298 + 0x180) = 0;
              *(undefined4 *)(iRam00715298 + 0x184) = 2;
              goto LAB_00624114;
            }
            *(undefined4 *)(iRam00715298 + 0x16c) = 99;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
            *(undefined4 *)(iRam00715298 + 0x180) = 0;
          }
          else {
            *(undefined4 *)(iRam00715298 + 0x16c) = 99;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
            *(uint *)(iRam00715298 + 0x180) = (uint)lVar3 & 0xff;
            iVar2 = *(int *)(iRam00715298 + 0x180);
            if (iVar2 == 4) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 4;
              func_0x001f46e0();
            }
            else if (iVar2 == 3) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 2;
              func_0x001f46e0();
            }
            else if (iVar2 == 2) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 3;
              func_0x001f46e0();
            }
            else if (iVar2 == 1) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 4;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
              *(undefined4 *)(iRam00715298 + 0x180) = 5;
              func_0x001f46e0();
            }
          }
        }
        else {
          if (cVar1 != '\x01') {
            if (cVar1 != '\0') {
              return 1;
            }
            *(short *)(iRam00715298 + 0x7a) = (short)*(undefined4 *)(iRam00715298 + 0x17c);
            *(char *)(iRam00715298 + 0x161) = *(char *)(iRam00715298 + 0x161) + '\x01';
            *(undefined4 *)(iRam00715298 + 0x16c) = 2;
            func_0x001f4980(*(undefined4 *)(iRam00715298 + 0x164),
                            *(undefined4 *)(iRam00715298 + 0x170),0);
            *(undefined4 *)(iRam00715298 + 0x184) = 0x3c;
          }
          lVar3 = func_0x001f5620();
          if (lVar3 == -1) {
            return 1;
          }
          if (lVar3 == 0) {
            *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
            *(undefined4 *)(iRam00715298 + 0x180) = 1;
            func_0x001f46e0();
            return 1;
          }
          if (lVar3 == -0xfb) {
            *(undefined4 *)(iRam00715298 + 0x16c) = 99;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
            *(undefined4 *)(iRam00715298 + 0x180) = 0xffffffff;
          }
          else if (lVar3 == -0x100) {
            *(undefined4 *)(iRam00715298 + 0x16c) = 0xaa;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
            *(undefined4 *)(iRam00715298 + 0x180) = 0xffffffff;
          }
          else if (lVar3 == -0xfe) {
            *(undefined4 *)(iRam00715298 + 0x16c) = 5;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
            *(undefined4 *)(iRam00715298 + 0x180) = 3;
            func_0x001f46e0();
          }
          else if (lVar3 == -0xfd) {
            *(undefined4 *)(iRam00715298 + 0x16c) = 5;
            *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
            *(undefined4 *)(iRam00715298 + 0x180) = 2;
            func_0x001f46e0();
          }
          else {
            *(uint *)(iRam00715298 + 0x180) = (uint)lVar3 & 0xff;
            *(undefined1 *)(iRam00715298 + 0x161) = 99;
            iVar2 = *(int *)(iRam00715298 + 0x180);
            if (iVar2 == 4) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 4;
              func_0x001f46e0();
            }
            else if (iVar2 == 3) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 2;
              func_0x001f46e0();
            }
            else if (iVar2 == 2) {
              *(undefined4 *)(iRam00715298 + 0x16c) = 5;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x14;
              *(undefined4 *)(iRam00715298 + 0x180) = 3;
              func_0x001f46e0();
            }
            else {
              if (iVar2 != 1) {
                return 1;
              }
              *(undefined4 *)(iRam00715298 + 0x16c) = 4;
              *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
              *(undefined4 *)(iRam00715298 + 0x180) = 5;
              func_0x001f46e0();
            }
          }
        }
        goto LAB_00624778;
      }
      lVar3 = func_0x001f5620();
      if (lVar3 == -1) {
LAB_0062426c:
        *(undefined4 *)(iRam00715298 + 0x188) = uRam0027e570;
        return 1;
      }
      if (lVar3 == -0x100) {
        *(undefined4 *)(iRam00715298 + 0x16c) = 0x8c;
        *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
        *(undefined4 *)(iRam00715298 + 0x180) = 0;
        goto LAB_00624778;
      }
      if (lVar3 == 0) {
        FUN_006247c0();
        func_0x001f4ca0(*(undefined4 *)(iRam00715298 + 0x164),*(undefined4 *)(iRam00715298 + 0x170))
        ;
        *(undefined4 *)(iRam00715298 + 0x16c) = 9;
        *(undefined1 *)(iRam00715298 + 0x161) = 0xf;
        *(undefined4 *)(iRam00715298 + 0x180) = 0;
        goto LAB_0062426c;
      }
      *(undefined4 *)(iRam00715298 + 0x16c) = 0x8c;
    }
    *(undefined1 *)(iRam00715298 + 0x161) = 0x1e;
    *(uint *)(iRam00715298 + 0x180) = (uint)lVar3 & 0xff;
    iVar2 = *(int *)(iRam00715298 + 0x180);
    if (iVar2 == 4) {
      *(undefined4 *)(iRam00715298 + 0x16c) = 0x67;
    }
    else if (iVar2 == 3) {
      *(undefined4 *)(iRam00715298 + 0x16c) = 5;
    }
    else if (iVar2 == 2) {
      *(undefined4 *)(iRam00715298 + 0x16c) = 0x91;
    }
    else if (iVar2 == 1) {
      *(undefined4 *)(iRam00715298 + 0x16c) = 4;
    }
  }
LAB_00624778:
  *(undefined1 *)(iRam00715298 + 0x29) = 1;
  *(undefined2 *)(iRam00715298 + 6) = 4;
  FUN_0061f2d0(0,2);
  return 1;
}



================================================================