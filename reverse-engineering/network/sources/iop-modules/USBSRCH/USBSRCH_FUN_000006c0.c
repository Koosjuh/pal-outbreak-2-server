FUNCTION FUN_000006c0 @ 0x000006c0 size=304
CALLERS (1): FUN_000007f0@0x000007f0
CALLEES (9): FUN_00000970@0x00000970, FUN_00000900@0x00000900, FUN_00000934@0x00000934, FUN_000008cc@0x000008cc, FUN_00000978@0x00000978, FUN_00000908@0x00000908, FUN_000009fc@0x000009fc, FUN_000009ec@0x000009ec, FUN_00000a30@0x00000a30

undefined4 FUN_000006c0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_00000900(&local_14);
  iVar1 = FUN_00000934(0x880);
  FUN_00000908(local_14);
  if ((((iVar1 == 0) || (iVar1 == -0xd5)) && (iVar1 = FUN_00000970(0xb80,0xb68), iVar1 != 0)) &&
     (iVar1 = FUN_00000978(0xb68), iVar1 != 0)) {
    FUN_000008cc(0xae8);
    local_10 = FUN_000009fc(DAT_00000bc4);
    local_10 = FUN_000009ec(DAT_00000bc4);
    FUN_00000a30(DAT_00000b60);
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


================================================================