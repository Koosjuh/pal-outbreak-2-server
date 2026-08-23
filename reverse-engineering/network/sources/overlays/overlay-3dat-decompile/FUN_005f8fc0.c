FUNCTION FUN_005f8fc0 @ 0x005f8fc0  size=392
CALLERS (1): FUN_005f8e20@0x005f8e20
CALLEES (4): FUN_005b14b0@0x005b14b0, FUN_005b1190@0x005b1190, FUN_005f8c20@0x005f8c20, FUN_005f8d00@0x005f8d00
----------------------------------------------------------------

void FUN_005f8fc0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if (*(char *)(iVar3 + 0xf) == '\x01') {
    iVar1 = (char)(*(char *)(iVar3 + 0x448) + *(char *)(iVar3 + 0x449)) * 0x15c;
    switch(*(byte *)(iVar1 + 0x6c076e)) {
    default:
      FUN_005f8d00(*(undefined1 *)(*(byte *)(iVar1 + 0x6c076e) + 0x649850));
      break;
    case 1:
      uRam006c4600 = (undefined1)*(undefined2 *)(iVar1 + 0x6c0760);
      *(undefined1 *)(iVar3 + 0xe) = 3;
      *(undefined1 *)(iVar3 + 0xf) = 0;
      *(undefined1 *)(iVar3 + 0x10) = 0;
      *(undefined1 *)(iVar3 + 0x11) = 0;
      break;
    case 3:
      uRam006c4600 = (undefined1)*(undefined2 *)(iVar1 + 0x6c0760);
      *(undefined1 *)(iVar3 + 0xe) = 2;
      *(undefined1 *)(iVar3 + 0xf) = 0;
      *(undefined1 *)(iVar3 + 0x10) = 0;
      *(undefined1 *)(iVar3 + 0x11) = 0;
    }
  }
  else if (*(char *)(iVar3 + 0xf) == '\0') {
    *(undefined1 *)(iVar3 + 0x992) = 1;
    lVar2 = FUN_005b1190(iVar3 + 0x448,iVar3 + 0x449,uRam006c4602,5,2);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x10);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x200);
        if (lVar2 != 0) {
          func_0x001b0140(2);
          FUN_005f8c20(param_1,0);
        }
      }
      else {
        *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
        func_0x001b0140(1);
        *(undefined1 *)(iVar3 + 0x992) = 0;
      }
    }
  }
  return;
}



================================================================