#ifndef INODEMAP_H
#define INODEMAP_H

#include <sys/types.h>

/* Add ino to map ino as key and v as associated value */
void add_Inode( ino_t ino, void * v );

/* Search map for ino, if found return associated value */
void * find_Inode( ino_t ino );

#endif
