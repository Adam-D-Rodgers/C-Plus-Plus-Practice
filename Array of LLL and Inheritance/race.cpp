//Adam Rodgers, 
//This class simulates the race and generates the terrain.  
#include "race.h"
using namespace std;

//defualt constructor
race::race(): finished_robots(0), finished_rexes(0) {
    robots.push_back(robot((char*)("ROBOT 1")));
    robots.push_back(robot((char*)("ROBOT 2")));
    robots.push_back(robot((char*)("ROBOT 3")));

    rexes.push_back(rex((char *)("REX 1")));
    rexes.push_back(rex((char *)("REX 2")));
    rexes.push_back(rex((char *)("REX 3")));

    toddlers.add(toddler((char*)("TODDLER JACK JACK"), (char *)"WILLOW"));
    toddlers.add(toddler((char*)("TODDLER MATILDA"), (char *)"QUATAMA"));
    toddlers.add(toddler((char*)("TODDLER GERTRUDE"),(char *)"MILIKEN"));
}

//simulates the race
void race::sim_race(){
  vector <robot>:: iterator v;
  list <rex>:: iterator i;
  
  track.make_array();

  cout << endl << endl << "THE GRAND RACE OF OREGON IN THE YEAR 3100 IS ABOUT TO BEGIN" << endl;
  cout << "AS USUAL WE WILL HAVE THREE RACES RUN SIMULTANEOUSLY" << endl;
  cout << "THIS YEAR OUR 3 RACES ARE BETWEEN TODDLERS, ROBOTS, AND T-REXES" << endl;
  cout << "THIS YEARS TRACK IS SPLIT INTO 5 CATEGORIES, EACH WITH DIFFRENT OBJECTS ON THE TRACK" << endl;
  cout << "HERE IS A BREAKDOWN OF THE RACE TRACK SHOWN ON THE BIG SCREEN!" << endl << endl << endl;
  track.displayW();
  cout << endl << endl << endl;
  cout << "AND WITHOUT FURTHER ADO..." << endl;
  cout << endl << endl << endl << "****************RACE START!!!****************" << endl << endl << endl;

  /*  toddlers.W_CLL(&track); //CLL copy test code
  cout << endl << endl << endl << endl << endl;

  CLL test(toddlers);
  test.W_CLL(&track);
  
  array_LLL test(track); //array of LLL copy test code
  cout << endl << endl << endl << endl << endl;
  test.displayW();*/


  for(int j = 0; j < 500; ++j){;
    toddlers.W_CLL(&track);
    i_list(rexes.begin());
    i_vectors(robots.begin());
  }
     
}

//itterates through list
void race::i_list(list<rex>::iterator i) {
  if(i == rexes.end()){
    return;
  }

  if(i->check_win(finished_rexes)){
    ++finished_rexes;
    i = rexes.erase(i);
  }
  else {
    i->terrain_effect(&track);
    i->events();
    ++i;
  }

    i_list(i);
}

//itterates through vectors
void race::i_vectors(vector<robot>::iterator v) {
  if(v == robots.end()){
    return;
  }

  if(v->check_win(finished_robots)){
    ++finished_robots;
    v = robots.erase(v);
  }
  else {
    v->terrain_effect(&track);
    v->events();
    ++v;
  }

    i_vectors(v);
}
