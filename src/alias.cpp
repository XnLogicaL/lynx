// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "alias.h"

#include <cstdint>
#include <utility>

#include "api.h"
#include "conf.h"

LYNX_API void lynx_setregister(lynx_State* L, uint16_t reg, lynx_Value val) {
  lynx::set_register(L, reg, std::move(val));
}

LYNX_API lynx_Value* lynx_getregister(lynx_State* L, uint16_t reg) {
  return lynx::get_register(L, reg);
}
