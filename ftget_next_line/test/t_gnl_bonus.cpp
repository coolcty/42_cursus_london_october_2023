extern "C" {
#include"get_next_line_bonus.h"
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

	printf("BUFFER_SIZE = %d \n", BUFFER_SIZE);

	UT_ENSURE(get_next_line(1023) == NULL);
	UT_ENSURE(get_next_line(-1) == NULL);

	pwd();
	std::vector<std::string> files = get_files_in_dir("./files/");
	//std::vector<std::string> files = get_files_in_dir("/home/coolcty/.vs/42_cursus_london_october_2023/087b3f34-49c0-4706-bd93-28fe013aeff7/src/ftget_next_line/test/files/");
	int size = files.size();
	for (int i = 0, j = size - 1;i < size;i++, j--)
	{
		auto& file1 = files[i];
		auto& file2 = files[j];
		printf("File: %s %s\n", file1.c_str(), file2.c_str());
		int fd_gnl1 = open(file1.c_str(), O_RDONLY);
		int fd_ref1 = open(file1.c_str(), O_RDONLY);
		int fd_gnl2 = open(file2.c_str(), O_RDONLY);
		int fd_ref2 = open(file2.c_str(), O_RDONLY);
		UT_ENSURE(fd_gnl1 >= 0);
		UT_ENSURE(fd_ref1 >= 0);
		UT_ENSURE(fd_gnl2 >= 0);
		UT_ENSURE(fd_ref2 >= 0);

		FILE* stream_ref1 = fdopen(fd_ref1, "r"), * stream_ref2 = fdopen(fd_ref2, "r");

		char* line_ref1, * line_ref2, * line_gnl1, * line_gnl2;
		while (1)
		{
			line_ref1 = NULL;
			line_gnl1 = get_next_line(fd_gnl1);
			line_ref2 = NULL;
			line_gnl2 = get_next_line(fd_gnl2);
			size_t len1 = 0, len2 = 0;
			ssize_t read1 = getline(&line_ref1, &len1, stream_ref1);
			ssize_t read2 = getline(&line_ref2, &len2, stream_ref2);




			if (line_gnl1 == NULL && read1 < 0)
			{
				//printf("both reach end of file \n");
				free(line_ref1);
			}
			else {
				UT_ENSURE(!line_ref1 == !line_gnl1);
				UT_CSTR_EQ(line_ref1, line_gnl1);
				free(line_ref1);
				free(line_gnl1);
			}
			if (line_gnl2 == NULL && read2 < 0)
			{
				free(line_ref2);
			}
			else
			{
				UT_ENSURE(!line_ref2 == !line_gnl2);
				UT_CSTR_EQ(line_ref2, line_gnl2);
				free(line_ref2);
				free(line_gnl2);
			}

			if (line_gnl1 == NULL && read1 < 0 && line_gnl2 == NULL && read2 < 0)
			{
				break;
			}


		}

		close(fd_gnl1);
		fclose(stream_ref1);
		close(fd_gnl2);
		fclose(stream_ref2);


	}
	//test with stdin as file descriptor
	int fd_gnl = 0;
	char* line;
	printf("Testing stdin, type some input and enter to see if it get the line correctly. To finish use ctrl+D to give an eof \n");
	while (line = get_next_line(fd_gnl))
	{
		printf("%s\n", line);
		free(line);
	}

};

int main() {
	return ft::UTests::runAll();
}