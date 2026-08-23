FUNCTION FUN_0060ba40 @ 0x0060ba40  size=532
CALLERS (1): FUN_00608c80@0x00608c80
CALLEES (1): FUN_0060b410@0x0060b410
----------------------------------------------------------------

long FUN_0060ba40(ulong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,
                 int param_9)

{
  long lVar1;
  long lVar2;
  
  lVar1 = (**(code **)(param_9 + 0x28))(*(undefined4 *)(param_9 + 0x30),0x120,4);
  if (lVar1 == 0) {
    lVar2 = -4;
  }
  else {
    lVar2 = FUN_0060b410(param_3,param_1,0x101,0x693340,0x6933c0,param_6,param_4,param_8);
    if ((lVar2 == 0) && (*(int *)param_4 != 0)) {
      lVar2 = FUN_0060b410((int)param_3 + (int)param_1 * 4,param_2,0,0x693440,0x6934c0,param_7,
                           param_5);
      if ((lVar2 == 0) && ((*(int *)param_5 != 0 || (param_1 < 0x102)))) {
        (**(code **)(param_9 + 0x2c))(*(undefined4 *)(param_9 + 0x30),lVar1);
        lVar2 = 0;
      }
      else {
        if (lVar2 == -3) {
          *(char **)(param_9 + 0x20) = s_oversubscribed_distance_tree_0064a3b0;
        }
        else if (lVar2 == -5) {
          *(char **)(param_9 + 0x20) = s_incomplete_distance_tree_0064a3d0;
          lVar2 = -3;
        }
        else if (lVar2 != -4) {
          lVar2 = -3;
          *(char **)(param_9 + 0x20) = s_empty_distance_tree_with_lengths_0064a3f0;
        }
        (**(code **)(param_9 + 0x2c))(*(undefined4 *)(param_9 + 0x30),lVar1);
      }
    }
    else {
      if (lVar2 == -3) {
        *(char **)(param_9 + 0x20) = s_oversubscribed_literal_length_tr_0064a360;
      }
      else if (lVar2 != -4) {
        lVar2 = -3;
        *(char **)(param_9 + 0x20) = s_incomplete_literal_length_tree_0064a390;
      }
      (**(code **)(param_9 + 0x2c))(*(undefined4 *)(param_9 + 0x30),lVar1);
    }
  }
  return lVar2;
}



================================================================