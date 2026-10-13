#ifndef JIDAO_COMMAND_51_H_
#define JIDAO_COMMAND_51_H_

#include "emu8051.h"


// 这里是用来表示51单片机指令的函数声明
// 一切函数前缀都是emu
// 随后是指令小写
// 用相应字符来表示寄存器，寄存器首字母大写
// 如果操作数是@Rn形式的写成atRn
// 如果操作数是#data的形式写成iDate
// 对于变址寻址的@A+DPTR形式的写成atA_DPTR,以此类推

// ========== 算术运算 ==========
enum StatusCode emu_add_A_R0(struct Emu8051Core* core); // 0x28 0b00101000
enum StatusCode emu_add_A_R1(struct Emu8051Core* core); // 0x29 0b00101001
enum StatusCode emu_add_A_R2(struct Emu8051Core* core); // 0x2A 0b00101010
enum StatusCode emu_add_A_R3(struct Emu8051Core* core); // 0x2B 0b00101011
enum StatusCode emu_add_A_R4(struct Emu8051Core* core); // 0x2C 0b00101100
enum StatusCode emu_add_A_R5(struct Emu8051Core* core); // 0x2D 0b00101101
enum StatusCode emu_add_A_R6(struct Emu8051Core* core); // 0x2E 0b00101110
enum StatusCode emu_add_A_R7(struct Emu8051Core* core); // 0x2F 0b00101111
enum StatusCode emu_add_A_Direct(struct Emu8051Core* core); // 0x25 0b00100101
enum StatusCode emu_add_A_atR0(struct Emu8051Core* core); // 0x26 0b00100110
enum StatusCode emu_add_A_atR1(struct Emu8051Core* core); // 0x27 0b00100111
enum StatusCode emu_add_A_iData(struct Emu8051Core* core); // 0x24 0b00100100

enum StatusCode emu_addc_A_R0(struct Emu8051Core* core); // 0x38 0b00111000
enum StatusCode emu_addc_A_R1(struct Emu8051Core* core); // 0x39 0b00111001
enum StatusCode emu_addc_A_R2(struct Emu8051Core* core); // 0x3A 0b00111010
enum StatusCode emu_addc_A_R3(struct Emu8051Core* core); // 0x3B 0b00111011
enum StatusCode emu_addc_A_R4(struct Emu8051Core* core); // 0x3C 0b00111100
enum StatusCode emu_addc_A_R5(struct Emu8051Core* core); // 0x3D 0b00111101
enum StatusCode emu_addc_A_R6(struct Emu8051Core* core); // 0x3E 0b00111110
enum StatusCode emu_addc_A_R7(struct Emu8051Core* core); // 0x3F 0b00111111
enum StatusCode emu_addc_A_Direct(struct Emu8051Core* core); // 0x35 0b00110101
enum StatusCode emu_addc_A_atR0(struct Emu8051Core* core); // 0x36 0b00110110
enum StatusCode emu_addc_A_atR1(struct Emu8051Core* core); // 0x37 0b00110111
enum StatusCode emu_addc_A_iData(struct Emu8051Core* core); // 0x34 0b00110100

enum StatusCode emu_subb_A_R0(struct Emu8051Core* core); // 0x98 0b10011000
enum StatusCode emu_subb_A_R1(struct Emu8051Core* core); // 0x99 0b10011001
enum StatusCode emu_subb_A_R2(struct Emu8051Core* core); // 0x9A 0b10011010
enum StatusCode emu_subb_A_R3(struct Emu8051Core* core); // 0x9B 0b10011011
enum StatusCode emu_subb_A_R4(struct Emu8051Core* core); // 0x9C 0b10011100
enum StatusCode emu_subb_A_R5(struct Emu8051Core* core); // 0x9D 0b10011101
enum StatusCode emu_subb_A_R6(struct Emu8051Core* core); // 0x9E 0b10011110
enum StatusCode emu_subb_A_R7(struct Emu8051Core* core); // 0x9F 0b10011111
enum StatusCode emu_subb_A_Direct(struct Emu8051Core* core); // 0x95 0b10010101
enum StatusCode emu_subb_A_atR0(struct Emu8051Core* core); // 0x96 0b10010110
enum StatusCode emu_subb_A_atR1(struct Emu8051Core* core); // 0x97 0b10010111
enum StatusCode emu_subb_A_iData(struct Emu8051Core* core); // 0x94 0b10010100

