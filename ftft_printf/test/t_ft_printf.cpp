extern "C" {
#include"libftprintf.h"
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include<string.h>
}

#include"utest.h"
#include<string>
#include<vector>
#include<climits>
using namespace ft;

namespace {

	std::vector<std::string> get_files_in_dir(const char* dir) {
		std::vector<std::string> files;
		DIR* dp = opendir(dir);
		if (dp != NULL) {
			struct dirent* ep;
			while (ep = readdir(dp)) {
				if (ep->d_type == DT_REG) {
					files.emplace_back(std::string(dir) + std::string(ep->d_name));
				}
			}
			(void)closedir(dp);
		}
		else {
			perror("Couldn't open the directory");
		}
		return files;
	}


	int pwd() {
		char* cwd = getcwd(NULL, 0); // Dynamic allocation, handles any path length
		if (cwd != NULL) {
			printf("Current working directory: %s\n", cwd);
			free(cwd); // Remember to free the allocated memory
			return 0;
		}
		else {
			perror("getcwd() error");
			return 1;
		}
	}


};

#define UT_ENSURE(cond) if (!(cond)) { printf("Error: %s\n", #cond); throw; }
#define UT_CSTR_EQ(a, b) if(!strcmp(a, b) == 0){printf("Error: \n %s = %s\n %s = %s \n",#a, a, #b, b);throw;}

DEFINE_UNIT_TEST(test1, "first test to have a try")
{

	setbuf(stdout, NULL);
	// Test cases for simple conversions
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Pointer: %p\n", NULL);
	ft_printf("Integer: %d\n", 42);
	ft_printf("Unsigned Integer: %u\n", 12345);
	ft_printf("Hexadecimal: %x\n", 255);
	ft_printf("Hexadecimal: %X\n", 255);
	ft_printf("Percentage: %%\n");
	ft_printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 42);
	ft_printf("Welcome to %s! Today's temperature is %d degrees.\n", "City", 25);
	ft_printf("Zero: %d, Smallest Int: %d, Empty String: %s, NULL Pointer: %p\n", 0, INT_MIN, "", NULL);

	printf("Character: %c\n", 'A');
	printf("String: %s\n", "Hello, World!");
	printf("Pointer: %p\n", NULL);
	printf("Integer: %d\n", 42);
	printf("Unsigned Integer: %u\n", 12345);
	printf("Hexadecimal: %x\n", 255);
	printf("Hexadecimal: %X\n", 255);
	printf("Percentage: %%\n");
	printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 42);
	printf("Welcome to %s! Today's temperature is %d degrees.\n", "City", 25);
	printf("Zero: %d, Smallest Int: %d, Empty String: %s, NULL Pointer: %p\n", 0, INT_MIN, "", NULL);


	int original_count, ft_count; // Variables to store the return values of printf and ft_printf

	// Test cases for simple conversions

	// Test 'c' conversion
	original_count = printf("Character: %c\n", 'A');
	ft_count = ft_printf("Character: %c\n", 'A');
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'c' conversion
	original_count = printf("Character: %c\n", 0);
	ft_count = ft_printf("Character: %c\n", 0);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 's' conversion
	original_count = printf("String: %s\n", "Hello, World!");
	ft_count = ft_printf("String: %s\n", "Hello, World!");
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 's' conversion
	original_count = printf("String NULL: %s\n", NULL);
	ft_count = ft_printf("String NULL: %s\n", NULL);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'p' conversion
	original_count = printf("Pointer: %p\n", (void*)(NULL));
	ft_count = ft_printf("Pointer: %p\n", NULL);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'p' conversion
	original_count = printf("Pointer: %p\n", (void*)(1));
	ft_count = ft_printf("Pointer: %p\n", (void*)(1));
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'p' conversion
	original_count = printf("Pointer: %p\n", (void *)(-1));
	ft_count = ft_printf("Pointer: %p\n", (void *)(-1));
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'd' and 'i' conversions
	original_count = printf("Integer: %d\n", 42);
	ft_count = ft_printf("Integer: %d\n", 42);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'u' conversion
	original_count = printf("Unsigned Integer: %u\n", 12345);
	ft_count = ft_printf("Unsigned Integer: %u\n", 12345);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);


	// Test 'u' conversion
	original_count = printf("Unsigned Integer: %u\n", (unsigned long long)(-1) );
	ft_count = ft_printf("Unsigned Integer: %u\n", (unsigned long long)(-1));
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'x' conversion
	original_count = printf("Hexadecimal: %x\n", 255);
	ft_count = ft_printf("Hexadecimal: %x\n", 255);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test 'X' conversion
	original_count = printf("Hexadecimal: %X\n", 255);
	ft_count = ft_printf("Hexadecimal: %X\n", 255);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test '%' conversion
	original_count = printf("Percentage: %%\n");
	ft_count = ft_printf("Percentage: %%\n");
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test multiple conversions
	original_count = printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 42);
	ft_count = ft_printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 42);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test conversions in the middle of a sentence
	original_count = printf("Welcome to %s! Today's temperature is %d degrees.\n", "City", 25);
	ft_count = ft_printf("Welcome to %s! Today's temperature is %d degrees.\n", "City", 25);
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);

	// Test series of identical conversions
	original_count = printf("AAA\n");
	ft_count = ft_printf("AAA\n");
	printf("Return Value: %d (Original) vs %d (ft_printf)\n", original_count, ft_count);


	//test ft_printf for cspdiuxX%
	ft_printf("c s p d i u x X % \n %c %s %p %d %i %u %x %X %% \n", 'c', "String", &test1, -42, -101, -1, 123456789, 123456789, 99);
	printf("c s p d i u x X % \n %c %s %p %d %i %u %x %X %% \n", 'c', "String", &test1, -42, -101, -1, 123456789, 123456789, 99);
	
	//extra tests
	// 
	printf("\n");
	printf("%s everywhere", NULL);
	printf("\n");
	ft_printf("%s everywhere", NULL);
	printf("\n");

	printf("everywhere %s", NULL);
	printf("\n");
	ft_printf("everywhere %s", NULL);
	printf("\n");

	printf("%c - %s - %p %d - %i - %u - %x %X %%", 'b', NULL, ((void*)0), 20, -20, -1, -1, 200000000);
	printf("\n");
	ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'b', NULL, ((void*)0), 20, -20, -1, -1, 200000000);
	printf("\n");

	printf("%c %s - %p - %d - %i %u - %x - %X %%", '\0', NULL, (void*)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("\n");
	ft_printf("%c %s - %p - %d - %i %u - %x - %X %%", '\0', NULL, (void*)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("\n");

};

int main() {
	return ft::UTests::runAll();
}