#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:

        int val;
        Node* rep;
        Node* next;

        Node(int x)
        {
            val = x;
            rep = this;
            next = nullptr;
        }
};

class DisjointSets
{
    private:
        vector<Node*> nodes;

    public:

        DisjointSets(int n)
        {
            nodes.resize(n+1);

            for( int i=1; i<=n; i++)
            {
                CreateSet(i);
            }
        }

        void CreateSet(int i)
        {
            nodes[i] = new Node(i);
        }

        Node* FindSet(int x)
        {
            if(x>=nodes.size() || nodes[x]==nullptr) return nullptr ;
            return nodes[x]->rep;
        }

        void MergeSet(int x, int y)
        {
            Node* X = FindSet(x);
            Node* Y = FindSet(y);

            if(X == Y || X == nullptr || Y == nullptr ) return;

            Node* n;
            Node* o;

            if(X->val > Y->val)
            {
                n = X;
                o = Y;
            }
            else
            {
                n = Y;o=X;
            }

            Node* curr = n;
            while(curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = o;

            curr = curr->next;
            while( curr != nullptr )
            {
                curr->rep = n;
                curr = curr->next;
            }
        }

        bool SameSet(int x, int y)
        {
            Node* X = FindSet(x);
            Node* Y = FindSet(y);
            if( X == Y )
                return true;
            return false;
        }
};

int main()
{}