enum StatusCode emu_inc_A(struct Emu8051Core* core); // 0x04 0b00000100
enum StatusCode emu_inc_R0(struct Emu8051Core* core); // 0x08 0b00001000
enum StatusCode emu_inc_R1(struct Emu8051Core* core); // 0x09 0b00001001
enum StatusCode emu_inc_R2(struct Emu8051Core* core); // 0x0A 0b00001010
enum StatusCode emu_inc_R3(struct Emu8051Core* core); // 0x0B 0b00001011
enum StatusCode emu_inc_R4(struct Emu8051Core* core); // 0x0C 0b00001100
enum StatusCode emu_inc_R5(struct Emu8051Core* core); // 0x0D 0b00001101
enum StatusCode emu_inc_R6(struct Emu8051Core* core); // 0x0E 0b00001110
enum StatusCode emu_inc_R7(struct Emu8051Core* core); // 0x0F 0b00001111
enum StatusCode emu_inc_Direct(struct Emu8051Core* core); // 0x05 0b00000101
enum StatusCode emu_inc_atR0(struct Emu8051Core* core); // 0x06 0b00000110
enum StatusCode emu_inc_atR1(struct Emu8051Core* core); // 0x07 0b00000111
enum StatusCode emu_inc_DPTR(struct Emu8051Core* core); // 0xA3 0b10100011

enum StatusCode emu_dec_A(struct Emu8051Core* core); // 0x14 0b00010100
enum StatusCode emu_dec_R0(struct Emu8051Core* core); // 0x18 0b00011000
enum StatusCode emu_dec_R1(struct Emu8051Core* core); // 0x19 0b00011001
enum StatusCode emu_dec_R2(struct Emu8051Core* core); // 0x1A 0b00011010
enum StatusCode emu_dec_R3(struct Emu8051Core* core); // 0x1B 0b00011011
enum StatusCode emu_dec_R4(struct Emu8051Core* core); // 0x1C 0b00011100
enum StatusCode emu_dec_R5(struct Emu8051Core* core); // 0x1D 0b00011101
enum StatusCode emu_dec_R6(struct Emu8051Core* core); // 0x1E 0b00011110
enum StatusCode emu_dec_R7(struct Emu8051Core* core); // 0x1F 0b00011111
enum StatusCode emu_dec_Direct(struct Emu8051Core* core); // 0x15 0b00010101
enum StatusCode emu_dec_atR0(struct Emu8051Core* core); // 0x16 0b00010110
enum StatusCode emu_dec_atR1(struct Emu8051Core* core); // 0x17 0b00010111

enum StatusCode emu_mul_AB(struct Emu8051Core* core); // 0xA4 0b10100100
enum StatusCode emu_div_AB(struct Emu8051Core* core); // 0x84 0b10000100
enum StatusCode emu_da_A(struct Emu8051Core* core); // 0xD4 0b11010100

// ========== 逻辑运算 ==========
enum StatusCode emu_anl_A_R0(struct Emu8051Core* core); // 0x58 0b01011000
enum StatusCode emu_anl_A_R1(struct Emu8051Core* core); // 0x59 0b01011001
enum StatusCode emu_anl_A_R2(struct Emu8051Core* core); // 0x5A 0b01011010
enum StatusCode emu_anl_A_R3(struct Emu8051Core* core); // 0x5B 0b01011011
enum StatusCode emu_anl_A_R4(struct Emu8051Core* core); // 0x5C 0b01011100
enum StatusCode emu_anl_A_R5(struct Emu8051Core* core); // 0x5D 0b01011101
enum StatusCode emu_anl_A_R6(struct Emu8051Core* core); // 0x5E 0b01011110
enum StatusCode emu_anl_A_R7(struct Emu8051Core* core); // 0x5F 0b01011111
enum StatusCode emu_anl_A_Direct(struct Emu8051Core* core); // 0x55 0b01010101
enum StatusCode emu_anl_A_atR0(struct Emu8051Core* core); // 0x56 0b01010110
enum StatusCode emu_anl_A_atR1(struct Emu8051Core* core); // 0x57 0b01010111
enum StatusCode emu_anl_A_iData(struct Emu8051Core* core); // 0x54 0b01010100
enum StatusCode emu_anl_Direct_A(struct Emu8051Core* core); // 0x52 0b01010010
enum StatusCode emu_anl_Direct_iData(struct Emu8051Core* core); // 0x53 0b01010011

