#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include "constants.hpp"

namespace MagicNums {
    const Bitboard KING[SQUARE_COUNT] = {
        0x1440000000000000ULL, 0x8210000000000000ULL, 0x0910000000000000ULL, 0x0811000000000000ULL,
        0x0244000000000000ULL, 0x0204400000000000ULL, 0x0410800000000000ULL, 0x0081008000000000ULL,
        0x0840200000000000ULL, 0x2002440200000080ULL, 0x1008210020100000ULL, 0x0800610200040000ULL,
        0x0402084020100000ULL, 0x0a01042000000200ULL, 0x0900204404000000ULL, 0x0040210000000000ULL,
        0x0040100800000000ULL, 0x0020040880008100ULL, 0x0030020440004000ULL, 0x1008009100001000ULL,
        0x0044003080000100ULL, 0x0302010420000000ULL, 0x0001008210040200ULL, 0x0001008020000000ULL,
        0x0000400410000000ULL, 0x0100201042010000ULL, 0x0900020130000000ULL, 0x0000080091004001ULL,
        0x0000040081100082ULL, 0x1000084026000000ULL, 0x0000010060440004ULL, 0x0000010020400000ULL,
        0x0000001004400000ULL, 0x0020002001940000ULL, 0x00000010032a0000ULL, 0x0100002804108000ULL,
        0x0000104400811000ULL, 0x9000000201042000ULL, 0x81000001000c2000ULL, 0x0000000082002000ULL,
        0x0000000010044000ULL, 0x0000000320104200ULL, 0x0000090010020440ULL, 0x8800000008009100ULL,
        0x0000000604004880ULL, 0x4000002002010420ULL, 0x2400000001002044ULL, 0x0000000000220080ULL,
        0x0000000000100440ULL, 0x000000040020018cULL, 0x0000440000020130ULL, 0x0400010000080061ULL,
        0x201000101100804cULL, 0x0000000404004026ULL, 0x8004200000032013ULL, 0x0000000000002081ULL,
        0x0000000004004010ULL, 0x0000000000001082ULL, 0x0000000000001009ULL, 0x0000000000001108ULL,
        0x0000000000000884ULL, 0x0000000000000442ULL, 0x0000000000000221ULL, 0x0000200000000082ULL,
    };

    const Bitboard KNIGHT[SQUARE_COUNT] = {
        0x0020200000000002ULL, 0x0008200000000001ULL, 0x0014100000000000ULL, 0x000a080000000000ULL,
        0x000a020000000000ULL, 0x0008220000000000ULL, 0x000c010000000000ULL, 0x0002020000000040ULL,
        0x0800104000000000ULL, 0x0200082000000000ULL, 0x0400810400100020ULL, 0x10200c0410000000ULL,
        0x8100204100020000ULL, 0x040a010100000004ULL, 0x0400010100000000ULL, 0x0100040100000000ULL,
        0x0808022020080000ULL, 0x1010100406000000ULL, 0x0104001050002000ULL, 0x0404000208200040ULL,
        0x0400400700400000ULL, 0x0808800020800001ULL, 0x0900400180800000ULL, 0x2101200400400000ULL,
        0x00c0120004100000ULL, 0x0014280010080000ULL, 0x4801040010100000ULL, 0x0000440010140020ULL,
        0x8001410004040000ULL, 0x0042008000a02000ULL, 0x0008804000910000ULL, 0x0001010104006000ULL,
        0x4000401008041000ULL, 0x0000200802020900ULL, 0x0011100100040100ULL, 0x0000880200018080ULL,
        0x0400020080202020ULL, 0x0800020020108020ULL, 0x0000090040008880ULL, 0x0000000005100040102,
        0x0408000810002010ULL, 0x0041000800801010ULL, 0x0000004044000904ULL, 0x0002000044001014ULL,
        0x0000800020800a02ULL, 0x0008000111000041ULL, 0x0000000208880101ULL, 0x00000000cc000101ULL,
        0x0000000010200010ULL, 0x0000000020020008ULL, 0x0000800008204048ULL, 0x4000000004102104ULL,
        0x0000000882018002ULL, 0x000000000300c005ULL, 0x0000000000880002ULL, 0x0000000001010004ULL,
        0x0080000000202000ULL, 0x0000002000200800ULL, 0x0000000000104100ULL, 0x0000000000041400ULL,
        0x0000000000040500ULL, 0x0000000000020820ULL, 0x0000000020010400ULL, 0x0000001000020200ULL
    };

