FUNCTION FUN_005c85d0 @ 0x005c85d0  size=568
CALLERS (1): FUN_005c8810@0x005c8810
CALLEES (4): FUN_005d8930@0x005d8930, FUN_005d5c20@0x005d5c20, FUN_005c8530@0x005c8530, FUN_005d5ba0@0x005d5ba0
----------------------------------------------------------------

void FUN_005c85d0(void)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(char *)(iRam00701078 + 1) != '\x04') && (*(char *)(iRam00701070 + 1) == '\x01')) {
    if (cRam00701e10 == '\0') {
      if (((*(int *)(iRam00701068 + 0x68f90) == 0) && (lVar1 = func_0x001ee360(), lVar1 != 0)) &&
         ((lVar1 == 3 || ((lVar1 == 2 || (lVar1 == 1)))))) {
        *(undefined4 *)(iRam00701068 + 0x68f90) = 1;
        if (lVar1 == 3) {
          uRam00700ff0 = 1;
        }
        uVar2 = func_0x0010a050(0x642bc8);
        lVar1 = func_0x0010a338(iRam00701068 + 0x4f7a0,0x642bc8,uVar2);
        if (lVar1 != 0) {
          *(undefined1 *)(iRam00701068 + 0x60dca) = 1;
          *(undefined1 *)(iRam00701068 + 0x68e84) = 2;
          *(undefined1 *)(iRam00701068 + 0x60dcc) = 2;
          if (cRam00701f20 == '\x01') {
            if (*(char *)(iRam00701070 + 2) == '\x05') {
              FUN_005d8930();
              *(undefined1 *)(iRam00701070 + 1) = 1;
              *(undefined1 *)(iRam00701070 + 2) = 6;
            }
            else {
              uRam00700fe0 = 0xffffffff;
              *(undefined1 *)(iRam00701070 + 1) = 3;
            }
          }
          else if (cRam00701f20 == '\0') {
            if ((cRam00700fe8 == '\0') || (*(char *)(iRam00701070 + 0x2e) != '\x01')) {
              if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                FUN_005d5c20(0xe);
              }
              else {
                FUN_005d5ba0(0);
                *(undefined1 *)(iRam00701078 + 2) = 1;
              }
            }
            else {
              FUN_005d5c20(0xd);
            }
          }
        }
      }
    }
    else {
      FUN_005c8530();
    }
  }
  return;
}



================================================================