
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

#define NAME "Sicario"
#define CODENAME "iteration-1"
#define VERSION "v0.1.0"
#define AUTHOR "S. Kwan"
#define CHESS_PROGRAMMING "www.chessprogramming.org"
#define STOCKFISH "Stockfish"
#define BLUE_FEVER_SOFT "bluefeversoft"
#define STANDARD_GAME "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define DARK 0xAA55AA55AA55AA55

typedef uint64_t Hash;
typedef uint64_t Bitboard;
typedef uint16_t Move;

/**
 * Player side enum.
 */
enum Player {
    BLACK, WHITE
};

/**
 * The squares of the board and their associated numbers. NONE (64) used as a sentinel value.
 */
enum Square {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    NONE
};

/**
 * The squares in string format. Used for development and debugging.
 */
const std::string squareName[65] = {
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
    "None"
};

/**
 * The piece types.
 */
enum PieceType {
    B_KING, W_KING,
    W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN,
    B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT, B_PAWN,
    NO_PIECE
};

/**
 * Piece type strings. Used for development and debugging.
 */
const std::string piece_type_string[13] = {
    "B_KING", "W_KING",
    "W_QUEEN", "W_ROOK", "W_BISHOP", "W_KNIGHT", "W_PAWN",
    "B_QUEEN", "B_ROOK", "B_BISHOP", "B_KNIGHT", "B_PAWN",
    "NO_PIECE"
};

/**
 * The promotion piece types. In the format for move hashes (i.e. left shifted by 14 bits).
 */
enum Promotion {
    pKNIGHT = 0, pBISHOP = 1 << 14, pROOK = 2 << 14, pQUEEN = 3 << 14
};

/**
 * Promotion piece strings.
 */
const std::string promoName[4] = {
    "n", "b", "r", "q"
};

/**
 * The move types. In the format for move hashes (i.e. left shifted by 12 bits).
 */
enum MoveType {
    NORMAL = 0, PROMOTION = 1 << 12, EN_PASSANT = 2 << 12, CASTLING = 3 << 12
};

/**
 * Move type strings.
 */
const std::string moveName[4] = {
    "Normal", "Promotion", "En-passant", "Castling"
};

/**
 * Exit codes for the game or parsing.
 */
enum ExitCode {
    NORMAL_PLY,
    WHITE_WINS,
    BLACK_WINS,
    STALEMATE,
    THREE_FOLD_REPETITION,
    FIFTY_MOVES_RULE,
    INSUFFICIENT_MATERIAL,
    DRAW_BY_AGREEMENT,
    INVALID_FEN,
    INVALID_ARGS
};

/**
 * Player types.
 */
enum PlayerType {
    HUMAN, COMPUTER
};

/**
 * Castling options.
 */
enum Castling {
    WKSC, WQSC, BKSC, BQSC
};

/**
 * Bitboard of files with bits set.
 */
const Bitboard files[64] = {
    72340172838076673ULL, 144680345676153346ULL, 289360691352306692ULL, 578721382704613384ULL, 1157442765409226768ULL,
    2314885530818453536ULL, 4629771061636907072ULL, 9259542123273814144ULL
};

/**
 * Bitboards of ranks with bits set.
 */
const Bitboard ranks[64] = {
    255ULL, 65280ULL, 16711680ULL, 4278190080ULL, 1095216660480ULL, 280375465082880ULL, 71776119061217280ULL,
    18374686479671623680ULL
};

/**
 * Magic numbers for vertical and horizontal rook attacks.
 */
