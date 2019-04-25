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
public:
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

public:
    virtual bool grabTreasure(coord position,coord tposition,MapSystem my_map)
    {
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,0);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }
    virtual void setPosition(coord new_position)
    {
        position = new_position;
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
    bool grabTreasure(coord position,coord tposition, MapSystem my_map)
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
    bool grabTreasure(coord position,coord tposition, MapSystem my_map)
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
    bool grabTreasure(coord position,coord tposition, MapSystem my_map)
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
    bool grabTreasure(coord position,coord tposition, MapSystem my_map)
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

void Simulate(int rounds)
{

    for(int t=1;t<=rounds;t++)
    {

    }
}

int main()
{
    MapSystem my_map;
    my_map.load_map();
    my_map.print_map();
    return 0;
}
