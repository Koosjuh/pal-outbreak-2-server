FUNCTION FUN_000105e0 @ 0x000105e0 size=236
CALLERS (1): FUN_0000fc50@0x0000fc50
CALLEES (7): FUN_00010b64@0x00010b64, FUN_00010aec@0x00010aec, FUN_00010b24@0x00010b24, FUN_00010c38@0x00010c38, FUN_00010b5c@0x00010b5c, FUN_00010af4@0x00010af4, FUN_00010b8c@0x00010b8c

void FUN_000105e0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00014980 = 4;
  DAT_00012f04 = 0;
  DAT_00012f08 = 0;
  iVar1 = FUN_00010b8c();
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("aveppp timer thread priority = %d\n",*(undefined4 *)(iVar1 + 4));
  }
  uVar2 = *(undefined4 *)(iVar1 + 4);
  iVar1 = FUN_00010aec(DAT_00014980,0,1,1);
  if (iVar1 == 0) {
    iVar1 = FUN_00010af4(4,1,&LAB_000101d0,uVar2,0x1000);
    if ((iVar1 == 0) && (iVar1 = FUN_00010b5c(4,0), iVar1 == 0)) goto LAB_000106a8;
  }
  FUN_00010b24(0xffffffff);
LAB_000106a8:
  while (DAT_00012f04 < 1) {
    FUN_00010b64(100);
  }
  return;
}


================================================================