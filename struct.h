#ifndef PORJET_C_STRUCT_H
#define PORJET_C_STRUCT_H



enum Armor_type{
    head_piece,
    chest_piece,
    leg_piece,
    ring,
};

typedef struct Skill{
    char * name;
    int mana;
    int dmg;
}Skill;

typedef struct Armor{
    char * name;
    int mana;
    int def;
    enum Armor_type armor_type;
}Armor;

typedef struct Weapon{
    char * name;
    int dmg;
}Weapon;

typedef struct Monster{
    char* name;
    int level;
    int vie;
    int def;
    int dmg;
    char* sprite;
}Monster;

typedef struct ListItem{
    int potion_hp;
    int potion_mana;
    int potion_double;
}ListItem;

typedef struct ListWeapon {
    Weapon **weapon;
    int size;
    int capacity;
}ListWeapon;

typedef struct ListArmor{
    //chaque armor piece aura sa liste
    Armor **armor;
    int size;
    int capacity;
}ListArmor;

typedef struct ListSkill{
    Skill **skill;
    int size;
    int capacity;
}ListSkill;

typedef struct Inventory{
    ListItem * listItem;
    ListWeapon * listWeapon;
    ListArmor * listArmor;
    ListSkill * listSkill;
}Inventory;

typedef struct Player{
    char * name;
    int pos_x;
    int pos_y;
    int level;
    int exp;
    int og_vie;
    int og_mana;
    int og_def;
    int og_speed;
    int vie;
    int mana;
    int def;
    int ac;
    Weapon * weapon;
    Armor * head_piece;
    Armor * chest_piece;
    Armor * leg_piece;
    Armor * ring;
    Inventory * inventory;
    Skill * skill1;
    Skill * skill2;
    int ** map;
}Player;

#endif //PORJET_C_STRUCT_H