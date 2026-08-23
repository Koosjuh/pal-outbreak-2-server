FUNCTION FUN_006038f0 @ 0x006038f0  size=80
CALLERS (1): FUN_00602700@0x00602700
CALLEES (0): 
----------------------------------------------------------------

undefined2 * FUN_006038f0(undefined2 *param_1,undefined2 param_2,undefined2 *param_3)

{
  *param_1 = param_2;
  if (param_1 + 1 != param_3) {
    func_0x00109eb8(param_1 + 1,param_3);
  }
  cRam006c553a = cRam006c553a + '\x01';
  return param_1 + 0x40;
}



================================================================