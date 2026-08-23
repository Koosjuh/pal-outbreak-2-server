FUNCTION FUN_005c2e90 @ 0x005c2e90  size=172
CALLERS (2): FUN_005c2f40@0x005c2f40, FUN_005c3b10@0x005c3b10
CALLEES (0): 
----------------------------------------------------------------

undefined * FUN_005c2e90(char param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (cRam0034359d == '\x05') {
    iVar2 = 4;
  }
  else if (cRam0034359d == '\x04') {
    iVar2 = 3;
  }
  else if (cRam0034359d == '\x03') {
    iVar2 = 2;
  }
  else if (cRam0034359d == '\x02') {
    iVar2 = 1;
  }
  if (param_1 == '\0') {
    puVar1 = (&PTR_s_No__of_Players_00640480)[iVar2];
  }
  else {
    puVar1 = (&PTR_s_defficulity_control_006404a0)[iVar2];
  }
  return puVar1;
}



================================================================