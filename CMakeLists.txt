project(plasma-dataengine-libksane)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)

add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
    ${QT_INCLUDES}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${KDE_INCLUDES}
)

set(sane_engine_SRCS saneengine.cpp)

kde4_add_plugin(plasma_engine_libksane ${sane_engine_SRCS})
target_link_libraries(
    plasma_engine_libksane
    ${KDE4_KDECORE_LIBS}
    ${KDE4_PLASMA_LIBS}
)

install(
    TARGETS plasma_engine_libksane
    DESTINATION ${PLUGIN_INSTALL_DIR}
)

install(
    FILES plasma-dataengine-libksane.desktop
    DESTINATION ${SERVICES_INSTALL_DIR}
)
