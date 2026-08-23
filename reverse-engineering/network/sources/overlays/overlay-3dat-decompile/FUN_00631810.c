FUNCTION FUN_00631810 @ 0x00631810  size=104
CALLERS (1): FUN_00631790@0x00631790
CALLEES (2): FUN_006341d0@0x006341d0, FUN_00637e90@0x00637e90
----------------------------------------------------------------

void FUN_00631810(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00637e90();
  uVar2 = FUN_006341d0(param_1,param_2);
  if ((uVar2 & 0xffff) < (uVar1 & 0xffff)) {
    *(undefined2 *)((int)param_1 + (uVar2 & 0xffff) * 2) = 0;
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  }
  return;
}



================================================================