enum StatusCode emu_orl_A_R0(struct Emu8051Core* core); // 0x48 0b01001000
enum StatusCode emu_orl_A_R1(struct Emu8051Core* core); // 0x49 0b01001001
enum StatusCode emu_orl_A_R2(struct Emu8051Core* core); // 0x4A 0b01001010
enum StatusCode emu_orl_A_R3(struct Emu8051Core* core); // 0x4B 0b01001011
enum StatusCode emu_orl_A_R4(struct Emu8051Core* core); // 0x4C 0b01001100
enum StatusCode emu_orl_A_R5(struct Emu8051Core* core); // 0x4D 0b01001101
enum StatusCode emu_orl_A_R6(struct Emu8051Core* core); // 0x4E 0b01001110
enum StatusCode emu_orl_A_R7(struct Emu8051Core* core); // 0x4F 0b01001111
enum StatusCode emu_orl_A_Direct(struct Emu8051Core* core); // 0x45 0b01000101
enum StatusCode emu_orl_A_atR0(struct Emu8051Core* core); // 0x46 0b01000110
enum StatusCode emu_orl_A_atR1(struct Emu8051Core* core); // 0x47 0b01000111
enum StatusCode emu_orl_A_iData(struct Emu8051Core* core); // 0x44 0b01000100
enum StatusCode emu_orl_Direct_A(struct Emu8051Core* core); // 0x42 0b01000010
enum StatusCode emu_orl_Direct_iData(struct Emu8051Core* core); // 0x43 0b01000011

enum StatusCode emu_xrl_A_R0(struct Emu8051Core* core); // 0x68 0b01101000
enum StatusCode emu_xrl_A_R1(struct Emu8051Core* core); // 0x69 0b01101001
enum StatusCode emu_xrl_A_R2(struct Emu8051Core* core); // 0x6A 0b01101010
enum StatusCode emu_xrl_A_R3(struct Emu8051Core* core); // 0x6B 0b01101011
enum StatusCode emu_xrl_A_R4(struct Emu8051Core* core); // 0x6C 0b01101100
enum StatusCode emu_xrl_A_R5(struct Emu8051Core* core); // 0x6D 0b01101101
enum StatusCode emu_xrl_A_R6(struct Emu8051Core* core); // 0x6E 0b01101110
enum StatusCode emu_xrl_A_R7(struct Emu8051Core* core); // 0x6F 0b01101111
enum StatusCode emu_xrl_A_Direct(struct Emu8051Core* core); // 0x65 0b01100101
enum StatusCode emu_xrl_A_atR0(struct Emu8051Core* core); // 0x66 0b01100110
enum StatusCode emu_xrl_A_atR1(struct Emu8051Core* core); // 0x67 0b01100111
enum StatusCode emu_xrl_A_iData(struct Emu8051Core* core); // 0x64 0b01100100
enum StatusCode emu_xrl_Direct_A(struct Emu8051Core* core); // 0x62 0b01100010
enum StatusCode emu_xrl_Direct_iData(struct Emu8051Core* core); // 0x63 0b01100011

enum StatusCode emu_clr_A(struct Emu8051Core* core); // 0xE4 0b11100100
enum StatusCode emu_cpl_A(struct Emu8051Core* core); // 0xF4 0b11110100
enum StatusCode emu_rl_A(struct Emu8051Core* core); // 0x23 0b00100011
enum StatusCode emu_rlc_A(struct Emu8051Core* core); // 0x33 0b00110011
enum StatusCode emu_rr_A(struct Emu8051Core* core); // 0x03 0b00000011
enum StatusCode emu_rrc_A(struct Emu8051Core* core); // 0x13 0b00010011
enum StatusCode emu_swap_A(struct Emu8051Core* core); // 0xC4 0b11000100

// ========== 数据传送 ==========
enum StatusCode emu_mov_A_R0(struct Emu8051Core* core); // 0xE8 0b11101000
enum StatusCode emu_mov_A_R1(struct Emu8051Core* core); // 0xE9 0b11101001
enum StatusCode emu_mov_A_R2(struct Emu8051Core* core); // 0xEA 0b11101010
enum StatusCode emu_mov_A_R3(struct Emu8051Core* core); // 0xEB 0b11101011
enum StatusCode emu_mov_A_R4(struct Emu8051Core* core); // 0xEC 0b11101100
enum StatusCode emu_mov_A_R5(struct Emu8051Core* core); // 0xED 0b11101101
enum StatusCode emu_mov_A_R6(struct Emu8051Core* core); // 0xEE 0b11101110
enum StatusCode emu_mov_A_R7(struct Emu8051Core* core); // 0xEF 0b11101111
enum StatusCode emu_mov_A_Direct(struct Emu8051Core* core); // 0xE5 0b11100101
enum StatusCode emu_mov_A_atR0(struct Emu8051Core* core); // 0xE6 0b11100110
enum StatusCode emu_mov_A_atR1(struct Emu8051Core* core); // 0xE7 0b11100111
enum StatusCode emu_mov_A_iData(struct Emu8051Core* core); // 0x74 0b01110100

