
void FUN_001d9f78(int param_1,int param_2)

{
  uint *puVar1;
  char cStack_40;
  undefined1 uStack_3f;
  ushort uStack_3e;
  ushort uStack_3c;
  short sStack_3a;
  undefined4 uStack_38;
  uint uStack_34;
  uint *puStack_30;
  uint uStack_2c;
  uint *puStack_28;
  uint *puStack_24;
  uint *puStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  puStack_30 = (uint *)0x0;
  cStack_40 = '\0';
  uStack_38 = *(undefined4 *)(param_2 + 0x30);
  uStack_3c = (*(ushort *)(param_2 + 0x2c) & 0x3ff) - 0x10;
  if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
    sStack_3a = 0;
  }
  else {
    sStack_3a = 0x1000;
  }
  uStack_3f = (*(ushort *)(param_2 + 0x2c) & 0x2000) == 0;
  if ((bool)uStack_3f) {
    uStack_3e = *(ushort *)(param_2 + 0x2e) >> 8;
  }
  else {
    uStack_3e = 0;
  }
  uStack_34 = (uint)(*(ushort *)(param_2 + 0x2e) >> 8);
  uStack_2c = *(ushort *)(param_2 + 0x2e) & 0x7f;
  iStack_14 = uStack_2c - 3;
  switch(iStack_14) {
  case 0:
    if (*(int *)(param_1 + 0x548) != 0) {
      FUN_001d7ab0(param_2 + 0x3c);
      (**(code **)(param_1 + 0x548))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 1:
    if (*(int *)(param_1 + 0x558) != 0) {
      FUN_001d7b30(param_2 + 0x3c);
      (**(code **)(param_1 + 0x558))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 2:
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      FUN_001d8048(param_2 + 0x3c);
      if (*(int *)(param_1 + 0x55c) != 0) {
        (**(code **)(param_1 + 0x55c))(&cStack_40,param_2 + 0x3c);
      }
    }
    else {
      FUN_001d8048(param_2 + 0x3c);
      if (*(int *)(param_1 + 0x54c) != 0) {
        (**(code **)(param_1 + 0x54c))(&cStack_40,param_2 + 0x3c);
      }
    }
    break;
  case 3:
    FUN_001d80c8(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if (*(int *)(param_1 + 0x550) != 0) {
        (**(code **)(param_1 + 0x550))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (*(int *)(param_1 + 0x554) != 0) {
      (**(code **)(param_1 + 0x554))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 4:
    FUN_001d8048(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if (*(int *)(param_1 + 0x560) != 0) {
        (**(code **)(param_1 + 0x560))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (*(int *)(param_1 + 0x564) != 0) {
      (**(code **)(param_1 + 0x564))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 5:
    FUN_001d84cc(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if (*(int *)(param_1 + 0x568) != 0) {
        (**(code **)(param_1 + 0x568))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (*(int *)(param_1 + 0x56c) != 0) {
      (**(code **)(param_1 + 0x56c))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 6:
    FUN_001d84cc(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if (*(int *)(param_1 + 0x5a0) != 0) {
        (**(code **)(param_1 + 0x5a0))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (*(int *)(param_1 + 0x5a4) != 0) {
      (**(code **)(param_1 + 0x5a4))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 7:
    FUN_001d8848(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if (*(int *)(param_1 + 0x5a8) != 0) {
        (**(code **)(param_1 + 0x5a8))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (*(int *)(param_1 + 0x5ac) != 0) {
      (**(code **)(param_1 + 0x5ac))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 8:
    FUN_001d8d70(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5b4) != 0) {
      (**(code **)(param_1 + 0x5b4))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 9:
    FUN_001d93d4(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x570) != 0) {
      (**(code **)(param_1 + 0x570))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0xb:
    FUN_001d8ab0(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5b0) != 0) {
      (**(code **)(param_1 + 0x5b0))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0xc:
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if ((*(ushort *)(param_2 + 0x2c) & 0x400) == 0) {
        if ((*(ushort *)(param_2 + 0x2c) & 0x8000) == 0) {
          if (*(int *)(param_1 + 0x598) != 0) {
            (**(code **)(param_1 + 0x598))(&cStack_40,param_2 + 0x3c);
          }
        }
        else if (*(int *)(param_1 + 0x590) != 0) {
          (**(code **)(param_1 + 0x590))(&cStack_40,param_2 + 0x3c);
        }
      }
      else {
        iStack_1c = param_2 + 0x3c;
        *(undefined1 *)((uint)uStack_3c + iStack_1c) = 0;
        if (*(int *)(param_1 + 0x574) != 0) {
          (**(code **)(param_1 + 0x574))(&cStack_40,param_2 + 0x3c);
        }
      }
    }
    else if (((*(ushort *)(param_2 + 0x2c) & 0x400) != 0) && (*(int *)(param_1 + 0x57c) != 0)) {
      iStack_1c = param_2 + 0x3c;
      *(undefined1 *)((uint)uStack_3c + iStack_1c) = 0;
      (**(code **)(param_1 + 0x57c))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0xd:
    FUN_001d8e20(param_2 + 0x3c);
    if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
      if ((*(ushort *)(param_2 + 0x2c) & 0x400) == 0) {
        if ((*(ushort *)(param_2 + 0x2c) & 0x8000) == 0) {
          if (*(int *)(param_1 + 0x59c) != 0) {
            (**(code **)(param_1 + 0x59c))(&cStack_40,param_2 + 0x3c);
          }
        }
        else if (*(int *)(param_1 + 0x594) != 0) {
          (**(code **)(param_1 + 0x594))(&cStack_40,param_2 + 0x3c);
        }
      }
      else if (*(int *)(param_1 + 0x578) != 0) {
        (**(code **)(param_1 + 0x578))(&cStack_40,param_2 + 0x3c);
      }
    }
    else if (((*(ushort *)(param_2 + 0x2c) & 0x400) != 0) && (*(int *)(param_1 + 0x580) != 0)) {
      (**(code **)(param_1 + 0x580))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0xf:
    FUN_001d8048(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x588) != 0) {
      (**(code **)(param_1 + 0x588))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x10:
    FUN_001d8048(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x58c) != 0) {
      (**(code **)(param_1 + 0x58c))(&cStack_40,param_2 + 0x3c);
    }
  case 0x11:
    if (*(int *)(param_1 + 0x5e8) != 0) {
      (**(code **)(param_1 + 0x5e8))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x22:
    FUN_001d90ec(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5ec) != 0) {
      (**(code **)(param_1 + 0x5ec))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x24:
    cStack_40 = '\'';
  case 0x26:
    if (cStack_40 != '\'') {
      puStack_28 = (uint *)(param_2 + 0x3c);
      *puStack_28 = *puStack_28 << 0x18 | (*puStack_28 & 0xff00) << 8 |
                    (*puStack_28 & 0xff0000) >> 8 | *puStack_28 >> 0x18;
      puVar1 = (uint *)(param_2 + 0x40);
      *puVar1 = *puVar1 << 0x18 | (*puVar1 & 0xff00) << 8 | (*puVar1 & 0xff0000) >> 8 |
                *puVar1 >> 0x18;
      puStack_24 = (uint *)(param_2 + 0x44);
      *puStack_24 = *puStack_24 << 0x18 | (*puStack_24 & 0xff00) << 8 |
                    (*puStack_24 & 0xff0000) >> 8 | *puStack_24 >> 0x18;
      *(uint *)(param_1 + 0x44) = *puStack_24;
      FUN_001d507c(param_1,0,*(undefined2 *)puStack_28);
      *(undefined4 *)(param_1 + 0x80) = 0;
      puStack_30 = puStack_28 + 1;
      *puStack_30 = 1;
    }
  case 0x25:
    if (uStack_2c != 0x29) {
      puStack_30 = (uint *)(param_2 + 0x3c);
      FUN_001d7f6c(puStack_30);
    }
    iStack_18 = *puStack_30 - 1;
    switch(iStack_18) {
    case 0:
      if (*(int *)(param_1 + 0x5b8) != 0) {
        (**(code **)(param_1 + 0x5b8))(&cStack_40,puStack_30);
      }
      break;
    case 2:
      if (*(int *)(param_1 + 0x5bc) != 0) {
        (**(code **)(param_1 + 0x5bc))(&cStack_40,puStack_30);
      }
      break;
    case 3:
      if (*(int *)(param_1 + 0x5c4) != 0) {
        (**(code **)(param_1 + 0x5c4))(&cStack_40,puStack_30);
      }
      break;
    case 4:
      if (sStack_3a == 0x1000) {
        if (*(int *)(param_1 + 0x5c0) != 0) {
          (**(code **)(param_1 + 0x5c0))(&cStack_40,puStack_30);
        }
      }
      else if (*(int *)(param_1 + 0x5c8) != 0) {
        (**(code **)(param_1 + 0x5c8))(&cStack_40,puStack_30);
      }
      break;
    case 5:
      if (sStack_3a == 0x1000) {
        if (*(int *)(param_1 + 0x5cc) != 0) {
          (**(code **)(param_1 + 0x5cc))(&cStack_40,puStack_30);
        }
      }
      else if (cStack_40 == '\'') {
        if (*(int *)(param_1 + 0x5d0) != 0) {
          (**(code **)(param_1 + 0x5d0))(&cStack_40,puStack_30);
        }
      }
      else {
        FUN_001d8ed8(puStack_30);
        puStack_20 = puStack_30;
        if (*(int *)(param_1 + 0x5d0) != 0) {
          (**(code **)(param_1 + 0x5d0))(&cStack_40,puStack_30 + 1);
        }
      }
      break;
    case 6:
      if (sStack_3a == 0x1000) {
        if (*(int *)(param_1 + 0x5d4) != 0) {
          (**(code **)(param_1 + 0x5d4))(&cStack_40,puStack_30);
        }
      }
      else if (*(int *)(param_1 + 0x5d8) != 0) {
        (**(code **)(param_1 + 0x5d8))(&cStack_40,puStack_30);
      }
      break;
    case 7:
      if (cStack_40 == '\'') {
        if (*(int *)(param_1 + 0x5dc) != 0) {
          (**(code **)(param_1 + 0x5dc))(&cStack_40,puStack_30);
        }
      }
      else {
        FUN_001d861c(puStack_30);
        puStack_20 = puStack_30;
        if (*(int *)(param_1 + 0x5dc) != 0) {
          (**(code **)(param_1 + 0x5dc))(&cStack_40,puStack_30 + 1);
        }
      }
      break;
    case 8:
      if (sStack_3a == 0x1000) {
        if (*(int *)(param_1 + 0x5a4) != 0) {
          (**(code **)(param_1 + 0x5a4))(&cStack_40,puStack_30);
        }
      }
      else if (*(int *)(param_1 + 0x5a0) != 0) {
        (**(code **)(param_1 + 0x5a0))(&cStack_40,puStack_30);
      }
      break;
    case 9:
      if (sStack_3a == 0x1000) {
        if (*(int *)(param_1 + 0x5ac) != 0) {
          (**(code **)(param_1 + 0x5ac))(&cStack_40,puStack_30);
        }
      }
      else if (*(int *)(param_1 + 0x5a8) != 0) {
        (**(code **)(param_1 + 0x5a8))(&cStack_40,puStack_30);
      }
      break;
    case 10:
      if (*(int *)(param_1 + 0x5b4) != 0) {
        (**(code **)(param_1 + 0x5b4))(&cStack_40,puStack_30);
      }
      break;
    case 0xb:
      if (*(int *)(param_1 + 0x5e0) != 0) {
        (**(code **)(param_1 + 0x5e0))(&cStack_40,puStack_30);
      }
      break;
    case 0xc:
      if (*(int *)(param_1 + 0x5e4) != 0) {
        (**(code **)(param_1 + 0x5e4))(&cStack_40,puStack_30);
      }
      break;
    case 0xd:
      if (*(int *)(param_1 + 0x5b0) != 0) {
        (**(code **)(param_1 + 0x5b0))(&cStack_40,puStack_30);
      }
      break;
    case 0xe:
      if ((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) {
        if ((*(ushort *)(param_2 + 0x2c) & 0x400) == 0) {
          if ((*(ushort *)(param_2 + 0x2c) & 0x8000) == 0) {
            if (*(int *)(param_1 + 0x598) != 0) {
              (**(code **)(param_1 + 0x598))(&cStack_40,param_2 + 0x3c);
            }
          }
          else if (*(int *)(param_1 + 0x590) != 0) {
            (**(code **)(param_1 + 0x590))(&cStack_40,param_2 + 0x3c);
          }
        }
        else if (*(int *)(param_1 + 0x574) != 0) {
          (**(code **)(param_1 + 0x574))(&cStack_40,param_2 + 0x3c);
        }
      }
      else if (((*(ushort *)(param_2 + 0x2c) & 0x400) != 0) && (*(int *)(param_1 + 0x57c) != 0)) {
        (**(code **)(param_1 + 0x57c))(&cStack_40,param_2 + 0x3c);
      }
      break;
    case 0x24:
      if (*(int *)(param_1 + 0x5ec) != 0) {
        (**(code **)(param_1 + 0x5ec))(&cStack_40,puStack_30);
      }
      break;
    case 0x42:
      if ((sStack_3a != 0x1000) && (*(int *)(param_1 + 0x600) != 0)) {
        (**(code **)(param_1 + 0x600))(&cStack_40,puStack_30);
      }
      break;
    case 0x45:
      if (*(int *)(param_1 + 0x604) != 0) {
        (**(code **)(param_1 + 0x604))(&cStack_40,puStack_30);
      }
      break;
    case 0x46:
      if (*(int *)(param_1 + 0x608) != 0) {
        (**(code **)(param_1 + 0x608))(&cStack_40,puStack_30);
      }
      break;
    case 0x47:
      if (*(int *)(param_1 + 0x60c) != 0) {
        (**(code **)(param_1 + 0x60c))(&cStack_40,puStack_30);
      }
      break;
    case 0x48:
      if (*(int *)(param_1 + 0x610) != 0) {
        (**(code **)(param_1 + 0x610))(&cStack_40,puStack_30);
      }
    }
    break;
  case 0x2a:
    FUN_001d9678(param_1,param_2);
    break;
  case 0x2b:
    FUN_001d9550(param_1,param_2);
    break;
  case 0x2e:
    puStack_28 = (uint *)(param_2 + 0x3c);
    *puStack_28 = *puStack_28 << 0x18 | (*puStack_28 & 0xff00) << 8 | (*puStack_28 & 0xff0000) >> 8
                  | *puStack_28 >> 0x18;
    puVar1 = (uint *)(param_2 + 0x40);
    *puVar1 = *puVar1 << 0x18 | (*puVar1 & 0xff00) << 8 | (*puVar1 & 0xff0000) >> 8 |
              *puVar1 >> 0x18;
    puStack_24 = (uint *)(param_2 + 0x44);
    *puStack_24 = *puStack_24 << 0x18 | (*puStack_24 & 0xff00) << 8 | (*puStack_24 & 0xff0000) >> 8
                  | *puStack_24 >> 0x18;
    puStack_30 = (uint *)(param_2 + 0x40);
    FUN_001d507c(param_1,0,*(undefined2 *)puStack_28);
    cStack_40 = '\'';
    FUN_001dbd0c(param_1);
    if (*(int *)(param_1 + 0x5b8) != 0) {
      (**(code **)(param_1 + 0x5b8))(&cStack_40,puStack_30);
    }
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    break;
  case 0x2f:
    if (*(int *)(param_1 + 0x584) != 0) {
      (**(code **)(param_1 + 0x584))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x32:
    FUN_001d9354(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5fc) != 0) {
      (**(code **)(param_1 + 0x5fc))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x3d:
    FUN_001d9b6c(param_1,param_2);
    break;
  case 0x40:
    FUN_001d89f8(param_2 + 0x3c);
    if (((*(ushort *)(param_2 + 0x2c) & 0x1000) == 0) && (*(int *)(param_1 + 0x600) != 0)) {
      (**(code **)(param_1 + 0x600))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x44:
    FUN_001d8b60(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x608) != 0) {
      (**(code **)(param_1 + 0x608))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x45:
    FUN_001d8c10(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x60c) != 0) {
      (**(code **)(param_1 + 0x60c))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x46:
    FUN_001d8cc0(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x610) != 0) {
      (**(code **)(param_1 + 0x610))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x6b:
    FUN_001d91c0(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5f4) != 0) {
      (**(code **)(param_1 + 0x5f4))(&cStack_40,param_2 + 0x3c);
    }
    break;
  case 0x75:
    FUN_001d91c0(param_2 + 0x3c);
    if (*(int *)(param_1 + 0x5f8) != 0) {
      (**(code **)(param_1 + 0x5f8))(&cStack_40,param_2 + 0x3c);
    }
  }
  return;
}

