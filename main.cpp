#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
string s1, s2;
char space[3][3] = {
  {
    '1',
    '2',
    '3'
  },
  {
    '4',
    '5',
    '6'
  },
  {
    '7',
    '8',
    '9'
  }
};
int row;
int column;
int p = 72;
char token = 'X';
bool tiee;
bool wannaPlay = true;
int digit;
bool endOfProgram = false;
char again;
int p1Score = 0;
int p2Score = 0;
int games = 0;
char gameSelector;
bool computer;
int draws = 0;
class Players {
  private: string Name;
  int Score;
  public: Players(string n) {
    Name = n;
    Score = 0;
  }
  void setName(string name) {
    Name = name;
  }
  void setScore(int score) {
    Score = score;
  }
  string getName() {
    return Name;
  }
  int getScore() {
    return Score;
  }
};

Players p1(" ");
Players p2(" ");
bool functionThree();
void SinglerPlayer();
void Selection();
bool checkForWin(char player);
int computerMove();
void TwoPlayerFunction();
void GameInterface();
void playAgainFace();
void DemoGame();
void FACE();
void selectGame();
void CheckWin();

int main() {

  system("Color E4");
  PlaySound("music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
  FACE();
  cout << endl << endl << endl << endl << endl << endl << endl << endl;
  system("CLS");
  selectGame();
  Selection();

  while (wannaPlay == true) {
    system("CLS");
    games++;
    token == 'X';
    tiee = false;
    system("CLS"); 

    while (!functionThree()) {
      GameInterface();
      if (gameSelector == 1) {
        DemoGame();
      } else if (gameSelector == 2) {
        SinglerPlayer();
      } else if (gameSelector == 3) {
        TwoPlayerFunction();
      } else if (gameSelector == 4) {
        return 0;
      } else {
        return 0;
      }

      functionThree();
      system("CLS");
    }
    CheckWin();
  };
  return 0;
}

void CheckWin() {
	if (token == 'X' && tiee == false) {
    	if (gameSelector == 1) {
    		cout << endl << p2.getName() << " Won The Game!!!" << endl;
		}
       else if (gameSelector == 2) {
      	cout << endl << " The Computer Won The Game!" << endl;
	  } else {
	  	cout << endl << " Congratulations " << p2.getName() << ", You Won The Game!!!" << endl;
	  }
      p2.setScore(p2.getScore() + 1);
      GameInterface();

    } else if (token == 'O' && tiee == false) {
    	if (gameSelector == 1) {
    		cout << endl << p1.getName() << ", You Won The Game!!!" << endl;
		} else if (gameSelector == 2) {        
        cout << endl << " Congratulations " << p1.getName() << ", You Won The Game!!!" << endl;
      } else {
        cout << endl << " Congratulations " << p1.getName() << ", You Won The Game!!!" << endl;
      }
      p1.setScore(p1.getScore() + 1);
      GameInterface();
    } else {
      draws++;
      cout << endl << " It is a draw" << endl;
      GameInterface();
    }
    token = 'X';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        space[i][j] = '1' + i * 3 + j;
      }
    }
    Sleep(2000);
    system("CLS");
    playAgainFace();
    again = getch();
    if (again == 27) {
      system("CLS");
      cout << endl << endl << endl << endl << endl << endl << endl << endl;
      cout << "                                            GAME ENDED      " << endl <<
              "                                      THANK YOU FOR PLAYING!" << endl;
                cout << " ";
              	for (int i = 1; i <= 31; i++) {
              	cout << "__ ";
              	Sleep(5);
			  }
      wannaPlay = false;
    } else {
      wannaPlay = true;
    }
}
void TwoPlayerFunction() {
  int digit;

  if (token == 'X') {
    cout << endl << " " << p1.getName() << " Please Enter: ";
    digit = getche();
    digit -= 48;
    cout << endl;

  }
  if (token == 'O') {
    cout << endl << " " << p2.getName() << " Please Enter: ";
    digit = getche();
    digit -= 48;
    cout << endl;

  }
  if (digit == 1) {
    row = 0;
    column = 0;
  }
  if (digit == 2) {
    row = 0;
    column = 1;
  }
  if (digit == 3) {
    row = 0;
    column = 2;
  }
  if (digit == 4) {
    row = 1;
    column = 0;
  }
  if (digit == 5) {
    row = 1;
    column = 1;
  }
  if (digit == 6) {
    row = 1;
    column = 2;
  }
  if (digit == 7) {
    row = 2;
    column = 0;
  }
  if (digit == 8) {
    row = 2;
    column = 1;
  }
  if (digit == 9) {
    row = 2;
    column = 2;
  } else if (digit < 1 || digit > 9) {
    cout << " Invalid !!!" << endl;
    Sleep(300);
  }
  if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {
    space[row][column] = 'X';
    token = 'O';
  } else if (token == 'O' && space[row][column] != 'O' && space[row][column] != 'X') {
    space[row][column] = 'O';
    token = 'X';
  } else if (space[row][column] == 'X' && space[row][column] == 'O') {
    cout << " There is not empty space!" << endl;
    TwoPlayerFunction();
    Sleep(2000);
  }
}
void SinglerPlayer() {
  if (token == 'X') {
    cout << endl << " " << p1.getName() << " Please Enter: ";
    digit = getche();
    digit -= 48;
    cout << endl;

  }
  if (token == 'O') {
    cout << endl << " " << p2.getName() << ": ";
    srand(time(0));
    int time = (rand() % 10 + 1) * 500;
    Sleep(time);
    digit = computerMove();

  }
  if (digit == 1) {
    row = 0;
    column = 0;
  }
  if (digit == 2) {
    row = 0;
    column = 1;
  }
  if (digit == 3) {
    row = 0;
    column = 2;
  }
  if (digit == 4) {
    row = 1;
    column = 0;
  }
  if (digit == 5) {
    row = 1;
    column = 1;
  }
  if (digit == 6) {
    row = 1;
    column = 2;
  }
  if (digit == 7) {
    row = 2;
    column = 0;
  }
  if (digit == 8) {
    row = 2;
    column = 1;
  }
  if (digit == 9) {
    row = 2;
    column = 2;
  } else if (digit < 1 || digit > 9) {
    cout << " Invalid !!!" << endl;
    Sleep(300);
  }
  if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {
    space[row][column] = 'X';
    token = 'O';
  } else if (token == 'O' && space[row][column] != 'O' && space[row][column] != 'X') {
    space[row][column] = 'O';
    token = 'X';
  } else if (space[row][column] == 'X' && space[row][column] == 'O') {
    cout << " There is not empty space!" << endl;
    TwoPlayerFunction();
    Sleep(2000);
  }
}
void DemoGame() {
  if (token == 'X') {
    cout << endl << " " << p1.getName() << ": ";
    srand(time(0));
    int time = (rand() % 10 + 1) * 500;
    Sleep(time);
    digit = computerMove();

  }
  if (token == 'O') {
    cout << endl << " " << p2.getName() << ": ";
    srand(time(0));
    int time = (rand() % 10 + 1) * 500;
    Sleep(time);
    digit = computerMove();
  }
  if (digit == 1) {
    row = 0;
    column = 0;
  }
  if (digit == 2) {
    row = 0;
    column = 1;
  }
  if (digit == 3) {
    row = 0;
    column = 2;
  }
  if (digit == 4) {
    row = 1;
    column = 0;
  }
  if (digit == 5) {
    row = 1;
    column = 1;
  }
  if (digit == 6) {
    row = 1;
    column = 2;
  }
  if (digit == 7) {
    row = 2;
    column = 0;
  }
  if (digit == 8) {
    row = 2;
    column = 1;
  }
  if (digit == 9) {
    row = 2;
    column = 2;
  } else if (digit < 1 || digit > 9) {
    cout << " Invalid !!!" << endl;
    Sleep(300);
  }
  if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {
    space[row][column] = 'X';
    token = 'O';
  } else if (token == 'O' && space[row][column] != 'O' && space[row][column] != 'X') {
    space[row][column] = 'O';
    token = 'X';
  } else if (space[row][column] == 'X' && space[row][column] == 'O') {
    cout << " There is not empty space!" << endl;
    TwoPlayerFunction();
    Sleep(2000);
  }
}
int computerMove() {
  int x;
  if (space[0][1] == 'O' && space[0][2] == 'O' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } else if (space[1][0] == 'O' && space[2][0] == 'O' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } else if (space[1][1] == 'O' && space[2][2] == 'O' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } 
  
  else if (space[0][0] == 'O' && space[0][2] == 'O' && space[0][1] != 'X' && space[0][1] != 'O') {
    x = 2;
  } else if (space[1][1] == 'O' && space[2][1] == 'O' && space[0][1] != 'X' && space[0][1] != 'O') {
    x = 2;
  } 
  
  else if (space[0][0] == 'O' && space[0][1] == 'O' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } else if (space[1][2] == 'O' && space[2][2] == 'O' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } else if (space[1][1] == 'O' && space[2][0] == 'O' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } 
  
  else if (space[0][0] == 'O' && space[2][0] == 'O' && space[1][0] != 'X' && space[1][0] != 'O') {
    x = 4;
  } else if (space[1][1] == 'O' && space[1][2] == 'O' && space[1][0] != 'X' && space[1][0] != 'O') {
    x = 4;
  } 
  
  else if (space[0][0] == 'O' && space[2][2] == 'O' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[0][2] == 'O' && space[2][0] == 'O' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[0][1] == 'O' && space[2][1] == 'O' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[1][0] == 'O' && space[1][2] == 'O' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } 
  
  else if (space[1][0] == 'O' && space[1][1] == 'O' && space[1][2] != 'X' && space[1][2] != 'O') {
    x = 6;
  } else if (space[0][2] == 'O' && space[2][2] == 'O' && space[1][2] != 'X' && space[1][2] != 'O') {
    x = 6;
  }
  
   else if (space[0][0] == 'O' && space[1][0] == 'O' && space[2][0] != 'X' && space[2][0] != 'O') {
    x = 7;
  } else if (space[2][1] == 'O' && space[2][2] == 'O' && space[2][0] != 'X' && space[2][0] != 'O') {
    x = 7;
  } else if (space[0][2] == 'O' && space[1][1] == 'O' && space[2][0] != 'X' && space[2][0] != 'O') {
    x = 7;
  }
  
  else if (space[2][0] == 'O' && space[2][2] == 'O' && space[2][1] != 'X' && space[2][1] != 'O') {
    x = 8;
  } else if (space[0][1] == 'O' && space[1][1] == 'O' && space[2][1] != 'X' && space[2][1] != 'O') {
    x = 8;
  }
  
   else if (space[0][0] == 'O' && space[1][1] == 'O' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } else if (space[2][0] == 'O' && space[2][1] == 'O' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } else if (space[0][2] == 'O' && space[1][2] == 'O' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } 
  
  else if (space[0][1] == 'X' && space[0][2] == 'X' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } else if (space[1][0] == 'X' && space[2][0] == 'X' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } else if (space[1][1] == 'X' && space[2][2] == 'X' && space[0][0] != 'X' && space[0][0] != 'O') {
    x = 1;
  } 
  
  else if (space[0][0] == 'X' && space[0][2] == 'X' && space[0][1] != 'X' && space[0][1] != 'O') {
    x = 2;
  } else if (space[1][1] == 'X' && space[2][1] == 'X' && space[0][1] != 'X' && space[0][1] != 'O') {
    x = 2;
  } 
  
  else if (space[0][0] == 'X' && space[0][1] == 'X' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } else if (space[1][2] == 'X' && space[2][2] == 'X' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } else if (space[1][1] == 'X' && space[2][0] == 'X' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 3;
  } 
  
  else if (space[0][0] == 'X' && space[2][0] == 'X' && space[1][0] != 'X' && space[1][0] != 'O') {
    x = 4;
  } else if (space[1][1] == 'X' && space[1][2] == 'X' && space[1][0] != 'X' && space[1][0] != 'O') {
    x = 4;
  } 
  
  else if (space[0][0] == 'X' && space[2][2] == 'X' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[0][2] == 'X' && space[2][0] == 'X' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[0][1] == 'X' && space[2][1] == 'X' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  } else if (space[1][0] == 'X' && space[1][2] == 'X' && space[1][1] != 'X' && space[1][1] != 'O') {
    x = 5;
  }
  
   else if (space[1][0] == 'X' && space[1][1] == 'X' && space[1][2] != 'X' && space[1][2] != 'O') {
    x = 6;
  } else if (space[0][2] == 'X' && space[2][2] == 'X' && space[1][2] != 'X' && space[1][2] != 'O') {
    x = 6;
  } 
  
  else if (space[0][0] == 'X' && space[1][0] == 'X' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 7;
  } else if (space[2][1] == 'X' && space[2][2] == 'X' && space[0][2] != 'X' && space[0][2] != 'O') {
    x = 7;
  } else if (space[0][2] == 'X' && space[1][1] == 'X' && space[0][2] != 'X' && space[0][2] != 'O' ) {
  	x = 7;
  }


  
   else if (space[2][0] == 'X' && space[2][2] == 'X' && space[2][1] != 'X' && space[2][1] != 'O') {
    x = 8;
  } else if (space[0][1] == 'X' && space[1][1] == 'X' && space[2][1] != 'X' && space[2][1] != 'O') {
    x = 8;
  } 
  
  else if (space[0][0] == 'X' && space[1][1] == 'X' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } else if (space[2][0] == 'X' && space[2][1] == 'X' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } else if (space[0][2] == 'X' && space[1][2] == 'X' && space[2][2] != 'X' && space[2][2] != 'O') {
    x = 9;
  } 
  
  else {
    do {
      srand(time(0));
      x = rand() % 9 + 1;
      if (x == 1) {
        row = 0;
        column = 0;
      } else if (x == 2) {
        row = 0;
        column = 1;
      } else if (x == 3) {
        row = 0;
        column = 2;
      } else if (x == 4) {
        row = 1;
        column = 0;
      } else if (x == 5) {
        row = 1;
        column = 1;
      } else if (x == 6) {
        row = 1;
        column = 2;
      } else if (x == 7) {
        row = 2;
        column = 0;
      } else if (x == 8) {
        row = 2;
        column = 1;
      } else if (x == 9) {
        row = 2;
        column = 2;
      }

    } while (space[row][column] == 'O' || space[row][column] == 'X');
  }
  return x;
}
bool functionThree() {
  for (int i = 0; i < 3; i++) {
    if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
      return true;
    }
  }
  if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[2][0] == space[0][2])) {
    return true;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (space[i][j] != 'X' && space[i][j] != 'O') {
        return false;
      }
    }
  }
  tiee = true;
  return true;
}

