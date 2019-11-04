#include <iostream>
#include <cstdlib>
#include "facebook2.h"
#include <vector>
#include <fstream>

using namespace std;

User current_user; /// global
vector<User> allusers;
int totalusers = 1;
int current_user_id = 0;
User blah;
void menu();
int userid;
Post MyPost;
Post temp;
TimeLine bloo;


User::User()
{
    firstName = "";
    lastName = "";
    dateOfBirth = "";
    postCode = 0;
    gender = "";
    emailAddress = "";
    country = "";
    city = "";
    id_user = 0;
    userName = "";
    password = "";
    ///friends[]; /// don't need to initialize vectors
    ///MyTimeline; ///initialize??
    ///MyPosts[]; ///don't need to initialize vectors
    /// what about username password and other shit in .h file?
}

void User::UpdateUserDetails()
{
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Date of Birth: ";
    cin >> dateOfBirth;
    cout << "Post Code: ";
    cin >> postCode;
    cout << "Gender: ";
    cin >> gender;
    cout << "Email Address: ";
    cin >> emailAddress;
    cout << "Country: ";
    cin >> country;
    cout << "City: ";
    cin >> city;
    cout << "Username: ";
    cin >> userName;
    cout << "Password: ";
    cin >> password;
    id_user = totalusers;
    totalusers++;
    allusers.push_back(blah);
}

void User::DisplayUserDetails()
{
    cout << "    User Details   " << endl;
    cout << "-------------------" << endl;
    cout << endl;
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Post Code: " << postCode << endl;
    cout << "Gender: " << gender << endl;
    cout << "Email Address: " << emailAddress << endl;
    cout << "Country: " << country << endl;
    cout << "City: " << city << endl;
    cout << "User ID: " << id_user << endl; ///or maybe the function
}

void view_all_users()
{
    for (int i = 0; i < allusers.size(); i++)
    {
        allusers[i].DisplayUserDetails();
        cout << endl;
    }
}

void User::addFriend()
{
    view_all_users();
    cout << "Type a User ID to add friend" << endl;
    int id;
    cin >> id;
    allusers[userid].friends.push_back(allusers[id]);
    allusers[id].friends.push_back(allusers[userid]);
    cout << allusers[id].firstName << " has been added to your friend list" << endl;
}

void User::view_all_friends()
{
    for (int i = 0; i < friends.size(); i++)
    {
        friends[i].DisplayUserDetails();
        cout << endl;
    }
}

bool User::check_if_Friend()
{
    cout << "--------------" << endl;
    view_all_users();
    cout << "Which user do you want to check for friend? Enter user ID" << endl;
    int response;
    cin >> response;
    bool found = false;
    for (int i = 0; i < friends.size(); i++)
    {
        if (friends[i].id_user == response)
        {
            found = true;
        }
    }
    if (found == true)
    {
        cout << "You are friends. Yay" << endl;
    }
    else
    {
        cout << "You both aren't friends. LOL" << endl;
    }
}

Post::Post()
{
    content = "";
}

void Post::postOnNewsFeed()
{
    cout << "What's on your mind?" << endl;
    string x;
    cin >> x;
    MyPost.content = x;
    allusers[userid].MyTimeline.posts.push_back(MyPost);
}

void Post::postOnFriendWall()
{
    allusers[userid].view_all_friends();
    cout << "Type a friend's id to post on his/her wall" << endl;
    int a;
    cin >> a;
    cout << "Type your post :p" << endl;
    string y;
    cin >> y;
    MyPost.content = y;
    allusers[a].MyTimeline.posts.push_back(MyPost);
}

TimeLine::TimeLine()
{

}

void TimeLine::displayTimeline()
{
    for (int i = 0; i < posts.size(); i++)
    {
        cout << posts[i].content << endl;
        cout << endl;
    }
}

void login()
{
    cout << "Enter your login details" << endl;
    cout << "User ID: ";
    cin >> userid;
    cout << "Password: ";
    string pass;
    cin >> pass;
    int correct = 0;
    for (int i = 0; i < allusers.size(); i++)
    {
        if (allusers[i].id_user == userid && allusers[i].password == pass)
        {
            correct = 1;
        }
    }
    if (correct == 1)
    {
        cout << "Login Successful" << endl;
        current_user_id = userid;
        menu();
    }
    else
    {
        cout << "Incorrect user ID or password" << endl;
        login();
    }

}

void welcome_page()
{
    cout << "   WELCOME TO FACEBOOK   " << endl;
    cout << "-------------------------" << endl;
    cout << "Are you a new user? Press 1 for new user; press 0 for old user" << endl;
    int response;
    cin >> response;
    if (response == 1)
    {
        cout << "Kindly enter your details" <<endl;
        blah.UpdateUserDetails();
        cout << "Congratulations! Your account has been made" << endl;
        cout << "Your user ID is " << blah.id_user << endl;
        login();
    }
    else
    {
        login();
    }
}

void display_menu()
{
    cout << "------------------------" << endl;
    cout << "Choose any option" << endl;
    cout << "1. View your details" << endl;
    cout << "2. Add a friend" << endl;
    cout << "3. Check if you're friends with someone" << endl;
    cout << "4. View all friends" << endl;
    cout << "5. View everyone on facebook" << endl;
    cout << "6. Write a post on your Timeline" << endl;
    cout << "7. View your Timeline" << endl;
    cout << "8. Write a post on friend's Timeline" << endl;
    cout << "9. View a friend's Timeline" << endl;
    cout << "10. Logout" << endl;
}

void menu()
{
    display_menu();
    cout << "Option: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        allusers[userid].DisplayUserDetails();
        menu();
    }
    else if (choice == 2)
    {
        current_user.addFriend();
        menu();
    }
    else if (choice == 3)
    {
        allusers[userid].check_if_Friend();
        menu();
    }
    else if (choice == 4)
    {
        allusers[userid].view_all_friends();
        menu();
    }
    else if (choice == 5)
    {
        view_all_users();
        menu();
    }
    else if (choice == 6)
    {
        MyPost.postOnNewsFeed();
        menu();
    }
    else if (choice == 7)
    {
        allusers[userid].MyTimeline.displayTimeline();
        menu();
    }
    else if (choice == 8)
    {
        MyPost.postOnFriendWall();
        menu();
    }
    else if (choice == 9)
    {
        allusers[userid].view_all_friends();
        cout << "Type a friend's ID to view his/her timeline" << endl;
        int a;
        cin >> a;
        allusers[a].MyTimeline.displayTimeline();
        menu();
    }
    else if (choice == 10)
    {
        cout << "Logged out" << endl;
        welcome_page();
    }
    else
    {
        return;
    }
}
int main()
{
    User asad; /// asad
    asad.firstName = "Asad";
    asad.lastName = "Hussain";
    asad.dateOfBirth = "31/10/95";
    asad.postCode = 12345;
    asad.gender = "m";
    asad.emailAddress = "asadhussain@gmail.com";
    asad.country = "Pakistan";
    asad.city = "Karachi";
    asad.userName = "asad";
    asad.password = "potato";
    asad.id_user = 0;
    allusers.push_back(asad);

    welcome_page();

    return 0;
}
