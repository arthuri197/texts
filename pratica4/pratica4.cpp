#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() {
    POINT cursor_pos;
    while (1) {
        char ch;
        if (GetCursorPos(&cursor_pos)) {
             if (cursor_pos.x <= 799 && cursor_pos.y <= 449) {
                printf("Posição do Mouse: quadrante A\n");
            }
            else if (cursor_pos.x >= 800 && cursor_pos.y <= 449) {
                printf("Posição do Mouse: quadrante B\n");
            }
            else if (cursor_pos.x <= 799 && cursor_pos.y >= 450) {
                printf("Posição do Mouse: quadrante C\n");
            }
            else if (cursor_pos.x >= 800 && cursor_pos.y >= 450) {
                printf("Posição do Mouse: quadrante D\n");
            }
        }
                 
        Sleep(100); // ajusta o tempo de espera conforme necessário

        if (kbhit()) {
            ch = getch();
            if (ch == 27) // Esc para sair do loop
                break;
        }
    }
return 0;
}