#ifndef JIDAO_EMU8051_H_
#define JIDAO_EMU8051_H_

#include <stddef.h>


typedef char Byte;
typedef int Bool;

struct Emu8051Core
{
    Byte ram[256];
    Byte register_ram[128];
    Byte* extern_ram;
    Byte* rom;

    size_t pc;
    size_t tick_remain;
    char* error_msg;
};

enum StatusCode
{
    emu_ok, emu_fault
};


enum Emu8051Register
{
    // 标准 8051 SFR
    P0     = 0x80,  // Port 0
    SP     = 0x81,  // Stack Pointer
    DPL    = 0x82,  // Data Pointer Low
    DPH    = 0x83,  // Data Pointer High
    PCON   = 0x87,  // Power Control
    TCON   = 0x88,  // Timer Control
    TMOD   = 0x89,  // Timer Mode
    TL0    = 0x8A,  // Timer 0 Low
    TL1    = 0x8B,  // Timer 1 Low
    TH0    = 0x8C,  // Timer 0 High
    TH1    = 0x8D,  // Timer 1 High

    P1     = 0x90,  // Port 1
    SCON   = 0x98,  // Serial Control
    SBUF   = 0x99,  // Serial Buffer

    P2     = 0xA0,  // Port 2
    IE     = 0xA8,  // Interrupt Enable

    P3     = 0xB0,  // Port 3
    IP     = 0xB8,  // Interrupt Priority

    // 8052 / 常见衍生型号：定时器 2
    T2CON  = 0xC8,  // Timer 2 Control
    T2MOD  = 0xC9,  // Timer 2 Mode，部分派生型号有
    RCAP2L = 0xCA,  // Timer 2 Reload/Capture Low
    RCAP2H = 0xCB,  // Timer 2 Reload/Capture High
    TL2    = 0xCC,  // Timer 2 Low
    TH2    = 0xCD,  // Timer 2 High

    PSW    = 0xD0,  // Program Status Word
    ACC    = 0xE0,  // Accumulator
    B      = 0xF0   // B Register
};
enum Emu8051BitRegister
{
    // T2CON 位
    CP_RL2 = 0xC8,
    C_T2   = 0xC9,
    TR2    = 0xCA,
    EXEN2  = 0xCB,
    TCLK   = 0xCC,
    RCLK   = 0xCD,
    EXF2   = 0xCE,
    TF2    = 0xCF,

    // IE 中的 Timer2 中断使能
    ET2    = 0xAD,  // IE.5

    // IP 中的 Timer2 中断优先级
    PT2    = 0xBD   // IP.5
};


struct Emu8051Core* emu_init(const Byte* rom, size_t length, size_t extern_ram);
void emu_destroy(struct Emu8051Core* core);

enum StatusCode emu_tick(struct Emu8051Core* core);

Byte emu_read_byte(const struct Emu8051Core* core, size_t index);
Byte emu_read_register_byte(const struct Emu8051Core* core, size_t index);
Bool emu_read_bit_register_byte(const struct Emu8051Core* core, size_t index);

Byte emu_set_byte(struct Emu8051Core* core, size_t index, Byte value);
Byte emu_set_register_byte(struct Emu8051Core* core, size_t index, Byte value);
Bool emu_set_bit_register_byte(struct Emu8051Core* core, size_t index, Byte value);

const char* emu_get_error(const struct Emu8051Core* core);


#endif
