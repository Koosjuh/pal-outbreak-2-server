FUNCTION FUN_005d8340 @ 0x005d8340  size=1276
CALLERS (8): FUN_005ca640@0x005ca640, FUN_005c8ae0@0x005c8ae0, FUN_005c8d10@0x005c8d10, FUN_005cce30@0x005cce30, FUN_005cc980@0x005cc980, FUN_005c8bc0@0x005c8bc0, FUN_005ca560@0x005ca560, FUN_005c8e70@0x005c8e70
CALLEES (8): FUN_005dedc0@0x005dedc0, FUN_005d6ce0@0x005d6ce0, FUN_005de660@0x005de660, FUN_005d81b0@0x005d81b0, FUN_005d6920@0x005d6920, FUN_005d6710@0x005d6710, FUN_005d6c90@0x005d6c90, FUN_005d7a30@0x005d7a30
----------------------------------------------------------------

undefined4 FUN_005d8340(undefined4 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(iRam00701068 + 0x4f694);
  do {
    puVar5 = (undefined4 *)*puVar5;
    while( true ) {
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
      if (puVar5[0x41] == 0) {
        return 0;
      }
      lVar3 = func_0x0010a338(puVar5 + 1,*param_1,0x100);
      if (lVar3 != 0) break;
      if (puVar5[0x41] == 6) {
        if (*(char *)((int)puVar5 + 0x10d) == '\x02') {
          iVar1 = puVar5[0x45];
          iRam00701004 = 0;
          uRam00701008 = *(undefined1 *)(puVar5 + 0x49);
          uRam00701009 = *(undefined1 *)((int)puVar5 + 0x125);
          if (iVar1 != 0) {
            if (*(char *)(puVar5 + 0x49) == '\a') {
              if (*(int *)(iVar1 + 0x114) == 0) {
                FUN_005d6ce0();
              }
              else {
                *(undefined4 *)(iVar1 + 0x104) = 5;
              }
            }
            else {
              FUN_005d6ce0();
            }
          }
        }
        else {
          if (*(char *)((int)puVar5 + 0x10d) != '\x01') {
            iVar1 = puVar5[0x46];
            goto LAB_005d87fc;
          }
          uRam00700ff8 = 1;
          iVar1 = puVar5[0x45];
          switch(*(undefined1 *)(puVar5 + 0x49)) {
          default:
            iRam00701004 = 0;
            break;
          case 1:
            iRam00701004 = 0;
            break;
          case 2:
            iRam00701004 = 0;
            break;
          case 4:
            FUN_005d6920(iRam00701068 + 0x4f588,puVar5,iVar1 + 4);
            uRam00700ff8 = *(undefined1 *)((int)puVar5 + 0x125);
            if (*(char *)((int)puVar5 + 0x125) == '\x04') {
              func_0x001f1e40();
            }
            switch(*(undefined1 *)((int)puVar5 + 0x125)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
              uVar4 = FUN_005de660(2);
              FUN_005d81b0(iRam00701068 + 0x4d15c,uVar4,0x200);
            }
            iRam00701004 = iRam00701068 + 0x4d15c;
            break;
          case 5:
            iRam00701004 = 0;
            break;
          case 7:
            iRam00701004 = 0;
            break;
          case 8:
            FUN_005d6920(iRam00701068 + 0x4f588,puVar5,0);
            uVar4 = FUN_005de660(2,9);
            FUN_005d81b0(iRam00701068 + 0x4d15c,uVar4,0x200);
            iRam00701004 = iRam00701068 + 0x4d15c;
            break;
          case 9:
            FUN_005dedc0(iRam00701068 + 0x4d05c,*(undefined4 *)(iVar1 + 0x10c));
            iRam00701004 = iRam00701068 + 0x4d05c;
            break;
          case 10:
            iRam00701004 = 0;
            break;
          case 0xb:
            iRam00701004 = 0;
          }
          uRam00701008 = *(undefined1 *)(puVar5 + 0x49);
          uRam00701009 = *(undefined1 *)((int)puVar5 + 0x125);
          if (iVar1 != 0) {
            FUN_005d6c90(iVar1);
          }
        }
        iVar1 = puVar5[0x46];
LAB_005d87fc:
        if (iVar1 != 0) {
          func_0x01212a50();
          puVar5[0x46] = 0;
        }
        FUN_005d6710(puVar5);
        return 0x701004;
      }
      if (puVar5[0x41] == 5) {
        if (*(char *)((int)puVar5 + 0x10d) == '\x02') {
          iVar1 = puVar5[0x45];
          if (*(int *)(iVar1 + 0x104) == 3) {
            *(undefined4 *)(iVar1 + 0x10c) = puVar5[0x47];
            *(undefined4 *)(iVar1 + 0x110) = puVar5[0x48];
            uVar2 = *(undefined1 *)((int)puVar5 + 0x109);
            *(undefined1 *)(iVar1 + 0x108) = *(undefined1 *)(puVar5 + 0x42);
            *(undefined1 *)(iVar1 + 0x109) = uVar2;
            uVar2 = FUN_005d7a30(iVar1);
            *(undefined1 *)(puVar5 + 0x49) = uVar2;
            if (*(char *)(puVar5 + 0x49) != '\0') {
              puVar5[0x41] = 6;
              *(undefined1 *)((int)puVar5 + 0x125) = 0;
              return 0;
            }
            func_0x01212a50(puVar5[0x46]);
            puVar5[0x46] = 0;
            *(undefined4 *)(iVar1 + 0x104) = 2;
            return 0;
          }
          iRam00701004 = iVar1 + 0x114;
          uVar2 = *(undefined1 *)((int)puVar5 + 0x109);
          *(undefined1 *)(iVar1 + 0x108) = *(undefined1 *)(puVar5 + 0x42);
          *(undefined1 *)(iVar1 + 0x109) = uVar2;
          *(undefined4 *)(iVar1 + 0x104) = 5;
          uRam00701008 = *(undefined1 *)(puVar5 + 0x49);
          uRam00701009 = *(undefined1 *)((int)puVar5 + 0x125);
          uRam0070100a = *(undefined2 *)(iVar1 + 0x118);
          uRam0070100c = *(undefined2 *)(iVar1 + 0x11a);
        }
        else if (*(char *)((int)puVar5 + 0x10d) == '\x01') {
          iVar1 = puVar5[0x45];
          if (*(char *)((int)puVar5 + 0x125) == '\t') {
            uRam00700ff8 = 8;
          }
          if (*(int *)(iVar1 + 0x104) == 3) {
            *(undefined4 *)(iVar1 + 0x110) = puVar5[0x48];
            uVar2 = *(undefined1 *)((int)puVar5 + 0x109);
            *(undefined1 *)(iVar1 + 0x108) = *(undefined1 *)(puVar5 + 0x42);
            *(undefined1 *)(iVar1 + 0x109) = uVar2;
            func_0x01212a50(puVar5[0x46]);
            puVar5[0x46] = 0;
          }
          FUN_005d6920(iRam00701068 + 0x4f588,puVar5,iVar1 + 4);
          *(undefined4 *)(iVar1 + 0x104) = 5;
          iRam00701004 = *(int *)(iVar1 + 0x10c);
          uRam00701008 = *(undefined1 *)(puVar5 + 0x49);
          uRam00701009 = *(undefined1 *)((int)puVar5 + 0x125);
          uRam0070100a = 0;
          uRam0070100c = 0;
        }
        FUN_005d6710(puVar5);
        return 0x701004;
      }
      puVar5 = (undefined4 *)*puVar5;
    }
  } while( true );
}



================================================================