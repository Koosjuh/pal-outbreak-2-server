FUNCTION FUN_005de660 @ 0x005de660  size=204
CALLERS (1): FUN_005d8340@0x005d8340
CALLEES (0): 
----------------------------------------------------------------

undefined * FUN_005de660(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_1 == 2) {
    if (cRam0035ba80 == '\x05') {
      puVar1 = (&PTR_PTR_00645920)[param_2];
    }
    else if (cRam0035ba80 == '\x04') {
      puVar1 = (&PTR_PTR_00644f10)[param_2];
    }
    else if (cRam0035ba80 == '\x03') {
      puVar1 = (&PTR_PTR_006462a0)[param_2];
    }
    else if (cRam0035ba80 == '\x02') {
      puVar1 = (&PTR_PTR_00644600)[param_2];
    }
    else {
      puVar1 = (&PTR_PTR_00643bb0)[param_2];
    }
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



================================================================