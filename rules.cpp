# include "rules.h"
#include "game_manager.h"

void Land::getResource(){
    if(turnOrderForward){
        if(House){
           if(Forest){
             int wood = wood + 1; 
           }
           elseif(Hills){
               int brick = brick + 1;
           }
           elseif(Fields){
               int grain = grain + 1;
           }
           elseif(Pasture){
               int wool = wool + 1;
           }
           elseif(Mountain){
               int ore = ore + 1;
           }
           else{
               return 0;
           }
        }
        if(City){
           if(Forest){
             int wood = wood + 2; 
           }
           elseif(Hills){
               int brick = brick + 2;
           }
           elseif(Fields){
               int grain = grain + 2;
           }
           elseif(Pasture){
               int wool = wool + 2;
           }
           elseif(Mountain){
               int ore = ore + 2;
           }
           else{
               return 0;
           }
        }
    }
}
