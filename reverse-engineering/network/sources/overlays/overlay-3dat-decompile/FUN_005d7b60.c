FUNCTION FUN_005d7b60 @ 0x005d7b60  size=392
CALLERS (1): FUN_005d80c0@0x005d80c0
CALLEES (1): FUN_005d6a10@0x005d6a10
----------------------------------------------------------------

void FUN_005d7b60(int param_1)

{
  char cVar1;
  int extraout_a3_lo;
  int extraout_a3_lo_00;
  int iVar2;
  int extraout_t0_lo;
  int extraout_t0_lo_00;
  
  iVar2 = *(int *)(param_1 + 0x118);
  if (*(char *)(iVar2 + 0x68) != '\x02') {
    return;
  }
  switch(*(undefined1 *)(iVar2 + 0x3d)) {
  case 0:
    *(undefined4 *)(param_1 + 0x104) = 5;
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(iVar2 + 0x38);
    *(undefined1 *)(param_1 + 0x124) = 0;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    if (*(char *)(iVar2 + 0x34) == '\0') {
LAB_005d7c04:
      cVar1 = *(char *)(iVar2 + 0x3e);
    }
    else {
      if (*(char *)(iVar2 + 0x3f) == '\0') {
        FUN_005d6a10(param_1 + 0x108,4,0);
        iVar2 = extraout_a3_lo_00;
        param_1 = extraout_t0_lo_00;
        goto LAB_005d7c04;
      }
      FUN_005d6a10(param_1 + 0x108,4,1);
      cVar1 = *(char *)(extraout_a3_lo + 0x3e);
      param_1 = extraout_t0_lo;
    }
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x125) = 9;
    }
    break;
  case 1:
  case 2:
  case 3:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x10:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 2;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 4:
  case 5:
  case 6:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 4;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 0xf:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 1;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 0x11:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 7;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 0x12:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined1 *)(param_1 + 0x124) = 9;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 0x13:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 10;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
    break;
  case 0x14:
    *(undefined4 *)(param_1 + 0x104) = 6;
    *(undefined1 *)(param_1 + 0x124) = 0xb;
    *(undefined1 *)(param_1 + 0x125) = *(undefined1 *)(iVar2 + 0x3c);
  }
  return;
}



================================================================