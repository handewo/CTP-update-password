PROJECT(ctp_trade)
aux_source_directory(. SRC_LIST)

add_executable(ctp_update_passwd ${SRC_LIST})

target_link_libraries(ctp_update_passwd ${PROJECT_SOURCE_DIR}/lib/thosttraderapi_se.so -pthread)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
