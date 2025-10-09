#include "../Includes/Channel.hpp"

void	printer(std::vector<std::string> &printed)
{
	int i = 0;
	while(i < printed.size())
	{
		std::cout << printed[i];
		i++;
	}
	std::cout << '\n';
}
// JOIN command implementation
// This file will contain the JOIN command logic for IRC
// std::vector<std::string> ft_split_request(std::string &request,
// 	const std::string &delimiter)
// {
// 	size_t	end;
// 	size_t	start;
// 	int		i;

// 	std::vector<std::string> lines;
// 	start = 0;
// 	i = 0;
// 	end = request.find(delimiter);
// 	while (end != std::string::npos)
// 	{
// 		lines.push_back(request.substr(start, end - start));
// 		// std::cout << "testing line number " << i << " :" << lines[i] << std::endl;
// 		start = end + delimiter.length();
// 		end = request.find(delimiter, start);
// 		i++;
// 	}
// 	lines.push_back(request.substr(start));
// 	return (lines);
// }
std::vector<std::string> ft_split_request(const std::string &request,const std::string &delimiter)
{
    std::vector<std::string> parts;
    if (delimiter.empty())
    {
        parts.push_back(request);
        return parts;
    }

    size_t start = 0;
    size_t pos;
    while ((pos = request.find(delimiter, start)) != std::string::npos)
    {
        parts.push_back(request.substr(start, pos - start));
        start = pos + delimiter.length();
    }
    parts.push_back(request.substr(start));
    return parts;
}
// to looop with it after
int	check_channel_name(std::string &c_name)
{
	if (c_name.length() > 1)
	{
		if (c_name[0] == '#')
			return (1);
	}
	return (0);
}
// to check every channel if its valid syntax
int	check_allchannels_name(std::vector<std::string> &channels)
{
	for (int i = 0; i < channels.size(); i++)
	{
		if (check_channel_name(channels[i]) == 0)
			return (i); // returning which on is not valid
	}
	return (0); // succes
}
// i forgot why drtha hh
int	count_char_in_string(std::string &stringg, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stringg.length())
	{
		if (stringg[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	valid_syntax(std::string &request, std::vector<std::string> &out_channels,std::vector<std::string> &out_keys)
{
	int	bad_index;
	int	index_error;

	std::vector<std::string> divided = ft_split_request(request, " ");
	if (divided.size() < 2)
		throw("error not enough parametres \n");
	if (divided[0] == "JOIN")
	{
		std::string chans = divided[1];
		if (!chans.empty() && chans[0] == ':')
			chans.erase(0, 1);
		out_channels = ft_split_request(chans, ",");
		index_error = check_allchannels_name(out_channels);
		printer(out_channels);
		if (index_error != 0)
		{
			std::cout << "error 403 invalid channel name at index " << index_error << std::endl;
			return (1); // error
		}
		std::string passowrds = divided[2];
		out_keys = ft_split_request(passowrds,",");
		printer(out_keys);
	}
	return (0); // succes
}
int main(int ac, char **av)
{
	std::string request = av[1];
	std::vector<std::string> channels;
	std::vector<std::string> passwords;
			printer(channels);
		printer(passwords);
	if(valid_syntax(request,channels,passwords) == 1)
	{
		std::cout << "error happened" << std::endl;
		return 1;
	}
		std::cout << "succes" << std::endl;
		printer(channels);
		printer(passwords);

		return 0;

}
// void	addMember(int client_fd, const std::string &nick)
// {

// }
// void	removeMember(int client_fd)
// {
// }
// bool	isMember(int client_fd)
// {
// }
// bool	isOperator(int client_fd)
// {
// }