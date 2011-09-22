
if(UNIX)
    set( INSTALL_PREFIX "/usr/local" CACHE PATH " install path" )
    set( PLUGINS_EXT "so" )
    set( PLUGINS_PRE "lib" )
elseif(WIN32)
    set( INSTALL_PREFIX "C:/Program Files/MATIS" CACHE PATH " install path")
    set( PLUGINS_EXT "dll" )
    set( PLUGINS_PRE "" )
endif()

set( GILVIEWER_PLUGIN_INSTALL_PREFIX "${INSTALL_PREFIX}/lib/GilViewer/")
set( GILVIEWER_PLUGINS_DIR ${GILVIEWER_PLUGIN_INSTALL_PREFIX} )

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/src/GilViewer/config/config_plugins.hpp.cmake.in ${CMAKE_CURRENT_SOURCE_DIR}/src/GilViewer/config/config_plugins.hpp )

macro(scan_plugins dir)
    file( GLOB list "${dir}/*" )
    list( SORT list )
    foreach( entry ${list} )
        if ( IS_DIRECTORY ${entry} )
            if ( EXISTS ${entry}/CMakeLists.txt )
                message( STATUS "Configuring  ${entry} plugin" )
                add_subdirectory( ${entry} )
            else()
                message( STATUS "recursing to ${entry}" )
                scan_plugins(${entry})
            endif()
        endif()
    endforeach()
endmacro(scan_plugins)

message( STATUS "Scanning plugins :" )
scan_plugins("plugins")
