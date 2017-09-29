#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

enum TYPE{
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHT,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL
};

struct attack{
    TYPE T;
    std::string aname;
    unsigned int power;
    float accuracy;
};

//calculating a damage constant
float effect(TYPE atk, TYPE mon){
    if (atk == NORMAL){
        if ((mon == ROCK) || (mon == STEEL)){
            return(0.5);
        } else if (mon == GHOST){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == FIRE){
        if ((mon == GRASS) || (mon == ICE) || (mon == BUG) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ROCK) || (mon == DRAGON)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == WATER){
        if ((mon == FIRE) || (mon == GROUND) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == WATER) || (mon == GRASS) || (mon == DRAGON)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ELECTRIC){
        if ((mon == WATER) || (mon == FLYING)){
            return(2.0);
        } else if ((mon == ELECTRIC) || (mon == GRASS) || (mon == DRAGON)){
            return(0.5);
        } else if (mon == GROUND){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == GRASS){
        if ((mon == WATER) || (mon == GROUND) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == GRASS) || (mon == POISON) || (mon == FLYING) || (mon == BUG) || (mon == DRAGON) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ICE){
        if ((mon == GRASS) || (mon == GROUND) || (mon == FLYING) || (mon == DRAGON)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ICE) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == FIGHT){
        if ((mon == NORMAL) || (mon == ICE) || (mon == ROCK) || (mon == DARK) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == POISON) || (mon == FLYING) || (mon == PSYCHIC) || (mon == BUG)){
            return(0.5);
        } else if (mon == GHOST){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == POISON){
        if (mon == GRASS){
            return(2.0);
        } else if ((mon == POISON) || (mon == GROUND) || (mon == ROCK) || (mon == GHOST)){
            return(0.5);
        } else if (mon == STEEL){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == GROUND){
        if ((mon == FIRE) || (mon == ELECTRIC) || (mon == POISON) || (mon == ROCK) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == GRASS) || (mon == BUG)){
            return(0.5);
        } else if (mon == FLYING){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == FLYING){
        if ((mon == GRASS) || (mon == FIGHT) || (mon == BUG)){
            return(2.0);
        } else if ((mon == ELECTRIC) || (mon == ROCK) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == PSYCHIC){
        if ((mon == FIGHT) || (mon == POISON)){
            return(2.0);
        } else if ((mon == PSYCHIC) || (mon == STEEL)){
            return(0.5);
        } else if (mon == DARK){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == BUG){
        if ((mon == GRASS) || (mon == PSYCHIC) || (mon == DARK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == FIGHT) || (mon == POISON) || (mon == FLYING) || (mon == GHOST)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ROCK){
        if ((mon == FIRE) || (mon == ICE) || (mon == FLYING) || (mon == BUG)){
            return(2.0);
        } else if ((mon == FIGHT) || (mon == GROUND) || (mon == STEEL)){
            return(0.5);
        } else {
            return (1.0);
        }
    } else if (atk == GHOST){
        if ((mon == PSYCHIC) || (mon == GHOST)){
            return(2.0);
        } else if ((mon == DARK) || (mon == STEEL)){
            return(0.5);
        } else if (mon == NORMAL){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == DRAGON){
        if (mon == DRAGON){
            return(2.0);
        } else if (mon == STEEL){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == DARK){
        if ((mon == PSYCHIC) || (mon == GHOST)){
            return(2.0);
        } else if ((mon == FIGHT) || (mon == DARK) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == STEEL){
        if ((mon == ICE) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ELECTRIC) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    }else {
        return (1.0);
    }
}

class monster{
    //just for ease of reading. Members are initialised as private by default if no access specifier is used
private:
    //longest base name is 12 letters, ie; size = 13, prefix "Mega " = 5 & suffix " X" = 3
    char mname[21];
    //std::string mname; //to be converted
    unsigned int bhp, hp, atk, def, speed;
    TYPE t1, t2;
public:
    //Functions for returning object values
    char *getname(){
        return(mname);
    }
    unsigned int gethp(){
        return(hp);
    }
    unsigned int getattack(){
        return(atk);
    }
    unsigned int getdefence(){
        return(def);
    }
    unsigned int getspeed(){
        return(speed);
    }
    TYPE gettype1(){
        return(t1);
    }
    TYPE gettype2(){
        return(t2);
    }
    int update_info(char nm[21], TYPE a1, TYPE a2){
        t1 = a1;
        t2 = a2;
        strcpy(mname, nm);
        return(0);
    }
    //calculated for attacking monster
    //signed int is used in future consideration of using as a healing move as well
    int getpre_dmg(attack move){
        // based on level 50, as it's the official level cap. Formulae Sourced from serebii.net/games/damage.shtml
        return(22 * atk * move.power);
    }
    //calculation of stab, ie; a damage calculation constant
    float stab(TYPE move){
        if ((move == t1) || (move == t2)){
            return(1.5);
        } else {
            return(1.0);
        }
    }
    //calculated for defending monster
    //pre_dmg is calculated using above function (getpre_dmg) and returned here as argument
    //pre_dmg is calculated for attacking monster
    //dmgcalc is calculated for defending monster
    //stab is damage constant dependant on attacking monster's type and attack move's type matching =1.5, else =1
    int dmgcalc(int pre_dmg, attack move, float st = 1.0){
        //check for accuracy here, again using random number generation from 0 to 50, if < move.accuracy then return(0);
        // <-- insert code here -->
        // else the below code gets executed
        float eff = effect(move.T, t1) * effect(move.T, t2);
        float dmg = (((pre_dmg / def) / 50) + 2) * st * eff;
        //Insert a random multiplier (random_number/100) to dmg, where random_number is [85 to 100]
        // <-- insert code here -->
        return(int(dmg));
    }
    unsigned int updatehp(int dmgcalc){
        hp-=dmgcalc;
        return(hp);
    }
    //element[0] = base stat, element[1] = effort value, IVs have been maxed
    int statcalc(unsigned int b[2], unsigned int a[2], unsigned int d[2], unsigned int s[2]){
        //for base HP
        float temp = ((31 + (2 * b[0]) + (b[1] / 4)) * 2) + 60;
        bhp = (unsigned int)temp;
        //for attack stat
        temp = ((31 + (2 * a[0]) + (a[1] / 4)) * 2) + 5;
        atk = (unsigned int)temp;
        temp = ((31 + (2 * d[0]) + (d[1] / 4)) * 2) + 5;
        def = (unsigned int)temp;
        temp = ((31 + (2 * s[0]) + (s[1] / 4)) * 2) + 5;
        speed = (unsigned int)temp;
        hp = bhp;
        return(0);
    }
};

//consider possible convertion to class from struct in future for storing player stats
struct player{
    char id[30];
    char password[30];
    char name[40];
    monster team[6];
};

/*
//considered storage form for password
//a proper encryption method will be added to replace this

char *rockup(char ar[], int inc){
    char nsr[int(pow(int(sqrt(strlen(ar))),2))];
    for (int i = 0; i < strlen(ar); ++i) {
        nsr[i] = ar[i+int(sqrt(strlen(ar)))];
        nsr[i] = char(int(nsr[i]) + inc);
    }
    return(nsr);
}
*/

monster rec_mon(){
    monster ch, lch;
    //check C++14 syntax for file handling
    std::fstream fi;
    //opening in read only mode for displaying options
    fi.open("monster_list.dat", std::ios::binary | std::ios::in);
    //loop from below
    char choice;
    //listed menu loop
    do {
        while (fi.read((char*)&lch, sizeof(lch))){
            //show list of available monster graphically
        }
        //prompt user to choose
        choice = 'x';// placeholder to be replaced by a proper input through interface
    }while(choice != 'x');
    fi.close();
    return(ch);
}

player new_reg(){
    player nw;
    std::fstream fo;
    fo.open("player_list.dat", std::ios::binary | std::ios::app);
    //interface for entering the values

    //writing to file the new player entry
    fo.write((char *)&nw, sizeof(nw));
    fo.close();
    return(nw);
}

player lsearch(char argid[30]){
    std::fstream fi;
    player res;
    fi.open("player_list.dat", std::ios::binary | std::ios::in);
    while (fi.read((char *)&res, sizeof(res))){
        if (strcmp(res.id, argid) == 0){
            fi.close();
            return(res);
        }
    }
    fi.close();
    return(new_reg());
}

player rec_pl(){
    player pl;
    //check C++14 syntax for file handling
    std::fstream fi;
    //opening in read only mode for player profile
    fi.open("player_list.dat", std::ios::binary | std::ios::in);
    //list of registered players

    //search and return the requested player

    //authentication of profile ownership function call

    fi.close();
    return(pl);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string st;
    std::cout << "Enter a string: ";
    std::cin >> st;
    std::cout << st << std::endl;
    return 0;
}
