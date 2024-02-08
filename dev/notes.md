Allowed functions:
# CLASSIC
- open, close, read, write, malloc, free, exit
# ERRORS
- `void perror(const char *s);`
  Print a description of the last error with the syntax `<s>: <error>\n`
- `char *strerror(int errnum);`
  Get the description of the specified error.
- `int access(const char *pathname, int mode);`
  Return 0 if the calling process can access the file pathname
  with the specified mode(s) `R_OK / W_OK / X_OK` or `F_OK`,
  or -1 and an error with errno.
# PROCESS
- `int execve(const char *pathname, char *const argv[], char *const envp[]);`
  Execute the file pathname with the arguments argv (array ended by NULL)
  and the environment variables envp (same). 
- `pid_t wait(int *wstatus);`
  Wait state change for any child process.
  Return: PID of the terminated process on success, -1 on error with errno.
- `pid_t waitpid(pid_t pid, int *wstatus, int options);`
  pid > 0: wait state change for the specified child process.
  Return: PID of the terminated process on success, -1 on error with errno.
# FORK
- `pid_t fork(void);`
  Duplicate current process (wtf is that for)
# PIPE
- `int pipe(int pipefd[2]);`
  Create a link between two fds. The function set pipefd to be the two ends of the pipe:
  we write on pipefd[1] and we read on pipefd[0].
  Return value: 0 (success) or -1 (failure / errno set appropriately).
- `int dup(int oldfd);`
  Copy the fd.
- `int dup2(int oldfd, int newfd);`
  Copy the fd at the specified new fd. If newfd is already used,
  it "silently" closes it?
# OTHER
- `int unlink(const char *pathname);`
  Remove a file (tf is that for).
  Return 0 if success, -1 with errno if error.
