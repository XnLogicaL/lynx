// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_ALIAS_H_
#define LYNX_ALIAS_H_

#include <cstdint>

#include "conf.h"
#include "state.h"
#include "value.h"

using lynx_State = lynx::State;
using lynx_Value = lynx::Value;

LYNX_API void lynx_setregister(lynx_State* L, uint16_t reg, lynx_Value val);
LYNX_API lynx_Value* lynx_getregister(lynx_State* L, uint16_t reg);

#endif
