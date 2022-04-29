#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int freq;
    char data;
    const node *p,*p1;

    node (char d, int f=-1)
    {
        data=d;
        freq=f;
        p=NULL;
        p1=NULL;
    }

 node (const node *r, const node *s)
{
    data=0;
    freq=r->freq+s->freq;
    p=r;
    p1=s;
}

 bool operator<( const node &a ) const { //< operator performs to find priority in queue
      return freq >a.freq;
   }

void traverse(string code="")const
{
    if(p!=NULL)
    {
        p->traverse(code+'0');
        p1->traverse(code+'1');
    }
    else
    {
        cout << "Data: " << data<< ", Frequency: "<<freq << ", Code: " << code<<endl;
    }
}

};

void huffmanCode(string s)
{
    priority_queue <node> pq;
    int frequency [500];
    for(int i=0;i<256;i++)
        frequency[i]=0;
    for(int i=0;i<s.size();i++)
        frequency[int(s[i])]++;
    for(int i=0;i<256;i++)
    {
        if(frequency[i])
        {
            pq.push(node(i,frequency[i]));
        }
    }

    while(pq.size()>1)
    {
        node *t=new node(pq.top());
        pq.pop();
        node *q=new node(pq.top());
        pq.pop();
        pq.push(node(t,q));
    }
    cout<<" By encoding using Huffman Code:"<<endl;
    pq.top().traverse();
}

int main()
{
    string str;
    cout << "Enter the string you want to encode:" << endl;
    cin>>str;
    huffmanCode(str);
    return 0;
}
