#include "inodemap.h"
#include <stdio.h>
#include <stdlib.h>

struct map{
    ino_t key;
    void * val;
};

struct map *Map=NULL;
unsigned int MapSize=0;

void add_Inode( ino_t ino, void * v ){
    MapSize++;

    Map = realloc(Map, sizeof(struct map) * MapSize );

    Map[MapSize-1].key = ino;
    Map[MapSize-1].val = v;
}

void * find_Inode( ino_t ino ){

    for ( int i=0; i<MapSize; i++ ) {
        if ( Map[i].key == ino ) {
            return Map[i].val;
        }
    }

    return NULL;
}
