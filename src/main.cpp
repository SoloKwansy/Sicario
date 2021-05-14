
#include <iostream>
#include "movegen.hpp"
#include "uci.hpp"
#include "game.hpp"

namespace Run {
    void showStartUp() {
        std::cout << '\n' << NAME << " (" << VERSION << ")\n";
        std::cout << "By " << AUTHOR << '\n';
        std::cout << "Acknowledgments:\n";
        std::cout << "    " << CHESS_PROGRAMMING << '\n';
        std::cout << "    " << STOCKFISH << '\n';
        std::cout << "    " << BLUE_FEVER_SOFT << '\n';
        std::cout << '\n';
    }

    void showLogo() {
        std::cout << "\n  _______  _________  _______   ________   ________  _________  _______ \n";
        std::cout << " (  ____ \\ )__   __( (  ____ \\ (  ____  ) (  ____  ) \\__   __/ (  ___  )\n";
        std::cout << " | (    \\/    ) (    | (    \\/ | (    ) | | (    ) |    ) (    | (   ) |\n";
        std::cout << " | (_____     | |    | |       | (____) | | (____) |    | |    | |   | |\n";
        std::cout << " (_____  )    | |    | |       |  ____  | |     ___)    | |    | |   | |\n";
        std::cout << "       ) |    | |    | |       | (    ) | | (\\ (        | |    | |   | |\n";
        std::cout << " /\\____) |  __) (__  | (____/\\ | )    ( | | ) \\ \\___ ___) (___ | (___) |\n";
        std::cout << " \\_______) /_______\\ (_______/ |/      \\| |/   \\___/ )_______( (_______)\n";
        std::cout << "\n ======================== Genesis v1.0.0-alpha =========================\n\n";
    }

    void init() {
        showLogo();
        showStartUp();
        std::cout << std::flush;
        std::string input("");
        while (input != "uci" && input != "nouci" && input != "q" && input != "quit" && input != "exit") {
            std::getline(std::cin, input);
            if (input == "uci") {
                UCI::init(input);
            } else if (input == "nouci") {
                Play::init(input);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    Run::init();
    return 0;
}
