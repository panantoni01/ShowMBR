#include"parttypes_map.h"

static char* part_map[256];

void init_part_map() {
    memset(part_map, 0, 256*sizeof(char*));
    {
        part_map[0x00] = "Empty";
        part_map[0x01] = "FAT12";
        part_map[0x02] = "XENIX root";
        part_map[0x03] = "XENIX usr";
        part_map[0x04] = "FAT16 <32M";
        part_map[0x05] = "Extended";
        part_map[0x06] = "FAT16";
        part_map[0x07] = "HPFS/NTFS/exFAT";
        part_map[0x08] = "AIX";
        part_map[0x09] = "AIX bootable";
        part_map[0x0a] = "OS/2 Boot Manag";
        part_map[0x0b] = "W95 FAT32";
        part_map[0x0c] = "W95 FAT32 (LBA)";
        part_map[0x0e] = "W95 FAT16 (LBA)";
        part_map[0x0f] = "W95 Ext'd (LBA)";
        part_map[0x10] = "OPUS";
        part_map[0x11] = "Hidden FAT12";
        part_map[0x12] = "Compaq diagnost";
        part_map[0x14] = "Hidden FAT16 <3";
        part_map[0x16] = "Hidden FAT16";
        part_map[0x17] = "Hidden HPFS/NTF";
        part_map[0x18] = "AST SmartSleep";
        part_map[0x1b] = "Hidden W95 FAT3";
        part_map[0x1c] = "Hidden W95 FAT3";
        part_map[0x1e] = "Hidden W95 FAT1";
        part_map[0x24] = "NEC DOS";
        part_map[0x27] = "Hidden NTFS Win";
        part_map[0x39] = "Plan 9";
        part_map[0x3c] = "PartitionMagic";
        part_map[0x40] = "Venix 80286";
        part_map[0x41] = "PPC PReP Boot";
        part_map[0x42] = "SFS";
        part_map[0x4d] = "QNX4.x";
        part_map[0x4e] = "QNX4.x 2nd part";
        part_map[0x4f] = "QNX4.x 3rd part";
        part_map[0x50] = "OnTrack DM";
        part_map[0x51] = "OnTrack DM6 Aux";
        part_map[0x52] = "CP/M";
        part_map[0x53] = "OnTrack DM6 Aux";
        part_map[0x54] = "OnTrackDM6";
        part_map[0x55] = "EZ-Drive";
        part_map[0x56] = "Golden Bow";
        part_map[0x5c] = "Priam Edisk";
        part_map[0x61] = "SpeedStor";
        part_map[0x63] = "GNU HURD or Sys";
        part_map[0x64] = "Novell Netware";
        part_map[0x65] = "Novell Netware";
        part_map[0x70] = "DiskSecure Mult";
        part_map[0x75] = "PC/IX";
        part_map[0x80] = "Old Minix";
        part_map[0x81] = "Minix / old Lin";
        part_map[0x82] = "Linux swap / So";
        part_map[0x83] = "Linux";
        part_map[0x84] = "OS/2 hidden or";
        part_map[0x85] = "Linux extended";
        part_map[0x86] = "NTFS volume set";
        part_map[0x87] = "NTFS volume set";
        part_map[0x88] = "Linux plaintext";
        part_map[0x8e] = "Linux LVM";
        part_map[0x93] = "Amoeba";
        part_map[0x94] = "Amoeba BBT";
        part_map[0x9f] = "BSD/OS";
        part_map[0xa0] = "IBM Thinkpad hi";
        part_map[0xa5] = "FreeBSD";
        part_map[0xa6] = "OpenBSD";
        part_map[0xa7] = "NeXTSTEP";
        part_map[0xa8] = "Darwin UFS";
        part_map[0xa9] = "NetBSD";
        part_map[0xab] = "Darwin boot";
        part_map[0xaf] = "HFS / HFS+";
        part_map[0xb7] = "BSDI fs";
        part_map[0xb8] = "BSDI swap";
        part_map[0xbb] = "Boot Wizard hid";
        part_map[0xbc] = "Acronis FAT32 L";
        part_map[0xbe] = "Solaris boot";
        part_map[0xbf] = "Solaris";
        part_map[0xc1] = "DRDOS/sec (FAT-";
        part_map[0xc4] = "DRDOS/sec (FAT-";
        part_map[0xc6] = "DRDOS/sec (FAT-";
        part_map[0xc7] = "Syrinx";
        part_map[0xda] = "Non-FS data";
        part_map[0xdb] = "CP/M / CTOS / .";
        part_map[0xde] = "Dell Utility";
        part_map[0xdf] = "BootIt";
        part_map[0xe1] = "DOS access";
        part_map[0xe3] = "DOS R/O";
        part_map[0xe4] = "SpeedStor";
        part_map[0xea] = "Linux extended ";
        part_map[0xeb] = "BeOS fs";
        part_map[0xee] = "GPT";
        part_map[0xef] = "EFI (FAT-12/16/";
        part_map[0xf0] = "Linux/PA-RISC b";
        part_map[0xf1] = "SpeedStor";
        part_map[0xf2] = "DOS secondary";
        part_map[0xf4] = "SpeedStor";
        part_map[0xfb] = "VMware VMFS";
        part_map[0xfc] = "VMware VMKCORE ";
        part_map[0xfd] = "Linux raid auto";
        part_map[0xfe] = "LANstep";
        part_map[0xff] = "BBT";
    }
}

char* find_parttype_by_hex(uint8_t hex) {
    if (part_map[hex] != NULL)
        return part_map[hex];
    return "Unknown";
}