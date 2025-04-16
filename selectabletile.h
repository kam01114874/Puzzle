#ifndef SELECTABLETILE_H
#define SELECTABLETILE_H

#include "animatedtile.h"

/**
 * @class SelectableTile
 * @brief A tile that can be marked as selected (e.g., for editing or highlighting).
 *
 * This class extends AnimatedTile by adding a selection flag. Selected tiles are
 * visually distinguished in console output and can be used in editor or hint modes.
 */
class SelectableTile : public AnimatedTile
{
protected:
    /**
     * @brief Indicates whether the tile is currently selected.
     */
    bool selected = false;
public:
    /**
     * @brief Inherits constructors from AnimatedTile.
     */
    using AnimatedTile::AnimatedTile;

    /**
     * @brief Sets the selection state of the tile.
     * @param select True to mark the tile as selected, false to deselect it.
     */
    void setSelected(bool select);

    /**
     * @brief Checks if the tile is selected.
     * @return True if the tile is currently selected.
     */
    bool isSelected() const;

    /**
     * @brief Changes toggle selection state.
     */
    void toggleSelected();

    /**
     * @brief Renders the tile in the console.
     *
     * Visual representation:
     * - Empty tile: "[  ]"
     * - Selected tile: "[#X]"
     * - Active (movable) tile: ">X<"
     * - Regular tile: " X "
     */
    void drawConsole() const override;
};

#endif // SELECTABLETILE_H
