FUNCTION FUN_0000dfe4 @ 0x0000dfe4 size=168
CALLERS (1): FUN_00010cbc@0x00010cbc
CALLEES (3): FUN_0000ad44@0x0000ad44, FUN_0000e08c@0x0000e08c, FUN_00014e24@0x00014e24

undefined4 FUN_0000dfe4(short param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  sVar2 = FUN_0000e08c((int)param_1);
  iVar1 = DAT_00016180;
  uVar3 = 0xfffffffc;
  if (sVar2 == 0) {
    iVar5 = DAT_00016180 + param_1 * 0x17c;
    uVar4 = DAT_00016178 & 2;
    *(undefined2 *)(iVar5 + 0x13a) = 0;
    if (uVar4 != 0) {
      FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_Delete)\n",(iVar5 - iVar1) * -0x2b1da461 >> 2
                  );
    }
    *(byte *)(iVar5 + 0x13f) = *(byte *)(iVar5 + 0x13f) | 0x80;
    FUN_0000ad44();
    uVar3 = 0;
  }
  return uVar3;
}


================================================================