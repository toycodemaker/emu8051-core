#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emu8051.h"
#include "emu_assert.h"


typedef enum StatusCode (*EmuCallback)(struct Emu8051Core*);

static EmuCallback callback[255];


struct Emu8051Core* emu_init(const Byte* rom, size_t length, size_t extern_ram)
{
    EMU_ASSERT(rom);
    EMU_ASSERT(length < 64*1024);
    EMU_ASSERT(extern_ram < 64*1024);

    struct Emu8051Core* new_core = malloc(sizeof(struct Emu8051Core));
    memset(new_core, 0, sizeof(struct Emu8051Core));

    // 设置动态资源
    new_core->extern_ram = malloc(extern_ram);
    memset(new_core->extern_ram, 0, extern_ram);
    new_core->rom = malloc(length);
    memcpy(new_core->rom, rom, length);

    return new_core;
}


void emu_destroy(struct Emu8051Core *core)
{
    free(core->extern_ram);
    free(core->rom);
    free(core);
}


enum StatusCode emu_tick(struct Emu8051Core *core)
{
    if (core->tick_remain != 0) 
        return emu_ok;
    
    return callback[core->rom[core->pc]](core);
}


Byte emu_read_byte(const struct Emu8051Core* core, size_t index)
{
    return core->ram[index];
}


Byte emu_read_register_byte(const struct Emu8051Core* core, size_t index)
{
    if (index >= 0x80) {
        return core->register_ram[index-0x80];
    } else {
        return core->ram[index];
    }
}


// TODO 审核这段代码
Bool emu_read_bit_register_byte(const struct Emu8051Core* core, size_t index)
{
    size_t byte_addr;
    Byte bit_mask;

    if (index < 0x80) {
        // 内部 RAM 位寻址区：0x20 ~ 0x2F
        byte_addr = 0x20 + (index / 8);
        bit_mask = 1 << (index % 8);
    } else {
        // SFR 位寻址区：字节地址 = index & 0xF8，位偏移 = index & 0x07
        byte_addr = index & 0xF8;
        bit_mask = 1 << (index & 0x07);
    }

    Byte byte_val = emu_read_register_byte(core, byte_addr);
    return (byte_val & bit_mask) ? 1 : 0;
}


Byte emu_set_byte(struct Emu8051Core* core, size_t index, Byte value)
{
    return core->ram[index] = value;
}


Byte emu_set_register_byte(struct Emu8051Core* core, size_t index, Byte value)
{
    if (index >= 0x80) {
        return core->register_ram[index-0x80] = value;
    } else {
        return core->ram[index] = value;
    }
}


const char* emu_get_error(const struct Emu8051Core* core)
{
    return core->error_msg;
}


// TODO 审核这段代码
Bool emu_set_bit_register_byte(struct Emu8051Core* core, size_t index, Byte value)
{
    size_t byte_addr;
    Byte bit_mask;

    if (index < 0x80) {
        // 内部 RAM 位寻址区
        byte_addr = 0x20 + (index / 8);
        bit_mask = 1 << (index % 8);
    } else {
        // SFR 位寻址区
        byte_addr = index & 0xF8;
        bit_mask = 1 << (index & 0x07);
    }

    Byte byte_val = emu_read_register_byte(core, byte_addr);
    if (value) {
        byte_val |= bit_mask;
    } else {
        byte_val &= ~bit_mask;
    }
    emu_set_register_byte(core, byte_addr, byte_val);

    return (byte_val & bit_mask) ? 1 : 0;
}
