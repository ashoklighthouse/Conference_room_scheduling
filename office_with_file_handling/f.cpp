#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef struct room
{
    float floor_;
    int capacity;
    vector<int> v;
}room;

int main()
{
    vector<room> vec;
    ifstream myfile;
    string str;
    myfile.open("room.txt");
    int type;
    string line;
    while(myfile.peek() != EOF)
    {
        room r;
        getline(myfile,str,',');
        r.floor_=stof(str);
        cout << r.floor_;
        getline(myfile,str,',');
        r.capacity=stoi(str);
        while(getline(myfile,str,','))
        {
            type=stoi(str);
            r.v.push_back(type);
        }
        getline(myfile,str,'\n');
        type=stoi(str);
        vec.push_back(r);
    }
    int n = vec.size();
    int min_in;
    int floor = vec[n-1].floor_;
    int ori_cap = vec[n-1].capacity;
    int i,j,min=INT_MAX,start,end;
    start =  vec[n-1].v[0];
    end = vec[n-1].v[1];
    for(i=0;i<vec.size()-1;i++)
    {
    	if(vec[i].capacity>=ori_cap)
    	{
    		for(j=0;j<vec[i].v.size()-1;j+=2)
    		{
    			if(vec[i].v[j]<= start && vec[i].v[j+1]>=end)
    			{
    				if(abs(floor-vec[i].floor_)<min)
    				{
    					min = floor-vec[i].floor_;
                                         min_in = i;
    				}
    				break;
    			}
    		}
    	}
    }
    myfile.close();
     cout << vec[0].floor_<< "\n";
    return 0;
}
