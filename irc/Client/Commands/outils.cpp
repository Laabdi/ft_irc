#include <Channel.hpp>

const std::string &Channel::getName() const
{
    return(this->name);
}

const std::string &Channel::getTopic() const
{
	return (this->topic);
}

const std::string &Channel::getpassword() const
{
	return (this->password);
}

size_t Channel::getMemberCount() const
{
	return (this->members.size());
}

bool Channel::isInviteOnly() const
{
	return (this->invite_only);
}

bool Channel::hasUserLimit() const
{
	return (this->user_limit > 0);
}

int Channel::getUserLimit() const
{
	return (this->user_limit);
}

void Channel::setKey(const std::string &pass)
{
	this->password = pass;
}

void Channel::setInviteOnly(bool mode)
{
	this->invite_only = mode;
}

void Channel::setUserLimit(int limit)
{
	this->user_limit = limit;
}

void Channel::addMember(int client_fd)
{
	this->members.insert(client_fd);
}

void Channel::removeMember(int client_fd)
{
	this->members.erase(client_fd);
}

bool Channel::isMember(int client_fd)
{
	return (this->members.find(client_fd) != this->members.end());
}

bool Channel::isOperator(int /*client_fd*/)
{
	// TODO: No operators structure exists yet. Add e.g.,
		std::set<int> operators;
	// and implement accordingly.
	return (false);
}
