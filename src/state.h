// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_STATE_H_
#define LYNX_STATE_H_

#include "conf.h"
#include "header.h"
#include "heap_buffer.h"
#include "instruction.h"

namespace lynx {

struct State {
  const Header H;

  const Instruction *pc;

  Value *top;

  HeapBuffer<Value> regs;
  HeapBuffer<Value> stk;

  LYNX_NO_COPY(State);
  LYNX_NO_MOVE(State);
};

} // namespace lynx

#endif
