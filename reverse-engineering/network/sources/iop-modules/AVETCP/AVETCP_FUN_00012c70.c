FUNCTION FUN_00012c70 @ 0x00012c70 size=52
CALLERS (0): 
CALLEES (2): FUN_00014f64@0x00014f64, FUN_00014f6c@0x00014f6c

int FUN_00012c70(void)

{
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [4];
  int local_c;
  
  FUN_00014f64(auStack_18);
  FUN_00014f6c(auStack_18,auStack_10,&local_c);
  return local_c >> 2;
}


================================================================