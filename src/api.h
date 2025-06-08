// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_API_H_
#define LYNX_API_H_

#include "conf.h"
#include "header.h"
#include "state.h"

LYNX_API void lynx_setregister(lynx_State *L, uint16_t reg, lynx_Value &&val);
LYNX_API lynx_Value *lynx_getregister(lynx_State *L, uint16_t reg);

LYNX_API void lynx_push(lynx_State *L, lynx_Value &&val);
LYNX_API lynx_Value *lynx_pop(lynx_State *L);

#endif
