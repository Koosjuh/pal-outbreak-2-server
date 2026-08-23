FUNCTION FUN_0000edbc @ 0x0000edbc size=272
CALLERS (2): FUN_00004a30@0x00004a30, FUN_000113a8@0x000113a8
CALLEES (0): 

undefined4 FUN_0000edbc(int param_1,undefined4 param_2,int param_3,char param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = &DAT_000183f0;
  iVar3 = 0;
  if (DAT_0001619a != 0) {
    iVar2 = 0;
    do {
      sVar1 = (short)iVar3;
      iVar2 = iVar2 >> 0x10;
      if (((&DAT_000183f0)[iVar2 * 7] == param_1) && ((&DAT_000183f8)[iVar2 * 7] == param_3)) {
        if (param_4 == '\x01') {
LAB_0000ee40:
          if ((&DAT_00018409)[iVar2 * 0x1c] != '\x01') goto LAB_0000ee64;
        }
        else if ((&DAT_00018409)[iVar2 * 0x1c] == '\x01') {
          if (param_4 != '\x01') goto LAB_0000ee64;
          goto LAB_0000ee40;
        }
        if (((&DAT_000183fe)[iVar2 * 0xe] & 1) != 0) {
          puVar4 = &DAT_000183f0 + sVar1 * 7;
          break;
        }
      }
LAB_0000ee64:
      iVar3 = iVar3 + 1;
      sVar1 = (short)iVar3;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
    if (sVar1 < (short)(ushort)DAT_0001619a) {
      *(undefined2 *)((int)puVar4 + 0xe) = 0;
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================