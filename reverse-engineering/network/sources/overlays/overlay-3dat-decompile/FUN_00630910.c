FUNCTION FUN_00630910 @ 0x00630910  size=756
CALLERS (1): FUN_00630750@0x00630750
CALLEES (7): FUN_00637c40@0x00637c40, FUN_00637bf0@0x00637bf0, FUN_00637c70@0x00637c70, FUN_00637ca0@0x00637ca0, FUN_00632290@0x00632290, FUN_00637980@0x00637980, FUN_00637ba0@0x00637ba0
----------------------------------------------------------------

undefined4 FUN_00630910(ulong param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  ulong uVar4;
  
  if (((*(byte *)(iRam00715da8 + 0x33) & 0x10) == 0) || (lVar3 = FUN_00637c40(), lVar3 != 0)) {
    if (((*(byte *)(iRam00715da8 + 0x33) & 0x20) == 0) ||
       ((lVar3 = FUN_00637c40(param_1), lVar3 != 0 || ((param_1 & 0xffff) == 0x2d)))) {
      if (((*(byte *)(iRam00715da8 + 0x33) & 0x40) == 0) ||
         ((lVar3 = FUN_00637c40(param_1), lVar3 != 0 || (lVar3 = FUN_00637c70(param_1), lVar3 != 0))
         )) {
        if (((*(byte *)(iRam00715da8 + 0x33) & 0x80) == 0) ||
           (lVar3 = FUN_00637ca0(param_1), lVar3 != 0)) {
          uVar4 = param_1 & 0xffff;
          if (((*(byte *)(iRam00715da8 + 0x33) & 2) == 0) || ((param_1 & 0xffff) != 0x25)) {
            if (uVar4 == 0xff62) {
              uVar2 = 0;
            }
            else if (uVar4 == 0xff63) {
              uVar2 = 0;
            }
            else {
              uVar2 = 0;
              if (uVar4 != 0xb7) {
                lVar3 = FUN_00632290();
                if (lVar3 == 0) {
                  if (uVar4 == 0x5c) {
                    return 0;
                  }
                  if ((*(char *)(iRam00715da8 + 0x1d) == '\x05') &&
                     (lVar3 = FUN_00637bf0(param_1), lVar3 == 0)) {
                    return 0;
                  }
                  cVar1 = *(char *)(iRam00715da8 + 0x1d);
                  if ((((cVar1 == '\x01') || (cVar1 == '\x05')) || (cVar1 == '\x02')) &&
                     (lVar3 = FUN_00637ba0(param_1), lVar3 == 0)) {
                    return 0;
                  }
                  if ((*(uint *)(iRam00715da8 + 0x20) & 8) != 0) {
                    if (((((uVar4 == 0x7e) || (uVar4 == 0x7d)) ||
                         ((uVar4 == 0x7c || ((uVar4 == 0x7b || (uVar4 == 0x60)))))) ||
                        (uVar4 == 0x5d)) ||
                       ((((uVar4 == 0x5b || (uVar4 == 0x2f)) || (uVar4 == 0x25)) || (uVar4 == 0x24))
                       )) {
                      return 0;
                    }
                    if ((0x9f < uVar4) && (uVar4 < 0xc0)) {
                      return 0;
                    }
                  }
                  if ((*(uint *)(iRam00715da8 + 0x20) & 2) == 0) {
                    return 1;
                  }
                  if ((0xbf < uVar4) && (uVar4 < 0x1a0)) {
                    return 0;
                  }
                }
                else {
                  lVar3 = FUN_00637980(param_1);
                  if (lVar3 != 0) {
                    return 0;
                  }
                }
                uVar2 = 1;
              }
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================