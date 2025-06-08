// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEADER_H_
#define LYNX_HEADER_H_

#include <cstdint>

// lynx in hex
#define LYNX_MAGIC_VALUE 0x6c796e78

namespace lynx {

struct Value;
struct Proto;

struct Header {
  const uint32_t magic = LYNX_MAGIC_VALUE;

  uint32_t const_count;
  uint32_t proto_count;

  Value *consts;
  Proto *protos;

  Header() = default;

  Header(const Header &) = delete;
  Header(Header &&) = delete;

  const Header &operator=(const Header &) = delete;
  const Header &operator=(Header &&) = delete;
};

} // namespace lynx

#endif
