#ifndef PARTTYPES_H
#define PARTTYPES_H

#include<stdio.h>
#include<string.h>
#include<stdint.h>

void init_part_map(); 
char* find_parttype_by_hex(uint8_t hex);

#endif /* PARTTYPES_H */