project(SAMI)

add_library(SAMI SHARED)

# Kaynak dosyalarını ekle
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/SAMI/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/SAMI/*.h"
)
target_sources(SAMI PRIVATE ${SOURCES})

# Header dosyalarını dahil et
target_include_directories(SAMI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/spdlog/include
)

# Build output klasörleri
set_target_properties(SAMI PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SAMI"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SAMI"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SAMI"
)

if(WIN32 AND MSVC)
    target_compile_definitions(SAMI PRIVATE
        SM_PLATFORM_WINDOWS
        SM_BUILD_DLL
    )

    # MSVC ayarları
    target_compile_options(SAMI PRIVATE /utf-8 /D_SCL_SECURE_NO_WARNINGS)

    set_target_properties(SAMI PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
endif()

# Debug / Release tanımları
target_compile_definitions(SAMI PRIVATE
    $<$<CONFIG:Debug>:SM_DEBUG>
    $<$<CONFIG:Release>:SM_RELEASE>
)

# Post-build: DLL’i SandBox dizinine kopyala
add_custom_command(TARGET SAMI POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SandBox"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SAMI>"
        "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SandBox"
)
