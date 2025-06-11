// This file is a part of the lynx project (https://github.com/XnLogicaL/lynx)
// Licensed under GNU GPLv3.0 Copyright (C) 2025 XnLogicaL

#include "header.h"

#include <bit>
#include <cstdint>
#include <cstring>
#include <utility>

#include "heap_buffer.h"
#include "instruction.h"
#include "value.h"

using namespace lynx;

static void write8(FileBuf* B, uint8_t data) {
  *B->cursor = data;
  ++B->cursor;
}

static void write16(FileBuf* B, uint16_t data) {
  std::memcpy(B->cursor, &data, 2);
  B->cursor += 2;
}

static void write32(FileBuf* B, uint32_t data) {
  std::memcpy(B->cursor, &data, 4);
  B->cursor += 4;
}

static void write64(FileBuf* B, uint64_t data) {
  std::memcpy(B->cursor, &data, 8);
  B->cursor += 8;
}

static void writevalue(FileBuf* B, const Value& val) {
  write8(B, val.kind);

  switch (val.kind) {
    case LVK_BOOLEAN:
      write8(B, val.u.b);
      break;
    case LVK_INT:
      write32(B, val.u.i);
      break;
    case LVK_FLOAT: {
      uint32_t data = std::bit_cast<uint32_t>(val.u.f);
      write32(B, data);
    } break;
    default:
      break;
  }
}

static uint8_t read8(const FileBuf* B) {
  uint8_t data = *B->cursor;
  ++B->cursor;
  return data;
}

static uint16_t read16(const FileBuf* B) {
  uint16_t data;
  std::memcpy(&data, B->cursor, 2);
  B->cursor += 2;
  return data;
}

static uint32_t read32(const FileBuf* B) {
  uint32_t data;
  std::memcpy(&data, B->cursor, 4);
  B->cursor += 4;
  return data;
}

static uint64_t read64(const FileBuf* B) {
  uint64_t data;
  std::memcpy(&data, B->cursor, 8);
  B->cursor += 8;
  return data;
}

static Value readvalue(const FileBuf* B) {
  uint8_t kind = read8(B);

  switch (kind) {
    case LVK_NIL:
      return Value();
    case LVK_INT: {
      uint32_t data = read32(B);
      int val = static_cast<int>(data);
      return Value(val);
    }
    case LVK_FLOAT: {
      uint32_t data = read32(B);
      float val = std::bit_cast<float>(data);
      return Value(val);
    }
    case LVK_BOOLEAN: {
      uint8_t data = read8(B);
      bool val = static_cast<bool>(data);
      return Value(val);
    }
    default:
      break;
  }

  return Value();
}

Header::Header(Header&& other)
    : magic(other.magic),
      flags(other.flags),
      consts(std::move(other.consts)),
      bytecode(std::move(other.bytecode)) {
}

const Header& Header::operator=(Header&& other) {
  if (this != &other) {
    magic = other.magic;
    flags = other.flags;
    consts = std::move(other.consts);
    bytecode = std::move(other.bytecode);
  }

  return *this;
}

size_t lynx::header_size(const Header& H) {
  return sizeof(H.magic) + sizeof(H.flags) + H.consts.size + H.bytecode.size;
}

FileBuf lynx::header_encode(const Header& H) {
  FileBuf buf(header_size(H));

  write32(&buf, H.magic);
  write64(&buf, H.flags);
  write32(&buf, H.consts.size);

  Value* lastk = H.consts.data + H.consts.size;
  for (const Value* val = H.consts.data; val < lastk; ++val) {
    writevalue(&buf, *val);
  }

  write32(&buf, H.bytecode.size);

  Instruction* lastinsn = H.bytecode.data + H.bytecode.size;
  for (const Instruction* insn = H.bytecode.data; insn < lastinsn; ++insn) {
    uint64_t data = std::bit_cast<uint64_t>(*insn);
    write64(&buf, data);
  }

  return buf;
}

Header lynx::header_decode(const FileBuf& buf) {
  buf.cursor = buf.data;  // reset cursor to ensure no funny shit happens

  Header H;

  H.magic = read32(&buf);
  H.flags = read64(&buf);

  uint32_t kcount = read32(&buf);
  H.consts = HeapBuffer<Value>(kcount);

  for (size_t i = 0; i < kcount; i++) {
    *H.consts.cursor = readvalue(&buf);
    ++H.consts.cursor;
  }

  uint32_t icount = read32(&buf);
  H.bytecode = HeapBuffer<Instruction>(icount);

  for (size_t i = 0; i < icount; i++) {
    uint64_t data = read64(&buf);
    *H.bytecode.cursor = std::bit_cast<Instruction>(data);
    ++H.bytecode.cursor;
  }

  return H;
}
