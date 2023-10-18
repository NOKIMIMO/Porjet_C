//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "visual.h"

void printAt(int x, int y, char *str){
    printf("\033[%d;%dH%s", y, x, str);
}
void clearAll(){
    printf("\033[2J");
}
void moveCursor(int x, int y){
    printf("\033[%d;%dH", y, x);
}

void buildBoxInteraction(int width, int height,int x, int y){
    moveCursor(x,y);

    printf("╔");
    for (int i = 1; i < width - 1; i++){
        printf("═");
    }
    printf("╗\n");

    // Print the sides of the box
    for (int i = 1; i < height - 1; i++){
        printf("║");
        for (int j = 1; j < width - 1; j++){
            printf(" ");  // Space inside the box
        }
        printf("║\n");
    }

    // Print the bottom row of the box
    printf("╚");
    for (int i = 1; i < width - 1; i++){
        printf("═");
    }
    printf("╝\n");
}
void buildInteraction(int x, int y, char **str, int selectedIndex, int itemCount){
    for (int i = 0; i < itemCount; i++){
        printf("\033[%d;%dH", y + i, x);
        if (i == selectedIndex){
            printf("> %s", str[i]);
        } else {
            printf("* %s", str[i]);
        }
    }
}

void printLife(int x, int y, int currentLife, int maxLife){
    int currentBars = currentLife / 10;
    int maxBars = maxLife / 10;

    printf("\033[%d;%dH", y, x);
    printf("HP: ");

    // Set the text color to red (ANSI escape code)
    printf("\033[31m");

    for (int i = 0; i < currentBars; i++){
        printf("█");
    }

    for (int i = 0; i < maxBars - currentBars; i++){
        printf("#");
    }
    // Reset text color to default (ANSI escape code)
    printf("\033[0m");
    printf(" %d/%d", currentLife, maxLife);
    moveCursor(0,30);
}
void killVisual(){
    // Restore the terminal
    system("stty icanon");
    // Restore the original terminal state
    printf("\033[?1049l"); // Exit alternate screen
    clearAll();
}

int visual(){
    printf("\033[?1049h\033[H");
    system("stty -icanon min 1");

    clearAll();
    printLife(3,2,80,100);

    buildBoxInteraction(60,10,0,10);
    char *options[] = {
            "Option 1",
            "Option 2",
            "Option 3",
            "Option 4"
    };
    int selectedIndex = 0;
    int itemCount = sizeof(options) / sizeof(options[0]);
    buildInteraction(5, 12, options, selectedIndex, itemCount);

    while (1) {
        moveCursor(50,50);
        int c = getchar();
        if (c == 10 || c == 13) {  // Check for the ENTER key
            // Perform some action based on selectedIndex, e.g., execute the selected option
            printLife(3,2,40,100);
        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex--;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                } else if (arrowKey == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                }
            }else{
                killVisual();
                printf("Key pressed %d \n",c);
                break;
            }
        } else if (c == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
            selectedIndex--;
            buildInteraction(10, 5, options, selectedIndex, itemCount);
        } else if (c == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
            selectedIndex++;
            buildInteraction(10, 5, options, selectedIndex, itemCount);
        }
    }
    return 0;
}