/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include "RegularGameLogic.h"

using namespace std;

RegularGameLogic::RegularGameLogic(int size, GLType type) : GameLogic(size, type) {

}

RegularGameLogic *RegularGameLogic::clone() {
    RegularGameLogic *newGL = new RegularGameLogic(this->getBoardSize(), this->getType());
    // deleting the current board and creating a new one
    delete (newGL->board);
    newGL->setBoard(this->getBoard());
    return newGL;
}

void RegularGameLogic::possibleMoves(Pair pairArr[], int &index, Board::Status playerStat) {
    for (int i = 0; i < this->boardSize; i++) {
        for (int j = 0; j < this->boardSize; j++) {
            if (this->board->getCellStatus(Pair(i, j)) == Board::Empty) {
                if (playerStat == Board::Black) {
                    if (checkCell(Pair(i, j), Board::White, Board::Black)) {
                        pairArr[index] = Pair(i, j);
                        index++;
                    }
                } else {
                    if (checkCell(Pair(i, j), Board::Black, Board::White)) {
                        pairArr[index] = Pair(i, j);
                        index++;
                    }
                }
            }
        }
    }
}

bool RegularGameLogic::checkInput(Pair &p, Pair arr[], int count, Display *display) const {
    for (int i = 0; i < count; i++) {
        if (p.getRow() - 1 == arr[i].getRow() && p.getCol() - 1 == arr[i].getCol()) {
            return true;
        }
    }
    display->newLine();
    display->noValidMove();
    return false;
}

bool RegularGameLogic::checkCell(const Pair &p, Board::Status opponentP, Board::Status player) const {
    if (p.getRow() > 0 && p.getCol() > 0 &&
        this->board->getCellStatus(Pair(p.getRow() - 1, p.getCol() - 1)) == opponentP) {
        //scan north-west
        if (validMove(Pair(p.getRow() - 1, p.getCol() - 1), NorthWest, opponentP, player)) {
            return true;
        }
    }
    if (p.getRow() > 0 && this->board->getCellStatus(Pair(p.getRow() - 1, p.getCol())) == opponentP) {
        //scan north
        if (validMove(Pair(p.getRow() - 1, p.getCol()), North, opponentP, player)) {
            return true;
        }
    }
    if (p.getRow() > 0 && p.getCol() < this->boardSize - 1 &&
        this->board->getCellStatus(Pair(p.getRow() - 1, p.getCol() + 1)) == opponentP) {
        //scan north-east
        if (validMove(Pair(p.getRow() - 1, p.getCol() + 1), NorthEast, opponentP, player)) {
            return true;
        }
    }
    if (p.getCol() > 0 && this->board->getCellStatus(Pair(p.getRow(), p.getCol() - 1)) == opponentP) {
        //scan west
        if (validMove(Pair(p.getRow(), p.getCol() - 1), West, opponentP, player)) {
            return true;
        }
    }
    if (p.getCol() < this->boardSize - 1 && this->board->getCellStatus(Pair(p.getRow(), p.getCol() + 1)) == opponentP) {
        //scan east
        if (validMove(Pair(p.getRow(), p.getCol() + 1), East, opponentP, player)) {
            return true;
        }
    }
    if (p.getRow() < this->boardSize - 1 && p.getCol() > 0 &&
        this->board->getCellStatus(Pair(p.getRow() + 1, p.getCol() - 1)) == opponentP) {
        //scan south-west
        if (validMove(Pair(p.getRow() + 1, p.getCol() - 1), SouthWest, opponentP, player)) {
            return true;
        }
    }
    if (p.getRow() < this->boardSize - 1 && this->board->getCellStatus(Pair(p.getRow() + 1, p.getCol())) == opponentP) {
        //scan south
        if (validMove(Pair(p.getRow() + 1, p.getCol()), South, opponentP, player)) {
            return true;
        }
    }
    if (p.getRow() < this->boardSize - 1 && p.getCol() < this->boardSize - 1 &&
        this->board->getCellStatus(Pair(p.getRow() + 1, p.getCol() + 1)) == opponentP) {
        //scan south-east
        if (validMove(Pair(p.getRow() + 1, p.getCol() + 1), SouthEast, opponentP, player)) {
            return true;
        }
    }
    return false;
}

bool RegularGameLogic::validMove(const Pair &p, RegularGameLogic::ScanDirection scanD, Board::Status opponentP,
                                 Board::Status player) const {
    int x = p.getRow();
    int y = p.getCol();
    switch (scanD) {
        case NorthWest:
            for (; x >= 0 && y >= 0; x--, y--) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case North:
            for (; x >= 0 && y >= 0; x--) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case NorthEast:
            for (; x >= 0 && y < this->boardSize; x--, y++) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case West:
            for (; x >= 0 && y >= 0; y--) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case East:
            for (; x >= 0 && y < this->boardSize; x, y++) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case SouthWest:
            for (; x < this->boardSize && y >= 0; x++, y--) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case South:
            for (; x < this->boardSize && y >= 0; x++) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
        case SouthEast:
            for (; x < this->boardSize && y < this->boardSize; x++, y++) {
                if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
                    continue;
                } else return this->board->getCellStatus(Pair(x, y)) == player;
            }
            return false;
    }
}

void RegularGameLogic::flipCell(const Pair &p, Board::Status opponentP, Board::Status player) {
    this->board->changeStatus(Pair(p.getRow() - 1, p.getCol() - 1), player);
    flipNorthWest(p, opponentP, player);
    flipNorth(p, opponentP, player);
    flipNorthEast(p, opponentP, player);
    flipWest(p, opponentP, player);
    flipEast(p, opponentP, player);
    flipSouthWest(p, opponentP, player);
    flipSouth(p, opponentP, player);
    flipSouthEast(p, opponentP, player);
}

void RegularGameLogic::flipNorthWest(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x >= 0 && y >= 0; x--, y--) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipNorth(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x >= 0 && y >= 0; x--) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipNorthEast(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x >= 0 && y >= 0 && y < this->boardSize; x--, y++) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipWest(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x >= 0 && y >= 0; y--) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipEast(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x >= 0 && y < this->boardSize; x, y++) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipSouthWest(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x < this->boardSize && x >= 0 && y >= 0; x++, y--) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipSouth(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x < this->boardSize && y >= 0; x++) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::flipSouthEast(const Pair &p, Board::Status opponentP, Board::Status player) {
    Pair maybeFlipArr[this->boardSize];
    int x = p.getRow() - 1;
    int y = p.getCol() - 1;
    int count = -1;
    for (; x < this->boardSize && y < this->boardSize; x++, y++) {
        if (this->board->getCellStatus(Pair(x, y)) == opponentP) {
            count++;
            maybeFlipArr[count] = Pair(x, y);
        } else if (this->board->getCellStatus(Pair(x, y)) == player) {
            for (int i = 0; i <= count; i++) {
                this->board->changeStatus(Pair(maybeFlipArr[i].getRow(), maybeFlipArr[i].getCol()), player);
            }
            if (count != -1) {
                break;
            }
        } else {
            break;
        }
    }
}

void RegularGameLogic::setBoard(Board *board) {
    this->board = new Board(*board);
}