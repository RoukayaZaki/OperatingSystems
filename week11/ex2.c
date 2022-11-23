#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	DIR* root = opendir("/");
	struct dirent* entry;
	while ((entry = readdir(root)) != NULL) {
		printf("-> %s\n", entry->d_name);
	}
}