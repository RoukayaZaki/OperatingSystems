#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 50
#define MAX_FILES 10

typedef struct file
{
	unsigned long inode, nlink;
	char filename[MAX_NAME];
} file;

int main()
{
	DIR *dir = opendir("./tmp");
	if(dir == NULL)
	{
		printf("Error opening directory\n");
		return 1;
	}
	struct dirent *entry;
	file files[MAX_FILES];

	int file_count = 0;

	for(int i = 0; i < MAX_FILES; i++)
	{
		files[i].inode = 0;
        files[i].nlink = 0;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_name[0] == '.') continue;
		
		struct stat s = {};
		char dirname[4+MAX_NAME] = "tmp/";
		if(stat(strcat(dirname, entry->d_name), &s) != 0)
		{
			printf("Error reading file stat\n");
			break;
		}
        strcpy(files[file_count].filename, entry->d_name);
        files[file_count].inode = s.st_ino;
        files[file_count].nlink = s.st_nlink;
        file_count++;

	}
	closedir(dir);
    printf("File ------- Hard Links\n");
    for(int i = 0; i < file_count; i++)
    {
        if(files[i].inode == 0 || files[i].nlink < 2) continue;
        printf("%s ------- ", files[i].filename);
        bool firstlink = true;
        for (int j = 0; j < file_count; j++)
        {
            if(files[i].inode == files[j].inode)
            {
                if(!firstlink) printf(", ");
                printf("%s", files[j].filename);
                firstlink = false;
            }
        }
        printf("\n");
    }
	
	return 0;
}