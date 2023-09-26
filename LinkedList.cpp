#include <iostream>
#include <cmath>
#include "Class.cpp"

class Linked_List{
    private:
    Child *head;
    int activeChildren;
  

public:
    Linked_List():head(nullptr), activeChildren(0){

    }


    void addChild(double x, double y){
        
        if(x<=0 ||y<=0){
        std::cout<<"failure"<<std::endl;
        
    }
    else{
        
        Child *newChild=new Child(x,y);
        newChild->next=head;
        head=newChild;
        activeChildren++;
        std::cout<<"success"<<std::endl;
    }
    }

    void moveChildren(double t){
        
        if(t<0){                             //----------when t is strictly negative
            while(head!=nullptr && head->distance_to_wolf()<1.0){
                Child *removeChild=head;
                head=head->next;
                delete removeChild;
                activeChildren--;
            }
            
            std::cout<<"Number of children still playing the game: "<<activeChildren<<std::endl;
        }

        /*Child *current=head;
         Child *previous=nullptr;*/

        
        else{
             Child *current=head;
            Child *previous=nullptr;
           

            while(current!=nullptr){           
                current->move_to_wolf(t);
                
                if(current->x<=0 || current->y<=0){         //if the child is not in the 1st quadrant
                    Child *temp=current;
                    current=current->next;
                    if(previous!=nullptr){   //not the first node
                        previous->next=current;
                        delete temp;
                        activeChildren--;
                }
                    else{
                        head=current;
                        delete temp;
                        activeChildren--;
                    
                }
             }
            
            else{
            previous=current;
            current=current->next;            
            }           
        }
        std::cout<<"Number of children still playing the game: "<<activeChildren<<std::endl;        
    }
    }
    /*int getCapacity(){
        Child *current=head;
        int count{0};
        while(current!=nullptr){
            count ++;
            current=current->next;
        }
        return count;
    }*/
    void print_num(){
        std::cout<<"Number of children still playing the game: "<<activeChildren<<std::endl;
    }

    void print_Location(double D){
        
        int children_within_D{};
        Child *current=head;

        while(current!=nullptr){
            if(current->distance_to_wolf()<=D){
            std::cout<< current->x << " " << current->y <<std::endl;
            children_within_D++;
            }
            current=current->next;
        }
        if(children_within_D==0){
            std::cout<<"No children within distance."<<std::endl;
        }   
    }

    void game_over(){
         //int activeChildren=getCapacity();
        if(activeChildren>=1){
            std::cout<<"The players win."<<std::endl;
        }
        else{
            std::cout<<"The wolf wins."<<std::endl;
        }
        }
    //destructor 
    ~Linked_List(){
        while(head!=nullptr){
            Child *temp=head;
            head=head->next;
            delete temp;
        }

    }
    };

