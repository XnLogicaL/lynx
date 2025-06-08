// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEAP_BUFFER_H_
#define LYNX_HEAP_BUFFER_H_

#include "conf.h"
#include <cstddef>

namespace lynx {

template <typename T> struct HeapBuffer {
  T *data = NULL;
  size_t size = 0;

  HeapBuffer(const size_t size);
  ~HeapBuffer();

  LYNX_COPY(HeapBuffer);
  LYNX_MOVE(HeapBuffer);
};

} // namespace lynx

#endif
