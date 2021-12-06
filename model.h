#ifndef LAB_3_MODEL_H
#define LAB_3_MODEL_H
enum State {EMPTY,PLANT,PREDATOR,HERBIVORE};//types of living
const int N=40;
typedef class Living;
typedef class World;
typedef class Predator;
typedef class Herbivore;
typedef class Plant;
class Living{//abstract class
public:
    virtual State who()=0; //return type of living
//  virtual Living* next(World w)=0;//make next turn
    virtual Living* Move() = 0;
    virtual Living* Eating() = 0;
    virtual Living* Sex()=0;
    virtual Living* End_of_turn()=0;
    virtual ~Living()=0;
};
class Predator:public Living{
public:
    State who() override{
        return PREDATOR;
    }
    Living *Move() override{
        int direction=rand()%4,speed_point=speed;
        while(speed_point)
        {
            speed_point--;
            switch (direction) {
                case 0:break;
                case 1:break;
                case 2:break;
                case 3:

            }
        }
    }
    Living * Sex() override{
        if ()
    }
    Living * Eating() override{
        if ()
    }
protected:
    int speed{};
    char sex{};
    //int hp{};
    int size{};// 1-small, 2-not small not big, 3-big
    int age{};
    int satiety{};//1-10 from hungry to satiety
    int row{};
    int column{};
};
class Tiger:public Predator{
    Tiger(int r,int c){
        size=2;
        age=0;
        switch (rand()%2) {
            case 0:
                sex='M';break;
            case 1:
                sex='F';
        }
        row=r;
        column=c;
        speed=3;
    }
    ~Tiger(){
        delete this;
    }/*
    Living * End_of_turn() override{
        if (age<=30 || satiety<=0)
        {
            this->~Tiger;
        }
    }*/

};
class Field:public Living{
public:
    Field()=default;
    State plant_here()
    {
        if (Slot_for_plant->who()==PLANT)
            return PLANT;
        else
            return EMPTY;
    }
    State who() override{
        for (int i = 0; i < 4; ++i) {
            if(Slots_for_Animal->who() != EMPTY) {
                return Slots_for_Animal->who();
            }
        }
        return plant_here();
    }
protected:
    Living* Slots_for_Animal/*, *right_bottom,*right_top,*left_top*/;
    Living* Slot_for_plant;
};


class World{
public:
    World(int r,int c){
        row=r;
        column=c;
        board=new Field*[column];
        for (int i = 0; i < column; ++i) {
            board[i]=new Field[row];
        }
    }
    ~World(){
        for (int i = 0; i < column; ++i) {
            delete board[i];
        }
        delete board;
    }
protected:
    int column,row;
    Field** board;
};

#endif //LAB_3_MODEL_H
