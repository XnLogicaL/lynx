// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_STATE_H_
#define LYNX_STATE_H_

#include "conf.h"
#include "header.h"
#include "heap_buffer.h"
#include "instruction.h"

struct lynx_State {
  const lynx_Header H;

  const lynx_Instruction *pc;

  lynx_Value *top;

  lynx_HeapBuffer<lynx_Value> regs;
  lynx_HeapBuffer<lynx_Value> stk;

  LYNX_NO_COPY(lynx_State);
  LYNX_NO_MOVE(lynx_State);
};

#endif
