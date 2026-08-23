FUNCTION FUN_005c7ff0 @ 0x005c7ff0  size=148
CALLERS (3): FUN_005c7f20@0x005c7f20, FUN_005c5780@0x005c5780, FUN_005c7e30@0x005c7e30
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c7ff0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (cRam0034359d == '\x05') {
    iVar1 = 4;
  }
  else if (cRam0034359d == '\x04') {
    iVar1 = 3;
  }
  else if (cRam0034359d == '\x03') {
    iVar1 = 2;
  }
  else if (cRam0034359d == '\x02') {
    iVar1 = 1;
  }
  else if (cRam0034359d != '\x01') {
    iVar1 = 0;
  }
  return *(undefined4 *)((&PTR_PTR_00642bb0)[iVar1] + (param_1 & 0xff) * 4);
}



================================================================