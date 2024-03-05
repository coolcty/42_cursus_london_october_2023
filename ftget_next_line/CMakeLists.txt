project(ftget_next_line)

#BUFFER_SIZE_LIST 2048 6 1 42 41 43

set(_SIZE 42)

ft_add_binary(
NAME ${PROJECT_NAME}
TYPE SHARED 
INSTALL
SOURCES src/get_next_line.c src/get_next_line_utils.c
PUBLIC_DEFINITIONS 
BUFFER_SIZE=${_SIZE}
#LIBRARIES
#  ftLibft  
)

ft_add_binary(
NAME "${PROJECT_NAME}_bonus"
TYPE SHARED 
INSTALL
SOURCES src/get_next_line_bonus.c src/get_next_line_utils_bonus.c 
PUBLIC_DEFINITIONS 
BUFFER_SIZE=${_SIZE}
#LIBRARIES
#  ftLibft  
)

add_test(
	NAME Norminette
	COMMAND "norminette;-R;CheckForbiddenSourceHeader"
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
	COMMAND_EXPAND_LISTS )


file(GLOB C_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
foreach(FILE IN ITEMS ${C_FILES})
add_test(
	NAME ${PROJECT_NAME}${FILE}_Compile
	COMMAND "gcc;-Wall;-Wextra;-Werror;-D;BUFFER_SIZE=42;-c;${FILE};-o;${CMAKE_BINARY_DIR}/${PROJECT_NAME}_Compile"
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
	COMMAND_EXPAND_LISTS )
endforeach()