const Bitboard rookReachMagicNumbers[64] = {
    0x80001020400080ULL, 0x40004020001000ULL, 0x80300008802000ULL, 0x80100080040800ULL, 0x80040102800800ULL,
    0x80012400800200ULL, 0x806A0000800900ULL, 0x80002040800100ULL, 0x0A002081410200ULL, 0x4A002201054081ULL,
    0x43002001001040ULL, 0x01005000B90120ULL, 0x80800C00080080ULL, 0x07808004000A00ULL, 0x04001842100184ULL,
    0x01000081000042ULL, 0x800240042000C0ULL, 0x20008080204000ULL, 0x02808020001000ULL, 0x000A0020120040ULL,
    0x08010009100500ULL, 0x84808002000400ULL, 0x01C40010021108ULL, 0x01020004008041ULL, 0x00400080002388ULL,
    0x40032100408300ULL, 0x00200100430010ULL, 0x08090100100024ULL, 0x02110100040800ULL, 0x02000600081004ULL,
    0x46000A00040849ULL, 0x00800080084100ULL, 0x8000200040004AULL, 0x22200440401004ULL, 0x00200080801000ULL,
    0x00282103001000ULL, 0x80880080805400ULL, 0x00800201801400ULL, 0x04800200802100ULL, 0x00004082000401ULL,
    0x00802040008002ULL, 0x10102000484000ULL, 0x80500020008080ULL, 0x081200200A0040ULL, 0x04008040080800ULL,
    0x0440900C080120ULL, 0x01084110140012ULL, 0x00284100820004ULL, 0x41401020800480ULL, 0x00400900298500ULL,
    0x00102004410100ULL, 0x00402092002A00ULL, 0x05001298000500ULL, 0x44010040420040ULL, 0x00028308100400ULL,
    0x00800441001080ULL, 0x00442205008012ULL, 0x00210110400081ULL, 0x10104009022001ULL, 0x40045000090021ULL,
    0x02000804A0100AULL, 0x91005802040001ULL, 0x01000400820001ULL, 0x090000804A0A21ULL
};

const Bitboard rookMovesMagicNumbers[64] = {
    0xa6d02837c93f707aULL, 0x3eec9c49c592b8ccULL, 0xdc71f7857f05dee4ULL, 0x59d74e2ff0d1265ULL, 0xe82a97c714bf2199ULL, 0xf4fff5d6b47a97f3ULL, 0x85c43edf781a0bc9ULL, 0xde1a324853536d1fULL,
    0x9a89392f39b540f6ULL, 0xa896c7955c22717dULL, 0xc4f5ccb6de10c913ULL, 0x6b9b6475bfa26e2fULL, 0xffaff7fefff7eff7ULL, 0x5afefffb6dfaf35dULL, 0x970171e2fc3a8e55ULL, 0x4d2b791590f4f073ULL,
    0x39fdd950ae692134ULL, 0x53acf11ef0ab92a1ULL, 0x75ff3bd7fa7c1cf3ULL, 0x4f9538e949cc9627ULL, 0xfbfdf2fffafff9fbULL, 0xd399f4fffe6cf91fULL, 0x476e042386b7f2eaULL, 0xf0cbf45cfffefffdULL,
    0x4d6bb0c5b4ae8cacULL, 0x9e466b525bda20baULL, 0x66070f3711d2b973ULL, 0x3db84a69d8a4d15dULL, 0xadfd01b0bbe6582fULL, 0xdfcfbb76fffeffefULL, 0xbccde9984e0c35d2ULL, 0xfffeebfedeffaf9fULL,
    0x6e55d230f782cb61ULL, 0x7517d6645a9b6445ULL, 0xf7f7ffd7f7feff7fULL, 0xbf3222afd6d2a627ULL, 0xd7be7e2b2ffefdefULL, 0xeffbfdfafcfffcf7ULL, 0x5de253e5291cf63dULL, 0xbef47f7bbb12ffffULL,
    0xda774f37dcdcfd9fULL, 0x6fffbfffbfff1fffULL, 0x97ffa7ffe9fcff7dULL, 0xfdefdfafee3f1f8bULL, 0xdeddc70ca1092d6aULL, 0xff79e14f76feffedULL, 0xd5fdf31bfdbaffd7ULL, 0xe19e245f8a22e8d7ULL,
    0x76c09955657a61e3ULL, 0x611297f85e4a7a5cULL, 0x7f77fc2bfbdab45dULL, 0x5fd688829894db5eULL, 0xa532e26d19d30f6cULL, 0xace353dd9d2c9c74ULL, 0xd5f7f75ed777f97eULL, 0x2171d8dbb6986bbULL,
    0x76a795e1440f1397ULL, 0xf118ab5db92edb49ULL, 0xdf79d866ac48beedULL, 0x1da9466b71074e3bULL, 0x6f9abb5b38fe4ecfULL, 0xea462b890769778bULL, 0xbb7c798d7bcfacd9ULL, 0x3d6305bf99fc0846ULL,
};

