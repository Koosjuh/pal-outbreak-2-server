FUNCTION FUN_000175cc @ 0x000175cc size=1024
CALLERS (1): FUN_0000da1c@0x0000da1c
CALLEES (7): FUN_00011d90@0x00011d90, FUN_00019a48@0x00019a48, FUN_00019a40@0x00019a40, FUN_0000d658@0x0000d658, FUN_00019a58@0x00019a58, FUN_00019a60@0x00019a60, FUN_00019a50@0x00019a50

void FUN_000175cc(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20 [4];
  
  bVar1 = false;
  local_28 = 0xffffffff;
  do {
    iVar2 = FUN_0000d658(&DAT_0001e410,&local_28);
    if (iVar2 < 0) {
      FUN_00011d90("inet: sleep_wchans (%d)\n",iVar2);
    }
    FUN_00019a40(&local_30);
    if (DAT_0001e418 != 0) {
      FUN_00019a50(FUN_000175ac,&DAT_0001e410);
      DAT_0001e418 = 0;
    }
    uVar6 = 0;
    if (bVar1) {
      local_2c = local_2c - local_34;
      if (local_30 < local_38) {
        local_2c = local_2c + -1;
      }
      local_30 = local_30 - local_38;
      FUN_00019a60(&local_30,&local_24,local_20);
      uVar6 = local_24 * 1000 + (local_20[0] + 500) / 1000;
      if ((int)uVar6 < 1) {
        uVar6 = 0;
      }
    }
    piVar7 = DAT_0001e41c;
    if (DAT_0001e41c != (int *)0x0) {
      do {
        iVar2 = (int)uVar6 >> 0x1f;
        if ((int)uVar6 < 1) break;
        if ((iVar2 < piVar7[3]) || ((piVar7[3] == iVar2 && (uVar6 < (uint)piVar7[2])))) {
          uVar3 = piVar7[2];
          piVar7[2] = uVar3 - uVar6;
          piVar7[3] = (piVar7[3] - iVar2) - (uint)(uVar3 < uVar6);
        }
        else {
          iVar2 = piVar7[2];
          piVar7[2] = 0;
          piVar7[3] = 0;
          uVar6 = uVar6 - iVar2;
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
      while (((piVar7 = DAT_0001e41c, DAT_0001e41c != (int *)0x0 && (DAT_0001e41c[3] < 1)) &&
             ((DAT_0001e41c[3] != 0 || (DAT_0001e41c[2] == 0))))) {
        piVar4 = (int *)*DAT_0001e41c;
        if (piVar4 == (int *)0x0) {
          DAT_0001e420 = (int *)0x0;
          DAT_0001e41c = piVar4;
        }
        else {
          iVar2 = *DAT_0001e41c;
          DAT_0001e41c = piVar4;
          *(undefined4 *)(iVar2 + 4) = 0;
        }
        (*(code *)piVar7[4])(piVar7[5]);
        *piVar7 = (int)DAT_0001e424;
        DAT_0001e424 = piVar7;
      }
    }
LAB_00017914:
    piVar7 = DAT_0001e428;
    if (DAT_0001e428 != (int *)0x0) {
      DAT_0001e428 = (int *)*DAT_0001e428;
      if (DAT_0001e428 == (int *)0x0) {
        DAT_0001e42c = 0;
        piVar4 = DAT_0001e41c;
      }
      else {
        DAT_0001e428[1] = 0;
        piVar4 = DAT_0001e41c;
      }
      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if ((piVar7[3] < piVar4[3]) ||
           ((piVar4[3] == piVar7[3] && ((uint)piVar7[2] < (uint)piVar4[2])))) {
          if (piVar4 != (int *)0x0) {
            puVar5 = (undefined4 *)piVar4[1];
            piVar7[1] = (int)puVar5;
            if (puVar5 == (undefined4 *)0x0) {
              DAT_0001e41c = piVar7;
            }
            else {
              *puVar5 = piVar7;
            }
            *piVar7 = (int)piVar4;
            uVar6 = piVar4[2];
            piVar4[1] = (int)piVar7;
            uVar3 = piVar7[2];
            iVar2 = piVar7[3];
            piVar4[2] = uVar6 - uVar3;
            piVar4[3] = (piVar4[3] - iVar2) - (uint)(uVar6 < uVar3);
            goto LAB_00017914;
          }
          break;
        }
        uVar6 = piVar7[2];
        uVar3 = piVar4[2];
        iVar2 = piVar4[3];
        piVar7[2] = uVar6 - uVar3;
        piVar7[3] = (piVar7[3] - iVar2) - (uint)(uVar6 < uVar3);
      }
      piVar7[1] = (int)DAT_0001e420;
      if (DAT_0001e420 == (int *)0x0) {
        DAT_0001e41c = piVar7;
      }
      else {
        *DAT_0001e420 = (int)piVar7;
      }
      DAT_0001e420 = piVar7;
      *piVar7 = 0;
      goto LAB_00017914;
    }
    bVar1 = false;
    if (DAT_0001e41c != (int *)0x0) {
      iVar2 = DAT_0001e41c[2];
      if (1000 < iVar2) {
        iVar2 = 1000;
      }
      FUN_00019a58(iVar2 * 1000,&local_30);
      FUN_00019a40(&local_38);
      bVar1 = true;
      iVar2 = FUN_00019a48(&local_30,FUN_000175ac,&DAT_0001e410);
      if (iVar2 != 0) {
        FUN_00011d90("inet: SetAlarm (%d)\n",iVar2);
        return;
      }
      DAT_0001e418 = 1;
    }
  } while( true );
}


================================================================