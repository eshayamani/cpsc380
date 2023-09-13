#include "checksum.h"

//function to calculate the checksum
uint16_t checksum(uint8_t *address, u_int32_t count) {
    uint32_t total_sum = 0;
    uint16_t *buffer = (uint16_t *) address;

    while (count > 1) {
        total_sum += (*(buffer)++);
        count -= 2;
    }
    //adding any left over bits
    if (count > 0) {
        total_sum += (*address);
    }
    //converting to a 16 bit
    while (total_sum >> 16) {
        total_sum = (total_sum & 0xFFFF) + (total_sum >> 16);
    }

    return(~total_sum);

}

//struct args{
  //  int num_items;
    //int shmid;
    //void* ptr;
//};

//defining buffer
struct HUH{
    u_int8_t data[50];
    u_int16_t curr_checksum;
}HUH;

struct HUH *shm_ptr;

