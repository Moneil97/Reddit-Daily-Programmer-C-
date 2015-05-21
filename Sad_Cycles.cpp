Prompt: http://www.reddit.com/r/dailyprogrammer/comments/36cyxf/20150518_challenge_215_easy_sad_cycles/ 

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int calcSad(int num, int power);
int getPosition(int num, vector<int> list);

int main()
{
    int num, power;
    vector<int> list;

    cout << "Input Number" << endl;
    cin >> num;
    cout << "\nInput sad" << endl;
    cin >> power;

    int position = -5;
    while (position < 0){
        int sad = calcSad(num,power);
        position = getPosition(sad, list);
        list.push_back(sad);
        num = sad;
    }

    cout << endl; //<< "sads: " << list.size() << endl;
    for (int i=position; i < list.size()-1; i++){
       cout  << list.at(i) << ",";
    }

}

int getPosition(int num, vector<int> list){

    //cout << "checking: " << num << endl;

    for (int i=0; i < list.size(); i++)
        if (list.at(i) == num)
            return i;

    return -5;

}

int calcSad(int num, int power){

    int sum = 0;

    while (num > 0){
        sum += pow(num%10, power)+0.5;
        num = num/10;
    }

    return sum;
}
