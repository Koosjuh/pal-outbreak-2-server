FUNCTION FUN_00017540 @ 0x00017540 size=108
CALLERS (3): FUN_00013b50@0x00013b50, FUN_0001380c@0x0001380c, FUN_00013fd4@0x00013fd4
CALLEES (2): FUN_00019a40@0x00019a40, FUN_00019a60@0x00019a60

int FUN_00017540(void)

{
  undefined1 auStack_18 [8];
  int local_10;
  int local_c;
  
  FUN_00019a40(auStack_18);
  FUN_00019a60(auStack_18,&local_10,&local_c);
  return local_10 * 1000 + (local_c + 500) / 1000;
}


================================================================