# select说明

**select** 函数使我们可以执行I/O多路转接，传向select的参数告诉内核

- 我们所关心的描述符
- 对于每个描述符我们所关心的状态。（是否读一个给定的描述符？是否想写一个给定的描述符？是否关心一个描述符的异常状态？）
- 愿意等待多长时间（可以永远等待，等待一个固定量时间，或完全不等待）

从select返回时，内核告诉我们

- 已经准备好的描述符数量
- 对于读，写或异常这三个状态中的每一个，哪些描述符已经准备。

```
SYNOPSIS
     #include <sys/select.h>

     void
     FD_CLR(fd, fd_set *fdset);

     void
     FD_COPY(fd_set *fdset_orig, fd_set *fdset_copy);

     int
     FD_ISSET(fd, fd_set *fdset);

     void
     FD_SET(fd, fd_set *fdset);

     void
     FD_ZERO(fd_set *fdset);

     int
:...skipping...
SELECT(2)                                                              System Calls Manual                                                             SELECT(2)

NAME
     FD_CLR, FD_COPY, FD_ISSET, FD_SET, FD_ZERO, select – synchronous I/O multiplexing

SYNOPSIS
     #include <sys/select.h>

     void
     FD_CLR(fd, fd_set *fdset);

     void
     FD_COPY(fd_set *fdset_orig, fd_set *fdset_copy);

     int
     FD_ISSET(fd, fd_set *fdset);

     void
     FD_SET(fd, fd_set *fdset);

     void
     FD_ZERO(fd_set *fdset);

     int
     select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);

DESCRIPTION
     select() examines the I/O descriptor sets whose addresses are passed in readfds, writefds, and errorfds to see if some of their descriptors are ready for
     reading, are ready for writing, or have an exceptional condition pending, respectively.  The first nfds descriptors are checked in each set; i.e., the
     descriptors from 0 through nfds-1 in the descriptor sets are examined.  (Example: If you have set two file descriptors "4" and "17", nfds should  not be
     "2", but rather "17 + 1" or "18".)  On return, select() replaces the given descriptor sets with subsets consisting of those descriptors that are ready for
     the requested operation.  select() returns the total number of ready descriptors in all the sets.

     The descriptor sets are stored as bit fields in arrays of integers.  The following macros are provided for manipulating such descriptor sets:
     FD_ZERO(&fdset) initializes a descriptor set fdset to the null set.  FD_SET(fd, &fdset) includes a particular descriptor fd in fdset.  FD_CLR(fd, &fdset)
     removes fd from fdset.  FD_ISSET(fd, &fdset) is non-zero if fd is a member of fdset, zero otherwise.  FD_COPY(&fdset_orig, &fdset_copy) replaces an already
     allocated &fdset_copy file descriptor set with a copy of &fdset_orig.  The behavior of these macros is undefined if a descriptor value is less than zero or
     greater than or equal to FD_SETSIZE, which is normally at least equal to the maximum number of descriptors supported by the system.

     If timeout is not a null pointer, it specifies a maximum interval to wait for the selection to complete.

     If timeout is a null pointer, the select blocks indefinitely.

     To effect a poll, the timeout argument should be not be a null pointer, but it should point to a zero-valued timeval structure.

     timeout is not changed by select(), and may be reused on subsequent calls, however it is good style to re-initialize it before each invocation of select().

     Any of readfds, writefds, and errorfds may be given as null pointers if no descriptors are of interest.

RETURN VALUES
     select() returns the number of ready descriptors that are contained in the descriptor sets, or -1 if an error occurred.  If the time limit expires,
     select() returns 0.  If select() returns with an error, including one due to an interrupted call, the descriptor sets will be unmodified and the global
     variable errno will be set to indicate the error.

ERRORS
     An error return from select() indicates:

     [EAGAIN]           The kernel was (perhaps temporarily) unable to allocate the requested number of file descriptors.

     [EBADF]            One of the descriptor sets specified an invalid descriptor.

     [EINTR]            A signal was delivered before the time limit expired and before any of the selected events occurred.

     [EINVAL]           The specified time limit is invalid.  One of its components is negative or too large.

     [EINVAL]           ndfs is greater than FD_SETSIZE and _DARWIN_UNLIMITED_SELECT is not defined.

LEGACY SYNOPSIS
     #include <sys/select.h>
           - or -
     #include <sys/types.h>
     #include <sys/time.h>
     #include <unistd.h>

     FD_SET(fd, &fdset);

     FD_CLR(fd, &fdset);

     FD_ISSET(fd, &fdset);

     FD_COPY(&fdset_orig, &fdset_copy);

     FD_ZERO(&fdset);

COMPATIBILITY
     select() now returns with errno set to EINVAL when nfds is greater than FD_SETSIZE.  Use a smaller value for nfds or compile with
     -D_DARWIN_UNLIMITED_SELECT.

SEE ALSO
     accept(2), connect(2), connectx(2), getdtablesize(2), gettimeofday(2), read(2), recv(2), send(2), write(2), compat(5)
```