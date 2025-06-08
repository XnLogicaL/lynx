// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEAP_BUFFER_H_
#define LYNX_HEAP_BUFFER_H_

#include "conf.h"
#include <cstddef>

template <typename T> struct lynx_HeapBuffer {
  T *data = NULL;
  size_t size = 0;

  lynx_HeapBuffer(const size_t size);
  ~lynx_HeapBuffer();

  LYNX_COPY(lynx_HeapBuffer);
  LYNX_MOVE(lynx_HeapBuffer);
};

#endif
