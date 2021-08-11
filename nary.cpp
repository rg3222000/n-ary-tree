#include<bits/stdc++.h>
using namespace std;


int traverse(vector<pair<int,int>> v,vector<int> val)
{

	int sum=0;
    queue<int> q;
    q.push(0);
    int max1=0;
    int size=q.size();
    while(!q.empty())
    {   
    	int p=q.front();
    	q.pop();
    	for(auto e:v)
    	{
    		if(e.first==p)
    		{
    			sum+=val[e.second];
    		    q.push(e.second);
    		}
            
    	}   
    	size-=1;
    	if(size==0){
    		size=q.size();
    		cout<<size<<"\n";
    		max1=max(sum,max1);
    		sum=0;
    	}
    }

return max(val[0],max1);
}


int traverse_un_map(vector<pair<int,int>> v,vector<int> val)
{

	auto sum=0,c=0;
    unordered_map<int,int> mp;
    unordered_map<int,int> mp1;
    mp[0]=1;
    int max1=0;
    //int size=mp.size();
    while(1)
    {   
    	//int p=mp[i];
    	//mp.erase(i);
    	for(auto e:v)
    	{
    		if(mp[e.first])
    		{
    			sum+=val[e.second];
    		    mp1[e.second]=1;
    		}
            else{
            	c++;
            }
    	}
    	for(auto e:mp)
    	{
    	   if(mp[e.first]) mp[e.first]=0;
    	}   
    	for(auto e:mp1)
    	{
    	   mp[e.first]=1;
    	}
    	mp1.clear();
    	max1=max(sum,max1);
    	sum=0;

    	if(c==v.size())
    	break;

        c=0;
    }

return max(val[0],max1);
}

int main()
{


        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output1.txt","w",stdout);
        #endif

  vector<pair<int,int>> nos;
  int n,i,a,b;
  cin>>n;
  vector<int> v;
  for(i=1;i<n;i++)
  {
  	cin>>a>>b;

  	nos.push_back(make_pair(a,b));
  }
   
for(i=0;i<n;i++)
  {
  	cin>>a;
  	v.push_back(a);
  }   

 cout<<traverse_un_map(nos,v);
  return 0;
}