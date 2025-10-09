#pragma once
#include <set>
#include <string>
#include <vector>
#include <iostream>
class Channel
{
  private:
    // channel attributes
    std::string name;
    std::string topic;
    std::string password;
    std::set<int> members;          // fds of each client;
    std::set<std::string> _invited; /// invited peoples nickname
    // channel settings

    bool invite_only;
    bool topic_restricted;
    int user_limit;

  public:
    // Getters
    const std::string &getName() const;
    const std::string &getTopic() const;
    const std::string &getpassword() const;
    size_t getMemberCount() const;
    bool isInviteOnly() const;
    bool hasUserLimit() const;
    int getUserLimit() const;

    // Setters
    void setKey(const std::string &pass);
    void setInviteOnly(bool mode);
    void setUserLimit(int limit);

    //  operations
    // std::vector<std::string> ft_split_request(std::string &request, const std::string &delimiter);
    void addMember(int client_fd);
    void removeMember(int client_fd);
    bool isMember(int client_fd);
    bool isOperator(int client_fd);
};