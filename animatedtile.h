#ifndef ANIMATEDTILE_H
#define ANIMATEDTILE_H

#include "tile.h"

/**
 * @class AnimatedTile
 * @brief A tile that can be marked as active (adjacent to the empty tile).
 *
 * This class extends the base Tile class by adding a visual indication
 * of whether the tile can be moved into the empty space.
 * Active tiles are visually highlighted in console output.
 */
class AnimatedTile : public Tile
{
protected:
    /**
     * @brief Indicates whether the tile is adjacent to the empty tile.
     */
    bool active = false;

public:
    /**
     * @brief Inherits constructors from base Tile class.
     */
    using Tile::Tile;

    /**
     * @brief Sets whether this tile is active.
     * @param isActive True if the tile should be marked as active (movable), false otherwise.
     */
    void setActive(bool isActive);

    /**
     * @brief Checks whether the tile is active.
     * @return True if the tile is active.
     */
    bool isActive() const;

    /**
     * @brief Renders the tile in console.
     *
     * Shows empty tiles as "[  ]", active tiles as ">X<", and normal tiles as " X ".
     */
    void drawConsole() const override;
};

#endif // ANIMATEDTILE_H
