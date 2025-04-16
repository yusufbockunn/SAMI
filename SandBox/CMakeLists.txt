project(SandBox)

add_executable(SandBox)

# Kaynak dosyalarını ekle
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
target_sources(SandBox PRIVATE ${SOURCES})

# SAMI kütüphanesini bağla
target_link_libraries(SandBox PRIVATE SAMI)

# Include dizinini ayarla (SAMI'nin src klasörü dahil ediliyor)
target_include_directories(SandBox PRIVATE
    ${CMAKE_SOURCE_DIR}/SAMI/src
)

# Çıktı dizinini ayarla
set_target_properties(SandBox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>-x64/SandBox"
)

# MSVC için özel ayarlar
if(WIN32 AND MSVC)
    target_compile_options(SandBox PRIVATE /utf-8 /D_SCL_SECURE_NO_WARNINGS)

    set_target_properties(SandBox PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
endif()

# Platform ve yapı konfigürasyon tanımları
target_compile_definitions(SandBox PRIVATE
    SM_PLATFORM_WINDOWS
    $<$<CONFIG:Debug>:SM_DEBUG>
    $<$<CONFIG:Release>:SM_RELEASE>
)
