FUNCTION FUN_00612d10 @ 0x00612d10  size=700
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (11): FUN_00613600@0x00613600, FUN_00613530@0x00613530, FUN_00613aa0@0x00613aa0, FUN_0060e1c0@0x0060e1c0, FUN_00613740@0x00613740, FUN_006130a0@0x006130a0, FUN_00613840@0x00613840, FUN_006134b0@0x006134b0, FUN_006139c0@0x006139c0, FUN_00612fd0@0x00612fd0, FUN_00613380@0x00613380
----------------------------------------------------------------

void FUN_00612d10(void)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  
  switch(*(undefined1 *)(iRam0070d1c0 + 0x4d)) {
  case 0:
    break;
  case 1:
    FUN_006130a0();
    FUN_00612fd0();
    return;
  default:
    FUN_00612fd0();
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 0x15:
    FUN_00613530();
    FUN_00612fd0();
    break;
  case 7:
    FUN_00612fd0();
    FUN_00613380();
    break;
  case 9:
    FUN_00612fd0();
    FUN_00613600();
    break;
  case 0xb:
    FUN_00613740(iRam0070d1c0 + 0xabc,0x157,0xc4);
    FUN_00613740(iRam0070d1c0 + 0xac0,0x157,0xe0);
    FUN_00613740(iRam0070d1c0 + 0xac4,0x157,0xfc);
    FUN_00612fd0();
    break;
  case 0xd:
    FUN_00613740(iRam0070d1c0 + 0xac8,0x157,0xc4);
    FUN_00613740(iRam0070d1c0 + 0xacc,0x157,0xfc);
    FUN_00612fd0();
    break;
  case 0xe:
    FUN_00613aa0(iRam0070d1c0 + 0x8bc,0x654070,0x115,0xe0,0x18);
    FUN_00612fd0();
    break;
  case 0xf:
    FUN_00613aa0(iRam0070d1c0 + 0xad0,0x654090,0x115,0xe0,0x18);
    FUN_00612fd0();
    break;
  case 0x10:
  case 0x11:
  case 0x12:
    iVar2 = 0;
    do {
      iVar3 = *(char *)(iRam0070d1c0 + 0x1e) + iVar2;
      if ((long)iVar3 < (long)*(char *)(iRam0070d1c0 + 0x24)) {
        uVar1 = FUN_0060e1c0(iRam0070d1c0 + 0x1180,iRam0070d1c0 + iVar3 * 0x1340 + 0xaf00);
        FUN_006139c0(uVar1,(long)iVar3,0x65,(short)iVar2 * 0x1c + 0xc4,0x26);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    FUN_00612fd0();
    break;
  case 0x17:
    FUN_00613aa0(iRam0070d1c0 + 0xed8,0x6540b0,0x157,0xba,0x12);
    FUN_00613aa0(iRam0070d1c0 + 0xfd8,0x6540d0,0x157,0xea,0x12);
    FUN_00613840(iRam0070d1c0 + 0xed4,0x157,0xd2);
    FUN_00613840(iRam0070d1c0 + 0xed6,0x157,0x102);
    FUN_00612fd0();
    break;
  case 0x18:
    FUN_006134b0();
    FUN_00612fd0();
  }
  return;
}



================================================================