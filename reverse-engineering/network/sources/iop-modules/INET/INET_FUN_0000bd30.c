FUNCTION FUN_0000bd30 @ 0x0000bd30 size=128
CALLERS (1): FUN_0000f280@0x0000f280
CALLEES (1): FUN_0000bca0@0x0000bca0

undefined4 FUN_0000bd30(undefined4 param_1,uint param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_0000bca0(param_1,param_2 >> 0x18);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_0000bca0(puVar1 + 1,param_2 >> 0x10 & 0xff);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_0000bca0(puVar1 + 1,param_2 >> 8 & 0xff);
  *puVar1 = 0x2e;
  puVar1 = (undefined1 *)FUN_0000bca0(puVar1 + 1,param_2 & 0xff);
  *puVar1 = 0;
  return param_1;
}


================================================================