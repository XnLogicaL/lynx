// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEADER_H_
#define LYNX_HEADER_H_

#include <cstdint>

#include "conf.h"
#include "heap_buffer.h"
#include "instruction.h"
#include "value.h"

namespace lynx {

struct Header {
  uint32_t magic = LYNX_MAGIC_VALUE;
  uint64_t flags;

  HeapBuffer<Value> consts;
  HeapBuffer<Instruction> bytecode;

  Header() = default;

  LYNX_NO_COPY(Header);
  LYNX_MOVE(Header);
};

using FileBuf = HeapBuffer<uint8_t>;

size_t header_size(const Header& H);
FileBuf header_encode(const Header& H);
Header header_decode(const FileBuf& buf);

}  // namespace lynx

#endif