    /**
     * Magic numbers for pawn moves. First is for black, second is for white.
     */
    const Bitboard PAWN[PLAYER_COUNT][SQUARE_COUNT] = {
        {
            ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB,
            0xa000400000000000ULL, 0x2001000000000002ULL, 0x1000000000008010ULL, 0x0801000000200000ULL,
            0x0400000000040002ULL, 0x0200000000020200ULL, 0x0102000000800000ULL, 0x0108000000004000ULL,
            0x0040000001000080ULL, 0x0021000080000000ULL, 0x0010000000004020ULL, 0x0012000000100000ULL,
            0x0104000000000010ULL, 0x1002000004000000ULL, 0x0003040000000000ULL, 0x0002800000000200ULL,
            0x0008400000080000ULL, 0x0001200000000008ULL, 0x0000504000000000ULL, 0x8000080800000000ULL,
            0x0000040140000000ULL, 0x0000020000004008ULL, 0x0000070000000000ULL, 0x0400010000200000ULL,
            0x0000004800000008ULL, 0x0008012000000000ULL, 0x0800001000000004ULL, 0x2000001800000000ULL,
            0x1000008400000000ULL, 0x0000000201020000ULL, 0x0000001100000020ULL, 0x0000040100000800ULL,
            0x0000000040810000ULL, 0x0000100020000800ULL, 0x1000000011000000ULL, 0x0000000008020100ULL,
            0x0000808004000000ULL, 0x0000044002000000ULL, 0x0008000001080000ULL, 0x0000002002800000ULL,
            0x0000000280200000ULL, 0x0000000008200010ULL, 0x0000000014100000ULL, 0x0000800002080000ULL,
            0x0200000001040000ULL, 0x0000000001044000ULL, 0x0000010002008000ULL, 0x0000020000410000ULL,
            ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB,
        },
        {
            ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB,
            0x0000208000000040ULL, 0x0000104000200000ULL, 0x8000082000000000ULL, 0x0200080200000000ULL,
            0x1000040100000000ULL, 0x0000020080000200ULL, 0x0000010040000080ULL, 0x0000010040000100ULL,
            0x000000c000000002ULL, 0x0000006000000002ULL, 0x0000201000000020ULL, 0x0000002400000001ULL,
            0x0400000400400000ULL, 0x0804000200000000ULL, 0x0000001900000000ULL, 0x0000900100000000ULL,
            0x0000800040002000ULL, 0x0010000020000100ULL, 0x0180000010000000ULL, 0x0000420008000000ULL,
            0x004000000c000000ULL, 0x0000000002080008ULL, 0x0000000001010020ULL, 0x0400020001000000ULL,
            0x0008000000440000ULL, 0x0020000000240000ULL, 0x0801000000100000ULL, 0x0000000001080200ULL,
            0x1000010000040000ULL, 0x0000010000020001ULL, 0x0000008000010004ULL, 0x0004008000010000ULL,
            0x0004000000004800ULL, 0x0000008002002000ULL, 0x0011000000001000ULL, 0x0000100004000800ULL,
            0x0004000200000400ULL, 0x0000000080002200ULL, 0x0000280000000100ULL, 0x4000000080000100ULL,
            0x0000020100000040ULL, 0x0080000000100020ULL, 0x0000000000000212ULL, 0x0800000000000018ULL,
            0x0000200008000004ULL, 0x0000000008000802ULL, 0x0000000008004001ULL, 0x0024000000000001ULL,
            ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB, ZERO_BB,
        }
    };
}

namespace MagicNums::Reach {
    const Bitboard ROOK[SQUARE_COUNT] = {
        0x0080001020400080ULL, 0x0040004020001000ULL, 0x0080300008802000ULL, 0x0080100080040800ULL,
        0x0080040102800800ULL, 0x0080012400800200ULL, 0x00806A0000800900ULL, 0x0080002040800100ULL,
        0x000A002081410200ULL, 0x004A002201054081ULL, 0x0043002001001040ULL, 0x0001005000B90120ULL,
        0x0080800C00080080ULL, 0x0007808004000A00ULL, 0x0004001842100184ULL, 0x0001000081000042ULL,
        0x00800240042000C0ULL, 0x0020008080204000ULL, 0x0002808020001000ULL, 0x00000A0020120040ULL,
        0x0008010009100500ULL, 0x0084808002000400ULL, 0x0001C40010021108ULL, 0x0001020004008041ULL,
        0x0000400080002388ULL, 0x0040032100408300ULL, 0x0000200100430010ULL, 0x0008090100100024ULL,
        0x0002110100040800ULL, 0x0002000600081004ULL, 0x0046000A00040849ULL, 0x0000800080084100ULL,
        0x008000200040004AULL, 0x0022200440401004ULL, 0x0000200080801000ULL, 0x0000282103001000ULL,
        0x0080880080805400ULL, 0x0000800201801400ULL, 0x0004800200802100ULL, 0x0000004082000401ULL,
        0x0000802040008002ULL, 0x0010102000484000ULL, 0x0080500020008080ULL, 0x00081200200A0040ULL,
        0x0004008040080800ULL, 0x000440900C080120ULL, 0x0001084110140012ULL, 0x0000284100820004ULL,
        0x0041401020800480ULL, 0x0000400900298500ULL, 0x0000102004410100ULL, 0x0000402092002A00ULL,
        0x0005001298000500ULL, 0x0044010040420040ULL, 0x0000028308100400ULL, 0x0000800441001080ULL,
        0x0000442205008012ULL, 0x0000210110400081ULL, 0x0010104009022001ULL, 0x0040045000090021ULL,
        0x0002000804A0100AULL, 0x0091005802040001ULL, 0x0001000400820001ULL, 0x00090000804A0A21ULL
    };

