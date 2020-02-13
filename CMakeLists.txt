cmake_minimum_required (VERSION 2.8)
project(patliteusb C)


function(find_static_library LIB_NAME OUT)

    if (WIN32 OR MSVC)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    elseif (UNIX)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    endif()      

    find_library(
        FOUND_${LIB_NAME}_STATIC
        ${LIB_NAME}
        )

    if (FOUND_${LIB_NAME}_STATIC)
        get_filename_component(ABS_FILE ${FOUND_${LIB_NAME}_STATIC} ABSOLUTE)
    else()
        message(SEND_ERROR "Unable to find library ${LIB_NAME}")
    endif()

    set(${OUT} ${ABS_FILE} PARENT_SCOPE)

endfunction()


# patliteusb lib (shared)
add_library(patliteusb SHARED patliteusb.h)
set_target_properties(patliteusb PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(patliteusb usb-1.0 pthread udev)

## patliteusb lib (static)
#find_static_library(usb-1.0 LIBUSB_STATIC)
#find_static_library(pthread PTHREAD_STATIC)
#add_library(patliteusb_static STATIC patliteusb.h)
#set_target_properties(patliteusb_static PROPERTIES LINKER_LANGUAGE C)
#target_link_libraries(patliteusb_static ${LIBUSB_STATIC} ${PTHREAD_TATIC} ${UDEV_STATIC})

# demo patliteusb cli (shared)
add_executable(patliteusb_cli patliteusb_cli.c)
target_link_libraries(patliteusb_cli LINK_PUBLIC patliteusb)

## demo patliteusb cli (static)
#add_executable(patliteusb_cli_static patliteusb_cli.c)
#target_link_libraries(patliteusb_cli_static LINK_PUBLIC patliteusb_static)
