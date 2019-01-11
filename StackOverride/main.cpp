/**
 *   @file: main.cpp
 *
 *   @date: Jan 11, 2019
 * @author: Mateusz Midor
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// this func is nowhere explicitly called yet gets called due to stack override
void hack() {
    cout << "hack happened! exiting" << endl;
    exit(3);
}

// this func doesnt check input buffer len against the internal buffer len and thus does stack override
void unsafe_buff_use(char* src, size_t len) {
    char buff[32];
    memcpy(buff, src, len); // buff too small, stack gets overriden
    cout << "copy done. returning..." << endl;
    // return address from this func has been overriden and replaced with hack() func address
}

// fill the buffer with 8-byte aligned address of our "hack()" function
void fill_buff_with_unsafe_data(char* src, size_t len) {
    const uint64_t HACK_FUNC_ADDR = (uint64_t)hack;
    const size_t POINTER_SIZE_IN_BYTES = sizeof(char*);
    const size_t NUM_REPEATS = len/POINTER_SIZE_IN_BYTES;
    uint64_t int_addr = (uint64_t)src;
    uint64_t int_aligned_addr = int_addr /  POINTER_SIZE_IN_BYTES * POINTER_SIZE_IN_BYTES;
    uint64_t* aligned_addr = (uint64_t*)int_aligned_addr;
    std::fill(aligned_addr, aligned_addr + NUM_REPEATS, HACK_FUNC_ADDR);
}

// Must be compiled with -fno-stack-protector or will not work due to stack canary that protects against stack override attack
int main() {
    const size_t UNSAFE_BUFF_SIZE = 64;
    char unsafe_buff[UNSAFE_BUFF_SIZE];
    fill_buff_with_unsafe_data(unsafe_buff, UNSAFE_BUFF_SIZE);
    unsafe_buff_use(unsafe_buff, UNSAFE_BUFF_SIZE);
    cout << "no hack happened" << endl;
}
