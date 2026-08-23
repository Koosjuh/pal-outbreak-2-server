
void FUN_001c0e60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  FUN_001c0670(1,0x1b,1,0x248470,*(undefined2 *)param_4,*(char *)param_1,*(undefined1 *)param_2,
               *(undefined1 *)param_3);
  (*(code *)(&PTR_FUN_00248460)[*(char *)param_1])
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