    const Bitboard BISHOP[SQUARE_COUNT] = {
        0x0004081001020051ULL, 0x0010010842808000ULL, 0x0010010045020008ULL, 0x0018204040080000ULL,
        0x0021104008000008ULL, 0x006088200A00B954ULL, 0x0004010410040000ULL, 0x0030220802080200ULL,
        0x0000400808008280ULL, 0x0002200803010030ULL, 0x0000084283020080ULL, 0x0000040408808000ULL,
        0x0040011040040000ULL, 0x0000160904200040ULL, 0x00C9510082202100ULL, 0x0003004208A46000ULL,
        0x0041022008068080ULL, 0x0008003102008400ULL, 0x0050008802254050ULL, 0x0004000814101002ULL,
        0x0000804400A04000ULL, 0x0001008200820103ULL, 0x0000400121101000ULL, 0x000A020100848C00ULL,
        0x002410000C200842ULL, 0x00410400100CC802ULL, 0x0088080050882140ULL, 0x0011080004004090ULL,
        0x0040840002020200ULL, 0x0000D08014100400ULL, 0x0001040A22108408ULL, 0x0090810102014200ULL,
        0x0006104000100200ULL, 0x0008420800428828ULL, 0x00C0A80100080200ULL, 0x0000860080080080ULL,
        0x000C010200040084ULL, 0x0021004100020100ULL, 0x000210A100020801ULL, 0x0000820081005400ULL,
        0x0091100310002010ULL, 0x0000C21004001004ULL, 0x000A002208040104ULL, 0x00080020510A4800ULL,
        0x0014080104000241ULL, 0x0006008102000100ULL, 0x0002108409020489ULL, 0x0002080200B00080ULL,
        0x0044010110108100ULL, 0x0001010082200005ULL, 0x0048010401040000ULL, 0x000100002088000DULL,
        0x0010104008288200ULL, 0x00DCC4100A020000ULL, 0x00040410144104C0ULL, 0x0048500102006008ULL,
        0x0008440048080410ULL, 0x0008020184841000ULL, 0x0000000201466800ULL, 0x0042100024420200ULL,
        0x0000000040050102ULL, 0x0000800410420200ULL, 0x00002004C1080100ULL, 0x0020204101010010ULL
    };
}

namespace MagicNums::Moves {
    const Bitboard ROOK[SQUARE_COUNT] = {
        0xa6d02837c93f707aULL, 0x3eec9c49c592b8ccULL, 0xdc71f7857f05dee4ULL, 0x059d74e2ff0d1265ULL,
        0xe82a97c714bf2199ULL, 0xf4fff5d6b47a97f3ULL, 0x85c43edf781a0bc9ULL, 0xde1a324853536d1fULL,
        0x9a89392f39b540f6ULL, 0xa896c7955c22717dULL, 0xc4f5ccb6de10c913ULL, 0x6b9b6475bfa26e2fULL,
        0xffaff7fefff7eff7ULL, 0x5afefffb6dfaf35dULL, 0x970171e2fc3a8e55ULL, 0x4d2b791590f4f073ULL,
        0x39fdd950ae692134ULL, 0x53acf11ef0ab92a1ULL, 0x75ff3bd7fa7c1cf3ULL, 0x4f9538e949cc9627ULL,
        0xfbfdf2fffafff9fbULL, 0xd399f4fffe6cf91fULL, 0x476e042386b7f2eaULL, 0xf0cbf45cfffefffdULL,
        0x4d6bb0c5b4ae8cacULL, 0x9e466b525bda20baULL, 0x66070f3711d2b973ULL, 0x3db84a69d8a4d15dULL,
        0xadfd01b0bbe6582fULL, 0xdfcfbb76fffeffefULL, 0xbccde9984e0c35d2ULL, 0xfffeebfedeffaf9fULL,
        0x6e55d230f782cb61ULL, 0x7517d6645a9b6445ULL, 0xf7f7ffd7f7feff7fULL, 0xbf3222afd6d2a627ULL,
        0xd7be7e2b2ffefdefULL, 0xeffbfdfafcfffcf7ULL, 0x5de253e5291cf63dULL, 0xbef47f7bbb12ffffULL,
        0xda774f37dcdcfd9fULL, 0x6fffbfffbfff1fffULL, 0x97ffa7ffe9fcff7dULL, 0xfdefdfafee3f1f8bULL,
        0xdeddc70ca1092d6aULL, 0xff79e14f76feffedULL, 0xd5fdf31bfdbaffd7ULL, 0xe19e245f8a22e8d7ULL,
        0x76c09955657a61e3ULL, 0x611297f85e4a7a5cULL, 0x7f77fc2bfbdab45dULL, 0x5fd688829894db5eULL,
        0xa532e26d19d30f6cULL, 0xace353dd9d2c9c74ULL, 0xd5f7f75ed777f97eULL, 0x02171d8dbb6986bbULL,
        0x76a795e1440f1397ULL, 0xf118ab5db92edb49ULL, 0xdf79d866ac48beedULL, 0x1da9466b71074e3bULL,
        0x6f9abb5b38fe4ecfULL, 0xea462b890769778bULL, 0xbb7c798d7bcfacd9ULL, 0x3d6305bf99fc0846ULL
    };

