
void FUN_001d3130(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = iRam003435bc;
  FUN_001a5440(0xc);
  FUN_001afc20();
  do {
    lVar2 = FUN_001afc40(param_1);
  } while (lVar2 == 0);
  if (-1 < lVar2) {
    FUN_001a56f0(iVar1,iRam003435bc + 0x4000,0xc);
  }
  return;
}