void FACE() {
    system("Color E4");

    int x = 0;
    cout << endl;
    while (x < 30.5) {

      system("cls");
      cout << endl;
      for (int i = 0; i < x; i++) {
        cout << " ";
      }

      cout << "NAME: JAI KUMAR   ROLL NO: 22SW044" << endl;
      x++;
      Sleep(1);
    }
    cout << endl;
    cout << setw(p) << "###################################################" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |             TIC TAC TOE             |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |             CREATED  BY             |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |             JAI   KUMAR             |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "###################################################" << endl;

    Sleep(2000);
    system("cls");
};

void playAgainFace() 
{
	cout << endl << endl << endl;
    cout << setw(p) << "###################################################" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |            PRESS ANY KEY            |     #" << endl;
    cout << setw(p) << "#     |            TO PLAY AGAIN            |     #" << endl;
    cout << setw(p) << "#     |         (PRESS ESC TO EXIT)         |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "###################################################" << endl;
}

void selectGame()
{
	cout << endl << endl << endl;
    cout << setw(p) << "###################################################" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |              SELECT GAME            |     #" << endl;
    cout << setw(p) << "#     |            1.THE DEMO GAME          |     #" << endl;
    cout << setw(p) << "#     |            2.SINGLE PLAYER          |     #" << endl;
    cout << setw(p) << "#     |            3.DOUBLE PLAYER          |     #" << endl;
    cout << setw(p) << "#     |            4.EXIT THE GAME          |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     |                                     |     #" << endl;
    cout << setw(p) << "#     +-------------------------------------+     #" << endl;
    cout << setw(p) << "#                                                 #" << endl;
    cout << setw(p) << "###################################################" << endl;
}



