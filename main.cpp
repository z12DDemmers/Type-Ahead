//Sample code to read in test cases

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;


vector<string> tokenized;
vector<string> temp;

vector<string> temp_of_predictions;



void split(const char *str, char c);


const char *text = "Mary had a little lamb its fleece was white as snow And everywhere that Mary went the lamb was sure to go "
"It followed her to school one day which was against the rule "
"It made the children laugh and play to see a lamb at school "
"And so the teacher turned it out but still it lingered near "
"And waited patiently about till Mary did appear "
"Why does the lamb love Mary so the eager children cry Why Mary loves the lamb you know the teacher did reply ";


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    split(text,' ');
    while (getline(stream, line)) {

    string::size_type pos = line.find(',');
    string arg;
    int size = line.size();
    if(line.npos != pos) {
        arg = line.substr(pos + 1, size);
        line = line.substr(0, pos);
    }

    for(int i = 0; i < tokenized.size(); i++ )
    {
        if(tokenized[i] == arg)
        {
            temp_of_predictions.push_back(tokenized[i+1]);
        }

    }
  

   sort(temp_of_predictions.begin(),temp_of_predictions.end());
   double temp_count;
   for(int i = 0; i<temp_of_predictions.size(); i++)
   {
        if(temp_of_predictions[i] == temp_of_predictions[i+1])
        {
            temp_count ++;
        }
        else {
            temp_count++;
            cout << setprecision(3) << temp_of_predictions[i] << "," << double(temp_count/temp_of_predictions.size()) << ";";
            temp_count = 0;
        }
   
        // Do something with the line
    }


    return 0;
}
}


void split(const char *str, char c)
{
    

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        tokenized.push_back(string(begin, str));
    } while (0 != *str++);
}

