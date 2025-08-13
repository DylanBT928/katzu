add_library(katzu_engine SHARED src/engine.cpp)

target_include_directories(katzu_engine PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(katzu_engine PRIVATE KATZU_BUILD_DLL)

set_target_properties(katzu_engine PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(katzu_engine
  PUBLIC 
    SDL3::SDL3-static
    glm::glm
    glad
)

if(APPLE)
  target_link_libraries(katzu_engine PRIVATE "-framework OpenGL")
elseif(WIN32)
  target_link_libraries(katzu_engine PRIVATE opengl32)
else()
  find_package(OpenGL REQUIRED)
  target_link_libraries(katzu_engine PRIVATE OpenGL::GL)
endif()

set_target_properties(katzu_engine PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
