# UNDECODABLE — functions the Ghidra decompiler cannot lift (38)

These emit `halt_baddata()` (misaligned data-as-code, VU/MMI/COP macros, or overlay-relocation
artifacts). Their records preserve every recoverable low-level fact and are honestly marked opaque.
**To finish these:** corrected raw MIPS disassembly (Ghidra listing / live single-step), not the C
decompiler. None are on a rig-Confirmed protocol path; most are UI draw-macros or teardown leaves.

| Address | Name | Subsystem | Record |
|---|---|---|---|
| 0x005adc80 | box_arg_stub (opaque leaf accessor) | unknown | functions/unknown/005adc80_FUN_005adc80.md |
| 0x005af2c0 | ui_draw_set_color | ui | functions/ui/005af2c0_ui_draw_set_color.md |
| 0x005af2e0 | ui_draw_set_size | ui | functions/ui/005af2e0_ui_draw_set_size.md |
| 0x005af3c0 | draw_macro_stub_3c0 | unknown | functions/unknown/005af3c0_FUN_005af3c0.md |
| 0x005af3e0 | draw_macro_stub_3e0 | unknown | functions/unknown/005af3e0_FUN_005af3e0.md |
| 0x005af400 | draw_macro_stub_400 | unknown | functions/unknown/005af400_FUN_005af400.md |
| 0x005af420 | draw_macro_stub_420 | unknown | functions/unknown/005af420_FUN_005af420.md |
| 0x005b24c0 | FUN_005b24c0 (undecodable) | unknown | functions/unknown/005b24c0_FUN_005b24c0.md |
| 0x005be060 | FUN_005be060 (undecoded leaf) | unknown | functions/unknown/005be060_FUN_005be060.md |
| 0x005be080 | FUN_005be080 (undecoded leaf) | unknown | functions/unknown/005be080_FUN_005be080.md |
| 0x005c4370 | FUN_005c4370 (undecodable) | unknown | functions/unknown/005c4370_FUN_005c4370.md |
| 0x005d7690 | FUN_005d7690 | unknown | functions/unknown/005d7690_FUN_005d7690.md |
| 0x005de0f0 | loader_abort_stub | unknown | functions/unknown/005de0f0_FUN_005de0f0.md |
| 0x005dedb0 | FUN_005dedb0 | unknown | functions/unknown/005dedb0_FUN_005dedb0.md |
| 0x005dee40 | get_overlay_context (hypothesis) | unknown | functions/unknown/005dee40_FUN_005dee40.md |
| 0x005ef200 | FUN_005ef200 | unknown | functions/unknown/005ef200_FUN_005ef200.md |
| 0x005f52e0 | FUN_005f52e0 (softkbd_reset_tail [inferred]) | unknown | functions/unknown/005f52e0_FUN_005f52e0.md |
| 0x005f5ea0 | FUN_005f5ea0 (node_set_state10 [inferred]) | unknown | functions/unknown/005f5ea0_FUN_005f5ea0.md |
| 0x00605f80 | FUN_00605f80 (opaque stub) | unknown | functions/unknown/00605f80_FUN_00605f80.md |
| 0x006063a0 | FUN_006063a0 (opaque stub) | unknown | functions/unknown/006063a0_FUN_006063a0.md |
| 0x0060f0c0 | FUN_0060f0c0 | unknown | functions/unknown/0060f0c0_FUN_0060f0c0.md |
| 0x0060f150 | FUN_0060f150 | unknown | functions/unknown/0060f150_FUN_0060f150.md |
| 0x00614750 | FUN_00614750 (thunk/alignment region) | unknown | functions/unknown/00614750_FUN_00614750.md |
| 0x00616768 | FUN_00616768 (unrecovered_pic_trampoline) | unknown | functions/unknown/00616768_FUN_00616768.md |
| 0x006185f0 | FUN_006185f0 | helpers | functions/helpers/006185f0_FUN_006185f0.md |
| 0x00618c20 | FUN_00618c20 | helpers | functions/helpers/00618c20_FUN_00618c20.md |
| 0x0061e630 | FUN_0061e630 | unknown | functions/unknown/0061e630_FUN_0061e630.md |
| 0x0061e640 | FUN_0061e640 | unknown | functions/unknown/0061e640_FUN_0061e640.md |
| 0x0061e720 | menu_input_feedback_e720 [inferred] | unknown | functions/unknown/0061e720_FUN_0061e720.md |
| 0x0061e730 | input_bit10_action_e730 [inferred] | unknown | functions/unknown/0061e730_FUN_0061e730.md |
| 0x0061e740 | input_bit200_action_e740 [inferred] | unknown | functions/unknown/0061e740_FUN_0061e740.md |
| 0x0061e940 | input_sample_reset | ui | functions/ui/0061e940_input_sample_reset.md |
| 0x0061ea30 | FUN_0061ea30 | unknown | functions/unknown/0061ea30_FUN_0061ea30.md |
| 0x0061f8b0 | FUN_0061f8b0 | unknown | functions/unknown/0061f8b0_FUN_0061f8b0.md |
| 0x00627ae0 | FUN_00627ae0 | unknown | functions/unknown/00627ae0_FUN_00627ae0.md |
| 0x0062a5c0 | FUN_0062a5c0 | unknown | functions/unknown/0062a5c0_FUN_0062a5c0.md |
| 0x0062b9e0 | FUN_0062b9e0 | unknown | functions/unknown/0062b9e0_FUN_0062b9e0.md |
| 0x006386f0 | halt_baddata_stub | unknown | functions/unknown/006386f0_halt_baddata_stub.md |
