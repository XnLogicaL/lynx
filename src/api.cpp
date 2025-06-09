// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "api.h"

#include <cstdint>
#include <utility>

#include "conf.h"
#include "value.h"

namespace lynx {

void set_register(State* L, uint16_t reg, Value&& val) {
  L->regs.data[reg] = std::move(val);
}

Value* get_register(State* L, uint16_t reg) {
  return &L->regs.data[reg];
}

}  // namespace lynx
