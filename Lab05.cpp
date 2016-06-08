//**************************************************************************************************
// FILE:        Lab05.cpp
//
// DESCRIPTION: Reads season statistics for basketball players from an input file, computes per-game
//              statistics, and writes the per-game statistics to an output file.
//
// AUTHORS:     Zoe Aiyanna M. Cayetano          (zcayetan@asu.edu)
//
// COURSE:      CSE100 Principles of Programming with C++, Spring 2016
//**************************************************************************************************
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void ReadHeader(ifstream&);
void PrintHeader(ofstream& pFout);
void PrintStats(ifstream& pFin, ofstream& pFout);

int main()
{
    ifstream fin("stats-season.txt");
    
    if (!fin) {
        cout << "Could not open 'stats-season.txt' for reading. Terminating program." << endl;
        exit(-1);
    }
    
    ofstream fout("stats-game.txt");
    fout << fixed;
    
    ReadHeader(fin);
    PrintHeader(fout);
    PrintStats(fin, fout);
    
    fin.close();
    fout.close();
    
    return 0;
}

void PrintHeader(ofstream& pFout)
{
    pFout << left << setw(16) << "Name";
    pFout << right << setw(4) << "GP";
    pFout << setw(6) << "PPG";
    pFout << setw(6) << "RPG";
    pFout << setw(7) << "FG%";
    pFout << setw(7) << "FT%";
    pFout << setw(7) << "3P%";
    pFout << endl;
}

void PrintStats(ifstream& pFin, ofstream& pFout)
{
    for (int i = 1; i <= 11; ++i) {
        
        string name;
        pFin >> name;
        
        int gp,
            fgm,
            fga,
            ftm,
            fta,
            threem,
            threea,
            pts,
            reb;
        
        pFin >> gp >> fgm >> fga >> ftm >> fta >> threem >> threea >> pts >> reb;
        double fgp;
        fgp = (static_cast<double>(fgm))/fga;
        double ftp;
        ftp = (static_cast<double>(ftm))/fta;
        double threep;
        threep = (static_cast<double>(threem))/threea;
        double ppg;
        ppg = (static_cast<double>(pts))/gp;
        double rpg;
        rpg = (static_cast<double>(reb))/gp;
        
        pFout << left << setw(16) << name;
        pFout << right << setprecision(1) << setw(4) << gp;
        pFout << setw(6) << ppg;
        pFout << setw(6) << rpg;
        pFout << setprecision(3) << setw(7) << fgp;
        pFout << setw(7) << ftp;
        pFout << setw(7) << threep;
        pFout << endl;
    }
}

void ReadHeader(ifstream& pFin)
{
    string header;
    getline(pFin, header);
}