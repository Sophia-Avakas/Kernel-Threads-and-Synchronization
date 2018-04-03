# Kernel Threads and Synchronization
<br>(1) I  implemented a new system call dumpM() for the xv6 OS, which will dump memory of a process on the console. The new system call has the following interface.
<br>int dump(int pid, void *addr, void *buffer, int size); 
<br>Where pid is a process identifier of the process which memory you're dumping, addr is the address inside the process memory from where the memory is dumped, buffer is the user allocated buffer where content of the user memory is saved, and size is the size of the memory region to dump.
<br>to test the system call I created a user-level program dump.c that calls the new system call. 
