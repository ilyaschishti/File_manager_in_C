#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a file
void createFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        printf("File already exists!\n");
        fclose(file);
    }
    else
    {
        file = fopen(filename, "w");
        if (file != NULL)
        {
            printf("File created successfully: %s\n", filename);
            fclose(file);
        }
        else
        {
            printf("Unable to create file!\n");
        }
    }
}

// Function to delete a file
void deleteFile(const char *filename)
{
    if (remove(filename) == 0)
    {
        printf("File deleted successfully: %s\n", filename);
    }
    else
    {
        printf("Unable to delete file or file does not exist!\n");
    }
}

// Function to duplicate a file
void duplicateFile(const char *srcFilename, const char *destFilename)
{
    FILE *srcFile = fopen(srcFilename, "rb");
    FILE *destFile = fopen(destFilename, "wb");

    if (srcFile != NULL && destFile != NULL)
    {
        char buffer[1024];
        size_t bytesRead;

        while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0)
        {
            fwrite(buffer, 1, bytesRead, destFile);
        }

        printf("File duplicated successfully: %s to %s\n", srcFilename, destFilename);

        fclose(srcFile);
        fclose(destFile);
    }
    else
    {
        printf("Unable to duplicate file!\n");
    }
}

// Function to move a file
void moveFile(const char *srcFilename, const char *destFilename)
{
    if (rename(srcFilename, destFilename) == 0)
    {
        printf("File moved successfully: %s to %s\n", srcFilename, destFilename);
    }
    else
    {
        printf("Unable to move file or file does not exist!\n");
    }
}

// Function to list files in a directory
void listFiles(const char *directory)
{
    char command[100];
    sprintf(command, "ls -al %s", directory);
    system(command);
}

// Function to search for a file by name and extension
void searchFile(const char *directory, const char *filename)
{
    char command[100];
    sprintf(command, "find %s -name '%s'", directory, filename);
    system(command);
}

int main()
{
    char filename[50], destFilename[50], directory[50], searchFilename[50];

    printf("Enter file name to be created: ");
    scanf("%s", filename);
    createFile(filename);

    printf("Enter file name to be deleted: ");
    scanf("%s", filename);
    deleteFile(filename);

    printf("Enter source file name to be duplicated: ");
    scanf("%s", filename);
    printf("Enter destination file name for duplication: ");
    scanf("%s", destFilename);
    duplicateFile(filename, destFilename);

    printf("Enter source file name to be moved: ");
    scanf("%s", filename);
    printf("Enter destination file name for move: ");
    scanf("%s", destFilename);
    moveFile(filename, destFilename);

    printf("Enter directory to list files: ");
    scanf("%s", directory);
    listFiles(directory);

    printf("Enter directory to search for file: ");
    scanf("%s", directory);
    printf("Enter file name to search: ");
    scanf("%s", searchFilename);
    searchFile(directory, searchFilename);

    return 0;
}
