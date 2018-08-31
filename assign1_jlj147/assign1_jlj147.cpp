// File Name: assign1_jlj147.cpp
//
// Author: Jayce Jones
// Date: 2/2/2016
// Assignment Number: 1
// CS 2308.251 Spring 2016
// Instructor: Jill Seaman
//
// Computes the total points, percent grade, and letter grade of up to 50
// students and outputs the data to a file

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function Prototypes
double calculateTotal(int[], int, int[], int);
double calculatePercent(float);
char findGrade (int);

int main()
{
    const int EXAM_GRADES = 5;      //Array size for exam grades
    const int ASSIGN_GRADES = 4;   //Array size for assignment grades
    int examScore[EXAM_GRADES];    //Array that holds five exam scores
    int assignScore[ASSIGN_GRADES];//Array that holds four assignments scores
    string studentID;              //Student ID number beginning with A
    int participationScore;        //Numeric value of participation score
    double totalScore;             //Numeric value for total points earned
    double percentGrade;           //Numeric value for grade as a percent
    int dropScore;                 //Numeric value of lowest exam grade
    char letterGrade;              //Letter grade A-F based on total score
    int count = 0;                 //Count variable initialized to zero
    
    //Open output file and format
    ofstream fout;
    fout.open("final_grades.txt");
    
    fout << "StudentID  Points  Percent  Grade" << endl;
    fout << "----------------------------------" << endl;
    fout << endl;
    
    //Test for file open error
    ifstream fin;
    fin.open ("class_scores.txt");
    if (!fin)
    {
        cout << "Error - File not found" << endl;
        return (0);
    }
    //Begin reading in data
    while (fin >> studentID && count < 49)
    {
        
        
        for (int i=0; i < 5; i++)
        {
            fin >> examScore[i];
        }
        
        dropScore = 100; //Resets score in order to find lowest grade in index
        
        for (int i=0; i < 5; i++)
        {
            if(examScore[i] < dropScore)
            {
                dropScore = examScore[i];
            }
        }
        
        fin >> participationScore;
        if (participationScore > 60)
            participationScore = 60;
        
        for (int i=0; i < 4; i++)
        {
            fin >> assignScore[i];
        }
        
        //Call to function
        totalScore = calculateTotal (examScore,participationScore,
                                     assignScore,dropScore);
        
        //Call to function
        percentGrade = calculatePercent(totalScore);
        
        //Call to function
        letterGrade = findGrade(totalScore);
        
        //Send and format data to output file
        fout << left << setw(12) << studentID << setw(8) << fixed
        << setprecision(0) << totalScore << setw(10) << fixed
        << setprecision(1) << percentGrade << setw(7)
        << letterGrade << endl;
        
        count++;
    }
    
    fin.close();
    fout.close();
    
    cout << "Grades written to file 'final_grades.txt'" << endl;
    
    return 0;
}

//***********************************************************
// calculateTotal: Calculates the students total points
//
// e: Array containing students 5 exam scores
// p: Holds the student participation score
// a: Array containing students 4 assignment score
// drop: Holds the students lowest exam score that is to be dropped
// returns: Total points earned by the student
//***********************************************************

double calculateTotal (int e[], int p, int a[], int drop)
{
    double total = 0;
    
    for (int i=0; i < 5 ; i++){
        total+=e[i];
    }
    
    total = total-drop;
    
    total += p;
    
    for (int i=0; i < 4; i++){
        total+=a[i];
    }
    
    return total;
}

//***********************************************************
// calculatePercent: Calculates the students percent grade
//
// t: Contains the students total points earned
// returns: The students grade in the form of a percent
//***********************************************************

double calculatePercent(float t)
{
    float percent = 0.0; //Percent grade to be sent back to main
    
    percent = t/500;
    percent = percent*100;
    
    return percent;
}

//***********************************************************
// calculatePercent: Gives the student a letter grade based on total
//                   points earned
//
// tp: Contains the students total points earned
// returns: The letter grade the student earned
//***********************************************************

char findGrade (int tp)
{
    char letterGrade = 'A'; //Initilaizig letter grade
    
    if (tp<= 500 && tp >= 448)
        letterGrade ='A';
    else if (tp<= 447 && tp>= 398)
        letterGrade = 'B';
    else if (tp<= 397 && tp>= 348)
        letterGrade = 'C';
    else if (tp<= 347 && tp>= 298)
        letterGrade = 'D';
    else if (tp<= 297 && tp>= 0)
        letterGrade = 'F';
    
    return letterGrade;
}





