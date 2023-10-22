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
void buildInteraction(int x, int y, char **str, int selectedIndex, int itemCount) {
    for (int i = 0; i < itemCount; i++) {
        if (str[i] == NULL || str[i][0] == '\0' || str[i][0] == '\n') {
            // Skip empty or NULL entries
            continue;
        }
        printf("\033[%d;%dH", y + i, x);
        if (i == selectedIndex) {
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
void attackVisual(Monster * monster,Player * player){
    clearAll();
    int selectedIndex = 0;
    char *options[] = {
            "10",
            "20",
            "30",
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    while (1) {
        printLife(3,2, get_vie_P(player),100);
        printLife(3,4, get_vie_M(monster),100);
        buildBoxInteraction(60,10,0,10);
        buildInteraction(5, 12, options, selectedIndex, itemCount);
        moveCursor(50, 50);
        int c = getchar();
        if (c == 10 || c == 13) {
            // Check for the ENTER key
            switch (selectedIndex) {
                case 0:
                    set_vie_M(monster,get_vie_M(monster)- get_player_dmg(player,monster));
                    return;
                case 1:
                    set_vie_M(monster,get_vie_M(monster)-20);
                    return;
                case 2:
                    set_vie_M(monster,get_vie_M(monster)-30);
                    return;
                default:
                    break;
            }
        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex--;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                    moveCursor(30,20);
                } else if (arrowKey == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                    moveCursor(30, 20);
                }
            } else {
                break;
            }
        }
        wait(100);
        clearAll();
    }
}
void skillVisual(){

}
void itemVisual(){

}


int visual(){
    Player player= create_player(100,100,100,100,10,5,
                                 create_weapon( 10, 5),
                                 NULL,
                                 create_armor( 10, 5, 5, 5, chest_piece),
                                 NULL,
                                 NULL);


    Monster monster = create_monster();

    printf("\033[?1049h\033[H");
    system("stty -icanon min 1");
    clearAll();
    int selectedIndex = 0;
    char *options[] = {
            "Attack",
            "Skill",
            "Items",
            "Flee"
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    while (1) {
        printLife(3,2, get_vie_P(&player),100);
        printLife(3,4, get_vie_M(&monster),100);
        buildBoxInteraction(60,10,0,10);
        buildInteraction(5, 12, options, selectedIndex, itemCount);
        moveCursor(50, 50);
        int c = getchar();

        if (c == 10 || c == 13) {  // Check for the ENTER key
            switch (selectedIndex) {
                case 0:
                    attackVisual(&monster,&player);
                    break;
                case 1:
                    skillVisual();
                    break;
                case 2:
                    itemVisual();
                    break;
                case 3:
                    killVisual();
                    break;
                default:
                    break;
            }
        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex--;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                    moveCursor(30,20);
                } else if (arrowKey == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                    buildInteraction(5, 12, options, selectedIndex, itemCount);
                    moveCursor(30, 20);
                }
            } else {
                killVisual();
                break;
            }
        }


        wait(100);
        clearAll();
    }

    return 0;
}
