#include <iostream>
#include <string>
#include <vector>
using namespace std;

string SpiritsAndGnomes(string strArr[], int arrLength) {

    int xS = 0;
    int xG = 0;
    std::vector<char> potential_gnomes;
    std::vector<char> gnome_candidates;

    for(int i = 0; i < strArr[0].size(); i++){
        if(strArr[0][i] == strArr[1][i]){
            xS++;
        } else {
            potential_gnomes.push_back(strArr[0][i]);
            gnome_candidates.push_back(strArr[1][i]);
        }
    }

    for(auto& pot_gnome : potential_gnomes){
        for(auto& gnome_can : gnome_candidates){
            if(pot_gnome != 'x' && gnome_can != 'x'){
                if(pot_gnome == gnome_can){
                    pot_gnome = 'x';
                    gnome_can = 'x';
                    xG++;
                }
            }
        }
    }

    return to_string(xS) + "S" + to_string(xG) + "G";
}
