#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include "../util/timer.h"
#include "../util/utils.h"

using namespace std;

struct Input
{
    long long startID, endID;
};

vector<Input> parse(string _in)
{
    vector<Input> out;

    ifstream file_in(_in);

    string line;
    while (getline(file_in, line, ','))
    {
        int pos = line.find_first_of('-');
        Input in = {
            stoll(line.substr(0, pos)),
            stoll(line.substr(pos + 1))};
        out.push_back(in);
    }

    return out;
}

long long part1(vector<Input> _in)
{
    long long out = 0;

    for (auto ids : _in)
    {
        for (auto i = ids.startID; i <= ids.endID; i++)
        {
            string id = to_string(i);
            int len = id.length();
            if (len % 2 == 0 && id.substr(0, len/2) == id.substr(len/2))
                out += i;
        }
    }

    return out;
}

long long part2(vector<Input> _in)
{
    long long out = 0;

    //stupid regex
    regex pattern(R"(^(.+)\1+$)");

    for (auto ids : _in)
    {
        for (auto i = ids.startID; i <= ids.endID; i++)
        {
            string id = to_string(i);
            if (regex_match(id, pattern))
                out += i;
        }
    }

    return out;
}

int main()
{
    auto exampleInput = parse("example.txt");
    auto input = parse("input.txt");


    assert_equal(part1(exampleInput), (long long)1227775554);

    Timer timer;
    cout << "Part 1 result is: " << part1(input) << " in: " << timer.elapsed() << "ms" << "\n\n";

    assert_equal(part2(exampleInput), (long long)4174379265);

    timer.reset();
    cout << "Part 2 result is: " << part2(input) << " in: " << timer.elapsed() << "ms" << "\n\n";
}