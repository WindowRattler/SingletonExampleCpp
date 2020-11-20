//BenjaminKramer
//11/19/2020

//Singleton data structure utilizing
//a filestream that acts as a time capsule
//storing a previous version of the singleton
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;



//Datastore as a Singleton
//PRIVATE constructor
//PUBLIC method that RETURNS pointer to the object.
class DataStore {

  private:
    static DataStore *instance;
    int data;
  
    //Private constructor so that no objects can be created.
    DataStore() {
        data = 0;
    }

   public:
    static DataStore *getInstance() {
        if (!instance) {
          instance = new DataStore;
        }
        return instance;
    }

    int getData() {
        return data;
    }

    void setData(int newData) {
        data = newData;
    }
};


//Initialize pointer to zero so that it can be 
//initialized in first call to getInstance()
//sort of sucks to have to do this, but in C++, we 
//have to do it this way
DataStore *DataStore::instance = nullptr;

int main(){

  //clock/time initialized
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  //file creation
  ofstream singletonfile;

  //a little weird - calling a method instead 
  //of a constructor to get "s"
  //but ...ok right?
  DataStore *s = s->getInstance();
  cout << "s->getInstance() " << endl;

  //shouldn't be surprising output here, right?
  cout << "s->getData() \t\t" << s->getData() << endl << endl;
  

  //here we have a "setter" - no biggie
  s->setData(100);
  cout << "s->setData(100) " << endl;

  //bet you'll never guess what this is!
  cout << "s->getData() \t\t" << s->getData() << endl << endl;

  //No big deal, same as above right?
  DataStore *t = t->getInstance();
  cout << "t->getInstance() " << endl;

  //boom. This is where the Singleton is useful. 
  //We have ONE actual object.
  //unlike above, "t" didn't have it's "data" 
  //set to 0. It *IS* "s"
  cout << "t->getData() \t\t" << t->getData() << endl << endl;

  //File open/save time-stamp
  printf ("Time and Date File Saved: %s", asctime(timeinfo));
  cout << endl;
  //Opening, writing, and closing filestream
  //We are storing the initial values of the singleton here
  //This functions like a time capsule
  singletonfile.open ("Datastore.txt");
  singletonfile << "Initial Singleton Values"<< endl << endl;
  singletonfile << "s->getData() \t\t" << s->getData() << endl << endl;
  singletonfile << "t->getData() \t\t" << t->getData() << endl << endl;
  singletonfile.close();

  //New values set
  t->setData(200);
  cout << "t->setData(200) " << endl;

  //bet you'll never guess what this is!
  cout << "t->getData() \t\t" << t->getData() << endl << endl;

  //bet you'll never guess what this is!
  cout << "s->getData() \t\t" << s->getData() << endl;

  return 0;
}
