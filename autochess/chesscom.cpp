#include "chesscom.h"

void ChessCommunicator::MakeMove(string move)
{
    moveType->MakeMove(move);
}

ChessCommunicator::ChessCommunicator() {}
