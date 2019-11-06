#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 4096

/**
* This is a Custom implementation of tee which is question 4.1 in the
* Linux programming interface book.
*
* @return int status code
*
* @version 6/13/2018
* @author Michael Trottier
*/
int tee(int appendFileFlag, char *fileName) {
    /*
     * ssize_t is used for functions whose return value could either be a valid size or a negative value to
     * indicate an error, it is guaranteed to have the reange [-1, SSIZE_MAX], SSIZE_MAX system dependent
     */
    ssize_t bytesRead, writeStatus;

    int inputFd, writeFd;
    char buffer[BUF_SIZE];
    memset(buffer, 0, sizeof(buffer));

    /*
     * O_WRONLY open for writing only
     * O_CREAT create file if it doesn't already exist
     * O_APPEND writes are always append to the end of the file
     * O_TRUNC truncate existing file to zero length
     */
    writeFd = open(fileName, O_WRONLY | O_CREAT | (appendFileFlag ? O_APPEND: O_TRUNC));

    /*
     * Will return negative one if open system call fails
     * errno man page: http://man7.org/linux/man-pages/man3/errno.3.html
     */
    int errnoSaved = errno;
    if (0 > writeFd) {
        fprintf(stderr,
                "Errno Error Code: %d, see man page: http://man7.org/linux/man-pages/man3/errno.3.html\n",
                errnoSaved);
        fprintf(stderr, "Couldn't open file: %s\n", fileName);
        return -1;
    }

    /*
     * The read system call reads data from the open file referred to by the file descriptor fd
     * returns number of bytes read, 0 on EOF or -1 on error
     *
     * Read from stdin, fd 0
     * Stdout fd 1
     * Stderr fd 2
     */
    inputFd = 0;
    while ((bytesRead = read(inputFd, buffer, BUF_SIZE)) > 0) {
        /*
         * Only pass the number of bytes read to the write call so you are not writing junk, also, thils is safe because
         * the body of the while loop will on enter if the bytesRead is greater than zero
         */
        writeStatus = write(writeFd, buffer, (size_t) bytesRead);

        errnoSaved = errno;
        if (-1 == writeStatus) {
            fprintf(stderr,
                    "Errno Error Code: %d, see man page: http://man7.org/linux/man-pages/man3/errno.3.html\n",
                    errnoSaved);
            fprintf(stderr, "Couldn't write to file: %s\n", fileName);
            return -1;
        }

        // Print the output to both stdout and the file described by command line option
        fprintf(stdout, "%s", buffer);

        // Returns a void pointer to the buffer no need to check system call
        memset(buffer, 0, sizeof(buffer));
    }

    errnoSaved = errno;
    if (-1 == bytesRead) {
        fprintf(stderr,
                "Errno Error Code: %d, see man page: http://man7.org/linux/man-pages/man3/errno.3.html\n",
                errnoSaved);
        fprintf(stderr, "Issue in reading bytes from pipe. %s\n", fileName);
        return -1;
    }

    return close(writeFd);
}

/**
* Main method into the tee executable.
*
* @param argc integer representing the number or arguments passed to the executable
* @param argv the array of arguments passed to the executable
* @return
*/
int main(int argc, char *argv[]) {
    // Don't run anything if the filename isn't passed in via command line argument
    if (argc <= 1) {
        fprintf(stderr, "usage: %s [-a] [file...]\n", argv[0]);
        return 1;
    }

    int appendFileFlag = 0;
    int executableOptions = -1;

    // Store a reference pointer in memory to store the filename
    char *fileName = NULL;

    /*
     * Regarding the third argument of getopt, a single : marks the option as requiring an argument, a double ::
     * makes the argument optional, this is a GNU extension, if there is no argument optarg is null
     */
    while ((executableOptions = getopt(argc, argv, "a:")) != -1) {
        switch(executableOptions) {
            case 'a':
                appendFileFlag = 1;
                fileName = optarg;
                break;
            default:
                fprintf(stderr, "usage: %s [-a] [file...]\n", argv[0]);
                return 1;
        }
    }


    /*
     * Pass the argv[1] parameter as the filename or send the actual filename through getopt
     * Declared 0 == to avoid common error with = in which it sets variable
     */
    if (0 == appendFileFlag) {
        return tee(appendFileFlag, argv[1]);
    }

    return tee(appendFileFlag, fileName);
}
