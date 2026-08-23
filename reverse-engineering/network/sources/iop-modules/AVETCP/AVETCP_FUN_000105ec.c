FUNCTION FUN_000105ec @ 0x000105ec size=168
CALLERS (4): FUN_0000c428@0x0000c428, FUN_0000decc@0x0000decc, FUN_000097cc@0x000097cc, FUN_00007000@0x00007000
CALLEES (3): FUN_000120e0@0x000120e0, FUN_00000138@0x00000138, FUN_0000db74@0x0000db74

undefined4 FUN_000105ec(short param_1,int param_2,short param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = (int)param_1;
    if ((&DAT_00018838)[iVar2 * 3] != -1) {
      *(short *)(&DAT_00018832 + iVar2 * 0xc) = param_3;
      *(short *)(&DAT_00018830 + iVar2 * 0xc) = param_1;
      FUN_000120e0((&DAT_00018838)[iVar2 * 3]);
    }
  }
  else {
    uVar1 = FUN_00000138((int)param_1,param_2,(int)param_3);
    FUN_0000db74((int)param_1,uVar1);
  }
  return 0;
}


================================================================