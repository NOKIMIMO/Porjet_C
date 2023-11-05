//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "visual.h"

void printStrAt(int x, int y, char *str){
    printf("\033[%d;%dH%s", y, x, str);
}
void printCharAt(int x, int y, char str){
    printf("\033[%d;%dH%c", y, x, str);
}
void printIntAt(int x, int y, int val){
    printf("\033[%d;%dH%d", y, x, val);
}
void printCharIndices(int x,int y,const char *str) {
    moveCursor(x, y);
    for (int i = 0; str[i] != '\0'; i++) {
        if (i % 7 == 0 && i != 0) {
            y++;
            moveCursor(x, y);
        }
        if (str[i] == '\n' ) {
            printf("%d : 'end' | ", i);
            continue;
        }
        printf("%d : '%c' | ", i, str[i]);
    }
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
    printf("╗");
    y++;
    moveCursor(x,y);
    // Print the sides of the box
    for (int i = 1; i < height - 1; i++){
        printf("║");
        for (int j = 1; j < width - 1; j++){
            printf(" ");  // Space inside the box
        }
        printf("║");
        y++;
        moveCursor(x,y);
    }

    // Print the bottom row of the box
    printf("╚");
    for (int i = 1; i < width - 1; i++){
        printf("═");
    }
    printf("╝");
    y++;
    moveCursor(x,y);
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
void printFromToLine(int x,int y,int width,char str){
    moveCursor(x,y);
    for (int j = 0; j < width; ++j) {
        printf("%c",str);
    }

}
void printFromToShape(int x1,int y1,int x2,int y2,char * str){
    for (int i = y1; i <= y2; i++){
        for (int j = x1; j <= x2; j++){
            printStrAt(j, i, str);
        }
    }

}
void buildBasic(Player player){
    printLife(3,2, get_vie_P(&player),100);
    printMana(3,3, get_mana_P(&player),100);
    buildBoxInteraction(60,10,interaction_x-5,interaction_y-2);
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
void printMap(int x,int y, int ** map){
    int start_x=x;
    int start_y=y;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j <7 ; ++j) {
            if(map[i][j]==0){
                printFromToShape(x+1,y+1,x+3,y+3,"█");
                x+=3;
            }else if(map[i][j]==1){
                printFromToShape(x+1,y+1,x+3,y+3,"░");
                x+=3;
            }else if(map[i][j]==2){
                printFromToShape(x+1,y+1,x+3,y+3,"▓");
                x+=3;
            }else if(map[i][j]==3){
                printFromToShape(x+1,y+1,x+3,y+3,"▒");
                x+=3;
            }
        }
        y+=3;
        x= start_x;
        moveCursor(x+3,y+1);
    }
}
void itemInteraction(int x,int y, Player * player){
    buildBoxInteraction(30,23,32+x-2,y-2);
    //get hp potion number
    int hp_potion_number = get_potion_type_I(player,"Potion de vie");
    //get mana potion number
    int mana_potion_number = get_potion_type_I(player,"Potion de mana");
    //get potion double number
    int potion_double_number = get_potion_type_I(player,"Potion double");

    // "Potion de vie x hp_potion_number"
    char po_hp[50];
    sprintf(po_hp,"Potion de vie x %d",hp_potion_number);
    // "Potion de mana x mana_potion_number"
    char po_mana[50];
    sprintf(po_mana,"Potion de mana x %d",mana_potion_number);
    // "Potion double x potion_double_number"
    char po_double[50];
    sprintf(po_double,"Potion double x %d",potion_double_number);

    char *options2[] = {
            po_hp,
            po_mana,
            po_double,
            "Back"
    };

    int itemCount2 = sizeof(options2) / sizeof(options2[0]);
    int selectedIndex2 = 0;
    while(1){
        buildInteraction(32+x, y, options2, selectedIndex2, itemCount2);
        moveCursor(50, 50);
        int c2 = getchar();
        if (c2 == ' ') {  // Check for the SPACE key
            switch (selectedIndex2) {
                case 0:
                    //potion de vie
                    if(get_size_LI(get_listItem_P(player))>0){
                        int size = get_size_LI(get_listItem_P(player));
                        //si il y a des potions dans l'inventaire
                        for (int i = 0; i < size; ++i) {
                            if(strcmp(get_name_I(getItemFromListItem(get_listItem_P(player),i)),"Potion de vie")==0){
                                set_vie_P(player,get_vie_P(player)+get_hp_I(getItemFromListItem(get_listItem_P(player),i)));
                                printLife(3,2, get_vie_P(player),100);
                                removeItemFromListItem(get_listItem_P(player),i);
                                return;
                            }
                        }
                    }
                    break;
                case 1:
                    //potion de mana
                    if(get_size_LI(get_listItem_P(player))>0){
                        int size = get_size_LI(get_listItem_P(player));
                        //si il y a des potions dans l'inventaire
                        for (int i = 0; i < size; ++i) {
                            if(strcmp(get_name_I(getItemFromListItem(get_listItem_P(player),i)),"Potion de mana")==0){
                                set_mana_P(player, get_mana_P(player)+get_mana_I(getItemFromListItem(get_listItem_P(player),i)));
                                printMana(3,3, get_mana_P(player),100);
                                removeItemFromListItem(get_listItem_P(player),i);
                                return;
                            }
                        }
                    }
                    break;
                case 2:
                    //potion double
                    if(get_size_LI(get_listItem_P(player))>0){
                        int size = get_size_LI(get_listItem_P(player));
                        //si il y a des potions dans l'inventaire
                        for (int i = 0; i < size; ++i) {
                            if(strcmp(get_name_I(getItemFromListItem(get_listItem_P(player),i)),"Potion double")==0){
                                set_vie_P(player,get_vie_P(player)+get_hp_I(getItemFromListItem(get_listItem_P(player),i)));
                                set_mana_P(player, get_mana_P(player)+get_mana_I(getItemFromListItem(get_listItem_P(player),i)));
                                printLife(3,2, get_vie_P(player),100);
                                printMana(3,3, get_mana_P(player),100);
                                removeItemFromListItem(get_listItem_P(player),i);
                                return;
                            }
                        }
                    }
                    break;
                case 3:
                    //back
                    clearFromTo(32+x-2,y-2,32+x+30,y+23);
                    return;
                default:
                    break;
            }
        } else if (c2 == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                if (arrowKey == 65 && selectedIndex2 > 0) {  // Up arrow key (ASCII 65)
                    selectedIndex2--;
                    buildInteraction(32+x, y, options2, selectedIndex2, itemCount2);
                    moveCursor(30,20);
                } else if (arrowKey == 66 && selectedIndex2 < itemCount2 - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex2++;
                    buildInteraction(32+x, y, options2, selectedIndex2, itemCount2);
                    moveCursor(30, 20);
                }
            } else {
                break;
            }
        }
        wait(100);
    }
}
void buildInventory(int x, int y, Player * player){
    clearAll();
    printLife(3,2, get_vie_P(player),100);
    printMana(3,3, get_mana_P(player),100);
    buildBoxInteraction(30,23,x-2,y-2);
    char const *options[] = {
            "Weapon",
            "Head Piece",
            "Chest Piece",
            "Leg Piece",
            "Ring",
            "Items",
            "Back"
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    int selectedIndex = 0;
    while (1) {
        buildInteraction(x, y, options, selectedIndex, itemCount);
        moveCursor(50, 50);
        int c = getchar();
        if (c == ' ') {  // Check for the SPACE key
            switch (selectedIndex) {
                case 0:
                    //weapon
                    break;
                case 1:
                    //head piece
                    break;
                case 2:
                    //chest piece
                    break;
                case 3:
                    //leg piece
                    break;
                case 4:
                    //ring
                    break;
                case 5:
                    //Items
                    itemInteraction(x,y,player);
                    clearFromTo(32+x-2,y-2,32+x+30,y+23);
                    break;
                case 6:
                    //back
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
                    buildInteraction(x, y, options, selectedIndex, itemCount);
                    moveCursor(30,20);
                } else if (arrowKey == 66 && selectedIndex < itemCount - 1) {  // Down arrow key (ASCII 66)
                    selectedIndex++;
                    buildInteraction(x, y, options, selectedIndex, itemCount);
                    moveCursor(30, 20);
                }
            } else {
                break;
            }
        }

        wait(100);
//        clearAll();
    }
}
void buildMapGraph(int x,int y,Player player,int ** map){
    clearAll();
    printf("\033[?1049h\033[H");
    system("stty -icanon min 1");
    printLife(3,2, get_vie_P(&player),100);
    printMana(3,3, get_mana_P(&player),100);
    buildBoxInteraction(60,23,x,y);
    int cpt=0;
    x++;
    int start_x=x;
    int start_y=y;
    printMap(start_x,start_y,map);

    while (1) {
        moveCursor((get_pos_x_P(&player)+1)*3,(get_pos_y_P(&player)+1)*3+1);
        int old_pos_x = get_pos_x_P(&player);
        int old_pos_y = get_pos_y_P(&player);

        //print player with red ■
        printf("\033[31m");
        printf("■");
        //go back to white
        printf("\033[0m");
        moveCursor(50, 50);

        int c = getchar();
        if (c == ' ') {  // Check for the SPACE key
            printf("\032[31m");
            printIntAt(7,33,map[get_pos_y_P(&player)-1][get_pos_x_P(&player)-1]);
            //go back to white
            printf("\033[0m");

        } else if (c == 27) {  // Check for the ESC key
            int nextChar = getchar();  // Read the next character in the escape sequence
            if (nextChar == 91) {  // Check for the [ character (indicating an arrow key)
                int arrowKey = getchar();  // Read the character representing the arrow key
                switch (arrowKey) {
                    case 65:
                        // Up arrow key (ASCII 65)
                        //check if not out of bound and if not wall
                        if(get_pos_y_P(&player)>0 && map[get_pos_y_P(&player)-2][get_pos_x_P(&player)-1]!=0){

                            set_pos_y_P(&player,get_pos_y_P(&player)-1);

                            if(map[old_pos_y-1][get_pos_x_P(&player)-1]==0){
                                //celui n'est sensé jamais arriver mais qui c'est
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"█");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==1){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"░");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==2){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"▓");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==3){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"▒");
                            }

                        }
                        break;
                    case 66:
                        // Down arrow key (ASCII 66)
                        if(get_pos_y_P(&player)<7 && map[get_pos_y_P(&player)][get_pos_x_P(&player)-1]!=0){

                            set_pos_y_P(&player,get_pos_y_P(&player)+1);

                            if(map[old_pos_y-1][get_pos_x_P(&player)-1]==0){
                                //celui n'est sensé jamais arriver mais qui c'est
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"█");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==1){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"░");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==2){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"▓");
                            }else if(map[old_pos_y-1][get_pos_x_P(&player)-1]==3){
                                printStrAt((get_pos_x_P(&player)+1)*3,(old_pos_y+1)*3+1,"▒");
                            }

                        }
                        break;
                    case 67:
                        // Right arrow key
                        if(get_pos_x_P(&player)<7 && map[get_pos_y_P(&player)-1][get_pos_x_P(&player)]!=0){

                            set_pos_x_P(&player,get_pos_x_P(&player)+1);

                            if(map[get_pos_y_P(&player)-1][old_pos_x-1]==0){
                                //celui n'est sensé jamais arriver mais qui c'est
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"█");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==1){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"░");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==2){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"▓");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==3){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"▒");
                            }

                        }
                        break;
                        // Left arrow key
                    case 68:
                        if(get_pos_x_P(&player)>0 && map[get_pos_y_P(&player)-1][get_pos_x_P(&player)-2]!=0){

                            set_pos_x_P(&player,get_pos_x_P(&player)-1);
                            if(map[get_pos_y_P(&player)-1][old_pos_x-1]==0){
                                //celui n'est sensé jamais arriver mais qui c'est
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"█");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==1){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"░");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==2){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"▓");
                            }else if(map[get_pos_y_P(&player)-1][old_pos_x-1]==3){
                                printStrAt((old_pos_x+1)*3,(get_pos_y_P(&player)+1)*3+1,"▒");
                            }
                        }
                        break;

                }
            } else {
                break;
            }
        }else if(c == 'i'){
            //TODO: inventaire
            buildInventory(5,9,&player);
            clearAll();
            printLife(3,2, get_vie_P(&player),100);
            printMana(3,3, get_mana_P(&player),100);
            buildBoxInteraction(60,23,x,y);
            printMap(start_x,start_y,map);
        }
        if(map[get_pos_y_P(&player)-1][get_pos_x_P(&player)-1]==1){
            clearAll();
            //combat
            int ret = visual(&player);
            if(ret==1) {
                //le joueur est mort
                showDeathMessage(7, 35);
                killVisual();
                free(map);
                return;
            }else if(ret == 3) {
                //fuite du joueur
                printLife(3,2, get_vie_P(&player),100);
                printMana(3,3, get_mana_P(&player),100);
                buildBoxInteraction(60,23,x,y);
                printMap(start_x,start_y,map);
                set_pos_x_P(&player,old_pos_x);
                set_pos_y_P(&player,old_pos_y);
            }else{
                mofidyMapAtPos(get_pos_x_P(&player)-1,get_pos_y_P(&player)-1,map,2);
                printLife(3,2, get_vie_P(&player),100);
                printMana(3,3, get_mana_P(&player),100);
                buildBoxInteraction(60,23,x,y);
                printMap(start_x,start_y,map);
            }
        }

        wait(100);
    }

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
int visual(Player * player){


    //3 monstre max
    int nb_monster = get_RNG_int(1,3);
    Monster * monster_list = malloc(sizeof(Monster)*nb_monster);
    for (int i = 0; i < nb_monster; i++) {
        monster_list[i] = create_monster();
    }

//    printf("\033[?1049h\033[H");
//    system("stty -icanon min 1");
//    clearAll();
    int selectedIndex = 0;
    char *options[] = {
            "Attack",
            "Skill",
            "Items",
            "Flee"
    };
    int itemCount = sizeof(options) / sizeof(options[0]);
    int action= get_ac_P(player);
    while (1) {
        //build all
        buildBasic(*player);
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
        if (c == ' ') {  // Check for the SPACE key
            switch (selectedIndex) {
                case 0:
                    action -= attackVisual(monster_list,player,nb_monster);
                    break;
                case 1:
                    action -= skillVisual(monster_list,player);
                    break;
                case 2:
                    action -= itemVisual(monster_list,player);
                    break;
                case 3:
                    //killVisual();
                    clearAll();
                    return 3;
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
            //plus de monstre donc go map
            clearAll();
            return 0;
        }

        //ennemy turn
        if(action ==0){
            for (int i = 0; i < nb_monster; ++i) {
                if(strcmp(get_name_M(&monster_list[i]),"###DEAD###")!=0){
                    int dmg_received = monster_attack(player,&monster_list[i]);
                    showDmgReceived(dmg_received,&monster_list[i],interaction_x,interaction_y);
                    if(get_vie_P(player)<=0){
                        showDeathMessage(interaction_x,interaction_y);
                        free(monster_list);
                        killVisual();
                        return 1;
                    }
                }
            }
            action += get_ac_P(player);
        }

    }
    //exit par player
    clearAll();
    moveCursor(0,0);
    printf("Vous avez quit");
    return 0;
}
