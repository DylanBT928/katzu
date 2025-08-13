add_executable(katzu src/main.cpp)

target_link_libraries(katzu PRIVATE katzu_engine)

set_target_properties(katzu PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
