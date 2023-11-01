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
    clearFromTo(x, y, x + 10, y + 4);
    moveCursor(x, y);
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
void printMana(int x, int y, int currentMana, int maxMana){
    int currentBars = currentMana / 10;
    int maxBars = maxMana / 10;

    printf("\033[%d;%dH", y, x);
    printf("MP: ");

    // Set the text color to blue (ANSI escape code)
    printf("\033[34m");

    for (int i = 0; i < currentBars; i++){
        printf("█");
    }

    for (int i = 0; i < maxBars - currentBars; i++){
        printf("#");
    }
    // Reset text color to default (ANSI escape code)
    printf("\033[0m");
    printf(" %d/%d", currentMana, maxMana);
    moveCursor(0,30);
}
void clearAt(int x, int y) {
    printf("\033[%d;%dH ", y, x);
}
void clearFromTo(int x1, int y1, int x2, int y2){
    for (int i = y1; i <= y2; i++){
        for (int j = x1; j <= x2; j++){
            clearAt(j, i);
        }
    }
}
void buildBasic(Player player){
    printLife(3,2, get_vie_P(&player),100);
    printMana(3,3, get_mana_P(&player),100);
    buildBoxInteraction(60,10,0,13);
}
void showDeathMessage(int x, int y){
    clearFromTo(x,y,x+50,y+5);
    moveCursor(x,y);
    printf("Vous etes mort");
    fflush(stdout);
    wait(2000);
}
void killVisual(){
    // Restore the terminal
    system("stty icanon");
    // Restore the original terminal state
    printf("\033[?1049l"); // Exit alternate screen
    clearAll();
}
void showDmgReceived(int value,Monster * monster,int x, int y){
    clearFromTo(x,y,x+50,y+5);
    moveCursor(x,y);
    printf("le monstre ");
    printf("%s",get_name_M(monster));
    printf(" vous a attacker pour ");
    printf("-%d DMG",value);
    fflush(stdout);
    wait(1200);
}
void showHPReceived(int value, int x, int y){

}
int attackVisual(Monster * monster,Player * player, int nb_monster){
    int selectedIndex = 0;
    char **options = malloc(sizeof(char*)*nb_monster+1);
    Monster **monster_alive = malloc(sizeof(Monster*) * nb_monster);
    int nb_monster_alive = 0;
    for (int i = 0; i < nb_monster; i++) {
        if (strcmp(get_name_M(&monster[i]), "###DEAD###") != 0) {
            // Monster is alive, store its address in the monster_alive array.
            monster_alive[nb_monster_alive] = &monster[i];
            nb_monster_alive++; // Increment the count of living monsters.
        }
    }
    for (int i = 0; i < nb_monster_alive; i++) {
        options[i] = get_name_M(monster_alive[i]);
    }
    options[nb_monster_alive] = "Back";
    while (1) {
        buildInteraction(interaction_x, interaction_y, options, selectedIndex, nb_monster_alive+1);
        moveCursor(50, 50);
        int c = getchar();
        if (c == ' ') {
            // Check for the SPACE key
            if(selectedIndex==nb_monster_alive){
                free(options);
                free(monster_alive);
                return 0;
            }else{
                set_vie_M((monster_alive)[selectedIndex],get_vie_M((monster_alive)[selectedIndex])- get_player_dmg(player,(monster_alive)[selectedIndex]));
                if(get_vie_M(monster_alive[selectedIndex])<=0){
                    *monster_alive[selectedIndex] = dead_monster();
                }
                free(options);
                free(monster_alive);
                return 1;
            }
        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex--;
                    buildInteraction(interaction_x, interaction_y, options, selectedIndex, nb_monster_alive+1);
                    moveCursor(30,20);
                } else if (arrowKey == 66 && selectedIndex < nb_monster ) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                    buildInteraction(interaction_x, interaction_y, options, selectedIndex, nb_monster_alive+1);
                    moveCursor(30, 20);
                }
            } else {
                break;
            }
        }

        wait(100);
