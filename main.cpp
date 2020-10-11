#include <iostream>
#include "iomanip"
#include "POKEMON.h"

using namespace std;

int indexFinder(string name);
int sumStats(string name);
string simple_battle(string one, string two);
string wild_battle(string one, string two);
float damage(string attacker, string defender);
string battle(string one, string two);
string final_battle(string one, string two);

/**
 * Main method for Pokemon Battle Simulator
 *
 * Prints out results of all questions
 */
int main() {
    // Sets the rounding to print out 2 decimal places at all times
    cout<< fixed << setprecision(2);

    // #Q1: What is the name of the Pokémon at index 0?
    cout<<"#Q1"<<endl;
    cout<<get_name(0)<<endl;
    cout<<endl;

    // #Q2: At what index is Metapod?
    cout<<"#Q2"<<endl;
    cout<<indexFinder("Metapod")<<endl;
    cout<<endl;

    // #Q3: What is the result of a simple battle between Snorunt and Starly?
    cout<<"#Q3"<<endl;
    cout<<simple_battle("Snorunt", "Starly")<<endl;
    cout<<endl;

    // #Q4: What is the result of a simple battle between Snorunt and Staravia?
    cout<<"#Q4"<<endl;
    cout<<simple_battle("Snorunt", "Staravia")<<endl;
    cout<<endl;

    // #Q5: What is the result of a simple battle between Charmander and Chimchar?
    cout<<"#Q5"<<endl;
    cout<<simple_battle("Charmander", "Chimchar")<<endl;
    cout<<endl;

    // #Q6: Print the result of the wild_battle between Caterpie and Melmetal.
    cout<<"#Q6"<<endl;
    cout<<wild_battle("Caterpie", "Melmetal")<<endl;
    cout<<endl;

    // #Q7: Print the result of the wild_battle between Dragonite and Snorunt.
    cout<<"#Q7"<<endl;
    cout<<wild_battle("Dragonite", "Snorunt")<<endl;
    cout<<endl;

    // #Q8: How much damage will Scraggy do to Tranquill in one attack?
    cout<<"#Q8"<<endl;
    cout<<damage("Scraggy", "Tranquill")<<endl;
    cout<<endl;

    // #Q9: How much damage does Dragonite do to Rockruff in one attack?
    cout<<"#Q9"<<endl;
    cout<<damage("Dragonite", "Rockruff")<<endl;
    cout<<endl;

    // #Q10: How much damage does Quilava do to Grovyle in one attack?
    cout<<"#Q10"<<endl;
    cout<<damage("Quilava", "Grovyle")<<endl;
    cout<<endl;

    cout<<"#Q11"<<endl;
    cout<<damage("Goomy", "Beedrill")<<endl;
    cout<<endl;

    // #Q11: How much damage does Goomy do to Beedrill in one attack?
    cout<<"#Q12"<<endl;
    cout<<damage("Tepig", "Charizard")<<endl;
    cout<<endl;

    // #Q12: How much damage does Tepig do to Charizard in one attack?
    cout<<"#Q12"<<endl;
    cout<<damage("Tepig", "Charizard")<<endl;
    cout<<endl;

    // #Q13: What is the outcome of a battle between Scraggy and Krabby?
    cout<<"#Q13"<<endl;
    cout<<battle("Scraggy", "Krabby")<<endl;
    cout<<endl;

    // #Q14: What is the outcome of a battle between Charizard and Krabby?
    cout<<"#Q14"<<endl;
    cout<<battle("Charizard", "Krabby")<<endl;
    cout<<endl;

    // #Q15: What is the output of a battle between Treecko and Litten?
    cout<<"#Q15"<<endl;
    cout<<battle("Treecko", "Litten")<<endl;
    cout<<endl;

    // #Q16: What is the output of a battle between Treecko and Buizel?
    cout<<"#Q16"<<endl;
    cout<<battle("Treecko", "Buizel")<<endl;
    cout<<endl;

    // #Q17: What is the result of final battle between Grotle and Roggenrola?
    cout<<"#Q17"<<endl;
    cout<<final_battle("Grotle", "Roggenrola")<<endl;
    cout<<endl;

    // #Q18: What is the result of final battle between Starly and Goodra?
    cout<<"#Q18"<<endl;
    cout<<final_battle("Starly", "Goodra")<<endl;
    cout<<endl;
}

/**
 * Finds the index for a specific pokemon in the list
 *
 * @param name string containing a pokemon's name
 *
 * @return index of specific pokemon
 */
