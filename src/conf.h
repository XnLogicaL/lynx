// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#ifndef LYNX_CONF_H_
#define LYNX_CONF_H_

// lynx in hex
#define LYNX_MAGIC_VALUE 0x6c796e78

#ifdef LYNX_BUILD_DLL

#else
#define LYNX_API extern "C"
#endif

#define LYNX_NO_COPY(target)                                                   \
  target(const target &) = delete;                                             \
  const target &operator=(const target &) = delete;

#define LYNX_NO_MOVE(target)                                                   \
  target(target &&) = delete;                                                  \
  const target &operator=(target &&) = delete;

#define LYNX_COPY(target)                                                      \
  target(const target &);                                                      \
  const target &operator=(const target &);

#define LYNX_MOVE(target)                                                      \
  target(target &&);                                                           \
  const target &operator=(target &&);

#endif
