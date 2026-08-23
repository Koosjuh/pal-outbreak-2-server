FUNCTION FUN_005de330 @ 0x005de330  size=796
CALLERS (10): FUN_005e5200@0x005e5200, FUN_005e5650@0x005e5650, FUN_005dd660@0x005dd660, FUN_005d60a0@0x005d60a0, FUN_005d81b0@0x005d81b0, FUN_005e2060@0x005e2060, FUN_005dbca0@0x005dbca0, FUN_005e4f10@0x005e4f10, FUN_005dc010@0x005dc010, FUN_005e4b00@0x005e4b00
CALLEES (0): 
----------------------------------------------------------------

undefined * FUN_005de330(int param_1,int param_2)

{
  if (cRam0035ba80 == '\x05') {
    if (param_1 == 9) {
      return (&PTR_s_Esci__00645b60)[param_2];
    }
    if (param_1 == 8) {
      return (&PTR_PTR_00645a88)[param_2];
    }
    if (param_1 == 4) {
      return (&PTR_s_Address_006459c8)[param_2];
    }
    if (param_1 == 3) {
      return (&PTR_s_Ricarica_006459b8)[param_2];
    }
  }
  else if (cRam0035ba80 == '\x04') {
    if (param_1 == 9) {
      return (&PTR_s_Verlassen__00645180)[param_2];
    }
    if (param_1 == 8) {
      return (&PTR_s_Verbindungsfehler_aufgetreten__B_006450a8)[param_2];
    }
    if (param_1 == 4) {
      return (&PTR_s_Address_00644fb8)[param_2];
    }
    if (param_1 == 3) {
      return (&PTR_s_Neu_laden_00644fa8)[param_2];
    }
  }
  else if (cRam0035ba80 == '\x03') {
    if (param_1 == 9) {
      return (&PTR_s_salir__00646500)[param_2];
    }
    if (param_1 == 8) {
      return (&PTR_PTR_00646428)[param_2];
    }
    if (param_1 == 4) {
      return (&PTR_s_Address_00646348)[param_2];
    }
    if (param_1 == 3) {
      return (&PTR_s_Recargar_00646338)[param_2];
    }
  }
  else {
    if (cRam0035ba80 != '\x02') {
      if (param_1 == 9) {
        return (&PTR_s_exit__00643e10)[param_2];
      }
      if (param_1 == 8) {
        return (&PTR_s_A_connection_error_has_occurred__00643d38)[param_2];
      }
      if (param_1 == 4) {
        return (&PTR_s_Address_00643c58)[param_2];
      }
      if (param_1 != 3) {
        return (undefined *)0x0;
      }
      return (&PTR_s_Reload_00643c48)[param_2];
    }
    if (param_1 == 9) {
      return (&PTR_s_Quitter__00644830)[param_2];
    }
    if (param_1 == 8) {
      return (&PTR_DAT_00644770)[param_2];
    }
    if (param_1 == 4) {
      return (&PTR_s_Address_006446a8)[param_2];
    }
    if (param_1 == 3) {
      return (&PTR_s_Recharger_00644698)[param_2];
    }
  }
  return (undefined *)0x0;
}



================================================================