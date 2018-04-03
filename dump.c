#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

#define PGSIZE 4096

void dump() {
  int pid = fork();
  uint j;
  if (pid == 0) {
    while (1) {
      sleep(5);
    }
  }
  
  void *s = sbrk(0);
  uint size = (uint)s;
  void *buffer = malloc(size);
  void *va = 0;
  dumpM(pid, va, buffer, size );
  for (j = 0; (j + 16) <= size; j = j + 16) {
    printf(1, "0x%x:\t0x%x\t0x%x\t0x%x\t0x%x\n", j, *((uint *)(buffer + j)), *((uint *)(buffer + j + 4)), *((uint *)(buffer + j + 8)), *((uint *)(buffer + j + 12)));
  }

}


int main(int argc, char *argv[]) {
  dump();
  exit();
}

