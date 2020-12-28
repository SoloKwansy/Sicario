
#ifndef GAME_HPP
#define GAME_HPP

#include "constants.hpp"
#include "movegen.hpp"

typedef uint64_t Hash;

/**
 * A struct representing the current board position.
 */
class Pos {
    public:
        Pos(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        void run();
        uint64_t perft(int depth, bool print = false);
        ExitCode parseFen(std::string fen);
        void display() const;

    private:
        // Non-position information
        bool turn;
        int castling;
        Square en_passant;
        int halfmove, fullmove;

        // Bitboards
        uint64_t sides[2];
        uint64_t kings, queens, rooks, bishops, knights, pawns;
        Bitboard enemy_attacks;
        Bitboard rook_pins;
        Bitboard bishop_pins;
        Bitboard kEnemy_attacks;

        // Piece positions
        int piece_index[12];
        Square piece_list[12][10];
        PieceType pieces[64];

        // Piece counts for insufficient material checks.
        int piece_cnt = 0;
        int knight_cnt = 0;
        int wdsb_cnt = 0, wlsb_cnt = 0;
        int bdsb_cnt = 0, blsb_cnt = 0;

        // Pos history
        Move last_move;
        PieceType piece_moved;
        PieceType piece_captured;
        MoveType last_move_type;
        History history[MAX_MOVES];
        std::unordered_map<Bitboard, int> hashes;
        Hash hash;
        int ply;

        // Miscellaneous info
        Player white = HUMAN, black = HUMAN;

        // AI?
        double alphaBeta(int depth, double alpha, double beta, bool max);
        double evaluate();

        // EOG checks
        ExitCode isEOG(int move_index);
        bool insufficientMaterial();
        bool isThreeFoldRep();

        // Game logic
        void checkCastlingEnPassantMoves(uint start, uint end, Move* move);
        bool validMove(Move move, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int* moves_index);
        bool isChecked();
        bool isDoubleChecked();
        uint64_t getBishopCheckRays(Square square, uint64_t* checkers_only);
        uint64_t getRookCheckRays(Square square, uint64_t* checkers);
        uint64_t getPawnCheckers(Square square, uint64_t* checkers_only);
        uint64_t getKnightCheckers(Square square, uint64_t* checkers_only);
        const int rookBlockIndex(uint64_t pos, Square square);

        // Position updates
        void findAndRemovePiece(PieceType piece, Square square);
        void addPiece(PieceType piece, Square square);
        void removePiece();

        // Make move
        void makeMove(Move move);
        void makeKingMoves(Move move);
        void makeQueenMoves(Move move);
        void makeRookMoves(Move move);
        void makeBishopMoves(Move move);
        void makeKnightMoves(Move move);
        void makePawnMoves(Move move);
        void handleCastle();

        // Undo
        void undoNormal();
        void undoMove();
        void undoCastling();
        void undoPromotion();
        void undoEnPassant();

        // Move generation
        void getMoves(int& moves_index, std::vector<Move>* pos_moves[MAX_MOVE_SETS]);
        void getEnemyAttacks();
        MovesStruct* getRookFamily(Square square);
        MovesStruct* getBishopFamily(Square square);
        uint64_t pawnMoveArgs(Square square);

        // Normal move generation
        void getNormalMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getKingMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getQueenMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getRookMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getBishopMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getKnightMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getPawnMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getRookPinMoves(int square, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getBishopPinMoves (int square, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getCastlingMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getEpMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void horizontalPinEp(int king, bool turn, int attacker_sq, int captured_pawn, int ep, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void diagonalPinEp(int king, bool turn, int attacker_sq, int captured_pawn, int ep, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);

        // Check move generation
        void getCheckedMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getCheckedEp(uint64_t checkers, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);

        // Move reading and parsing
        Move chooseMove(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int* moves_index);
        void getSquares(std::string move_string, Move* move, uint* start, uint* end);

        // Miscellaneous
        void initialiseHash();
        void showEOG(ExitCode code);
        std::string getFEN();
        void saveHistory(Move move);
        void displayAll() const;
        void zero();
        void incrementHash(Move move);
        void decrementHash(Hash hash);
};

namespace Play {
    void init(std::string input);
}

#endif
