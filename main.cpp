

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void assCalc();
void letterGrade();
void sign();
int main()
{
    int studentId, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, minAss, assTotal, midterm, Final, labexercises, totalPoints, pct;
    int studentcount = 0;
    float grand_totalPoints = 0, grand_totalPct = 0;
    char grade, plusminus;
    int numA = 0, numB = 0, numC = 0, numD = 0, numF = 0;
    const string DataFile = "student_data.txt";
    const string ReportFile = "report.txt";
    const string SummaryFile = "summary.sum";
    const int MaxPoints = 400;
    float avg_totalPoints, avg_pctTotal;

    ifstream fin(DataFile.c_str());
    if (!fin)
    {
        cerr << "Unable to open input file: " << DataFile << endl;
        exit(-2);
    }

    ofstream fout(ReportFile.c_str());
    if (!fout)
    {
        cerr << "Unable to open output file: " << ReportFile << endl;
        exit(-3);
    }

    // Write report file heading
    fout << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
    fout << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;

    while (1)
    {
        fin >> studentId;
        if (fin.eof())
            break;
        fin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10 >> a11
            >> midterm >> Final >> labexercises;

        // Determine the minimum assignment grade
        minAss = a1;
        if (a2 < minAss)
            minAss = a2;
        if (a3 < minAss)
            minAss = a3;
        if (a4 < minAss)
            minAss = a4;
        if (a5 < minAss)
            minAss = a5;
        if (a6 < minAss)
            minAss = a6;
        if (a7 < minAss)
            minAss = a7;
        if (a8 < minAss)
            minAss = a8;
        if (a9 < minAss)
            minAss = a9;
        if (a10 < minAss)
            minAss = a10;

        // Assignment total
        assTotal = a1 + a2 + a3+ a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 - minAss;

        // Total Points
        totalPoints = assTotal + midterm + Final + labexercises;

        // Calculate percent
        pct = static_cast<int>(100.*totalPoints/MaxPoints+.5);

        // Determine letter grade
        switch (pct/10)
        {
        case 10:       // "fall through"
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
        }

        // Determine plus or minus
        if (pct > 97)
            plusminus = '+';
        else if (pct >= 60 && pct % 10 < 2)
            plusminus = '-';
        else if (pct > 67 && pct%10 > 7)
            plusminus = '+';
        else
            plusminus = ' ';

        // Write report
    fout << setw(8) << setfill('0') << studentId;
    fout << setfill(' ');
    fout << setw(4) << a1
         << setw(3) << a2
         << setw(3) << a3
         << setw(3) << a4
         << setw(3) << a5
         << setw(3) << a6
         << setw(3) << a7
         << setw(3) << a8
         << setw(3) << a9
         << setw(3) << a10
         << setw(3) << a11
         << setw(5) << assTotal
         << setw(5) << midterm
         << setw(5) << Final
         << setw(4) << labexercises
         << setw(6) << totalPoints
         << setw(5) << pct
         << setw(2) << grade << plusminus <<endl;

        numA += (grade == 'A' ? 1 : 0);
        numB += (grade == 'B' ? 1 : 0);
        numC += (grade == 'C' ? 1 : 0);
        numD += (grade == 'D' ? 1 : 0);
        numF += (grade == 'F' ? 1 : 0);

        studentcount++;
        grand_totalPoints += totalPoints;
        avg_totalPoints = grand_totalPoints/studentcount;
        
        grand_totalPct += pct;
        avg_pctTotal = grand_totalPct/studentcount;
        
        

    }
    cout << "The number of A's = " << numA << endl;
    cout << "The number of B's = " << numB << endl;
    cout << "The number of C's = " << numC << endl;
    cout << "The number of D's = " << numD << endl;
    cout << "The number of F's = " << numF << endl;
    
    
    //Summary Info Check
    cout << "Number of students = " << studentcount << endl;
    cout << "The average total points = " << setprecision(1) << fixed << avg_totalPoints << endl;
    cout << "The average percent total = " << setprecision(1) << fixed << avg_pctTotal << "%" << endl;
    

}
