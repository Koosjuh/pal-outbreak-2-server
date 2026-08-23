FUNCTION FUN_00000fe4 @ 0x00000fe4 size=436
CALLERS (1): FUN_00007974@0x00007974
CALLEES (7): FUN_00000d10@0x00000d10, FUN_0000134c@0x0000134c, FUN_00008ddc@0x00008ddc, FUN_000091c8@0x000091c8, FUN_000090a8@0x000090a8, FUN_00001284@0x00001284, FUN_000012fc@0x000012fc

int FUN_00000fe4(undefined4 param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort local_30;
  byte local_2e [6];
  
  iVar1 = FUN_00000d10();
  if (-1 < iVar1) {
    FUN_00001284(&DAT_0000b208);
    iVar2 = FUN_00008ddc(param_1,0x602,0x1ff);
    if (iVar2 < 0) {
      iVar1 = -3;
      if (iVar2 == -5) {
        iVar1 = -0x12;
      }
    }
    else {
      iVar3 = 0;
      iVar1 = 0;
      while (param_3 != 0) {
        if (param_3 < 2) {
          iVar4 = iVar3 + 1;
          local_2e[0] = FUN_000012fc(*(undefined1 *)param_2,(&DAT_0000b1f0)[iVar3]);
          iVar3 = 0;
          if (iVar4 != 0x18) {
            iVar3 = iVar4;
          }
          local_2e[0] = ~local_2e[0];
          iVar4 = FUN_000090a8(iVar2,local_2e,1);
          param_3 = param_3 + -1;
          if (iVar4 < 0) goto LAB_0000113c;
          iVar1 = iVar1 + 1;
        }
        else {
          iVar4 = iVar3 + 1;
          local_30 = FUN_0000134c(*param_2,(&DAT_0000b1f0)[iVar3]);
          iVar3 = 0;
          if (iVar4 != 0x18) {
            iVar3 = iVar4;
          }
          local_30 = ~local_30;
          iVar4 = FUN_000090a8(iVar2,&local_30,2);
          param_2 = param_2 + 1;
          if (iVar4 < 0) {
LAB_0000113c:
            FUN_000091c8(iVar2);
            if (iVar4 == -5) {
              return -0x12;
            }
            return -5;
          }
          param_3 = param_3 + -2;
          iVar1 = iVar1 + 2;
        }
      }
      FUN_000091c8(iVar2);
    }
  }
  return iVar1;
}


================================================================