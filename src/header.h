// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEADER_H_
#define LYNX_HEADER_H_

#include "conf.h"
#include "heap_buffer.h"
#include <cstdint>

namespace lynx {

struct Value;
struct Proto;

struct Header {
  const uint32_t magic = LYNX_MAGIC_VALUE;

  HeapBuffer<Value> consts;
  HeapBuffer<Proto> protos;

  LYNX_NO_COPY(Header);
  LYNX_NO_MOVE(Header);
};

} // namespace lynx

#endif
