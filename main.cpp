#include "header.h"

struct coord
{
    int x;
    int y;
};

class MapSystem
{
private:
    int map_array[100][100];
    int limit;
    int treasure_count = 3;
public:
    int getTreasureCount()
    {
        return treasure_count;
    }
    void removeTreasure()
    {
        treasure_count--;
    }
    int getPositionValue(coord position)
    {
        return map_array[position.x][position.y];
    }
    void setPositionValue(coord position,int value)
    {
        map_array[position.x][position.y] = value;
    }
    void setMapLimit(int value)
    {
        limit = value;
    }
    int getMapLimit()
    {
        return limit;
    }
    void load_map()
    {
        in>>limit;
        for(int i=1; i<=limit; i++)
        {
            for(int j=1; j<=limit; j++)
            {
                int value;
                in>>value;
                coord position;
                position.x = i;
                position.y = j;
                setPositionValue(position,value);
            }
        }
    }
    void print_map()
    {
        for(int i=1; i<=limit; i++)
        {
            for(int j=1; j<=limit; j++)
            {
                cout<<map_array[i][j]<<" ";
            }
            cout<<'\n';
        }
    }

};

class Hunter
{
private:
    coord position;
    bool can_move=1;

public:
     virtual void setPosition(coord new_position)
    {
        position = new_position;
    }
    virtual bool grabTreasure(coord position,MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,0);
            my_map.setPositionValue(position,0);
            return true;
        }
        else
            return false;
    }
    virtual bool getCanMove()
    {
        return can_move;
    }
    virtual void disableMovement()
    {
        can_move = 0;
    }
    coord getPosition()
    {
        return position;
    }
    bool okMovementUp(coord current_pos)
    {
        if(current_pos.x>1)
            return true;
        else
            return false;
    }
    bool okMovementDown(coord current_pos,int limit)
    {
        if(current_pos.x<limit)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool okMovementLeft(coord current_pos)
    {
        if(current_pos.y>1)
            return true;
        else
            return false;
    }
    bool okMovementRight(coord current_pos,int limit)
    {
        if(current_pos.y<limit)
            return true;
        else
            return false;
    }
};

class UHunter : Hunter
{
    bool grabTreasure(coord position, MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,-1);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }
};
class DHunter : Hunter
{
    bool grabTreasure(coord position, MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,-2);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }
    void setPosition(int limit)
    {

    }
};
class LHunter : Hunter
{
    bool grabTreasure(coord position, MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,-3);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }
};
class RHunter : Hunter
{
    bool grabTreasure(coord position, MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,-4);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }
};

void Simulate()
{
    int rounds;
    cin>>rounds;

    MapSystem my_map;
    my_map.load_map();

    UHunter my_UHunter;
    DHunter my_DHunter;
    LHunter my_LHunter;
    RHunter my_RHunter;

    for(int t=1;t<=rounds;t++)
    {
        moveUHunter(my_map,my_UHunter);
        moveDHunter(my_map,my_DHunter);
        moveLHunter(my_map,my_LHunter);
        moveRHunter(my_map,my_DHunter);
        my_map.print_map();

        if(my_map.treasure_count()==0)
            break;
        else if(my_UHunter.can_move()==0 && my_DHunter.can_move()==0 && my_LHunter.can_move()==0 &&  my_RHunter.can_move()==0)
            break;
    }

    cout<<<<'\n'<<"END GAME";

}

int main()
{
    Simulate();
    return 0;
}
