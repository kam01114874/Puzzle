/**
 * @file ShuffleAlgorithm.h
 * @brief Template definition of ShuffleAlgorithm used to shuffle tile grids in puzzle games.
 */
#ifndef SHUFFLEALGORITHM_H
#define SHUFFLEALGORITHM_H

#include <vector>
#include <random>
#include <algorithm>
#include "board.h"

/**
 * @class ShuffleAlgorithm
 * @brief Template class for shuffling a puzzle board represented as a 2D grid of elements of type T.
 *
 * The class performs randomized but legal moves of an empty tile,
 * ensuring that the final board state is always solvable.
 *
 * @tparam T The type of elements stored in the puzzle grid (e.g., shared_ptr<Tile>).
 */
template<typename T>
class ShuffleAlgorithm {
public:
    /**
    * @brief Shuffles the board by performing legal random moves of the empty tile.
    *
    * @param grid 2D vector representing the board.
    * @param moves Number of shuffle moves to perform.
    * @param emptyR Row index of the empty tile at the start; updated to final row after shuffling.
    * @param emptyC Column index of the empty tile at the start; updated to final column after shuffling.
    */
    void shuffle(std::vector<std::vector<T>>& grid, int moves, int& emptyR, int& emptyC);

private:
    /**
     * @brief Returns the opposite direction to the one provided.
     *
     * Used to avoid immediately undoing the previous move during shuffle.
     *
     * @param dir Last move direction.
     * @return Direction Opposite to the input.
     */
    Direction getOpposite(Direction dir);
};

template<typename T>
Direction ShuffleAlgorithm<T>::getOpposite(Direction dir) {
    switch (dir) {
    case Direction::Up:    return Direction::Down;
    case Direction::Down:  return Direction::Up;
    case Direction::Left:  return Direction::Right;
    case Direction::Right: return Direction::Left;
    }
    return dir;
}

template<typename T>
void ShuffleAlgorithm<T>::shuffle(std::vector<std::vector<T>>& grid, int moves, int& emptyR, int& emptyC) {
    // Size of the puzzle board.
    int size = grid.size();
    // Variable to store the last move made.
    Direction lastMove;
    // Flag indicating that the first move has not yet been made.
    bool firstMove = true;

    // Pseudorandom number generator to draw directions.
    std::random_device rd;
    std::mt19937 gen(rd());

    // Vector of all possible directions to move an empty field.
    std::vector<Direction> directions = {
        Direction::Up, Direction::Down, Direction::Left, Direction::Right
    };

    // Performs 'moves' number of shuffle attempts.
    for (int i = 0; i < moves; ++i) {
        // Randomizes the directions in which moves will be attempted.
        std::vector<Direction> shuffled = directions;
        std::shuffle(shuffled.begin(), shuffled.end(), gen);

        // Flag indicating whether move was successfully made in this iteration.
        bool moved = false;

        for (Direction dir : shuffled) {
            // If this is not the first move and the given direction is the opposite of the previous one it - skip this direction
            if (!firstMove && dir == getOpposite(lastMove))
                continue;

            // Change the direction to coordinates
            int dr = 0, dc = 0;
            switch (dir) {
            case Direction::Up:    dr = -1; break;
            case Direction::Down:  dr =  1; break;
            case Direction::Left:  dc = -1; break;
            case Direction::Right: dc =  1; break;
            }

            // New coordinates of the empty field after making the move.
            int newR = emptyR + dr;
            int newC = emptyC + dc;

            // Check if the new position does not go beyond the board.
            // If move was legal: Swap the empty field with the selected tile, update its new position, save the last direction and ark that the first move has been made.
            if (newR >= 0 && newR < size && newC >= 0 && newC < size) {
                std::swap(grid[emptyR][emptyC], grid[newR][newC]);
                emptyR = newR;
                emptyC = newC;
                lastMove = dir;
                firstMove = false;
                moved = true;
                break;
            }
        }

        // If there were no legal moves allow the previous move to be reversed, since no other move was successful.
        if (!moved) {
            for (Direction dir : directions) {
                int dr = 0, dc = 0;
                switch (dir) {
                case Direction::Up:    dr = -1; break;
                case Direction::Down:  dr =  1; break;
                case Direction::Left:  dc = -1; break;
                case Direction::Right: dc =  1; break;
                }

                int newR = emptyR + dr;
                int newC = emptyC + dc;

                if (newR >= 0 && newR < size && newC >= 0 && newC < size) {
                    std::swap(grid[emptyR][emptyC], grid[newR][newC]);
                    emptyR = newR;
                    emptyC = newC;
                    lastMove = dir;
                    firstMove = false;
                    break;
                }
            }
        }
    }
}
#endif // SHUFFLEALGORITHM_H

