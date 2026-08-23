FUNCTION FUN_00616318 @ 0x00616318  size=228
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_00616318(uint param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0xffffffff;
  puVar2 = (undefined4 *)param_2;
  if (param_1 == 0xd) {
    if (pcRam0070f2c8 != (code *)0x0) {
      uVar1 = (*pcRam0070f2c8)(*puVar2,puVar2 + 5,(int)puVar2 + puVar2[1] + 0x14,puVar2 + 1,
                               puVar2[3],puVar2[4]);
    }
  }
  else if (param_1 < 0xe) {
    if (param_1 != 0xc) {
      *puVar2 = 0xffffffff;
      return param_2;
    }
    if (pcRam0070f2c4 != (code *)0x0) {
      uVar1 = (*pcRam0070f2c4)(puVar2 + 4,(int)puVar2 + puVar2[2] + 0x10,*puVar2,puVar2[1],
                               puVar2 + 1);
    }
  }
  else {
    if (param_1 != 0xe) {
      *puVar2 = 0xffffffff;
      return param_2;
    }
    if (pcRam0070f2cc != (code *)0x0) {
      uVar1 = (*pcRam0070f2cc)(*puVar2);
    }
  }
  *puVar2 = uVar1;
  return param_2;
}



================================================================