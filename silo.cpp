#include "silo.h"
#include <math.h>

        struct temp {
  int numWheat;
  int capacity;
  int level;
  unsigned int upgradeStartTime;
  int shenaseP;
  bool isBeingUpgraded;
};

silo::silo(int shenaseP){


  temp A;

  ifstream fin;
  ofstream fout;
  fin.open("silo.txt");
  if (!fin) {
    fin.close();
    fout.open("silo.txt");
    fout.close();
    fin.open("silo.txt", ios::app);
  }
  bool find = 1;
  while (!fin.eof()) {/////////////////////taghir dar hame
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == shenaseP) {
      numWheat=A.numWheat;
      capacity = A.capacity;
      level = A.level;
      upgradeStartTime=A.upgradeStartTime;
      shenaseP = A.shenaseP;
      isBeingUpgrad=A.isBeingUpgraded;
            find=0;
      break;
    }
  }
  fin.close();
  if (find) {    //first login
    numWheat=0;
      capacity = 10;
      level = 1;
      upgradeStartTime=0;
      isBeingUpgraded=0;
    //..................
    A.numWheat=0;
      A.capacity = 10;
      A.level = 1;
      A.upgradeStartTime=0;
      A.isBeingUpgraded=0;
            A.shenaseP=shenaseP;

    fout.open("silo.txt",ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();
  }

    }
    int silo::getCapaticy(){return capacity;}
    int silo::getNumWheat(){return numWheat;}
    int silo::getLevel(){return level;}
    int silo::addWheat(int addedWheatNumber){
    int freeSpace=capacity-numWheat;
    if(addedWheatNumber<=freeSpace){
        numWheat+=addedWheatNumber;
return 1;
}
    else
return 0;
}
void silo::checkForUpgrade(int shenaseP){
    
}
bool silo::isFull(){
if(numWheat==capacity)
    return true;
else
    return false;
}
  void storage::update_file() {

	temp p;

	ofstream outfile;//for writing in new file.
	ifstream infile;//for reading.

	infile.open("silo.txt", ios::in);
	if (infile.is_open()) {
		outfile.open("silo-temp.txt", ios::out);//make file.
		infile.seekg(0, ios::end);
		int size = infile.tellg();
		infile.seekg(0, ios_base::beg);
		while (infile.tellg() < size) {
			infile.read((char*)&p, sizeof(p));
			if (shenaseP == p.shenaseP) {

       p.numWheat=numWheat;
   p.capacity=capacity;
   p.level=level;
  p.upgradeStartTime=upgradeStartTime;
   p.shenaseP=shenaseP;
   p.isBeingUpgraded=isBeingUpgraded;
			}
			outfile.write((char*)&p, sizeof(p));
		}
		outfile.close();
		infile.close();
		remove("silo.txt");
		rename("silo-temp.txt", "silo.txt");
	}
}
