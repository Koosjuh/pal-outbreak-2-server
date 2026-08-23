FUNCTION FUN_005bdd90 @ 0x005bdd90  size=260
CALLERS (1): FUN_005b3790@0x005b3790
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bdd90(byte param_1,int param_2,code *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  if (cRam006cbacc == '\0') {
    func_0x00106b60(0x6fe8e9,0,1);
    func_0x00106b60(0x6fc184,0,0x154);
    if (1 < param_1) {
      param_1 = 1;
    }
    bRam006fc184 = param_1;
    bRam006fe8e8 = param_1;
    iVar2 = 0;
    while( true ) {
      if ((int)(uint)param_1 <= iVar2) break;
      *(undefined1 *)(iVar2 + 0x6fe8e9) = *(undefined1 *)(param_2 + iVar2);
      iVar2 = iVar2 + 1;
    }
    auStack_10[0] = 0;
    cRam006cbacc = '\0';
    uRam006cbac8 = 0;
    pcRam006cbaac = param_3;
    (*param_3)(auStack_10,auStack_10);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================