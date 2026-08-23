FUNCTION FUN_00634970 @ 0x00634970  size=200
CALLERS (7): FUN_00636f90@0x00636f90, FUN_006345e0@0x006345e0, FUN_00635cb0@0x00635cb0, FUN_006352e0@0x006352e0, FUN_006353e0@0x006353e0, FUN_00634ab0@0x00634ab0, FUN_00635f80@0x00635f80
CALLEES (0): 
----------------------------------------------------------------

ushort FUN_00634970(ushort param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = param_2 & 0xedf;
  if ((param_2 & 0xedf) == 0) {
    if ((param_1 & 0xedf) == 0) {
      uVar1 = 0;
      *(undefined2 *)(iRam00715da8 + 0x1a) = 0;
    }
    else {
      *(char *)(iRam00715da8 + 0x1c) = *(char *)(iRam00715da8 + 0x1c) + -1;
      uVar1 = 0;
      if (*(char *)(iRam00715da8 + 0x1c) < '\x01') {
        *(undefined1 *)(iRam00715da8 + 0x1c) = 2;
        uVar1 = *(ushort *)(iRam00715da8 + 0x1a) & param_1 & 0xedf;
        *(ushort *)(iRam00715da8 + 0x1a) = uVar1;
      }
    }
  }
  else {
    *(ushort *)(iRam00715da8 + 0x1a) = uVar1;
    *(undefined1 *)(iRam00715da8 + 0x1c) = 10;
  }
  return uVar1;
}



================================================================