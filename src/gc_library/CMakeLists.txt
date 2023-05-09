include(GenerateExportHeader)


add_library(gc_library gc_library.cpp)



add_library(myproject::gc_library ALIAS gc_library)

target_link_libraries(gc_library PRIVATE myproject_options myproject_warnings)

target_include_directories(gc_library ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

target_compile_features(gc_library PUBLIC cxx_std_20)

set_target_properties(
  gc_library
  PROPERTIES VERSION ${PROJECT_VERSION}
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN YES)

generate_export_header(gc_library EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/myproject/gc_library_export.hpp)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(gc_library PUBLIC gc_library_STATIC_DEFINE)
endif()
