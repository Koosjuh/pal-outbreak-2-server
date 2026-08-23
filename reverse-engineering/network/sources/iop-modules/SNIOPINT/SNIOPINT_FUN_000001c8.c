FUNCTION FUN_000001c8 @ 0x000001c8 size=184
CALLERS (2): FUN_000019a4@0x000019a4, FUN_00001e68@0x00001e68
CALLEES (2): FUN_00003660@0x00003660, FUN_00003668@0x00003668

undefined4 FUN_000001c8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  switch(param_1) {
  case 0:
    local_c = 0xcf;
    break;
  case 1:
    local_c = 1;
    break;
  case 2:
    local_c = 2;
    break;
  case 3:
    local_c = 4;
    break;
  case 4:
    local_c = 8;
    break;
  default:
    return 0xffffffff;
  }
  FUN_00003668(9,auStack_10,4);
  FUN_00003660(9,&local_c,4);
  uVar1 = FUN_00003668(9,auStack_10,4);
  return uVar1;
}


================================================================