    const Bitboard BISHOP[SQUARE_COUNT] = {
        0xf595f2102713b0ddULL, 0xfd9f408bac4f8229ULL, 0x2be56992e4b44da5ULL, 0xea16a3dec07a88dcULL,
        0xd4ae1df28d6d048bULL, 0xe80318fc54cbad4fULL, 0xd025035c36eef61eULL, 0x1bd8f40dbaf48c29ULL,
        0x42562d998e6bcb8bULL, 0xfbfff7f6fdfeff7fULL, 0x2ff6fdfbf87ad7e0ULL, 0x97ffebebeff7fbf4ULL,
        0x6fbf3f77f9dfbf7bULL, 0xef3d6f9ef0890daeULL, 0xdeffef7fbd8dfbafULL, 0xd97dfe30548c482bULL,
        0x08e6f973a94d9589ULL, 0xa9cb619a4e4e46abULL, 0xad0bdf5f7cd7bfd5ULL, 0x4fa95ee73b440b0aULL,
        0x0ac8bbcc417b0eeeULL, 0x2820eecacb33a95fULL, 0xef9bcf5afefba0d7ULL, 0x93036c14d5abb8f9ULL,
        0xe992a24eb7b41e62ULL, 0x8f7926bfb2015389ULL, 0xfffbf7efebfdfeffULL, 0xfeff7fbff7dffbdfULL,
        0xeffbf5fbeaffbdffULL, 0xf7ff7dfeefdfefffULL, 0x7bfed6fff77fbfbfULL, 0xcc306c56ced7c9c2ULL,
        0x22b70d5c771ba398ULL, 0x59f9fab7fec3efffULL, 0xfff67fedfffbfdffULL, 0xfeb347dbf5eebe72ULL,
        0x70bef5647e5bffefULL, 0xfefb9beddfffbf7fULL, 0x97937fb7d43797ffULL, 0x49c4ea382f67c1f4ULL,
        0xf49ab4d42998763cULL, 0x6e2ee0cdcdcbfdbfULL, 0xfeefcfbff6fcefffULL, 0x3fd39ddfbf7ff7feULL,
        0x6bfdce6f9fbffdffULL, 0xb56fdb7cf7f580ffULL, 0x78ccac6ebefffb6fULL, 0x6d6a5e9ef068222dULL,
        0x48c35bdd537386c1ULL, 0x9b2edfc46f542ee0ULL, 0xfbf250b36a2b1170ULL, 0x5f7368f9e3e15548ULL,
        0xb13dc6ff9f018184ULL, 0xc3c6153eb02af92eULL, 0x6be76d1e806480efULL, 0xbb8bb68d4860be8aULL,
        0x1097d0e7e9e7e430ULL, 0xeb5e9f3440c7212eULL, 0x4fd029705c0976dfULL, 0x2d41cab3c83c6e3bULL,
        0x15188e74a9e789deULL, 0xbb18adb45b6d1509ULL, 0x67abafd14128e465ULL, 0xbbde1b299238c781ULL
    };
}

namespace MagicNums::Block {
    const Bitboard ROOK[SQUARE_COUNT] = {
        0xbc5f4194a983b999ULL, 0xecac1d7047698be1ULL, 0x1b1c38abd0a6fbc8ULL, 0xcea26b01466cdcb7ULL,
        0x3644be10d67edd0cULL, 0x3781de487fa12b8aULL, 0xf4724b8d5264dc53ULL, 0x95a463b1e18cc59fULL,
        0xf84d4f8277b9212aULL, 0x1dc436c6b017ddacULL, 0xfbf0f0d525cb8822ULL, 0x7a5b86b54529ea6fULL,
        0x532f4fbcbc213826ULL, 0x81b22f4a96e5d1f4ULL, 0xa6c98d4fc5c04f65ULL, 0x0e327d1ae55ed283ULL,
        0x35e32149985fe93cULL, 0x0d19bc553b22a53fULL, 0xfc3709c7ae0858e9ULL, 0xf43af87d73c96458ULL,
        0x0193e96f508cbde5ULL, 0x718b2d27bc1ec907ULL, 0xf83d4e88a37391e2ULL, 0x524b947976b154cdULL,
        0x8660fbdcf0a5215dULL, 0xc1a64535c9f95b29ULL, 0x9dfbf5c4bd79eedbULL, 0xdaf89477c5ec33e7ULL,
        0x69c1af6ca3bf8e51ULL, 0xcbff9635959ed08fULL, 0x521a213d739b1b75ULL, 0x1eb36a91e3315395ULL,
        0x6b19f5471c2037ecULL, 0xbf35c655d4e02133ULL, 0x31a2ed09dea192cfULL, 0x73ad322fb095f9a6ULL,
        0xf6e26c547c2d9975ULL, 0x63fadb25c9c1e0edULL, 0xfa72eb247489f786ULL, 0x6c58a0f2b26e85dbULL,
        0x4eae72c26de852d8ULL, 0xb4110ee2af77957dULL, 0x5705d37d1da30e32ULL, 0x24ce19f79ad852a9ULL,
        0x7e08e1b21a32bb1fULL, 0x666961dda7464f9dULL, 0xf276a4ddc93e1b2aULL, 0x01da62e63812dfe7ULL,
        0x7167c6db5018e68eULL, 0x5988bd629e39895dULL, 0x7bf297666a188a1aULL, 0xd8d9882afb6298e9ULL,
        0x0bfeb4bcc1f9b42cULL, 0x1e1423694f83d95fULL, 0x986df6242a97c9d2ULL, 0x5193b61bd0f6ad09ULL,
        0x085e3d57954e155dULL, 0x04495aa7d5d033efULL, 0x3d1714ce29eac371ULL, 0xc74b0472b7995653ULL,
        0x9905434bd5d2f0f3ULL, 0x63c51fb11acc9475ULL, 0x8d8920ebe62d1775ULL, 0x09e69b7344723cd6ULL
    };

