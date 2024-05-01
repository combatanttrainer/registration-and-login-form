#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

int main()
{
    m:
    int choice{};
    std::cout << "\t\tWelcome to the login page\n";
    std::cout << "   ______________________________________________________\n";
    std::cout << "                          Menu\n";
    std::cout << "   ______________________________________________________\n\n";
    std::cout << "   | Press 1 to login.\n";
    std::cout << "   | Press 2 to register.\n";
    std::cout << "   | Press 3 if you've forgotten your password.\n";
    std::cout << "   | Press 4 to exit.\n\n";
    std::cout << "        Enter your choice: ";

    std::cin >> choice;

    switch (choice)
    {
        case 1:
            {system("cls");
            int count{0};
            std::string username{}, Id{}, name{}, userId{};
            std::cout << " Enter your username and password.\n";
            std::cout << "\tUsername: ";
            std::cin >> username;
            std::cout << "\tPassword: ";
            std::cin >> Id;

            std::ifstream input("records.txt");
            while (input >> name >> userId)
            {
                if (name == username && userId == Id)
                {
                    count = 1;
                    system("cls");
                }
            }
           input.close();

           if (count == 1)
           {
               std::cout << " You have successfully logged in.\n\n";
               goto m;
           }
           else
           {
               std::cout << " Please check your username or password.\n\n";
               goto m;
           }}
            break;
        case 2:
            {system("cls");
            std::string rusername{}, rId{};
            std::cout << " Enter your username and password:\n";
            std::cout << "\tUsername: ";
            std::cin >> rusername;
            std::cout << "\tPassword: ";
            std::cin >> rId;

            std::ofstream f1("records.txt", std::ios::app);
            f1 << rusername << ' ' << rId << '\n';
            system("cls");

            std::cout << " Your registration is successful.\n\n";
            goto m;}
            break;
        case 3:
            {system("cls");
            int option{};
            std::cout << " you forgot the password no worries." << '\n';
            std::cout << "   press 1 to find your password by your id:\n";
            std::cout << "   press 2 to go to main.\n\n";
            std::cout << "\tenter your choice: ";
            std::cin >> option;

            switch(option)
            {
            case 1:
                {
                    int count{0};
                    std::string fusername{}, fId{}, fname{};
                    std::cout << " enter the last username wich you remember:";
                    std::cin >> fusername;
                    std::ifstream f2("records.txt");
                    while (f2 >> fId >> fname)
                    {
                        if (fId == fusername)
                        {
                            count = 1;
                        }
                    }
                    f2.close();
                    system("cls");
                        if (count == 1)
                        {
                            std::cout << " Your account has been found.\n";
                            std::cout << '\t' << fusername << " your password is " << fname << '\n';
                            goto m;
                        }
                        else
                        {
                            std::cout << " Sorry, your account was not found. try again\n\n";
                            goto m;
                        }
                        break;
            f2.close();}
            case 2:
                {
                    goto m;
                }

                }
            }
            break;
        case 4:
            std::cout << "\nThank you.\n";
            break;
        default:
            system("cls");
            std::cout << "Please select from the options given above.\n";
    }

    getch();
}

