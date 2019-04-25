#include "header.h"

using namespace std;

struct coord
{
    int x;
    int y;
};

class MapSystem
{

};

class Hunter
{
private:
    coord position;

public:
    virtual bool grabTreasure(coord position)
    {

    }
    coord getPosition()
    {
        return position;
    }
    void setPosition(coord new_position)
    {
        position = new_position;
    }
    bool okMovementUp(coord current_pos)
    {
        if(current_pos.x>1)
            return true;
        else
            return false;
    }
    bool okMovementDown(coord current_pos)
    {

    }
    bool okMovementLeft(coord current_pos)
    {
        if(current_pos.y>1)
            return true;
        else
            return false;
    }
    bool okMovementRight(coord current_pos)
    {

    }
};

class UHunter : Hunter
{

};



int main()
{

    return 0;
}
