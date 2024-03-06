project(ftft_printf)


ft_add_binary(
NAME ${PROJECT_NAME}
TYPE SHARED 
INSTALL
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
	COMMAND "gcc;-Wall;-Wextra;-Werror;-c;${FILE};-o;${CMAKE_BINARY_DIR}/${PROJECT_NAME}_Compile"
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
	COMMAND_EXPAND_LISTS )
endforeach()