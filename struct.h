#ifndef PORJET_C_STRUCT_H
#define PORJET_C_STRUCT_H



enum Armor_type{
    head_piece,
    chest_piece,
    leg_piece,
    boots,
    ring,
};

typedef struct Weapon{
    int dmg;
    int speed;
}Weapon;

typedef struct Armor{
    int name;
    int mana;
    int def;
    int speed;
    enum armor_type;
}Armor;

typedef struct Monster{
    int vie;
    int def;
    int dmg;
    int speed;
    int momentum;
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
    int speed;
    int momentum;
    Weapon * weapon;
    Armor * head_piece;
    Armor * chest_piece;
    Armor * leg_piece;
    Armor * ring;
}Player;

#endif PORJET_C_STRUCT_H