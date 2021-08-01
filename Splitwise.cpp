//splitwise app
#include<bits/stdc++.h>
using namespace std;
class comparator
{
    public:
bool operator()(pair<string,int> p1,pair<string,int> p2)
{
    return p1.second<p2.second;
}
};
int main()
{
    int no_of_transactions,friends;
    cout<<"Enter no. of friends : "<<endl;
    cin>>friends;
    cout<<"Enter total no. of transactions :"<<endl;
    cin>>no_of_transactions;
    string x,y;
    int amount;
    //maintaining the net amt. for all friends present in the transaction
    map<string,int> net;
    while(no_of_transactions--)
    {
        cout<<"The person that has to pay :"<<endl;
        cin>>x;
        cout<<"The person that gets the money :"<<endl;
        cin>>y;
        cout<<"Amount :"<<endl;
        cin>>amount;
        if(net.count(x)==0) //removing garbage value
        {
            net[x] =0;
        }
         if(net.count(y)==0) //removing garbage value
        {
            net[y] =0;
        }
        net[x] -= amount;
        net[y] += amount;
    }
    //min. transaction list
    multiset<pair<string,int>, comparator > m;
    for(auto p : net)
    {
        string person = p.first;
        int amount = p.second;
        if(net[person] != 0)
        {
            m.insert(make_pair(person, amount));
        }
    }
    // total no. of transaction
    int count =0 ;
    while(!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end()); // access
        string debit_person = low->first;
        int debit = low->second;
        string credit_person = high->first;
        int credit = high->second;
        m.erase(low);
        m.erase(high);
        int settled_amount = min(abs(debit),abs(credit));
        debit += settled_amount;
        credit -= settled_amount;
        count++;
        cout<<debit_person<<" will pay "<<settled_amount<<" to "<<credit_person<<endl;
        if(debit != 0)
        {
            m.insert(make_pair(debit_person,debit));
        }
        if(credit !=0)
        {
             m.insert(make_pair(credit_person,credit));
        }
        cout<<"The total nuber of transactions : "<<count<<endl;
    }
    return 0;
}