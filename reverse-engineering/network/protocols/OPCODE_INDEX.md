# OPCODE_INDEX — functions touching each opcode

_Auto-generated from indexes/opcodes_seen.json. Role inferred from summary keywords (verify per record)._

## 0x00

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c4100 snap_send_session_hello | session | builder |

## 0x01

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c3c90 build_packet_header | packets | builder |
| 0x001ef540 snap_req_op01_session_open | session | builder |
| 0x005c4d20 send_op01_to_conn | packets | builder |
| 0x005d7420 build_req_op01 | rooms | builder |
| 0x005d76b0 build_req_op01_sub2 | rooms | builder |

## 0x02

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c3c90 build_packet_header | packets | builder |
| 0x001dbd0c snap_send_close | session | builder |
| 0x001dbe60 snap_close | session | builder |
| 0x001ef5c0 snap_req_op02 | session | builder |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5ff0 send_op02 | session | builder |

## 0x03

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dbefc snap_send_op03 | session | builder |
| 0x005bb8e0 lobby_area_population_increment | lobby |  |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5bb0 send_op03 | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |
| 0x005d74a0 build_req_op03 | rooms | builder |

## 0x04

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d0040 libsnap_send_op04_create_slot | session | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dc310 snap_send_op05_data | rooms | builder |
| 0x001dc508 snap_send_create_room | rooms | builder |
| 0x005b41b0 create_room_entry_sm | rooms |  |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5c10 send_op04_create_slot | rooms | builder |
| 0x005d70b0 build_req_enter_or_create | rooms | builder |
| 0x005d7760 session_enter_dispatch | session |  |
| 0x00603d90 roster_ctx_finish_by_opcode | rooms |  |
| 0x00603e40 roster_ctx_state_machine | rooms |  |

## 0x05

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c8dd0 snap_send_op05_or_finalize | session | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dc804 snap_send_op05 | rooms | builder |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5d30 send_op05 | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |
| 0x005d71e0 build_req_enter_or_prev | rooms | builder |
| 0x005d7760 session_enter_dispatch | session |  |

## 0x06

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001cfa30 libsnap_send_op06_member_join | session | builder |
| 0x001d0fe0 close_op06_join_channel | transport |  |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dc9fc snap_send_join | rooms | builder |
| 0x001dcbf4 snap_send_join_named | rooms | builder |
| 0x001dcdfc snap_send_op06_var | rooms | builder |
| 0x001ef4f0 snap_req_op06_join | session | builder |
| 0x005b3ed0 roomjoin_state2_enter | rooms | builder |
| 0x005bb670 room_member_leave_and_roster_refresh | roster | dispatcher |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c3490 room_enter_commit_sm | rooms | builder |
| 0x005c5db0 send_op06_member_join | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |
| 0x005c9690 room_enter_state_handler | rooms | builder |
| 0x005ca0a0 inroom_member_tick | rooms | builder |
| 0x005d70b0 build_req_enter_or_create | rooms | builder |
| 0x005d71e0 build_req_enter_or_prev | rooms | builder |
| 0x005d7320 build_req_op06_refresh | rooms | builder |
| 0x005d7760 session_enter_dispatch | session |  |
| 0x005d7e00 txn_begin_enter | session | builder |

## 0x07

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001cfc90 send_op07_and_load_table | menus | builder |
| 0x001dd07c snap_send_leave | rooms | builder |
| 0x001dd1dc snap_send_leave_nodata | rooms | builder |
| 0x001ef610 snap_req_op07_leave | session | builder |
| 0x005bb980 lobby_area_population_decrement | lobby |  |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5e30 send_op07_charstats | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |
| 0x005ce530 room_confirm_nav_input | rooms | builder |

## 0x08

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001cfb30 send_op08_message | rooms | builder |
| 0x001dd33c snap_send_register | session | builder |
| 0x001ef690 snap_req_op08_leave | session | builder |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5eb0 send_op08 | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |

## 0x09

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001cf8e0 send_op09_register_member | roster | builder |
| 0x001dd5f8 snap_send_op09_nodata | rooms | builder |
| 0x001dd840 snap_send_op09 | rooms | builder |
| 0x005b25c0 lobby_init_and_register_handlers | session | builder |
| 0x005c5cd0 send_op09_register | roster | builder |
| 0x005c6500 room_roster_sync_sm | rooms | builder |
| 0x00627d40 msg_task_init_state9 | rooms |  |
| 0x006290e0 charsel_register_send_step | rooms | builder |

## 0x0a

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c8f50 snap_send_op0a_memberlist_req | roster | builder |
| 0x001d0230 build_and_send_list_screen_msg | roster | builder |
| 0x001ddee8 snap_send_op0a_memberlist_req | roster | builder |
| 0x001de0c0 snap_send_op0a_memberlist_req_alt | roster | builder |
| 0x001ef710 snap_req_op0a_member_list | roster | builder |
| 0x005bc430 roster_member_update_and_redraw | roster | dispatcher |
| 0x005c3370 scenario_member_scan_reply_cb | roster | handler |
| 0x005c5f10 send_op0a_member_list | roster | builder |