    const Bitboard BISHOP[SQUARE_COUNT] = {
        0x61e93c52c41d555fULL, 0xa0bb0366d163f333ULL, 0xcb3cb91e9051f86cULL, 0xd61c956d35001f9fULL,
        0x6a370f654395984fULL, 0xb8f603525a73f921ULL, 0xb545e286d94e86b9ULL, 0x76a6a894b9a0d92fULL,
        0x88721f25cf66391eULL, 0xaf429dbe0232eba1ULL, 0x5bcf88874734cec2ULL, 0x78cc91a5eb04f5b8ULL,
        0x8569dc5d7b2265c4ULL, 0x3b816c4c8ea92ecfULL, 0x60847177ede2e09eULL, 0x5ba0b8fba46a7388ULL,
        0x88d1b8aa3b9173d6ULL, 0x02795cf5e5683cb1ULL, 0xa7da9e2119631b87ULL, 0x6628d27da90aa1feULL,
        0x3d12a1f3dd855c85ULL, 0x7d9e0a36db420df0ULL, 0x66e77292e8e2a6e0ULL, 0xf90aef5309c832bcULL,
        0x6b507aa44b8eecd2ULL, 0x5c5c0b5e153f2ac5ULL, 0x36c20d46e735a7c9ULL, 0x29f7c34105e6f127ULL,
        0xf33235d88c917c72ULL, 0x344eaad8c97f1315ULL, 0xa82face5ac66a3c8ULL, 0x8e1d5d1de49e438aULL,
        0x8d290bb5cc3ad4d9ULL, 0x6b8e52e9892a7396ULL, 0x13aab8e9ac34ae56ULL, 0x290a7234826dbfafULL,
        0x2ed4a9be42f38d21ULL, 0xe995c6fc4e1824e5ULL, 0xb3331f76345c1ac8ULL, 0xb0918e076ba5e7e2ULL,
        0xef6b061b8eb63c08ULL, 0x895fe38ec4cfe009ULL, 0x60b1e5edd113a723ULL, 0xe6839aad1d378649ULL,
        0x67a852355246d9e7ULL, 0xcc35d5d24312a9f5ULL, 0x1dd5a548f0f255d4ULL, 0xdaa52c19b2bd0d3cULL,
        0x6740d530f95e5479ULL, 0x1716c272f4c47799ULL, 0x218fad51e68edad0ULL, 0xc645cc9bb3b1f094ULL,
        0xa0d91d09aedb3f84ULL, 0xfb286de654a6122bULL, 0x563c0f52ba96941fULL, 0xacdf37014a28bb3aULL,
        0xa856079dd8e8b46eULL, 0x0d1759fc45a8658fULL, 0xb13708b637b1e4aaULL, 0xa1b4d49cf392e949ULL,
        0x708a4a9d5ef92365ULL, 0xbf496c88ce324e96ULL, 0x28c55f3af4d850b6ULL, 0x872c5366171d13faULL
    };
}

namespace Masks {
    const Bitboard FILE[FILE_COUNT] = {
        0x0101010101010101ULL, 0x0202020202020202ULL, 0x0404040404040404ULL, 0x0808080808080808ULL,
        0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL
    };

    const Bitboard RANK[RANK_COUNT] = {
        0x00000000000000FFULL, 0x000000000000FF00ULL, 0x0000000000FF0000ULL, 0x00000000FF000000ULL,
        0x000000FF00000000ULL, 0x0000FF0000000000ULL, 0x00FF000000000000ULL, 0xFF00000000000000ULL
    };

    const Bitboard KING[SQUARE_COUNT] = {
        0x0000000000000302ULL, 0x0000000000000705ULL, 0x0000000000000e0aULL, 0x0000000000001c14ULL,
        0x0000000000003828ULL, 0x0000000000007050ULL, 0x000000000000e0a0ULL, 0x000000000000c040ULL,
        0x0000000000030203ULL, 0x0000000000070507ULL, 0x00000000000e0a0eULL, 0x00000000001c141cULL,
        0x0000000000382838ULL, 0x0000000000705070ULL, 0x0000000000e0a0e0ULL, 0x0000000000c040c0ULL,
        0x0000000003020300ULL, 0x0000000007050700ULL, 0x000000000e0a0e00ULL, 0x000000001c141c00ULL,
        0x0000000038283800ULL, 0x0000000070507000ULL, 0x00000000e0a0e000ULL, 0x00000000c040c000ULL,
        0x0000000302030000ULL, 0x0000000705070000ULL, 0x0000000e0a0e0000ULL, 0x0000001c141c0000ULL,
        0x0000003828380000ULL, 0x0000007050700000ULL, 0x000000e0a0e00000ULL, 0x000000c040c00000ULL,
        0x0000030203000000ULL, 0x0000070507000000ULL, 0x00000e0a0e000000ULL, 0x00001c141c000000ULL,
        0x0000382838000000ULL, 0x0000705070000000ULL, 0x0000e0a0e0000000ULL, 0x0000c040c0000000ULL,
        0x0003020300000000ULL, 0x0007050700000000ULL, 0x000e0a0e00000000ULL, 0x001c141c00000000ULL,
        0x0038283800000000ULL, 0x0070507000000000ULL, 0x00e0a0e000000000ULL, 0x00c040c000000000ULL,
        0x0302030000000000ULL, 0x0705070000000000ULL, 0x0e0a0e0000000000ULL, 0x1c141c0000000000ULL,
        0x3828380000000000ULL, 0x7050700000000000ULL, 0xe0a0e00000000000ULL, 0xc040c00000000000ULL,
        0x0203000000000000ULL, 0x0507000000000000ULL, 0x0a0e000000000000ULL, 0x141c000000000000ULL,
        0x2838000000000000ULL, 0x5070000000000000ULL, 0xa0e0000000000000ULL, 0x40c0000000000000ULL
    };

