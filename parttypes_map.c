#include"parttypes_map.h"

/*  taken from:
    https://searchcode.com/file/62142966/usr/src/cmd/fdisk/fdisk.c/ */
static char *part_map[256] = {
    "Empty", /* 0 */
    "FAT12", /* 1 */
    "XENIX /", /* 2 */
    "XENIX /usr", /* 3 */
    "FAT16 (Upto 32M)", /* 4 */
    "DOS Extended", /* 5 */
    "FAT16 (>32M, HUGEDOS)", /* 6 */
    "IFS: NTFS", /* 7 */
    "AIX Boot/QNX(qny)", /* 8 */
    "AIX Data/QNX(qnz)", /* 9 */
    "OS/2 Boot/Coherent swap", /* 10 */
    "WIN95 FAT32(Upto 2047GB)", /* 11 */
    "WIN95 FAT32(LBA)", /* 12 */
    "Unused", /* 13 */
    "WIN95 FAT16(LBA)", /* 14 */
    "WIN95 Extended(LBA)", /* 15 */
    "OPUS", /* 16 */
    "Hidden FAT12", /* 17 */
    "Diagnostic", /* 18 */
    "Unknown", /* 19 */
    "Hidden FAT16(Upto 32M)", /* 20 */
    "Unknown", /* 21 */
    "Hidden FAT16(>=32M)", /* 22 */
    "Hidden IFS: HPFS", /* 23 */
    "AST SmartSleep Partition", /* 24 */
    "Unused/Willowtech Photon", /* 25 */
    "Unknown", /* 26 */
    "Hidden FAT32", /* 27 */
    "Hidden FAT32(LBA)", /* 28 */
    "Unused", /* 29 */
    "Hidden FAT16(LBA)", /* 30 */
    "Unknown", /* 31 */
    "Unused/OSF1", /* 32 */
    "Reserved/FSo2(Oxygen FS)", /* 33 */
    "Unused/(Oxygen EXT)", /* 34 */
    "Reserved", /* 35 */
    "NEC DOS 3.x", /* 36 */
    "Unknown", /* 37 */
    "Reserved", /* 38 */
    "Unknown", /* 39 */
    "Unknown", /* 40 */
    "Unknown", /* 41 */
    "AtheOS File System", /* 42 */
    "SyllableSecure", /* 43 */
    "Unknown", /* 44 */
    "Unknown", /* 45 */
    "Unknown", /* 46 */
    "Unknown", /* 47 */
    "Unknown", /* 48 */
    "Reserved", /* 49 */
    "NOS", /* 50 */
    "Reserved", /* 51 */
    "Reserved", /* 52 */
    "JFS on OS/2", /* 53 */
    "Reserved", /* 54 */
    "Unknown", /* 55 */
    "THEOS 3.2 2GB", /* 56 */
    "Plan9/THEOS 4", /* 57 */
    "THEOS 4 4GB", /* 58 */
    "THEOS 4 Extended", /* 59 */
    "PartitionMagic Recovery", /* 60 */
    "Hidden NetWare", /* 61 */
    "Unknown", /* 62 */
    "Unknown", /* 63 */
    "Venix 80286", /* 64 */
    "MINIX/PPC PReP Boot", /* 65 */
    "Win2K Dynamic Disk/SFS(DOS)", /* 66 */
    "Linux+DRDOS shared", /* 67 */
    "GoBack partition", /* 68 */
    "Boot-US boot manager", /* 69 */
    "EUMEL/Elan", /* 70 */
    "EUMEL/Elan", /* 71 */
    "EUMEL/Elan", /* 72 */
    "Unknown", /* 73 */
    "ALFS/THIN FS for DOS", /* 74 */
    "Unknown", /* 75 */
    "Oberon partition", /* 76 */
    "QNX 4,x", /* 77 */
    "QNX 4,x 2nd Part", /* 78 */
    "QNX 4,x 3rd Part", /* 79 */
    "OnTrack DM R/O, Lynx RTOS", /* 80 */
    "OnTrack DM R/W, Novell", /* 81 */
    "CP/M", /* 82 */
    "Disk Manager 6.0 Aux3", /* 83 */
    "Disk Manager 6.0 DDO", /* 84 */
    "EZ-Drive", /* 85 */
    "Golden Bow VFeature/AT&T MS-DOS", /* 86 */
    "DrivePro", /* 87 */
    "Unknown", /* 88 */
    "Unknown", /* 89 */
    "Unknown", /* 90 */
    "Unknown", /* 91 */
    "Priam EDisk", /* 92 */
    "Unknown", /* 93 */
    "Unknown", /* 94 */
    "Unknown", /* 95 */
    "Unknown", /* 96 */
    "SpeedStor", /* 97 */
    "Unknown", /* 98 */
    "Unix SysV, Mach, GNU Hurd", /* 99 */
    "PC-ARMOUR, Netware 286", /* 100 */
    "Netware 386", /* 101 */
    "Netware SMS", /* 102 */
    "Novell", /* 103 */
    "Novell", /* 104 */
    "Netware NSS", /* 105 */
    "Unknown", /* 106 */
    "Unknown", /* 107 */
    "Unknown", /* 108 */
    "Unknown", /* 109 */
    "Unknown", /* 110 */
    "Unknown", /* 111 */
    "DiskSecure Multi-Boot", /* 112 */
    "Reserved", /* 113 */
    "Unknown", /* 114 */
    "Reserved", /* 115 */
    "Scramdisk partition", /* 116 */
    "IBM PC/IX", /* 117 */
    "Reserved", /* 118 */
    "M2FS/M2CS,Netware VNDI", /* 119 */
    "XOSL FS", /* 120 */
    "Unknown", /* 121 */
    "Unknown", /* 122 */
    "Unknown", /* 123 */
    "Unknown", /* 124 */
    "Unknown", /* 125 */
    "Unused", /* 126 */
    "Unused", /* 127 */
    "MINIX until 1.4a", /* 128 */
    "MINIX since 1.4b, early Linux", /* 129 */
    "Solaris/Linux swap", /* 130 */
    "Linux native", /* 131 */
    "OS/2 hidden,Win Hibernation", /* 132 */
    "Linux extended", /* 133 */
    "Old Linux RAID,NT FAT16 RAID", /* 134 */
    "NTFS volume set", /* 135 */
    "Linux plaintext part table", /* 136 */
    "Unknown", /* 137 */
    "Linux Kernel Partition", /* 138 */
    "Fault Tolerant FAT32 volume", /* 139 */
    "Fault Tolerant FAT32 volume", /* 140 */
    "Free FDISK hidden PDOS FAT12", /* 141 */
    "Linux LVM partition", /* 142 */
    "Unknown", /* 143 */
    "Free FDISK hidden PDOS FAT16", /* 144 */
    "Free FDISK hidden DOS EXT", /* 145 */
    "Free FDISK hidden FAT16 Large", /* 146 */
    "Hidden Linux native, Amoeba", /* 147 */
    "Amoeba Bad Block Table", /* 148 */
    "MIT EXOPC Native", /* 149 */
    "Unknown", /* 150 */
    "Free FDISK hidden PDOS FAT32", /* 151 */
    "Free FDISK hidden FAT32 LBA", /* 152 */
    "DCE376 logical drive", /* 153 */
    "Free FDISK hidden FAT16 LBA", /* 154 */
    "Free FDISK hidden DOS EXT", /* 155 */
    "Unknown", /* 156 */
    "Unknown", /* 157 */
    "Unknown", /* 158 */
    "BSD/OS", /* 159 */
    "Laptop hibernation", /* 160 */
    "Laptop hibernate,HP SpeedStor", /* 161 */
    "Unknown", /* 162 */
    "HP SpeedStor", /* 163 */
    "HP SpeedStor", /* 164 */
    "BSD/386,386BSD,NetBSD,FreeBSD", /* 165 */
    "OpenBSD,HP SpeedStor", /* 166 */
    "NeXTStep", /* 167 */
    "Mac OS-X", /* 168 */
    "NetBSD", /* 169 */
    "Olivetti FAT12 1.44MB Service", /* 170 */
    "Mac OS-X Boot", /* 171 */
    "Unknown", /* 172 */
    "Unknown", /* 173 */
    "ShagOS filesystem", /* 174 */
    "ShagOS swap", /* 175 */
    "BootStar Dummy", /* 176 */
    "HP SpeedStor", /* 177 */
    "Unknown", /* 178 */
    "HP SpeedStor", /* 179 */
    "HP SpeedStor", /* 180 */
    "Unknown", /* 181 */
    "Corrupted FAT16 NT Mirror Set", /* 182 */
    "Corrupted NTFS NT Mirror Set", /* 183 */
    "Old BSDI BSD/386 swap", /* 184 */
    "Unknown", /* 185 */
    "Unknown", /* 186 */
    "Boot Wizard hidden", /* 187 */
    "Unknown", /* 188 */
    "Unknown", /* 189 */
    "Solaris x86 boot", /* 190 */
    "Solaris2", /* 191 */
    "REAL/32 or Novell DOS secured", /* 192 */
    "DRDOS/secured(FAT12)", /* 193 */
    "Hidden Linux", /* 194 */
    "Hidden Linux swap", /* 195 */
    "DRDOS/secured(FAT16,< 32M)", /* 196 */
    "DRDOS/secured(Extended)", /* 197 */
    "NT corrupted FAT16 volume", /* 198 */
    "NT corrupted NTFS volume", /* 199 */
    "DRDOS8.0+", /* 200 */
    "DRDOS8.0+", /* 201 */
    "DRDOS8.0+", /* 202 */
    "DRDOS7.04+ secured FAT32(CHS)", /* 203 */
    "DRDOS7.04+ secured FAT32(LBA)", /* 204 */
    "CTOS Memdump", /* 205 */
    "DRDOS7.04+ FAT16X(LBA)", /* 206 */
    "DRDOS7.04+ secure EXT DOS(LBA)", /* 207 */
    "REAL/32 secure big, MDOS", /* 208 */
    "Old MDOS secure FAT12", /* 209 */
    "Unknown", /* 210 */
    "Unknown", /* 211 */
    "Old MDOS secure FAT16 <32M", /* 212 */
    "Old MDOS secure EXT", /* 213 */
    "Old MDOS secure FAT16 >=32M", /* 214 */
    "Unknown", /* 215 */
    "CP/M-86", /* 216 */
    "Unknown", /* 217 */
    "Non-FS Data", /* 218 */
    "CP/M,Concurrent DOS,CTOS", /* 219 */
    "Unknown", /* 220 */
    "Hidden CTOS memdump", /* 221 */
    "Dell PowerEdge utilities(FAT)", /* 222 */
    "DG/UX virtual disk manager", /* 223 */
    "ST AVFS(STMicroelectronics)", /* 224 */
    "SpeedStor 12-bit FAT EXT", /* 225 */ 
    "Unknown", /* 226 */
    "SpeedStor", /* 227 */
    "SpeedStor 16-bit FAT EXT", /* 228 */
    "Tandy MSDOS", /* 229 */
    "Storage Dimensions SpeedStor", /* 230 */
    "Unknown", /* 231 */
    "Unknown", /* 232 */
    "Unknown", /* 233 */
    "Unknown", /* 234 */
    "BeOS BFS", /* 235 */
    "SkyOS SkyFS", /* 236 */
    "Unused", /* 237 */
    "EFI Header Indicator", /* 238 */
    "EFI Filesystem", /* 239 */
    "Linux/PA-RISC boot loader", /* 240 */
    "SpeedStor", /* 241 */
    "DOS 3.3+ secondary", /* 242 */
    "SpeedStor Reserved", /* 243 */
    "SpeedStor Large", /* 244 */
    "Prologue multi-volume", /* 245 */
    "SpeedStor", /* 246 */
    "Unused", /* 247 */
    "Unknown", /* 248 */
    "pCache", /* 249 */
    "Bochs", /* 250 */
    "VMware File System", /* 251 */
    "VMware swap", /* 252 */
    "Linux raid autodetect", /* 253 */
    "NT Disk Administrator hidden", /* 254 */
    "Xenix Bad Block Table" /* 255 */
};

char* find_parttype_by_hex(uint8_t hex) {
    if (part_map[hex] != NULL)
        return part_map[hex];
    return "Unknown";
}