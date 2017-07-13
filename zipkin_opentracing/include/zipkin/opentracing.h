#include <opentracing/tracer.h>
#include <zipkin/ip_address.h>

namespace zipkin {
struct ZipkinOtTracerOptions {
  std::string collector_host = "localhost";
  uint32_t collector_port = 9411;

  std::string service_name;
  IpAddress service_address;
};

std::shared_ptr<opentracing::Tracer>
makeZipkinOtTracer(const ZipkinOtTracerOptions &options);
} // namespace zipkin
