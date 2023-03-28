#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program illustrates inter-process communication using a shared memory
// buffer. This example uses `mmap` over `shmget`, as its newer.

// This function is taken from `http://git.suckless.org/dwm/file/util.c.html`.
//
// Print the error message and `perror` if the message ends in `':'`. Assumes
// `fmt` is not `NULL`.
void die(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);

  // Following Unix convention (see `man perror`), first check if the string is
  // not empty.
  if(fmt[0] && fmt[strlen(fmt) - 1] == ':') {
    fputc(' ', stderr);
    perror(NULL);
  } else {
    fputc('\n', stderr);
  }

  exit(0);
}

int main(int argc, char** argv) {
  int protection = PROT_READ | PROT_WRITE;

  // Mapping is shared between multiple processes but is anonymous (i.e. it
  // does not create any file representing it), meaning only this process and
  // its children will be able to access it.
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  // The arguments for `mmap` are: address, size, protection, flags, file
  // descriptor, and offset. The file descriptor is irrelevant because of the
  // `MAP_ANONYMOUS` flag.
  char* buffer = mmap(NULL, 4096, protection, visibility, -1, 0);

  if(buffer == MAP_FAILED) die("could not map memory:");

  // `fork` current process. On success, the child's PID is returned to the
  // parent and `0` is returned to the child. On failure, `-1` is returned and
  // no process is created.
  pid_t pid = fork();

  if(pid == -1) die("could not fork:");

  // At this point both processes have a pointer to `buffer` (virtual memory
  // address) and can access the same memory region (phisical memory address)
  // because of the `MAP_SHARED` flag.
  if(pid == 0) {
    fgets(buffer, 4096, stdin);
  } else {
    // Suspend the execution of the parent until one of its children
    // terminates.
    wait(NULL);

    printf("%s\n", buffer);
  }

  return 0;
}
