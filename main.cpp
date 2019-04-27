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
                if(map_array[i][j]==8)
                    cout<<"X ";
                else
                    cout<<map_array[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
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
    virtual bool grabTreasure(coord position,MapSystem &my_map)
    {
        coord tposition;
        tposition.x = position.x;
        tposition.y = position.y;
        if(my_map.getPositionValue(tposition)==6)
        {
            // my_map.setPositionValue(position,0);
            // my_map.setPositionValue(position,0);
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
        if(getPosition().x>1)
            return true;
        else
        {
            return false;
        }
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
    void moveHunterOnMap(MapSystem &my_map,int typeValue)
    {
        bool hasMoved = 0;
        coord next_position;
        if(can_move==false)
            return;
        if(okMovementUp()==true)
        {
            next_position.x = position.x-1;
            next_position.y = position.y;
            if(my_map.getPositionValue(next_position)==0)
            {
                my_map.setPositionValue(position,8);
                my_map.setPositionValue(next_position,typeValue);
                position = next_position;
                hasMoved = 1;
            }
        }
        if(okMovementDown(my_map.getMapLimit())==true && hasMoved==0)
        {
            next_position.x = position.x+1;
            next_position.y = position.y;
            if(my_map.getPositionValue(next_position)==0)
            {
                my_map.setPositionValue(position,8);
                my_map.setPositionValue(next_position,typeValue);
                position = next_position;
                hasMoved = 1;
            }
        }
        if(okMovementLeft()==true && hasMoved==0)
        {
            next_position.x = position.x;
            next_position.y = position.y-1;
            if(my_map.getPositionValue(next_position)==0)
            {
                my_map.setPositionValue(position,8);
                my_map.setPositionValue(next_position,typeValue);
                position = next_position;
                hasMoved = 1;
            }
        }
        if(okMovementRight(my_map.getMapLimit())==true && hasMoved==0)
        {
            next_position.x = position.x;
            next_position.y = position.y+1;
            if(my_map.getPositionValue(next_position)==0)
            {
                my_map.setPositionValue(position,8);
                my_map.setPositionValue(next_position,typeValue);
                position = next_position;
                hasMoved = 1;
            }
        }
        if(hasMoved==0)
        {
            can_move=false;
        }
    }
};

class UHunter :public Hunter
{
private:
    const int typevalue = 1;
public:
    void setInitialPosition(int limit)
    {
        coord tposition;
        tposition.x = limit;
        tposition.y = 1;
        setPosition(tposition);
    }
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(MapSystem &my_map)
    {

        coord tposition;
        coord position = getPosition();
        tposition.x = position.x-1;
        tposition.y = position.y;
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,8);
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
    void setInitialPosition(int limit)
    {
        coord tposition;
        tposition.x = 1;
        tposition.y = limit;
        setPosition(tposition);
    }
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(MapSystem &my_map)
    {

        coord tposition;
        coord position = getPosition();
        tposition.x = position.x+1;
        tposition.y = position.y;
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,8);
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
    void setInitialPosition(int limit)
    {
        coord tposition;
        tposition.x = 1;
        tposition.y = 1;
        setPosition(tposition);
    }
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(MapSystem &my_map)
    {

        coord tposition;
        coord position = getPosition();
        tposition.x = position.x;
        tposition.y = position.y-1;
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,8);
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
    void setInitialPosition(int limit)
    {
        coord tposition;
        tposition.x = limit;
        tposition.y = limit;
        setPosition(tposition);
    }
    int getTypeValue()
    {
        return typevalue;
    }
    bool grabTreasure(MapSystem &my_map)
    {

        coord tposition;
        coord position = getPosition();
        tposition.x = position.x;
        tposition.y = position.y+1;
        if(my_map.getPositionValue(tposition)==6)
        {
            my_map.setPositionValue(position,8);
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


    my_UHunter.setInitialPosition(my_map.getMapLimit());
    my_DHunter.setInitialPosition(my_map.getMapLimit());
    my_LHunter.setInitialPosition(my_map.getMapLimit());
    my_RHunter.setInitialPosition(my_map.getMapLimit());

    for(int t=1; t<=rounds; t++)
    {
        /// UHUNTER
        if(my_UHunter.grabTreasure(my_map)==true)
        {
            my_UHunter.disableMovement();
        }
        else if(my_UHunter.getCanMove()==true)
        {
            my_UHunter.moveHunterOnMap(my_map,my_UHunter.getTypeValue());
        }


        /// DHUNTER
        if(my_DHunter.grabTreasure(my_map)==true)
        {
            my_DHunter.disableMovement();
        }
        else if(my_DHunter.getCanMove()==true)
        {
            my_DHunter.moveHunterOnMap(my_map,my_DHunter.getTypeValue());
        }

        /// LHUNTER
        if(my_LHunter.grabTreasure(my_map)==true)
        {
            my_LHunter.disableMovement();
        }
        else if(my_LHunter.getCanMove()==true)
        {
            my_LHunter.moveHunterOnMap(my_map,my_LHunter.getTypeValue());
        }

        if(my_RHunter.grabTreasure(my_map)==true)
        {
            my_RHunter.disableMovement();
        }
        else if(my_RHunter.getCanMove()==true)
        {
            my_RHunter.moveHunterOnMap(my_map,my_RHunter.getTypeValue());
        }



        cout<<"Round "<<t<<" :"<<'\n';
        cout<<my_UHunter.getCanMove()<<'\n';
        my_map.print_map();

        if(my_map.getTreasureCount()==0)
            break;
        else if(my_UHunter.getCanMove()==0 && my_DHunter.getCanMove()==0 && my_LHunter.getCanMove()==0 &&  my_RHunter.getCanMove()==0)
            break;
    }

}

void LoadTitle()
{
    cout<<"$$$$$$$$\\ "<<'\n';
    cout<<"\\__$$  __| "<<'\n';
    cout<<"   $$ | $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$$\\ $$\\   $$\\  $$$$$$\\   $$$$$$\\        $$ |  $$ |$$\\   $$\\ $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\  "<<'\n';
    cout<<"   $$ |$$  __$$\\ $$  __$$\\  \\____$$\\ $$  _____|$$ |  $$ |$$  __$$\\ $$  __$$\\       $$$$$$$$ |$$ |  $$ |$$  __$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ "<<'\n';
    cout<<"   $$ |$$ |  \\__|$$$$$$$$ | $$$$$$$ |\\$$$$$$\\  $$ |  $$ |$$ |  \\__|$$$$$$$$ |      $$  __$$ |$$ |  $$ |$$ |  $$ | $$ |    $$$$$$$$ |$$ |  \\__|"<<'\n';
    cout<<"   $$ |$$ |      $$   ____|$$  __$$ | \\____$$\\ $$ |  $$ |$$ |      $$   ____|      $$ |  $$ |$$ |  $$ |$$ |  $$ | $$ |$$\\ $$   ____|$$ |      "<<'\n';
    cout<<"   $$ |$$ |      \\$$$$$$$\\ \\$$$$$$$ |$$$$$$$  |\\$$$$$$  |$$ |      \\$$$$$$$\\       $$ |  $$ |\\$$$$$$  |$$ |  $$ | \\$$$$  |\\$$$$$$$\\ $$ |      "<<'\n';
    cout<<"   \\__|\\__|       \\_______| \\_______|\\_______/  \\______/ \\__|       \\_______|      \\__|  \\__| \\______/ \\__|  \\__|  \\____/  \\_____/ \\__/"<<'\n';
    cout<<'\n';
}

void LoadMenu()
{
    cout<<"1. Start Game \n2. Rules\n3. Options\n4. Quit\n\n";
}

void LoadRules()
{
    cout<<"There are 4 hunter: \n";
    cout<<"UHunter - he can grab the treasure only if it is above him\n";
    cout<<"DHunter - he can grab the treasure only if it is under him\n";
    cout<<"LHunter - he can grab the treasure only if it is on the left tile of him\n";
    cout<<"RHunter - he can grab the treasure only if it is on the right tile of him\n";
    cout<<"They are encoded with 1 2 3 4\n";
    cout<<"0 = unvisited position\n";
    cout<<"6 = treasure\n";
    cout<<"X = visited position\n";
    cout<<"Move the treasure in map.in to change the simulation"
}

void LoadGameScreen()
{
    LoadTitle();
    LoadMenu();

    int option = 0;
    while(option!=1)
    {
        cin>>option;
        if(option==1)
        {
            cout<<"\n \nEnter Number of rounds : ";
            break;
        }

        else if(option==2)
        {
            LoadRules();
        }
        else if(option==3)
        {
            cout<<"\nEdit map.in to change game configuration\n\n";
        }
    }

}

int main()
{
    LoadGameScreen();
    Simulate();
    return 0;
}
