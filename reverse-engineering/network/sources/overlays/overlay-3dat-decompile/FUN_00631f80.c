FUNCTION FUN_00631f80 @ 0x00631f80  size=104
CALLERS (1): FUN_00631030@0x00631030
CALLEES (2): FUN_006341d0@0x006341d0, FUN_00637e10@0x00637e10
----------------------------------------------------------------

ulong FUN_00631f80(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    uVar1 = FUN_006341d0(param_1,param_2 & 0xffff);
    *(undefined2 *)param_1 = 0;
    FUN_00637e10(param_1,(undefined2 *)param_1 + (uVar1 & 0xffff));
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  }
  return param_2;
}



================================================================