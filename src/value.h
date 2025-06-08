// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_VALUE_H_
#define LYNX_VALUE_H_

#include "conf.h"

enum lynx_ValueKind {
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

struct lynx_Value {
  lynx_ValueKind kind;
  union {
    lynx_Integer i;
    lynx_Float f;
    lynx_Boolean b;
  } u;

  lynx_Value();
  explicit lynx_Value(lynx_Integer i);
  explicit lynx_Value(lynx_Float f);
  explicit lynx_Value(lynx_Boolean b);

  ~lynx_Value();

  LYNX_NO_COPY(lynx_Value);
  LYNX_MOVE(lynx_Value);
};

#endif
