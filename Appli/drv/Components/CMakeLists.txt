add_library(components
    # flash
    aps256xx/aps256xx.c
    mx66uw1g45g/mx66uw1g45g.c
)

target_include_directories(components PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/aps256xx
    ${CMAKE_CURRENT_SOURCE_DIR}/mx66uw1g45g 
)