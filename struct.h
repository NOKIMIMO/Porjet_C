#ifndef PORJET_C_STRUCT_H
#define PORJET_C_STRUCT_H



enum Armor_type{
    head_piece,
    chest_piece,
    leg_piece,
    boots,
    ring,
};

typedef struct Item {
    int name;
    int mana;
    int hp;
}Item;

typedef struct Skill{
    int name;
    int mana;
    int dmg;
}Skill;

typedef struct Armor{
    int name;
    int mana;
    int def;
    enum Armor_type armor_type;
}Armor;

typedef struct Weapon{
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


typedef struct Player{
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
}Player;

#endif PORJET_C_STRUCT_H