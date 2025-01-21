// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef LIB_EXTRAS_DEC_JPEGLI_H_
#define LIB_EXTRAS_DEC_JPEGLI_H_

// Decodes JPG pixels and metadata in memory using the libjpegli library.

#include <cstdint>
#include <vector>

#include "lib/base/data_parallel.h"
#include "lib/base/status.h"
#include "lib/base/types.h"

namespace jxl {
namespace extras {

class PackedPixelFile;

struct JpegDecompressParams {
  JxlDataType output_data_type = JXL_TYPE_UINT8;
  JxlEndianness output_endianness = JXL_NATIVE_ENDIAN;
  bool force_rgb = false;
  bool force_grayscale = false;
  int num_colors = 0;
  bool two_pass_quant = true;
  // 0 = none, 1 = ordered, 2 = Floyd-Steinberg
  int dither_mode = 2;
};

Status DecodeJpeg(const std::vector<uint8_t>& compressed,
                  const JpegDecompressParams& dparams, ThreadPool* pool,
                  PackedPixelFile* ppf);

}  // namespace extras
}  // namespace jxl

#endif  // LIB_EXTRAS_DEC_JPEGLI_H_
