#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

void printOut(double average, double sDev){
    ofstream afile;
    afile.open("numbers.txt", ios::app);
    afile<<"\nAverage = "<<average<<'\n';
    cout<<"Average = "<<average<<endl;
    afile<<"Standard Deviation = "<<sDev;
    cout<<"Standard Deviation = "<<sDev<<endl;
    afile.close();
}

int main() {
    double average(0.0), sDev(0.0), temp(0.0);
    double counter = 0;
    ifstream afile;
    string fileName = "numbers.txt";
    afile.open(fileName);
    //checking if file is open
    if (!afile.is_open()) {
        cerr << "unable to open " << fileName << endl;
    }
    else {//read entire file and output to screen
        while (!afile.eof()) {  // eof returns true if we have tried to read and nothing is left
            afile>>temp;
            average+=temp;
            counter++;
        }
        average = average/counter;
        afile.close();
    }
    counter = 0;
    afile.clear();
    while (!afile.eof()) {  // eof returns true if we have tried to read and nothing is left
        afile>>temp;
        sDev+=(pow(temp-average, 2));
        counter++;
    }
    sDev = sDev/counter;
    sDev = sqrt(sDev);
    afile.close();
    printOut(average, sDev);




}