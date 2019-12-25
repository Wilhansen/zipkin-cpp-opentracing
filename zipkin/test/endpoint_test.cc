#include <zipkin/tracer.h>

#define CATCH_CONFIG_MAIN
#include <zipkin/catch/catch.hpp>
using namespace zipkin;

TEST_CASE("endpoint") {
    {
        // Empty endpoint
        Endpoint ep;
        CHECK(ep.toJson() == "{\"serviceName\":\"\"}");
    }

    {
        // Only service name is set
        Endpoint ep("foo", IpAddress(IpVersion::v4, ""), 0);
        CHECK(ep.toJson() == "{\"serviceName\":\"foo\"}");
    }

    {
        // Service name is set but IP address is not valid IPv4
        Endpoint ep("foo", IpAddress(IpVersion::v4, "foo.example.com"), 0);
        CHECK(ep.toJson() == "{\"serviceName\":\"foo\"}");
    }

    {
        // Service name is set, IP address is set to IPv4, port not set
        Endpoint ep("foo", IpAddress(IpVersion::v4, "1.2.3.4"), 0);
        CHECK(ep.toJson() == "{\"ipv4\":\"1.2.3.4\",\"serviceName\":\"foo\"}");
    }

    {
        // Service name is set, IP address is not set, port is set
        Endpoint ep("foo", IpAddress(), 5678);
        CHECK(ep.toJson() == "{\"port\":5678,\"serviceName\":\"foo\"}");
    }

    {
        // Service name is set, IP address is set to IPv4, port is set
        Endpoint ep("foo", IpAddress(IpVersion::v4, "1.2.3.4"), 5678);
        CHECK(ep.toJson() == "{\"ipv4\":\"1.2.3.4\",\"port\":5678,\"serviceName\":\"foo\"}");
    }

    {
        // Service name is set, IP address is set to IPv6, port is set
        Endpoint ep("foo", IpAddress(IpVersion::v6, "2001:1234:0000:0:0:a:b:c"), 5678);
        CHECK(ep.toJson() == "{\"ipv6\":\"2001:1234::a:b:c\",\"port\":5678,\"serviceName\":\"foo\"}");
    }
}
