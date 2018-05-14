#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<ctime>
using namespace std;

int change_do_you_know;
int change_my_messages=1;
int change_upcoming_events=1;
int change_announcements=1;
string getIntInput()
{
    char s[10];
    char c;
    int i = 0;
    while(true)
    {
        c = getch();
        if(c == '\b' && i>0){cout<<"\b \b";s[i-1]='\0';--i;}
        else if(c == '\r' || c == '\n')break;
        else if(i==8) continue;
        else if(c>='0'&&c<='9'){cout<<c;s[i]=c;++i;}
    }
    s[i] = '\0';
    string l = s;
    return l;
}

class homepage_class
{
    string reg_no_ori,password_ori,name_ori,section_ori,roll_no_ori;
    double attendance_ori,cgpa_ori;
    string reg_no,password;
public:
    void init()
    {
        reg_no_ori="11605215";
        password_ori="surya";
        name_ori="surya prakash";
        section_ori="K1601";
        roll_no_ori="50";
        attendance_ori=97;
        cgpa_ori=9.75;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////     1   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
    void first_default_page()
    {
        system("cls");
        cout<<"\n\n\n\t\t\t\t\t ------------------------------------";
        cout<<"\n\t\t\t\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";
        cout<<"\n\t\t\t\t\t ------------------------------------";
        cout<<"\n\n\tLovely  Professional  University  is  a  semi  residential  university  college  in  North-India  created \n\tunder"
            <<"  the  Punjab  State  Private  University  act.  and  recognized  by  UGC .LPU  offers  around  200  \n\tprogrammes  and  "
            <<"  courses  at  diploma,  undergraduate,  graduate,  postgraduate,  and  doctoral  levels. \n\tThe  university  has  "
            <<"more  than  30,000  students  graduating  every  year";
        cout<<"\n\n\n\t\t\t\t\tMotto:            Transforming Education Transforming India."
            <<"\n\t\t\t\t\tType:             Private"
            <<"\n\t\t\t\t\tEstablished:      2005"
            <<"\n\t\t\t\t\tChancellor:       Ashok Mittal"
            <<"\n\t\t\t\t\tVice-Chancellor:  Dr.Ramesh Kanwar"
            <<"\n\t\t\t\t\tAcademic staff:   3,500"
            <<"\n\t\t\t\t\tStudents:         45,000"
            <<"\n\t\t\t\t\tCampus:           Semi-Urban 600 Acres.";
            cout<<"\n\n\t\t\t\t\tPress anything to continue:";
            getch();
            login_page();
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////    2    //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void login_page()
    {
        system("cls");
        cout<<"\n\n\t\t\t\t\t ------------------------------------"
            <<"\n\t\t\t\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |"
            <<"\n\t\t\t\t\t ------------------------------------";
        cout<<"\n\n\t\t\t\t\t  _________________________________"
            <<"\n\t\t\t\t\t |                                 |"
            <<"\n\t\t\t\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |"
            <<"\n\t\t\t\t\t |_________________________________|";
        cout<<"\n\n\n\t\t\t\t\t Registration Number:";
        reg_no=getIntInput();
        if(reg_no.length()<8)
        {
            cout<<"\n\n\n\t\t\t\t\tToo few characters ";
            cout<<"\n\n\n\n\n\t\t\t\t\tTry again";
            Sleep(1000);
            login_page();
        }
        int ret_check_reg_no=check_reg_no(reg_no);
        if(ret_check_reg_no==1)
        {
            int basic_int=0;
            do
            {
                basic_int++;
                if(basic_int==1)
                {
                    cout<<"\n\n\t\t\t\t\t Password:";
                    cin>>password;
                }
                else
                {
                    cout<<"\n\n\t\t\t\t\t--Wrong Password--";
                    cout<<"\n\n\t\t\t\t\t Please enter correct password:";
                    cin>>password;
                }

                if(password==password_ori)
                  ;//some function


            }while(password!=password_ori);
        }
        else
        {
            system("cls");
            bool ret_password;
            int basic_int=0;
            string password_dup;
            cout<<"\n\n\t\t\t\t\t  _________________________________"
            <<"\n\t\t\t\t\t |                                 |"
            <<"\n\t\t\t\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |"
            <<"\n\t\t\t\t\t |_________________________________|";
            cout<<"\n\n\t\t\t\t\tYou are logging into UMS for the first time\n\t\t\t\t\t     Please fill the form.";
            reg_no_ori=reg_no;
            cout<<"\n\n\t\t\t\t\tEnter your Name:";
            cin.sync();
            getline(cin,name_ori);
            cout<<"\n\t\t\t\t\tEnter your Section:";
            cin>>section_ori;
            cout<<"\n\t\t\t\t\tEnter your Roll Number:";
            cin>>roll_no_ori;
            cout<<"\n\t\t\t\t\tEnter your CGPA:";
            cin>>cgpa_ori;
            cout<<"\n\t\t\t\t\tEnter your Attendance in Last Semester:";
            cin>>attendance_ori;
            do
            {
                basic_int++;
                if(basic_int==1)
                {
                   cout<<"\n\t\t\t\t\tEnter a new password:";
                   cin>>password_dup;
                   cout<<"\n\t\t\t\t\tConfirm Password:";
                   cin>>password_ori;
                   if(password_dup==password_ori)
                   {
                      ret_password=1;
                   }
                   else
                   {
                      ret_password=0;
                   }
                }
                else
                {
                    cout<<"\n\t\t\t\t\tPasswords did not match...\n\t\t\t\t\tPlease enter correctly.";
                    cout<<"\n\n\t\t\t\t\tEnter a new password:";
                    cin>>password_dup;
                    cout<<"\n\t\t\t\t\tConfirm Password:";
                    cin>>password_ori;
                    if(password_dup==password_ori)
                    {
                       ret_password=1;
                    }
                    else
                    {
                       ret_password=0;
                    }

                }

            }while(!ret_password);

            ofstream file;
            file.open("surya.txt",ios::app);
            file<<reg_no_ori<<endl<<name_ori<<endl<<section_ori<<endl<<roll_no_ori<<endl<<cgpa_ori
                <<endl<<attendance_ori<<endl<<password_ori<<endl;
            file.close();



        }
        lp_homepage();
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////    3    ///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int check_reg_no(string reg_no_dup)
    {
        int file_int;
        ifstream file;
        file.open("surya.txt",ios::in);
        while(file.eof()==0)
        {
            file>>reg_no_ori>>name_ori>>section_ori>>roll_no_ori>>cgpa_ori>>attendance_ori>>password_ori;
            if(reg_no_dup==reg_no_ori)
                return 1;
            else
                file_int=0;
        }
        file.close();
        return file_int;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////      4    //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lp_homepage()
{
    int basic_int=0;
    int lp_choice;
    bool ret_choice;
    system("cls");
    change_do_you_know++;
    cout<<"\n\n\t\t\t\t ------------------------------------";cout<<"\t\t          ----------------------------";
    cout<<"\n\t\t\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";    cout<<"\t\t          |  1.Home Page    2.Logout |";
    cout<<"\n\t\t\t\t ------------------------------------";    cout<<"\t\t          ----------------------------";



    cout<<"\n\n\n\tWelcome "<<name_ori;
    cout<<"\t\t\t\t\t\t\t\t  DO YOU KNOW:";
    time_t now=time(0);
    char* lt=ctime(&now);
    cout<<"\n\t"<<lt;
        switch(change_do_you_know)
        {
            case 3:
                cout<<"\t\t\t\t\t\t\t\tUniversity Management System gets more than\t\t\t\t\t\t\t\t\t\t        65000 hits in a day.";
            break;
            case 2:
                cout<<"\t\t\t\t\t\t\t\tLovely Professional University is using 35+ servers and\n\t\t\t\t\t\t\t\t 136 TB of storage "
                     <<"for CCTV, Database, FTP, Backup etc.";
            break;
            case 1:
                cout<<"\t\t\t\t\t\t\t\tLovely Professional University is a member of Microsoft \t\t\t\t\t\t\t\tDeveloper "
                    <<" Network (MSDN) Academic Alliance.";
            break;
            case 4:
                cout<<"\t\t\t\t\t\t\t\tFaculty members can upload the marks of the assignments \t\t\t\t\t\t\t\tthrough "
                    <<"online and offline mode in UMS.";
            break;
            case 5:
                cout<<"\t\t\t\t\t\t\t\tUniversity Management System is accessed by more "
                    <<"than \t\t\t\t\t\t\t\t\t24000 (distinct users) in a day.";
            break;
        }
         cout<<"\n\n\t------------------------------";  cout<<"\t\t\t\t------------------------------------------------------";
         cout<<"\n\t|      Zeroth                |";  cout<<"\t\t\t\t|          LPU NEWS                                  |";
         cout<<"\n\t------------------------------";   cout<<"\t\t\t\t------------------------------------------------------";
         cout<<"\n\t| \"Regular attendance is the |" ;  cout<<"\t\t\t\t|06 APR 2017                                         |";
         cout<<" \n\t|hallmark of a good student\" |";  cout<<"\t\t\t\t|    Tata Group Company LPU associated for           |";
         cout<<"\n\t------------------------------";    cout<<"\t\t\t\t|    Corporate Social Responsibility                 |";
         cout<<"\n";                                    cout<<"\t\t\t\t\t\t\t\t------------------------------------------------------";
         cout<<"\n\t-----------------------------";    cout<<"\t\t\t\t|31 MAR 2017                                         |";
         cout<<"\n\t|   Student Result Analysis |";    cout<<"\t\t\t\t|    Automotive Engineering’s top International      |";
         cout<<"\n\t-----------------------------";   cout<<"\t\t\t\t|    Go-Kart Championship 2017’ concluded            |";
         cout<<"\n\t|       CGPA:"<<cgpa_ori<<"           |";cout<<"\t\t\t\t|    at LPU Campus                                   |";
        cout<<"\n\t|---------------------------|";       cout<<"\t\t\t\t------------------------------------------------------";
        cout<<"\n\t|       Attendance:"<<attendance_ori<<"%      |";cout<<"\t\t\t\t|*based upon last updation in database   \t     |";
         cout<<"\n\t-----------------------------";      cout<<"\t\t\t\t------------------------------------------------------";
         do
         {
             basic_int++;
             if(basic_int==1)
             {
                 cout<<"\n\n\t\t\t\tEnter your choice:";
                 cin>>lp_choice;
                 if(lp_choice==1)
                  {
                      ret_choice=1;
                      homepage();
                  }
                 else if(lp_choice==2)
                 {
                     ret_choice=1;
                     first_default_page();
                 }
                 else
                    ret_choice=0;
             }
             else
             {
                 cout<<"\n\t\t\t\tWrong Choice..!"
                     <<"   Please Enter correctly"
                     <<"\n\t\t\t\tEnter your choice:";
                 cin>>lp_choice;
                 if(lp_choice==1)
                  {
                      ret_choice=1;
                      homepage();
                  }
                 else if(lp_choice==2)
                 {
                     ret_choice=1;
                     first_default_page();
                 }
                 else
                    ret_choice=0;
             }


         }while(!ret_choice);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////          5         //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void homepage()
{
    int choice_homepage;
    system("cls");
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";

    cout<<"\n\n    Welcome:"<<name_ori;
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";
    cout<<"\n   |      Reg.No:"<<reg_no_ori<<"\t      |";            cout<<"\t\t\t\t|           1.My Messages                |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";
    cout<<"\n   |      Section:"<<section_ori<<"  \t      |";          cout<<"\t\t\t\t|           2.Upcoming Events            |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |      Group No:2                  |";
    else
        cout<<"\n   |      Group No:1                  |";        cout<<"\t\t\t\t|           3.Announcements              |";
    cout<<"\n   ------------------------------------";            cout<<"\t\t\t\t------------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |         Roll No.:B"<<roll_no_ori<<"  \t      |";
    else
        cout<<"\n   |         Roll No.:A"<<roll_no_ori<<"  \t      |";    cout<<"\t\t\t\t|    4.Security Information Brochure     |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";

    cout<<"\n\n\t\t\t\t\tEnter your choice:";
    cin>>choice_homepage;
    switch(choice_homepage)
    {
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 1:
        my_messages();
        break;
    case 2:
        upcoming_events();
        break;
    case 3:
        announcements();
        break;
    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        homepage();
        break;

    }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////      6        //////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void my_messages()
{
    int choice_my_messages;
    system("cls");
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";

    cout<<"\n\n\tMy Messages:";
    switch(change_my_messages)
    {
    case 2:

        cout<<"\n\n\t---------------------------------------------------------------------------------";
        cout<<"\n\t| MICROSOFT DREAMSPARK LOGIN AND PASSWORD                                        |";
        cout<<"\n\t----------------------------------------------------------------------------------";
        cout<<"\n\t| By: Janpreet Singh (Mar 28, 2017)                                              |";
        cout<<"\n\t|                                                                                |";
        cout<<"\n\t| Dear Student, You login id and password for Microsoft Dreamspark account       |"
           <<"\n\t| is LoginID: same as your microsoft username Password:123456                    |";
        cout<<"\n\t----------------------------------------------------------------------------------";
    break;
    case 3:
        cout<<"\n\n\t-------------------------------------------------------------------------------------";
        cout<<"\n\t|   CA-4                                                                            |";
        cout<<"\n\t-------------------------------------------------------------------------------------";
        cout<<"\n\t|  By: Gitika Jalota (Apr 07, 2017)                                                 |";
        cout<<"\n\t|                                                                                   |";
        cout<<"\n\t|   CA 4 i.e Power point presentation is scheduled between 17th April               |"
            <<"\n\t|   to 22nd April in the respective tutorial classes.                               |";
        cout<<"\n\t-------------------------------------------------------------------------------------";
        break;
    case 1:
        cout<<"\n\n\t--------------------------------------------------------------------------------------------";
        cout<<"\n\t|   FEEDBACK ON CURRICULUM AND FACULTY FEEDBACK                                            |";
        cout<<"\n\t--------------------------------------------------------------------------------------------";
        cout<<"\n\t|   By: Monika Kalani (Mar 27, 2017)                                                       |"
            <<"\n\t|                                                                                          |"
            <<"\n\t|   Dear Student, We are pleased to inform you that the interface for giving the           |"
            <<"\n\t|   feedback on curriculum is open now. It is open for a limited period only till          |"
            <<"\n\t|   April 10, 2017. Please visit the link: UMS Navigation--Feedback and Surveys--Feedback  |"
            <<"\n\t|   for Program Scheme and Course to record your valuable feedback on curriculum.          |"
            <<"\n\t--------------------------------------------------------------------------------------------";
            break;
    }
    cout<<"\n\n\t\t\t\t1.Previous\t\t2.Next";
    cout<<"\n\n\t\t\t\t\t\t";
    cin>>choice_my_messages;
    switch(choice_my_messages)
    {
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 1:
        if(change_my_messages==1)
          {
              change_my_messages=3;
              my_messages();
          }
        else
          {
              change_my_messages--;
              my_messages();
          }
          break;
    case 2:
        if(change_my_messages==3)
        {
            change_my_messages=1;
            my_messages();
        }
        else
        {
            change_my_messages++;
            my_messages();
        }

    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        my_messages();
        break;

    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////    7     //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void upcoming_events()
{
    system("cls");
    int choice_upcoming_events;
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\tOn-going Events:";
    switch(change_upcoming_events)
    {
    case 2:
        cout<<"\n\n\t--------------------------------------------------------------------------------";
        cout<<"\n\t|     Saturday,April-22-2017                                                   |";
        cout<<"\n\t--------------------------------------------------------------------------------";
        cout<<"\n\t|  DESIGNER AND MODELLING SHOW                                                 |";
        cout<<"\n\t|                                                                              |";
        cout<<"\n\t|   Venue: Campus-Cafe stage,LPU                                               |";
        cout<<"\n\t|   Time:6:00 PM Onwards                                                       |";
        cout<<"\n\t--------------------------------------------------------------------------------";
        break;
    case 3:
        cout<<"\n\n\t----------------------------------------------------------------------------------";
        cout<<"\n\t|    Tuesday,April-11-2017                                                       |";
        cout<<"\n\t----------------------------------------------------------------------------------";
        cout<<"\n\t|   SEMI-FINALE OF CONCOCTION                                                    |";
        cout<<"\n\t|                                                                                |";
        cout<<"\n\t|   Venue:DSA Stage,Block-13                                                     |";
        cout<<"\n\t|   Time:5:30 PM Onwards                                                         |";
        cout<<"\n\t----------------------------------------------------------------------------------";
        break;
    case 1:
        cout<<"\n\n\t-------------------------------------------------------------------------------------";
        cout<<"\n\t|    Friday,April-14-2017                                                           |";
        cout<<"\n\t-------------------------------------------------------------------------------------";
        cout<<"\n\t|   FINALE OF CONCOCTION                                                            |";
        cout<<"\n\t|                                                                                   |";
        cout<<"\n\t|    Venue:DSA Stage,Block-13                                                       |";
        cout<<"\n\t|    Time:5:30 PM Onwards                                                           |";
        cout<<"\n\t-------------------------------------------------------------------------------------";
        break;
    }

    cout<<"\n\n\t\t\t\t1.Previous\t\t2.Next";
    cout<<"\n\n\t\t\t\t\t\t";
    cin>>choice_upcoming_events;
    switch(choice_upcoming_events)
    {
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
    case 11:
        ums_navigation();
        break;
    case 1:
        if(change_upcoming_events==1)
          {
              change_upcoming_events=3;
              upcoming_events();
          }
        else
          {
              change_upcoming_events--;
              upcoming_events();
          }
          break;
    case 2:
        if(change_upcoming_events==3)
        {
            change_upcoming_events=1;
            upcoming_events();
        }
        else
        {
            change_upcoming_events++;
            upcoming_events();
        }

    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        upcoming_events();
        break;

    }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////    8        ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void announcements()
 {
     system("cls");
    int choice_announcements;
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\tAnnouncements:";
    cout<<"\n\n\n\t\tNo announcements to display.";
    cout<<"\n\n\n\t\tEnter your choice:";
    cin>>choice_announcements;
    switch(choice_announcements)
    {
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        announcements();
        break;

    }


 }

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////      9           //////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ums_navigation()
{
    system("cls");
    int choice_ums_navigation;
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";

    cout<<"\n\n    Welcome:"<<name_ori;
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t----------------------------------------";
    cout<<"\n   |      Reg.No:"<<reg_no_ori<<"\t      |";        cout<<"\t\t\t\t|    1.Academic course syllabus        |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t----------------------------------------";
    cout<<"\n   |      Section:"<<section_ori<<"  \t      |";    cout<<"\t\t\t\t|    2.CGPA Calculator                 |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t----------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |      Group No:2                  |";
    else
        cout<<"\n   |      Group No:1                  |";
    cout<<"\n   ------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |         Roll No.:B"<<roll_no_ori<<"  \t      |";
    else
        cout<<"\n   |         Roll No.:A"<<roll_no_ori<<"  \t      |";
    cout<<"\n   ------------------------------------";

    cout<<"\n\n\t\t\t\t\tEnter your choice:";
    cin>>choice_ums_navigation;
    switch(choice_ums_navigation)
    {
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 1:
        academic_syllabus();
        break;
    case 2:
        cgpa_calculator();
        break;

    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        ums_navigation();
        break;

    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////       10           //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void academic_syllabus()
{
    system("cls");
    int choice_academic_syllabus;
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\tACADEMIC COURSE SYLLABUS:";
    cout<<"\n\n\t--------------------------------------------";
    cout<<"\n\t|      1.CSE-202                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\t|      2.CSE-326                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\t|      3.PEL-131                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\t|      4.MTH-166                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\t|      5.PHY-109                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\t|      6.ECE-213                           |";
    cout<<"\n\t--------------------------------------------";
    cout<<"\n\n\t\tEnter your choice:";
    cin>>choice_academic_syllabus;
    switch(choice_academic_syllabus)
    {
    case 33:
        ums_password();
    case 1:
        subject_syllabus(1);
        break;
    case 2:
        subject_syllabus(2);
        break;
    case 3:
        subject_syllabus(3);
        break;
    case 4:
        subject_syllabus(4);
        break;
    case 5:
        subject_syllabus(5);
        break;


    case 11:
        ums_navigation();
        break;
    case 22:
        important_links();
        break;
    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        academic_syllabus();
        break;


    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////       11              //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void subject_syllabus(int subject)
{
    int choice_subject_syllabus;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\t-------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\t|   1.Back              |";
    cout<<"\n\t\t\t\t\t\t\t\t\t-------------------------";
    cout<<"\n\n";
    switch(subject)
    {
    case 1:
        cout<<"\n\t\tCSE-202 OBJECT ORIENTED LANGUAGE";
        cout<<"\n\n\t\tUNIT-1:Concepts and Basics of C++ Programming";
        cout<<"\n\n\t\tUnit-2:Pointers,Reference variables,Arrays and Strings";
        cout<<"\n\n\t\tUnit-3:Constructors and Destructors and File Handling";
        cout<<"\n\n\t\tUnit-4:Inheritance and Polymorphism";
        cout<<"\n\n\t\tUnit-5:Dynamic memory management";
        cout<<"\n\n\t\tUnit-6:Exception Handling and STL";
        break;
    case 2:
        cout<<"\n\t\tCSE-326 INTERNET PROGRAMMING";
        cout<<"\n\n\t\tUNIT-1:Exposure To HTML ";
        cout<<"\n\n\t\tUnit-2:Working with Text,Multimedia";
        cout<<"\n\n\t\tUnit-3:Working With Tables,HTML Forms and Iframes";
        cout<<"\n\n\t\tUnit-4:JavaScript Application Development ";
        cout<<"\n\n\t\tUnit-5:JavaScript Functions,Events and Validation";
        cout<<"\n\n\t\tUnit-6:Cascading Style Sheets";
        break;
    case 3:
        cout<<"\n\t\tPEL 131: Communication Skills II ";
        cout<<"\n\n\t\tUNIT-1:Meeting and greeting people";
        cout<<"\n\n\t\tUnit-2:Tenses and conversation";
        cout<<"\n\n\t\tUnit-3:Engaging in small talk";
        cout<<"\n\n\t\tUnit-4:Presenting your ideas and making a reservation:";
        cout<<"\n\n\t\tUnit-5:Planning-writing an itinerary and presentation:";
        cout<<"\n\n\t\tUnit-6:Making arrangements:";
        break;
    case 4:
        cout<<"\n\t\tMTH166:DIFFERENTIAL EQUATIONS AND VECTOR CALCULUS";
        cout<<"\n\n\t\tUNIT-1:Ordinary differential equations ";
        cout<<"\n\n\t\tUnit-2:Differential equations of higher order ";
        cout<<"\n\n\t\tUnit-3:Linear differential equation ";
        cout<<"\n\n\t\tUnit-4:Partial differential equation ";
        cout<<"\n\n\t\tUnit-5:Vector calculus I";
        cout<<"\n\n\t\tUnit-6:Vector calculus II";
        break;
    case 5:
        cout<<"\n\t\tPHY109:ENGINEERING PHYSICS";
        cout<<"\n\n\t\tUNIT-1:Electromagnetic theory ";
        cout<<"\n\n\t\tUnit-2:Lasers and applications";
        cout<<"\n\n\t\tUnit-3:Fiber optics ";
        cout<<"\n\n\t\tUnit-4:Quantum mechanics-I ";
        cout<<"\n\n\t\tUnit-5:Quantum mechanics-II";
        cout<<"\n\n\t\tUnit-6:Solid state physics ";
        break;
    }
    cout<<"\n\n\t\t\tEnter your choice:";
    cin>>choice_subject_syllabus;
    if(choice_subject_syllabus==1)
        academic_syllabus();
    else
    {
        cout<<"\n\n\t\tWrong Choice....";
        Sleep(1000);
        subject_syllabus(subject);
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////      12           ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void important_links()
{
    int choice_important_links;
    system("cls");
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";

    cout<<"\n\n    Welcome:"<<name_ori;
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";
    cout<<"\n   |      Reg.No:"<<reg_no_ori<<"\t      |";        cout<<"\t\t\t\t|     1.Academic Calendar                |";
    cout<<"\n   ------------------------------------";           cout<<"\t\t\t\t------------------------------------------";
    cout<<"\n   |      Section:"<<section_ori<<"  \t      |";
    cout<<"\n   ------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |      Group No:2                  |";
    else
        cout<<"\n   |      Group No:1                  |";
    cout<<"\n   ------------------------------------";
    if(roll_no_ori>"33")
        cout<<"\n   |         Roll No.:B"<<roll_no_ori<<"  \t      |";
    else
        cout<<"\n   |         Roll No.:A"<<roll_no_ori<<"  \t      |";
    cout<<"\n   ------------------------------------";

    cout<<"\n\n\t\t\t\t\tEnter your choice:";
    cin>>choice_important_links;
    switch(choice_important_links)
    {
    case 1:
        academic_calendar();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 33:
        ums_password();
        break;
    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        homepage();
        break;

    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////       13          ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void academic_calendar()
{
    system("cls");
    int choice_academic_calendar;
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n\t\t       ACADEMIC CALENDAR FOR SESSION 2016-17 \t\t\t\t\t\t 1.Back ";
    cout<<"\n\n\t\t Commencement of Classes                            : W, Jan 11, 2017";
    cout<<"\n\n\t\t Last date for applying for Revaluation for Term-I, :2016-17 M, Jan 23, 2017";
    cout<<"\n\n\t\t Mid Term Test (MTT)                                :Sa-F, Mar 04-10, 2017";
    cout<<"\n\n\t\t Registration for Summer Term (Without Late Fee)    :Tu-Sa, May 02-20, 2017";
    cout<<"\n\n\t\t Close of Session                                   :Sa, May 06, 2017";
    cout<<"\n\n\t\t Preparatory Leave for ETE                          :Su-M, May 07-08, 2017";
    cout<<"\n\n\t\t End Term Examinations (ETE)** including Theory     :Tu-Sa, May 09-27, 2017";
    cout<<"\n\n\t\t #Commencement of Classes of Term-I Session 2017-18  :F, Jul 28, 2017 onwards";
    cout<<"\n\n\t\t\tEnter your choice:";
    cin>>choice_academic_calendar;
    if(choice_academic_calendar==1)
        important_links();
    else
    {
        cout<<"\n\n\t\t\tWrong Choice.....";
        Sleep(1000);
        academic_calendar();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////        14            ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ums_password()
{
    string reg_no_dup;
    int choice_ums_password;
    string password_dup;
    string password_ori_new;
    system("cls");
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\tCHANGE PASSWORD:";
    cout<<"\n\n\t\tEnter current password:";
    cin>>password_dup;
    if(password_dup=="11")
        ums_navigation();
    if(password_dup=="22")
        important_links();
    if(password_dup=="33")
        ums_password();
    if(password_dup=="44")
        lp_homepage();
    if(password_dup=="55")
        homepage();
    if(password_dup=="66")
        first_default_page();

    if(password_dup==password_ori)
    {
        cout<<"\n\n\t\tEnter new password:";
        cin>>password_ori_new;
        if(password_ori_new=="11")
            ums_navigation();
        if(password_ori_new=="22")
            important_links();
        if(password_ori_new=="33")
            ums_password();
        if(password_ori_new=="44")
            lp_homepage();
        if(password_ori_new=="55")
            homepage();
        if(password_ori_new=="66")
            first_default_page();
        cout<<"\n\n\t\tRe-enter the new password:";
        cin>>password_dup;
        if(password_dup=="11")
            ums_navigation();
        if(password_dup=="22")
            important_links();
        if(password_dup=="33")
            ums_password();
        if(password_dup=="44")
            lp_homepage();
        if(password_dup=="55")
            homepage();
        if(password_dup=="66")
            first_default_page();
        if(password_dup==password_ori_new)
        {
            ifstream ori;
            ori.open("surya.txt",ios::in);
            ofstream dup;
            dup.open("duplicate.txt",ios::out);
            while(ori.eof()==0)
            {
               ori>>reg_no_dup>>name_ori>>section_ori>>roll_no_ori>>cgpa_ori>>attendance_ori>>password_ori;
               if(reg_no_ori==reg_no_dup)
               {
                   dup<<reg_no_ori<<endl<<name_ori<<endl<<section_ori<<endl<<roll_no_ori<<endl<<cgpa_ori<<endl<<attendance_ori<<endl<<password_ori_new<<endl;
               }
               else
               {
                   dup<<reg_no_dup<<endl<<name_ori<<endl<<section_ori<<endl<<roll_no_ori<<endl<<cgpa_ori<<endl<<attendance_ori<<endl<<password_ori<<endl;
               }

            }
            ori.close();
            dup.close();
            ifstream dup1;
            dup1.open("duplicate.txt",ios::in);
            ofstream ori1;
            ori1.open("surya.txt",ios::out);
            while(dup1.eof()==0)
            {
                dup1>>reg_no_ori>>name_ori>>section_ori>>roll_no_ori>>cgpa_ori>>attendance_ori>>password_ori;
                ori1<<reg_no_ori<<endl<<name_ori<<endl<<section_ori<<endl<<roll_no_ori<<endl<<cgpa_ori<<endl<<attendance_ori<<endl<<password_ori<<endl;
            }
            ori1.close();
            dup1.close();
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\tYour Password has been changed successfully.";
            Sleep(1000);
            for(int i=3;i>0;i--)
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\tYou will be redirected to login-page within "<<i<<" seconds.";
                Sleep(1000);
            }
            first_default_page();

        }
        else
        {
            cout<<"\n\n\t\tPasswords did not match..Try again.....,";
            Sleep(1000);
            ums_password();
        }

    }
    else
    {
        cout<<"\n\n\t\tWrong Password....";
        Sleep(1000);
        ums_password();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////     15          /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cgpa_calculator()
{
    int choice_cgpa_calculator;
    int grade_points;
    int total=0;
    double cgpa;
    system("cls");
    cout<<"\n\n\t\t  __________________________________";  cout<<"\t\t  _________________________________";
    cout<<"\n\t\t |                                  |";   cout<<"\t\t |                                 |";
    cout<<"\n\t\t |  LOVELY PROFESSIONAL UNIVERSITY  |";   cout<<"\t\t |  UNIVERSITY MANAGEMENT SYSTEM   |";
    cout<<"\n\t\t |__________________________________|";   cout<<"\t\t |_________________________________|";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n|  11.UMS navigation  |  22.Important Links   |  33.Change Password  |            | 44.go to LP | 55.Home | 66.Logout |";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\t1.Back";
    cout<<"\n\n\n\t\tCGPA Calculator";
    cout<<"\n\n\t\tEnter grade points in CSE-202:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+3*grade_points;
    cout<<"\n\t\tEnter grade points in CSE-326:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+1*grade_points;
    cout<<"\n\t\tEnter grade points in ECE-213:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+4*grade_points;
    cout<<"\n\t\tEnter grade points in ECE-216:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+1*grade_points;
    cout<<"\n\t\tEnter grade points in MEC-103:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+4*grade_points;
    cout<<"\n\t\tEnter grade points in MTH-166:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+4*grade_points;
    cout<<"\n\t\tEnter grade points in PEL-131:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+3*grade_points;
    cout<<"\n\t\tEnter grade points in PHY-109:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+4*grade_points;
    cout<<"\n\t\tEnter grade points in PHY-119:";
    cin>>grade_points;
    if(grade_points==1)
        ums_navigation();
    total=total+1*grade_points;
    cgpa=(float)total/25;
    cout<<"\n\n\t\t\t\tYour CGPA is "<<cgpa;
    enter_choice:
    cout<<"\n\n\t\t\tEnter your choice:";
    cin>>choice_cgpa_calculator;
    switch(choice_cgpa_calculator)
    {
    case 1:
        ums_navigation();
        break;
    case 33:
        ums_password();
        break;
    case 22:
        important_links();
        break;
    case 11:
        ums_navigation();
        break;
    case 44:
        lp_homepage();
        break;
    case 55:
        homepage();
        break;
    case 66:
        first_default_page();
        break;
    default:
        cout<<"\n\n\t\t\t\tWrong Choice Enter Correctly..";
        Sleep(1000);
        goto enter_choice;
        break;

    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////       16      /////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};
int main()
{
    homepage_class home;
    //home.init();
    home.first_default_page();
    //home.login_page();
   //home.lp_homepage();
   //home.homepage();
   //home.my_messages();
   //home.upcoming_events();
   //home.announcements();
   //home.ums_navigation();
   //home.academic_syllabus();
   //home.important_links();
}
