add_library(${GAMEPLAY_ENGINE_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp
)

target_include_directories(${GAMEPLAY_ENGINE_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GAMEPLAY_ENGINE_NAME} PUBLIC SFML::Graphics)
target_link_libraries(${GAMEPLAY_ENGINE_NAME} PUBLIC SFML::Window)
target_link_libraries(${GAMEPLAY_ENGINE_NAME} PUBLIC SFML::System)
target_link_libraries(${GAMEPLAY_ENGINE_NAME} PUBLIC SFML::Audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND 
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibToTarget(sfml-graphics ${GAMEPLAY_ENGINE_NAME})
CopyLibToTarget(sfml-window ${GAMEPLAY_ENGINE_NAME})
CopyLibToTarget(sfml-system ${GAMEPLAY_ENGINE_NAME})
CopyLibToTarget(sfml-audio ${GAMEPLAY_ENGINE_NAME})