enum StatusCode emu_mov_R0_A(struct Emu8051Core* core); // 0xF8 0b11111000
enum StatusCode emu_mov_R1_A(struct Emu8051Core* core); // 0xF9 0b11111001
enum StatusCode emu_mov_R2_A(struct Emu8051Core* core); // 0xFA 0b11111010
enum StatusCode emu_mov_R3_A(struct Emu8051Core* core); // 0xFB 0b11111011
enum StatusCode emu_mov_R4_A(struct Emu8051Core* core); // 0xFC 0b11111100
enum StatusCode emu_mov_R5_A(struct Emu8051Core* core); // 0xFD 0b11111101
enum StatusCode emu_mov_R6_A(struct Emu8051Core* core); // 0xFE 0b11111110
enum StatusCode emu_mov_R7_A(struct Emu8051Core* core); // 0xFF 0b11111111

enum StatusCode emu_mov_R0_Direct(struct Emu8051Core* core); // 0xA8 0b10101000
enum StatusCode emu_mov_R1_Direct(struct Emu8051Core* core); // 0xA9 0b10101001
enum StatusCode emu_mov_R2_Direct(struct Emu8051Core* core); // 0xAA 0b10101010
enum StatusCode emu_mov_R3_Direct(struct Emu8051Core* core); // 0xAB 0b10101011
enum StatusCode emu_mov_R4_Direct(struct Emu8051Core* core); // 0xAC 0b10101100
enum StatusCode emu_mov_R5_Direct(struct Emu8051Core* core); // 0xAD 0b10101101
enum StatusCode emu_mov_R6_Direct(struct Emu8051Core* core); // 0xAE 0b10101110
enum StatusCode emu_mov_R7_Direct(struct Emu8051Core* core); // 0xAF 0b10101111

enum StatusCode emu_mov_R0_iData(struct Emu8051Core* core); // 0x78 0b01111000
enum StatusCode emu_mov_R1_iData(struct Emu8051Core* core); // 0x79 0b01111001
enum StatusCode emu_mov_R2_iData(struct Emu8051Core* core); // 0x7A 0b01111010
enum StatusCode emu_mov_R3_iData(struct Emu8051Core* core); // 0x7B 0b01111011
enum StatusCode emu_mov_R4_iData(struct Emu8051Core* core); // 0x7C 0b01111100
enum StatusCode emu_mov_R5_iData(struct Emu8051Core* core); // 0x7D 0b01111101
enum StatusCode emu_mov_R6_iData(struct Emu8051Core* core); // 0x7E 0b01111110
enum StatusCode emu_mov_R7_iData(struct Emu8051Core* core); // 0x7F 0b01111111

enum StatusCode emu_mov_Direct_A(struct Emu8051Core* core); // 0xF5 0b11110101
enum StatusCode emu_mov_Direct_R0(struct Emu8051Core* core); // 0x88 0b10001000
enum StatusCode emu_mov_Direct_R1(struct Emu8051Core* core); // 0x89 0b10001001
enum StatusCode emu_mov_Direct_R2(struct Emu8051Core* core); // 0x8A 0b10001010
enum StatusCode emu_mov_Direct_R3(struct Emu8051Core* core); // 0x8B 0b10001011
enum StatusCode emu_mov_Direct_R4(struct Emu8051Core* core); // 0x8C 0b10001100
enum StatusCode emu_mov_Direct_R5(struct Emu8051Core* core); // 0x8D 0b10001101
enum StatusCode emu_mov_Direct_R6(struct Emu8051Core* core); // 0x8E 0b10001110
enum StatusCode emu_mov_Direct_R7(struct Emu8051Core* core); // 0x8F 0b10001111
enum StatusCode emu_mov_Direct_Direct(struct Emu8051Core* core); // 0x85 0b10000101
enum StatusCode emu_mov_Direct_atR0(struct Emu8051Core* core); // 0x86 0b10000110
enum StatusCode emu_mov_Direct_atR1(struct Emu8051Core* core); // 0x87 0b10000111
enum StatusCode emu_mov_Direct_iData(struct Emu8051Core* core); // 0x75 0b01110101

