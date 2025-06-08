// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_INSTRUCTION_H_
#define LYNX_INSTRUCTION_H_

#include "common.h"

namespace lynx {

enum Opcode : uint16_t {
  LOP_NOP,
  LOP_CONST,
  LOP_ADD,
  LOP_SUB,
  LOP_MUL,
  LOP_DIV,
};

struct alignas(8) Instruction {
  Opcode op;
  uint16_t a, b, c;
};

} // namespace lynx

#endif
