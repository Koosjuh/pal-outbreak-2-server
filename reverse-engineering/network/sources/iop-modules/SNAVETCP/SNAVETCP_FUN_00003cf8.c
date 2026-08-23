FUNCTION FUN_00003cf8 @ 0x00003cf8 size=328
CALLERS (1): FUN_00001ab0@0x00001ab0
CALLEES (1): FUN_0001168c@0x0001168c

undefined4 FUN_00003cf8(short param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (DAT_0001617e != 0) {
    iVar1 = 0;
    do {
      iVar2 = DAT_000161a0 + (iVar1 >> 0x10) * 0x30;
      if (((*(short *)(iVar2 + 8) != 0) && (*(char *)(iVar2 + 0x14) != '\0')) &&
         (param_2 == *(int *)(iVar2 + 0x18))) {
        if (*(char *)(iVar2 + 0x15) == '\0') {
          if ((byte)(param_3 - 1U) < 2) {
            uVar3 = *(undefined4 *)(iVar2 + 0x28);
            uVar4 = 0x80;
            goto LAB_00003dec;
          }
        }
        else if ((param_1 == *(short *)(iVar2 + 0xe)) && ((param_3 == '\x03' || (param_3 == '\0'))))
        {
          uVar3 = *(undefined4 *)(iVar2 + 0x28);
          uVar4 = 0x81;
LAB_00003dec:
          FUN_0001168c(iVar1 >> 0x10,uVar3,2,uVar4);
        }
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar5 * 0x10000;
    } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_0001617e);
  }
  return 0;
}


================================================================