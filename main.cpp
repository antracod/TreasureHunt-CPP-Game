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
    vector <string> winnerList;
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
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
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
    bool okMovementUp()
    {
        if(position.x>1)
            return true;
        else
            return false;
    }
    bool okMovementDown(int limit)
    {
        if(position.x<limit)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool okMovementLeft()
    {
        if(position.y>1)
            return true;
        else
            return false;
    }
    bool okMovementRight(int limit)
    {
        if(position.y<limit)
            return true;
        else
            return false;
    }
    virtual void moveHunterOnMap(MapSystem my_map,int typeValue)
    {
        coord next_position;
        if(okMovementUp()==true)
        {
            next_position.x = position.x-1;
            next_position.y = position.y;
            if(my_map.getPositionValue(next_position)==0)
            {
                my_map.setPositionValue(position,0);
                my_map.setPositionValue(position,typeValue);
                position.x = next_position.x;
                position.y = next_position.y;

            }
        }
    }
};

class UHunter :public Hunter
{
private:
      const int typevalue = 1;
public:
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(coord position, MapSystem my_map)
    {
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
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
class DHunter : public Hunter
{
private:
      const int typevalue = 2;
public:
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(coord position, MapSystem my_map)
    {
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,-2);
            my_map.setPositionValue(tposition,0);
            return true;
        }
        else
            return false;
    }

};

class LHunter : public Hunter
{
private:
     const int typevalue = 3;
public:
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(coord position, MapSystem my_map)
    {
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
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

class RHunter : public Hunter
{
private:
    const int typevalue = 4;
public:
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(coord position, MapSystem my_map)
    {
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
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
        my_UHunter.moveHunterOnMap(my_map,my_UHunter.getTypeValue());
        my_DHunter.moveHunterOnMap(my_map,my_DHunter.getTypeValue());
        my_LHunter.moveHunterOnMap(my_map,my_LHunter.getTypeValue());
        my_RHunter.moveHunterOnMap(my_map,my_RHunter.getTypeValue());
        my_map.print_map();

        if(my_map.getTreasureCount()==0)
            break;
        else if(my_UHunter.getCanMove()==0 && my_DHunter.getCanMove()==0 && my_LHunter.getCanMove()==0 &&  my_RHunter.getCanMove()==0)
            break;
    }

}

int main()
{
    Simulate();
    return 0;
}
