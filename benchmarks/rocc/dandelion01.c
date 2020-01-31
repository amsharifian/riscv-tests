// See LICENSE for license details.

//#include <assert.h>
#include "dandelion01.h"

#include <stdint.h>
#include <stdio.h>

#include "translator.h"

#define N 1

int main() {
    /*uint64_t data [] = {0xdead, 0xbeef, 0x0bad, 0xf00d}, y;*/
    uint64_t data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, y;

    // Write data
    uint16_t addr = 0;
    for (int i = 0; i < N; i++) {
        printf("[INFO] Write R[%d] = 0x%lx\n", addr, data);
        doWrite(y, addr, data);
    }

    // Read data
    for (int i = 0; i < N; i++) {
        printf("[INFO] Read R[%d]\n", addr);
        doRead(y, addr);
        printf("[INFO] Received 0x%lx (expected 0x%lx)\n", y, data);
    }

    uint64_t data_accel = 0;
    printf("[INFO] Accel: ...\n");
    doAccum(y, addr, data_accel);
    /*printf("[INFO] Accel R[%d] with 0x%lx\n", addr, data_accum);*/
    /*//assert(y == data[0]);*/

    printf("[INFO] Read R[%d]\n", addr + 1);
    doRead(y, addr + 1);
    printf("[INFO] Received 0x%lx (expected 0x%lx)\n", y, data[9]);
    /*//assert(y == data[1]);*/

    for(int i = 0; i < 10; i++){
        printf("a[%d]: %d\n", i, data[i]);
    }

    /*printf("[INFO] Read R[%d] -- Cycle count\n", addr + 4);*/
    /*doRead(y, addr + 4);*/
    /*printf("[INFO] Received %d\n", y);*/
    /*uint64_t data_addr;*/
    /*doTranslate(data_addr, &data[2]);*/
    /*printf("[INFO] Load 0x%lx (virt: 0x%p, phys: 0x%p) via L1 virtual
     * address\n",*/
    /*data[2], &data[2], (void *) data_addr);*/
    /*doLoad(y, addr, &data[2]);*/
    /*//assert(y == data[1]);*/

    /*printf("[INFO] Read R[%d]\n", addr);*/
    /*doRead(y, addr);*/
    /*printf("[INFO]   Received 0x%lx (expected 0x%lx)\n", y, data[2]);*/
    // assert(y == data[2]);

    return 0;
}
