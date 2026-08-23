FUNCTION FUN_005e7e30 @ 0x005e7e30  size=1144
CALLERS (1): FUN_005de170@0x005de170
CALLEES (7): FUN_005da420@0x005da420, FUN_005da500@0x005da500, thunk_FUN_005c8ed0@0x005d89c0, FUN_005d8f90@0x005d8f90, FUN_005e7a30@0x005e7a30, FUN_005da370@0x005da370, FUN_005e7710@0x005e7710
----------------------------------------------------------------

undefined4 FUN_005e7e30(long param_1,undefined8 param_2,undefined1 param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uStack_8;
  undefined2 uStack_4;
  undefined1 uStack_2;
  
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    if (cRam007012a8 != '\x04') {
      if (cRam007012a8 != '\x03') {
        uVar3 = (undefined4)param_1;
        if (cRam007012a8 != '\x02') {
          if (cRam007012a8 != '\x01') {
            if (cRam007012a8 != '\0') {
              return 2;
            }
            iRam007012a0 = iRam00701068 + 0x1a000;
            func_0x00106b60(iRam007012a0,0,0xfbc4);
            *(undefined2 *)(iRam007012a0 + 0x182) = 0x248;
            *(undefined2 *)(iRam007012a0 + 0x10) = 0x248;
            *(undefined4 *)(iRam007012a0 + 0xd964) = uVar3;
            FUN_005e7710(0xfffffffffffffff6);
            *(undefined1 *)(iRam007012a0 + 0xe96b) = param_3;
            *(undefined2 *)(iRam007012a0 + 0xe97e) = 0x2e7;
            cRam007012a8 = '\x01';
          }
          lVar4 = FUN_005e7a30(param_2);
          if (0 < lVar4) {
            return 0;
          }
          if (*(ushort *)(iRam007012a0 + 0x182) < 0x248) {
            *(undefined2 *)(iRam007012a0 + 0x182) = 0x248;
          }
          func_0x00106b60(iRam007012a0 + 0x1540,0,4000);
          *(undefined2 *)(iRam007012a0 + 0x184) = 0x17c;
          *(undefined2 *)(iRam007012a0 + 0x10) = *(undefined2 *)(iRam007012a0 + 0x182);
          cRam007012a8 = '\x02';
          *(undefined4 *)(iRam007012a0 + 0xd964) = uVar3;
          FUN_005e7710(1);
        }
        lVar4 = FUN_005e7a30(param_2);
        if (0 < lVar4) {
          return 0;
        }
        cRam007012a8 = 3;
        *(undefined4 *)(iRam007012a0 + 0xd964) = uVar3;
        FUN_005e7710(0);
        return 1;
      }
      if (*(char *)(iRam007012a0 + 0xe96b) == '\0') {
        thunk_FUN_005c8ed0();
        FUN_005da370(*(undefined2 *)(iRam007012a0 + 0xe97e),iRam007012a0 + 0xe980,
                     *(undefined1 *)(iRam007012a0 + 0xfbc1),*(undefined1 *)(iRam007012a0 + 0xfbc2));
      }
      cRam007012a8 = '\x04';
    }
    sVar2 = 0;
    uStack_8 = DAT_00648240;
    uStack_4 = DAT_00648244;
    uStack_2 = DAT_00648246;
    lVar4 = FUN_005e7a30(param_2);
    if (lVar4 < 1) {
      if (((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 400) != '\0')) &&
         (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
        sVar2 = func_0x0010a050(&uStack_8);
        FUN_005d8f90(0x10,*(short *)(iRam007012a0 + 0x184),sVar2 * 8 + 0x18,
                     *(short *)(iRam007012a0 + 0x184) + 0x14,&uStack_8);
        sVar2 = 0x28;
      }
      if (*(char *)(iRam007012a0 + 0xe96b) == '\0') {
        FUN_005da420(*(undefined2 *)(iRam007012a0 + 0x10),*(short *)(iRam007012a0 + 0x184) + sVar2);
      }
      if (*(char *)(iRam007012a0 + 0x186) == '\0') {
        cVar1 = *(char *)(iRam007012a0 + 0x18e);
        if (cVar1 == '+') {
          FUN_005da500(9);
        }
        else if (cVar1 == '*') {
          FUN_005da500(8);
        }
        else if (cVar1 == ')') {
          FUN_005da500(7);
        }
        else if (cVar1 == '\x01') {
          FUN_005da500(6);
        }
        else if (cVar1 == '\a') {
          FUN_005da500(5);
        }
        else if (cVar1 == '\x06') {
          FUN_005da500(4);
        }
        else if (cVar1 == '\x04') {
          FUN_005da500(3);
        }
        else if (cVar1 == '\x03') {
          FUN_005da500(2);
        }
        else if (cVar1 == '\x13') {
          FUN_005da500();
        }
        else if (cVar1 == '\x12') {
          FUN_005da500(0);
        }
      }
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



================================================================