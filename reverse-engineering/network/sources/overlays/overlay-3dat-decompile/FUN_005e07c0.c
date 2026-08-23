FUNCTION FUN_005e07c0 @ 0x005e07c0  size=3596
CALLERS (7): FUN_005e3a80@0x005e3a80, FUN_005e2fa0@0x005e2fa0, FUN_005e4840@0x005e4840, FUN_005dbca0@0x005dbca0, FUN_005db8a0@0x005db8a0, FUN_005e07c0@0x005e07c0, FUN_005db300@0x005db300
CALLEES (3): FUN_005ddb40@0x005ddb40, FUN_005e07c0@0x005e07c0, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

void FUN_005e07c0(float param_1,float param_2,float param_3,float param_4,undefined1 param_5,
                 long param_6)

{
  undefined8 uVar1;
  
  if (-32.0 <= param_2) {
    if (448.0 < param_2) {
      return;
    }
    if (param_6 == 0) {
      param_6 = -1;
    }
    switch(param_5) {
    case 2:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 - 2.0),(int)(param_2 - 1.0),0x16,0x1d,0x2a,0x20);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 18.0),(int)(param_2 - 1.0),0x52,0x1d,0x40,0x20);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 100.0),(int)(param_2 - 1.0),0x10,0x1d,0x70,0x20);
      break;
    case 3:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 - 1.0),(int)param_2,0x16,0x20,0x2a,0x20);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 19.0),(int)param_2,0xde,0x20,0x40,0x20);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 240.0),(int)param_2,0x10,0x20,0x70,0x20);
      break;
    case 4:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0xdd,0x1e,0,0xc0);
      break;
    case 5:
      uVar1 = FUN_005e00e0(1);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0xdd,0x1e,0,0);
      break;
    case 6:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x14,0x14,0,0xa0);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)((param_1 + param_3) - 20.0),(int)param_2,0x14,0x14,0x20,0xa0)
      ;
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 - 1.0),(int)param_2,(int)(param_3 - 1.0),0x14,0x10,
                   0xa0);
      break;
    case 7:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x14,0x14,0,0x80);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)((param_1 + param_3) - 20.0),(int)param_2,0x14,0x14,0x20,0x80)
      ;
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 4.0),(int)param_2,(int)(param_3 - 4.0),0x14,0x10,
                   0x80);
      break;
    case 8:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x14,0x14,0,0x60);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)((param_1 + param_3) - 20.0),(int)param_2,0x14,0x14,0x20,0x60)
      ;
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 16.0),(int)param_2,(int)(param_3 - 32.0),0x14,0x10,
                   0x60);
      break;
    case 9:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x14,0x14,0,0x40);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)((param_1 + param_3) - 20.0),(int)param_2,0x14,0x14,0x20);
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)(param_1 + 16.0),(int)param_2,(int)(param_3 - 32.0),0x14,0x10,
                   0x40);
      break;
    case 10:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0xe0,0x40);
      break;
    case 0xb:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0xe0,0x60);
      break;
    case 0xc:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0xe0,0x80);
      break;
    case 0xd:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0xe0,0xa0);
      break;
    case 0xe:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0x100,0x80);
      break;
    case 0xf:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0x100,0x60);
      break;
    case 0x10:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0x100,0xc0);
      break;
    case 0x11:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0x100,0xa0);
      break;
    case 0x12:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,(int)param_3,(int)param_4,0x80,0x40);
      break;
    case 0x13:
      if (param_4 < 32.0) {
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,(int)param_3,(int)param_4,0x60,0x40);
      }
      else {
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,(int)param_3,0x10,0x60,0x40);
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)((param_2 + param_4) - 16.0),(int)param_3,0x10,
                     0x60,0x50);
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)(param_2 + 16.0),(int)param_3,
                     (int)(param_4 - 32.0),0x60,0x48);
      }
      break;
    case 0x14:
      uVar1 = FUN_005e00e0(0);
      FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,(int)param_3,(int)param_4,0x40,0x40);
      break;
    case 0x15:
      if (param_3 < 32.0) {
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,(int)param_3,(int)param_4,0x60,0x40);
      }
      else {
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)param_1,(int)param_2,0x10,(int)param_4,0x60,0x40);
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)((param_1 + param_3) - 16.0),(int)param_2,0x10,(int)param_4,
                     0x70,0x40);
        uVar1 = FUN_005e00e0(0);
        FUN_005ddb40(param_6,uVar1,(int)(param_1 + 16.0),(int)param_2,(int)(param_3 - 32.0),
                     (int)param_4,0x68,0x40);
      }
      break;
    case 0x16:
      FUN_005e07c0(param_1,param_2,param_3,param_4,7,0);
      FUN_005e07c0((param_1 + param_3) - 16.0,param_2 + 1.0,0x41800000,param_4,0xb,0);
      break;
    case 0x17:
      FUN_005e07c0(param_1,param_2,param_3,param_4,7,0);
      FUN_005e07c0((param_1 + param_3) - 16.0,param_2 + 1.0,0x41800000,param_4,0xf,0);
    }
  }
  return;
}



================================================================