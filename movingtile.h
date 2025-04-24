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

    /**
    * @brief Draws the tile on a graphical interface using QPainter.
    *
    * This method renders the tile as a rectangle filled with either a solid background
    * or an image fragment. It also draws decorative frames if the tile is active or recently moved,
    * and overlays the tile number if it's not an empty tile.
    *
    * @param painter Pointer to the QPainter used for drawing on the widget.
    * @param rect Rectangle area in which the tile should be drawn.
    * @param tileImage Cropped fragment of the full puzzle image corresponding to this tile.
    */
    void drawGraphics(QPainter* painter, const QRect& rect, const QPixmap& tileImage) const override;
};

#endif // MOVINGTILE_H
