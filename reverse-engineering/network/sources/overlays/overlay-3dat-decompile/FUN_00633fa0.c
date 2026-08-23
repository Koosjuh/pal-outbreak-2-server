FUNCTION FUN_00633fa0 @ 0x00633fa0  size=112
CALLERS (2): FUN_00635cb0@0x00635cb0, FUN_00631bb0@0x00631bb0
CALLEES (1): FUN_00637d10@0x00637d10
----------------------------------------------------------------

undefined8 FUN_00633fa0(short *param_1,int param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  uVar1 = 0;
  iVar2 = 0;
  while( true ) {
    if ((*param_1 == 0) || (param_2 <= iVar2)) break;
    FUN_00637d10(*param_1,auStack_4);
    uVar1 = func_0x001af420(auStack_4);
    iVar2 = iVar2 + (int)uVar1;
    param_1 = param_1 + 1;
  }
  return uVar1;
}



================================================================