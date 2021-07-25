#include"wrappers.h"
#include"mbr.h"
#include"parttypes_map.h"

#define STYLE_BOLD  "\033[1m"
#define STYLE_NO_BOLD  "\033[22m"

void hexdump_MBR(uint8_t buffer[MBR_SIZE]) {
    for (int i = 0; i < MBR_SIZE/ROW; i++) {
        printf("%08x  ", i*ROW);
        char printable[17]; 
        printable[16] = '\0';
        for (int j = 0; j < ROW; j++) {
            printf("%02x ", buffer[i*ROW + j]);
            if (buffer[i*ROW + j] <= 125 && buffer[i*ROW + j] >= 32)
                printable[j] = buffer[i*ROW + j];
            else
                printable[j] = '.'; 
        }
        printf(" |%s|\n", printable);
    }
}

void print_part(uint8_t buffer[MBR_SIZE], int num) {
    if (num < 0 || num > 3) { /* we have 4 partitions: part0 ... part3 */
        fprintf(stderr, "ERROR: wrong partition number\n");
        exit(1);
    }

    /* index (in 'buffer' array) of the first byte of partition no. `num` */
    const int part_entry_addr = 510 - (4 - num) * sizeof(struct part_entry);
    struct part_entry* curr_entry = (struct part_entry*)(buffer + part_entry_addr);
   
    printf(STYLE_BOLD);
    printf("Partition no. %d:\n", num);
    printf(STYLE_NO_BOLD);

    printf("boot flag is 0x%02x - ", (int)curr_entry->part_status);
    if (curr_entry->part_status == 0x80)
        printf("active (bootable) partition\n");
    else if (curr_entry->part_status == 0x0)
        printf("inactive (non-bootable) partition\n");
    else
        printf("invalid boot flag\n");

    printf("partition type is 0x%02x - %s\n", curr_entry->part_type, find_parttype_by_hex(curr_entry->part_type));
}