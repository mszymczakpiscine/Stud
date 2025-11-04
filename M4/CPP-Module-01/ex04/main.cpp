/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:48:44 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:44 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace_word(std::size_t pos, std::string &content, std::string &search, std::string &replace)
{
    std::string before = content.substr(0, content.find(search, pos));
    std::string after = content.substr(content.find(search, pos) + search.size());
    return (before + replace + after);
}
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string search = argv[2];
    std::string replace = argv[3];
    std::string file_replace = (filename + ".replace");
    std::ifstream input_file(filename.c_str());

    if (!input_file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::ofstream output_file(file_replace.c_str());
    if (!output_file.is_open())
    {
        std::cerr << "Error: Could not create file " << file_replace << std::endl;
        input_file.close();
        return 1;
    }
    std::string line;
    while (std::getline(input_file, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(search, pos)) != std::string::npos)
        {
            if (search == replace || search.empty())
                break ;
            line = replace_word(pos, line, search, replace);
            pos = line.find(replace, pos) + replace.size();
        }
        output_file << line << std::endl;
    }
    input_file.close();
    output_file.close();
    return 0;
}
