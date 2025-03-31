#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() {
    POINT cursor_pos;
    while (1) {
        char ch;
        if (GetCursorPos(&cursor_pos)) {
            int quadrant; // Variável para armazenar o número do quadrante

            if (cursor_pos.x <= 799 && cursor_pos.y <= 449) {
                quadrant = 1; // Quadrante A
            }
            else if (cursor_pos.x >= 800 && cursor_pos.y <= 449) {
                quadrant = 2; // Quadrante B
            }
            else if (cursor_pos.x <= 799 && cursor_pos.y >= 450) {
                quadrant = 3; // Quadrante C
            }
            else if (cursor_pos.x >= 800 && cursor_pos.y >= 450) {
                quadrant = 4; // Quadrante D
            }

            // Usando switch para determinar o quadrante
            switch (quadrant) {
                case 1:
                    printf("Posição do Mouse: quadrante A\n");
                    break;
                case 2:
                    printf("Posição do Mouse: quadrante B\n");
                    break;
                case 3:
                    printf("Posição do Mouse: quadrante C\n");
                    break;
                case 4:
                    printf("Posição do Mouse: quadrante D\n");
                    break;
                default:
                    printf("Posição do Mouse: fora da tela\n");
                    break;
            }
        }

        Sleep(100); // Ajuste o tempo de espera conforme necessário

        if (kbhit()) {
            ch = getch();
            if (ch == 27) // Esc para sair do loop
                break;
        }
    }
    return 0;
}
