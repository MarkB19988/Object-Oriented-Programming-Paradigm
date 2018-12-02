#include <iostream>




class gumballMachine { //creates a class called gumballMachine
  public: //declares the public functions and variables

  
    gumballMachine(int qty) { //a contstrutor that sets the ammount of gumballs in the machine and sets the initial state to NoCoinInserted
      std::cout << "Welcome to the Gumball Machine!\n"; //Prints message
      std::cout << "There Are 3 Gumballs in the Machine\n"; //Prints message
      setGumballsLeft(qty); //sets the ammount of gumballs left
      setState(NoCoinInserted); //sets the initial state to NoCoinInserted
    }
    
    int getState() { //a function that returns the current state of the machine
      return state; //returns the current state
    }

    const int NoCoinInserted = 0; // sets a constant of NoCoinInserted to equal the value 0
    const int CoinInserted = 1; //sets a constant of CoinInserted to equal the value of 1
    const int CrankTurned = 2; // sets a constant if CrankTurned to equal the vlaue of 2


    void insertCoin() { //declares function insertCoin
      if (state == NoCoinInserted) { //checks that the current state is NoCoinInserted
        std::cout << "Coin Inserted\n"; //prints message
        setState(CoinInserted);//sets the state to CoinInserted
      } else {//if the current state isn't NoCoinInserted, this runs instead
        std::cout << "Cannot Insert Coin\n";//prints message
      }
    }

    void ejectCoin() {//declares function ejectCoin
      if (state == CoinInserted) {//checks that the current state is CoinInserted
        std::cout << "Coin Ejected\n";//prints message
        setState(NoCoinInserted);//sets the state to NoCoinInserted
      } else {//if the current state isn't CoinInserted, this runs instead
        std::cout << "Cannot Eject Coin, No Coin Inserted\n";//prints message
      }
    }

    void turnCrank() {//declares function turnCrank
      if (state == CoinInserted) {//checks that the current state is CoinInserted
        std::cout << "Crank Turned\n";//prints message
        setState(CrankTurned);//sets the state to CrankTurned
      } else {//if the current state isn't CoinInserted, this runs instead
        std::cout << "Cannot Turn Crank, Please Insert Coin\n";//prints message
      }
      if (state == CrankTurned) {//checks that the current state is CrankTurned
        std::cout << "Attempting to Dispense Gumball\n";//prints message
          if (gumballsLeft > 0) {//checks how many gumballs are left, if there is more than 0, this runs
            std::cout << "Gumball Dispensed, Enjoy!\n";//prints message
            gumballsLeft = (gumballsLeft - 1);//takes one away from gumballsLeft
            setState(NoCoinInserted);//sets the state to NoCoinInserted
          } else {//if there are 0 gumballsLeft, this runs instead
            std::cout <<"No Gumballs Left, Please Refil\n";//prints message
          }
      }
      }
   


  private: //declares private functions and values 
    int state;// declares an int called state
    
    void setState (int newState) { //creates the function that changes the current state of the machine
      state=newState;
    }

    int gumballsLeft; //declares an int called gumballsLeft

    void setGumballsLeft (int newGumballsLeft) { //creates the function that changes the amount of gumballsLeft
      gumballsLeft=newGumballsLeft;
    }
};






int main() {
  
  gumballMachine gumball(3);

    std::cout << "Current State: " << gumball.getState();
    std::cout << "\n";

    gumball.insertCoin();
    gumball.turnCrank();
    gumball.turnCrank();
    gumball.insertCoin();
    gumball.turnCrank();
    gumball.ejectCoin();
    gumball.insertCoin();
    gumball.ejectCoin();
    gumball.insertCoin();
    gumball.turnCrank();
    gumball.insertCoin();
    gumball.turnCrank();

}