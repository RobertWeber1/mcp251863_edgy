cmake_minimum_required(VERSION 3.12)

include(~/workspace/pico-sdk/pico_sdk_import.cmake)
project(pico_slcan CXX C)
pico_sdk_init()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--print-memory-usage")

add_executable(pico_slcan
	src/main.cc
	src/reset_interface.c
	src/stdio_usb.c
	src/stdio_usb_descriptors.cc
)

target_include_directories(pico_slcan
    PRIVATE src
)

# enable usb output, disable uart output
# pico_enable_stdio_usb(pico_slcan 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(pico_slcan)

target_compile_definitions(pico_slcan
    PRIVATE
        LIB_PICO_STDIO_USB=1
        PICO_STDIO_USB_ENABLE_RESET_VIA_VENDOR_INTERFACE=1
        PICO_STDIO_USB_RESET_INTERFACE_SUPPORT_RESET_TO_BOOTSEL=1
        PICO_STDIO_USB_RESET_INTERFACE_SUPPORT_RESET_TO_FLASH_BOOT=1
)


target_link_libraries(pico_slcan
    pico_stdlib
    tinyusb_device_unmarked
    pico_stdio
    pico_time
    pico_unique_id
    pico_usb_reset_interface_headers
)


    # target_include_directories(pico_stdio_usb INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

    # target_sources(pico_stdio_usb INTERFACE
    #     ${CMAKE_CURRENT_LIST_DIR}/reset_interface.c
    #     ${CMAKE_CURRENT_LIST_DIR}/stdio_usb.c
    #     ${CMAKE_CURRENT_LIST_DIR}/stdio_usb_descriptors.c
    # )

    # target_link_libraries(pico_stdio_usb INTERFACE
    #     tinyusb_device_unmarked
    #     pico_stdio
    #     pico_time
    #     pico_unique_id
    #     pico_usb_reset_interface_headers
    # )
