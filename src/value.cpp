// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "value.h"

lynx_Value::lynx_Value() : kind(LVK_NIL) {}

lynx_Value::lynx_Value(lynx_Integer i) : kind(LVK_INT), u({.i = i}) {}

lynx_Value::lynx_Value(lynx_Float f) : kind(LVK_FLOAT), u({.f = f}) {}

lynx_Value::lynx_Value(lynx_Boolean b) : kind(LVK_BOOLEAN), u({.b = b}) {}

lynx_Value::~lynx_Value() {}
