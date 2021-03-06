/*
 * Copyright 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
// Interface to the A2DP AAC Encoder
//

#ifndef A2DP_AAC_ENCODER_H
#define A2DP_AAC_ENCODER_H

#include "a2dp_aac_constants.h"
#include "a2dp_codec_api.h"

// Is used in btav_a2dp_codec_config_t.codec_specific_1 when codec is AAC
enum class AacEncoderBitrateMode : int64_t {
  // Variable bitrate mode unsupported when used in a codec report, and upper
  // layer can use this value as system default (keep current settings)
  AACENC_BR_MODE_CBR = A2DP_AAC_VARIABLE_BIT_RATE_DISABLED,
  // Constant bitrate mode when Variable bitrate mode is supported. This can
  // also be used to disable Variable bitrate mode by upper layer
  AACENC_BR_MODE_VBR_C = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x00),
  // Variable bitrate mode (very low bitrate for software encoding).
  AACENC_BR_MODE_VBR_1 = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x01),
  // Variable bitrate mode (low bitrate for software encoding).
  AACENC_BR_MODE_VBR_2 = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x02),
  // Variable bitrate mode (medium bitrate for software encoding).
  AACENC_BR_MODE_VBR_3 = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x03),
  // Variable bitrate mode (high bitrate for software encoding).
  AACENC_BR_MODE_VBR_4 = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x04),
  // Variable bitrate mode (very high bitrate for software encoding).
  AACENC_BR_MODE_VBR_5 = (A2DP_AAC_VARIABLE_BIT_RATE_ENABLED | 0x05),
};

// Loads the A2DP AAC encoder.
// Return true on success, otherwise false.
bool A2DP_LoadEncoderAac(void);

// Unloads the A2DP AAC encoder.
void A2DP_UnloadEncoderAac(void);

// Initialize the A2DP AAC encoder.
// |p_peer_params| contains the A2DP peer information
// The current A2DP codec config is in |a2dp_codec_config|.
// |read_callback| is the callback for reading the input audio data.
// |enqueue_callback| is the callback for enqueueing the encoded audio data.
void a2dp_aac_encoder_init(const tA2DP_ENCODER_INIT_PEER_PARAMS* p_peer_params,
                           A2dpCodecConfig* a2dp_codec_config,
                           a2dp_source_read_callback_t read_callback,
                           a2dp_source_enqueue_callback_t enqueue_callback);

// Cleanup the A2DP AAC encoder.
void a2dp_aac_encoder_cleanup(void);

// Reset the feeding for the A2DP AAC encoder.
void a2dp_aac_feeding_reset(void);

// Flush the feeding for the A2DP AAC encoder.
void a2dp_aac_feeding_flush(void);

// Get the A2DP AAC encoder interval (in milliseconds).
uint64_t a2dp_aac_get_encoder_interval_ms(void);

// Get the A2DP AAC encoded maximum frame size
int a2dp_aac_get_effective_frame_size();

// Prepare and send A2DP AAC encoded frames.
// |timestamp_us| is the current timestamp (in microseconds).
void a2dp_aac_send_frames(uint64_t timestamp_us);

#endif  // A2DP_AAC_ENCODER_H
