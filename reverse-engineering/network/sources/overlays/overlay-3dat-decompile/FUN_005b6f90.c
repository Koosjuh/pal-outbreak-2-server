FUNCTION FUN_005b6f90 @ 0x005b6f90  size=728
CALLERS (1): FUN_005b7270@0x005b7270
CALLEES (0): 
----------------------------------------------------------------

void FUN_005b6f90(int param_1)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_8 [8];
  
  iVar2 = 0;
  while ((iVar2 < 0xb &&
         (lVar1 = func_0x0010a700(0x6ca2e0,(&PTR_s_DUMMY_00638f20)[iVar2]), lVar1 == 0))) {
    iVar2 = iVar2 + 1;
  }
  switch(iVar2) {
  case 1:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    uRam006ca880 = 1;
    break;
  case 2:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
    if ((cRam006ca2e5 < '0') || ('9' < cRam006ca2e5)) {
      if ((cRam006ca2e5 < 'a') || ('f' < cRam006ca2e5)) {
        *(char *)(param_1 + 9) = cRam006ca2e5 + -0x37;
      }
      else {
        *(char *)(param_1 + 9) = cRam006ca2e5 + -0x57;
      }
    }
    else {
      *(char *)(param_1 + 9) = cRam006ca2e5 + -0x30;
    }
    if (0xf < *(byte *)(param_1 + 9)) {
      *(undefined1 *)(param_1 + 9) = 5;
    }
    break;
  case 3:
    func_0x00106b60(auStack_8,0,8);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
    if ((cRam006ca2e6 < '0') || ('9' < cRam006ca2e6)) {
      if ((cRam006ca2e6 < 'a') || ('f' < cRam006ca2e6)) {
        *(char *)(param_1 + 8) = cRam006ca2e6 + -0x37;
      }
      else {
        *(char *)(param_1 + 8) = cRam006ca2e6 + -0x57;
      }
    }
    else {
      *(char *)(param_1 + 8) = cRam006ca2e6 + -0x30;
    }
    if (0xf < *(byte *)(param_1 + 8)) {
      *(undefined1 *)(param_1 + 8) = 7;
    }
    break;
  case 4:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
    uRam006ca880 = 2;
    break;
  case 5:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
    break;
  case 6:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x20;
    break;
  case 7:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
    break;
  case 8:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x80;
    break;
  case 9:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x100;
    *(char *)(param_1 + 10) = cRam006ca2e3 + -0x30;
    if (9 < *(byte *)(param_1 + 10)) {
      *(undefined1 *)(param_1 + 10) = 9;
    }
    uRam006ca880 = 2;
    break;
  case 10:
    func_0x00106b60(auStack_8,0,8);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
    if ((cRam006ca2e2 < '0') || ('9' < cRam006ca2e2)) {
      if ((cRam006ca2e2 < 'a') || ('f' < cRam006ca2e2)) {
        *(char *)(param_1 + 8) = cRam006ca2e2 + -0x37;
      }
      else {
        *(char *)(param_1 + 8) = cRam006ca2e2 + -0x57;
      }
    }
    else {
      *(char *)(param_1 + 8) = cRam006ca2e2 + -0x30;
    }
    if (0xf < *(byte *)(param_1 + 8)) {
      *(undefined1 *)(param_1 + 8) = 7;
    }
  }
  uRam006ca882 = (char)iVar2;
  return;
}



================================================================