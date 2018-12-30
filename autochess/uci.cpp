#include "uci.h"

Uci::Uci()
{
    moveType = new MoveUci();
    UCIReader = new UCIReader();
}

void Uci::MakeMove(string move)
{
    moveType->MakeMove(move);
}

void Uci::Initialize()
{

}
