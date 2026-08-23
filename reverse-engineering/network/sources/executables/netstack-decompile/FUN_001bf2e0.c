
void FUN_001bf2e0(undefined2 *param_1,undefined2 *param_2,ushort *param_3,undefined2 *param_4)

{
  undefined1 auStack_20 [8];
  int iStack_18;
  
  *param_1 = (short)piRam0035c3d8[2];
  *param_2 = (short)piRam0035c3d8[3];
  *param_3 = uRam0036d560 & 1;
  *param_4 = 0;
  if ((*piRam0035c3d8 == 3) || (*piRam0035c3d8 == 2)) {
    FUN_001eeb50(auStack_20);
    *param_4 = (short)(iStack_18 / 100);
  }
  return;
}