    /**
     * Masks for rooks on each square excluding squares on the edge of the board.
     */
    const Bitboard ROOK[SQUARE_COUNT] = {
        0x000101010101017EULL, 0x000202020202027CULL, 0x000404040404047AULL, 0x0008080808080876ULL,
        0x001010101010106EULL, 0x002020202020205EULL, 0x004040404040403EULL, 0x008080808080807EULL,
        0x0001010101017E00ULL, 0x0002020202027C00ULL, 0x0004040404047A00ULL, 0x0008080808087600ULL,
        0x0010101010106E00ULL, 0x0020202020205E00ULL, 0x0040404040403E00ULL, 0x0080808080807E00ULL,
        0x00010101017E0100ULL, 0x00020202027C0200ULL, 0x00040404047A0400ULL, 0x0008080808760800ULL,
        0x00101010106E1000ULL, 0x00202020205E2000ULL, 0x00404040403e4000ULL, 0x00808080807E8000ULL,
        0x000101017E010100ULL, 0x000202027C020200ULL, 0x000404047A040400ULL, 0x0008080876080800ULL,
        0x001010106E101000ULL, 0x002020205E202000ULL, 0x004040403E404000ULL, 0x008080807E808000ULL,
        0x0001017E01010100ULL, 0x0002027C02020200ULL, 0x0004047A04040400ULL, 0x0008087608080800ULL,
        0x0010106E10101000ULL, 0x0020205E20202000ULL, 0x0040403E40404000ULL, 0x0080807E80808000ULL,
        0x00017E0101010100ULL, 0x00027C0202020200ULL, 0x00047A0404040400ULL, 0x0008760808080800ULL,
        0x00106E1010101000ULL, 0x00205E2020202000ULL, 0x00403E4040404000ULL, 0x00807E8080808000ULL,
        0x007E010101010100ULL, 0x007C020202020200ULL, 0x007A040404040400ULL, 0x0076080808080800ULL,
        0x006E101010101000ULL, 0x005E202020202000ULL, 0x003E404040404000ULL, 0x007E808080808000ULL,
        0x7E01010101010100ULL, 0x7C02020202020200ULL, 0x7A04040404040400ULL, 0x7608080808080800ULL,
        0x6E10101010101000ULL, 0x5E20202020202000ULL, 0x3E40404040404000ULL, 0x7E80808080808000ULL
    };

    const Bitboard BISHOP[SQUARE_COUNT] = {
        0x0040201008040200ULL, 0x0000402010080400ULL, 0x0000004020100A00ULL, 0x0000000040221400ULL,
        0x0000000002442800ULL, 0x0000000204085000ULL, 0x0000020408102000ULL, 0x0002040810204000ULL,
        0x0020100804020000ULL, 0x0040201008040000ULL, 0x00004020100A0000ULL, 0x0000004022140000ULL,
        0x0000000244280000ULL, 0x0000020408500000ULL, 0x0002040810200000ULL, 0x0004081020400000ULL,
        0x0010080402000200ULL, 0x0020100804000400ULL, 0x004020100A000A00ULL, 0x0000402214001400ULL,
        0x0000024428002800ULL, 0x0002040850005000ULL, 0x0004081020002000ULL, 0x0008102040004000ULL,
        0x0008040200020400ULL, 0x0010080400040800ULL, 0x0020100A000A1000ULL, 0x0040221400142200ULL,
        0x0002442800284400ULL, 0x0004085000500800ULL, 0x0008102000201000ULL, 0x0010204000402000ULL,
        0x0004020002040800ULL, 0x0008040004081000ULL, 0x00100A000A102000ULL, 0x0022140014224000ULL,
        0x0044280028440200ULL, 0x0008500050080400ULL, 0x0010200020100800ULL, 0x0020400040201000ULL,
        0x0002000204081000ULL, 0x0004000408102000ULL, 0x000A000A10204000ULL, 0x0014001422400000ULL,
        0x0028002844020000ULL, 0x0050005008040200ULL, 0x0020002010080400ULL, 0x0040004020100800ULL,
        0x0000020408102000ULL, 0x0000040810204000ULL, 0x00000A1020400000ULL, 0x0000142240000000ULL,
        0x0000284402000000ULL, 0x0000500804020000ULL, 0x0000201008040200ULL, 0x0000402010080400ULL,
        0x0002040810204000ULL, 0x0004081020400000ULL, 0x000A102040000000ULL, 0x0014224000000000ULL,
        0x0028440200000000ULL, 0x0050080402000000ULL, 0x0020100804020000ULL, 0x0040201008040200ULL
    };

