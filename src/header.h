// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEADER_H_
#define LYNX_HEADER_H_

#include "conf.h"
#include "heap_buffer.h"
#include <cstdint>

struct lynx_Value;
struct lynx_Proto;

struct lynx_Header {
  const uint32_t magic = LYNX_MAGIC_VALUE;

  lynx_HeapBuffer<lynx_Value> consts;
  lynx_HeapBuffer<lynx_Proto> protos;

  LYNX_NO_COPY(lynx_Header);
  LYNX_NO_MOVE(lynx_Header);
};

#endif
