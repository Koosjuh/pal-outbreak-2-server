FUNCTION FUN_0060ae40 @ 0x0060ae40  size=1488
CALLERS (1): FUN_0060c6e0@0x0060c6e0
CALLEES (2): FUN_00608ab0@0x00608ab0, FUN_00608c80@0x00608c80
----------------------------------------------------------------

long FUN_0060ae40(long param_1,int param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  int *piVar7;
  
  if (((param_1 == 0) || (piVar7 = (int *)param_1, piVar7[9] == 0)) || (*piVar7 == 0)) {
    return -2;
  }
  if (param_2 == 4) {
    lVar6 = -5;
  }
  else {
    lVar6 = 0;
  }
  lVar4 = -5;
  do {
    puVar2 = (undefined1 *)piVar7[9];
    switch(*puVar2) {
    case 0:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      uVar5 = (uint)*pbVar3;
      *(uint *)(piVar7[9] + 8) = uVar5;
      if ((uVar5 & 0xf) != 8) {
        *(undefined1 *)piVar7[9] = 0xd;
        piVar7[8] = (int)s_unknown_compression_method_0064a270;
        *(undefined4 *)(piVar7[9] + 8) = 5;
        lVar4 = lVar6;
        break;
      }
      puVar2 = (undefined1 *)piVar7[9];
      if (*(uint *)(puVar2 + 0x1c) < (*(uint *)(puVar2 + 8) >> 4) + 8) {
        *puVar2 = 0xd;
        piVar7[8] = (int)s_invalid_window_size_0064a290;
        *(undefined4 *)(piVar7[9] + 8) = 5;
        lVar4 = lVar6;
        break;
      }
      *puVar2 = 1;
      lVar4 = lVar6;
    case 1:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      puVar2 = (undefined1 *)piVar7[9];
      bVar1 = *pbVar3;
      if ((int)(*(int *)(puVar2 + 8) * 0x100 + (uint)bVar1) % 0x1f == 0) {
        if ((bVar1 & 0x20) != 0) {
          *puVar2 = 2;
          lVar4 = lVar6;
          goto switchD_0060aec0_caseD_2;
        }
        *puVar2 = 7;
        lVar4 = lVar6;
      }
      else {
        *puVar2 = 0xd;
        piVar7[8] = (int)s_incorrect_header_check_0064a2b0;
        *(undefined4 *)(piVar7[9] + 8) = 5;
        lVar4 = lVar6;
      }
      break;
    case 2:
switchD_0060aec0_caseD_2:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = (ulong)*pbVar3 << 0x18;
      *(undefined1 *)piVar7[9] = 3;
      lVar4 = lVar6;
switchD_0060aec0_caseD_3:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3 * 0x10000;
      *(undefined1 *)piVar7[9] = 4;
      lVar4 = lVar6;
switchD_0060aec0_caseD_4:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3 * 0x100;
      *(undefined1 *)piVar7[9] = 5;
      lVar4 = lVar6;
switchD_0060aec0_caseD_5:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3;
      *(undefined8 *)(piVar7 + 0xe) = *(undefined8 *)(piVar7[9] + 0x10);
      *(undefined1 *)piVar7[9] = 6;
      return 2;
    case 3:
      goto switchD_0060aec0_caseD_3;
    case 4:
      goto switchD_0060aec0_caseD_4;
    case 5:
      goto switchD_0060aec0_caseD_5;
    case 6:
      *puVar2 = 0xd;
      piVar7[8] = (int)s_need_dictionary_0064a2d0;
      *(undefined4 *)(piVar7[9] + 8) = 0;
      return -2;
    case 7:
      lVar4 = FUN_00608c80(*(undefined4 *)(puVar2 + 0x20),param_1,lVar4);
      if (lVar4 == -3) {
        *(undefined1 *)piVar7[9] = 0xd;
        *(undefined4 *)(piVar7[9] + 8) = 0;
        lVar4 = -3;
      }
      else {
        if (lVar4 == 0) {
          lVar4 = lVar6;
        }
        if (lVar4 != 1) {
          return lVar4;
        }
        FUN_00608ab0(*(undefined4 *)(piVar7[9] + 0x20),param_1,piVar7[9] + 8);
        puVar2 = (undefined1 *)piVar7[9];
        if (*(int *)(puVar2 + 0x18) == 0) {
          *puVar2 = 8;
          lVar4 = lVar6;
          goto switchD_0060aec0_caseD_8;
        }
        *puVar2 = 0xc;
        lVar4 = lVar6;
      }
      break;
    case 8:
switchD_0060aec0_caseD_8:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = (ulong)*pbVar3 << 0x18;
      *(undefined1 *)piVar7[9] = 9;
      lVar4 = lVar6;
switchD_0060aec0_caseD_9:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3 * 0x10000;
      *(undefined1 *)piVar7[9] = 10;
      lVar4 = lVar6;
switchD_0060aec0_caseD_a:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3 * 0x100;
      *(undefined1 *)piVar7[9] = 0xb;
      lVar4 = lVar6;
switchD_0060aec0_caseD_b:
      if (piVar7[1] == 0) {
        return lVar4;
      }
      piVar7[1] = piVar7[1] + -1;
      *(long *)(piVar7 + 2) = *(long *)(piVar7 + 2) + 1;
      pbVar3 = (byte *)*piVar7;
      *piVar7 = (int)(pbVar3 + 1);
      *(ulong *)(piVar7[9] + 0x10) = *(long *)(piVar7[9] + 0x10) + (ulong)*pbVar3;
      puVar2 = (undefined1 *)piVar7[9];
      if (*(long *)(puVar2 + 8) == *(long *)(puVar2 + 0x10)) {
        *puVar2 = 0xc;
LAB_0060b3fc:
        return 1;
      }
      *puVar2 = 0xd;
      piVar7[8] = (int)s_incorrect_data_check_0064a2e0;
      *(undefined4 *)(piVar7[9] + 8) = 5;
      lVar4 = lVar6;
      break;
    case 9:
      goto switchD_0060aec0_caseD_9;
    case 10:
      goto switchD_0060aec0_caseD_a;
    case 0xb:
      goto switchD_0060aec0_caseD_b;
    case 0xc:
      goto LAB_0060b3fc;
    case 0xd:
      return -3;
    default:
      return -2;
    }
  } while( true );
}



================================================================