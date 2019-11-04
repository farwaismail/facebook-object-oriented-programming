#ifndef __FACEBOOK2_H
#define __FACEBOOK2_H
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Post;

class TimeLine
{
public:
    TimeLine();
    vector<Post> posts;
    void clearTimeline();
    void displayTimeline();
};


class User
{
public:
    string firstName;
    string lastName;
    string dateOfBirth;
    int postCode;
    string gender;
    string emailAddress;
    string country;
    string city;
    int id_user;
    string userName;
    string password;
    vector<User> friends;
    TimeLine MyTimeline;
    ///vector<Post> MyPosts;


    User();
    void DisplayUserDetails();
    void UpdateUserDetails();
    void addFriend();
    bool check_if_Friend();
    void view_all_friends();
};


class Post
{
public:
    string content;
    ///vector<User> taggedFriends;


    Post();
    void view_posts();
    void postOnFriendWall();
    void postOnNewsFeed();
};

/**class PublicPost: public Post
{
public:
    PublicPost(): Post(){}
    void postOnNewsFeed();
};

class PrivatePost: public Post
{
public:
    PrivatePost(): Post(){}
    void postOnFriendWall();
};*/

#endif // __FACEBOOK2_H


