// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_VALUE_H_
#define LYNX_VALUE_H_

#include "conf.h"

namespace lynx {

enum ValueKind {
  LVK_NIL,
  LVK_INT,
  LVK_FLOAT,
  LVK_BOOLEAN,
  LVK_STRING,
  LVK_ARRAY,
  LVK_DICT,
  LVK_OBJECT,
  LVK_TUPLE,
};

struct Value {
  lynx::ValueKind kind;
  union {
    int i;
    float f;
    bool b;
  } u;

  Value();
  explicit Value(int i);
  explicit Value(float f);
  explicit Value(bool b);

  ~Value();

  LYNX_NO_COPY(Value);
  LYNX_MOVE(Value);
};

}  // namespace lynx

#endif
