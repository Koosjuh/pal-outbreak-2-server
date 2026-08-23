FUNCTION FUN_00002198 @ 0x00002198 size=164
CALLERS (2): FUN_00002394@0x00002394, FUN_0000223c@0x0000223c
CALLEES (0): 

byte * FUN_00002198(int param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (DAT_0001618c != 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 >> 0xb;
      bVar1 = (&DAT_000187a0)[iVar2];
      if (((bVar1 & param_2) != 0) && (*(int *)((int)&DAT_000187b4 + iVar2) == param_1)) {
        if ((bVar1 & 2) == 0) {
          if ((bVar1 & 1) != 0) {
            (&DAT_000187b0)[iVar2] = 3;
          }
        }
        else {
          (&DAT_000187b0)[iVar2] = 0x14;
        }
        return &DAT_000187a0 + iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
  }
  return (byte *)0x0;
}


================================================================