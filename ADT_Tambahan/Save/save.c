#include <stdio.h>
#include <sys/stat.h>

int isDirectoryExists(const char *path)
{
    struct stat info;

    if (stat(path, &info) != 0)
    {

        return 0;
    }

    return S_ISDIR(info.st_mode);
}

int main()
{
    FILE *filesave;
    const char *directoryPath = "tes";

    if (isDirectoryExists(directoryPath))
    {
        printf("Directory exists.\n");
        filesave = fopen("tes/pengguna.config", "w");
        fprintf(filesave, "Hmm?");

        // Close the file after writing
        fclose(filesave);
    }
    else
    {
        printf("Directory does not exist.\n");
        filesave = fopen("tes/pengguna.config", "w");
        fprintf(filesave, "Hello");

        // Close the file after writing
        fclose(filesave);
    }

    return 0;
}