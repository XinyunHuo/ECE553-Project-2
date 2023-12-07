#include "GameEngine.h"
#include <iostream>
#include <fstream>
#include <algorithm>

GameEngine::GameEngine() : field(nullptr), fieldHeight(0), fieldWidth(0), score(0), NUMBEROFVEGGIES(30), NUMBEROFRABBITS(5), captain(nullptr) {}


// @brief This function is to initialize the game
void GameEngine::initializeGame()
{
    initVeggies();
    initCaptain();
    initRabbits();
    score = 0;
}

// @brief This function is to initialize vegetable in the game
void GameEngine::initVeggies()
{
    string fileName;
    cout << "Please enter the name of the vegetable point file: ";
    cin >> fileName;

    ifstream veggieFile(fileName); //read from file

    while (!veggieFile.is_open())
    {
        cout << fileName << " does not exist! Please enter the name of the vegetable point file: ";
        cin >> fileName;
        veggieFile.open(fileName);
    }

    string line;
    getline(veggieFile, line);
    string dataLine;
    dataLine = line.substr(line.find(",")+1); 

    fieldHeight = stoi(dataLine.substr(0,dataLine.find(","))); //get field height from file
    fieldWidth = stoi(dataLine.substr(dataLine.find(",")+1)); //get field width from file

    field = new FieldInhabitant**[fieldWidth];
    for (int i = 0; i < fieldWidth; i++)
    {
        field[i] = new FieldInhabitant*[fieldHeight];
        for (int j = 0; j < fieldHeight; j++)
        {
            field[i][j] = nullptr; //set field as empty
        }
    }

    while (getline(veggieFile, line)) //get each vegetable's info
    {
        string name;
        string symbol;
        int points;

        name = line.substr(0, line.find(",")); //get vegetable name

        dataLine = line.substr(line.find(",")+1);

        symbol = dataLine.substr(0, dataLine.find(",")); //get vegetable symbol
        points = stoi(dataLine.substr(dataLine.find(",")+1)); //get vegetable point
        

        Veggie* veggie = new Veggie(name, symbol, points); //add vegetable to the class
        veggies.push_back(veggie);

    }

    //generate 30 vegetables in the feild
    for (int i = 0; i < 30; i++)
    {
        int x;
        int y;

        cout << "1" << endl;
        
        srand(time(0)); //seed random number

        do
        {
            x = rand() % fieldWidth;
            y = rand() % fieldHeight;
        } while (field[x][y] != nullptr);

        int randomNum;
        randomNum = rand() % 6;

        Veggie* veggie = veggies[randomNum];
        string name = veggies[randomNum]->getVegetableName();
        string symbol = veggies[randomNum]->getSymbol();
        int points = veggies[randomNum]->getPointValue();

        veggie = new Veggie(name, symbol, points); //add vegetable to the class       
        veggies.push_back(veggie);
        field[x][y] = veggie; //log veggie in field
    }

    veggieFile.close();

}

// @brief Thsi function is to initialize captain position
void GameEngine::initCaptain()
{
    int x;
    int y;

    do //Generate captain in a empty place
    {
        x = rand() % fieldWidth;
        y = rand() % fieldHeight;
    } while (field[x][y] != nullptr);

    captain = new Captain(x, y);
    field[x][y] = captain; //log captain in field
}

// @brief Thsi function is to initialize rabbit position
void GameEngine::initRabbits()
{
    for (int i = 0; i < 5; i++) //Generate 5 rabbits
    {
        int x;
        int y;

        do
        {
            x = rand() % fieldWidth;
            y = rand() % fieldHeight;
        } while (field[x][y] != nullptr);

        Rabbit* rabbit = new Rabbit(x, y);
        rabbits.push_back(rabbit);
        field[x][y] = rabbit; //log rabbit in field
    }
}

