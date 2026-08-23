FUNCTION FUN_005b2aa0 @ 0x005b2aa0  size=272
CALLERS (1): FUN_005b2bc0@0x005b2bc0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005b2aa0(char param_1)

{
  if (param_1 == '\x04') {
    if (cRam00874f35 == '\0') {
      return 1;
    }
    if (cRam00874f35 == '\x03') {
      return 1;
    }
    if (cRam00874f35 == '\x02') {
      return 1;
    }
    if (cRam00874f35 == '\x01') {
      return 1;
    }
  }
  else if (param_1 == '\x03') {
    if (cRam00874f35 == '\0') {
      return 1;
    }
    if (cRam00874f35 == '\x03') {
      return 1;
    }
    if (cRam00874f35 == '\x02') {
      return 1;
    }
  }
  else if (param_1 == '\x02') {
    if (cRam00874f35 == '\0') {
      return 1;
    }
    if (cRam00874f35 == '\x03') {
      return 1;
    }
  }
  else {
    if (param_1 != '\x01') {
      if (param_1 == '\0') {
        return 1;
      }
      return 0;
    }
    if (cRam00874f35 == '\0') {
      return 1;
    }
  }
  return 0;
}



================================================================