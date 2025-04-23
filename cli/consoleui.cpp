#include "ConsoleUI.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

ConsoleUI::ConsoleUI() {
    configureGame();
    game = std::make_unique<Game>(size, tileType);
    game->start();
}

void ConsoleUI::run() {
    drawBoard();
    handleInput();
}

void ConsoleUI::configureGame() {
    char mode;
    do {
        std::cout << "Wybierz tryb gry:\n";
        std::cout << "0 - Tryb podstawowy\n";
        std::cout << "1 - Tryb z podświetlaniem ostatniego ruchu\n";
        std::cin >> mode;

        switch (mode) {
        case '0':
            tileType = TileType::Animated;
            break;
        case '1':
            tileType = TileType::Moving;
            break;
        default:
            std::cout << "Wybrano nieprawidłowy typ gry. Spróbuj ponownie.\n";
            std::cout << std::endl;
            mode = 'a';
            break;
        }
    } while (mode != '0' && mode != '1');

    do {
        std::cout << "Wybierz rozmiar planszy (3–7): ";
        std::cin >> size;
        std::cout << std::endl;
        if (size < 3 || size > 7) {
            std::cout << "Niepoprawny rozmiar. Dozwolone wartości to 3, 4, 5, 6 lub 7.\n";
        }
    } while (size < 3 || size > 7);
}

void ConsoleUI::drawBoard() const {
    game->getBoard().draw();
    std::cout << "Ilość wykonanych ruchów: " << game->getMoveCount() << "\n\n";
}

void ConsoleUI::handleInput() {
    char n;

    while (!game->isWon()) {
        std::cout << "Menu: r - reset gry, x - zakończ grę\n";
        std::cout << "Ruch: w - góra, s - dół, a - lewo, d - prawo\n> ";
        std::cout << std::endl;
        std::cin >> n;

        switch (n) {
        case 'r':
            game->reset();
            std::cout << "\nResetowano układankę\n";
            break;
        case 'x':
            std::cout << "Zakończono grę.\n";
            return;
        case 'w':
        case 's':
        case 'a':
        case 'd': {
            Direction d;
            switch (n) {
            case 'w': d = Direction::Up; break;
            case 's': d = Direction::Down; break;
            case 'a': d = Direction::Left; break;
            case 'd': d = Direction::Right; break;
            }

            if (!game->move(d)) {
                std::cout << "Nieprawidłowy ruch!\n";
            }
            break;
        }
        default:
            std::cout << "Nieznana komenda.\n";
        }

        drawBoard();
    }

    std::cout << "Układanka ułożona poprawnie!\n";
}

void ConsoleUI::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
