/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_REGULARGAMELOGIC_H
#define EX3WITHTESTS_REGULARGAMELOGIC_H


#include "Pair.h"
#include "GameLogic.h"
#include "Board.h"
#include "ConsoleDisplay.h"

/**
 * This class features a regular game logic.
 */
class RegularGameLogic : public GameLogic {
public:
    /**
     * The constructor for the game logic.
     * @param size: inputted board size.
     */
    RegularGameLogic(int size, GLType type);

    /**
     * This method clones a game logic (return a new game logic).
     * @return new cloned game logic.
     */
    RegularGameLogic *clone();

    /**
     * This method sets the game board of this game logic.
     * @param b inputted board.
     */
    void setBoard(Board *b);

    /**
     * Function to check if the move is valid.
     * @param p wanted cell.
     * @param scanD scan direction.
     * @param opponentP opponent's player color.
     * @param player: player's color.
     * @return true/false.
     */
    bool validMove(const Pair &p, ScanDirection scanD, Board::Status opponentP, Board::Status player) const;

    /**
     * Function to update all the possible moves.
     * @param pairArr inputted array to update.
     * @param index number of moves.
     * @param playerStat player's color.
     */
    void possibleMoves(Pair pairArr[], int &index, Board::Status playerStat);

    /**
     * Function to check if the cell is a possible move.
     * @param p inputted pair.
     * @param opponentP opponent's player color.
     * @param player: player's color.
     * @return true/false.
     */
    bool checkCell(const Pair &p, Board::Status opponentP, Board::Status player) const;

    /**
     * Function to flip the right cells after the user played it's turn.
     * @param p inputted pair (wanted move).
     * @param opponentP opponent's player color.
     * @param player: player's color.
     */
    void flipCell(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method checks the users input validation (right format & picking a move from the possible moves)
     * @param p wanted users move.
     * @param arr array of possible moves.
     * @param count number of possible moves.
     * @return true/false for good/bad format.
     */
    bool checkInput(Pair &p, Pair arr[], int, Display *display) const;

private:
    /**
     * This method flips the matching cells on the north west side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipNorthWest(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the north side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipNorth(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the north east side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipNorthEast(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the west side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipWest(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the east side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipEast(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the south west side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipSouthWest(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the south side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipSouth(const Pair &p, Board::Status opponentP, Board::Status player);

    /**
     * This method flips the matching cells on the south east side of the pair.
     * @param p inputted pair.
     * @param opponentP opponent player status.
     * @param player: player's status.
     */
    void flipSouthEast(const Pair &p, Board::Status opponentP, Board::Status player);
};

#endif //EX3WITHTESTS_REGULARGAMELOGIC_H