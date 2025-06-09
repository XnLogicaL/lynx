// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_API_H_
#define LYNX_API_H_

#include "conf.h"
#include "state.h"
#include "value.h"

namespace lynx {

LYNX_API void set_register(State *L, uint16_t reg, Value &&val);
LYNX_API Value *get_register(State *L, uint16_t reg);

LYNX_API void push(State *L, Value &&val);
LYNX_API void drop(State *L);
LYNX_API Value *pop(State *L);

LYNX_API void exec(State *L);
LYNX_API void exec_step(State *L);

}  // namespace lynx

#endif
