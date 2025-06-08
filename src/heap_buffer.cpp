// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "heap_buffer.h"
#include <cstring>

template <typename T>
lynx_HeapBuffer<T>::lynx_HeapBuffer(const size_t size)
    : data(new T[size]), size(size) {}

template <typename T>
lynx_HeapBuffer<T>::lynx_HeapBuffer(const lynx_HeapBuffer<T> &other)
    : data(new T[other.size]), size(other.size) {
  std::memcpy(data, other.data, size);
}

template <typename T>
lynx_HeapBuffer<T>::lynx_HeapBuffer(lynx_HeapBuffer<T> &&other)
    : data(other.data), size(other.size) {
  other.data = NULL;
  other.size = 0;
}

template <typename T>
const lynx_HeapBuffer<T> &
lynx_HeapBuffer<T>::operator=(const lynx_HeapBuffer<T> &other) {
  data = new T[other.size];
  size = other.size;
  std::memcpy(data, other.data, size);
}

template <typename T>
const lynx_HeapBuffer<T> &
lynx_HeapBuffer<T>::operator=(lynx_HeapBuffer<T> &&other) {
  data = new T[other.size];
  size = other.size;
  std::memcpy(data, other.data, size);
  other.data = NULL;
  other.size = 0;
}
