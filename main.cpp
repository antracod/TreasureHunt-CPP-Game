#include "header.h"

using namespace std;

struct coord
{
    int x;
    int y;
};

class Hunter
{
private:
    coord position;
public:
    coord getPosition()
    {
        return position;
    }
    void setPosition(coord new_position)
    {
        position = new_position;
    }


};




int main()
{

    return 0;
}
