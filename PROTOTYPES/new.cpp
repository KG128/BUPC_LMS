#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <windows.h>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"
using namespace std;

void Clear_screen();
void Clear_screen() {system("cls");}
void Add_Student();

int User_Input_choice;
class Input_student_with_book_data 
{
    public:
        int    Month;
        int    Day;
        int    Month_Deadline;
        int    Day_Deadline;
        string Student_firstname;
        string Student_lastname;
        string Student_ID;
        string Student_Course;
        string Student_YearLevel;
        string Borrowed_BookCategory;
        string Borrowed_BookName;
        string Borrowed_BookAuthor;
        string Borrowed_BookDate;
        string Line_from_data;
        string Temp_Book_Pointer;
        string Month_in_LetterForm(int Numerical_form_of_month) 
        {
            string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
            return Months[Numerical_form_of_month-1];
        }
        void Get_Student_Name();
        void Insert_Data_to_Database();
        void Get_Student_Yearlevel();   
        void Get_Student_Course();
        void Get_BookCategory();
        void Get_Date_and_Deadline_of_Borrow();
        void Get_Book();
        void Check_if_Information_is_right();
        void get_book_data_from_list();
};

int main() 
{
    Add_Student();
}


void Add_Student() 
{   
    Input_student_with_book_data BorrowedBook_data;
    Clear_screen();
    BorrowedBook_data.Get_Student_Name();
    Clear_screen();
    BorrowedBook_data.Get_Student_Yearlevel();
    Clear_screen();
    BorrowedBook_data.Get_Student_Course();   
    Clear_screen();
    BorrowedBook_data.Get_Book();   
}
void Input_student_with_book_data::Get_Student_Name() 
{
    cout << "Student Full Name: ";
    cin >> Student_firstname >> Student_lastname;
    cout << "Student ID: ";
    cin >> Student_ID; cout << endl;
}

void Input_student_with_book_data::Get_Student_Yearlevel() 
{
    cout << "----PICK YEAR LEVEL-----\n";
    cout << "[1] 1st year" << endl;
    cout << "[2] 2nd year" << endl;
    cout << "[3] 3rd year" << endl;
    cout << "[4] 4th year" << endl;
    cout << "Year Level: ";
    cin >> User_Input_choice;

    switch (User_Input_choice)
    {
    case 1:
        Student_YearLevel = "1st_Year";
        break;
    case 2:
        Student_YearLevel = "2nd_Year";
        break;
    case 3:
        Student_YearLevel = "3rd_Year";
        break;
    case 4:
        Student_YearLevel = "4th_Year";
        break;
    default:
        cout << "NO OPTION, TRY AGAIN\n";
        Input_student_with_book_data::Get_Student_Yearlevel();
        break;
    }
}

void Input_student_with_book_data::Get_Student_Course() 
{

    cout << "\n";
    cout << "----PICK COURSE-----\n";
    cout << "[1] BSECE" << endl;
    cout << "[2] BSCpE" << endl;
    cout << "Student Program: ";
    cin >> User_Input_choice;

    switch (User_Input_choice)
    {
        case 1:
            Student_Course = "BSECE";
            break;
        case 2:
            Student_Course = "BSCpE";
            break;
        default:
            cout << "NO OPTION, TRY AGAIN\n";
            Input_student_with_book_data::Get_Student_Course();
            break;
    }
}

void Input_student_with_book_data::Get_BookCategory() 
{
    cout << "----PICK BOOK CATEGORY-----\n";
    cout << "[1] MATHEMATICS"  << endl;
    cout << "[2] SCIENCE"      << endl;
    cout << "[3] ENGINEERING"  << endl;
    cout << "Enter Book Category: ";
    cin >> User_Input_choice;

    switch (User_Input_choice)
    {
        case 1:
            Borrowed_BookCategory = "MATHEMATICS";
            break;
        case 2:
            Borrowed_BookCategory = "SCIENCE";
            break;
        case 3:
            Borrowed_BookCategory = "ENGINEERING";
            break;
        default:
            cout << "NO OPTION, TRY AGAIN\n";
            Input_student_with_book_data::Get_BookCategory();
            break;
    }
}
void Input_student_with_book_data::Get_Book() 
{
    Clear_screen();
    ifstream Book_List("booklist.data");
    cout << "ENTER BOOK NUMBER: ";
    cin >> Temp_Book_Pointer;
    Book_List.open("booklist.data");
    if (!Book_List.is_open()) 
    {
        cout << "Book List Database Not Found";
        cout << endl; system("pause");
    } else if (Book_List.is_open()) {

        cout << "Book List Found";
        cout << endl; system("pause");
        get_book_data_from_list();
        
    }
}

