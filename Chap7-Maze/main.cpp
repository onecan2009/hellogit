#include <QCoreApplication>
#include <iostream>
using namespace std;

class Maze
{
public:
    Maze(){/*cout<<"Maze is constructed"<<endl;*/}
    virtual void Create()
    {
        CreateWall();
        CreateDoor();
        CreateMino();
        cout<<"Maze is created!"<<endl;
    }
protected:
    void CreateWall(){cout<<"Wall is created"<<endl;}
    void CreateDoor(){cout<<"Door is created"<<endl;}
    void CreateMino(){cout<<"Mino is created"<<endl;}
};

class StoneMaze:public Maze
{
public:
    StoneMaze(){/*cout<<"Stone Maze is constructed"<<endl;*/}
    virtual void Create()
    {
        CreateStoneWall();
        CreateStoneDoor();
        CreateStoneMino();
        cout<<"Stone Maze is created!"<<endl;
    }
protected:
    void CreateStoneWall(){cout<<"Stone Wall is created"<<endl;}
    void CreateStoneDoor(){cout<<"Stone Door is created"<<endl;}
    void CreateStoneMino(){cout<<"Stone Mino is created"<<endl;}
};

class IronMaze:public Maze
{
public:
    IronMaze(){/*cout<<"Iron Maze is constructed"<<endl;*/}
    virtual void Create()
    {
        CreateIronWall();
        CreateIronDoor();
        CreateIronMino();
        cout<<"Iron Maze is created!"<<endl;
    }
protected:
    void CreateIronWall(){cout<<"Iron Wall is created"<<endl;}
    void CreateIronDoor(){cout<<"Iron Door is created"<<endl;}
    void CreateIronMino(){cout<<"Iron Mino is created"<<endl;}
};

class MagicStoneMaze:public StoneMaze
{
public:
    MagicStoneMaze(){/*cout<<"Magic Stone Maze is constructed"<<endl;*/}
    virtual void Create()
    {
        CreateMaigicStoneWall();
        CreateMaigicStoneDoor();
        CreateMaigicStoneMino();
        cout<<"Magic stone Maze is created!"<<endl;
    }
protected:
    void CreateMaigicStoneWall(){cout<<"Magic Stone Wall is created"<<endl;}
    void CreateMaigicStoneDoor(){cout<<"Magic Stone Door is created"<<endl;}
    void CreateMaigicStoneMino(){cout<<"Magic Stone Mino is created"<<endl;}
};

class MagicIronMaze:public IronMaze
{
public:
    MagicIronMaze(){/*cout<<"Magic Iron Maze is constructed"<<endl;*/}
    virtual void Create()
    {
        CreateMaigicIronWall();
        CreateMaigicIronDoor();
        CreateMaigicIronMino();
        cout<<"Magic Iron Maze is created!"<<endl;
    }
protected:
    void CreateMaigicIronWall(){cout<<"Magic Iron Wall is created"<<endl;}
    void CreateMaigicIronDoor(){cout<<"Magic Iron Door is created"<<endl;}
    void CreateMaigicIronMino(){cout<<"Magic Iron Mino is created"<<endl;}
};

//A static Maze Creator
class MazeCreator
{
public:
    static void Create(Maze* pM)
    {
        pM->Create();
    }
};

//The Real executing program
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        int i;
        while(1)
        {
            cout<<"Please input episode(1-5):";
            cin>>i;
            if(i>=1&&i<=5)
                break;
            cout<<"Wrong Input"<<endl;
        }
        Maze* pMaze;

        //recognize input type and new a Maze pointer
        if(i == 1)
            pMaze = new Maze();
        else if(i == 2)
            pMaze = new StoneMaze();
        else if(i == 3)
            pMaze = new IronMaze();
        else if(i == 4)
            pMaze = new MagicStoneMaze();
        else if(i == 5)
            pMaze = new MagicIronMaze();
        else
            cout<<"Exeptional exit!"<<endl;

        //The line really create a maze that fit for the input type
        MazeCreator::Create(pMaze);

        //clear pointer to the Maze
        if(pMaze != NULL)
            delete pMaze;
    }

    return a.exec();
}
