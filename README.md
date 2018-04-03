# Kernel Threads and Synchronization
<br>(1) Memory Dump
<br>
<br>I  implemented a new system call dumpM() for the xv6 OS, which will dump memory of a process on the console. The new system call has the following interface.
<br>
<br>int dump(int pid, void *addr, void *buffer, int size); 
<br>
<br>Where pid is a process identifier of the process which memory you're dumping, addr is the address inside the process memory from where the memory is dumped, buffer is the user allocated buffer where content of the user memory is saved, and size is the size of the memory region to dump.
<br>
<br>To test the system call I created a user-level program dump.c that calls the new system call. 
<br>
<br>(2) Kernel Threads Implementation
<br>
<br>I implemented three new system calls: first one to create a kernel thread, thread_create(), second to wait for the thread to finish thread_join(), and then a third one that allows the thread to exit thread_exit().
<br>
<br>int thread_create(void(*fcn)(void*), void *arg, void*stack)
<br>In my implementation I copy file descriptors in the same manner fork() does it. The new process uses stack as its user stack, which is passed the given argument arg and uses a fake return PC (0xffffffff). The stack should be one page in size. The new thread starts executing at the address specified by fcn . As with fork(), the PID of the new thread is returned to the parent.
<br>
<br>The other new system call is int thread_join(void) . This call waits for a child thread that shares the address space with the calling process. It returns the PID of waited-for child or -1 if none.
<br>
<br>Finally, the int thread_exit(void) system call allows a thread to terminate.
<br>
<br>(3)Synchronization
<br>
<br>For spinlocks, I defined a simple lock data structure and implemented three functions that: 1) initialize the lock to the correct initial state (void thread_spin_init(struct thread_spinlock *lk)), 2) a funtion to acquire a lock (void thread_spin_lock(struct thread_spinlock *lk)), and 3) a function to release it void thread_spin_unlock(struct thread_spinlock *lk).
<br>
<br>For Mutexes, I defined a simple mutex data structure and implemented three functions that: 1) initialize the mutex to the correct initial state (void thread_mutex_init(struct thread_mutex *m)), 2) a funtion to acquire a mutex (void thread_mutex_lock(struct thread_mutex *m)), and 3) a function to release it void thread_mutex_unlock(struct thread_mutex *m).
