FUNCTION FUN_00007da0 @ 0x00007da0 size=128
CALLERS (1): FUN_00000944@0x00000944
CALLEES (1): FUN_00007d10@0x00007d10

undefined4 FUN_00007da0(undefined4 param_1,uint param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_00007d10(param_1,param_2 >> 0x18);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_00007d10(puVar1 + 1,param_2 >> 0x10 & 0xff);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_00007d10(puVar1 + 1,param_2 >> 8 & 0xff);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_00007d10(puVar1 + 1,param_2 & 0xff);
  *puVar1 = 0;
  return param_1;
}


================================================================