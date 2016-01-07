cmake_minimum_required(VERSION 3.2)
project(meat)

set(ENV{PATH} "/Users/boneskull/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Applications/Server.app/Contents/ServerRoot/usr/bin:/Applications/Server.app/Contents/ServerRoot/usr/sbin:/usr/local/git/bin:/usr/local/MacGPG2/bin:./node_modules/.bin:/usr/local/bin:/usr/local/sbin:/usr/local/heroku/bin:/usr/local/opt/coreutils/libexec/gnubin")
set(PLATFORMIO_CMD "/usr/local/bin/platformio")

include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/variants/d1_mini")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/cores/esp8266")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/cores/esp8266/spiffs")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/libraries/ESP8266WiFi/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/libraries/ESP8266WiFi/src/arch")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/libraries/ESP8266WiFi/src/include")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoespressif/libraries/ESP8266WiFi/src/lwip")
include_directories("$ENV{HOME}/.platformio/lib/Adafruit_Unified_Sensor_ID31")
include_directories("$ENV{HOME}/.platformio/lib/Adafruit_DHT_ID19")
include_directories("$ENV{HOME}/.platformio/lib/Adafruit_DHT_Unified_ID18")
include_directories("/Volumes/alien/projects/platformio/meat/lib/MAX6675")
include_directories("$ENV{HOME}/.platformio/lib/Blynk_ID415/Adapters")
include_directories("$ENV{HOME}/.platformio/lib/Blynk_ID415/Blynk")
include_directories("$ENV{HOME}/.platformio/lib/Blynk_ID415")
include_directories("$ENV{HOME}/.platformio/lib/Blynk_ID415/utility")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-xtensa/xtensa-lx106-elf/include")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-xtensa/lib/gcc/xtensa-lx106-elf/4.8.2/include")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-xtensa/lib/gcc/xtensa-lx106-elf/4.8.2/include-fixed")

add_definitions(-DF_CPU=80000000L)
add_definitions(-D__ets__)
add_definitions(-DICACHE_FLASH)
add_definitions(-DESP8266)
add_definitions(-DARDUINO_ARCH_ESP8266)
add_definitions(-DARDUINO_ESP8266_ESP12)
add_definitions(-DARDUINO=200)
add_definitions(-DPLATFORMIO=020701)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(meat
        src/meat.cpp
        src/meat.h)
