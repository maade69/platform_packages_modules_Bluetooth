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

#pragma once

#include <cstdint>
#include <vector>

#include "device.h"

namespace rootcanal {

class Classic : public Device {
 public:
  Classic();
  Classic(const std::vector<std::string>& args);
  ~Classic() = default;

  static std::shared_ptr<Device> Create(const std::vector<std::string>& args) {
    return std::make_shared<Classic>(args);
  }

  // Return a string representation of the type of device.
  virtual std::string GetTypeString() const override { return "classic"; }

 private:
  static bool registered_;
};

}  // namespace rootcanal
