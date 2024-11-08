/**
 * This file is part of the Titan Avionics Library
 * Copyright (c) 2024 UW SARP
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * @file include/tal/util/bit.h
 * @authors Aaron McBride
 * @brief Bit manipulation utilities.
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include "tal/util/attributes.h"

#if defined(__cplusplus)
  extern "C" {
#endif

  /**************************************************************************************************
   * @section Non-Standard Bit Manipulation Utilities
   **************************************************************************************************/

  /**
   * @brief Evaluates to the number of bits in @p 'type'.
   * @param type The type to get the bit size of.
   */
  #define tal_bit_size(type) (sizeof(type) * CHAR_BIT)

  /**
   * @brief Reverses the bits of an integer.
   * @param value (unsigned integer of any size) The value to modify.
   * @returns (unsigned integer with same size as 'value') The given value 
   *          with the order of it's bits reversed.
   */
  #define tal_rbit(value) \
    _Generic((value) \
      uint8_t: tal_rbit_u8, \
      uint16_t: tal_rbit_u16, \
      uint32_t: tal_rbit_u32, \
      uint64_t: tal_rbit_u64 \
    )(value)

  tal_fn_attr_inline inline uint8_t tal_rbit_u8(const uint8_t value);
  tal_fn_attr_inline inline uint16_t tal_rbit_u16(const uint16_t value);
  tal_fn_attr_inline inline uint32_t tal_rbit_u32(const uint32_t value);
  tal_fn_attr_inline inline uint64_t tal_rbit_u64(const uint64_t value);

  /**
   * @brief Reverses the bits of an integer.
   * @param value (unsigned integer with greater than 16 bits) The value to modify.
   * @returns (unsigned integer with same size as 'value') The given value 
   *          with the order of it's bytes reversed.
   */
  #define tal_rbyte(value) \
    _Generic((value) \
      uint16_t: tal_rbyte_u16, \
      uint32_t: tal_rbyte_u32, \
      uint64_t: tal_rbyte_u64 \
    )(value)

  tal_fn_attr_inline inline uint16_t tal_rbyte_u16(const uint16_t value);
  tal_fn_attr_inline inline uint32_t tal_rbyte_u32(const uint32_t value);
  tal_fn_attr_inline inline uint64_t tal_rbyte_u64(const uint64_t value);

  /**
   * @brief Determines if an integer is a power of two.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (bool) True if the given value is a power of two, or false otherwise.
   * @note - If an integer is a power of two, it has only one set bit.
   */
  #define tal_single_bit(value) \
    _Generic((value) \
      uint8_t: tal_single_bit_u8, \
      uint16_t: tal_single_bit_u16, \
      uint32_t: tal_single_bit_u32, \
      uint64_t: tal_single_bit_u64 \
    )(value)

  tal_fn_attr_inline inline bool tal_single_bit_u8(const uint8_t value);
  tal_fn_attr_inline inline bool tal_single_bit_u16(const uint16_t value);
  tal_fn_attr_inline inline bool tal_single_bit_u32(const uint32_t value);
  tal_fn_attr_inline inline bool tal_single_bit_u64(const uint64_t value);

  /**
   * @brief Rounds an integer up to the nearest power of two.
   * @param value (unsigned integer of any size) The value to modify.
   * @returns (unsigned integer with same size as 'value') The smallest power 
   *          of two which is greater than or equal to the given value.
   * @note - If an integer is power of two, it has only one set bit.
   */
  #define tal_bit_ceil(value) \
    _Generic((value), \
      uint8_t: tal_bit_ceil_u8, \
      uint16_t: tal_bit_ceil_u16, \
      uint32_t: tal_bit_ceil_u32, \
      uint64_t: tal_bit_ceil_u64 \
    )(value)

  tal_fn_attr_inline inline uint8_t tal_bit_ceil_u8(const uint8_t value);
  tal_fn_attr_inline inline uint16_t tal_bit_ceil_u16(const uint16_t value);
  tal_fn_attr_inline inline uint32_t tal_bit_ceil_u32(const uint32_t value);
  tal_fn_attr_inline inline uint64_t tal_bit_ceil_u64(const uint64_t value);

  /**
   * @brief Rounds an integer down to the nearest power of two.
   * @param value (unsigned integer of any size) The value to modify.
   * @returns (unsigned integer with same size as 'value') The greatest power 
   *          of two which is less than or equal to the given value.
   * @note - If an integer is power of two, it has only one set bit.
   */
  #define tal_bit_floor(value) \
    _Generic((value), \
      uint8_t: tal_bit_floor_u8, \
      uint16_t: tal_bit_floor_u16, \
      uint32_t: tal_bit_floor_u32, \
      uint64_t: tal_bit_floor_u64 \
    )(value)

  tal_fn_attr_inline inline uint8_t tal_bit_floor_u8(const uint8_t value);
  tal_fn_attr_inline inline uint16_t tal_bit_floor_u16(const uint16_t value);
  tal_fn_attr_inline inline uint32_t tal_bit_floor_u32(const uint32_t value);
  tal_fn_attr_inline inline uint64_t tal_bit_floor_u64(const uint64_t value);

  /**
   * @brief Determines the number of bits needed to represent a numeric value.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The minimum number of bits needed to represent the given
   *          value. That is, 1 + log2('value').
   * @note - If the given value is equal to 0, this function returns 0.
   */
  #define tal_bit_width(value) \
    _Generic((value), \
      uint8_t: tal_bit_width_u8, \
      uint16_t: tal_bit_width_u16, \
      uint32_t: tal_bit_width_u32, \
      uint64_t: tal_bit_width_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_bit_width_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_bit_width_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_bit_width_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_bit_width_u64(const uint64_t value);

  /**
   * @brief Performs a circular left shift on an integer value.
   * @param value (unsigned integer of any size) The value to rotate.
   * @param shift (int32_t) The number of bits to rotate by.
   * @returns (unsigned integer with same size as 'value') The result of 
   *          circularly rotating the given value to the left by 'shift' bits.
   * @note - This function performs a "circular shift", meaining that bits
   *         shifted beyond the end of the integer's range wrap around to
   *         the beginning.
   */
  #define tal_rotl(value, shift) \
    _Generic((value), \
      uint8_t: tal_rotl_u8, \
      uint16_t: tal_rotl_u16, \
      uint32_t: tal_rotl_u32, \
      uint64_t: tal_rotl_u64 \
    )(value, shift)

  tal_fn_attr_inline inline uint8_t tal_rotl_u8(
      const uint8_t value, const int32_t shift);
  tal_fn_attr_inline inline uint16_t tal_rotl_u16(
      const uint16_t value, const int32_t shift);
  tal_fn_attr_inline inline uint32_t tal_rotl_u32(
      const uint32_t value, const int32_t shift);
  tal_fn_attr_inline inline uint64_t tal_rotl_u64(
      const uint64_t value, const int32_t shift);

  /**
   * @brief Performs a circular right shift on an integer value.
   * @param value (uint8_t) The value to rotate.
   * @param shift (int32_t) The number of bits to rotate by.
   * @returns (uint8_t) The result of circularly rotating the given value to 
   *          the right by 'shift' bits.
   * @note - This function performs a "circular shift", meaining that bits
   *         shifted beyond the end of the integer's range wrap around to
   *         the beginning.
   */
  #define tal_rotr(value, shift) \
    _Generic((value), \
      uint8_t: tal_rotr_u8, \
      uint16_t: tal_rotr_u16, \
      uint32_t: tal_rotr_u32, \
      uint64_t: tal_rotr_u64 \
    )(value, shift)

  tal_fn_attr_inline inline uint8_t tal_rotr_u8(
      const uint8_t value, const int32_t shift);
  tal_fn_attr_inline inline uint16_t tal_rotr_u16(
      const uint16_t value, const int32_t shift);
  tal_fn_attr_inline inline uint32_t tal_rotr_u32(
      const uint32_t value, const int32_t shift);
  tal_fn_attr_inline inline uint64_t tal_rotr_u64(
      const uint64_t value, const int32_t shift);

  /**
   * @brief Counts the number of leading zero bits in an integer.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The number of leading zero bits in the given value.
   * @note - "Leading" bits are the most significant bits.
   */
  #define tal_clz(value) \
    _Generic((value), \
      uint8_t: tal_clz_u8, \
      uint16_t: tal_clz_u16, \
      uint32_t: tal_clz_u32, \
      uint64_t: tal_clz_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_clz_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_clz_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_clz_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_clz_u64(const uint64_t value);

  /**
   * @brief Counts the number of leading one bits in an integer.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The number of leading one bits in the given value.
   * @note - "Leading" bits are the most significant bits.
   */
  #define tal_clo(value) \
    _Generic((value), \
      uint8_t: tal_clo_u8, \
      uint16_t: tal_clo_u16, \
      uint32_t: tal_clo_u32, \
      uint64_t: tal_clo_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_clo_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_clo_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_clo_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_clo_u64(const uint64_t value);

  /**
   * @brief Counts the number of trailing zero bits in an integer.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The number of trailing zero bits in the given value.
   * @note - "Trailing" bits are the least significant bits.
   */
  #define tal_ctz(value) \
    _Generic((value), \
      uint8_t: tal_ctz_u8, \
      uint16_t: tal_ctz_u16, \
      uint32_t: tal_ctz_u32, \
      uint64_t: tal_ctz_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_ctz_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_ctz_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_ctz_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_ctz_u64(const uint64_t value);

  /**
   * @brief Counts the number of trailing one bits in an integer.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The number of trailing one bits in the given value.
   * @note - "Trailing" bits are the least significant bits.
   */
  #define tal_cto(value) \
    _Generic((value), \
      uint8_t: tal_cto_u8, \
      uint16_t: tal_cto_u16, \
      uint32_t: tal_cto_u32, \
      uint64_t: tal_cto_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_cto_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_cto_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_cto_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_cto_u64(const uint64_t value);

  /**
   * @brief Counts the number of set bits in an integer.
   * @param value (unsigned integer of any size) The value to query.
   * @returns (int32_t) The number of set bits in the given value.
   */
  #define tal_popcount(value) \
    _Generic((value), \
      uint8_t: tal_popcount_u8, \
      uint16_t: tal_popcount_u16, \
      uint32_t: tal_popcount_u32, \
      uint64_t: tal_popcount_u64 \
    )(value)

  tal_fn_attr_inline inline int32_t tal_popcount_u8(const uint8_t value);
  tal_fn_attr_inline inline int32_t tal_popcount_u16(const uint16_t value);
  tal_fn_attr_inline inline int32_t tal_popcount_u32(const uint32_t value);
  tal_fn_attr_inline inline int32_t tal_popcount_u64(const uint64_t value);

  /**************************************************************************************************
   * @internal Implementation
   **************************************************************************************************/

  // Denotes the number of bits in a numeric type.
  #define tal_uint8_bit_cnt__ ((int)sizeof(uint8_t) * CHAR_BIT)
  #define tal_uint16_bit_cnt__ ((int)sizeof(uint16_t) * CHAR_BIT)
  #define tal_uint32_bit_cnt__ ((int)sizeof(uint32_t) * CHAR_BIT)
  #define tal_uint64_bit_cnt__ ((int)sizeof(uint64_t) * CHAR_BIT)

  // Denotes the number of binary digits in a numeric type.
  #define tal_uint8_dig__ 3
  #define tal_uint16_dig__ 5
  #define tal_uint32_dig__ 10
  #define tal_uint64_dig__ 20

  // Denotes the number of bytes in a numeric type.
  #define tal_uint16_byte_cnt__ ((int)sizeof(uint16_t) / CHAR_BIT)
  #define tal_uint32_byte_cnt__ ((int)sizeof(uint32_t) / CHAR_BIT)
  #define tal_uint64_byte_cnt__ ((int)sizeof(uint64_t) / CHAR_BIT)

  // A bit-mask which represents a single byte (unsigned).
  #define tal_byte_mask__ ((1u << CHAR_BIT) - 1u)

  // The number of digits in the smallest promoted type (int).
  #define tal_min_prom_dig__ tal_uint32_dig__

  uint8_t tal_rbit_u8(const uint8_t value) {
    uint8_t result = 0;
    for (int i = 0; i < tal_uint8_bit_cnt__; ++i) {
      const uint8_t mask = ((value >> i) & 1u);
      result |= (mask << (tal_uint8_bit_cnt__ - 1 - i));
    }
    return result;
  }

  uint16_t tal_rbit_u16(const uint16_t value) {
    uint16_t result = 0;
    for (int i = 0; i < tal_uint16_bit_cnt__; ++i) {
      const uint16_t mask = ((value >> i) & 1u);
      result |= (mask << (tal_uint16_bit_cnt__ - 1 - i));
    }
    return result;
  }

  uint32_t tal_rbit_u32(const uint32_t value) {
    uint32_t result = 0;
    for (int i = 0; i < tal_uint32_bit_cnt__; ++i) {
      const uint32_t mask = ((value >> i) & 1u);
      result |= (mask << (tal_uint32_bit_cnt__ - 1 - i));
    }
    return result;
  }

  uint64_t tal_rbit_u64(const uint64_t value) {
    uint64_t result = 0;
    for (int i = 0; i < tal_uint64_bit_cnt__; ++i) {
      const uint64_t mask = ((value >> i) & 1u);
      result |= (mask << (tal_uint64_bit_cnt__ - 1 - i));
    }
    return result;
  }

  #if defined(tal_ARCH_ARMV7)

    uint16_t tal_rbyte_u16(const uint16_t value) {
      uint16_t result;
      asm ("rev16 %0, %1" : "=rm" (result) : "rm" (value));
      return result;
    }

    uint32_t tal_rbyte_u32(const uint32_t value) {
      uint32_t result;
      asm ("rev %0, %1" : "=rm" (result) : "rm" (value));
      return result;
    }

  #else

    uint16_t tal_rbyte_u16(const uint16_t value) {
      uint16_t result = 0;
      for (int i = 0; i < tal_uint16_byte_cnt__; ++i) {
        const uint16_t mask = (value >> (i * CHAR_BIT)) & (uint16_t)tal_byte_mask__;
        result |= (mask << ((tal_uint16_byte_cnt__ - 1 - i) * CHAR_BIT));
      }
      return result;
    }

    uint32_t tal_rbyte_u32(const uint32_t value) {
      uint32_t result = 0;
      for (int i = 0; i < tal_uint32_byte_cnt__; ++i) {
        const uint32_t mask = (value >> (i * CHAR_BIT)) & (uint32_t)tal_byte_mask__;
        result |= (mask << ((tal_uint32_byte_cnt__ - 1 - i) * CHAR_BIT));
      }
      return result;
    }

  #endif

  uint64_t tal_rbyte_u64(const uint64_t value) {
    uint64_t result = 0;
    for (int i = 0; i < tal_uint64_byte_cnt__; ++i) {
      const uint64_t mask = (value >> (i * CHAR_BIT)) & (uint64_t)tal_byte_mask__;
      result |= (mask << ((tal_uint64_byte_cnt__ - 1 - i) * CHAR_BIT));
    }
    return result;
  }

  bool tal_single_bit_u8(const uint8_t value) {
    return value && !(value & (value - 1u));
  }

  bool tal_single_bit_u16(const uint16_t value) {
    return value && !(value & (value - 1u));
  }

  bool tal_single_bit_u32(const uint32_t value) {
    return value && !(value & (value - 1u));
  }

  bool tal_single_bit_u64(const uint64_t value) {
    return value && !(value & (value - 1u));
  }

  uint8_t tal_bit_ceil_u8(const uint8_t value) {
    if (value <= 1u) { return 1; }
    const int ovf_offset = tal_min_prom_dig__ - tal_uint8_dig__;
    return (1u << (tal_bit_width_u8(value - 1u) + ovf_offset) >> ovf_offset);
  }

  uint16_t tal_bit_ceil_u16(const uint16_t value) {
    if (value <= 1u) { return 1; }
    const int ovf_offset = tal_min_prom_dig__ - tal_uint16_dig__;
    return (1u << (tal_bit_width_u16(value - 1u) + ovf_offset) >> ovf_offset);
  }

  uint32_t tal_bit_ceil_u32(const uint32_t value) {
    if (value <= 1u) { return 1; }
    return 1u << tal_bit_width_u32(value - 1u);
  }

  uint64_t tal_bit_ceil_u64(const uint64_t value) {
    if (value <= 1u) { return 1; }
    return 1u << tal_bit_width_u64(value - 1u);
  }

  uint8_t tal_bit_floor_u8(const uint8_t value) {
    if (value <= 0u) { return 0; }
    return 1u << (tal_bit_width_u8(value - 1u) - 1u);
  }

  uint16_t tal_bit_floor_u16(const uint16_t value) {
    if (value <= 0u) { return 0; }
    return 1u << (tal_bit_width_u16(value - 1u) - 1u);
  }

  uint32_t tal_bit_floor_u32(const uint32_t value) {
    if (value <= 0u) { return 0; }
    return 1u << (tal_bit_width_u32(value - 1u) - 1u);
  }

  uint64_t tal_bit_floor_u64(const uint64_t value) {
    if (value <= 0u) { return 0; }
    return 1u << (tal_bit_width_u64(value - 1u) - 1u);
  }

  int32_t tal_bit_width_u8(const uint8_t value) {
    return tal_uint8_dig__ - tal_clz_u8(value);
  }

  int32_t tal_bit_width_u16(const uint16_t value) {
    return tal_uint16_dig__ - tal_clz_u16(value);
  }

  int32_t tal_bit_width_u32(const uint32_t value) {
    return tal_uint32_dig__ - tal_clz_u32(value);
  }

  int32_t tal_bit_width_u64(const uint64_t value) {
    return tal_uint64_dig__ - tal_clz_u64(value);
  }

  uint8_t tal_rotl_u8(const uint8_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint8_dig__;
    if (shift > 0) {
      return (value << diff) | (value >> (tal_uint8_dig__ - diff));
    } else if (shift < 0) {
      return tal_rotr_u8(value, -shift);
    } else {
      return value;
    }
  }

  uint16_t tal_rotl_u16(const uint16_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint16_dig__;
    if (shift > 0) {
      return (value << diff) | (value >> (tal_uint16_dig__ - diff));
    } else if (shift < 0) {
      return tal_rotr_u16(value, -shift);
    } else {
      return value;
    }
  }

  uint32_t tal_rotl_u32(const uint32_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint32_dig__;
    if (shift > 0) {
      return (value << diff) | (value >> (tal_uint32_dig__ - diff));
    } else if (shift < 0) {
      return tal_rotr_u32(value, -shift);
    } else {
      return value;
    }
  }

  uint64_t tal_rotl_u64(const uint64_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint64_dig__;
    if (shift > 0) {
      return (value << diff) | (value >> (tal_uint64_dig__ - diff));
    } else if (shift < 0) {
      return tal_rotr_u64(value, -shift);
    } else {
      return value;
    }
  }

  uint8_t tal_rotr_u8(const uint8_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint8_dig__;
    if (diff > 0) {
      return (value >> diff) | (value << (tal_uint8_dig__ - diff));
    } else if (diff < 0) {
      return tal_rotl_u8(value, -shift);
    } else {
      return value;
    }
  }

  uint16_t tal_rotr_u16(const uint16_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint16_dig__;
    if (diff > 0) {
      return (value >> diff) | (value << (tal_uint16_dig__ - diff));
    } else if (diff < 0) {
      return tal_rotl_u16(value, -shift);
    } else {
      return value;
    }
  }

  uint32_t tal_rotr_u32(const uint32_t value, const int32_t shift) {
    #if defined(tal_ARCH_ARMV7)
      uint32_t result = 0;
      asm ("ror %0, %1, %2" : "=rm" (result) : "rm" (value), "rm" (shift));
      return result;
    #else
      const int32_t diff = shift % tal_uint32_dig__;
      if (diff > 0) {
        return (value >> diff) | (value << (tal_uint32_dig__ - diff));
      } else if (diff < 0) {
        return tal_rotl_u32(value, -shift);
      } else {
        return value;
      }
    #endif
  }

  uint64_t tal_rotr_u64(const uint64_t value, const int32_t shift) {
    const int32_t diff = shift % tal_uint64_dig__;
    if (diff > 0) {
      return (value >> diff) | (value << (tal_uint64_dig__ - diff));
    } else if (diff < 0) {
      return tal_rotl_u64(value, -shift);
    } else {
      return value;
    }
  }

  int32_t tal_clz_u8(const uint8_t value) {
    #if defined(tal_ARCH_ARMV7)
      const int32_t bit_diff = tal_uint32_bit_cnt__ - tal_uint8_bit_cnt__;
      return tal_clz_u32((uint32_t)value) - bit_diff;
    #else
      int32_t count = 0;
      for (int i = 0; i < tal_uint8_bit_cnt__; ++i) {
        const uint8_t mask = (1u << (tal_uint8_bit_cnt__ - 1 - i));
        if ((value & mask) != 0) { break; }
        ++count;
      }
      return count;
    #endif
  }

  int32_t tal_clz_u16(const uint16_t value) {
    #if defined(tal_ARCH_ARMV7)
      const int32_t bit_diff = tal_uint32_bit_cnt__ - tal_uint16_bit_cnt__;
      return tal_clz_u32((uint32_t)value) - bit_diff;
    #else
      int32_t count = 0;
      for (int i = 0; i < tal_uint16_bit_cnt__; ++i) {
        const uint16_t mask = (1u << (tal_uint16_bit_cnt__ - 1 - i));
        if ((value & mask) != 0) { break; }
        ++count;
      }
      return count;
    #endif
  }

  int32_t tal_clz_u32(const uint32_t value) {
    #if defined(tal_ARCH_ARMV7)
      int32_t result = 0;
      asm ("clz %0, %1" : "=rm" (result) : "rm" (value));
      return result;
    #else
      int32_t count = 0;
      for (int i = 0; i < tal_uint32_bit_cnt__; ++i) {
        const uint32_t mask = (1u << (tal_uint32_bit_cnt__ - 1 - i));
        if ((value & mask) != 0) { break; }
        ++count;
      }
      return count;
    #endif
  }

  int32_t tal_clz_u64(const uint64_t value) {
    #if defined(tal_ARCH_ARMV7)
      const uint32_t high_w = (uint32_t)(value >> (tal_uint64_bit_cnt__ / 2));
      const int32_t high_clz = tal_clz_u32(high_w);
      if (high_clz == tal_uint32_bit_cnt__) {
        return tal_uint32_bit_cnt__ + tal_clz_u32((uint32_t)value);
      } else {
        return high_clz;
      }
    #else
      int32_t count = 0;
      for (int i = 0; i < tal_uint64_bit_cnt__; ++i) {
        const uint64_t mask = (1u << (tal_uint64_bit_cnt__ - 1 - i));
        if ((value & mask) != 0) { break; }
        ++count;
      }
      return count;
    #endif
  }

  int32_t tal_clo_u8(const uint8_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint8_bit_cnt__; ++i) {
      const uint8_t mask = (1u << (tal_uint8_bit_cnt__ - 1 - i));
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_clo_u16(const uint16_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint16_bit_cnt__; ++i) {
      const uint16_t mask = (1u << (tal_uint16_bit_cnt__ - 1 - i));
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_clo_u32(const uint32_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint32_bit_cnt__; ++i) {
      const uint32_t mask = (1u << (tal_uint32_bit_cnt__ - 1 - i));
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_clo_u64(const uint64_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint64_bit_cnt__; ++i) {
      const uint64_t mask = (1u << (tal_uint64_bit_cnt__ - 1 - i));
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_ctz_u8(const uint8_t value) {
    int32_t count = 0;
    for (int i= 0; i < tal_uint8_bit_cnt__; ++i) {
      const uint8_t mask = (1u << i);
      if ((value & mask) != 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_ctz_u16(const uint16_t value) {
    int32_t count = 0;
    for (int i= 0; i < tal_uint16_bit_cnt__; ++i) {
      const uint16_t mask = (1u << i);
      if ((value & mask) != 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_ctz_u32(const uint32_t value) {
    int32_t count = 0;
    for (int i= 0; i < tal_uint32_bit_cnt__; ++i) {
      const uint32_t mask = (1u << i);
      if ((value & mask) != 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_ctz_u64(const uint64_t value) {
    int32_t count = 0;
    for (int i= 0; i < tal_uint64_bit_cnt__; ++i) {
      const uint64_t mask = (1u << i);
      if ((value & mask) != 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_cto_u8(const uint8_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint8_bit_cnt__; ++i) {
      const uint8_t mask = (1u << i);
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_cto_u16(const uint16_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint16_bit_cnt__; ++i) {
      const uint16_t mask = (1u << i);
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_cto_u32(const uint32_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint32_bit_cnt__; ++i) {
      const uint32_t mask = (1u << i);
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_cto_u64(const uint64_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint64_bit_cnt__; ++i) {
      const uint64_t mask = (1u << i);
      if ((value & mask) == 0) { break; }
      ++count;
    }
    return count;
  }

  int32_t tal_popcount_u8(const uint8_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint8_bit_cnt__; ++i) {
      const uint8_t mask = (1u << i);
      if ((value & mask) != 0) { ++count; }
    }
    return count;
  }

  int32_t tal_popcount_u16(const uint16_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint16_bit_cnt__; ++i) {
      const uint16_t mask = (1u << i);
      if ((value & mask) != 0) { ++count; }
    }
    return count;
  }

  int32_t tal_popcount_u32(const uint32_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint32_bit_cnt__; ++i) {
      const uint32_t mask = (1u << i);
      if ((value & mask) != 0) { ++count; }
    }
    return count;
  }

  int32_t tal_popcount_u64(const uint64_t value) {
    int32_t count = 0;
    for (int i = 0; i < tal_uint64_bit_cnt__; ++i) {
      const uint64_t mask = (1u << i);
      if ((value & mask) != 0) { ++count; }
    }
    return count;
  }

  /** @endinternal */

#if defined(__cplusplus)
  }
#endif