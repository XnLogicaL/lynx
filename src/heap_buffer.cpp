// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "heap_buffer.h"

#include <cstddef>
#include <cstring>

using namespace lynx;

template <typename T>
HeapBuffer<T>::HeapBuffer(const size_t size)
    : data(new T[size]), cursor(data), size(size) {}

template <typename T>
HeapBuffer<T>::~HeapBuffer<T>() {
  delete[] data;
}

template <typename T>
HeapBuffer<T>::HeapBuffer(const HeapBuffer<T> &other)
    : data(new T[other.size]), cursor(data), size(other.size) {
  std::memcpy(data, other.data, size);
}

template <typename T>
HeapBuffer<T>::HeapBuffer(HeapBuffer<T> &&other)
    : data(other.data), cursor(data), size(other.size) {
  other.data = NULL;
  other.cursor = NULL;
  other.size = 0;
}

template <typename T>
const HeapBuffer<T> &HeapBuffer<T>::operator=(const HeapBuffer<T> &other) {
  if (this != &other) {
    delete[] data;
    data = new T[other.size];
    cursor = data;
    size = other.size;
    std::memcpy(data, other.data, size);
  }

  return *this;
}

template <typename T>
const HeapBuffer<T> &HeapBuffer<T>::operator=(HeapBuffer<T> &&other) {
  if (this != &other) {
    delete[] data;
    data = new T[other.size];
    cursor = data;
    size = other.size;
    std::memcpy(data, other.data, size);
    other.data = NULL;
    other.cursor = NULL;
    other.size = 0;
  }

  return *this;
}