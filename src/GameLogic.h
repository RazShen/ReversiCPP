/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_GAMELOGIC_H
#define EX3WITHTESTS_GAMELOGIC_H


#include "Board.h"
#include "ConsoleDisplay.h"

class GameLogic {
public:

    /**
     * This enum is for the game logic type.
     */
    enum GLType {
        Regular, Advanced
    };

    /**
     * Enum for the board scanning directions.
     */
    enum ScanDirection {
        NorthWest, North, NorthEast, West, East, SouthWest, South, SouthEast
    };

    /**
     * Enum for game winning.
     */
    enum GameWinner {
        Draw, BlackWon, WhiteWon
    };

    /**
     * This constructor creates a basic game logic abstract class.
     * @param size inputted board size.
     */
    GameLogic(int size, GLType type);

    /**
     * This method clones the game logic.
     * @return
     */
    virtual GameLogic *clone() = 0;


    /**
     * This method returns who won the game, or draw by scanning the board cells.
     * @return who won the game, or draw
     */
    GameWinner whoWon() const;

    /**
     * This method returns the size of the board.
     * @return
     */
    int getBoardSize() const;

    /**
     * This method checks if the game should end.
     * @param noMoreActionsB boolean for the black player possible move (have moves or don't have moves).
     * @param noMoreActionsW boolean for the while player possible move (have moves or don't have moves).
     * @return
     */
    bool checkAndAnnounceFinish(bool &noMoreActionsB, bool &noMoreActionsW, Display *display) const;

    /**
     * Pure virtual function to check if the move is valid.
     * @param p wanted cell.
     * @param scanD scan direction.
     * @param opponentP opponent's player color.
     * @param player: player's color.
     * @return true/false.
     */
    virtual bool validMove(const Pair &p, ScanDirection scanD, Board::Status opponentP, Board::Status player) const = 0;

    /**
     * Pure virtual function to update all the possible moves.
     * @param pairArr inputted array to update.
     * @param index number of moves.
     * @param playerStat player's color.
     */
    virtual void possibleMoves(Pair pairArr[], int &index, Board::Status playerStat) = 0;

    /**
     * Pure virtual function to check if the cell is a possible move.
     * @param p inputted pair.
     * @param opponentP opponent's player color.
     * @param player: player's color.
     * @return true/false.
     */
    virtual bool checkCell(const Pair &p, Board::Status opponentP, Board::Status player) const = 0;

    /**
     * Pure virtual function to flip the right cells after the user played it's turn.
     * @param p inputted pair (wanted move).
     * @param opponentP opponent's player color.
     * @param player: player's color.
     */
    virtual void flipCell(const Pair &p, Board::Status opponentP, Board::Status player) = 0;

    /**
     * Virtual method to checks the users input validation (right format & picking a move from the possible moves)
     * @param p wanted users move.
     * @param arr array of possible moves.
     * @param count number of possible moves.
     * @return true/false for good/bad format.
     */
    virtual bool checkInput(Pair &p, Pair arr[], int count, Display *display) const = 0;

    /**
     * This method returns the current board (used for cloning).
     * @return
     */
    Board *getBoard() const;

    /**
     * This method returns the type of the game logic.
     * @return
     */
    GLType getType() const;

    /**
     * Destructor of the game.
     */
    ~GameLogic();

    /**
     * This method returns the current score of the black player.
     * @return current score of the black player.
     */
    int getBlackScore();

protected:
    // Game logic members.
    Board *board;
    int boardSize;
    GLType type;
};


#endif //EX3WITHTESTS_GAMELOGIC_H