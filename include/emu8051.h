#ifndef JIDAO_EMU8051_H_
#define JIDAO_EMU8051_H_

#include <stddef.h>
#include <stdint.h>


typedef char Byte;

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


struct Emu8051Core* emu_init(const Byte* rom, size_t length, size_t extern_ram);
void emu_destroy(struct Emu8051Core* core);

enum StatusCode emu_tick(struct Emu8051Core* core);

Byte emu_read_byte(const struct Emu8051Core* core, size_t index);
Byte emu_read_register_byte(const struct Emu8051Core* core, size_t index);
Byte emu_set_byte(struct Emu8051Core* core, size_t index, Byte value);
Byte emu_set_register_byte(struct Emu8051Core* core, size_t index, Byte value);

const char* emu_get_error(const struct Emu8051Core* core);


#endif
