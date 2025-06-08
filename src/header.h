// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEADER_H_
#define LYNX_HEADER_H_

#include "conf.h"
#include <cstdint>

struct lynx_Value;
struct lynx_Proto;

struct lynx_Header {
  const uint32_t magic = LYNX_MAGIC_VALUE;

  uint32_t const_count;
  uint32_t proto_count;

  lynx_Value *consts;
  lynx_Proto *protos;

  lynx_Header() = default;

  LYNX_NO_COPY(lynx_Header);
  LYNX_NO_MOVE(lynx_Header);
};

#endif