// @brief Thsi function is to get number of remaining vegetable
int GameEngine::remainingVeggies() const
{
    int remainNum = 0;
    for (int i = 0; i < fieldWidth; i++) //search each colum
    {
        for (int j = 0; j < fieldHeight; j++) //search each row
        {
            if (dynamic_cast<Veggie*>(field[i][j]) != nullptr) //judge if item is vegetable
            {
                remainNum++;
            }
        }
    }
    return remainNum;
}

// @brief Thsi function is to output game intro
void GameEngine::intro()
{
    cout << "Welcome to Captain Veggie!" << endl;
    cout << "The rabbits have invaded your garden and you must harvest" << endl;
    cout << "as many vegetables as possible before the rabbits eat them" << endl;
    cout << "all! Each vegetable is worth a different number of points" << endl;
    cout << "so go for the high score!" << endl;
    cout << endl;

    cout << "The vegetables are: " << endl;

    for (int i = 0; i < 6; i++)
    {
        Veggie* veggie = veggies[i];
        
        cout << veggies[i]->getSymbol() << ": " << veggies[i]->getVegetableName() << " " << veggies[i]->getPointValue() << " points" << endl;
    }

    cout << endl;
}

// @brief Thsi function is to print field
void GameEngine::printField()
{
    for (int i = 0; i < fieldWidth*3 + 2; i++) //generate edge of the field
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < fieldHeight; i++)
    {
        cout << "#";
        for (int j = 0; j < fieldWidth; j++)
        {
            if (field[j][i] == nullptr) //generate space if position is empty
            {
                cout << "   ";
            }
            else
            {
                cout << " " << field[j][i]->getSymbol() << " "; //generate needed symbol
            }
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < fieldWidth*3 + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
}

// @brief Thsi function is to get the player score
int GameEngine::getScore() const
{
    return score;
}

// @brief Thsi function is to move rabbit position
void GameEngine::moveRabbits()
{
    for (auto& rabbit : rabbits)
    {
        srand(time(0));
        int direction = rand() % 9;

        int x;
        int y;
        x = rabbit->getXCoordinate(); //get rabbit current position
        y = rabbit->getYCoordinate();

        switch (direction)
        {
            case 0: //upper left
                x = x - 1;
                y = y - 1;
                break;
            case 1: //up
                x = x - 1;
                y = y;
                break;
            case 2: //upper right
                x = x - 1;
                y = y + 1;
                break;
            case 3: //left
                x = x;
                y = y - 1;
                break;
            case 4: //not move
                x = x;
                y = y;
                break;
            case 5: //right
                x = x;
                y = y + 1;
                break;
            case 6: //lower left
                x = x + 1;
                y = y - 1;
                break;
            case 7: //down
                x = x + 1;
                y = y;
                break;
            case 8: //lower right
                x = x + 1;
                y = y + 1;
                break;
        }

        if (x < 0 || y < 0 || x >= fieldWidth || y >= fieldHeight) //check if out of bound
        {
            continue;
        }
        else if (field[x][y] == rabbit || field[x][y] == captain) //check if the position taken by captain
        {
            continue;
        }
        else if (field[x][y] == nullptr) //check empty
        {
            field[x][y] = rabbit;
            field[rabbit->getXCoordinate()][rabbit->getYCoordinate()] = nullptr;

            rabbit->setXCoordinate(x);
            rabbit->setYCoordinate(y);
        }
        else if (field[x][y] == dynamic_cast<Veggie*>(field[x][y])) //check vegetable
        {
            Veggie* veggie = dynamic_cast<Veggie*>(field[x][y]);
            field[x][y] = rabbit;
            field[rabbit->getXCoordinate()][rabbit->getYCoordinate()] = nullptr; //last position clean

            rabbit->setXCoordinate(x); //store new position
            rabbit->setYCoordinate(y);

            auto it = find(veggies.begin(), veggies.end(), veggie); //clear memory
            if (it != veggies.end())
            {
                veggies.erase(it);
                delete veggie;
            }
        }
    }
}

// @brief Thsi function is to move captain position vertical
// @param movement indicate the direction and length of movement
void GameEngine::moveCptVertical(int movement)
{
    int x;
    int y;

    x = captain->getXCoordinate();
    y = captain->getYCoordinate();

    y += movement;

    if (y >= 0 && y < fieldHeight) //check boundary
    {
        if (field[x][y] == nullptr)
        {
            field[x][y] = captain;
            field[captain->getXCoordinate()][captain->getYCoordinate()] = nullptr;

            captain->setXCoordinate(x);
            captain->setYCoordinate(y);
        }
        else if (dynamic_cast<Veggie*>(field[x][y])) //check vegetable
        {
            Veggie* veggie = dynamic_cast<Veggie*>(field[x][y]);

            field[x][y] = captain;
            field[captain->getXCoordinate()][captain->getYCoordinate()] = nullptr;

            captain->setXCoordinate(x);
            captain->setYCoordinate(y);

            captain->addVeggie(veggie);
            score += veggie->getPointValue();

            cout << "Yummy! A delicious " << veggie->getVegetableName();
        }
        else if (dynamic_cast<Rabbit*>(field[x][y])) //check rabbit
        {
            cout << "Don't step on the bunnies!" << endl;
        }
        
    }
    else
    {
        cout << "You can't move that way!" << endl;
    }
}

// @brief Thsi function is to move captain position horizontal
// @param movement indicate the direction and length of movement
void GameEngine::moveCptHorizontal(int movement)
{
    int x;
    int y;

    x = captain->getXCoordinate();
    y = captain->getYCoordinate();

    x += movement;

    if (x >= 0 && x < fieldWidth)
    {
        if (field[x][y] == nullptr)
        {
            field[x][y] = captain;
            field[captain->getXCoordinate()][captain->getYCoordinate()] = nullptr;

            captain->setXCoordinate(x);
            captain->setYCoordinate(y);
        }
        else if (dynamic_cast<Veggie*>(field[x][y]))
        {
            Veggie* veggie = dynamic_cast<Veggie*>(field[x][y]);

            field[x][y] = captain;
            field[captain->getXCoordinate()][captain->getYCoordinate()] = nullptr;

            captain->setXCoordinate(x);
            captain->setYCoordinate(y);

            captain->addVeggie(veggie);
            score += veggie->getPointValue();

            cout << "Yummy! A delicious " << veggie->getVegetableName();
        }
        else if (dynamic_cast<Rabbit*>(field[x][y]))
        {
            cout << "Don't step on the bunnies!" << endl;
        }
        
    }
    else
    {
        cout << "You can't move that way!" << endl;
    }
}

// @brief this function is to move captain base on user input
void GameEngine::moveCaptain()
{
    string direction_check; // this is for checking the input length is one, or re-enter
    char direction;
    cout << "Would you like to move up(W), down(S), left(A), or right(D):";
    cin >> direction_check;
    
    if (direction_check.length() != 1) {
        cout << direction_check << " is not a valid option" << endl;
    }
    else {
        direction = direction_check.at(0);
        direction = tolower(direction);

        switch (direction)
        {
        case 'w': //up
            moveCptVertical(-1);
            break;
        case 'a': //left
            moveCptHorizontal(-1);
            break;
        case 's': //down
            moveCptVertical(1);
            break;
        case 'd': //right
            moveCptHorizontal(1);
            break;
        default: //invalid input
            cout << direction << " is not a valid option" << endl;
        }
    }
}

// @brief this function indicate the end of game
void GameEngine::gameOver()
{
    cout << "GAME OVER!" << endl;
    cout << "You managed to harvest the followingg vegetables:" << endl;
    const vector<Veggie*>& collectedVeggie = captain->getCollectedVeggies();
    for (const auto& veggie : collectedVeggie) //output all the vegetables collected
    {
        cout << veggie->getVegetableName() << endl;
    }
    cout << "Your score was: " << score << endl; //output user score
}