int indexFinder(string name){
    int pokemonAmount = *(&pokemon_list + 1) - pokemon_list;
    int index = -1;
    for(int i = 0; i < pokemonAmount; i++){ // Searches through entire pokemon_list for the name passed in
        if(get_name(i).compare(name) == 0){
            index = i;
            break;
        }
    }
    return index;
}

/**
 * Calculates the total stats for a specific pokemon
 *
 * @param name string containing a pokemon's name
 *
 * @return number of total stats
 */
int sumStats(string name){
    int index = indexFinder(name);
    int sum = 0 + get_attack(index) + get_defense(index) + get_hp(index) // Adds all numerical stats together
            + get_special_attack(index) + get_special_defense(index) + get_speed(index);
    return sum;
}

/**
 * Runs a simple battle simulation higher stats wins
 *
 * @param one name of first pokemon
 * @param two name of second pokemon
 *
 * @return winner of battle
 */
string simple_battle(string one, string two){
    int oneStats = sumStats(one);
    int twoStats = sumStats(two);
    if(oneStats > twoStats){
        return one;
    } else if(oneStats < twoStats){
        return two;
    } else{
        return "Draw";
    }
}

/**
 * Simulates a battle of two pokemon in thw wild
 *
 * @param one name of first pokemon
 * @param two name of second pokemon
 *
 * @return Battle results
 */
string wild_battle(string one, string two){
    int oneStats = sumStats(one);
    int twoStats = sumStats(two);
    if(abs(oneStats - twoStats) > 300){ // Checks to see if the difference in stats is greater than 300
        if(oneStats > twoStats){
            return two + " ran away";
        } else{
            return one + " ran away";
        }
    }
    return simple_battle(one, two);
}

/**
 * Calculates the damage of each move for a specific pokemon
 *
 * @param attacker name of attacking pokemon
 * @param defender name of defending pokemon
 *
 * @return the highest damage of attack on defender
 */
float damage(string attacker, string defender){
    int indexAttacker = indexFinder(attacker);
    int indexDefender = indexFinder(defender);
    float physicalAttack = 100 * (float) 10 * get_attack(indexAttacker) / get_defense(indexDefender);
    float specialAttack = 100 * (float) 10 * get_special_attack(indexAttacker) / get_special_defense(indexDefender);

    if(physicalAttack > specialAttack){
        return (float)((int) (physicalAttack + 0.5)) / 100;
    }else{
        return (float)((int) (specialAttack + 0.5)) / 100;
    }
}

/**
 * Simulates a real back and forth battle
 *
 * @param one name of first pokemon
 * @param two name of second pokemon
 *
 * @return Winner of battle
 */
string battle(string one, string two){
    int indexOne = indexFinder(one);
    int indexTwo = indexFinder(two);
    string first = "";
    string second = "";
    if(get_speed(indexOne) ==  get_speed(indexTwo)){ // Checks to see which pokemon attacks first by comparing speed
        char charOne[one.length() + 1];
        char charTwo[two.length() + 1];
        strcpy(charOne, one.c_str());
        strcpy(charTwo, two.c_str());
        int compare = strcmp(charOne,charTwo);
        if(compare < 0){
            first = one;
            second = two;
        } else if(compare > 0){
            first = two;
            second = one;
        }

    } else if(get_speed(indexOne) > get_speed(indexTwo)){
        first = one;
        second = two;
    } else {
        first = two;
        second = one;
    }
    float hpOne = (float)get_hp(indexOne);
    float hpTwo = (float)get_hp(indexTwo);
    string winner = "";
    while(hpOne > 0 && hpTwo > 0 ){ // While pokemon both still have health remaining
        float attackOne = damage(first, second);
        hpTwo -= attackOne;
        if(hpTwo <= 0){
            winner = one;
            break;
        }
        float attackTwo = damage(second, first);
        hpOne -= attackTwo;
        if(hpOne <= 0){
            winner = two;
            break;
        }
    }
    return winner;
}

/**
 * Runs a back and forth battle, but ensures opponents can reach each other
 *
 * @param one name of first pokemon
 * @param two name of second pokemon
 *
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
string final_battle(string one, string two){
    int indexOne = indexFinder(one);
    int indexTwo = indexFinder(two);
    string regionOne = get_region(indexOne);
    string regionTwo = get_region(indexTwo);
    if((regionOne.compare(regionTwo) != 0 ) // Checks to see if pokemon will ever come into contact with each other
        && (get_type_1(indexOne).compare("Flying") != 0
        && get_type_2(indexOne).compare("Flying") != 0
        && get_type_1(indexTwo).compare("FLying")!= 0
        && get_type_2(indexTwo).compare("Flying") != 0)){
        return "Cannot Battle";
    } else{
        return battle(one, two);
    }
}