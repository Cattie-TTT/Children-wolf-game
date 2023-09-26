#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main(){
    
    Linked_List game;
    string cmd;
    double x;
    double y;
    double t;
    double D;
    while(cin>>cmd){
        if(cmd=="SPAWN"){
            cin>>x;
            cin>>y;
            game.addChild(x,y);
        }
        else if(cmd=="TIME"){
            cin>>t;
            game.moveChildren(t);
        }
        else if(cmd=="NUM"){
            game.print_num();
        }
        else if(cmd=="PRT"){
            cin>>D;
            game.print_Location(D);
        }
        else if(cmd=="OVER"){
            game.game_over();
        }
    }
    return 0;






}