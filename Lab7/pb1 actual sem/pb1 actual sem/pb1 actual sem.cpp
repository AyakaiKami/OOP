#include <iostream>
template<typename T>
bool eqT(T a, T b)
{
    if(a==b)
        return true;
    else
        return false;
}
template<typename T>
class Tree {
private:
    class Node
    {   public:
        T value;
        int size_children;
        bool exists;
        Node* children[256];
        Node* find_V(Node* father,T value_in, bool (*cmp)(T a, T b) = eqT)
        {
            if (cmp(father->value, value_in))
            {
                return father;
            }
            else
            {
                Node* ptr = nullptr;
                for (int i = 0; i < father->size_children; i++)
                {
                    if (find_V(father->children[i], value_in, cmp) != nullptr)
                        ptr = find_V(father->children[i], value_in, cmp);
                    break;
                }
                return ptr;
            }
        }
        bool friend operator<(Node a, Node* b)
        {
            if (a.value < b->value)
                return true;
            else
                return false;
        }
        int Count_V()
        {
            if (exists == true)
            {
                if (size_children == 0)
                    return 1;
                else
                {
                    int sum = 1;
                    for (int i = 0; i < size_children; i++)
                    {
                        if (children[i] != nullptr)
                        {
                            sum += children[i]->Count_V();
                        }
                    }
                    return sum;
                }
            }
            else
                return 0;
        }
        void Redo()
        {
            for (int i = 0; i < size_children; i++)
                if (children[i]->exists == false || children[i]==nullptr)
                {
                    for (int j = i; j < size_children-1; j++)
                        children[j] = children[j+1];
                    size_children--;
                }
        }
    }*HeadNode;
public:
    Tree() { HeadNode = nullptr; }
    ~Tree() { delete HeadNode; }
    void add_node(T value_in, Node* father = nullptr )
    {
        if(father==nullptr)
        {
            HeadNode = new Node;
            HeadNode->value = value_in;
            HeadNode->exists = true;
            HeadNode->size_children = 0;
        }
        else
        {
            Node* nou_nod = new Node;
            nou_nod->size_children = 0;
            nou_nod->value = value_in;
            nou_nod->exists = true;
            father->children[father->size_children] = nou_nod;
            father->size_children++;
        }
    }
    Node* get_node(T value_in, Node* father = nullptr)
    {
        if (father == nullptr)
            return HeadNode;
        for (int i = 0; i < father->size_children; i++)
            if (father->children[i]->value == value_in)
                return father->children[i];
        return nullptr;
    }
    void delete_node(Node* father)
    {
        father->exists = false;
        for (int i = 0; i < father->size_children; i++)
            delete father->children[i];
       father = nullptr;
    }
    void insert(T value_in, Node* father,int index)
    {
        if (father != nullptr)
        {
            if (index < father->size_children + 1)
            {
                bool in = false;
                for (int i = father->size_children; i > index; i--)
                    father->children[i] = father->children[i - 1];
                father->children[index] = new Node;
                father->children[index]->value = value_in;
                father->children[index]->exists = true;
                father->size_children++;
            }
        }
    }
    Node* get_Head()
    {
        return HeadNode;
    }
    Node* find(T value_in,bool (*cmp)(T a, T b) )
    {
        Node *x =HeadNode->find_V(HeadNode, value_in, cmp);
        return x;
    }
    void Sort(Node* father, bool (*cmp)(Node* a, Node* b))
    {
        father->Redo();
        if (cmp == nullptr)
        {
            for (int i = 0; i < father->size_children - 1; i++)
                for (int j = i ; j < father->size_children; j++)
                    if (*(father->children[i]) < father->children[j])
                    {
                        
                        Node* cop = father->children[i];
                        father->children[i] = father->children[j];
                        father->children[j] = cop;
                    }
        }
        else
        {
            for (int i = 0; i < father->size_children - 1; i++)
                for (int j = i ; j < father->size_children; j++)
                    if (cmp(father->children[i],father->children[j]))
                    {
                        Node* cop = father->children[i];
                        father->children[i] = father->children[j];
                        father->children[j] = cop;
                    }
        }
    }
    int Count(Node* father=nullptr)
    {
        if (father == nullptr)
        {
            return HeadNode->Count_V();
        }
        else
            return father->Count_V();
    }
    void Print_N(Node* father = nullptr)
    {
        if (father == nullptr)
            father = HeadNode;
        father->Redo();
        printf("Father is : %d (%d)\n", father->value,father->exists);
        printf("Children : ");
        for (int i = 0; i < father->size_children; i++)
            if (father->children[i]!=nullptr)
                printf("%d(%d) ", father->children[i]->value, father->children[i]->exists);
        printf("\n");
    }
    void Print_All(Node* father=nullptr)
    {
        if (father == nullptr)
            father = HeadNode;
        father->Redo();
        printf("Father is : %d (%d)\n", father->value, father->exists);
        printf("Children : ");
        for (int i = 0; i < father->size_children; i++)
            if (father->children[i] != nullptr)
                printf("%d(%d) ", father->children[i]->value, father->children[i]->exists);
        printf("\n");
        for (int i = 0; i < father->size_children; i++)
            if (father->children[i] != nullptr)
                Print_N(father->children[i]);
    }
};
int main()
{
    Tree<int> b;
    b.add_node(5); 
    b.add_node(6,b.get_node(5));
    b.get_node(6,b.get_node(5));
    b.insert(10, b.get_Head(),0);
    b.find(10,(eqT));
    b.delete_node(b.get_node(6, b.get_node(5)));
    b.add_node(11, b.get_Head());
    b.add_node(8, b.get_Head());
    //b.Print_N();
    b.Sort(b.get_Head(),nullptr);
    printf("Count:%d\n", b.Count(b.get_Head()));
    b.Print_All();
    return 0;
}