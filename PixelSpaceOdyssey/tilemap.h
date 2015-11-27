//
//  tilemap.h
//  PixelSpaceOdessey
//
//  Created by Alex Lementuev on 11/26/15.
//  Copyright © 2015 Space Madness. All rights reserved.
//

#ifndef tilemap_h
#define tilemap_h

#include "common.h"

#define TILE_WIDTH  2048 /* S2W(8) */
#define TILE_HEIGHT 2048 /* S2W(8) */
#define TILE_WIDTH_HALF  1024 /* S2W(4) */
#define TILE_HEIGHT_HALF 1024 /* S2W(4) */

#define TILE_WIDTH_PX  8
#define TILE_HEIGHT_PX 8

#define TILE_GET_LEFT(TILE)   ((TILE).x - TILE_WIDTH_HALF)
#define TILE_GET_RIGHT(TILE)  ((TILE).x + TILE_WIDTH_HALF)
#define TILE_GET_TOP(TILE)    ((TILE).y - TILE_HEIGHT_HALF)
#define TILE_GET_BOTTOM(TILE) ((TILE).y + TILE_HEIGHT_HALF)

typedef struct _Tile {
    int16_t x;
    int16_t y;
    uint8_t index;
} Tile;

typedef struct _TileMap {
    const PgmPtr* tiles;
    const uint8_t* indices;
    uint8_t width;
    uint8_t heigth;
} TileMap;

inline TileMap TileMapMake(const PgmPtr* tiles, const uint8_t* indices, uint8_t width, uint8_t height)
{
    TileMap tileMap;
    tileMap.tiles = tiles;
    tileMap.indices = indices;
    tileMap.width   = width;
    tileMap.heigth  = height;
    return tileMap;
}

void TileMapDraw(const TileMap* tileMap, int16_t x, int16_t y);
bool TileMapGetTile(const TileMap* tileMap, int16_t x, int16_t y, Tile* tile);

#endif /* tilemap_h */
