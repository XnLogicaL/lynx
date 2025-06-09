// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "value.h"

using namespace lynx;

Value::Value() : kind(LVK_NIL) {}

Value::Value(int i) : kind(LVK_INT), u({.i = i}) {}

Value::Value(float f) : kind(LVK_FLOAT), u({.f = f}) {}

Value::Value(bool b) : kind(LVK_BOOLEAN), u({.b = b}) {}

Value::~Value() {}