/**
 * Shifts for finding rook indices.
 */
const int rookReachShifts[64] = {
    52, 53, 53, 53, 53, 53, 53, 52,
    53, 54, 54, 54, 54, 54, 54, 53,
    53, 54, 54, 54, 54, 54, 54, 53,
    53, 54, 54, 54, 54, 54, 54, 53,
    53, 54, 54, 54, 54, 54, 54, 53,
    53, 54, 54, 54, 54, 54, 54, 53,
    53, 54, 54, 54, 54, 54, 54, 53,
    52, 53, 53, 53, 53, 53, 53, 52,
};

const int rookMovesShifts[64] = {
    56, 55, 55, 54, 54, 55, 55, 56,
    55, 54, 53, 53, 54, 54, 54, 55,
    54, 53, 53, 52, 53, 53, 53, 55,
    54, 53, 52, 52, 52, 53, 53, 55,
    54, 53, 53, 52, 53, 53, 53, 55,
    55, 54, 53, 53, 52, 53, 54, 55,
    55, 54, 54, 53, 53, 54, 55, 56,
    56, 56, 55, 54, 55, 55, 56, 56,
};

/**
 * Masks for vertical and horizontal rook attacks.
 */
const Bitboard rookMasks[64] = {
    0x000101010101017EULL, 0x000202020202027CULL, 0x000404040404047AULL, 0x0008080808080876ULL, 0x001010101010106EULL,
    0x002020202020205EULL, 0x004040404040403EULL, 0x008080808080807EULL, 0x0001010101017E00ULL, 0x0002020202027C00ULL,
    0x0004040404047A00ULL, 0x0008080808087600ULL, 0x0010101010106E00ULL, 0x0020202020205E00ULL, 0x0040404040403E00ULL,
    0x0080808080807E00ULL, 0x00010101017E0100ULL, 0x00020202027C0200ULL, 0x00040404047A0400ULL, 0x0008080808760800ULL,
    0x00101010106E1000ULL, 0x00202020205E2000ULL, 0x00404040403e4000ULL, 0x00808080807E8000ULL, 0x000101017E010100ULL,
    0x000202027C020200ULL, 0x000404047A040400ULL, 0x0008080876080800ULL, 0x001010106E101000ULL, 0x002020205E202000ULL,
    0x004040403E404000ULL, 0x008080807E808000ULL, 0x0001017E01010100ULL, 0x0002027C02020200ULL, 0x0004047A04040400ULL,
    0x0008087608080800ULL, 0x0010106E10101000ULL, 0x0020205E20202000ULL, 0x0040403E40404000ULL, 0x0080807E80808000ULL,
    0x00017E0101010100ULL, 0x00027C0202020200ULL, 0x00047A0404040400ULL, 0x0008760808080800ULL, 0x00106E1010101000ULL,
    0x00205E2020202000ULL, 0x00403E4040404000ULL, 0x00807E8080808000ULL, 0x007E010101010100ULL, 0x007C020202020200ULL,
    0x007A040404040400ULL, 0x0076080808080800ULL, 0x006E101010101000ULL, 0x005E202020202000ULL, 0x003E404040404000ULL,
    0x007E808080808000ULL, 0x7E01010101010100ULL, 0x7C02020202020200ULL, 0x7A04040404040400ULL, 0x7608080808080800ULL,
    0x6E10101010101000ULL, 0x5E20202020202000ULL, 0x3E40404040404000ULL, 0x7E80808080808000ULL
};

/**
 * Magic numbers for diagonal attacks.
 */
