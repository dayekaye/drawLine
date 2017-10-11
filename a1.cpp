#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


//prototype
vector<int> parsePS();
void writeToBuffer();

int main() {
  vector<int> coordinates, draw;
  int x1, y1, x2, y2, dx, dy, px, py, a, b, c;
  c = 0;
  //get coordinates from ps file
  coordinates = parsePS();

  //for each line of coordinates...
  for(int i = 0; i != coordinates.size(); i += 4){

    //do line drawing algorithm stuff

    //display current coordinates we are dealing with
    cout << "x1: " << coordinates[i] << endl;
    cout << "y1: " << coordinates[i+1] << endl;
    cout << "x2: " << coordinates[i+2] << endl;
    cout << "y2: " << coordinates[i+3] << endl;

    //compute helper variables
    x1 = coordinates[i];
    y1 = coordinates[i+1];
    x2 = coordinates[i+2];
    y2 = coordinates[i+3];
    dy = (y2-y1);
    dx = (x2-x1);

    cout << "dx: " << dx << endl;
    cout << "dy: " << dy << endl;

    //set current pixel location
    // p = 2*dy - dx;

    //decide on next pixel position with a bunch of if statements
    if(dx == 0){
      //vertical line
     for(int j = 0; x1 != x2; j+=3){
        draw.push_back(x1);
        draw.push_back(y1);
        //black color
        draw.push_back(c);
        x1++;
      }

    }

    if(dy == 0){
      //horizontal line
      // cout << "entered if statement" << endl;
      for(int j = 0; x1 != x2; j+=3){
        // cout << "entered for loop" << endl;
        draw.push_back(x1);
        draw.push_back(y1);
        //black color
        draw.push_back(c);

        // cout << "draw[j]: " << draw[j] << endl;
        // cout << "draw[j+1]: " << draw[j+1] << endl;
        // cout << "draw[j+2]: " << draw[j+2] << endl << endl;
        x1++;
      }
      cout << "draw size: " << draw.size() << endl << endl;
    }


    if(dy < dx && dx != 0){  
      //if 0 < m < 1
      for(int j = 0; x1 != x2; j+=3 ){
        a = dx;
        b = 0-dy;
        c = (dx*coordinates[i+3]) - (dx*coordinates[i+2]);

        int decision = (2*a*x1) + (2*b*y1) + (2*a + b + 2*c);
        cout << "decision: " << decision << endl << endl;

        if(decision > 0 || decision == 0){
          draw.push_back(x1 + 1);
          draw.push_back(y1 + 1);
          draw.push_back(1);
          y1++;
          x1++;
        }
        if(decision < 0){
          draw.push_back(x1 + 1);
          draw.push_back(y1);
          draw.push_back(1);
          x1++;
        }

      }
    }

    if( dy > dx ){
      //m > 1
      

    }

    if((dy < 0 && dy < dx) || (dx < 0 && dy < dx)){
      //-1 < m < 0
      while( x1 != x2 ){

      }
    }

    if((dy < 0 && dy > dx) || (dx < 0 && dy > dx)){
      // m < -1
      for(int j = 0; x1 != x2; j+=3 ){
        a = dx;
        b = 0-dy;
        c = (dx*coordinates[i+3]) - (dx*coordinates[i+2]);

        int decision = (2*a*x1) + (2*b*y1) + (a - 2*b + c);
        cout << "decision: " << decision << endl << endl;

        if(decision > 0 || decision == 0){
          draw.push_back(x1 + 1);
          draw.push_back(y1 + 1);
          draw.push_back(1);
          y1++;
          x1++;
        }
        if(decision < 0){
          draw.push_back(x1 + 1);
          draw.push_back(y1);
          draw.push_back(1);
          x1++;
        }
    }
  }



    //write to xpm file
    writeToBuffer();

  }

  return 0;
}

//PARSE PS FILE
vector<int> parsePS(){

  ifstream infile("hw1_1.ps");
  string line;
  vector<int> v;

  while(getline(infile, line))
  {
    istringstream iss(line);
    int n;

    while (iss >> n)
    {
      v.push_back(n);
    }

    // print v for testing
    // for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    // std::cout << *i << ' ' << endl;
 }
  return v;
}

//LINE DRAWING CALCULATIONS


//WRITE TO FRAME BUFFER (XPM FILE)
void writeToBuffer(){
  ofstream ofs;
  ofs.open ("test.txt", std::ofstream::out | std::ofstream::app);

  ofs << "/* XPM /*" << endl << "static char *sco100[] = {" << endl << endl << "/* width height num_colors chars_per_pixel/*" << endl << 
  "\"500 500 1 1\"," << endl << endl << "/* colors /*"  << endl << "\"- c #000000\"," << endl << "\"X c #ffffff\"," << endl << endl << "/* pixels /*";

  ofs.close();
}