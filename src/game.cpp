#include "../includes/game.hpp"

Game::Game(int width, int height) {
    board = new Board(width, height);
    pieces = std::vector<Piece*>();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board->setTile(Vec2D<int>(j, i), 0);
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
        
Piece* Game::getPiece (int id) {
    for (auto p = pieces.begin(); p != pieces.end(); ++p) {
        if ((*p)->getId() == id) return *p;
    }
    return nullptr;
}

Board* Game::getBoard () {
    return board;
}

Vec2D<int> Game::getKing (bool color) {
    return kings[color];
}
        
bool Game::isTurn () {
    return turn;
}
        
bool Game::move (Move move) {

    // Select Origin and Target Piece
    int origin = board->getTile(move.origin);
    int target = board->getTile(move.target);

    // Get Target and Origin Colors
    bool o_color = (origin / abs(origin) + 1) / 2;
    bool t_color = (target / abs(target) + 1) / 2;

    // Empty piece or not your piece
    if (origin == 0 || o_color != this->turn) return false; 

    // Target tile cannot have your piece.
    if (t_color == turn) return false;

    // Check if specific piece can make this move.
    if (getPiece(origin)->logic()) {
        turn = !turn;
        return true;
    }

    return false;
}