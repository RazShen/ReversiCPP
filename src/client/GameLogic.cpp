/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "GameLogic.h"

GameLogic::GameLogic(int size, GLType type) {
    this->boardSize = size;
    this->board = new Board(this->boardSize);
    this->type = type;
}

GameLogic::GameWinner GameLogic::whoWon() const {
    int blackCells = 0;
    int whiteCells = 0;
    for (int i = 0; i < this->boardSize; i++) {
        for (int j = 0; j < this->boardSize; j++) {
            if (this->board->getCellStatus(Pair(i, j)) == Board::White) {
                whiteCells++;
            } else if (this->board->getCellStatus(Pair(i, j)) == Board::Black) {
                blackCells++;
            }
        }
    }
    if (blackCells > whiteCells) {
        return BlackWon;
    } else if (whiteCells > blackCells) {
        return WhiteWon;
    } else {
        return Draw;
    }
}

bool GameLogic::checkAndAnnounceFinish(bool &noMoreActionsB, bool &noMoreActionsW, Display *display) const {
    if (this->board->isBoardFull()) {
        display->currentBoard();
        display->printBoard(board);
        display->fullBoard();
        if (this->whoWon() == GameLogic::Draw) {
            display->declareDraw();
        } else if (this->whoWon() == GameLogic::BlackWon) {
            display->declareBlackWin();
        } else {
            display->declareWhiteWIn();
        }
        return true;
    }
    if (noMoreActionsB && noMoreActionsW) {
        display->noMoreMovesForAll();
        if (this->whoWon() == GameLogic::Draw) {
            display->declareDraw();
        } else if (this->whoWon() == GameLogic::BlackWon) {
            display->declareBlackWin();
        } else {
            display->declareWhiteWIn();
        }
        return true;
    }
    return false;
}

int GameLogic::getBoardSize() const {
    return this->boardSize;
}

GameLogic::~GameLogic() {
    delete (this->board);
}

Board *GameLogic::getBoard() const {
    return this->board;
}

GameLogic::GLType GameLogic::getType() const {
    return this->type;
}

int GameLogic::getBlackScore() {
    int blackCells = 0;
    int whiteCells = 0;
    for (int i = 0; i < this->boardSize; i++) {
        for (int j = 0; j < this->boardSize; j++) {
            if (this->board->getCellStatus(Pair(i, j)) == Board::White) {
                whiteCells++;
            } else if (this->board->getCellStatus(Pair(i, j)) == Board::Black) {
                blackCells++;
            }
        }
    }
    return (blackCells - whiteCells);
}