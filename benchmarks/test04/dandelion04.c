// See LICENSE for license details.

//#include <assert.h>
#include "dandelion01.h"

#include <stdint.h>
#include <stdio.h>

#include "translator.h"

#define N 3

int test04(int a, int b, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a) * b;
    }
    return sum;
}

int main() {
    /*uint64_t data [] = {0xdead, 0xbeef, 0x0bad, 0xf00d}, y;*/
    uint64_t data[] = {5, 3, 5, 3030}, y;

    // Write data
    uint16_t addr = 0;
    for (int i = 0; i < N; i++) {
        printf("[INFO] Write R[%d] = 0x%lx\n", addr + i, data[i]);
        doWrite(y, addr + i, data[i]);
    }

    // Read data
    for (int i = 0; i < N; i++) {
        printf("[INFO] Read R[%d]\n", addr + i);
        doRead(y, addr + i);
        printf("[INFO] Received 0x%lx (expected 0x%lx)\n", y, data[i]);
    }

    uint64_t data_accel = test04(5, 3, 5);
    printf("[INFO] Accel: arg(%d, %d)...\n", data[0], data[1], data[2]);
    doAccum(y, addr, data_accel);
    /*printf("[INFO] Accel R[%d] with 0x%lx\n", addr, data_accum);*/
    /*//assert(y == data[0]);*/

    printf("[INFO] Read R[%d]\n", addr + 3);
    doRead(y, addr + 3);
    printf("[INFO] Received 0x%lx (expected 0x%lx)\n", y, data[3]);
    /*//assert(y == data[1]);*/

    printf("[INFO] Read R[%d] -- Cycle count\n", addr + 4);
    doRead(y, addr + 4);
    printf("[INFO] Received %d\n", y);

    return 0;
}
