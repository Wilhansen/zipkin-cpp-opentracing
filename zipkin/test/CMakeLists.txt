macro(_zipkin_test TEST_NAME)
  add_executable(${TEST_NAME} ${ARGN})
  target_link_libraries(${TEST_NAME} zipkin)
  add_test(${TEST_NAME} ${TEST_NAME})
endmacro()

_zipkin_test(hex_test hex_test.cc)
_zipkin_test(endpoint_test endpoint_test.cc)