## 0x0b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d0400 send_op0b_small | rooms | builder |
| 0x001dda88 snap_send_op0b | rooms | builder |
| 0x001ef770 snap_req_op0b | session | builder |
| 0x005bc590 handle_name_register_reply | session | dispatcher |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c5f70 send_op0b_word | rooms | builder |
| 0x005cf1e0 room_exit_input_handler | rooms | builder |

## 0x0c

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001de470 snap_send_prepare | rooms | builder |
| 0x001ef7d0 snap_req_op0c_prepare | session | builder |
| 0x005c3490 room_enter_commit_sm | rooms | builder |
| 0x005c6050 send_op0c_prepare | rooms | builder |
| 0x00603d90 roster_ctx_finish_by_opcode | rooms |  |
| 0x00603e40 roster_ctx_state_machine | rooms |  |
| 0x00604180 member_sync_state_machine | roster | builder |

## 0x0d

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c94c0 snap_send_op0d_data_chunk | session | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001de648 snap_send_op0d | rooms | builder |
| 0x005bc590 handle_name_register_reply | session | dispatcher |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |

## 0x0e

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c4070 snap_send_op0e_flush | transport | builder |
| 0x001ddc60 snap_send_op0e | rooms | builder |
| 0x001ef830 snap_req_op0e_query3 | session | builder |
| 0x005bc790 handle_name_reply_simple | session | dispatcher |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |
| 0x005c6150 send_op0e_bare | rooms | builder |

## 0x0f

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c46a0 snap_send_op0f_request | session | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001de840 snap_send_op0f_reliable | chat | builder |
| 0x001df1d8 snap_send_op0f_unrel | chat | builder |
| 0x001ef8d0 snap_send_op0f_data | packets | builder |
| 0x005c61b0 send_op0f_bare | rooms | builder |

## 0x10

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c3c90 build_packet_header | packets | builder |
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001de9e8 snap_send_op10_multi | rooms | builder |
| 0x001ded08 snap_send_op10_multi_ptr | rooms | builder |
| 0x001df380 snap_send_op10_multi_unrel | rooms | builder |
| 0x001df66c snap_send_op10_multi_unrel_ptr | rooms | builder |
| 0x001ef9a0 snap_send_op10_roominfo | packets | builder |
| 0x005c5c70 send_op10_room_info | rooms | builder |

## 0x11

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dfbf8 snap_send_op11_unrel | chat | builder |
| 0x005c60d0 send_op11_word | rooms | builder |
| 0x00628110 query_op11_send_step | rooms | builder |

## 0x12

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c48c0 snap_send_op12_named_request | lobby | builder |
| 0x001c4960 recv_download_setup_A | lobby | handler |
| 0x001df9a8 snap_send_op12 | session | builder |
| 0x001efa70 snap_recv_op12_data | packets | builder |

## 0x13

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001dfad0 snap_send_op13 | session | builder |
| 0x001efb80 snap_recv_op13_data | packets | builder |
| 0x005bba20 inroom_subevent_dispatcher | rooms | dispatcher |
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |

## 0x14

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c4c80 snap_send_op14_chunk_request_A | lobby | builder |
| 0x001c4d40 recv_download_chunk_A | lobby | handler |
| 0x001dfda0 snap_send_op14_seq | rooms | builder |

## 0x15

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005bc860 register_snap_message_handlers | transport | dispatcher |

## 0x16

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c4560 snap_send_op16_request | session | builder |
| 0x001efcf0 snap_req_op16_query3 | session | builder |

## 0x17

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001efda0 snap_req_op17 | session | builder |

## 0x18

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c42d0 snap_send_op18_request | session | builder |
| 0x001efee0 snap_req_op18 | session | builder |

## 0x19

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001eff60 snap_send_op19_data_padded | packets | builder |

## 0x1a

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c43c0 snap_send_op1a_request | session | builder |

## 0x1c

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c6dc0 snap_send_op1c_roomlist_request | rooms | builder |
| 0x001efe00 snap_req_op1c_roomlist | session | builder |

## 0x1d

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001efe70 snap_req_op1d_roomlist | session | builder |

## 0x1e

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c7580 snap_send_op1e_detail_request | rooms | builder |
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x1f

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x20

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c7000 snap_send_op20_roomlist_page_request | rooms | builder |

## 0x22

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c7980 snap_send_op22_request | rooms | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x23

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x00627d60 member_op23_task_dispatch | roster | builder |
| 0x00627ea0 member_list_send_init | roster | builder |
| 0x00627f20 member_list_reply_process | roster | builder |

## 0x24

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c85c0 snap_send_op24_member_batch | roster | builder |

## 0x25

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001dff7c snap_send_op25_name2int | rooms | builder |

## 0x26

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c5900 snap_send_op26_create_prepare | rooms | builder |