void GameInterface() 
{
	cout << "  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << " |  _______ ________ _______   |" << endl;
    cout << " | |       |        |       |  |" << endl;
    cout << " | |   " << space[0][0] << "   |"<< "   " << space[0][1] << "    |"<< "   " << space[0][2] << "   |  |"<< "\t\t\tGAMES: " << games << endl; 
    cout << " | |_______|________|_______|  |" << "\t\t\tScore:" << endl;
    cout << " | |       |        |       |  |" << "\t\t\t  " << p1.getName() << ": " << p1.getScore() << endl; 
    cout << " | |   " << space[1][0] << "   |"<< "   " << space[1][1] << "    |"<< "   " << space[1][2] << "   |  |\t\t\t  " << p2.getName() << ": " << p2.getScore() << endl;
    cout << " | |_______|________|_______|  |" << "\t\t\t  Draws: " << draws << endl;
    cout << " | |       |        |       |  |" << endl;
    cout << " | |   " << space[2][0] << "   |"<< "   " << space[2][1] << "    |"<< "   " << space[2][2] << "   |  |"<<endl;
    cout << " | |_______|________|_______|  |" << endl;
    cout << " |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|  " << endl;
}

void Selection() {
  while (gameSelector != 1 && gameSelector != 2 && gameSelector != 3 && gameSelector != 4) {
    gameSelector = getch();
    gameSelector -= 48;
    if (gameSelector == 1) {
      system("CLS");
      p1.setName("Player 1");
      p2.setName("Player 2");
    } else if (gameSelector == 2) {
      system("CLS");
      cout << endl << endl << endl << endl  << endl  << endl << endl << endl << endl << endl;
      cout << "                                       Your Player: ";
      getline(cin, s1);
      cout << endl;
      p1.setName(s1);
      p2.setName("Computer");
      Sleep(2000);
      system("CLS");
    } else if (gameSelector == 3) {
      system("CLS");
      cout << endl << endl << endl << endl << endl << endl << endl << endl;
      cout << "                                      First Player: ";
      getline(cin, s1);
      cout << endl;
      cout << "                                      Second Player: ";
      getline(cin, s2);
      p1.setName(s1);
      p2.setName(s2);
      Sleep(2000);
      system("CLS");
    } else if (gameSelector == 4) {
      system("CLS");
      cout << endl << endl << endl << endl << endl << endl << endl << endl;
      cout << "                                            GAME ENDED      " << endl <<
              "                                      THANK YOU FOR PLAYING!" << endl;
              cout << " ";
              for (int i = 1; i <= 31; i++) {
              	cout << "__ ";
              	Sleep(5);
			  }
      wannaPlay = false;
    }
  }
}
