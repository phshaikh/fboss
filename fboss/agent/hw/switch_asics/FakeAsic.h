// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

#include "fboss/agent/hw/switch_asics/HwAsic.h"

namespace facebook::fboss {

class FakeAsic : public HwAsic {
 public:
  bool isSupported(Feature) const override {
    return true; // fake supports all features
  }
  AsicType getAsicType() const override {
    return AsicType::ASIC_TYPE_FAKE;
  }
  cfg::PortSpeed getMaxPortSpeed() const override {
    return cfg::PortSpeed::HUNDREDG;
  }
  std::set<cfg::StreamType> getQueueStreamTypes(bool cpu) const override {
    if (cpu) {
      return {cfg::StreamType::MULTICAST};
    } else {
      return {cfg::StreamType::UNICAST};
    }
  }
  int getDefaultNumPortQueues(cfg::StreamType streamType) const override {
    return streamType == cfg::StreamType::UNICAST ? 8 : 10;
  }
  bool needsObjectKeyCache() const override {
    return false;
  }
};

} // namespace facebook::fboss
