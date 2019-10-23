#include <unistd.h>
#include <stdio.h>
#include <dirent.h>     //To access a directory, use the opendir() function. It’s prototyped in the dirent.h header file
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void searchDir(char *dir, int depth) {      //The function requires a string argument, a name or path to a directory. 
    DIR *dp;                                // The function requires a DIR pointer
    struct dirent *entry;                   //
    struct stat stat;
    if ((dp = opendir(dir)) == NULL) {      //The DIR pointer variable folder acts as the directory handle for the opendir() function 
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);                                         // change the current directory
    while ((entry = readdir(dp)) != NULL) {  
        lstat(entry->d_name, &stat);                 //lstat() function gets status information about a specified file 
        if (S_ISDIR(stat.st_mode)) {                    // We check file type with st_mode field (S_ISDIR - directory?)
            if (strcmp(".", entry->d_name) == 0 ||          // On success, zero is returned. On error, -1 is returned
                strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);   // entry->d_name prints its name
            searchDir(entry->d_name, depth + 4);            //Searches for the dir by entry name and shifts by 4 (pointer size) to the next
        } else {
            if (stat.st_nlink >= 2) {                           //checks whether hard link count is two or more
                printf("%*s%s\n", depth, "", entry->d_name);        //print all file names that point to the file
            }
        }
    }
    chdir("..");
    closedir(dp);       //close the directory
}

int main() {
    printf("Directory scan ./:\n");
    searchDir("/shokhista-insp/operating-systems/week10/", 0);
    exit(0);
}
