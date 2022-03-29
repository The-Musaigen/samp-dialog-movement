#ifndef MAIN_H_
#define MAIN_H_

// winsdk
#include <process.h>

// memwrapper
#include "memwrapper/memwrapper.h"

namespace {
constexpr std::string_view kModule = "samp.dll";
constexpr std::string_view kPattern =
    "\x6A\x02\xE8\x00\x00\x00\x00\x8B\x4F\x1C\x85\xC9\x0F\x84\x00\x00\x00"
    "\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8D\x54\x24\x14\x52\x8B"
    "\xCF\xE8\x00\x00\x00\x00\x8B\x57\x34\x85\xD2\x74\x63\x8B\x47\x2C\x83"
    "\xF8\x01\x74\x09\x85\xC0\x74\x05\x83\xF8\x03\x75\x52";   // big boy
constexpr std::string_view kMask =
    "xxx????xxxxxxx????x????x????xxxxxxxx????xxxxxxxxxxxxxxxxxxxxxxxx";

constexpr uint8_t CURSOR_LOCKCAMANDCONTROL = 0x02;
constexpr uint8_t CURSOR_LOCKCAM           = 0x03;

constexpr auto kShiftToOperand = 1u;

// non-const
memwrapper::scoped_patch patch_set_cursor_mode;
}   // namespace

#endif   // !MAIN_H_
