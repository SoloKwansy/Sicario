
#ifndef GAME_HPP
#define GAME_HPP

#include <atomic>

#include "constants.hpp"
#include "movegen.hpp"
#include "search.hpp"

void printMove(Move move, bool extraInfo);
MoveType type(Move move);
Square end(Move move);
Square start(Move move);
Promotion promo(Move move);

/**
 * Forward declarations.
 */
class SearchInfo;
class MoveList;

/**
 * A struct representing the current board position.
 */
class Pos {
    public:
        Pos(std::string fen = STANDARD_GAME);
        void run();
        uint64_t perft(int depth, bool print = false);
        ExitCode parseFen(std::string fen);
        void display() const;
        void displayAll() const;
        void setPlayer(Player, std::string);

        // Static position evaluation
        bool isEndGame() const;
        int psqt() const;
        int material() const;

        // Tree search
        void setDepth(int depth);
        void setHashSize(int size);
        void search(SearchParams, std::atomic_bool&);

        // Move generation
        void getMoves(int& moves_index, std::vector<Move>* pos_moves[MAX_MOVE_SETS]);

        // Accessors
        Hash getHash();

    private:
        // Non-position information
        bool turn;
        int castling;
        Square en_passant;
        int halfmove, fullmove;

        // Bitboards
        Bitboard sides[2];
        Bitboard kings, queens, rooks, bishops, knights, pawns;
        Bitboard enemy_attacks;
        Bitboard rook_pins;
        Bitboard bishop_pins;
        Bitboard kEnemy_attacks;
        Bitboard check_rays;
        Bitboard checkers;

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
        std::vector<History> history;
        std::unordered_map<Bitboard, int> hashes;
        Hash hash;
        int ply;

        // Miscellaneous info
        PlayerType white = HUMAN, black = HUMAN;

        // Evaluation and search
        SearchInfo searchInfo;
        int depth = 3;
        std::vector<std::pair<int, Move>> orderMoves(SearchParams, MoveList&);
        void mcst(std::vector<std::pair<int, Move>>, SearchParams, std::atomic_bool&);

        // Move ordering
        int scoreMove(Move);
        int kingSafety(Move);
        int scoreCastlingSafety(Move);
        int scoreKingSafety(Move);
        int captures(Move);

        // Perft hashing
        std::unordered_map<Bitboard, uint64_t> perft_hash;

        // EOG checks
        ExitCode isEOG(MoveList& move_list);
        bool insufficientMaterial();
        bool isThreeFoldRep();

        // Game logic
        void checkCastlingEnPassantMoves(uint start, uint end, Move& move);
        bool validMove(Move move, MoveList&);
        bool isChecked();
        bool isDoubleChecked();
        Bitboard getBishopCheckRays(Square square, Bitboard& checkers_only);
        Bitboard getRookCheckRays(Square square, Bitboard& checkers);
        Bitboard getPawnCheckers(Square square, Bitboard& checkers_only);
        Bitboard getKnightCheckers(Square square, Bitboard& checkers_only);
        const int rookBlockIndex(Bitboard pos, Square square);
        Bitboard isAttacked(const Square, const bool);
        Bitboard isOccupied(const Square);
        void setBitboards();
        bool oneBitSet(Bitboard bits);
        Bitboard getKingAttackers(const Square, const bool) const;
        void setCheckers();
        Bitboard getKingAttackBitBoard() const;

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
        void getEnemyAttacks();
        MovesStruct* getRookFamily(Square square);
        MovesStruct* getBishopFamily(Square square);
        Bitboard pawnMoveArgs(Square square);

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
        void horizontalPinEp(int king, bool turn, int attacker_sq, int captured_pawn, int ep,
                std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void diagonalPinEp(int king, bool turn, int attacker_sq, int captured_pawn, int ep,
                std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);

        // Check move generation
        void getCheckedMoves(std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);
        void getCheckedEp(Bitboard checkers, std::vector<Move>* pos_moves[MAX_MOVE_SETS], int& moves_index);

        // Move reading and parsing
        Move chooseMove(MoveList&);
        void getSquares(std::string move_string, Move& move, uint& start, uint& end);

        // Miscellaneous
        void initialiseHash();
        void showEOG(ExitCode code);
        std::string getFEN();
        void saveHistory(Move move);
        void zero();
        void incrementHash(Move move);
        void decrementHash(Hash hash);
};

class MoveList {
    public:
        MoveList(Pos&);
        uint64_t bulkCount();

        struct Iterator {
            Iterator(int, int, int, std::vector<Move>**, Move&);

            Move& operator*() const;
            Move* operator->();

            Iterator& operator++(); // Prefix
            Iterator operator++(int); // Postfix

            friend bool operator== (const Iterator& a, const Iterator& b) {
                return a.ptr == b.ptr;
            }

            friend bool operator!= (const Iterator& a, const Iterator& b) {
                return a.ptr != b.ptr;
            }

            private:
                Move* ptr;
                std::vector<Move>** moves;
                int vec_cnt, i, j;
                Move* endAddr;
        };

        Iterator begin();
        Iterator end();

        std::vector<Move>* moves[MAX_MOVE_SETS];
        int moves_index;
        Move endMove; // Dummy move for end of iterator. Just need the address.
};

namespace Play {
    void init(std::string input);
}

#endif