    const Bitboard KNIGHT[SQUARE_COUNT] = {
        0x0000000000020400ULL, 0x0000000000050800ULL, 0x00000000000a1100ULL, 0x0000000000142200ULL,
        0x0000000000284400ULL, 0x0000000000508800ULL, 0x0000000000a01000ULL, 0x0000000000402000ULL,
        0x0000000002040004ULL, 0x0000000005080008ULL, 0x000000000a110011ULL, 0x0000000014220022ULL,
        0x0000000028440044ULL, 0x0000000050880088ULL, 0x00000000a0100010ULL, 0x0000000040200020ULL,
        0x0000000204000402ULL, 0x0000000508000805ULL, 0x0000000a1100110aULL, 0x0000001422002214ULL,
        0x0000002844004428ULL, 0x0000005088008850ULL, 0x000000a0100010a0ULL, 0x0000004020002040ULL,
        0x0000020400040200ULL, 0x0000050800080500ULL, 0x00000a1100110a00ULL, 0x0000142200221400ULL,
        0x0000284400442800ULL, 0x0000508800885000ULL, 0x0000a0100010a000ULL, 0x0000402000204000ULL,
        0x0002040004020000ULL, 0x0005080008050000ULL, 0x000a1100110a0000ULL, 0x0014220022140000ULL,
        0x0028440044280000ULL, 0x0050880088500000ULL, 0x00a0100010a00000ULL, 0x0040200020400000ULL,
        0x0204000402000000ULL, 0x0508000805000000ULL, 0x0a1100110a000000ULL, 0x1422002214000000ULL,
        0x2844004428000000ULL, 0x5088008850000000ULL, 0xa0100010a0000000ULL, 0x4020002040000000ULL,
        0x0400040200000000ULL, 0x0800080500000000ULL, 0x1100110a00000000ULL, 0x2200221400000000ULL,
        0x4400442800000000ULL, 0x8800885000000000ULL, 0x100010a000000000ULL, 0x2000204000000000ULL,
        0x0004020000000000ULL, 0x0008050000000000ULL, 0x00110a0000000000ULL, 0x0022140000000000ULL,
        0x0044280000000000ULL, 0x0088500000000000ULL, 0x0010a00000000000ULL, 0x0020400000000000ULL
    };

    /**
     * Masks for black and white pawns on each square. First is for black, second is for white.
     */
    const Bitboard PAWN[PLAYER_COUNT][SQUARE_COUNT] = {
        {
            0x0300000000000000ULL, 0x0700000000000000ULL, 0x0e00000000000000ULL, 0x1c00000000000000ULL,
            0x3800000000000000ULL, 0x7000000000000000ULL, 0xe000000000000000ULL, 0xc000000000000000ULL,
            0x0000000000000003ULL, 0x0000000000000007ULL, 0x000000000000000eULL, 0x000000000000001cULL,
            0x0000000000000038ULL, 0x0000000000000070ULL, 0x00000000000000e0ULL, 0x00000000000000c0ULL,
            0x0000000000000300ULL, 0x0000000000000700ULL, 0x0000000000000e00ULL, 0x0000000000001c00ULL,
            0x0000000000003800ULL, 0x0000000000007000ULL, 0x000000000000e000ULL, 0x000000000000c000ULL,
            0x0000000000030000ULL, 0x0000000000070000ULL, 0x00000000000e0000ULL, 0x00000000001c0000ULL,
            0x0000000000380000ULL, 0x0000000000700000ULL, 0x0000000000e00000ULL, 0x0000000000c00000ULL,
            0x0000000003000000ULL, 0x0000000007000000ULL, 0x000000000e000000ULL, 0x000000001c000000ULL,
            0x0000000038000000ULL, 0x0000000070000000ULL, 0x00000000e0000000ULL, 0x00000000c0000000ULL,
            0x0000000300000000ULL, 0x0000000700000000ULL, 0x0000000e00000000ULL, 0x0000001c00000000ULL,
            0x0000003800000000ULL, 0x0000007000000000ULL, 0x000000e000000000ULL, 0x000000c000000000ULL,
            0x0000030100000000ULL, 0x0000070200000000ULL, 0x00000e0400000000ULL, 0x00001c0800000000ULL,
            0x0000381000000000ULL, 0x0000702000000000ULL, 0x0000e04000000000ULL, 0x0000c08000000000ULL,
            0x0003000000000000ULL, 0x0007000000000000ULL, 0x000e000000000000ULL, 0x001c000000000000ULL,
            0x0038000000000000ULL, 0x0070000000000000ULL, 0x00e0000000000000ULL, 0x00c0000000000000ULL
        },
        {
            0x0000000000000300ULL, 0x0000000000000700ULL, 0x0000000000000e00ULL, 0x0000000000001c00ULL,
            0x0000000000003800ULL, 0x0000000000007000ULL, 0x000000000000e000ULL, 0x000000000000c000ULL,
            0x0000000001030000ULL, 0x0000000002070000ULL, 0x00000000040e0000ULL, 0x00000000081c0000ULL,
            0x0000000010380000ULL, 0x0000000020700000ULL, 0x0000000040e00000ULL, 0x0000000080c00000ULL,
            0x0000000003000000ULL, 0x0000000007000000ULL, 0x000000000e000000ULL, 0x000000001c000000ULL,
            0x0000000038000000ULL, 0x0000000070000000ULL, 0x00000000e0000000ULL, 0x00000000c0000000ULL,
            0x0000000300000000ULL, 0x0000000700000000ULL, 0x0000000e00000000ULL, 0x0000001c00000000ULL,
            0x0000003800000000ULL, 0x0000007000000000ULL, 0x000000e000000000ULL, 0x000000c000000000ULL,
            0x0000030000000000ULL, 0x0000070000000000ULL, 0x00000e0000000000ULL, 0x00001c0000000000ULL,
            0x0000380000000000ULL, 0x0000700000000000ULL, 0x0000e00000000000ULL, 0x0000c00000000000ULL,
            0x0003000000000000ULL, 0x0007000000000000ULL, 0x000e000000000000ULL, 0x001c000000000000ULL,
            0x0038000000000000ULL, 0x0070000000000000ULL, 0x00e0000000000000ULL, 0x00c0000000000000ULL,
            0x0300000000000000ULL, 0x0700000000000000ULL, 0x0e00000000000000ULL, 0x1c00000000000000ULL,
            0x3800000000000000ULL, 0x7000000000000000ULL, 0xe000000000000000ULL, 0xc000000000000000ULL,
            0x0000000000000003ULL, 0x0000000000000007ULL, 0x000000000000000eULL, 0x000000000000001cULL,
            0x0000000000000038ULL, 0x0000000000000070ULL, 0x00000000000000e0ULL, 0x00000000000000c0ULL
        }
    };
}

