#include "../includes/game.hpp"

Game::Game(int width, int height) {
    board = new Board(width, height);
    pieces = std::vector<Piece*>();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board->setTile(j, i, 0);
        }
    }
}
        
Game::~Game() {
    free(board);
    for (int i = 0; i < pieces.size(); i++) {
        free(pieces[i]);
    }
}
        
void Game::addPiece (Piece* piece) {
    pieces.push_back(piece);
}
        
Piece* Game::getPiece (uint id) {
    for (auto p = pieces.begin(); p != pieces.end(); ++p) {
        if ((*p)->getId() == id) return *p;
    }
    return nullptr;
}

Board* Game::getBoard () {
    return board;
}

Pos Game::getKing (bool color) {
    return kings[color];
}
        
bool Game::isTurn () {
    return turn;
}
        
bool Game::move (Pos p1, Pos p2) {

    // Selected tile must have your piece.

    uint origin = board->getTile(p1.x, p1.y);
    bool o_color = (origin / abs(origin) + 1) / 2;

    if (origin == 0 || o_color != turn) return false; 

    // Target tile cannot have your piece.

    uint target = board->getTile(p2.x, p2.y);
    bool t_color = (target / abs(target) + 1) / 2;

    if (t_color == turn) return false;

    // Check if piece can make this move.

    if (getPiece(origin)->logic()) {
        turn = !turn;
        return true;
    }
}