extern "C" {
#include"get_next_line.h"
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include<string.h>
}

#include"utest.h"
#include<string>
#include<vector>
using namespace ft;

namespace {

	std::vector<std::string> get_files_in_dir(const char* dir) {
		std::vector<std::string> files;
		DIR* dp = opendir(dir);
		if (dp != NULL) {
			struct dirent* ep;
			while (ep = readdir(dp)) {
				if (ep->d_type == DT_REG) {
					files.emplace_back(std::string(dir)+ std::string(ep->d_name));
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

	printf("BUFFER_SIZE = %d \n", BUFFER_SIZE);

	UT_ENSURE(get_next_line(1023)==NULL);
	UT_ENSURE(get_next_line(-1) == NULL);

	pwd();
	std::vector<std::string> files = get_files_in_dir("./files/");
	//std::vector<std::string> files = get_files_in_dir("/home/coolcty/.vs/42_cursus_london_october_2023/087b3f34-49c0-4706-bd93-28fe013aeff7/src/ftget_next_line/test/files/");
	for (auto& file : files)
	{
		printf("File: %s\n", file.c_str());
		int fd_gnl = open(file.c_str(), O_RDONLY);
		int fd_ref = open(file.c_str(), O_RDONLY);
		UT_ENSURE(fd_gnl >= 0);
		UT_ENSURE(fd_ref >= 0);

		FILE* stream_ref = fdopen(fd_ref, "r");

		char* line_ref, * line_gnl;
		while (1)
		{
			line_ref = NULL;
			line_gnl = get_next_line(fd_gnl);
			size_t len = 0;
			ssize_t read = getline(&line_ref, &len, stream_ref);
			
			if (line_gnl == NULL && read< 0)
			{
				//printf("both reach end of file \n");
				free(line_ref);
				break;
			}
			UT_ENSURE(!line_ref == !line_gnl);
			UT_CSTR_EQ(line_ref, line_gnl);

			free(line_ref);
			free(line_gnl);
		}

		close(fd_gnl);
		fclose(stream_ref);



	}
	//test with stdin as file descriptor
	int fd_gnl = 0;
	char* line;
	printf("Testing stdin, type some input and enter to see if it get the line correctly. To finish use ctrl+D to give an eof \n");
	while(line = get_next_line(fd_gnl))
		{
			printf("%s\n", line);
			free(line);
		}

};

int main() {
	return ft::UTests::runAll();
}