void Input_student_with_book_data::get_book_data_from_list() {

    ifstream Book_List("booklist.data");
    while(getline(Book_List, Line_from_data)) 
        {
            string  Book_Number_Code, 
                    Book_Name_from_Database,
                    Book_Author_from_Database,
                    Book_Date_from_Database;
            istringstream Book_Number_on_line(Line_from_data);
            Book_Number_on_line >> Book_Number_Code >> Book_Name_from_Database >> Book_Author_from_Database >> Book_Date_from_Database;
            
            if (Temp_Book_Pointer == Book_Number_Code)
            {
                Borrowed_BookName = Book_Name_from_Database;
                Borrowed_BookAuthor = Book_Author_from_Database;
                Borrowed_BookDate = Book_Date_from_Database; 
                Input_student_with_book_data::Get_Date_and_Deadline_of_Borrow();   
            } 
            else if
            {
                Clear_screen();
                print("NO BOOK FOR CODE " + Temp_Book_Pointer + " IS FOUND..", color_white, color_red);
                FAILSOUND();
                cout << endl; system("PAUSE");
                Input_student_with_book_data::Get_Book();
            }
        }
}

void Input_student_with_book_data::Check_if_Information_is_right() 
{
    Clear_screen();
    cout << "------------STUDENT DETAILS------------" << endl << endl;
    cout << "Student Name: " << Student_firstname << " " << Student_lastname << endl;
    cout << "Student ID: " << Student_ID << endl;
    cout << "Student Year: " << Student_YearLevel << endl;
    cout << "Student Course: " << Student_Course << endl;
    cout << "\n\n------------BOOK DETAILS------------" << endl << endl;
    cout << "Book Name: " << Borrowed_BookName << endl;
    cout << "Book Author: " << Borrowed_BookAuthor << endl;
    cout << "Book Date: " << Borrowed_BookDate << endl;
    cout << "Date of Borrow: " <<  Month_in_LetterForm(Month) << ". " << Day << endl;
    cout << "Deadline: " << Month_in_LetterForm(Month_Deadline) << ". " << Day_Deadline   << endl;


    string User_Input_choice_string;
    cout << "\n\nAre the Details right? (Y/n): "; 
    cin >> User_Input_choice_string;
    
    if (User_Input_choice_string == "Y") 
    {
        Input_student_with_book_data::Insert_Data_to_Database();
    } 
    else 
    {
        
    }
}
void Input_student_with_book_data::Get_Date_and_Deadline_of_Borrow() 
{
    Clear_screen();
    cout << "Enter The Date and Deadline of Borrow" << endl;
    cout << "--------------------DAY TODAY--------------------" << endl;
    cout << "Enter the Month: "; 
    cin >> Month;
    cout << "Enter Day: "; 
    cin >> Day;
    cout << "--------------------DEADLINE--------------------" << endl;
    cout << "Enter the Month: "; 
    cin >> Month_Deadline;
    cout << "Enter Day: "; 
    cin >> Day_Deadline;
    Input_student_with_book_data::Check_if_Information_is_right();
}
void Input_student_with_book_data::Insert_Data_to_Database() 
{   
    ofstream borrowedbook_database("borrowedbooks.data", ios::app);
    ifstream myfile("borrowedbooks.data");
    string firstline;
    getline(myfile,firstline);
    borrowedbook_database << Student_firstname << " " << Student_lastname     
    << " " << Student_ID << " " << Student_YearLevel 
    << " " << Borrowed_BookCategory <<  " " 
    << Borrowed_BookName << " " << Borrowed_BookAuthor << " " << Month_in_LetterForm(Month) << "_" << Day << " " <<  Month_in_LetterForm(Month_Deadline) << "_" << Day_Deadline << endl;
    cout << "\n--------STUDENT ADDED TO DATABASE----------\n";
    borrowedbook_database.close();
    system("pause");
}