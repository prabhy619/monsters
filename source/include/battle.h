#ifndef _MONSTER_H
#include "monster.h"
#endif

#ifndef _BATTLE_H
#define _BATTLE_H 1

class battle {
private:
	static Battle* b_instance;

    Battle() {}
    Battle(Battle const&) = delete;
    void operator=(Battle const&) = delete;

public:
	static Battle* getInstance(){
        if(b_instance == NULL){
            b_instance = new Battle();
        }
        return b_instance;
    }
	//setters
    //getters


    //signed int is used in future consideration of using as a healing move as well
    int getPreDmg(attack move){
        // based on level 50, as it's the official level cap in tournaments.
        //Formulae Sourced from serebii.net/games/damage.shtml
        return(22 * atk * move.power);
    }

    //calculation of stab, ie; a damage calculation constant
    float getStabBonus(TYPE move){
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
    bool StatCalc(unsigned int hp[2], unsigned int atk[2], unsigned int def[2], unsigned int spd[2]){
        //check sum for element[1]
        int sum = hp[1] + atk[1] + def[1] + spd[1];

        if ((hp[0] > 180)||(atk[0] > 180)||(def[0] > 180)||(spd[0] > 180){
	    return(false);
        }

        //correction required for the EV spread condition
        if (sum > 31){
            std::cout << "Invalid EVs" << std::endl;
            return(false);
        }

        //for base HP
        float temp = ((31 + (2 * _hp[0]) + (_hp[1] / 4)) * 2) + 60;
        m_max_hp = (unsigned int)temp;

        //for attack stat
        temp = ((31 + (2 * _atk[0]) + (_atk[1] / 4)) * 2) + 5;
        m_attack = (unsigned int)temp;

        //for defence stat
        temp = ((31 + (2 * _def[0]) + (_def[1] / 4)) * 2) + 5;
        m_defence = (unsigned int)temp;

        //for speed stat
        temp = ((31 + (2 * _spd[0]) + (_spd[1] / 4)) * 2) + 5;
        m_speed = (unsigned int)temp;

        m_hp = m_max_hp;
        return(true);
    }
};
#endif
