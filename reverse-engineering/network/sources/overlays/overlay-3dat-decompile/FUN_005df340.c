FUNCTION FUN_005df340 @ 0x005df340  size=692
CALLERS (2): FUN_005d7e00@0x005d7e00, FUN_005d7f80@0x005d7f80
CALLEES (9): FUN_005df110@0x005df110, FUN_005df780@0x005df780, FUN_005def30@0x005def30, FUN_005df640@0x005df640, FUN_005dee60@0x005dee60, FUN_005df0b0@0x005df0b0, FUN_005df170@0x005df170, FUN_005df060@0x005df060, FUN_005deea0@0x005deea0
----------------------------------------------------------------

long FUN_005df340(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  
  lVar5 = FUN_005df640(param_2);
  if (lVar5 == -1) {
    if ((param_1 == 0) || (*(char *)param_1 == '\0')) {
      param_1 = 0x6465a8;
    }
    lVar5 = FUN_005df170(param_1,iRam00701068 + 0x4cf5c,1);
    if (lVar5 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = FUN_005df170(lVar5,param_2,0);
      if (lVar5 == 0) {
        lVar5 = 0;
      }
      else {
        uVar6 = FUN_005dee60(lVar5);
        iVar2 = FUN_005def30(lVar5,uVar6);
        if (iVar2 == 0) {
          lVar5 = 0;
        }
        else {
          while (lVar7 = FUN_005df060(iVar2,uVar6), lVar7 != 0) {
            iVar4 = func_0x0010a050((int)lVar7 + 1);
            func_0x00106a58(lVar7,(int)lVar7 + 1,iVar4 + 1);
            uVar6 = FUN_005dee60(iVar2);
          }
          cVar1 = FUN_005df780(lVar5);
          if (cVar1 == '\x02') {
            while ((iVar4 = FUN_005df110(iVar2,uVar6), iVar4 != 0 && (iVar4 == iVar2))) {
              iVar3 = func_0x0010a050(iVar4 + 3);
              func_0x00106a58(iVar4,iVar4 + 3,iVar3 + 1);
              uVar6 = FUN_005dee60(iVar2);
            }
            while (lVar7 = FUN_005df110(iVar2,uVar6), lVar7 != 0) {
              iVar4 = (int)lVar7;
              lVar7 = FUN_005deea0(iVar2,iVar4 + -1);
              if (lVar7 == 0) {
                return 0;
              }
              iVar3 = func_0x0010a050(iVar4 + 3);
              func_0x00106a58(lVar7,iVar4 + 3,iVar3 + 1);
              uVar6 = FUN_005dee60(iVar2);
            }
          }
          else {
            while (iVar4 = FUN_005df110(iVar2,uVar6), iVar4 != 0) {
              if (iVar4 == iVar2) {
                iVar4 = func_0x0010a050(0x6465b8);
                iVar2 = iVar2 + iVar4;
              }
              else {
                lVar7 = FUN_005deea0(iVar2,iVar4 + -1);
                if (lVar7 == 0) {
                  return 0;
                }
                iVar3 = func_0x0010a050(iVar4 + 3);
                func_0x00106a58(lVar7,iVar4 + 3,iVar3 + 1);
              }
              uVar6 = FUN_005dee60(iVar2);
            }
            iVar2 = FUN_005def30(lVar5);
          }
          while (lVar7 = FUN_005df0b0(iVar2,uVar6), lVar7 != 0) {
            iVar4 = func_0x0010a050((int)lVar7 + 2);
            func_0x00106a58(lVar7,(int)lVar7 + 2,iVar4 + 1);
            uVar6 = FUN_005dee60(iVar2);
          }
        }
      }
    }
  }
  else {
    lVar5 = 0;
  }
  return lVar5;
}



================================================================