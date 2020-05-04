#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
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
    int t1,t2,num,i,n;
    cout<<"Enter no of rooms"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cout<<"Enter room info\n"; //taking input from users
    	room point;
    	cout<<"floor ";
    	cin>>point.floor_;
    	cout<<"Capacity ";
    	cin>>point.capacity;
    	cout<<"Enter number of available time slots"<<endl;
    	cin>>num;
    	while(num>0)
    	{
    		cout<<"Start Time ";
    		cin>>t1;
    		point.v.push_back(t1);
    		cout<<"End Time ";
    		cin>>t2;
    		point.v.push_back(t2);
    		num--;
    	}
    	vec.push_back(point);
    }
    float floor,min=100.0;
    int ori_cap;
    int j,start,end;
    cout<<"Enter the info for the meeting\n";
    cout<<"floor ";
    cin>>floor;
    cout<<"Capacity ";
    cin>>ori_cap;
    cout<<"Start Time ";
    cin>>start;
    cout<<"End Time ";
    cin>>end;
    float output;
    for(i=0;i<n;i++)
    {
    	if(vec[i].capacity>=ori_cap)   //to check the capacity
    	{
    		for(j=0;j<vec[i].v.size()-1;j+=2) // time slot availability
    		{
    			if(vec[i].v[j]<= start && vec[i].v[j+1]>=end)
    			{
    				int k1 = vec[i].floor_;
    				int k2 = floor;
    				//cout<<"k1"<<k1<<"k2"<<k2<<endl;
    				if(abs(k1-k2)<min) // after satisying all conditions,the nearest room
    				{
    					output = vec[i].floor_;
    					min = floor-vec[i].floor_;
    				}
    				break;
    			}
    		}
    	}
    }
    cout<<"Output ";
    cout<<output<<endl;
    return 0;
}
