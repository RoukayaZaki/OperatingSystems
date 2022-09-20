#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIR 8
#define MAX_SIZE_FILES 256
#define MAX_SIZE_NAME 63
#define MAX_SIZE_DATA 1024
#define MAX_SIZE_PATH 2048

struct Directory;
struct File;

struct File
{
    int id;
    char name[MAX_SIZE_NAME];
    int size;
    char data[MAX_SIZE_DATA];
    char path[MAX_SIZE_PATH];
    struct Directory *parent; // The parent directory
};

struct Directory
{
    struct File *files[MAX_SIZE_FILES];
    struct Directory *directories[MAX_NUM_DIR];
    int nf;
    int nd;
    char path[MAX_SIZE_PATH];
};

typedef struct Directory Directory;
typedef struct File File;

// Operations on files
void add_to_file(File *file, const char *content);
void append_to_file(File *file, const char *content);
void pwd_file(File *file);

// Operations on directories
void add_file(File *file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you


// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

void createDirectory(struct Directory* directory, const char* dirName, const char* dirPath) {
    struct Directory dir;
    strcpy(dir.path, dirPath);
    dir.nd = 0;
    dir.nf = 0;
    *directory = dir;
}

void create_file(struct File* file, const char* fileName) {
    struct File newFile;
    strcpy(newFile.name, fileName);
    *file = newFile;
}

int main(void)
{

    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";

    Directory home, bin, root;

    createDirectory(&root, "root", "/");
    createDirectory(&home, "home", "/home");
    createDirectory(&bin, "bin", "/bin");
    // add_dir(&home, &root);
    // add_dir(&bin, &root);

    // Example: the path of the folder home is /home

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash, ex3_1, ex3_2;
    create_file(&bash, "bash");
    add_file(&bash, &bin);

    create_file(&ex3_1, "ex3_1.c");
    add_to_file(&ex3_1, "int printf(const char * format, ...);");
    add_file(&ex3_1, &home);

    create_file(&ex3_2, "ex3_2.c");
    add_to_file(&ex3_2, "//This is a comment in C language");
    add_file(&ex3_2, &home);

    add_to_file(&bash, "Bourne Again Shell!!");

    append_to_file(&ex3_1, "int main(){printf('Hello World!')}");

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex3_1);
    show_file_detailed(&ex3_2);

    pwd_file(&bash);
    pwd_file(&ex3_1);
    pwd_file(&ex3_2);

    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir)
{
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++)
    {
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");

    for (int i = 0; i < dir->nd; i++)
    {
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file)
{
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file)
{
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %u\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}

// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char *content)
{
    strcpy(file->data, content);
    file->size = strlen(content);
}

// Appends the content to the File file
void append_to_file(File *file, const char *content)
{
    strcat(file->data, content);
}

// Prints the path of the File file
void pwd_file(File *file)
{
    printf("%s/%s\n", file->parent->path, file->name);
}

// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File *file, Directory *dir)
{
    file->id = dir->nf + 1;
    dir->files[dir->nf++] = file;
    file->parent = dir;
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2)
{
    if (dir1 && dir2)
    {
        dir2->directories[dir2->nd] = dir1;
        dir2->nd++;
    }
}