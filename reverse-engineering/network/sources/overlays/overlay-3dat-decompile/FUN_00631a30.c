FUNCTION FUN_00631a30 @ 0x00631a30  size=136
CALLERS (6): FUN_00630c90@0x00630c90, FUN_00636890@0x00636890, FUN_00631cf0@0x00631cf0, FUN_00631ac0@0x00631ac0, FUN_00631bb0@0x00631bb0, FUN_00631c80@0x00631c80
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00631a30(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((*(char *)(iRam00715da8 + 0x30) == '\0') &&
       (uVar1 = 0, *(char *)(iRam00715da8 + 0x2f) == '\0')) &&
      (uVar1 = 0, (*(byte *)(iRam00715da8 + 0x4a) & 1) == 0)) &&
     (((*(char *)(iRam00715da8 + 0x1f) != '\x04' ||
       (uVar1 = 1, (*(byte *)(iRam00715da8 + 0x35) & 0xf) != 0)) &&
      (uVar1 = 1, *(char *)(iRam00715da8 + 0x1f) != '\x05')))) {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================