/**
 * This file is part of the Titan Flight Computer Project
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
 * @file common/util/str.h
 * @authors Aaron McBride
 * @brief String manipulation and querying utilities.
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "tal/util/attributes.h"
#include "tal/util/misc.h"

#if defined(__cplusplus)
  extern "C" {
#endif
  
  /**
   * @brief Determines the length of a string.
   * @param str (const char*) The null-terminated byte string to query.
   * @returns (int32_t) The length of 'str' in bytes, not including the null 
   *          terminator.
   */
  tal_fn_attr_inline int32_t tal_strlen(const char* str);

  /**
   * @brief Copies a string from one location to annother.
   * @param dest (char* restrict) The destination.
   * @param src (const char* restrict) The source (null-terminated byte string).
   * @returns A pointer to the destination string.
   * @note - All characters up to and including the null-terminator of 'src' are copied.
   * @warning - The destination string must be large enough to hold the source string.
   * @warning - The source and destination strings/locations must not overlap.
   */
  tal_fn_attr_inline inline char* tal_strcpy(char* restrict dest, const char* restrict src);

  /**
   * @brief Swaps the contents of two strings.
   * @param str_l (char* restrict) The "left-hand" string.
   * @param str_r (char* restrict) The "right-hand" string.
   * @warning - The left and right-hand strings must not overlap.
   */
  tal_fn_attr_inline inline void tal_strswap(char* restrict str_l, char* restrict str_r);

  /**
   * @brief TODO
   * @param dest
   * @param src
   * @returns
   */
  tal_fn_attr_inline inline char* tal_strcat(char* dest, const char* src);

  /**
   * @brief TODO
   * @param dest 
   * @param src 
   * @param n 
   * @return 
   */
  tal_fn_attr_inline inline char* tal_strncat(char* dest, const char* src, int32_t n);

  /**
   * @brief TODO
   * @param str_l 
   * @param str_r 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strcmp(const char* str_l, const char* str_r);

  /**
   * @brief TODO
   * @param str_l 
   * @param str_r 
   * @param n 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strncmp(const char* str_l, const char* str_r, int32_t n);
  
  
  /**
   * @brief TODO
   * @param str
   * @param qchar
   * @returns
   */
  tal_fn_attr_inline inline char* tal_strchr(const char* str, char qchar);

  /**
   * @brief TODO
   * @param str 
   * @param qchar 
   * @return 
   */
  tal_fn_attr_inline inline char* tal_strrchr(const char* str, char qchar);

  /**
   * @brief TODO
   * @param str
   * @param qchar
   * @param n
   */
  tal_fn_attr_inline inline char* tal_strnchr(const char* str, char qchar, int32_t n);

  /**
   * @brief TODO
   * @param str
   * @param qstr
   * @returns
   */
  tal_fn_attr_inline inline int32_t tal_strchr_i(const char* str, char qchar);

  /**
   * @brief TODO
   * @param str
   * @param qchar
   * @returns
   */
  tal_fn_attr_inline inline int32_t tal_strrchr_i(const char* str, char qchar);

  /**
   * @brief TODO
   * @param str 
   * @param qchar 
   * @param n 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strnchr_i(const char* str, char qchar, int32_t n);

  /**
   * @brief TODO
   * @param str
   * @param qstr
   * @returns
   */
  tal_fn_attr_inline inline int32_t tal_strspn(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strcspn(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @return 
   */
  tal_fn_attr_inline inline char* tal_strstr(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @param n 
   * @return 
   */
  tal_fn_attr_inline inline char* tal_strnstr(const char* str, const char* qstr, int32_t n);

  /**
   * @brief TODO
   * @param str
   * @param qstr
   * @returns
   */
  tal_fn_attr_inline inline char* tal_strrstr(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strstr_i(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strrstr_i(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str 
   * @param qstr 
   * @param n 
   * @return 
   */
  tal_fn_attr_inline inline int32_t tal_strnstr_i(const char* str, const char* qstr, int32_t n);

  /**
   * @brief TODO
   * @param str
   * @param qstr
   * @returns
   */
  tal_fn_attr_inline inline char* tal_strpbrk(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str
   * @param qstr
   * @returns
   */
  tal_fn_attr_inline inline int32_t tal_strpbrk_i(const char* str, const char* qstr);

  /**
   * @brief TODO
   * @param str
   * @param delim
   * @returns
   */
  tal_fn_attr_inline inline char* tal_strsplit(const char* str, char* tok, const char* delim);

  /**************************************************************************************************
   * @internal Implementation
   **************************************************************************************************/

  char* tal_strcat (char* dest, const char* src) {
    if (dest && src) {
      char* tdest = dest;
      while (*tdest) { ++tdest; }
      while (*src) { 
        *tdest = *src; 
        ++tdest;
        ++src;
      }
    }
    return dest;
  }

  char* tal_strncat(char* dest, const char* src, int32_t n) {
    if (dest && src && n > 0) {
      char* tdest = dest;
      while (*tdest) { ++tdest; }
      for (int32_t i = 0; i < n && *src; ++i) {
        *tdest = *src;
        ++tdest;
        ++src;
      }
    }
    return dest;
  }

  char* tal_strcpy(char* restrict dest, const char* restrict src) {
    if (dest && src) {
      char* tdest = dest;
      while (*src) {
        *tdest = *src;
        ++tdest;
        ++src;
      }
    }
    return dest;
  }

  void tal_strswap(char* restrict str_l, char* restrict str_r) {
    if (str_l && str_r) {
      while (*str_l && *str_r) {
        char t_char = *str_l;
        *str_l = *str_r;
        *str_r = t_char;
        ++str_l;
        ++str_r;
      }
      str_l = 0;
      str_r = 0;
    }
  }

  int32_t tal_strcmp(const char* str_l, const char* str_r) {
    if (!str_l || !str_r) { return 0; }
    while (*str_l == *str_r && *str_l && *str_r) {
      str_l++;
      str_r++;
    }
    return (int32_t)*str_l - (int32_t)*str_r;
  }

  int32_t tal_strncmp(const char* str_l, const char* str_r, int32_t n) {
    if (str_l && str_r && n > 0) {
      for (int32_t i = 0; i < n; ++i) {
        if (*str_l != *str_r || !*str_l || !*str_r) { 
          return (int32_t)*str_l - (int32_t)*str_r; 
        }
        ++str_l;
        ++str_r;
      }
    }
    return 0;
  }

  char* tal_strchr(const char* str, char qchar) {
    if (str) {
      while (*str != qchar) {
        if (!*str) { return NULL; }
        ++str;
      }
    }
    return (char*)str;
  }

  char* tal_strrchr(const char* str, char qchar) {
    if (str) {
      const char* t_str = str;
      while (*t_str) {
        if (*t_str == qchar) { str = t_str; }
        ++t_str;
      }
      if (!qchar) { return (char*)t_str; }
    }
    return (char*)str;
  }

  char* tal_strnchr(const char* str, char qchar, int32_t n) {
    if (str && n > 0)  {
      int32_t count = 0;
      while (*str) {
        if (*str == qchar) {
          ++count;
          if (count >= n) { return (char*)str; }
        }
        ++str;
      }
      if (!qchar && n == 1) { return (char*)str; }
    }
    return NULL;
  }

  int32_t tal_strchr_i(const char* str, char qchar) {
    if (!str) { return tal_err_idx; }
    int32_t i = 0;
    while (*str != qchar) {
      if (!*str) { return tal_err_idx; }
      ++str;
      ++i;
    }
    return i;
  }

  int32_t tal_strrchr_i(const char* str, char qchar) {
    int32_t ret = tal_err_idx;
    if (str) {
      int32_t i = 0;
      while (*str) {
        if (*str == qchar) { ret == i; }
        ++str;
        ++i;
      }
      if (!qchar) { return i; }
    }
    return ret;
  }

  int32_t tal_strnchr_i(const char* str, char qchar, int32_t n) {
    if (str) {
      int32_t count = 0;
      int32_t i = 0;
      while (*str) {
        if (*str == qchar) {
          ++count;
          if (count >= n) { return i; }
        }
        ++str;
        ++i;
      }
      if (!qchar && n == 1) { return i; }
    }
    return tal_err_idx;
  }

  int32_t tal_strspn(const char* str, const char* qstr) {
    if (!str || !qstr) { return tal_err_idx; }
    int32_t count = 0;
    while (*str) {
      const char* t_qstr = qstr;
      while (*str != *t_qstr) {
        ++t_qstr;
        if (!*t_qstr) { return count; }
      }
      ++count;
      ++str;
    }
    return count;
  }

  int32_t tal_strcspn(const char* str, const char* qstr) {
    if (!str || !qstr) { return tal_err_idx; }
    int32_t count = 0;
    while (*str) {
      const char* t_qstr = qstr;
      while (*t_qstr) {
        if (*t_qstr == str) { return count; }
        ++t_qstr;
      }
      ++count;
      ++str;
    }
    return count;
  }

  char* tal_strstr(const char* str, const char* qstr) {
    if (str && qstr) {
      const char* t_str = str;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (!*t_qstr) { return (char*)t_str; }
        } else {
          t_qstr = qstr;
          t_str = str;
        }
        ++str;
      }
    }
    return NULL;
  }

  char* tal_strnstr(const char* str, const char* qstr, int32_t n) {
    if (str && qstr) {
      int32_t count = 0;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (!*t_qstr) {
            ++count;
            if (count == n) { return (char*)t_qstr; }
          }
        } else {
          t_qstr = qstr;
        }
        ++str;
      }
    }
    return NULL;
  }

  char* tal_strrstr(const char* str, const char* qstr) {
    const char* lstr = NULL;
    if (str && qstr) {
      const char* t_str = str;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (t_qstr == *str) { lstr = t_str; }
        } else {
          t_qstr = qstr;
          t_str = str; 
        }
        ++str;
      }
    }
    return (char*)lstr;
  }

  int32_t tal_strstr_i(const char* str, const char* qstr) {
    if (str && qstr) {
      int32_t i = 0;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (!*t_qstr) { return i; }
        } else {
          t_qstr = qstr;
        }
        ++str;
        ++i;
      }
    }
    return tal_err_idx;
  }

  int32_t tal_strrstr_i(const char* str, const char* qstr) {
    int32_t ret = tal_err_idx;
    if (str && qstr) {
      int32_t i = 0;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (!*t_qstr) { ret = i; }
        } else {
          t_qstr = qstr;
        }
        ++str;
        ++i;
      }
    }
    return ret;
  }

  int32_t tal_strnstr_i(const char* str, const char* qstr, int32_t n) {
    if (str && qstr && n > 0) {
      int32_t i = 0;
      int32_t count = 0;
      const char* t_qstr = qstr;
      while (*str) {
        if (*t_qstr == *str) {
          ++t_qstr;
          if (!*t_qstr) { 
            ++count; 
            if (count == n) { return i; }
          }
        } else {
          t_qstr = qstr;
        }
        ++str;
        ++i;
      }
    }
    return tal_err_idx;
  }

  char* tal_strpbrk(const char* str, const char* qstr) {
    if (str && qstr) {
      while (*str) {
        const char* t_qstr = qstr;
        while (*t_qstr) {
          if  (*t_qstr == *str) { return (char*)str; }
        }
        ++str;
      }
    }
    return NULL;
  }

  int32_t tal_strpbrk_i(const char* str, const char* qstr) {
    if (str && qstr) {
      int32_t i = 0;
      while (*str) {
        const char* t_qstr = qstr;
        while (*t_qstr) {
          if (*t_qstr == str) { return i; }
        }
        ++str;
        ++i;
      }
    }
    return tal_err_idx;
  }

  int32_t tal_strlen(const char* str) {
    int32_t len = 0;
    while (str[len]) { ++len; }
    return len;
  }

  char* tal_strsplit(const char* str, char* tok, const char* delim) {
    if (str && tok && delim) {
      const char* t_str = str;
      const char* t_delim = delim;
      while (*str) {
        if (*str == *t_delim) {
          ++t_delim;
          if (!*t_delim) {
            ++str;
            while (t_str != str) {
              *tok = *t_str;
              ++t_str;
              ++tok;
              return (char*)str;
            }
          }
        } else {
          t_delim = delim;
          t_str = str;
        }
        ++str;
      }
    }
    return NULL;
  }

#if defined(__cplusplus)
  }
#endif