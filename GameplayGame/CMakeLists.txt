add_executable(${GAMEPLAY_GAME_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

target_include_directories(${GAMEPLAY_GAME_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GAMEPLAY_GAME_NAME} PUBLIC ${GAMEPLAY_ENGINE_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND 
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirToTarget(${GAMEPLAY_ENGINE_NAME} ${GAMEPLAY_GAME_NAME})

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
    TARGET ${GAMEPLAY_GAME_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCE_SRC_DIR}
    $<TARGET_FILE_DIR:${GAMEPLAY_GAME_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
    "config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES    
)