FUNCTION FUN_00007658 @ 0x00007658 size=580
CALLERS (1): FUN_00007b40@0x00007b40
CALLEES (2): FUN_00000944@0x00000944, FUN_00006f00@0x00006f00

int FUN_00007658(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0x150);
  if (piVar5 != (int *)0x0) {
    iVar4 = param_1 + 0x40;
    do {
      iVar2 = piVar5[2];
      bVar1 = false;
      if (iVar2 == 2) {
LAB_000076e8:
        iVar2 = FUN_00000944(iVar4,0x400,piVar5 + 3);
        if (iVar2 != 0) {
          return -1;
        }
        puVar3 = &DAT_0000a914;
        if (bVar1) {
          puVar3 = &DAT_0000a910;
        }
        iVar2 = FUN_00006f00(param_1,"nameserver %s %s\n",puVar3,iVar4);
      }
      else {
        if (iVar2 < 3) {
          if (iVar2 != 1) {
            return -1;
          }
          bVar1 = true;
          goto LAB_000076e8;
        }
        if (iVar2 == 3) {
          puVar3 = &DAT_0000a930;
          if ((piVar5[0x12] & 2U) != 0) {
            puVar3 = &DAT_0000a928;
          }
          iVar2 = FUN_00006f00(param_1,"route add -%s",puVar3);
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_00000944(iVar4,0x400,piVar5 + 3);
          if (iVar2 != 0) {
            return -1;
          }
          iVar2 = FUN_00006f00(param_1,&DAT_0000a6f4,iVar4);
          if (iVar2 < 0) {
            return iVar2;
          }
          if ((piVar5[0x12] & 4U) != 0) {
            iVar2 = FUN_00000944(iVar4,0x400,piVar5 + 8);
            if (iVar2 != 0) {
              return -1;
            }
            iVar2 = FUN_00006f00(param_1," gw %s",iVar4);
            if (iVar2 < 0) {
              return iVar2;
            }
          }
          iVar2 = FUN_00000944(iVar4,0x400,piVar5 + 0xd);
          if (iVar2 != 0) {
            return -1;
          }
          iVar2 = FUN_00006f00(param_1," netmask %s",iVar4);
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = FUN_00006f00(param_1,&DAT_0000a700);
        }
        else {
          if (iVar2 != 4) {
            return -1;
          }
          iVar2 = FUN_00000944(iVar4,0x400,piVar5 + 3);
          if (iVar2 != 0) {
            return -1;
          }
          iVar2 = FUN_00006f00(param_1,"route del %s\n",iVar4);
        }
      }
      if (iVar2 < 0) {
        return iVar2;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)0x0);
  }
  return 0;
}


================================================================