enum StatusCode emu_mov_atR0_A(struct Emu8051Core* core); // 0xF6 0b11110110
enum StatusCode emu_mov_atR1_A(struct Emu8051Core* core); // 0xF7 0b11110111
enum StatusCode emu_mov_atR0_Direct(struct Emu8051Core* core); // 0xA6 0b10100110
enum StatusCode emu_mov_atR1_Direct(struct Emu8051Core* core); // 0xA7 0b10100111
enum StatusCode emu_mov_atR0_iData(struct Emu8051Core* core); // 0x76 0b01110110
enum StatusCode emu_mov_atR1_iData(struct Emu8051Core* core); // 0x77 0b01110111

enum StatusCode emu_mov_DPTR_iData16(struct Emu8051Core* core); // 0x90 0b10010000
enum StatusCode emu_movc_A_atA_DPTR(struct Emu8051Core* core); // 0x93 0b10010011
enum StatusCode emu_movc_A_atA_PC(struct Emu8051Core* core); // 0x83 0b10000011

enum StatusCode emu_movx_A_atR0(struct Emu8051Core* core); // 0xE2 0b11100010
enum StatusCode emu_movx_A_atR1(struct Emu8051Core* core); // 0xE3 0b11100011
enum StatusCode emu_movx_A_atDPTR(struct Emu8051Core* core); // 0xE0 0b11100000
enum StatusCode emu_movx_atR0_A(struct Emu8051Core* core); // 0xF2 0b11110010
enum StatusCode emu_movx_atR1_A(struct Emu8051Core* core); // 0xF3 0b11110011
enum StatusCode emu_movx_atDPTR_A(struct Emu8051Core* core); // 0xF0 0b11110000

enum StatusCode emu_push_Direct(struct Emu8051Core* core); // 0xC0 0b11000000
enum StatusCode emu_pop_Direct(struct Emu8051Core* core); // 0xD0 0b11010000

enum StatusCode emu_xch_A_R0(struct Emu8051Core* core); // 0xC8 0b11001000
enum StatusCode emu_xch_A_R1(struct Emu8051Core* core); // 0xC9 0b11001001
enum StatusCode emu_xch_A_R2(struct Emu8051Core* core); // 0xCA 0b11001010
enum StatusCode emu_xch_A_R3(struct Emu8051Core* core); // 0xCB 0b11001011
enum StatusCode emu_xch_A_R4(struct Emu8051Core* core); // 0xCC 0b11001100
enum StatusCode emu_xch_A_R5(struct Emu8051Core* core); // 0xCD 0b11001101
enum StatusCode emu_xch_A_R6(struct Emu8051Core* core); // 0xCE 0b11001110
enum StatusCode emu_xch_A_R7(struct Emu8051Core* core); // 0xCF 0b11001111
enum StatusCode emu_xch_A_Direct(struct Emu8051Core* core); // 0xC5 0b11000101
enum StatusCode emu_xch_A_atR0(struct Emu8051Core* core); // 0xC6 0b11000110
enum StatusCode emu_xch_A_atR1(struct Emu8051Core* core); // 0xC7 0b11000111
enum StatusCode emu_xchd_A_atR0(struct Emu8051Core* core); // 0xD6 0b11010110
enum StatusCode emu_xchd_A_atR1(struct Emu8051Core* core); // 0xD7 0b11010111

// ========== 位操作 ==========
enum StatusCode emu_clr_C(struct Emu8051Core* core); // 0xC3 0b11000011
enum StatusCode emu_clr_Bit(struct Emu8051Core* core); // 0xC2 0b11000010
enum StatusCode emu_cpl_C(struct Emu8051Core* core); // 0xB3 0b10110011
enum StatusCode emu_cpl_Bit(struct Emu8051Core* core); // 0xB2 0b10110010
enum StatusCode emu_setb_C(struct Emu8051Core* core); // 0xD3 0b11010011
enum StatusCode emu_setb_Bit(struct Emu8051Core* core); // 0xD2 0b11010010
enum StatusCode emu_anl_C_Bit(struct Emu8051Core* core); // 0x82 0b10000010
enum StatusCode emu_anl_C_notBit(struct Emu8051Core* core); // 0xB0 0b10110000
enum StatusCode emu_orl_C_Bit(struct Emu8051Core* core); // 0x72 0b01110010
enum StatusCode emu_orl_C_notBit(struct Emu8051Core* core); // 0xA0 0b10100000
enum StatusCode emu_mov_C_Bit(struct Emu8051Core* core); // 0xA2 0b10100010
enum StatusCode emu_mov_Bit_C(struct Emu8051Core* core); // 0x92 0b10010010
enum StatusCode emu_jc_rel(struct Emu8051Core* core); // 0x40 0b01000000
enum StatusCode emu_jnc_rel(struct Emu8051Core* core); // 0x50 0b01010000
enum StatusCode emu_jb_Bit_rel(struct Emu8051Core* core); // 0x20 0b00100000
enum StatusCode emu_jnb_Bit_rel(struct Emu8051Core* core); // 0x30 0b00110000
enum StatusCode emu_jbc_Bit_rel(struct Emu8051Core* core); // 0x10 0b00010000

