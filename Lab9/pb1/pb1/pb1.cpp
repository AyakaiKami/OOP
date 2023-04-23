#include <iostream>
template <typename V,typename K>
class Map
{
private:
public:  // int size;
    struct Nod {
        int index;
        V value;
        K key;
        Nod* next;
        void operator=(const K& key) { this->key = key; }
    };
    int size ;
    Nod *HeadNod;
    Nod nodes[256];

    Map() { HeadNod = new Nod; HeadNod->next = nullptr; size = 0; }
    void Set(V value, const K key )
    {
        if (size == 0)
        {
            HeadNod->index = size+1;
            HeadNod->key = key;
            HeadNod->value = value;
            size++;
            nodes[0] = *HeadNod;
        }
        else
        {
            
            Nod* nouNod = new Nod;
            nouNod->index = size + 1;
            nouNod->key = key;
            nouNod->value = value;
            nouNod->next = nullptr;
            Nod* parcurgere = HeadNod;
            while (parcurgere->next != nullptr)
            {
                parcurgere = parcurgere->next;
            }
            parcurgere->next = nouNod;
            nodes[size] = *nouNod;
            size++;
        }
    }
    bool Get(const K& key, V& value)
    {
        Nod* parcurgere = HeadNod;
        while (parcurgere->next != nullptr)
        {
            if (key == parcurgere->key)
            {
                value = parcurgere->value;
                return true;
            }
            parcurgere = parcurgere->next;
        }
        if (key == parcurgere->key)
        {
            value = parcurgere->value;
            return true;
        }
        return false;
    }
    int Count()
    {
        return size;
    }
    void Clear()
    {
        Nod* parcurgere = HeadNod;
        Nod* copy;
        while (parcurgere->next!=nullptr)
        {
            copy = parcurgere;
            parcurgere = parcurgere->next;
            delete copy;
        }
        HeadNod = parcurgere;
        HeadNod->key = nullptr;
        HeadNod->value = 0;
        size = 0;
    }
    bool Delete(const K& key)
    {
        Nod* parcurgere = HeadNod;
        if (parcurgere->key == key)
        {
            size--;
            HeadNod->key = nullptr;
            HeadNod->value = 0;
        }
        while (parcurgere->next != nullptr)
        {
            if (key == parcurgere->next->key)
            {
                Nod* copy = parcurgere->next;
                parcurgere->next = parcurgere->next->next;
                delete copy;
                size--;
                return true;
            }
            else
            parcurgere = parcurgere->next;
        }
        return false;
    }
    Nod& operator[](int value)
    {
        Nod* parcurgere = HeadNod;
        if (parcurgere->value == value)
            return *parcurgere;

        while (parcurgere->next != nullptr)
        {
        if (parcurgere->value == value)
            return *parcurgere;
        parcurgere = parcurgere->next;
        }
        
        if (parcurgere->value == value)
            return *parcurgere;

        size++;
        Nod* nouNod = new Nod;
        parcurgere->next = nouNod;
        nouNod->value = value;
        return *nouNod;
    }
   /* bool Includes(const Map<K, V>& map)
    {
        if (this->Count() < map.Count())
            return false;
        Nod* parcurgere = HeadNod;
        while (parcurgere != nullptr)
        {
            K verif;
            if (map.Get(parcurgere->value, verif) == false)
                return false;
            else
            {
                map.Get(parcurgere->value, verif);
                if (verif != parcurgere->key)
                    return false;
            }
            parcurgere = parcurgere->next;
        }
        return true;
    }*/
    Nod* begin() { return &nodes[0]; }
    Nod* end() { return &nodes[size - 1]; }
 
};

int main()
{
    Map<int, const char*>m;
    Map<const char*, int>vf;
    vf.Set("C++", 10);
    m.Set(10, "C++");
    m[20] = "plm";
    int v;
    m.Get("plm", v);
    printf("%d", v);
    for(auto[key,value,index,ptr]:m)
       printf("%s %d %d",key,value,index);
    return 0;
}