const Bitboard bishopReachMagicNumbers[64] = {
    0x04081001020051, 0x10010842808000, 0x10010045020008, 0x18204040080000, 0x21104008000008, 0x6088200A00B954,
    0x04010410040000, 0x30220802080200, 0x00400808008280, 0x02200803010030, 0x00084283020080, 0x00040408808000,
    0x40011040040000, 0x00160904200040, 0xC9510082202100, 0x03004208A46000, 0x41022008068080, 0x08003102008400,
    0x50008802254050, 0x04000814101002, 0x00804400A04000, 0x01008200820103, 0x00400121101000, 0x0A020100848C00,
    0x2410000C200842, 0x410400100CC802, 0x88080050882140, 0x11080004004090, 0x40840002020200, 0x00D08014100400,
    0x01040A22108408, 0x90810102014200, 0x06104000100200, 0x08420800428828, 0xC0A80100080200, 0x00860080080080,
    0x0C010200040084, 0x21004100020100, 0x0210A100020801, 0x00820081005400, 0x91100310002010, 0x00C21004001004,
    0x0A002208040104, 0x080020510A4800, 0x14080104000241, 0x06008102000100, 0x02108409020489, 0x02080200B00080,
    0x44010110108100, 0x01010082200005, 0x48010401040000, 0x0100002088000D, 0x10104008288200, 0xDCC4100A020000,
    0x040410144104C0, 0x48500102006008, 0x08440048080410, 0x08020184841000, 0x00000201466800, 0x42100024420200,
    0x00000040050102, 0x00800410420200, 0x002004C1080100, 0x20204101010010
};

const Bitboard bishopMovesMagicNumbers[64] = {
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL,
    0ULL, 0ULL, 0ULL, 0ULL
};

/**
 * Shifts for finding bishop indices.
 */
const int bishopReachShifts[64] = {
    58, 59, 59, 59, 59, 59, 59, 58,
    59, 59, 59, 59, 59, 59, 59, 59,
    59, 59, 57, 57, 57, 57, 59, 59,
    59, 59, 57, 55, 55, 57, 59, 59,
    59, 59, 57, 55, 55, 57, 59, 59,
    59, 59, 57, 57, 57, 57, 59, 59,
    59, 59, 59, 59, 59, 59, 59, 59,
    58, 59, 59, 59, 59, 59, 59, 58
};

const int bishopMovesShifts[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

/**
 * Masks for diagonal attacks.
 */
const Bitboard bishopMasks[64] = {
    0x40201008040200, 0x00402010080400, 0x00004020100A00, 0x00000040221400, 0x00000002442800, 0x00000204085000,
    0x00020408102000, 0x02040810204000, 0x20100804020000, 0x40201008040000, 0x004020100A0000, 0x00004022140000,
    0x00000244280000, 0x00020408500000, 0x02040810200000, 0x04081020400000, 0x10080402000200, 0x20100804000400,
    0x4020100A000A00, 0x00402214001400, 0x00024428002800, 0x02040850005000, 0x04081020002000, 0x08102040004000,
    0x08040200020400, 0x10080400040800, 0x20100A000A1000, 0x40221400142200, 0x02442800284400, 0x04085000500800,
    0x08102000201000, 0x10204000402000, 0x04020002040800, 0x08040004081000, 0x100A000A102000, 0x22140014224000,
    0x44280028440200, 0x08500050080400, 0x10200020100800, 0x20400040201000, 0x02000204081000, 0x04000408102000,
    0x0A000A10204000, 0x14001422400000, 0x28002844020000, 0x50005008040200, 0x20002010080400, 0x40004020100800,
    0x00020408102000, 0x00040810204000, 0x000A1020400000, 0x00142240000000, 0x00284402000000, 0x00500804020000,
    0x00201008040200, 0x00402010080400, 0x02040810204000, 0x04081020400000, 0x0A102040000000, 0x14224000000000,
    0x28440200000000, 0x50080402000000, 0x20100804020000, 0x40201008040200
};

#endif
