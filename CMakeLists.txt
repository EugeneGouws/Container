cmake_minimum_required(VERSION 3.19)
project(Container LANGUAGES CXX)

set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Xml Concurrent Network)

qt_standard_project_setup()


qt_add_executable(Container
    WIN32 MACOSX_BUNDLE
    main.cpp



    mainclient.h mainclient.cpp
    widget.h widget.cpp
    resource.qrc
    container.h container.cpp
    box.h box.cpp
    cylinder.h cylinder.cpp
    containerfactory.h containerfactory.cpp
    containerlist.h containerlist.cpp
    palletlist.h palletlist.cpp
    pallet.h pallet.cpp
    backup.h backup.cpp
    xmlwriter.h xmlwriter.cpp

)

target_link_libraries(Container
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Xml
        Qt::Concurrent
        Qt::Network

)

include(GNUInstallDirs)

install(TARGETS Container
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Container
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
