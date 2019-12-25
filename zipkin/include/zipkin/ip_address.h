#pragma once

#include <cstdint>
#include <string>

namespace zipkin {
enum class IpVersion { v4, v6 };

class IpAddress {
public:
  IpAddress() = default;

  IpAddress(IpVersion version, const std::string &address);

  IpVersion version() const { return version_; }

  const std::string &addressAsString() const { return address_; }

  bool valid() const { return !address_.empty(); }

private:
  IpVersion version_;
  std::string address_;
};
} // namespace zipkin
