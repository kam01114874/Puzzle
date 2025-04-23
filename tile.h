/**
 * @file Tile.h
 * @brief Declaration of the abstract base class Tile.
 */

#ifndef TILE_H
#define TILE_H

#include <QPainter>

/**
 * @class Tile
 * @brief Abstract base class representing a single tile.
 *
 * This class serves as a base for different types of tiles in a tile-based game.
 * It stores the tile's numeric value and a flag indicating whether the tile is empty.
 * Provides getter methods and enforces implementation of a draw method in derived classes.
 */
class Tile
{
protected:
    /**
     * @brief Numeric identifier of the tile.
     */
    int number;

    /**
     * @brief Flag indicating whether this tile is the empty tile.
     */
    bool isEmptyTile;

public:
    /**
     * @brief Constructor that initializes the tile with a given identifier and sets its empty state.
     * @param num Value of the tile.
     * @param empty Optional. Whether the tile is an empty tile (default: false).
     */
    Tile(int num, bool empty = false);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Tile() = default;

    /**
    * @brief Returns the numeric identifier of the tile.
    * @return Integer representing the tile's value.
    */
    int getNumber() const;

    /**
     * @brief Checks whether this is the empty tile.
     * Helps distinguish movable tiles from the placeholder empty space.
     * @return True if the tile is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
    * @brief Draws the tile to the console.
    *
    * This is a pure virtual function and must be implemented by derived tile types.
    */
    virtual void drawConsole() const = 0;

    /**
    * @brief Draws the tile to the interface.
    *
    * This is a pure virtual function and must be implemented by derived tile types.
    */
    virtual void drawGraphics(QPainter* painter, const QRect& rect) const = 0;
};

#endif // TILE_H
