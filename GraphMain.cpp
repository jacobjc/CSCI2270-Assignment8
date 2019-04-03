#include "Graph.cpp"
#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    Graph* myGraph = new Graph();
    ifstream fr;
    fr.open(argv[1]);
    string line = "";

    getline(fr, line); //first line
    // cout<<line<<endl;
    stringstream ss(line);
    string line2 = "";
    vector <string> cities;

    getline(ss, line2, ','); //skip first word "cities" (top left corner in table/matrix)
    while(getline(ss, line2, ',')){ //get all cities into a seperate word, and put into the graph as verticies
        myGraph->addVertex(line2);
        cities.push_back(line2);
    }

    while(getline(fr, line)){ //get all lines below the first
        // cout<<line<<endl;
        stringstream ss(line);
        string line2 = "";
        string currCity = "";

        getline(ss, currCity, ',');//get first word *city name* (currCity)
        int index = 0;
        while(getline(ss, line2, ',')){//get numbers associated with currCity
            if(stoi(line2) > 0){
                myGraph->addEdge(currCity, cities[index], index);
            }
            index++;
        }
    }

    string input = "";
    while(input != "3"){
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Vertex adjacent" << endl;
        cout << "3. Quit" << endl;
        cin >> input;
        if(input == "1"){
            myGraph->displayEdges();
        }
        else if(input == "2"){
            string c1 = "";
            string c2 = "";
            cout<<"Enter first city:"<<endl;
            cin >> c1;
            cout<<"Enter second city:"<<endl;
            cin >> c2;
            if((myGraph->isAdjacent(c1, c2)) == true){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
    }
    
    cout<<"Goodbye!"<<endl;
    return 0;
}