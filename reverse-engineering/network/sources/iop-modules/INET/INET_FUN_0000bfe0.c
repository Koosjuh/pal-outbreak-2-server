FUNCTION FUN_0000bfe0 @ 0x0000bfe0 size=508
CALLERS (1): FUN_0000cdd4@0x0000cdd4
CALLEES (1): FUN_0000ae24@0x0000ae24

char * FUN_0000bfe0(ushort *param_1,int param_2,char *param_3,ushort param_4,int param_5)

{
  char cVar1;
  ushort *puVar2;
  ushort *puVar3;
  char *pcVar4;
  
  FUN_0000ae24();
  *param_1 = param_4;
  param_1[1] = param_1[1] & 0xf087 | 1;
  cVar1 = *param_3;
  param_3 = param_3 + 1;
  puVar3 = param_1 + 6;
  do {
    if (cVar1 == '\0') {
LAB_0000c0d8:
      if ((int)puVar3 - (int)param_1 < param_2) {
        *(char *)puVar3 = '\0';
        pcVar4 = (char *)0xffffffff;
        if (((int)puVar3 + 1) - (int)(param_1 + -2) <= param_2) {
          cVar1 = '\x01';
          if (0 < param_5) {
            cVar1 = '\f';
          }
          *(char *)((int)puVar3 + 1) = '\0';
          *(char *)(puVar3 + 1) = cVar1;
          *(char *)((int)puVar3 + 3) = '\0';
          *(char *)(puVar3 + 2) = '\x01';
          pcVar4 = (char *)((int)puVar3 + (5 - (int)param_1));
          param_1[2] = 1;
          *param_1 = *param_1 << 8 | *param_1 >> 8;
          param_1[2] = param_1[2] << 8 | param_1[2] >> 8;
          param_1[3] = param_1[3] << 8 | param_1[3] >> 8;
          param_1[4] = param_1[4] << 8 | param_1[4] >> 8;
          param_1[5] = param_1[5] << 8 | param_1[5] >> 8;
        }
      }
      else {
        pcVar4 = (char *)0xffffffff;
      }
      return pcVar4;
    }
    puVar2 = (ushort *)((int)puVar3 + 1);
    do {
      if (cVar1 == '.') {
        cVar1 = *param_3;
        param_3 = param_3 + 1;
        break;
      }
      if (cVar1 == '\\') {
        cVar1 = *param_3;
        param_3 = param_3 + 1;
        if (cVar1 == '\0') break;
      }
      if (param_2 <= (int)puVar2 - (int)param_1) {
        return (char *)0xffffffff;
      }
      *(char *)puVar2 = cVar1;
      puVar2 = (ushort *)((int)puVar2 + 1);
      cVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)((int)puVar2 + (-1 - (int)puVar3));
    if ((pcVar4 == (char *)0x0) && (cVar1 == '\0')) {
      puVar3 = (ushort *)((int)puVar2 + -1);
      goto LAB_0000c0d8;
    }
    if ((char *)0x3e < (char *)((int)puVar2 + (-2 - (int)puVar3))) {
      return (char *)0xffffffff;
    }
    *(char *)puVar3 = (char)pcVar4;
    puVar3 = puVar2;
  } while( true );
}


================================================================