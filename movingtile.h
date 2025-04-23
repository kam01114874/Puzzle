#ifndef MOVINGTILE_H
#define MOVINGTILE_H

#include "animatedtile.h"

/**
 * @class MovingTile
 * @brief A tile that can track the most recently moved tile.
 *
 * This class extends AnimatedTile by adding a flag to indicate recent movement,
 * allowing visual highlighting or animation after a tile move.
 */
class MovingTile : public AnimatedTile
{
protected:
    /**
     * @brief Flag indicating whether the tile was the most recently moved tile.
     */
    bool wasMoved = false;

public:
    /**
     * @brief Inherits constructors from AnimatedTile.
     */
    using AnimatedTile::AnimatedTile;

    /**
     * @brief Marks the tile as having been moved.
     * @param moved True if the tile was just moved; false otherwise.
     */
    void setMoved(bool moved);

    /**
     * @brief Checks whether the tile was the last one moved.
     * @return True if the tile was just moved.
     */
    bool wasRecentlyMoved() const;

    /**
     * @brief Renders the tile in the console.
     *
     * Visual representation:
     * - Empty tile: "[  ]"
     * - Recently moved tile: "[*X]"
     * - Active tile (but not moved): ">X<"
     * - Regular tile: " X "
     */
    void drawConsole() const override;

    void drawGraphics(QPainter* painter, const QRect& rect) const override;
};

#endif // MOVINGTILE_H