// ========== 控制转移 ==========
enum StatusCode emu_acall_addr(struct Emu8051Core* core); // 0x11 0b00010001
enum StatusCode emu_lcall_addr(struct Emu8051Core* core); // 0x12 0b00010010
enum StatusCode emu_ret(struct Emu8051Core* core); // 0x22 0b00100010
enum StatusCode emu_reti(struct Emu8051Core* core); // 0x32 0b00110010
enum StatusCode emu_ajmp_addr(struct Emu8051Core* core); // 0x01 0b00000001
enum StatusCode emu_ljmp_addr(struct Emu8051Core* core); // 0x02 0b00000010
enum StatusCode emu_sjmp_rel(struct Emu8051Core* core); // 0x80 0b10000000
enum StatusCode emu_jmp_atA_DPTR(struct Emu8051Core* core); // 0x73 0b01110011
enum StatusCode emu_jz_rel(struct Emu8051Core* core); // 0x60 0b01100000
enum StatusCode emu_jnz_rel(struct Emu8051Core* core); // 0x70 0b01110000

enum StatusCode emu_cjne_A_Direct_rel(struct Emu8051Core* core); // 0xB5 0b10110101
enum StatusCode emu_cjne_A_iData_rel(struct Emu8051Core* core); // 0xB4 0b10110100

enum StatusCode emu_cjne_R0_iData_rel(struct Emu8051Core* core); // 0xB8 0b10111000
enum StatusCode emu_cjne_R1_iData_rel(struct Emu8051Core* core); // 0xB9 0b10111001
enum StatusCode emu_cjne_R2_iData_rel(struct Emu8051Core* core); // 0xBA 0b10111010
enum StatusCode emu_cjne_R3_iData_rel(struct Emu8051Core* core); // 0xBB 0b10111011
enum StatusCode emu_cjne_R4_iData_rel(struct Emu8051Core* core); // 0xBC 0b10111100
enum StatusCode emu_cjne_R5_iData_rel(struct Emu8051Core* core); // 0xBD 0b10111101
enum StatusCode emu_cjne_R6_iData_rel(struct Emu8051Core* core); // 0xBE 0b10111110
enum StatusCode emu_cjne_R7_iData_rel(struct Emu8051Core* core); // 0xBF 0b10111111

enum StatusCode emu_cjne_atR0_iData_rel(struct Emu8051Core* core); // 0xB6 0b10110110
enum StatusCode emu_cjne_atR1_iData_rel(struct Emu8051Core* core); // 0xB7 0b10110111

enum StatusCode emu_djnz_R0_rel(struct Emu8051Core* core); // 0xD8 0b11011000
enum StatusCode emu_djnz_R1_rel(struct Emu8051Core* core); // 0xD9 0b11011001
enum StatusCode emu_djnz_R2_rel(struct Emu8051Core* core); // 0xDA 0b11011010
enum StatusCode emu_djnz_R3_rel(struct Emu8051Core* core); // 0xDB 0b11011011
enum StatusCode emu_djnz_R4_rel(struct Emu8051Core* core); // 0xDC 0b11011100
enum StatusCode emu_djnz_R5_rel(struct Emu8051Core* core); // 0xDD 0b11011101
enum StatusCode emu_djnz_R6_rel(struct Emu8051Core* core); // 0xDE 0b11011110
enum StatusCode emu_djnz_R7_rel(struct Emu8051Core* core); // 0xDF 0b11011111
enum StatusCode emu_djnz_Direct_rel(struct Emu8051Core* core); // 0xD5 0b11010101

// ========== 空操作 ==========
enum StatusCode emu_nop(struct Emu8051Core* core); // 0x00 0b00000000


#endif
