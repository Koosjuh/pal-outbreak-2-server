FUNCTION FUN_00012170 @ 0x00012170 size=1652
CALLERS (0): 
CALLEES (32): FUN_0000d464@0x0000d464, FUN_000199d4@0x000199d4, FUN_00019978@0x00019978, FUN_000198f4@0x000198f4, FUN_00011d90@0x00011d90, FUN_00012138@0x00012138, FUN_00018c08@0x00018c08, FUN_00015c18@0x00015c18, FUN_00019920@0x00019920, FUN_00019a40@0x00019a40, FUN_000198fc@0x000198fc, FUN_0000d508@0x0000d508, FUN_00019928@0x00019928, FUN_0001999c@0x0001999c, FUN_0000a5c8@0x0000a5c8, FUN_00006d98@0x00006d98, FUN_00000cac@0x00000cac, FUN_0000afa0@0x0000afa0, FUN_00019a08@0x00019a08, FUN_00019a20@0x00019a20, FUN_00019ac8@0x00019ac8, FUN_0000ae24@0x0000ae24, FUN_00017d10@0x00017d10, FUN_00019ad0@0x00019ad0, FUN_0000889c@0x0000889c, FUN_0001994c@0x0001994c, FUN_00011fb8@0x00011fb8, FUN_000199cc@0x000199cc, FUN_00011f48@0x00011f48, FUN_000199b4@0x000199b4, FUN_0000b4c4@0x0000b4c4, FUN_00019954@0x00019954

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00012170(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  byte *pbVar6;
  int *piVar7;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  if (param_1 < 0) {
    iVar3 = FUN_00011fb8();
    return iVar3;
  }
  FUN_00019978("INET (%s)",PTR_s_Version_2_25_0_0001b940);
  FUN_00019978(s_DEBUG_0001b8b4);
  iVar3 = FUN_00012138();
  pcVar5 = " (REMOVABLE)";
  if (iVar3 != 0) {
    pcVar5 = " REMOVABLE";
  }
  param_1 = param_1 + -1;
  FUN_00019978(pcVar5);
  piVar7 = (int *)(param_2 + 4);
  FUN_00019978(&DAT_0001b88c);
  DAT_0001b9dc = 0x20000;
  do {
    while( true ) {
      if (param_1 < 1) {
        FUN_00019978("inet: mem=%dKB",DAT_0001b9dc >> 10);
        FUN_00019978(" thpri=%d thstack=%d\n",DAT_0001b848,DAT_0001b84c);
        FUN_00019978("inet: debug=0x%x &debug=%p",DAT_0001b850,&DAT_0001b850);
        FUN_00019978(" &free_{size,min}=%p,%p",&DAT_0001b9d4,&DAT_0001b9d8);
        FUN_00019978(&DAT_0001b88c);
        FUN_00011f48();
        FUN_00019a40(&DAT_0001b310);
        FUN_0000afa0(DAT_0001b314 + DAT_0001b310 + DAT_0001b858);
        DAT_0001b2f0 = FUN_0000d464(FUN_0000da1c,0);
        if (0 < DAT_0001b2f0) {
          local_30 = 1;
          local_28 = 1;
          local_24 = 1;
          local_2c = 0;
          DAT_0001b2e8 = FUN_00019ac8(&local_30);
          if (DAT_0001b2e8 < 1) {
            FUN_00011d90("inet: CreatSema (%d)\n",DAT_0001b2e8);
          }
          else {
            DAT_0001b2ec = FUN_00019ac8(&local_30);
            if (DAT_0001b2ec < 1) {
              FUN_00011d90("inet: CreatSema (%d)\n",DAT_0001b2ec);
            }
            else {
              FUN_00019920(local_20);
              DAT_0001b9e4 = FUN_000198f4(0,DAT_0001b9dc,0);
              FUN_00019928(local_20[0]);
              if (DAT_0001b9e4 == 0) {
                FUN_00011d90("inet: AllocSysMemory\n");
              }
              else {
                FUN_0000ae24(DAT_0001b9e4,DAT_0001b9dc);
                FUN_0000a5c8(DAT_0001b9e4,DAT_0001b9dc);
                DAT_0001b2f8 = 1;
                ram0x0001b2e0 = DAT_0001b9e4;
                DAT_0001b2e4 = DAT_0001b9e4 + DAT_0001b9dc;
                iVar3 = FUN_0001994c(&DAT_00019780);
                if (iVar3 == 0) {
                  iVar3 = FUN_0001994c(&DAT_00019860);
                  if (iVar3 == 0) {
                    FUN_00017d10();
                    FUN_00000cac();
                    FUN_0000889c();
                    FUN_00018c08();
                    FUN_00015c18();
                    FUN_0000b4c4();
                    FUN_00006d98();
                    DAT_0001b2f4 = 1;
                    iVar3 = FUN_00012138();
                    return (uint)(iVar3 != 0) << 1;
                  }
                  FUN_00011d90("inet: RegisterLibraryEntries (netdev) -> %d\n",iVar3);
                  FUN_00019954(&DAT_00019780);
                }
                else {
                  FUN_00011d90("inet: RegisterLibraryEntries (inet) -> %d\n",iVar3);
                }
                FUN_00019920(local_20);
                FUN_000198fc(DAT_0001b9e4);
                FUN_00019928(local_20[0]);
              }
              FUN_00019ad0(DAT_0001b2ec);
            }
            FUN_00019ad0(DAT_0001b2e8);
          }
          FUN_00019a20(DAT_0001b2f0);
          FUN_00019a08(DAT_0001b2f0);
        }
        FUN_0000d508(&DAT_0001b308,1);
        FUN_0000d508(&DAT_0001b300,1);
        return 1;
      }
      iVar3 = FUN_000199cc(&DAT_0001b8bc,*piVar7,4);
      if (iVar3 != 0) {
        iVar3 = FUN_000199cc(s_thpri__0001b8cc,*piVar7,6);
        if (iVar3 == 0) {
          iVar3 = *piVar7;
          pcVar5 = (char *)(iVar3 + 6);
          uVar4 = FUN_0001999c((int)*(char *)(iVar3 + 6));
          if (((uVar4 & 4) == 0) ||
             (DAT_0001b848 = FUN_000199d4(pcVar5,0,10), 0x72 < DAT_0001b848 - 9U))
          goto LAB_00012238;
          if (*(char *)(iVar3 + 6) != '\0') {
            do {
              uVar4 = FUN_0001999c((int)*pcVar5);
              if ((uVar4 & 4) == 0) goto LAB_00012444;
              pcVar5 = pcVar5 + 1;
              cVar2 = '\0';
            } while (*pcVar5 != '\0');
            goto LAB_0001244c;
          }
        }
        else {
          iVar3 = FUN_000199cc("thstack=",*piVar7,8);
          if (iVar3 == 0) {
            iVar3 = *piVar7;
            pcVar5 = (char *)(iVar3 + 8);
            uVar4 = FUN_0001999c((int)*(char *)(iVar3 + 8));
            if ((uVar4 & 4) == 0) goto LAB_00012238;
            DAT_0001b84c = FUN_000199d4(pcVar5,0,10);
            cVar2 = *(char *)(iVar3 + 8);
            while ((cVar2 != '\0' && (uVar4 = FUN_0001999c((int)*pcVar5), (uVar4 & 4) != 0))) {
              pcVar5 = pcVar5 + 1;
              cVar2 = *pcVar5;
            }
            iVar3 = FUN_000199b4(pcVar5,&DAT_0001b8c4);
            if (iVar3 != 0) goto LAB_00012444;
            DAT_0001b84c = DAT_0001b84c << 10;
          }
          else {
            iVar3 = FUN_000199cc(s_debug__0001b8d4,*piVar7,6);
            if (iVar3 != 0) goto LAB_00012238;
            pbVar6 = (byte *)(*piVar7 + 6);
            bVar1 = *(byte *)(*piVar7 + 6);
            while (bVar1 != 0) {
              DAT_0001b850 = DAT_0001b850 << 4;
              bVar1 = *pbVar6;
              if (bVar1 - 0x30 < 10) {
                uVar4 = (int)(char)bVar1 - 0x30;
              }
              else {
                if (5 < (bVar1 - 0x61 & 0xff)) goto LAB_00012238;
                uVar4 = (int)(char)bVar1 - 0x57;
              }
              DAT_0001b850 = DAT_0001b850 | uVar4;
              pbVar6 = pbVar6 + 1;
              bVar1 = *pbVar6;
            }
          }
        }
        goto LAB_000124fc;
      }
      iVar3 = *piVar7;
      pcVar5 = (char *)(iVar3 + 4);
      uVar4 = FUN_0001999c((int)*(char *)(iVar3 + 4));
      if ((uVar4 & 4) == 0) goto LAB_00012238;
      DAT_0001b9dc = FUN_000199d4(pcVar5,0,10);
      cVar2 = *(char *)(iVar3 + 4);
      while ((cVar2 != '\0' && (uVar4 = FUN_0001999c((int)*pcVar5), (uVar4 & 4) != 0))) {
        pcVar5 = pcVar5 + 1;
        cVar2 = *pcVar5;
      }
      iVar3 = FUN_000199b4(pcVar5,&DAT_0001b8c4);
      if (iVar3 != 0) break;
      DAT_0001b9dc = DAT_0001b9dc << 10;
LAB_000124fc:
      param_1 = param_1 + -1;
      piVar7 = piVar7 + 1;
    }
    iVar3 = FUN_000199b4(pcVar5,&DAT_0001b8c8);
    if (iVar3 == 0) {
      DAT_0001b9dc = DAT_0001b9dc << 0x14;
      goto LAB_000124fc;
    }
LAB_00012444:
    cVar2 = *pcVar5;
LAB_0001244c:
    param_1 = param_1 + -1;
    if (cVar2 != '\0') {
LAB_00012238:
      FUN_00011d90("inet: invalid option (%s)\n",*piVar7);
      return 1;
    }
    piVar7 = piVar7 + 1;
  } while( true );
}


================================================================