//        clearAll();
    }
    free(options);
    return 0;
}
int skillVisual(Monster * monster,Player * player){

}
int itemVisual(Monster * monster,Player * player){

}

void buildEnnemies(int x, int y, Monster * monster) {
    char* monster_name = get_name_M(monster);
    if (monster_name == NULL) {
        // Gérer le cas où get_name_M renvoie NULL (une chaîne invalide)
        monster_name="monstre_inconnu";
    }

    //max size 9
    char entier_str[9];
    moveCursor(x, y);
    printf("╔═════");
    printf("%s", monster_name);
    int size = strlen(monster_name);
    for (int i = 0; i < 12 - size; i++) {
        printf("═");
    }
    printf("╗");
    y++;
    moveCursor(x,y);
    printf("║                 ║");
    y++;
    moveCursor(x,y);
    printf("║");
    snprintf(entier_str, sizeof(get_vie_M(monster)), "%d", get_vie_M(monster));
    printf("  HP: %s", entier_str);
    size = strlen(entier_str);
    for (int i = 0; i < 11 - size; i++) {
        printf(" ");
    }
    printf("║");
    y++;
    moveCursor(x,y);
    printf("║                 ║");
    y++;
    moveCursor(x,y);
    printf("╚═════════════════╝");

}
int visual(){
    Player player= create_player(100,100,100,100,10,create_weapon( 100),
                                 NULL,
                                 create_armor( 10, 5, 5, chest_piece),
                                 NULL,
                                 NULL);

    //3 monstre max
    int nb_monster = 2;
    Monster * monster_list = malloc(sizeof(Monster)*nb_monster);
    for (int i = 0; i < nb_monster; i++) {
        monster_list[i] = create_monster();
    }

    printf("\033[?1049h\033[H");
    system("stty -icanon min 1");
//    clearAll();
    int selectedIndex = 0;
    char *options[] = {
            "Attack",
            "Skill",
            "Items",
            "Flee"
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    int action= get_ac_P(&player);
    while (1) {
        //build all
        buildBasic(player);
        //build ennemies
        for (int i = 0; i < nb_monster; i++) {
            if(strcmp(get_name_M(&monster_list[i]),"###DEAD###")!=0){
                buildEnnemies(mob_pos_x+(i*20),mob_pos_y,&monster_list[i]);
            }else{
                clearFromTo(mob_pos_x+(i*20),mob_pos_y,mob_pos_x+(i*20)+20,mob_pos_y+5);
            }
        }
        //build interaction
        buildInteraction(interaction_x, interaction_y, options, selectedIndex, itemCount);
        moveCursor(50, 50);
        int c = getchar();
        if (c == ' ') {  // Check for the ENTER key
            switch (selectedIndex) {
                case 0:
                    action -= attackVisual(monster_list,&player,nb_monster);
                    break;
                case 1:
                    action -= skillVisual(monster_list,&player);
                    break;
                case 2:
                    action -= itemVisual(monster_list,&player);
                    break;
                case 3:
                    //killVisual();
                    clearAll();
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
        if(is_monster_list_empty(monster_list,nb_monster)){
            //plus de monstre
            //TODO: faire naviguation

        }

        //ennemy turn
        if(action ==0){
            for (int i = 0; i < nb_monster; ++i) {
                if(strcmp(get_name_M(&monster_list[i]),"###DEAD###")!=0){
                    int dmg_received = monster_attack(&player,&monster_list[i]);
                    showDmgReceived(dmg_received,&monster_list[i],interaction_x,interaction_y);
                    if(get_vie_P(&player)<=0){
                        showDeathMessage(interaction_x,interaction_y);
                        free(monster_list);
                        killVisual();
                        return 1;
                    }
                }
            }
            action += get_ac_P(&player);
        }

    }
    //exit par player
    clearAll();
    moveCursor(0,0);
    printf("Vous avez quit");
    return 0;
}