## 0x28

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c67b0 snap_send_op28_request | session | builder |

## 0x29

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x2a

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9678 snap_connect_reply_handler | session | handler |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x2b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c5bd0 snap_send_op2b_enter_request | rooms | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x2c

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001db7e8 snap_session_open | session | builder |

## 0x2d

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c5a20 recv_op2d_transfer_setup | rooms | parser |
| 0x001c5c90 recv_conn_data_chunk | rooms |  |
| 0x001c5ea0 snap_send_op2d_request | rooms | builder |
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x2e

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x2f

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c6060 snap_send_op2f_chunk_request_D | lobby | builder |
| 0x001c6130 recv_download_chunk_D | lobby | handler |
| 0x005c1f30 build_msg_op6e_variant | packets | builder |

## 0x31

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c6330 snap_send_op31_finalize | lobby | builder |

## 0x32

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001df044 snap_send_op32_unrel | chat | builder |

## 0x33

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c64f0 snap_send_op33_chunk_request_E | lobby | builder |
| 0x001c65c0 recv_download_chunk_E | lobby | handler |

## 0x34

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001e0188 snap_send_op34_string | chat | builder |

## 0x35

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c8b60 snap_send_op35_record | session | builder |
| 0x005c1e70 build_msg_register_variant | packets | builder |

## 0x37

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x39

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c4fb0 snap_send_op39_request | lobby | builder |
| 0x001c5040 recv_download_setup_B | lobby | handler |

## 0x3b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c51a0 snap_send_op3b_chunk_request_B | lobby | builder |
| 0x001c5260 recv_download_chunk_B | lobby | handler |

## 0x3d

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c5480 snap_send_op3d_request | lobby | builder |
| 0x001c5510 recv_download_setup_C | lobby | handler |
| 0x001d9b6c snap_keyexchange_reply | session | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x3e

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001e05c8 snap_send_op3e | chat | builder |
| 0x005c2080 build_msg_op70_variant | packets | builder |

## 0x3f

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c5630 snap_send_op3f_chunk_request_C | lobby | builder |
| 0x001c56f0 recv_download_chunk_C | lobby | handler |
| 0x001e0774 snap_send_op3f_hdr_blob | chat | builder |

## 0x40

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x41

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9b6c snap_keyexchange_reply | session | builder |
| 0x005c1f30 build_msg_op6e_variant | packets | builder |

## 0x43

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001de298 snap_send_op43 | menus | builder |
| 0x005c2080 build_msg_op70_variant | packets | builder |

## 0x44

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x45

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c69b0 snap_send_op45_request | lobby | builder |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x46

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001dc0b8 snap_send_op46 | rooms | builder |

## 0x47

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c6b90 snap_send_op47_chunk_request | lobby | builder |
| 0x001c6c60 recv_op47_download_chunk | lobby | handler |
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |
| 0x001ddda0 snap_send_op47 | rooms | builder |

## 0x48

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d84cc bswap_name_record | roster |  |
| 0x001d861c bswap_name_record_at8 | roster |  |
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |
| 0x001e094c snap_send_op48_name_query | roster | builder |
| 0x005bca90 send_name_query | roster | builder |

## 0x49

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001e0ed8 snap_build_op49_addr_register | rooms | builder |
| 0x005c1e70 build_msg_register_variant | packets | builder |

## 0x4a

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |
| 0x001efc90 snap_req_op4a | session | builder |

## 0x4b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x54

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x55

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x59

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001c9b00 snap_app_sm_pump | session | dispatcher |

## 0x62

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001ca410 snap_lookup_resolve_sm | session | builder |

## 0x63

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001ca410 snap_lookup_resolve_sm | session | builder |

## 0x64

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001ca410 snap_lookup_resolve_sm | session | builder |

## 0x6b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x6e

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c04f0 send_op6e_with_name | rooms | builder |
| 0x005c05c0 on_reply_create_enter_op6e | rooms | handler |
| 0x005c1f30 build_msg_op6e_variant | packets | builder |
| 0x005c1ff0 build_msg_op6e_data | packets | builder |

## 0x70

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c0750 room_commit_send_stat_op70 | rooms | builder |
| 0x005c2080 build_msg_op70_variant | packets | builder |

## 0x75

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x001d9f78 snap_app_msg_dispatch | packets | dispatcher |

## 0x7b

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c02b0 send_register_maxi | rooms | builder |
| 0x005c1e70 build_msg_register_variant | packets | builder |

## 0x86

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c0a00 request_member_list | roster | builder |
| 0x005c0ae0 on_reply_member_list | roster | handler |
| 0x005c0dc0 build_msg_op86 | packets | builder |

## 0x91

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c08b0 build_msg_op91 | packets | builder |

## 0xd3

| Function | Subsystem | Inferred role | 
|---|---|---|
| 0x005c2120 send_op_d3_prepare | rooms | builder |
| 0x005c21c0 on_reply_op_d3 | rooms | handler |
| 0x005c2250 build_msg_opd3 | packets | builder |