namespace Shifts {
    const int KING[SQUARE_COUNT] = {
        61, 59, 59, 59, 59, 59, 59, 61,
        59, 56, 56, 56, 56, 56, 56, 59,
        59, 56, 56, 56, 56, 56, 56, 59,
        59, 56, 56, 56, 56, 56, 56, 59,
        59, 56, 56, 56, 56, 56, 56, 59,
        59, 56, 56, 56, 56, 56, 56, 59,
        59, 56, 56, 56, 56, 56, 56, 59,
        61, 59, 59, 59, 59, 59, 59, 61
    };

    const int KNIGHT[SQUARE_COUNT] = {
        62, 61, 60, 60, 60, 60, 61, 62,
        61, 60, 58, 58, 58, 58, 60, 61,
        60, 58, 56, 56, 56, 56, 58, 60,
        60, 58, 56, 56, 56, 56, 58, 60,
        60, 58, 56, 56, 56, 56, 58, 60,
        60, 58, 56, 56, 56, 56, 58, 60,
        61, 60, 58, 58, 58, 58, 60, 61,
        62, 61, 60, 60, 60, 60, 61, 62
    };

    /**
     * Shifts for finding pawn moves indices. First is for black, second is for white.
     */
    const int PAWN[PLAYER_COUNT][SQUARE_COUNT] = {
        {
            0, 0, 0, 0, 0, 0, 0, 0,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            61, 60, 60, 60, 60, 60, 60, 61,
            0, 0, 0, 0, 0, 0, 0, 0
        },
        {
            0, 0, 0, 0, 0, 0, 0, 0,
            61, 60, 60, 60, 60, 60, 60, 61,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            62, 61, 61, 61, 61, 61, 61, 62,
            0, 0, 0, 0, 0, 0, 0, 0
        }
    };
}

namespace Shifts::Reach {
    const int ROOK[SQUARE_COUNT] = {
        52, 53, 53, 53, 53, 53, 53, 52,
        53, 54, 54, 54, 54, 54, 54, 53,
        53, 54, 54, 54, 54, 54, 54, 53,
        53, 54, 54, 54, 54, 54, 54, 53,
        53, 54, 54, 54, 54, 54, 54, 53,
        53, 54, 54, 54, 54, 54, 54, 53,
        53, 54, 54, 54, 54, 54, 54, 53,
        52, 53, 53, 53, 53, 53, 53, 52
    };

    const int BISHOP[SQUARE_COUNT] = {
        58, 59, 59, 59, 59, 59, 59, 58,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 57, 57, 57, 57, 59, 59,
        59, 59, 57, 55, 55, 57, 59, 59,
        59, 59, 57, 55, 55, 57, 59, 59,
        59, 59, 57, 57, 57, 57, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        58, 59, 59, 59, 59, 59, 59, 58
    };
}

namespace Shifts::Moves {
    const int ROOK[SQUARE_COUNT] = {
        56, 55, 55, 54, 54, 55, 55, 56,
        55, 54, 53, 53, 54, 54, 54, 55,
        54, 53, 53, 52, 53, 53, 53, 55,
        54, 53, 52, 52, 52, 53, 53, 55,
        54, 53, 53, 52, 53, 53, 53, 55,
        55, 54, 53, 53, 52, 53, 54, 55,
        55, 54, 54, 53, 53, 54, 55, 56,
        56, 56, 55, 54, 55, 55, 56, 56
    };

    const int BISHOP[SQUARE_COUNT] = {
        60, 60, 59, 59, 59, 59, 60, 60,
        60, 58, 57, 57, 57, 57, 58, 60,
        59, 57, 55, 54, 54, 55, 57, 59,
        59, 57, 55, 53, 53, 55, 57, 59,
        59, 57, 55, 53, 53, 55, 57, 59,
        59, 57, 55, 55, 55, 55, 57, 59,
        60, 58, 57, 57, 57, 57, 58, 60,
        60, 60, 59, 59, 59, 59, 60, 60
    };
}

namespace Shifts::Block {
    const int ROOK[SQUARE_COUNT] = {
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59,
        59, 59, 59, 59, 59, 59, 59, 59
    };

    const int BISHOP[SQUARE_COUNT] = {
        60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 59, 59, 60, 60, 60,
        60, 60, 59, 59, 59, 59, 60, 60,
        60, 59, 59, 59, 59, 59, 59, 60,
        60, 59, 59, 59, 59, 59, 59, 60,
        60, 60, 59, 59, 59, 59, 60, 60,
        60, 60, 60, 59, 59, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 60, 60
    };
}

#endif