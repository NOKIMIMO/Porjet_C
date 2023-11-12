//
// Created by ACER PREDATOR on 01/11/2023.
//
#include "splashScreen.h"

int splashScreen() {
    printf("\033[?1049h\033[H");
    system("stty -icanon min 1");
    char *options[] = {
            "New game",
            "Saves",
            "Exit",
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    int selectedIndex = 0;
    int x = 1, y = 4;

    printStrAt(x-1,y-1,"Doomdephts");
    buildBoxInteraction(20, 7, x, y);
    while (1) {
        buildInteraction(x+2, y+2, x+4, y+3, options, selectedIndex, itemCount);
        moveCursor(50, 50);
        int c = getchar();
        if (c == ' ') {  // Check for the SPACE key
            switch (selectedIndex) {
                case 0 :
                    return 1;
                case 1 :
                    return 2;
                case 2 :
                    printf("Vous avez quitté\n");
                    return 0;
                default:
                    break;
            }
        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex--;
                } else if (arrowKey == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                }
            } else {
                killVisual();
                break;
            }
        }
        wait(100);
    }
}