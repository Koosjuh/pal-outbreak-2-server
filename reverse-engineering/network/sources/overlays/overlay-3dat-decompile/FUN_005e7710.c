FUNCTION FUN_005e7710 @ 0x005e7710  size=800
CALLERS (1): FUN_005e7e30@0x005e7e30
CALLEES (2): FUN_005ec100@0x005ec100, FUN_005ec4f0@0x005ec4f0
----------------------------------------------------------------

void FUN_005e7710(undefined1 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *puRam007012a0 = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x186) = param_1;
  *(undefined2 *)(puRam007012a0 + 0x62) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x17f) = 0;
  puRam007012a0[2] = 0;
  puRam007012a0[3] = 0;
  puRam007012a0[1] = 0;
  *(undefined1 *)(puRam007012a0 + 0x3639) = 0;
  *(undefined2 *)(puRam007012a0 + 0x3630) = 0;
  *(undefined2 *)(puRam007012a0 + 0x362f) = 0;
  *(undefined2 *)((int)puRam007012a0 + 0xd8c2) = 0;
  *(undefined2 *)((int)puRam007012a0 + 0xd8be) = 0;
  *(undefined2 *)(puRam007012a0 + 6) = 0;
  *(undefined2 *)(puRam007012a0 + 0x3632) = 0;
  *(undefined1 *)(puRam007012a0 + 0x3633) = 0;
  puRam007012a0[7] = 0;
  *(undefined2 *)(puRam007012a0 + 0x3624) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0xd892) = 0;
  *(undefined2 *)(puRam007012a0 + 0x3625) = 0;
  *(undefined2 *)((int)puRam007012a0 + 0xd896) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x18b) = 0;
  *(undefined1 *)(puRam007012a0 + 99) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x18d) = 0;
  *(undefined1 *)(puRam007012a0 + 5) = 0;
  *(undefined1 *)(puRam007012a0 + 0x5f) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x17e) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x17d) = 0;
  *(undefined2 *)((int)puRam007012a0 + 0x12) = 0;
  func_0x00109eb8((int)puRam007012a0 + 0x2a3,0x648220);
  func_0x00109eb8((int)puRam007012a0 + 0x2b3,0x648228);
  func_0x00109eb8((int)puRam007012a0 + 0x193,0x648230);
  func_0x00109eb8((int)puRam007012a0 + 0x1a3,0x648238);
  *(undefined2 *)(puRam007012a0 + 0x49) = 0;
  *(undefined1 *)((int)puRam007012a0 + *(short *)(puRam007012a0 + 0x49) + 0x168) = 3;
  puVar1 = puRam007012a0;
  uVar2 = FUN_005ec4f0((int)puRam007012a0 + 0x2a3);
  puVar1[*(short *)(puVar1 + 0x49) + 0x4a] = uVar2;
  uVar2 = FUN_005ec4f0((int)puRam007012a0 + 0x193);
  puRam007012a0[0x48] = uVar2;
  uVar2 = FUN_005ec4f0((int)puRam007012a0 + 0x2b3);
  puRam007012a0[0x5e] = uVar2;
  FUN_005ec100(*(undefined1 *)(puRam007012a0 + 0x5f));
  func_0x00106b60(puRam007012a0 + 0x448,0,0x108);
  *(undefined1 *)((int)puRam007012a0 + 0x18e) = 0;
  *(undefined1 *)((int)puRam007012a0 + 399) = 0;
  *(undefined1 *)(puRam007012a0 + 100) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x191) = 0;
  *(undefined1 *)((int)puRam007012a0 + 0x192) = 0;
  func_0x00106b60((int)puRam007012a0 + 0xfac1,0,0x100);
  return;
}



================================================================