FUNCTION FUN_005d60a0 @ 0x005d60a0  size=748
CALLERS (1): FUN_005c9c50@0x005c9c50
CALLEES (4): FUN_005d6560@0x005d6560, FUN_005d59f0@0x005d59f0, FUN_005de330@0x005de330, FUN_005d5cc0@0x005d5cc0
----------------------------------------------------------------

undefined4 FUN_005d60a0(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 auStack_100 [256];
  
  uVar4 = func_0x0010a050(iRam00701080 + 0x21e);
  if (uVar4 < 8) {
    uVar3 = 0xffffffff;
  }
  else {
    cVar1 = *(char *)(iRam00701070 + 0x30);
    if ((cVar1 == '\x05') || (cVar1 == '\x04')) {
      lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x642fd0);
      if ((lVar5 == 0) || (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x642fe0), lVar5 == 0)) {
        uVar2 = 0;
      }
      else {
        lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x642ff0);
        if ((lVar5 == 0) || (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643000), lVar5 == 0)) {
          uVar2 = 0;
        }
        else {
          lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643010);
          if ((lVar5 == 0) || (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643020), lVar5 == 0))
          {
            uVar2 = 0;
          }
          else {
            lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643030);
            if ((lVar5 == 0) || (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643040), lVar5 == 0)
               ) {
              uVar2 = 1;
            }
            else {
              lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643050);
              if ((lVar5 == 0) ||
                 (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643060), lVar5 == 0)) {
                uVar2 = 0;
              }
              else {
                lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643070);
                if ((lVar5 == 0) ||
                   (lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643080), lVar5 == 0)) {
                  uVar2 = 2;
                }
                else {
                  lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x643090);
                  if (lVar5 == 0) {
                    uVar2 = 3;
                  }
                  else {
                    lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x6430a0);
                    if (lVar5 == 0) {
                      uVar2 = 4;
                    }
                    else {
                      lVar5 = func_0x00109d70(iRam00701080 + 0x21e,0x6430b0);
                      if (lVar5 == 0) {
                        uVar2 = 5;
                      }
                      else {
                        uVar2 = 6;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      uVar6 = FUN_005de330(6,uVar2);
      func_0x00109eb8(iRam00701080 + 0x2421,uVar6);
      FUN_005d6560(*(undefined4 *)(iRam00701068 + 0x4db5c),iRam00701080 + 0x2421,
                   iRam00701080 + 0x21e,1);
      func_0x00109728(auStack_100,0x6430c0,0);
      FUN_005d5cc0(auStack_100);
      FUN_005d59f0();
      uVar3 = 1;
    }
    else if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}



================================================================