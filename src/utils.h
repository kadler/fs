#pragma once

#include "uv.h"

#include <string>

#define BEGIN_CPP try {

#define END_CPP                                                                \
  }                                                                            \
  catch (std::exception & e) {                                                 \
    Rf_error("C++ exception: %s", e.what());                                   \
  }

// If dirent is not unknown, just return it, otherwise stat the file and get
// the filetype from that.
uv_dirent_type_t get_dirent_type(
    const char* path,
    const uv_dirent_type_t& entry_type = UV_DIRENT_UNKNOWN,
    bool fail = true);

std::string path_tidy_(const std::string& in);
