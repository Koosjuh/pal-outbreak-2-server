FUNCTION FUN_00607a10 @ 0x00607a10  size=164
CALLERS (3): FUN_00606fc0@0x00606fc0, FUN_00607260@0x00607260, FUN_00607370@0x00607370
CALLEES (5): FUN_00607bd0@0x00607bd0, FUN_00607b10@0x00607b10, FUN_00607ac0@0x00607ac0, FUN_00607cf0@0x00607cf0, FUN_00607dc0@0x00607dc0
----------------------------------------------------------------

undefined8 FUN_00607a10(char *param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *param_1;
  if (cVar1 == '\x04') {
    uVar2 = FUN_00607dc0(0x6c4b90);
  }
  else if (cVar1 == '\x03') {
    uVar2 = FUN_00607cf0();
  }
  else if (cVar1 == '\x02') {
    uVar2 = FUN_00607bd0();
  }
  else if (cVar1 == '\x01') {
    uVar2 = FUN_00607b10();
  }
  else if (cVar1 == '\0') {
    uVar2 = FUN_00607ac0();
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  return uVar2;
}



================================================================