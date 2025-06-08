// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_HEAP_BUFFER_H_
#define LYNX_HEAP_BUFFER_H_

#include <cstddef>
#include <type_traits>

namespace lynx {

template <typename T> struct HeapBuffer {
  static_assert(std::is_default_constructible_v<T>, "");

  T *data = NULL;
  size_t size = 0;

  HeapBuffer(const size_t size);
  HeapBuffer(const HeapBuffer &other);
  HeapBuffer(HeapBuffer &&other);

  const HeapBuffer &operator=(const HeapBuffer &other);
  const HeapBuffer &operator=(HeapBuffer &&other);
};

} // namespace lynx

#endif
